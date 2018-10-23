<?php

function igcommerce_utility_articles_safety_notice_content() {
  $name = 'safety_notice';
  
  $settings = array();
  $settings = array(
      'ajax' => 0,
      'hide_if_empty' => 1,
      'default_tab' => 0,
      'title' => 'Safety Notices',
      'renderer' => 'quicktabs',
      'style' => 'nostyle',
  );
  
  $custom_tabs = array();
  
  //Callback
  $custom_tabs[] = array(
      'title' => t('Current'),
      'bid' => 'igcommerce_utility_articles_delta_article_safety_notice_current',
      'weight' => 1,
      'type' => 'block',
      'hide_title' => FALSE,
  );
  
  $custom_tabs[] = array(
      'title' => t('Archive'),
      'bid' => 'igcommerce_utility_articles_delta_article_safety_notice_archive',
      'weight' => 2,
      'type' => 'block',
      'hide_title' => FALSE,
  );

  $qt = quicktabs_build_quicktabs($name, $settings, $custom_tabs);
  return drupal_render($qt);  
}

function igcommerce_utility_articles_safety_notice_archive() {
  global $language;
  
  if (!$docs = igcommerce_utility_articles_safety_notice_get_entities('archive')) {
    return t('No Results Found');
  }
  
  $items = array();
  
  foreach ($docs as $doc) {
    $title = $doc->ss_field_content_title;
    $url = '/' . $doc->path_alias;
    $vars['title'] = l($title, $url);
    $desc = '';
    if (!empty($doc->ss_article_short_summary)) {
      $desc = $doc->ss_article_short_summary;
    }
    $vars['desc'] = $desc;
    $items[] = theme('articles_safety_notice_item', $vars);
  }  
  
  return theme('item_list', array('items' => $items));
}

function igcommerce_utility_articles_safety_notice_current() {
  global $language;
  
  if (!$docs = igcommerce_utility_articles_safety_notice_get_entities('current')) {
    return t('No Results Found');
  }
  
  $items = array();
  
  foreach ($docs as $doc) {
    $title = $doc->ss_field_content_title;
    // If there is not ss_field_content_title, use the label instead.
    // This means there is a content issue, but will prevent 'empty' items from showing 
    if (empty($doc->ss_field_content_title)) {
      $title = $doc->label;
    }
    $url = '/' . $doc->path_alias;
    $vars['title'] = l($title, $url);
    $desc = '';
    if (!empty($doc->ss_article_short_summary)) {
      $desc = $doc->ss_article_short_summary;
    }
    $vars['desc'] = $desc;
    $items[] = theme('articles_safety_notice_item', $vars);
  }
  
  return theme('item_list', array('items' => $items));
}

/**
 * Query article entities based on field_current_archive value
 * @param unknown $type
 * MIG2219: field_article_type Press Release(2054) - Safety Notice (2055)
 */
function igcommerce_utility_articles_safety_notice_get_entities($type) {
  global $language;
  
  $filters = array(
      'entity_type' => 'node',
      'bundle' => 'article',
      'ss_language' => $language->language,
      'bs_status' => TRUE, // only interested in published articles
      'sm_article_type' => 2055, // only interested in safety notices, NOT press releases
      'ss_field_current_archive' => $type,
  );
  
  $query = fluke_solr_get_connection();
  $filters = fluke_solr_add_filters($query, array('rows' => 1000, 'filters' => $filters, 'sort' => array('ds_created' => 'desc')));
  $response = fluke_solr_query($filters);
  
  if (empty($response->response->docs[0])) {
    return;
  }  
  
  return $response->response->docs;  
}