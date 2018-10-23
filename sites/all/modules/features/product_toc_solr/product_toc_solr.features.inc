<?php
/**
 * @file
 * product_toc_solr.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function product_toc_solr_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function product_toc_solr_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
