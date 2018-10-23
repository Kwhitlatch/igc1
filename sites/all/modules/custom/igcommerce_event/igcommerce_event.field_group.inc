<?php
/**
 * @file
 * igcommerce_event1.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function igcommerce_event_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_details|node|event|form';
  $field_group->group_name = 'group_event_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event';
  $field_group->data = array(
    'label' => 'Event details',
    'weight' => '23',
    'children' => array(
      0 => 'field_event_product',
      1 => 'field_event_date',
      2 => 'field_event_price',
      3 => 'field_event_location',
      4 => 'field_event_register_button',
      5 => 'field_event_image',
      6 => 'field_event_what_you_will_learn',
      7 => 'field_events_type',
      8 => 'field_event_what_you_will_be_get',
      9 => 'field_event_sponsor',
      10 => 'field_event_industry',
      11 => 'field_event_product_category',
      12 => 'field_event_application',
      13 => 'field_event_feature',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Event details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-event-details  field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_event_details|node|event|form'] = $field_group;

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
      0 => 'language',
      1 => 'group_general',
      2 => 'group_navigation',
      3 => 'group_event_details',
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

  // Translatables
  // Included for use with string extractors like potx.
  t('Event');
  t('Event details');

  return $field_groups;
}
