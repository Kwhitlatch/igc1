<?php

$plugin = array(
'title' => t('Where To Buy - Title & Description'),
'description' => t('Retrieve and display title and description from solr'),
'category' => 'Widgets',
'icon' => '',
'render callback' => 'wtb_title_block',
'defaults' => array(),
);

// render callback
function wtb_title_block() {

  $block = new stdClass();
  $content = igcommerce_event_title_description('Where to buy', TRUE);

  // Also retrieve the basic page content
  $content .= igcommerce_wtb_page('Where to buy');

  $block->content = $content;
  $block->id = 'wtb-title-block';




  return $block;
}
