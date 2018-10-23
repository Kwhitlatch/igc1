<?php
/**
 * @file
 * tax_meas_electrical.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_electrical_taxonomy_default_vocabularies() {
  return array(
    'electrical' => array(
      'name' => 'Measurement - Electrical',
      'machine_name' => 'electrical',
      'description' => 'Electrical Product Specifications Filters',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
