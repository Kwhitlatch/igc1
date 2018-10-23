<?php

namespace igXmlSitemap;

abstract class igXmlSitemapItemBase {
  public $lang;
  public $bundle;
  public $entity_type;
  public $docs = [];
  public $fails = 0;

  function __construct($lang, $bundle, $entity_type) {
    $this->lang = $lang;
    $this->bundle = $bundle;
    $this->entity_type = $entity_type;

    $this->query();
  }

  function filters() {
    $return = [
      "bundle" => $this->bundle,
      "entity_type" => $this->entity_type,
      "ss_language" => $this->lang,
    ];

    if ($this->entity_type === 'node') {
      $return['bs_status'] = TRUE;
    }

    if (method_exists($this, 'alterFilters')) {
      $this->alterFilters($return);
    }

    return $return;
  }

  function query(){

    $options = array('filters' => $this->filters(), 'rows' => 1500);

    // If the derived class has a fields method, use this to specify which fields to return
    // Implementing a fields method can speed up the process and prevent timeouts
    if(method_exists($this, 'fields')){
      $options['fl'] = $this->fields();

      // Also make sure we are including the bs_noindex field
      $options['fl'] .= ',bs_noindex';
    }

    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query, $options);

    try {
      if(drupal_is_cli()){
        echo 'Querying solr for '. $this->bundle .'...';

        $start_time = time();
      }
      $response = fluke_solr_query($filters);
    }catch(\Exception $e){
      $this->fails ++;
      if(drupal_is_cli() && $this->fails < 3){
        echo "Query failed!  Attempting to retry...".PHP_EOL;
      }

      if($this->fails < 3){
        $this->query();
      }elseif(drupal_is_cli()){
        echo "Failed to query solr multiple times.  Aborting.".PHP_EOL;

        exit(1);
      }
    }

    if(drupal_is_cli()){
      $end_time = time();

      $seconds = $end_time - $start_time;

      echo 'completed in '. $seconds .' seconds.'.PHP_EOL;
    }

    $this->docs = $response->response->docs;
  }

  function calculateUrl($doc){

    if(!empty($doc->ss_field_url)) {

      return $this->lang .'/'.$doc->ss_field_url;

    }elseif(empty($doc->ss_path_alias_locale)) {
      $parts = json_decode($doc->sm_url_path_builder[0]);

      if (is_array($parts) && count($parts > 1) && $parts[0] !== 'null') {
        $parts = array_reverse($parts);
        unset($parts[0]);

        return $this->lang . '/' . implode('/', $parts). '/' . $doc->ss_field_url_title;
      }
    }else{
      // Items in url builder that start with fluke/ for their path are actually supposed to be at the root of the site.
      $path_alias_locale = $doc->ss_path_alias_locale;

      if(strpos($path_alias_locale, 'fluke/') === 0){
        //@todo: this no longer appears to be the case

        //$path_alias_locale = str_replace('fluke/', '', $path_alias_locale);;
      }

      return $this->lang .'/'. $path_alias_locale;
    }
    return NULL;
  }

  function getUrlSet(){
    return $this->urlSet;
  }
}