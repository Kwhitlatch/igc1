<?php

namespace igXmlSitemap;

class toc extends igXmlSitemapItemBase {
  function __construct($lang, $urlSet) {
    parent::__construct($lang, 'toc', 'node');

    $this->urlSet = $urlSet;

    foreach($this->urlSet as $linkUrl => $link){
      $found = FALSE;

      foreach($this->docs as $doc){
        $url = $this->calculateUrl($doc);

        if(!empty($doc->bs_noindex)){
          unset($this->urlSet['$url']);
          continue;
        }

        if($linkUrl === $url){

          $link->lastModified = \DateTime::createFromFormat(DATE_ISO8601, $doc->ds_changed);
          $found = TRUE;
          //@todo: images and vids associated with tocs?

          // Set the title for html sitemaps
          if(!empty($doc->ss_field_h1_title)) {
            $link->title = $doc->ss_field_h1_title;
          }elseif(!empty($doc->ss_field_content_title)){
            $link->title = $doc->ss_field_content_title;
          }

          if(empty($link->title)){
            $x = 1;
          }
        }

      }
      if($found === FALSE && $link->toc_page === TRUE){
        unset($this->urlSet[$linkUrl]);
      }
    }
  }

  /*
  function fields(){
    return 'ss_field_url_title,sm_url_path_builder,ds_changed,entity_id,ss_path_alias_locale,ss_path_alias';
  }*/
}