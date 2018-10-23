<?php
/**
 * Created by PhpStorm.
 * User: trev
 * Date: 12/29/17
 * Time: 6:39 AM
 */

namespace igXmlSitemap;


class slideshow extends igXmlSitemapItemBase {
  private $collection = [];

  function __construct($lang) {
    parent::__construct($lang, 'slideshow', 'node');

    foreach($this->docs as $doc){
      $this->collection[$doc->entity_id] = $doc;
    }
  }

  function fields(){
    return 'sm_field_product_image_desktop,entity_id';
  }

  public function getCollection(){
    return $this->collection;
  }

}