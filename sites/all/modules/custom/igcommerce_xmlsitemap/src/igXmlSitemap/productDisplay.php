<?php
/**
 * Created by PhpStorm.
 * User: trev
 * Date: 12/28/17
 * Time: 1:47 PM
 */

namespace igXmlSitemap;


class productDisplay extends igXmlSitemapItemBase {
  function __construct($lang, $urlSet, $slideshows) {
    parent::__construct($lang, 'product_display', 'node');

    $this->urlSet = $urlSet;

    foreach($this->docs as $doc){
      $url = $this->calculateUrl($doc);

      if(!empty($doc->bs_noindex)){
        unset($this->urlSet['$url']);
        continue;
      }

      // Skip recalled and discontinued products
      if(!empty($doc->tm_alerts)){
        continue;
      }

      if(!empty($url)) {
        $this->urlSet[$url] = new igLink($url, $lang, 'node', 'product_display', $doc->entity_id, $doc->ss_path_alias, $doc->ds_changed);
        $this->urlSet[$url]->label = $doc->label;
      }else{
        // If we can't produce a valid url then skip.  Most likely url builder isn't set, and the item doesn't show up on the site
        continue;
      }
      // check for a slideshow in the collection
      if(!empty($doc->is_product_slideshow) && !empty($slideshows[$doc->is_product_slideshow])){
        $product_slideshow = $slideshows[$doc->is_product_slideshow];

        if(!empty($product_slideshow->sm_field_product_image_desktop)) {
          foreach ($product_slideshow->sm_field_product_image_desktop as $image) {
            $data = json_decode($image, TRUE);

            $X = 1; //@TODO: Is there any way to identify which items are videos?

            $this->urlSet[$url]->images[] = $data;
          }
        }
      }
    }
  }

  function fields(){
    return 'ss_field_url_title,is_product_slideshow,sm_url_path_builder,ds_changed,entity_id,tm_alerts,ss_path_alias_locale,ss_path_alias,label';
  }

  /*

  function calculateUrl($doc){
    $parts = json_decode($doc->sm_url_path_builder[0]);
    if(is_array($parts)) {
      $parts = array_reverse($parts);
    }else{
      return NULL;
    }

    unset($parts[0]);

    $terms = taxonomy_get_term_by_name('product', 'url_builder');

    $term = array_pop($terms);

    $part = !empty($term->field_url_title[$this->lang][0]['value'])
      ? $term->field_url_title[$this->lang][0]['value']
      : $term->field_url_title['en'][0]['value'];

    $parts[1] = $part;

    return $this->lang .'/'.implode('/', $parts). '/'. $doc->ss_field_url_title;
  }*/
}