<?php
/**
 * @file
 * tax_solutions.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_solutions_taxonomy_default_vocabularies() {
  return array(
    'solutions' => array(
      'name' => 'Solutions',
      'machine_name' => 'solutions',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
