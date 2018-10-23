<?php
/**
 * @file
 * tax_meas_data.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_data_taxonomy_default_vocabularies() {
  return array(
    'data' => array(
      'name' => 'Measurement - Data',
      'machine_name' => 'data',
      'description' => 'Data Product Specifications',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
