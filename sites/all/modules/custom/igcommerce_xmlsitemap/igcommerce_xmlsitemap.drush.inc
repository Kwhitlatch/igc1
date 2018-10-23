<?php

function igcommerce_xmlsitemap_drush_command() {
  $items = array();

  $items['ig-xml-map-rebuild'] = array(
    'description' => "Rebuild the sitemaps with fresh data from solr.",
    'examples' => array(
      'drush igxr' => 'Rebuild sitemaps for all languages',
    ),
    'aliases' => array('igxr'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL
  );

  $items['ig-xml-map-rebuild-china'] = array(
    'description' => "Rebuild the sitemaps with fresh data from solr.",
    'examples' => array(
    'drush igxrcn' => 'Rebuild sitemaps for all China',
  ),
    'aliases' => array('igxrcn'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL
  );

  $items['ig-xml-map-integrity-check'] = array(
    'description' => "Check links for validity.",
    'arguments' => array(
      'lang' => 'Check for one language, if not provided all languages will be checked. Example: en-us',
    ),
    'examples' => array(
      'drush igxric en-us' => 'Checks links for the en-us sitemap',
      'drush igxric' => 'Checks links for all languages',
    ),
    'aliases' => array('igxric'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL
  );

  $items['ig-xml-map-generate-html'] = array(
    'description' => "Generate HTML Sitemaps.  This command shouldn't be run on production, otherwise you might need to re-run igxr.",
    'aliases' => array('ightml'),
    'arguments' => array(
      'lang' => 'Generate html sitemap for one language, if not provided all languages will be checked. Example: en-us',
    ),
  );

  return $items;
}

function drush_igcommerce_xmlsitemap_ig_xml_map_rebuild(){
  igcommerce_xmlsitemap_rebuild();
}

function drush_igcommerce_xmlsitemap_ig_xml_map_rebuild_china(){
  igcommerce_xmlsitemap_rebuild_china();
}

function drush_igcommerce_xmlsitemap_ig_xml_map_integrity_check($lang = NULL){
  igcommerce_xmlsitemap_integrity_check($lang);
}

function drush_igcommerce_xmlsitemap_ig_xml_map_generate_html($lang = NULL){
  igcommerce_xmlsitemap_generate_html_maps($lang);
}