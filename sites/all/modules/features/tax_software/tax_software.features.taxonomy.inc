<?php
/**
 * @file
 * tax_software.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_software_taxonomy_default_vocabularies() {
  return array(
    'software' => array(
      'name' => 'Software',
      'machine_name' => 'software',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
