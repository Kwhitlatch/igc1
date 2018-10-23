<?php
/**
 * @file
 * igcommerce_event1.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function igcommerce_event_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_application_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_application_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_industry_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_industry_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_product_category_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_product_category_pattern'] = $strongarm;

  return $export;
}
