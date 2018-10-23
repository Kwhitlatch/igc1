<?php
/**
 * @file
 * tax_url_builder.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_url_builder_taxonomy_default_vocabularies() {
  return array(
    'url_builder' => array(
      'name' => 'URL Builder',
      'machine_name' => 'url_builder',
      'description' => 'By selecting one option from this list - it will build the URL for you. Domain/Locale/YOUR-SELECTION/content-piece-url-title-.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
