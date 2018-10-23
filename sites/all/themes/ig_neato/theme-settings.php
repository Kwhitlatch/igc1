<?php


function ig_neato_form_system_theme_settings_alter(&$form, &$form_state){

  $form['ig_neato_theme_selector'] = array(
    '#type' => 'radios',
    '#title' => t('Brand Specific Theme File'),
    '#options' => array(
      'styles-fluke' => t('Fluke'),
      'styles-amprobe' => t('Amprobe'),
        'styles-fpi' => t('Fluke Process Instruments'),
        'styles-pomona' => t('Pomona'),
    ),
    '#default_value' => theme_get_setting('ig_neato_theme_selector'),
    '#description' => t('Select which theme files you want to use.'),
    // Place this above the color scheme options.
    '#weight' => -2,
  );

}