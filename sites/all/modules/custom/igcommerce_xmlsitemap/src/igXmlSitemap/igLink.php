<?php
/**
 * Created by PhpStorm.
 * User: trev
 * Date: 12/28/17
 * Time: 1:25 PM
 */

namespace igXmlSitemap;

use Thepixeldeveloper\Sitemap\Url;
use Thepixeldeveloper\Sitemap\Extensions\Image;
use Thepixeldeveloper\Sitemap\Extensions\Video;
use Thepixeldeveloper\Sitemap\Extensions\Link;

class igLink {
  public $link;
  public $lastModified;
  public $priority = '.5';
  public $changeFreq = 'weekly';
  public $identifier = '';
  public $language = '';
  public $bucket = '';

  function __construct($link, $language, $entity, $bundle, $id, $path_alias, $lastModified = REQUEST_TIME) {
    $this->link = strtolower($link);

    $this->bucket = $this->calculateBucket($path_alias);

    $this->language = $language;

    $this->identifier = $entity . '|' . $bundle . '|' . $id;

    if (is_numeric($lastModified)) {
      $this->lastModified = new \DateTime();
      $this->lastModified->setTimestamp($lastModified);
    } else {
      $this->lastModified = $this->fromSolrDate($lastModified);
    }
  }

  /**
   * Use the untranslated path alias to figure out which sheet the link should go in
   *
   * @param $path_alias
   */
  private function calculateBucket($path_alias) {
    $bucket = 'general';
    $buckets = [
      'product' => 'products',
      'products' => 'products',
      'learn' => 'learn',
      'support' => 'support',
    ];

    $parts = explode('/', $path_alias);

    if (isset($buckets[$parts[0]])) {
      $bucket = $buckets[$parts[0]];
    }

    return $bucket;
  }

  private function fromSolrDate($date) {
    return \DateTime::createFromFormat(DATE_ISO8601, $date);
  }

  function buildDB() {
    $base_url = $this->baseUrl();

    return [
      'identifier' => $this->identifier,
      'url' => $base_url . '/' . $this->link,
      'language' => $this->language,
      'bucket' => $this->bucket,
    ];

  }

  private function baseUrl() {
    global $base_url;
    //$base_url = 'https://live-igcommerce.pantheonsite.io'; // Useful for debugging integrity check


    if ($this->language === 'cn') {
      $base_url = 'https://www.fluke.com.cn';

      // Useful items for testing:
      //$base_url = 'https://staging.fluke.com.cn';
      //$base_url = 'http://live-chinapoc.flukedev.com';

      $this->link = str_replace('cn/', '', $this->link);


    } else {
      $base_url = 'https://www.fluke.com';
    }

    return $base_url;
  }

  function build() {
    $base_url = $this->baseUrl();

    $url = $base_url . '/' . $this->link;

    $return = new Url($url);

    $return->setPriority($this->priority);
    $return->setLastMod($this->lastModified);
    $return->setChangeFreq($this->changeFreq);

    /*
    // Moved to a different sheet
    // extensions for video and images
    if (!empty($this->images)) {
      foreach ($this->images as $imageData) {

        if (strpos($imageData->url, 'brightcove') !== FALSE || strpos($imageData->url, 'youtube') !== FALSE) {

          $item = new Video($imageData->thumbnail, $imageData->caption, $imageData->alt);

          if($imageData->url === NULL){
            continue;
          }

          // @todo: SEO people may want this to be swapped, or done differently
          if (strpos($imageData->url, 'brightcove') !== FALSE) {
            $item->setContentLoc('https:' . $imageData->url);
          } else {
            $item->setContentLoc($imageData->url);
          }

          //@todo: any other properties we need? https://developers.google.com/webmasters/videosearch/sitemaps
        } else {
          // some images are indexed with their drupal rather than s3 location

          $s3_url = variable_get('s3_bucket_url', '');
          $default_assets_url = 'data.fluke.com/sites/default/files';
          $url = $imageData['url'];

          if (strpos($url, $default_assets_url)) {
            $url = str_replace($default_assets_url, $s3_url, $url);
            $url = str_replace("//http://", "http://", $url);
          }

          if(strpos($url, '//') === 0){
            $url = 'https:'.$url;
          }

          if($url === NULL){
            continue;
          }

          $item = new Image($url);

          // @todo: SEO people may want this to be swapped, or done differently
          $item->setCaption($imageData['caption']);
          $item->setTitle($imageData['alt']);
        }

        $return->addExtension($item);
      }
    }
    */

    // For german child languages there will be no products or learn sitemaps
//    $de_child_skip = ['learn', 'products'];

    if ($this->language != 'cn') {

      // Add hreflang links
      $db = $this->buildDB();

      $hreflanglinks = db_select('igsitemap_links', 'l')
        ->fields('l')
        ->condition('identifier', $db['identifier'])
        ->execute()
        ->fetchAllAssoc('id');

      foreach ($hreflanglinks as $item) {

        if ($item->language !== 'zh-cn' && $item->language !== 'cn') {

/*
          if($item->language !== 'de-de'
            && strpos($item->language, 'de') === 0
            && in_array($this->bucket, $de_child_skip)){
            //Skip de child locales if it is learn or products
            continue;
          }
*/
          $hreflink = new Link($item->language, $item->url);
          $return->addExtension($hreflink);

          if ($item->language === 'en-us') {
            //put in the default link
            $hreflink = new Link('x-default', $item->url);
            $return->addExtension($hreflink);
          }
        }
      }
    }

    return $return;
  }

  function buildImage() {
    $return = NULL;
    $itemsAdded = FALSE;

    if (count($this->images)) {

      $base_url = $this->baseUrl();

      $url = $base_url . '/' . $this->link;

      $return = new Url($url);

      $return->setPriority($this->priority);
      $return->setLastMod($this->lastModified);
      $return->setChangeFreq($this->changeFreq);


      foreach ($this->images as $imageData) {
        $item = NULL;

        if (strpos($imageData['url'], 'download.fluke.com') !== FALSE) {
          // Skip our old videos that use flash
          continue;
        }

        if (strpos($imageData['url'], 'brightcove') !== FALSE || strpos($imageData['url'], 'youtube') !== FALSE) {
          // Video, do nothing
        } else {
          // some images are indexed with their drupal rather than s3 location

          if($this->language != 'cn') {
            $s3_url = variable_get('s3_bucket_url', '');
          }else{
            $s3_url = 'dam-assets.fluke.com.cn';
          }

          $default_assets_url = 'data.fluke.com/sites/default/files';

          $url = $imageData['url'];

          if (strpos($url, $default_assets_url)) {
            $url = str_replace($default_assets_url, $s3_url, $url);
            $url = str_replace("//http://", "http://", $url);
          }

          // Different dam url for china
          if($this->language === 'cn' && strpos($url, 'dam-assets.fluke.com/s3fs-public')){
            $url = str_replace('dam-assets.fluke.com/s3fs-public', $s3_url.'/s3fs-public', $url);
          }

          if (strpos($url, '//') === 0) {
            $url = 'https:' . $url;
          }

          if ($url === NULL) {
            continue;
          }

          $item = new Image($url);

          // @todo: SEO people may want this to be swapped, or done differently
          $item->setCaption($imageData['caption']);
          $item->setTitle($imageData['alt']);
        }
        if ($item) {
          $itemsAdded = TRUE;
          $return->addExtension($item);
        }
      }
    }
    if ($itemsAdded === TRUE) {
      return $return;
    } else {
      return NULL;
    }
  }

  function buildVideo() {
    $return = NULL;
    $itemsAdded = FALSE;

    if (count($this->images)) {
      $base_url = $this->baseUrl();

      $url = $base_url . '/' . $this->link;

      $return = new Url($url);

      $return->setPriority($this->priority);
      $return->setLastMod($this->lastModified);
      $return->setChangeFreq($this->changeFreq);

      $item = FALSE;

      foreach ($this->images as $imageData) {
        if (strpos($imageData['url'], 'download.fluke.com') !== FALSE) {
          // Skip our old videos taht use flash
          continue;
        }


        if (strpos($imageData['url'], 'brightcove') !== FALSE
          || strpos($imageData['url'], 'youtube') !== FALSE
          || !empty($imageData['video'])) {

          if ($imageData['url'] === NULL) {
            continue;
          }

          $item = new Video($imageData['thumbnail'], $imageData['caption'], $imageData['alt']);

          // @todo: SEO people may want this to be swapped, or done differently
          if (strpos($imageData['url'], 'brightcove') !== FALSE) {
            $item->setContentLoc('https:' . $imageData['url']);
          } else {
            $item->setContentLoc($imageData['url']);
          }

          //@todo: any other properties we need? https://developers.google.com/webmasters/videosearch/sitemaps
        } else {
          // Image, do nothing
        }
        if ($item) {
          $itemsAdded = TRUE;
          $return->addExtension($item);
        }
      }
    }
    if ($itemsAdded === TRUE) {
      return $return;
    } else {
      return NULL;
    }
  }

}