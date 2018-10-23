<?php
/**
 * Created by PhpStorm.
 * User: trev
 * Date: 13/01/18
 * Time: 1:18 PM
 */

namespace igXmlSitemap;

use Thepixeldeveloper\Sitemap\SitemapIndex;
use Thepixeldeveloper\Sitemap\Sitemap;
use Thepixeldeveloper\Sitemap\Drivers\XmlWriterDriver;

class indexWriter {
  /**
   * Generates the sitemap index file
   */
  public static function writeIndex(array $languages, $allow_cn = FALSE){
    global $base_url;

    // Add it to a collection.
    $siteMapIndex = new SitemapIndex();

    $time = new \DateTime();
    $time->setTimestamp(REQUEST_TIME);

    foreach($languages as $lang => $language){
      $types = [
        'general' => 'general',
        'products' =>'products',
        'learn' => 'learn',
        'support' =>'support',
        'image' => 'image',
        //'video'
      ];

      if($lang === 'cn'){
        // China should not have a solutions sitemap
        unset($types['solutions']);
      }

      // For german child languages there will be no products or learn sitemaps
      // based on MIG-4463 -- adding the de child languages back in for products and learn
      // on 101/9/2018 -- TT
      //$de_child_skip = ['learn', 'products'];

      foreach($types as $type) {
          /*
        if($lang !== 'de-de'
          && strpos($lang, 'de') === 0
          && in_array($type, $de_child_skip)){
          //Skip de child locales if it is learn or products
          continue;
        }
          */

        // Also skip en-tt (trinidad/tobago) since that site has been eliminated, also leave out zh-cn
        $skip = ['en-tt', 'zh-cn'];

        if (!in_array($lang, $skip) && ($lang !== 'cn' || $allow_cn === TRUE)) {
          // Sitemap entry.
          if($lang !== 'cn') {
            $url = new Sitemap($base_url . '/' . $lang . '/sitemap-' . $lang . '-' . $type . '.xml');
          }else{
            //CN doesn't have a language in the path
            $url = new Sitemap($base_url . '/sitemap-' . $lang . '-' . $type . '.xml');
          }
          $url->setLastMod($time);

          $siteMapIndex->add($url);
        }
      }
    }

    $dir = 'public://igxmlsitemap/';
    file_prepare_directory($dir, FILE_CREATE_DIRECTORY);

    $driver = new XmlWriterDriver();
    $siteMapIndex->accept($driver);

    $data = $driver->output();
    $dest = $dir . '/sitemap.xml';

    file_save_data($data, $dest, FILE_EXISTS_REPLACE);
  }
}