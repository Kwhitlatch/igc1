<?php
/**
 * @file
 * tax_opco.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_opco_taxonomy_default_vocabularies() {
  return array(
    'opco' => array(
      'name' => 'Opco',
      'machine_name' => 'opco',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
