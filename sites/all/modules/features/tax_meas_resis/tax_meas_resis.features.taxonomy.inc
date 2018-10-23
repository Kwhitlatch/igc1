<?php
/**
 * @file
 * tax_meas_resis.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_resis_taxonomy_default_vocabularies() {
  return array(
    'resistance' => array(
      'name' => 'Measurement - Resistance',
      'machine_name' => 'resistance',
      'description' => 'Resistance Product Specifications Filters',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
