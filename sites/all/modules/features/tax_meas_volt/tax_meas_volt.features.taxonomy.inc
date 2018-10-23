<?php
/**
 * @file
 * tax_meas_volt.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_meas_volt_taxonomy_default_vocabularies() {
  return array(
    'voltage' => array(
      'name' => 'Measurement - Voltage',
      'machine_name' => 'voltage',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
