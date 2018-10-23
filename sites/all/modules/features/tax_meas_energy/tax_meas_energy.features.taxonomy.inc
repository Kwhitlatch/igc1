<?php
/**
 * @file
 * tax_meas_energy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_energy_taxonomy_default_vocabularies() {
  return array(
    'energy' => array(
      'name' => 'Measurement - Energy',
      'machine_name' => 'energy',
      'description' => 'Energy Product Specifications',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
