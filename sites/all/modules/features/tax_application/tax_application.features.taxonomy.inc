<?php
/**
 * @file
 * tax_application.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_application_taxonomy_default_vocabularies() {
  return array(
    'application' => array(
      'name' => 'Application',
      'machine_name' => 'application',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
