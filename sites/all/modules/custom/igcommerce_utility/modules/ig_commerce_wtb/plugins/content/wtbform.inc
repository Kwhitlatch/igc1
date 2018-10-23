<?php

$plugin = array(
'title' => t('Where To Buy Solr Search'),
'description' => t(''),
'category' => 'Widgets',
'icon' => '',
'render callback' => 'wtb_form_block',
'defaults' => array(),
);

// render callback
function wtb_form_block() {

    $block = new stdClass();
    $block->content = drupal_get_form('ig_commerce_wtb_form');
    $block->id = 'wtb-form-block';

    return $block;
}
