<?php
/**
 * Created by PhpStorm.
 * User: trev
 * Date: 12/27/17
 * Time: 3:38 PM
 */

namespace igXmlSitemap;

class urlBuilder extends igXmlSitemapItemBase {
  function __construct($lang) {
    parent::__construct($lang, 'url_builder', 'taxonomy_term');

    $this->urlSet = [];

    $allTocs = igcommerce_xmlsitemap_toc_paths();

    foreach($this->docs as $doc){

      if(!empty($doc->bs_noindex)){
        continue;
      }

      if(!empty($doc->bs_field_hide_from_toc_left_navigat)){
        continue;
      }

      if(!empty($doc->ss_field_url)){
        global $base_url;
        // Don't index url builder items that link to external pages.
        if(strpos($doc->ss_field_url, '//') && strpos($doc->ss_field_url, $base_url) === FALSE){
          continue;
        }
      }

      $url = $this->calculateUrl($doc);
      $this->urlSet[$url] = new igLink($url, $lang, 'taxonomy_term', 'url_builder', $doc->entity_id, $doc->ss_path_alias);

      $this->urlSet[$url]->label = $doc->label;
      $this->urlSet[$url]->title = !empty($doc->ss_url_builder_term_h1_title) ? $doc->ss_url_builder_term_h1_title : $doc->sm_field_content_title[0];

      if(!empty($doc->ts_cat_img_toc_desktop)) {
        $desktop_img = json_decode($doc->ts_cat_img_toc_desktop);

        $image = [
          'url' => $desktop_img->img_url,
          'alt' => $desktop_img->img_alt,
          'caption' => $desktop_img->img_caption
        ];

        $this->urlSet[$url]->images[] = $image;
      }

      if($doc->label === 'Webinars'){
        $this->webinarsUrl = $url;
      }

      if($doc->entity_id == '2238'){
        $this->trainingLibUrl = $url;
      }

      if(!empty($allTocs[$doc->ss_path_alias])){
        $this->urlSet[$url]->toc_page = TRUE;
      }else{
        $this->urlSet[$url]->toc_page = FALSE;
      }

    }
  }

  public function fields(){
    return 'ts_cat_img_toc_desktop,entity_id,sm_url_path_builder,ss_path_alias_locale,ss_field_url,ss_path_alias,sm_field_content_title,ss_url_builder_term_h1_title,label,bs_field_hide_from_toc_left_navigat';
  }
}

