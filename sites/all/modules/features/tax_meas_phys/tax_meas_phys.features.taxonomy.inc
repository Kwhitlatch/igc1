<?php
/**
 * @file
 * tax_meas_phys.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_phys_taxonomy_default_vocabularies() {
  return array(
    'physical' => array(
      'name' => 'Measurement - Physical',
      'machine_name' => 'physical',
      'description' => 'Physical Product Specifications Filters',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
