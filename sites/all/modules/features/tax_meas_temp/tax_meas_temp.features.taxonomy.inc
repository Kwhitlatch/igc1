<?php
/**
 * @file
 * tax_meas_temp.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_temp_taxonomy_default_vocabularies() {
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
