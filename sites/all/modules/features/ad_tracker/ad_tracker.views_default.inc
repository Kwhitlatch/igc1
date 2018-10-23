<?php
/**
 * @file
 * ad_tracker.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ad_tracker_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ad_tracker';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'redirect';
  $view->human_name = 'Ad Tracker';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ad Tracker';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'manage adtracker';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'access' => 'access',
    'count' => 'count',
    'source' => 'source',
    'redirect' => 'redirect',
    'language' => 'language',
    'rid' => 'rid',
    'uid' => 'uid',
    'name' => 'name',
    'edit_redirect' => 'edit_redirect',
    'status' => 'status',
    'status_code' => 'status_code',
    'activate_on' => 'activate_on',
    'deactivate_on' => 'deactivate_on',
  );
  $handler->display->display_options['style_options']['default'] = 'access';
  $handler->display->display_options['style_options']['info'] = array(
    'access' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'source' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'redirect' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_redirect' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'activate_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'deactivate_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Redirect: User ID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'redirect';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Redirect: Redirect ID */
  $handler->display->display_options['relationships']['rid']['id'] = 'rid';
  $handler->display->display_options['relationships']['rid']['table'] = 'redirect';
  $handler->display->display_options['relationships']['rid']['field'] = 'rid';
  $handler->display->display_options['relationships']['rid']['required'] = TRUE;
  /* Field: Redirect: Last accessed date */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'redirect';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'short';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Redirect: Clicks */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'redirect';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  /* Field: Redirect: Source URL */
  $handler->display->display_options['fields']['source']['id'] = 'source';
  $handler->display->display_options['fields']['source']['table'] = 'redirect';
  $handler->display->display_options['fields']['source']['field'] = 'source';
  $handler->display->display_options['fields']['source']['label'] = 'Vanity URL';
  $handler->display->display_options['fields']['source']['absolute'] = 0;
  /* Field: Redirect: Redirect URL */
  $handler->display->display_options['fields']['redirect']['id'] = 'redirect';
  $handler->display->display_options['fields']['redirect']['table'] = 'redirect';
  $handler->display->display_options['fields']['redirect']['field'] = 'redirect';
  $handler->display->display_options['fields']['redirect']['label'] = 'Redirects To';
  $handler->display->display_options['fields']['redirect']['absolute'] = 0;
  /* Field: Redirect: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'redirect';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Redirect: Redirect ID */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'redirect';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  /* Field: Redirect: User ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'redirect';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Redirect: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'redirect';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'enabled-disabled';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Redirect: Status Code */
  $handler->display->display_options['fields']['status_code']['id'] = 'status_code';
  $handler->display->display_options['fields']['status_code']['table'] = 'redirect';
  $handler->display->display_options['fields']['status_code']['field'] = 'status_code';
  $handler->display->display_options['fields']['status_code']['exclude'] = TRUE;
  /* Field: Redirect Scheduler: Active-on Date */
  $handler->display->display_options['fields']['activate_on']['id'] = 'activate_on';
  $handler->display->display_options['fields']['activate_on']['table'] = 'redirect_schedule';
  $handler->display->display_options['fields']['activate_on']['field'] = 'activate_on';
  $handler->display->display_options['fields']['activate_on']['relationship'] = 'rid';
  $handler->display->display_options['fields']['activate_on']['label'] = 'Start Date';
  $handler->display->display_options['fields']['activate_on']['date_format'] = 'short';
  $handler->display->display_options['fields']['activate_on']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Redirect Scheduler: Deactive-on Date */
  $handler->display->display_options['fields']['deactivate_on']['id'] = 'deactivate_on';
  $handler->display->display_options['fields']['deactivate_on']['table'] = 'redirect_schedule';
  $handler->display->display_options['fields']['deactivate_on']['field'] = 'deactivate_on';
  $handler->display->display_options['fields']['deactivate_on']['relationship'] = 'rid';
  $handler->display->display_options['fields']['deactivate_on']['label'] = 'End Date';
  $handler->display->display_options['fields']['deactivate_on']['date_format'] = 'short';
  $handler->display->display_options['fields']['deactivate_on']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Redirect: Operations */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'redirect';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  /* Filter criterion: Redirect: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'redirect';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Redirect: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'redirect';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Redirect: Source URL */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'redirect';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['exposed'] = TRUE;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'Vanity URL';
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Redirect: Status Code */
  $handler->display->display_options['filters']['status_code']['id'] = 'status_code';
  $handler->display->display_options['filters']['status_code']['table'] = 'redirect';
  $handler->display->display_options['filters']['status_code']['field'] = 'status_code';
  $handler->display->display_options['filters']['status_code']['value']['value'] = '302';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/config/search/ad-tracker';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ad Tracker 302 Redirects';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['ad_tracker'] = array(
    t('Master'),
    t('Ad Tracker'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('user'),
    t('redirect schedule'),
    t('Last accessed date'),
    t('Clicks'),
    t('Vanity URL'),
    t('Redirects To'),
    t('Language'),
    t('Redirect ID'),
    t('User ID'),
    t('Name'),
    t('Status'),
    t('Status Code'),
    t('Start Date'),
    t('End Date'),
    t('Operations'),
    t('Page'),
  );
  $export['ad_tracker'] = $view;

  return $export;
}
