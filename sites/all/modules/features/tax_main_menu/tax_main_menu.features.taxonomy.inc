<?php
/**
 * @file
 * tax_main_menu.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_main_menu_taxonomy_default_vocabularies() {
  return array(
    'main_menu' => array(
      'name' => 'Main Menu',
      'machine_name' => 'main_menu',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
