<?php
/**
 * @file
 * tax_meas_harm.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_harm_taxonomy_default_vocabularies() {
  return array(
    'harmonics' => array(
      'name' => 'Measurement - Harmonics',
      'machine_name' => 'harmonics',
      'description' => 'Harmonics Product Specifications',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
