<?php
/**
 * @file
 * tax_meas_os.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_os_taxonomy_default_vocabularies() {
  return array(
    'oscilloscopes' => array(
      'name' => 'Measurement - Oscilloscopes',
      'machine_name' => 'oscilloscopes',
      'description' => 'Oscilloscopes Product Specifications Filters',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
