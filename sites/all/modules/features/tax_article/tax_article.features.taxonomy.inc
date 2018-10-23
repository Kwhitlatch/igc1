<?php
/**
 * @file
 * tax_article.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tax_article_taxonomy_default_vocabularies() {
  return array(
    'article' => array(
      'name' => 'Article',
      'machine_name' => 'article',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
