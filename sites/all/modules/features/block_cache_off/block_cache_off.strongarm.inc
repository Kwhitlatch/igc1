<?php
/**
 * @file
 * block_cache_off.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function block_cache_off_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'block_cache';
  $strongarm->value = 0;
  $export['block_cache'] = $strongarm;

  return $export;
}
