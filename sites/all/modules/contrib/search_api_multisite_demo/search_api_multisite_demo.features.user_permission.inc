<?php
/**
 * @file
 * search_api_multisite_demo.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function search_api_multisite_demo_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access search api multisite search'.
  $permissions['access search api multisite search'] = array(
    'name' => 'access search api multisite search',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_multisite_demo',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(),
    'module' => 'search_api',
  );

  return $permissions;
}
