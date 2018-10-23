
<?php
/*
 * @file
 * Admin setting form for event banner header.
 */

/*
 *
 */
function igcommerce_event_admin_setting() {
  $form = array();

  // Banner image of event.
  $form['igcommerce_event_default_banner_image'] = array(
    '#type' => 'textfield',
    '#title' => 'The default banner image URL',
    '#description' => t('The URL to the default banner image in the DAM'),
    '#default_value' => variable_get('igcommerce_event_default_banner_image', '//data.fluke.com/sites/default/files/banner-products-banner-PLACEHOLDER-1920x290.jpg'),
    '#required' => TRUE,
  );

  // Event Title.
  $form['igcommerce_event_title'] = array(
    '#type' => 'textfield',
    '#title' => 'Event Title',
    '#description' => t('The title for the event'),
    '#default_value' => variable_get('igcommerce_event_title', 'Event Listing'),
    '#required' => TRUE,
  );

  // Event Description.
  $form['igcommerce_event_description'] = array(
    '#type' => 'textarea',
    '#title' => 'Event Description',
    '#description' => t('The description of the event'),
    '#default_value' => variable_get('igcommerce_event_description', 'Event List description'),
    '#rows' => 5,
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
