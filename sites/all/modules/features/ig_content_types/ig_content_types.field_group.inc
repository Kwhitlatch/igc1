<?php
/**
 * @file
 * ig_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ig_content_types_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article|node|article|form';
  $field_group->group_name = 'group_article';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Article',
    'weight' => '0',
    'children' => array(
      0 => 'group_taxonomy',
      1 => 'group_general',
      2 => 'group_reference',
      3 => 'group_main',
      4 => 'group_list_view',
      5 => 'group_related',
      6 => 'group_publish',
      7 => 'group_cta',
      8 => 'group_header_footer',
      9 => 'group_other',
      10 => 'group_navigation',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-article field-group-tabs',
      ),
    ),
  );
  $field_groups['group_article|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cta|node|article|form';
  $field_group->group_name = 'group_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'CTA',
    'weight' => '70',
    'children' => array(
      0 => 'field_cta_left_link',
      1 => 'field_cta_right_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cta field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cta|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_and_topic_wrapper|node|article|article_bl01v1_vm_fnp_topic_feat';
  $field_group->group_name = 'group_date_and_topic_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'article_bl01v1_vm_fnp_topic_feat';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and topic wrapper',
    'weight' => '4',
    'children' => array(
      0 => 'field_topic',
      1 => 'field_publication_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date and topic wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'pubdate-topic-set',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_date_and_topic_wrapper|node|article|article_bl01v1_vm_fnp_topic_feat'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_and_topic_wrapper|node|article|article_bl01v1_vm_fnp_topic_foot';
  $field_group->group_name = 'group_date_and_topic_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'article_bl01v1_vm_fnp_topic_foot';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and topic wrapper',
    'weight' => '2',
    'children' => array(
      0 => 'field_topic',
      1 => 'field_publication_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date and topic wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'pubdate-topic-set',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_date_and_topic_wrapper|node|article|article_bl01v1_vm_fnp_topic_foot'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_and_topic_wrapper|node|article|article_bl01v1_vm_fnp_topic_list';
  $field_group->group_name = 'group_date_and_topic_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'article_bl01v1_vm_fnp_topic_list';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and topic wrapper',
    'weight' => '3',
    'children' => array(
      0 => 'field_topic',
      1 => 'field_publication_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date and topic wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'pubdate-topic-set',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_date_and_topic_wrapper|node|article|article_bl01v1_vm_fnp_topic_list'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_and_topic_wrapper|node|article|default';
  $field_group->group_name = 'group_date_and_topic_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and topic wrapper',
    'weight' => '3',
    'children' => array(
      0 => 'field_topic',
      1 => 'field_publication_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-date-and-topic-wrapper field-group-fieldset',
      ),
    ),
  );
  $field_groups['group_date_and_topic_wrapper|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_distributor|node|distributor|form';
  $field_group->group_name = 'group_distributor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'distributor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Distributor',
    'weight' => '0',
    'children' => array(
      0 => 'group_general',
      1 => 'group_address',
      2 => 'group_other',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-distributor field-group-tabs',
      ),
    ),
  );
  $field_groups['group_distributor|node|distributor|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event|node|event|form';
  $field_group->group_name = 'group_event';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event',
    'weight' => '0',
    'children' => array(
      0 => 'group_general',
      1 => 'group_meta',
      2 => 'group_taxonomy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-event field-group-tabs',
      ),
    ),
  );
  $field_groups['group_event|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|article|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '65',
    'children' => array(
      0 => 'field_content_title',
      1 => 'field_owner',
      2 => 'field_notes',
      3 => 'field_url_title',
      4 => 'title_field',
      5 => 'path',
      6 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|distributor|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'distributor';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_distributor';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_distributor_name',
      2 => 'field_dist_id',
      3 => 'title_field',
      4 => 'field_url_title',
      5 => 'field_content_title',
      6 => 'path',
      7 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|distributor|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|event|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '20',
    'children' => array(
      0 => 'field_owner',
      1 => 'field_author_notes',
      2 => 'field_summary',
      3 => 'field_event_id',
      4 => 'field_event_name',
      5 => 'field_event_date',
      6 => 'field_event_location',
      7 => 'field_event_registration',
      8 => 'field_event_type',
      9 => 'field_event_cost',
      10 => 'field_event_sponsor',
      11 => 'title_field',
      12 => 'field_url_title',
      13 => 'field_content_title',
      14 => 'locations',
      15 => 'path',
      16 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|promotion|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '8',
    'children' => array(
      0 => 'field_content_title',
      1 => 'field_owner',
      2 => 'field_short_description',
      3 => 'field_long_description',
      4 => 'field_notes',
      5 => 'title_field',
      6 => 'field_url_title',
      7 => 'path',
      8 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|promotion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|resource|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_resource';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '4',
    'children' => array(
      0 => 'field_owner',
      1 => 'field_author_notes',
      2 => 'field_resource_id',
      3 => 'field_publication_date',
      4 => 'field_resource_url',
      5 => 'field_revision',
      6 => 'field_product_id_lit_number',
      7 => 'field_digital_asset',
      8 => 'title_field',
      9 => 'field_content_title',
      10 => 'field_url_title',
      11 => 'path',
      12 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header_footer|node|article|form';
  $field_group->group_name = 'group_header_footer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'Header/Footer',
    'weight' => '66',
    'children' => array(
      0 => 'field_custom_meta_head_element',
      1 => 'field_featured_image_s_',
      2 => 'field_href_lang',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-header-footer field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_header_footer|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_homepage_promo|node|promotion|form';
  $field_group->group_name = 'group_homepage_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion';
  $field_group->data = array(
    'label' => 'Homepage Promo',
    'weight' => '11',
    'children' => array(
      0 => 'field_digital_asset',
      1 => 'field_promo_image_title',
      2 => 'field_promo_image_1_short_descri',
      3 => 'field_promo_image_1_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-homepage-promo field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_homepage_promo|node|promotion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_list_view|node|article|form';
  $field_group->group_name = 'group_list_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'TOC Builder / Images',
    'weight' => '67',
    'children' => array(
      0 => 'field_sort_order',
      1 => 'field_digital_asset',
      2 => 'field_caption',
      3 => 'field_summary',
      4 => 'field_img_alt_tag',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'TOC Builder / Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-list-view field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_list_view|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|article|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '68',
    'children' => array(
      0 => 'body',
      1 => 'field_article_footer',
      2 => 'field_subtitle',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_main|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta_data|node|promotion|form';
  $field_group->group_name = 'group_meta_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion';
  $field_group->data = array(
    'label' => 'Header/Footer',
    'weight' => '9',
    'children' => array(
      0 => 'field_custom_meta_head_element',
      1 => 'field_footer_selection',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Header/Footer',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-meta-data field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_meta_data|node|promotion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_navigation|node|article|form';
  $field_group->group_name = 'group_navigation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'Navigation / Site Taxonomy',
    'weight' => '71',
    'children' => array(
      0 => 'field_url_builder',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Navigation / Site Taxonomy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-navigation field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_navigation|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|node|promotion|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '14',
    'children' => array(
      0 => 'body',
      1 => 'locations',
      2 => 'metatags',
      3 => 'xmlsitemap',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-other field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_other|node|promotion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promotion|node|promotion|form';
  $field_group->group_name = 'group_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promotion',
    'weight' => '0',
    'children' => array(
      0 => 'group_general',
      1 => 'group_meta_data',
      2 => 'group_homepage_promo',
      3 => 'group_toc_promo',
      4 => 'group_taxonomy',
      5 => 'group_main',
      6 => 'group_other',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-promotion field-group-tabs',
      ),
    ),
  );
  $field_groups['group_promotion|node|promotion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publish|node|article|form';
  $field_group->group_name = 'group_publish';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'Publish',
    'weight' => '75',
    'children' => array(
      0 => 'field_publication_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publish field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_publish|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reference|node|article|form';
  $field_group->group_name = 'group_reference';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'Reference',
    'weight' => '73',
    'children' => array(
      0 => 'field_cid',
      1 => 'field_breadcrumb',
      2 => 'field_card_id',
      3 => 'field_card_size',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-reference field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_reference|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|article|form';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'Related',
    'weight' => '69',
    'children' => array(
      0 => 'field_related_products',
      1 => 'field_digital_assets_partnerport',
      2 => 'field_product_digital_asset',
      3 => 'field_related_articles',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resource|node|resource|form';
  $field_group->group_name = 'group_resource';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Resource',
    'weight' => '0',
    'children' => array(
      0 => 'group_general',
      1 => 'group_taxonomy',
      2 => 'group_other',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-resource field-group-tabs',
      ),
    ),
  );
  $field_groups['group_resource|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|article|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article';
  $field_group->data = array(
    'label' => 'Taxonomy / Filters',
    'weight' => '72',
    'children' => array(
      0 => 'field_topic',
      1 => 'field_industry',
      2 => 'field_application',
      3 => 'field_region',
      4 => 'field_opco',
      5 => 'field_urlpatharticle',
      6 => 'field_article_type',
      7 => 'field_product_category',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomy / Filters',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_taxonomy|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|event|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '21',
    'children' => array(
      0 => 'field_appears_in_site_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomy|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|promotion|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '13',
    'children' => array(
      0 => 'field_application',
      1 => 'field_industry',
      2 => 'field_product_category',
      3 => 'field_opco',
      4 => 'field_region',
      5 => 'field_appears_in_site_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomy|node|promotion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy|node|resource|form';
  $field_group->group_name = 'group_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_resource';
  $field_group->data = array(
    'label' => 'Taxonomy',
    'weight' => '5',
    'children' => array(
      0 => 'field_industry',
      1 => 'field_product_category',
      2 => 'field_application',
      3 => 'field_region',
      4 => 'field_opco',
      5 => 'field_appears_in_site_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_taxonomy|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_toc_promo|node|promotion|form';
  $field_group->group_name = 'group_toc_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'promotion';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_promotion';
  $field_group->data = array(
    'label' => 'TOC Promo',
    'weight' => '12',
    'children' => array(
      0 => 'field_product_digital_asset',
      1 => 'field_promo_image_toc_title',
      2 => 'field_promo_image_toc_short_desc',
      3 => 'field_promo_image_toc_link',
      4 => 'field_promo_image_use_hompage_ti',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-toc-promo field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_toc_promo|node|promotion|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Article');
  t('CTA');
  t('Date and topic wrapper');
  t('Distributor');
  t('Event');
  t('General');
  t('Header/Footer');
  t('Homepage Promo');
  t('Main');
  t('Navigation / Site Taxonomy');
  t('Other');
  t('Promotion');
  t('Publish');
  t('Reference');
  t('Related');
  t('Resource');
  t('TOC Builder / Images');
  t('TOC Promo');
  t('Taxonomy');
  t('Taxonomy / Filters');

  return $field_groups;
}
