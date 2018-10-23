<?php
/**
 * @file
 * tax_event.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_event_taxonomy_default_vocabularies() {
  return array(
    'events' => array(
      'name' => 'Events',
      'machine_name' => 'events',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
