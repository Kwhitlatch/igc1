<?php
/**
 * @file
 * display_suite.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function display_suite_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|article_bl01v1_vm_fnp_topic_feat';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'article_bl01v1_vm_fnp_topic_feat';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Learn More',
        'wrapper' => '',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => '<div class="clearfix"></div>',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'row',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'col-sm-5 ',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'btn btn-primary btn-lg btn-block',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
        'field_formatter_class' => '',
      ),
    ),
    'field_content_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h2',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'a',
          'fi-cl' => '',
          'fi-at' => 'href="[node:url]"',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<span role="presentation"> | </span>',
        ),
      ),
    ),
    'field_digital_asset' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_publication_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'time',
          'fi-cl' => '',
          'fi-at' => 'pubdate="[node:field-publication-date:html5_datetime_value]" itemprop="datePublished"',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_summary' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article|article_bl01v1_vm_fnp_topic_feat'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|article_bl01v1_vm_fnp_topic_foot';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'article_bl01v1_vm_fnp_topic_foot';
  $ds_fieldsetting->settings = array(
    'field_content_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'a',
          'fi-cl' => '',
          'fi-at' => 'href="[node:url]"',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_digital_asset' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|article|article_bl01v1_vm_fnp_topic_foot'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|article_bl01v1_vm_fnp_topic_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'article_bl01v1_vm_fnp_topic_list';
  $ds_fieldsetting->settings = array(
    'field_content_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'a',
          'fi-cl' => '',
          'fi-at' => 'href="[node:url]"',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<span role="presentation"> | </span>',
        ),
      ),
    ),
    'field_digital_asset' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'field_publication_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'time',
          'fi-cl' => '',
          'fi-at' => 'pubdate="[node:field-publication-date:html5_datetime_value]" itemprop="datePublished"',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article|article_bl01v1_vm_fnp_topic_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|article_cb04v1_vm_fnp_full_page';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'article_cb04v1_vm_fnp_full_page';
  $ds_fieldsetting->settings = array(
    'field_content_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h1',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_digital_asset' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'img-responsive center-block',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article|article_cb04v1_vm_fnp_full_page'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|article_toc';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'article_toc';
  $ds_fieldsetting->settings = array(
    'field_content_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'h3_regular',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article|article_toc'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'article-body-content',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_content_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h1',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_topic' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_body_2' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'article-body-content',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_digital_asset' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'img-responsive center-block',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_publication_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ' | ',
        ),
      ),
    ),
    'field_subtitle' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|article|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|search_result_highlighting_input';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'search_result_highlighting_input';
  $ds_fieldsetting->settings = array(
    'field_publication_date' => array(
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|article|search_result_highlighting_input'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function display_suite_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|article_bl01v1_vm_fnp_topic_feat';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'article_bl01v1_vm_fnp_topic_feat';
  $ds_layout->layout = 'flukestrap_5_7_to_9_9';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_digital_asset',
      ),
      'right' => array(
        1 => 'field_content_title',
        2 => 'field_summary',
        3 => 'node_link',
        4 => 'group_date_and_topic_wrapper',
        5 => 'field_publication_date',
        6 => 'field_topic',
      ),
    ),
    'fields' => array(
      'field_digital_asset' => 'left',
      'field_content_title' => 'right',
      'field_summary' => 'right',
      'node_link' => 'right',
      'group_date_and_topic_wrapper' => 'right',
      'field_publication_date' => 'right',
      'field_topic' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|article_bl01v1_vm_fnp_topic_feat'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|article_bl01v1_vm_fnp_topic_foot';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'article_bl01v1_vm_fnp_topic_foot';
  $ds_layout->layout = 'flukestrap_col_only_3_to_6';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_digital_asset',
        1 => 'field_content_title',
      ),
    ),
    'fields' => array(
      'field_digital_asset' => 'left',
      'field_content_title' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|article_bl01v1_vm_fnp_topic_foot'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|article_bl01v1_vm_fnp_topic_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'article_bl01v1_vm_fnp_topic_list';
  $ds_layout->layout = 'flukestrap_3_5_to_3_9';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_digital_asset',
      ),
      'right' => array(
        1 => 'field_content_title',
        2 => 'field_summary',
        3 => 'group_date_and_topic_wrapper',
        4 => 'field_publication_date',
        5 => 'field_topic',
      ),
    ),
    'fields' => array(
      'field_digital_asset' => 'left',
      'field_content_title' => 'right',
      'field_summary' => 'right',
      'group_date_and_topic_wrapper' => 'right',
      'field_publication_date' => 'right',
      'field_topic' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|article_bl01v1_vm_fnp_topic_list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|article_cb04v1_vm_fnp_full_page';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'article_cb04v1_vm_fnp_full_page';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_content_title',
        1 => 'field_publication_date',
        2 => 'field_topic',
        3 => 'field_digital_asset',
        4 => 'body',
        5 => 'field_body_2',
        6 => 'field_article_footer',
      ),
    ),
    'fields' => array(
      'field_content_title' => 'ds_content',
      'field_publication_date' => 'ds_content',
      'field_topic' => 'ds_content',
      'field_digital_asset' => 'ds_content',
      'body' => 'ds_content',
      'field_body_2' => 'ds_content',
      'field_article_footer' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['node|article|article_cb04v1_vm_fnp_full_page'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|article_toc';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'article_toc';
  $ds_layout->layout = 'bootstrap_5_7';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_digital_asset',
      ),
      'right' => array(
        1 => 'field_content_title',
        2 => 'field_summary',
      ),
    ),
    'fields' => array(
      'field_digital_asset' => 'left',
      'field_content_title' => 'right',
      'field_summary' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|article|article_toc'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_related_products',
        1 => 'field_related_articles',
        2 => 'field_content_title',
        3 => 'group_date_and_topic_wrapper',
        4 => 'field_publication_date',
        5 => 'field_topic',
        6 => 'field_digital_asset',
        7 => 'field_subtitle',
        8 => 'body',
        9 => 'field_body_2',
      ),
    ),
    'fields' => array(
      'field_related_products' => 'ds_content',
      'field_related_articles' => 'ds_content',
      'field_content_title' => 'ds_content',
      'group_date_and_topic_wrapper' => 'ds_content',
      'field_publication_date' => 'ds_content',
      'field_topic' => 'ds_content',
      'field_digital_asset' => 'ds_content',
      'field_subtitle' => 'ds_content',
      'body' => 'ds_content',
      'field_body_2' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|article|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'bootstrap_5_7';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_digital_asset',
      ),
      'right' => array(
        1 => 'field_content_title',
        2 => 'field_subtitle',
        3 => 'field_publication_date',
        4 => 'field_summary',
      ),
    ),
    'fields' => array(
      'field_digital_asset' => 'left',
      'field_content_title' => 'right',
      'field_subtitle' => 'right',
      'field_publication_date' => 'right',
      'field_summary' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|article|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|search_result_highlighting_input';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'search_result_highlighting_input';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_content_title',
        1 => 'field_summary',
        2 => 'field_publication_date',
      ),
    ),
    'fields' => array(
      'field_content_title' => 'central',
      'field_summary' => 'central',
      'field_publication_date' => 'central',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|article|search_result_highlighting_input'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function display_suite_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'article_a1d';
  $ds_view_mode->label = 'article-a1d';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['article_a1d'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'article_bl01v1_vm_fnp_topic_body';
  $ds_view_mode->label = 'Digital-asset-article-list-image';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['article_bl01v1_vm_fnp_topic_body'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'article_bl01v1_vm_fnp_topic_feat';
  $ds_view_mode->label = 'Article-BL01v1-VM-FNP-Topic-Feat';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['article_bl01v1_vm_fnp_topic_feat'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'article_bl01v1_vm_fnp_topic_foot';
  $ds_view_mode->label = 'Article-BL01v1-VM-FNP-Topic-Foot';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['article_bl01v1_vm_fnp_topic_foot'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'article_bl01v1_vm_fnp_topic_list';
  $ds_view_mode->label = 'Article-BL01v1-VM-FNP-Topic-List';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['article_bl01v1_vm_fnp_topic_list'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'article_cb04v1_vm_fnp_full_page';
  $ds_view_mode->label = 'Article-CB04v1-VM-FNP-full-page';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['article_cb04v1_vm_fnp_full_page'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'article_toc';
  $ds_view_mode->label = 'Article TOC';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['article_toc'] = $ds_view_mode;

  return $export;
}
