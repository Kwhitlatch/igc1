<?php
/**
 * @file
 * fluke_articles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fluke_articles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "fieldable_panels_panes" && $api == "fieldable_panels_pane_type") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fluke_articles_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
