<?php
/**
 * @file
 * tax_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_news_taxonomy_default_vocabularies() {
  return array(
    'temperature' => array(
      'name' => 'Measurement - Temperature',
      'machine_name' => 'temperature',
      'description' => 'Temperature Product Specifications Filters',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
