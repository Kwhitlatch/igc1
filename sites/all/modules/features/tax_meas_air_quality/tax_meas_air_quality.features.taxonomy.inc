<?php
/**
 * @file
 * tax_meas_air_quality.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_air_quality_taxonomy_default_vocabularies() {
  return array(
    'air_quality' => array(
      'name' => 'Measurement - Air Quality',
      'machine_name' => 'air_quality',
      'description' => 'Air Quality Product Specifications',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
