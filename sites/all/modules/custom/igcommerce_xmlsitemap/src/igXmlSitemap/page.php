<?php

namespace igXmlSitemap;


class page extends igXmlSitemapItemBase {
  function __construct($lang, $urlSet) {
    parent::__construct($lang, 'page', 'node');

    $this->urlSet = $urlSet;

    foreach($this->docs as $doc){
      if(empty($doc->sm_url_path_builder[0])){
        continue;
      }

      if(!empty($doc->bs_noindex)){
        unset($this->urlSet['$url']);
        continue;
      }

      $this->collection[$doc->entity_id] = $doc;

      $url = $this->calculateUrl($doc);

      if(!empty($url)) {
        $this->urlSet[$url] = new igLink($url, $lang, 'node', 'article', $doc->entity_id, $doc->ss_path_alias, $doc->ds_changed);

        if(!empty($doc->ss_toc_large_img_url)){
           $image = [
            'url' => $doc->ss_toc_large_img_url,
            'thumbnail' => $doc->ss_toc_small_img_thumbnail
          ];

          $this->urlSet[$url]->images[] = $image;
        }
        $this->urlSet[$url]->title = !empty($doc->ss_page_h1_title) ? $doc->ss_page_h1_title : $doc->sm_field_content_title[0];
      }


    }

  }
/*
  function fields(){
    return 'ss_field_url_title,sm_url_path_builder,ds_changed,entity_id,ss_path_alias_locale,ss_path_alias';
  }*/

  public function calculateUrl($doc){
    $url = parent::calculateUrl($doc);

    if(!empty($url)) {

      return $url;
    }else{
      return NULL;
    }
  }
}