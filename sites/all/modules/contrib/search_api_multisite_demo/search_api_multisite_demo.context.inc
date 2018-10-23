<?php
/**
 * @file
 * search_api_multisite_demo.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function search_api_multisite_demo_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_multisite';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/multisite' => 'search/multisite',
        'search/multisite/*' => 'search/multisite/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'search_multisite' => 'search_multisite',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'content',
          'weight' => '-10',
        ),
        'facetapi-iCQmHjDcFmxhLRafPQkyrUvXM1CVA06C' => array(
          'module' => 'facetapi',
          'delta' => 'iCQmHjDcFmxhLRafPQkyrUvXM1CVA06C',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-xRoEljULUDYMZ26Z7Tohpj8xNhrX9keT' => array(
          'module' => 'facetapi',
          'delta' => 'xRoEljULUDYMZ26Z7Tohpj8xNhrX9keT',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['search_multisite'] = $context;

  return $export;
}
