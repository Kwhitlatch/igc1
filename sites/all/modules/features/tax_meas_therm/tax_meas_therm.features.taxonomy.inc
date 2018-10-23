<?php
/**
 * @file
 * tax_meas_therm.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_therm_taxonomy_default_vocabularies() {
  return array(
    'thermocouples' => array(
      'name' => 'Measurement - Thermocouples',
      'machine_name' => 'thermocouples',
      'description' => 'Thermocouples Product Specifications Filters',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
