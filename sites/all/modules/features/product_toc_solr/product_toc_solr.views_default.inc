<?php
/**
 * @file
 * product_toc_solr.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function product_toc_solr_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_toc';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product TOC';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_toc_top_sellers_taxonomy_term']['id'] = 'reverse_field_toc_top_sellers_taxonomy_term';
  $handler->display->display_options['relationships']['reverse_field_toc_top_sellers_taxonomy_term']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_toc_top_sellers_taxonomy_term']['field'] = 'reverse_field_toc_top_sellers_taxonomy_term';
  /* Field: Content: Top Sellers */
  $handler->display->display_options['fields']['field_top_sellers_solr']['id'] = 'field_top_sellers_solr';
  $handler->display->display_options['fields']['field_top_sellers_solr']['table'] = 'field_data_field_top_sellers_solr';
  $handler->display->display_options['fields']['field_top_sellers_solr']['field'] = 'field_top_sellers_solr';
  $handler->display->display_options['fields']['field_top_sellers_solr']['label'] = '';
  $handler->display->display_options['fields']['field_top_sellers_solr']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_top_sellers_solr']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_top_sellers_solr']['type'] = 'apachesolr_reference_formatter_ids';
  $handler->display->display_options['fields']['field_top_sellers_solr']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_top_sellers_solr']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'toc' => 'toc',
  );
  /* Filter criterion: Content: Top Sellers (field_top_sellers_solr) */
  $handler->display->display_options['filters']['field_top_sellers_solr_target_id']['id'] = 'field_top_sellers_solr_target_id';
  $handler->display->display_options['filters']['field_top_sellers_solr_target_id']['table'] = 'field_data_field_top_sellers_solr';
  $handler->display->display_options['filters']['field_top_sellers_solr_target_id']['field'] = 'field_top_sellers_solr_target_id';
  $handler->display->display_options['filters']['field_top_sellers_solr_target_id']['operator'] = 'not empty';

  /* Display: Top Sellers */
  $handler = $view->new_display('block', 'Top Sellers', 'top_sellers');

  /* Display: Product Listings */
  $handler = $view->new_display('block', 'Product Listings', 'product_listings');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Products: translated */
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['id'] = 'field_product_list_sort_solr_et';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['table'] = 'field_data_field_product_list_sort_solr';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['field'] = 'field_product_list_sort_solr_et';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['label'] = '';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['type'] = 'apachesolr_reference_formatter_ids';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'toc' => 'toc',
  );

  /* Display: Kit Listings */
  $handler = $view->new_display('block', 'Kit Listings', 'kit_listings');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Kits: translated */
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['id'] = 'field_kits_list_sort_solr_et';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['table'] = 'field_data_field_kits_list_sort_solr';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['field'] = 'field_kits_list_sort_solr_et';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['label'] = '';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['element_type'] = '0';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['type'] = 'apachesolr_reference_formatter_ids';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'toc' => 'toc',
  );

  /* Display: Accessory Listings */
  $handler = $view->new_display('block', 'Accessory Listings', 'accessory_listings');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Accessories: translated */
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['id'] = 'field_accessories_list_sort_solr_et';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['table'] = 'field_data_field_accessories_list_sort_solr';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['field'] = 'field_accessories_list_sort_solr_et';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['label'] = '';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['type'] = 'apachesolr_reference_formatter_ids';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'toc' => 'toc',
  );
  $translatables['product_toc'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('reverse_field_toc_top_sellers_taxonomy_term'),
    t('All'),
    t('Top Sellers'),
    t('Product Listings'),
    t('Kit Listings'),
    t('Accessory Listings'),
  );
  $export['product_toc'] = $view;

  $view = new view();
  $view->name = 'product_toc_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__fluke_opensolr';
  $view->human_name = 'Product TOC - Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['is_product_sort_order']['id'] = 'is_product_sort_order';
  $handler->display->display_options['sorts']['is_product_sort_order']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['sorts']['is_product_sort_order']['field'] = 'is_product_sort_order';
  /* Filter criterion: Apache Solr: im_field_product_type */
  $handler->display->display_options['filters']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['value'] = '1535';

  /* Display: Product Listings1 */
  $handler = $view->new_display('block', 'Product Listings1', 'product_listings1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_type'] = 'h2';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Apache Solr: entity_id */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: im_field_product_type */
  $handler->display->display_options['filters']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['value'] = '1533';

  /* Display: Accessory Listings1 */
  $handler = $view->new_display('block', 'Accessory Listings1', 'accessory_listings1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_type'] = 'h2';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Apache Solr: entity_id */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: im_field_product_type */
  $handler->display->display_options['filters']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['value'] = '1534';

  /* Display: Kit Listings1 */
  $handler = $view->new_display('block', 'Kit Listings1', 'kit_listings1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_content_title ']['element_type'] = 'h2';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Apache Solr: entity_id */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';

  /* Display: Top Sellers */
  $handler = $view->new_display('block', 'Top Sellers', 'top_sellers');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_type'] = 'h2';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Apache Solr: entity_id */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Product Listing Page */
  $handler = $view->new_display('page', 'Product Listing Page', 'products_page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['label'] = '';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  /* Field: Apache Solr: tm_urlpathproducts */
  $handler->display->display_options['fields']['tm_urlpathproducts']['id'] = 'tm_urlpathproducts';
  $handler->display->display_options['fields']['tm_urlpathproducts']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_urlpathproducts']['field'] = 'tm_urlpathproducts';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ts_short_description_summary']['id'] = 'ts_short_description_summary';
  $handler->display->display_options['fields']['ts_short_description_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ts_short_description_summary']['field'] = 'ts_short_description_summary';
  $handler->display->display_options['fields']['ts_short_description_summary']['label'] = '';
  $handler->display->display_options['fields']['ts_short_description_summary']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_url_product_category */
  $handler->display->display_options['fields']['sm_url_product_category']['id'] = 'sm_url_product_category';
  $handler->display->display_options['fields']['sm_url_product_category']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_url_product_category']['field'] = 'sm_url_product_category';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: im_field_product_type */
  $handler->display->display_options['filters']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['value'] = '1533';
  $handler->display->display_options['path'] = 'products/toc/product-listing';

  /* Display: Accessory Listings */
  $handler = $view->new_display('page', 'Accessory Listings', 'accessory_p');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  /* Field: Apache Solr: tm_urlpathproducts */
  $handler->display->display_options['fields']['tm_urlpathproducts']['id'] = 'tm_urlpathproducts';
  $handler->display->display_options['fields']['tm_urlpathproducts']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_urlpathproducts']['field'] = 'tm_urlpathproducts';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ts_short_description_summary']['id'] = 'ts_short_description_summary';
  $handler->display->display_options['fields']['ts_short_description_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ts_short_description_summary']['field'] = 'ts_short_description_summary';
  /* Field: Apache Solr: sm_url_product_category */
  $handler->display->display_options['fields']['sm_url_product_category']['id'] = 'sm_url_product_category';
  $handler->display->display_options['fields']['sm_url_product_category']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_url_product_category']['field'] = 'sm_url_product_category';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: im_field_product_type */
  $handler->display->display_options['filters']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['value'] = '1534';
  $handler->display->display_options['filters']['im_field_product_type']['group'] = 1;
  $handler->display->display_options['path'] = 'products/toc/accessories-listing';

  /* Display: Kit Listings */
  $handler = $view->new_display('page', 'Kit Listings', 'kit_p');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  /* Field: Apache Solr: tm_urlpathproducts */
  $handler->display->display_options['fields']['tm_urlpathproducts']['id'] = 'tm_urlpathproducts';
  $handler->display->display_options['fields']['tm_urlpathproducts']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_urlpathproducts']['field'] = 'tm_urlpathproducts';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ts_short_description_summary']['id'] = 'ts_short_description_summary';
  $handler->display->display_options['fields']['ts_short_description_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ts_short_description_summary']['field'] = 'ts_short_description_summary';
  /* Field: Apache Solr: sm_url_product_category */
  $handler->display->display_options['fields']['sm_url_product_category']['id'] = 'sm_url_product_category';
  $handler->display->display_options['fields']['sm_url_product_category']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_url_product_category']['field'] = 'sm_url_product_category';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: im_field_product_type */
  $handler->display->display_options['filters']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['filters']['im_field_product_type']['value'] = '1535';
  $handler->display->display_options['path'] = 'products/toc/kits-listing';

  /* Display: Products Listing Block */
  $handler = $view->new_display('block', 'Products Listing Block', 'products_block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  /* Field: Apache Solr: sm_url_product_category */
  $handler->display->display_options['fields']['sm_url_product_category']['id'] = 'sm_url_product_category';
  $handler->display->display_options['fields']['sm_url_product_category']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_url_product_category']['field'] = 'sm_url_product_category';
  /* Field: Apache Solr: tm_urlpathproducts */
  $handler->display->display_options['fields']['tm_urlpathproducts']['id'] = 'tm_urlpathproducts';
  $handler->display->display_options['fields']['tm_urlpathproducts']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_urlpathproducts']['field'] = 'tm_urlpathproducts';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ts_short_description_summary']['id'] = 'ts_short_description_summary';
  $handler->display->display_options['fields']['ts_short_description_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ts_short_description_summary']['field'] = 'ts_short_description_summary';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Accessory Listing Block */
  $handler = $view->new_display('block', 'Accessory Listing Block', 'accessory_block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  /* Field: Apache Solr: sm_url_product_category */
  $handler->display->display_options['fields']['sm_url_product_category']['id'] = 'sm_url_product_category';
  $handler->display->display_options['fields']['sm_url_product_category']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_url_product_category']['field'] = 'sm_url_product_category';
  /* Field: Apache Solr: tm_urlpathproducts */
  $handler->display->display_options['fields']['tm_urlpathproducts']['id'] = 'tm_urlpathproducts';
  $handler->display->display_options['fields']['tm_urlpathproducts']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_urlpathproducts']['field'] = 'tm_urlpathproducts';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ts_short_description_summary']['id'] = 'ts_short_description_summary';
  $handler->display->display_options['fields']['ts_short_description_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ts_short_description_summary']['field'] = 'ts_short_description_summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Kit Listing Block */
  $handler = $view->new_display('block', 'Kit Listing Block', 'kit_block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  /* Field: Apache Solr: sm_product_slideshow */
  $handler->display->display_options['fields']['sm_product_slideshow']['id'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_product_slideshow']['field'] = 'sm_product_slideshow';
  $handler->display->display_options['fields']['sm_product_slideshow']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: tm_summary */
  $handler->display->display_options['fields']['tm_summary']['id'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_summary']['field'] = 'tm_summary';
  $handler->display->display_options['fields']['tm_summary']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: im_field_product_type */
  $handler->display->display_options['fields']['im_field_product_type']['id'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['im_field_product_type']['field'] = 'im_field_product_type';
  $handler->display->display_options['fields']['im_field_product_type']['element_default_classes'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_skus']['id'] = 'sm_skus';
  $handler->display->display_options['fields']['sm_skus']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_skus']['field'] = 'sm_skus';
  /* Field: Apache Solr: sm_url_product_category */
  $handler->display->display_options['fields']['sm_url_product_category']['id'] = 'sm_url_product_category';
  $handler->display->display_options['fields']['sm_url_product_category']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_url_product_category']['field'] = 'sm_url_product_category';
  /* Field: Apache Solr: tm_urlpathproducts */
  $handler->display->display_options['fields']['tm_urlpathproducts']['id'] = 'tm_urlpathproducts';
  $handler->display->display_options['fields']['tm_urlpathproducts']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_urlpathproducts']['field'] = 'tm_urlpathproducts';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ts_short_description_summary']['id'] = 'ts_short_description_summary';
  $handler->display->display_options['fields']['ts_short_description_summary']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ts_short_description_summary']['field'] = 'ts_short_description_summary';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $translatables['product_toc_solr'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('ss_field_content_title '),
    t('sm_product_slideshow'),
    t('url'),
    t('tm_summary'),
    t('im_field_product_type'),
    t('Broken handler apachesolr__fluke_opensolr.sm_skus'),
    t('Product Listings1'),
    t('All'),
    t('Accessory Listings1'),
    t('Kit Listings1'),
    t('Top Sellers'),
    t('Product Listing Page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('tm_urlpathproducts'),
    t('sm_url_product_category'),
    t('Accessory Listings'),
    t('Broken handler apachesolr__fluke_opensolr.ts_short_description_summary'),
    t('Kit Listings'),
    t('Products Listing Block'),
    t('Accessory Listing Block'),
    t('Kit Listing Block'),
  );
  $export['product_toc_solr'] = $view;

  $view = new view();
  $view->name = 'product_toc_url_builder';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Product TOC - URL Builder';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Categories';
  $handler->display->display_options['css_class'] = 'row';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_toc_articles_pages_target_id']['id'] = 'field_toc_articles_pages_target_id';
  $handler->display->display_options['relationships']['field_toc_articles_pages_target_id']['table'] = 'field_data_field_toc_articles_pages';
  $handler->display->display_options['relationships']['field_toc_articles_pages_target_id']['field'] = 'field_toc_articles_pages_target_id';
  $handler->display->display_options['relationships']['field_toc_articles_pages_target_id']['required'] = TRUE;
  /* Relationship: Field: URL Builder (field_url_builder) */
  $handler->display->display_options['relationships']['field_url_builder_tid']['id'] = 'field_url_builder_tid';
  $handler->display->display_options['relationships']['field_url_builder_tid']['table'] = 'field_data_field_url_builder';
  $handler->display->display_options['relationships']['field_url_builder_tid']['field'] = 'field_url_builder_tid';
  $handler->display->display_options['relationships']['field_url_builder_tid']['relationship'] = 'field_toc_articles_pages_target_id';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_toc_articles_pages_target_id';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  /* Field: Entity translation: Display Title: translated */
  $handler->display->display_options['fields']['field_content_title_et']['id'] = 'field_content_title_et';
  $handler->display->display_options['fields']['field_content_title_et']['table'] = 'field_data_field_content_title';
  $handler->display->display_options['fields']['field_content_title_et']['field'] = 'field_content_title_et';
  $handler->display->display_options['fields']['field_content_title_et']['relationship'] = 'field_toc_articles_pages_target_id';
  $handler->display->display_options['fields']['field_content_title_et']['label'] = '';
  $handler->display->display_options['fields']['field_content_title_et']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_content_title_et']['alter']['text'] = '<a href="[path]"><h3>[field_content_title_et]</h3></a>';
  $handler->display->display_options['fields']['field_content_title_et']['element_type'] = '0';
  $handler->display->display_options['fields']['field_content_title_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_content_title_et']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_content_title_et']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_content_title_et']['field_api_classes'] = TRUE;
  /* Field: Field: Category TOC  */
  $handler->display->display_options['fields']['field_category_image_toc_uri']['id'] = 'field_category_image_toc_uri';
  $handler->display->display_options['fields']['field_category_image_toc_uri']['table'] = 'field_data_field_category_image_toc_uri';
  $handler->display->display_options['fields']['field_category_image_toc_uri']['field'] = 'field_category_image_toc_uri';
  $handler->display->display_options['fields']['field_category_image_toc_uri']['relationship'] = 'field_url_builder_tid';
  $handler->display->display_options['fields']['field_category_image_toc_uri']['label'] = '';
  $handler->display->display_options['fields']['field_category_image_toc_uri']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_category_image_toc_uri']['alter']['text'] = '<div class="col-sm-4">
<div class="toc-listing-image"><a href="[path]" >[field_category_image_toc_uri]</a></div><div class="toc-listing-image"><a href="[path]" ><h3>[field_content_title_et]</h3></a></div></div>';
  $handler->display->display_options['fields']['field_category_image_toc_uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_category_image_toc_uri']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_category_image_toc_uri']['click_sort_column'] = 'id';
  $handler->display->display_options['fields']['field_category_image_toc_uri']['type'] = 'dam_uri_image';
  $handler->display->display_options['fields']['field_category_image_toc_uri']['settings'] = array(
    'classes' => '',
  );
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['name']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['name']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';

  /* Display: Categories */
  $handler = $view->new_display('panel_pane', 'Categories', 'categories');
  $handler->display->display_options['argument_input'] = array(
    'name' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy term: Name',
    ),
  );

  /* Display: Product Listings */
  $handler = $view->new_display('block', 'Product Listings', 'product_listings');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Products: translated */
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['id'] = 'field_product_list_sort_solr_et';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['table'] = 'field_data_field_product_list_sort_solr';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['field'] = 'field_product_list_sort_solr_et';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['label'] = '';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['type'] = 'apachesolr_reference_formatter_ids';
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_product_list_sort_solr_et']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';

  /* Display: Kit Listings */
  $handler = $view->new_display('block', 'Kit Listings', 'kit_listings');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Kits: translated */
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['id'] = 'field_kits_list_sort_solr_et';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['table'] = 'field_data_field_kits_list_sort_solr';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['field'] = 'field_kits_list_sort_solr_et';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['label'] = '';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['element_type'] = '0';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['type'] = 'apachesolr_reference_formatter_ids';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_kits_list_sort_solr_et']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';

  /* Display: Accessory Listings */
  $handler = $view->new_display('block', 'Accessory Listings', 'accessory_listings');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Accessories: translated */
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['id'] = 'field_accessories_list_sort_solr_et';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['table'] = 'field_data_field_accessories_list_sort_solr';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['field'] = 'field_accessories_list_sort_solr_et';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['label'] = '';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['element_type'] = '0';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['type'] = 'apachesolr_reference_formatter_ids';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_accessories_list_sort_solr_et']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $translatables['product_toc_url_builder'] = array(
    t('Master'),
    t('Categories'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_toc_articles_pages_target_id'),
    t('term from field_url_builder'),
    t('Path'),
    t('<a href="[path]"><h3>[field_content_title_et]</h3></a>'),
    t('<div class="col-sm-4">
<div class="toc-listing-image"><a href="[path]" >[field_category_image_toc_uri]</a></div><div class="toc-listing-image"><a href="[path]" ><h3>[field_content_title_et]</h3></a></div></div>'),
    t('All'),
    t('View panes'),
    t('Product Listings'),
    t('Kit Listings'),
    t('Accessory Listings'),
  );
  $export['product_toc_url_builder'] = $view;

  $view = new view();
  $view->name = 'products_from_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__fluke_opensolr';
  $view->human_name = 'Products from Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = 'Title';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['bm_field_product_recall']['id'] = 'bm_field_product_recall';
  $handler->display->display_options['fields']['bm_field_product_recall']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['bm_field_product_recall']['field'] = 'bm_field_product_recall';
  $handler->display->display_options['fields']['bm_field_product_recall']['label'] = 'Recalled';
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['bm_field_product_recall']['id'] = 'bm_field_product_recall';
  $handler->display->display_options['filters']['bm_field_product_recall']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bm_field_product_recall']['field'] = 'bm_field_product_recall';
  $handler->display->display_options['filters']['bm_field_product_recall']['value'] = '1';

  /* Display: Product Recalls */
  $handler = $view->new_display('panel_pane', 'Product Recalls', 'product_recalls');
  $translatables['products_from_solr'] = array(
    t('Master'),
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
    t('Title'),
    t('Recalled'),
    t('Product Recalls'),
    t('View panes'),
  );
  $export['products_from_solr'] = $view;

  return $export;
}
