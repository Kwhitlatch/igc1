<?php
/**
 * @file
 * search_api_multisite_demo.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function search_api_multisite_demo_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_search-multisite:search/multisite
  $menu_links['navigation_search-multisite:search/multisite'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'search/multisite',
    'router_path' => 'search/multisite',
    'link_title' => 'Search multisite',
    'options' => array(
      'identifier' => 'navigation_search-multisite:search/multisite',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Search multisite');


  return $menu_links;
}
