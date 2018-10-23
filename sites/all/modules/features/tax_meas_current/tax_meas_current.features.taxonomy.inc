<?php
/**
 * @file
 * tax_meas_current.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_current_taxonomy_default_vocabularies() {
  return array(
    'current' => array(
      'name' => 'Measurement - Current',
      'machine_name' => 'current',
      'description' => 'Current Product Specifications Filters',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
