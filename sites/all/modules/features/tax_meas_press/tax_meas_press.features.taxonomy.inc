<?php
/**
 * @file
 * tax_meas_press.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_press_taxonomy_default_vocabularies() {
  return array(
    'pressure' => array(
      'name' => 'Measurement - Pressure',
      'machine_name' => 'pressure',
      'description' => 'Pressure Product Specifications Filters',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
