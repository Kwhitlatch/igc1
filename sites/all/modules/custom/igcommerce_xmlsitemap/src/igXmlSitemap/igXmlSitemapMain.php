<?php

namespace igXmlSitemap;

use Thepixeldeveloper\Sitemap\Drivers\XmlWriterDriver;
use Thepixeldeveloper\Sitemap\Urlset;
use Thepixeldeveloper\Sitemap\Url;
use Thepixeldeveloper\Sitemap\Extensions\Image;

class igXmlSitemapMain {
  function __construct($lang) {
    $this->lang = $lang;

    $this->getExclusions();

    $this->getGlobalAssignments($lang);

    $product_term = fluke_solr_get_term_by_name('product', 'url_builder', $this->lang);

    $this->product_translated = $product_term->sm_field_url_title[0];
    $products_term = fluke_solr_get_term_by_name('products', 'url_builder', $this->lang);

    $this->products_translated = $products_term->sm_field_url_title[0];

  }

  function getExclusions() {
    // Load excluded items csv
    $path = drupal_get_path('module', 'igcommerce_xmlsitemap') . '/exclude.csv';

    $this->excluded = [];

    if (file_exists($path)) {

      if (($handle = fopen($path, "r")) !== FALSE) {
        //First line is the header row
        $header = ($data = fgetcsv($handle, 1000, ","));
        while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {

          $this->excluded[$data[0]][] = $data[1];
        }
        fclose($handle);
      }
    }

    // Load the language integrit check to filter out 404s
    $dir = 'private://igxmlsitemap-ic';

    $filename = drupal_realpath($dir) . '/sitemap-integrity-check-' . $this->lang . '.csv';

    if (file_exists($filename)) {

      if (($handle = fopen($filename, "r")) !== FALSE) {

        while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
          if ($data[5] != 'Canonical Mismatch' && $data[5] != 'English in URL Title') {
            $identifier = explode('|', $data[1]);

            $this->excluded[$identifier[0]][] = $identifier[2];
          }
        }
        fclose($handle);
      }
    }
  }

  function getGlobalAssignments() {
    $path = drupal_get_path('module', 'igcommerce_xmlsitemap') . '/GlobalNavigationAssignment.csv';

    if (file_exists($path)) {

      if (($handle = fopen($path, "r")) !== FALSE) {
        //First line is the header row
        $header = ($data = fgetcsv($handle, 1000, ","));

        //determine which column pertains to the current language
        foreach ($header as $colKey => $column) {
          if ($column === $this->lang) {
            break;
          }
        }
        $row = 1;
        while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
          $row++;
          $assignment = new \stdClass();

          $name = $data[3];

          $assignment->name = $name;
          $assignment->status = $data[$colKey] === 'Y' ? TRUE : FALSE;
          $assignment->row = $row;

          if (empty($this->navAssignments[$name])) {
            $this->navAssignments[strtolower($name)] = $assignment;
          } else {
            $this->duplicateAssignments[$row] = $name;
          }

        }
        fclose($handle);
      }
    }
  }

  function build() {

    $this->doUrlBuilder();

    $this->checkAssignments();

    $this->doToc();
    $this->doProductDisplays();
    //$this->doWebinars(); //@todo: as of now od webinars are external links, and so no need to index them
    $this->doArticles();
    $this->doPages();

    $this->checkArticlePdAssignments();
    //$this->doTrainingVids();  //@todo: training videos use flash, so we aren't indexing them at this time

    //Manually add homepage link
    $this->doHomepage();

  }

  function checkArticlePdAssignments(){
    $paths = [];
    if(!empty($this->mispublished)) {
      foreach ($this->mispublished as $identifier => $item) {
        $paths[] = $item->link;
      }

      foreach ($this->urlSet as $path => $link) {
        $id_parts = explode('|', $link->identifier);

        $type = $id_parts[1];

        if ($type === 'product_display' || $type === 'article') {
          $this->checkPath($link, $paths, $type);
        }
      }
    }
  }

  function checkPath($link, $paths, $type){
    foreach($paths as $path){
      if($type === 'product_display'){
        $path = str_replace("/$this->products_translated/", "/$this->product_translated/", $path);
      }

      if(strpos($link->link, $path) === 0){
        $this->{'mispublished_'.$type}[] = $link;
        return;
      }
    }
  }

  protected function doUrlBuilder() {

    $urlBuilder = new urlBuilder($this->lang);

    $this->urlSet = $urlBuilder->getUrlSet();

    $this->WebinarsUrl = $urlBuilder->webinarsUrl;
    $this->trainingLibUrl = $urlBuilder->trainingLibUrl;
  }

  protected function checkAssignments() {
    foreach ($this->urlSet as $path => $item) {
       $id_parts = explode('|',$item->identifier);
       if(!in_array($id_parts[2], $this->excluded['taxonomy_term'])) {

         if (!empty($this->navAssignments[strtolower($item->label)])) {
           $assignment = $this->navAssignments[strtolower($item->label)];

           if ($assignment->status === FALSE) {
             $this->mispublished[$item->identifier] = $item;
           }

         } else {
           $this->assignmentNotFound[$item->identifier] = $item;
         }
       }
    }
  }

  protected function doToc() {

    $tocs = new toc($this->lang, $this->urlSet);

    $this->urlSet = $tocs->getUrlSet();
  }

  protected function doProductDisplays() {
    $sshow = new slideshow('en-us');

    $sshows = $sshow->getCollection();
    $pds = new productDisplay($this->lang, $this->urlSet, $sshows);

    $this->urlSet = $pds->getUrlSet();
  }

  /**
   * Index on-demand webinars pointing to the webinar page
   */
  protected function doWebinars() {
    $odwebs = new odWebinars($this->lang, $this->urlSet, $this->webinarsUrl);
  }

  protected function doArticles() {
    $articles = new article($this->lang, $this->urlSet);

    $this->urlSet = $articles->getUrlSet();
  }

  protected function doPages() {
    $page = new page($this->lang, $this->urlSet);

    $this->urlSet = $page->getUrlSet();
  }


  protected function doTrainingVids() {
    $trainingVids = new trainingVideos($this->lang, $this->urlSet, $this->trainingLibUrl);

    $this->urlSet = $trainingVids->getUrlSet();
  }

  protected function doHomepage() {
    if ($this->lang == 'cn') {
      $url = '';
    } else {
      $url = $this->lang;
    }

    $hp = new igLink($url, $this->lang, 'homepage', 'homepage', '0', '');

    $hp->changeFreq = 'daily';

    $this->urlSet[$this->lang] = $hp;
  }

  function writeDB() {


    ksort($this->urlSet);

    // Number of records to insert into the db at a time.  Adjust to fine tune performance
    //$writes_per_insert = 1200; ~400 seconds
    $writes_per_insert = 200;

    $query = db_insert('igsitemap_links')->fields(['identifier', 'url', 'language', 'bucket']);
    $count = 0;

    foreach ($this->urlSet as $url => $link) {

      $query->values($link->buildDB());
      $count++;

      if ($count >= $writes_per_insert) {
        $query->execute();
        $count = 0;
        $query = db_insert('igsitemap_links')->fields(['identifier', 'url', 'language', 'bucket']);
      }
    }
    if ($count > 0)
      $query->execute();

  }

  function write() {

    $buckets = [
      'general',
      'products',
      'learn',
      'support',
    ];

    // For german child languages there will be no products or learn sitemaps
//    $de_child_skip = ['learn', 'products'];

    $bucketUrlSets = [];
    foreach ($buckets as $bucket) {
      $bucketUrlSets[$bucket] = new Urlset();
    }

    $imageUrls = new Urlset();
    $videoUrls = new Urlset();

    foreach ($this->urlSet as $url => $link) {

      $id_parts = explode('|', $link->identifier);

      if (!empty($this->excluded[$id_parts[0]])) {
        $etype = $this->excluded[$id_parts[0]];

        if (in_array($id_parts[2], $etype)) {
          continue;
        }
      }

      $xmllink = $link->build();


      /*
      if($this->lang !== 'de-de'
        && strpos($this->lang, 'de') === 0
        && in_array($link->bucket, $de_child_skip)){
        //Skip de child locales
        continue;
      }
      */

      $bucketUrlSets[$link->bucket]->add($xmllink);

      //@todo: if the link has image or video also add it to the video/image sitemaps.
      $xmlImageLink = $link->buildImage();

      if (!empty($xmlImageLink)) {
        $imageUrls->add($xmlImageLink);
      }

      $xmlVideoLink = $link->buildVideo();

      if (!empty($xmlVideoLink)) {
        $videoUrls->add($xmlVideoLink);
      }
    }

    $dir = 'public://igxmlsitemap/' . $this->lang;
    file_prepare_directory($dir, FILE_CREATE_DIRECTORY);

    foreach ($buckets as $bucket) {
/*
      if($this->lang !== 'de-de'
        && strpos($this->lang, 'de') === 0
        && in_array($link->bucket, $de_child_skip)){
        //Skip de child locales
        continue;
      }
*/
      $this->_save_data($bucketUrlSets[$bucket], $dir . "/sitemap-$bucket.xml");
    }

    $this->_save_data($imageUrls, $dir . "/sitemap-image.xml");
    //$this->_save_data($videoUrls, $dir . "/sitemap-video.xml");
  }

  protected function _save_data($urlSet, $dest) {
    $driver = new XmlWriterDriver();

    $style_path = '/' . drupal_get_path('module', 'igcommerce_xmlsitemap') . '/stylesheet.xsl';

    $driver->addProcessingInstructions('xml-stylesheet', 'type="text/xsl" href="' . $style_path . '"');

    $urlSet->accept($driver);
    $data = $driver->output();

    file_save_data($data, $dest, FILE_EXISTS_REPLACE);
  }
}

/*
Where are the images?

  Url Builder     - ts_cat_img_toc_desktop
  Toc             - product lists (products, accessories, kits), top sellers, sm_toc_special_event,
  Product Display - slideshow, related products/accessories?


 */