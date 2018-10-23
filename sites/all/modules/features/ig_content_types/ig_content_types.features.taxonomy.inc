<?php
/**
 * @file
 * ig_content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ig_content_types_taxonomy_default_vocabularies() {
  return array(
    'application' => array(
      'name' => 'Application',
      'machine_name' => 'application',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'article' => array(
      'name' => 'Article',
      'machine_name' => 'article',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'digital_asset_type_external_' => array(
      'name' => 'Digital Asset Type (External)',
      'machine_name' => 'digital_asset_type_external_',
      'description' => 'For Partner Portal & SyncForce Links',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'events' => array(
      'name' => 'Events',
      'machine_name' => 'events',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'industry_segment' => array(
      'name' => 'Industry Segment',
      'machine_name' => 'industry_segment',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'opco' => array(
      'name' => 'Opco',
      'machine_name' => 'opco',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'product' => array(
      'name' => 'Product',
      'machine_name' => 'product',
      'description' => 'Primary product category, URL and breadcrumb, only select one',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'region' => array(
      'name' => 'Region',
      'machine_name' => 'region',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'site_section' => array(
      'name' => 'Site Section',
      'machine_name' => 'site_section',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'topic' => array(
      'name' => 'News Topic',
      'machine_name' => 'topic',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
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
