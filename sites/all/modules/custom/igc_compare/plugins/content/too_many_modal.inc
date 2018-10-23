<?php

$plugin = array(
  'title' => t('Compare Selection: Too many modal'),
  'description' => t(''),
  'category' => 'Widgets',
  'icon' => '',
  'render callback' => 'igc_compare_too_many_modal_block',
  'defaults' => array(),
);

// render callback
function igc_compare_too_many_modal_block() {

  $block = new stdClass();
  $modal_vars = [
    'modal_title' => t('[Not the actual modal title]'),
    'modal_body' => t('[Not the actual modal message]'),
  ];

  $block->content = theme('too_many_modal', $modal_vars);
  $block->id = 'igc-compare-too-many-modal';

  return $block;
}
