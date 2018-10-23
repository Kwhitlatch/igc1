<?php
/**
 * @file
 * social_share_block_solr_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function social_share_block_solr_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'share_block_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__fluke_opensolr';
  $view->human_name = 'Share Block Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Share Block Solr';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'figstrap-social-share';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Apache Solr: bundle */
  $handler->display->display_options['fields']['bundle']['id'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['bundle']['field'] = 'bundle';
  $handler->display->display_options['fields']['bundle']['label'] = '';
  $handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bundle']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: teaser */
  $handler->display->display_options['fields']['teaser']['id'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['teaser']['field'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['label'] = '';
  $handler->display->display_options['fields']['teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['teaser']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_additional_class */
  $handler->display->display_options['fields']['sm_field_additional_class']['id'] = 'sm_field_additional_class';
  $handler->display->display_options['fields']['sm_field_additional_class']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['sm_field_additional_class']['field'] = 'sm_field_additional_class';
  $handler->display->display_options['fields']['sm_field_additional_class']['label'] = '';
  $handler->display->display_options['fields']['sm_field_additional_class']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sm_field_additional_class']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['text'] = '<a href="[sm_field_additional_class]"  class="figstrap-share-link"  title="[label] "  data-width="570" data-height="520"  data-scrollbars="yes"  data-additionalclass="[label]">[F]</a>
';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Filter criterion: Apache Solr: entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'taxonomy_term';
  $handler->display->display_options['filters']['entity_type']['group'] = 1;
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'social_share';
  $handler->display->display_options['filters']['bundle']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'social_share_block_solr');
  $translatables['share_block_solr'] = array(
    t('Master'),
    t('Share Block Solr'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="[sm_field_additional_class]"  class="figstrap-share-link"  title="[label] "  data-width="570" data-height="520"  data-scrollbars="yes"  data-additionalclass="[label]">[F]</a>
'),
    t('Block'),
  );
  $export['share_block_solr'] = $view;

  return $export;
}
