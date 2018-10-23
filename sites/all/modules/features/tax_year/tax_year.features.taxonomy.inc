<?php
/**
 * @file
 * tax_year.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_year_taxonomy_default_vocabularies() {
  return array(
    'year' => array(
      'name' => 'Year',
      'machine_name' => 'year',
      'description' => '4 digit year',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
