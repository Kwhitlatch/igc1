<?php
/**
 * @file
 * tax_industry.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_industry_taxonomy_default_vocabularies() {
  return array(
    'industry_segment' => array(
      'name' => 'Industry Segment',
      'machine_name' => 'industry_segment',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
