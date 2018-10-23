<?php
/**
 * @file
 * tax_accessory.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_accessory_taxonomy_default_vocabularies() {
  return array(
    'accessory_type' => array(
      'name' => 'Accessory Type',
      'machine_name' => 'accessory_type',
      'description' => 'Sub-Category of Accessory',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
