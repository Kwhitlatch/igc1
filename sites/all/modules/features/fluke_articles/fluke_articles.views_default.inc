<?php
/**
 * @file
 * fluke_articles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fluke_articles_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'support_page_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__fluke_opensolr';
  $view->human_name = 'Article - Solr';
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'We are sorry, no content for the selected category were found.  ';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['text'] = '<h1>[ss_field_content_title ]</h1>';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ss_article_body']['id'] = 'ss_article_body';
  $handler->display->display_options['fields']['ss_article_body']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_article_body']['field'] = 'ss_article_body';
  /* Field: Apache Solr: ss_article_h1_title */
  $handler->display->display_options['fields']['ss_article_h1_title']['id'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_article_h1_title']['field'] = 'ss_article_h1_title';
  /* Contextual filter: Apache Solr: ss_field_url_title */
  $handler->display->display_options['arguments']['ss_field_url_title']['id'] = 'ss_field_url_title';
  $handler->display->display_options['arguments']['ss_field_url_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['arguments']['ss_field_url_title']['field'] = 'ss_field_url_title';
  $handler->display->display_options['arguments']['ss_field_url_title']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['ss_field_url_title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'article';
  $handler->display->display_options['filters']['bundle']['group'] = 1;
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['value'] = '1';
  $handler->display->display_options['filters']['bs_status']['group'] = 1;
  /* Filter criterion: Apache Solr: sm_vid_URL_Builder */
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['id'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['field'] = 'sm_vid_URL_Builder';

  /* Display: Support Pages - Desc */
  $handler = $view->new_display('panel_pane', 'Support Pages - Desc', 'support_pages_desc');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['text'] = '<h1>[ss_field_content_title ]</h1>';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: ss_article_h1_title */
  $handler->display->display_options['fields']['ss_article_h1_title']['id'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_article_h1_title']['field'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['label'] = '';
  $handler->display->display_options['fields']['ss_article_h1_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ss_article_h1_title']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['tm_article_body']['id'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_article_body']['field'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['label'] = '';
  $handler->display->display_options['fields']['tm_article_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'article';
  $handler->display->display_options['filters']['bundle']['group'] = 1;
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['value'] = '1';
  $handler->display->display_options['filters']['bs_status']['group'] = 1;
  /* Filter criterion: Apache Solr: sm_term_depth */
  $handler->display->display_options['filters']['sm_term_depth']['id'] = 'sm_term_depth';
  $handler->display->display_options['filters']['sm_term_depth']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['sm_term_depth']['field'] = 'sm_term_depth';
  $handler->display->display_options['filters']['sm_term_depth']['value'] = '2';
  $handler->display->display_options['filters']['sm_term_depth']['group'] = 1;
  /* Filter criterion: Apache Solr: sm_vid_URL_Builder */
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['id'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['field'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['value'] = 'Support';
  $handler->display->display_options['argument_input'] = array(
    'ss_field_url_title' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Apache Solr: ss_field_url_title',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Support-Aboutus Pages - Desc */
  $handler = $view->new_display('panel_pane', 'Support-Aboutus Pages - Desc', 'support_aboutus_pages_desc');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['text'] = '<h1>[ss_field_content_title ]</h1>';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: ss_article_h1_title */
  $handler->display->display_options['fields']['ss_article_h1_title']['id'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_article_h1_title']['field'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['label'] = '';
  $handler->display->display_options['fields']['ss_article_h1_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ss_article_h1_title']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['tm_article_body']['id'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_article_body']['field'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['label'] = '';
  $handler->display->display_options['fields']['tm_article_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'article';
  $handler->display->display_options['filters']['bundle']['group'] = 1;
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['value'] = '1';
  $handler->display->display_options['filters']['bs_status']['group'] = 1;
  /* Filter criterion: Apache Solr: sm_vid_URL_Builder */
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['id'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['field'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['value'] = 'Support';
  $handler->display->display_options['argument_input'] = array(
    'ss_field_url_title' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Apache Solr: ss_field_url_title',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Footer Pages - Desc */
  $handler = $view->new_display('panel_pane', 'Footer Pages - Desc', 'footer_pages_desc');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['text'] = '<h1>[ss_field_content_title ]</h1>';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: ss_article_h1_title */
  $handler->display->display_options['fields']['ss_article_h1_title']['id'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_article_h1_title']['field'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['label'] = '';
  $handler->display->display_options['fields']['ss_article_h1_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ss_article_h1_title']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['tm_article_body']['id'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_article_body']['field'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['label'] = '';
  $handler->display->display_options['fields']['tm_article_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Apache Solr: ss_field_url_title */
  $handler->display->display_options['arguments']['ss_field_url_title']['id'] = 'ss_field_url_title';
  $handler->display->display_options['arguments']['ss_field_url_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['arguments']['ss_field_url_title']['field'] = 'ss_field_url_title';
  $handler->display->display_options['arguments']['ss_field_url_title']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['ss_field_url_title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'article';
  $handler->display->display_options['filters']['bundle']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'ss_field_url_title' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Apache Solr: ss_field_url_title',
    ),
  );

  /* Display: Training Educators/Courses Pages -Desc */
  $handler = $view->new_display('panel_pane', 'Training Educators/Courses Pages -Desc', 'training_educators_pages_desc');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ss_field_content_title ']['element_type'] = 'h1';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: ss_article_h1_title */
  $handler->display->display_options['fields']['ss_article_h1_title']['id'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_article_h1_title']['field'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['label'] = '';
  $handler->display->display_options['fields']['ss_article_h1_title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['ss_article_h1_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ss_article_h1_title']['empty'] = '[ss_field_content_title ]';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['tm_article_body']['id'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_article_body']['field'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['label'] = '';
  $handler->display->display_options['fields']['tm_article_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Apache Solr: ss_field_url_title */
  $handler->display->display_options['arguments']['ss_field_url_title']['id'] = 'ss_field_url_title';
  $handler->display->display_options['arguments']['ss_field_url_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['arguments']['ss_field_url_title']['field'] = 'ss_field_url_title';
  $handler->display->display_options['arguments']['ss_field_url_title']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['ss_field_url_title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['ss_field_url_title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'article';
  $handler->display->display_options['filters']['bundle']['group'] = 1;
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['value'] = '1';
  $handler->display->display_options['filters']['bs_status']['group'] = 1;
  /* Filter criterion: Apache Solr: sm_term_depth */
  $handler->display->display_options['filters']['sm_term_depth']['id'] = 'sm_term_depth';
  $handler->display->display_options['filters']['sm_term_depth']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['sm_term_depth']['field'] = 'sm_term_depth';
  $handler->display->display_options['filters']['sm_term_depth']['value'] = '3';
  $handler->display->display_options['filters']['sm_term_depth']['group'] = 1;
  /* Filter criterion: Apache Solr: sm_vid_URL_Builder */
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['id'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['field'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['value'] = 'Training';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'ss_field_url_title' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Apache Solr: ss_field_url_title',
    ),
  );

  /* Display: Training Pages -Desc */
  $handler = $view->new_display('panel_pane', 'Training Pages -Desc', 'training_pages_desc');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: ss_field_content_title  */
  $handler->display->display_options['fields']['ss_field_content_title ']['id'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_field_content_title ']['field'] = 'ss_field_content_title ';
  $handler->display->display_options['fields']['ss_field_content_title ']['label'] = '';
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['ss_field_content_title ']['alter']['text'] = '<h1>[ss_field_content_title ]</h1>';
  $handler->display->display_options['fields']['ss_field_content_title ']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: ss_article_h1_title */
  $handler->display->display_options['fields']['ss_article_h1_title']['id'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['ss_article_h1_title']['field'] = 'ss_article_h1_title';
  $handler->display->display_options['fields']['ss_article_h1_title']['label'] = '';
  $handler->display->display_options['fields']['ss_article_h1_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ss_article_h1_title']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['tm_article_body']['id'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['fields']['tm_article_body']['field'] = 'tm_article_body';
  $handler->display->display_options['fields']['tm_article_body']['label'] = '';
  $handler->display->display_options['fields']['tm_article_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'article';
  $handler->display->display_options['filters']['bundle']['group'] = 1;
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['value'] = '1';
  $handler->display->display_options['filters']['bs_status']['group'] = 1;
  /* Filter criterion: Apache Solr: sm_term_depth */
  $handler->display->display_options['filters']['sm_term_depth']['id'] = 'sm_term_depth';
  $handler->display->display_options['filters']['sm_term_depth']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['sm_term_depth']['field'] = 'sm_term_depth';
  $handler->display->display_options['filters']['sm_term_depth']['value'] = '2';
  $handler->display->display_options['filters']['sm_term_depth']['group'] = 1;
  /* Filter criterion: Apache Solr: sm_vid_URL_Builder */
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['id'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['table'] = 'apachesolr__fluke_opensolr';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['field'] = 'sm_vid_URL_Builder';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['value'] = 'Training';
  $handler->display->display_options['filters']['sm_vid_URL_Builder']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'ss_field_url_title' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Apache Solr: ss_field_url_title',
    ),
  );
  $translatables['support_page_view'] = array(
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
    t('We are sorry, no content for the selected category were found.  '),
    t('<h1>[ss_field_content_title ]</h1>'),
    t('Broken handler apachesolr__fluke_opensolr.ss_article_body'),
    t('ss_article_h1_title'),
    t('All'),
    t('Support Pages - Desc'),
    t('View panes'),
    t('Support-Aboutus Pages - Desc'),
    t('Footer Pages - Desc'),
    t('Training Educators/Courses Pages -Desc'),
    t('[ss_field_content_title ]'),
    t('Training Pages -Desc'),
  );
  $export['support_page_view'] = $view;

  return $export;
}
