<?php
/**
 * @file
 * social_links_footer_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function social_links_footer_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'social_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Social Links';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Taxonomy term: Language-Locale Specific URL */
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['id'] = 'field_language_locale_specific_u_1';
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['table'] = 'field_data_field_language_locale_specific_u';
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['field'] = 'field_language_locale_specific_u';
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['label'] = '';
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_language_locale_specific_u_1']['type'] = 'link_plain';
  /* Field: Taxonomy term: Wrapper class  */
  $handler->display->display_options['fields']['field_wrapper_class_']['id'] = 'field_wrapper_class_';
  $handler->display->display_options['fields']['field_wrapper_class_']['table'] = 'field_data_field_wrapper_class_';
  $handler->display->display_options['fields']['field_wrapper_class_']['field'] = 'field_wrapper_class_';
  $handler->display->display_options['fields']['field_wrapper_class_']['label'] = '';
  $handler->display->display_options['fields']['field_wrapper_class_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_wrapper_class_']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wrapper_class_']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_wrapper_class_']['type'] = 'text_plain';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = '[field_language_locale_specific_u]';
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['link_class'] = 'fluke-icon-[field_wrapper_class_]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Language-Locale Specific URL */
  $handler->display->display_options['fields']['field_language_locale_specific_u']['id'] = 'field_language_locale_specific_u';
  $handler->display->display_options['fields']['field_language_locale_specific_u']['table'] = 'field_data_field_language_locale_specific_u';
  $handler->display->display_options['fields']['field_language_locale_specific_u']['field'] = 'field_language_locale_specific_u';
  $handler->display->display_options['fields']['field_language_locale_specific_u']['label'] = '';
  $handler->display->display_options['fields']['field_language_locale_specific_u']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_language_locale_specific_u']['alter']['text'] = '<a itemprop="sameAs" href="[field_language_locale_specific_u_1]" title="[name]" class="fluke-icon" target="_blank"><span aria-hidden="true" class="fluke-icon fluke-icon-[field_wrapper_class_]"><span class="hide">[name]</span></span></a>';
  $handler->display->display_options['fields']['field_language_locale_specific_u']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_language_locale_specific_u']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_language_locale_specific_u']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_language_locale_specific_u']['type'] = 'link_title_plain';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'social_links' => 'social_links',
  );
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Social Icons - Language Locale Specific */
  $handler = $view->new_display('panel_pane', 'Social Icons - Language Locale Specific', 'panel_pane_1');

  /* Display: Social Icons - Language Locale Specific Block */
  $handler = $view->new_display('block', 'Social Icons - Language Locale Specific Block', 'block_1');
  $translatables['social_links'] = array(
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
    t('Translations'),
    t('<a itemprop="sameAs" href="[field_language_locale_specific_u_1]" title="[name]" class="fluke-icon" target="_blank"><span aria-hidden="true" class="fluke-icon fluke-icon-[field_wrapper_class_]"><span class="hide">[name]</span></span></a>'),
    t('Social Icons - Language Locale Specific'),
    t('View panes'),
    t('Social Icons - Language Locale Specific Block'),
  );
  $export['social_links'] = $view;

  return $export;
}
