<?php
/**
 * @file
 * ig_wtb_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ig_wtb_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
