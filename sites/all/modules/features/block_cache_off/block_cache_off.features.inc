<?php
/**
 * @file
 * block_cache_off.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function block_cache_off_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
