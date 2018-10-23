<?php
/**
 * @file
 * product_toc_solr.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function product_toc_solr_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:toc:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'toc';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'flukestrap_toc';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f09a244d-0ac7-432d-8ce1-8d806ea55d62';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ff50c9ef-93fa-4345-afd4-d577fde7069f';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ff50c9ef-93fa-4345-afd4-d577fde7069f';
  $display->content['new-ff50c9ef-93fa-4345-afd4-d577fde7069f'] = $pane;
  $display->panels['contentmain'][0] = 'new-ff50c9ef-93fa-4345-afd4-d577fde7069f';
  $pane = new stdClass();
  $pane->pid = 'new-6fbabe5a-0a7b-4cb4-9bf6-a42643151f95';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6fbabe5a-0a7b-4cb4-9bf6-a42643151f95';
  $display->content['new-6fbabe5a-0a7b-4cb4-9bf6-a42643151f95'] = $pane;
  $display->panels['contentmain'][1] = 'new-6fbabe5a-0a7b-4cb4-9bf6-a42643151f95';
  $pane = new stdClass();
  $pane->pid = 'new-22992e7f-a7ba-4b87-8f39-91537dc8a2f0';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_articles';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '22992e7f-a7ba-4b87-8f39-91537dc8a2f0';
  $display->content['new-22992e7f-a7ba-4b87-8f39-91537dc8a2f0'] = $pane;
  $display->panels['contentmain'][2] = 'new-22992e7f-a7ba-4b87-8f39-91537dc8a2f0';
  $pane = new stdClass();
  $pane->pid = 'new-c0b1637a-4fe2-420b-a1a0-87399eeb0303';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_description_read_more';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'readmore_formatter',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'speed' => '100',
      'collapsedHeight' => '80',
      'heightMargin' => '16',
      'moreLink' => '<a href="#">Read more</a>',
      'lessLink' => '<a href="#">Close</a>',
      'embedCSS' => '1',
      'sectionCSS' => 'display: block; width: 100%;',
      'startOpen' => '0',
      'expandedClass' => 'readmore-js-expanded',
      'collapsedClass' => 'readmore-js-collapsed',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c0b1637a-4fe2-420b-a1a0-87399eeb0303';
  $display->content['new-c0b1637a-4fe2-420b-a1a0-87399eeb0303'] = $pane;
  $display->panels['contentmain'][3] = 'new-c0b1637a-4fe2-420b-a1a0-87399eeb0303';
  $pane = new stdClass();
  $pane->pid = 'new-9bc3c0f9-6b2f-4b6a-b10a-12165405cf42';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_product_tocs-top_sellers';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9bc3c0f9-6b2f-4b6a-b10a-12165405cf42';
  $display->content['new-9bc3c0f9-6b2f-4b6a-b10a-12165405cf42'] = $pane;
  $display->panels['contentmain'][4] = 'new-9bc3c0f9-6b2f-4b6a-b10a-12165405cf42';
  $pane = new stdClass();
  $pane->pid = 'new-4abfdf6c-df99-462a-8883-c55e5a6402d4';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'quicktabs-product_toc_listings';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'products/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '4abfdf6c-df99-462a-8883-c55e5a6402d4';
  $display->content['new-4abfdf6c-df99-462a-8883-c55e5a6402d4'] = $pane;
  $display->panels['contentmain'][5] = 'new-4abfdf6c-df99-462a-8883-c55e5a6402d4';
  $pane = new stdClass();
  $pane->pid = 'new-7b723bdc-4ad3-4361-9b8a-47a32bf8ce7a';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_product_tocs-toc_tabs_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '7b723bdc-4ad3-4361-9b8a-47a32bf8ce7a';
  $display->content['new-7b723bdc-4ad3-4361-9b8a-47a32bf8ce7a'] = $pane;
  $display->panels['contentmain'][6] = 'new-7b723bdc-4ad3-4361-9b8a-47a32bf8ce7a';
  $pane = new stdClass();
  $pane->pid = 'new-62c80385-c3fd-43db-9492-92b3527d6da0';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '0',
          'paths' => 'products/*
solutions/fluke-news
solutions/fluke-news/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '62c80385-c3fd-43db-9492-92b3527d6da0';
  $display->content['new-62c80385-c3fd-43db-9492-92b3527d6da0'] = $pane;
  $display->panels['contentmain'][7] = 'new-62c80385-c3fd-43db-9492-92b3527d6da0';
  $pane = new stdClass();
  $pane->pid = 'new-51aeab9c-47ff-40bc-943e-468bf0be10e3';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_toc_featured_articles';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'solutions/fluke-news
solutions/fluke-news/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '51aeab9c-47ff-40bc-943e-468bf0be10e3';
  $display->content['new-51aeab9c-47ff-40bc-943e-468bf0be10e3'] = $pane;
  $display->panels['contentmain'][8] = 'new-51aeab9c-47ff-40bc-943e-468bf0be10e3';
  $pane = new stdClass();
  $pane->pid = 'new-93c8886a-0ef0-4f5d-aeb7-1ff33c0dc3f9';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_toc_top_stories';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'solutions/fluke-news',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '93c8886a-0ef0-4f5d-aeb7-1ff33c0dc3f9';
  $display->content['new-93c8886a-0ef0-4f5d-aeb7-1ff33c0dc3f9'] = $pane;
  $display->panels['contentmain'][9] = 'new-93c8886a-0ef0-4f5d-aeb7-1ff33c0dc3f9';
  $pane = new stdClass();
  $pane->pid = 'new-9706f75c-598d-4104-a1d0-fd7b99c91063';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-fluke_news_toc_top_stories';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'solutions/fluke-news/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '9706f75c-598d-4104-a1d0-fd7b99c91063';
  $display->content['new-9706f75c-598d-4104-a1d0-fd7b99c91063'] = $pane;
  $display->panels['contentmain'][10] = 'new-9706f75c-598d-4104-a1d0-fd7b99c91063';
  $pane = new stdClass();
  $pane->pid = 'new-88312fb9-7b92-4b38-bef7-4cec9b3b94a4';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_toc_recent_stories';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'solutions/fluke-news',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '88312fb9-7b92-4b38-bef7-4cec9b3b94a4';
  $display->content['new-88312fb9-7b92-4b38-bef7-4cec9b3b94a4'] = $pane;
  $display->panels['contentmain'][11] = 'new-88312fb9-7b92-4b38-bef7-4cec9b3b94a4';
  $pane = new stdClass();
  $pane->pid = 'new-1be34276-abe4-46d9-b06f-70145bc4f579';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_flukenews_cool_links';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'solutions/fluke-news',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '1be34276-abe4-46d9-b06f-70145bc4f579';
  $display->content['new-1be34276-abe4-46d9-b06f-70145bc4f579'] = $pane;
  $display->panels['contentmain'][12] = 'new-1be34276-abe4-46d9-b06f-70145bc4f579';
  $pane = new stdClass();
  $pane->pid = 'new-c632c459-493d-43bb-8659-52c839ff252b';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_flukenews_surveylink';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'solutions/fluke-news',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = 'c632c459-493d-43bb-8659-52c839ff252b';
  $display->content['new-c632c459-493d-43bb-8659-52c839ff252b'] = $pane;
  $display->panels['contentmain'][13] = 'new-c632c459-493d-43bb-8659-52c839ff252b';
  $pane = new stdClass();
  $pane->pid = 'new-f88e943e-a240-4909-9c80-6f2f778f2753';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_sub_rel_products';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f88e943e-a240-4909-9c80-6f2f778f2753';
  $display->content['new-f88e943e-a240-4909-9c80-6f2f778f2753'] = $pane;
  $display->panels['footer'][0] = 'new-f88e943e-a240-4909-9c80-6f2f778f2753';
  $pane = new stdClass();
  $pane->pid = 'new-68eb9bbf-5fdb-4da9-9a1e-63f5600624ce';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_sub_rel_articles';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '68eb9bbf-5fdb-4da9-9a1e-63f5600624ce';
  $display->content['new-68eb9bbf-5fdb-4da9-9a1e-63f5600624ce'] = $pane;
  $display->panels['footer'][1] = 'new-68eb9bbf-5fdb-4da9-9a1e-63f5600624ce';
  $pane = new stdClass();
  $pane->pid = 'new-30176d9d-2409-4d26-b025-64e8a490ba9e';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_url_products_solr';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '30176d9d-2409-4d26-b025-64e8a490ba9e';
  $display->content['new-30176d9d-2409-4d26-b025-64e8a490ba9e'] = $pane;
  $display->panels['footer'][2] = 'new-30176d9d-2409-4d26-b025-64e8a490ba9e';
  $pane = new stdClass();
  $pane->pid = 'new-f9e4ec6e-4900-400f-b6e3-1a1ec8a05f92';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_url_resources_solr';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f9e4ec6e-4900-400f-b6e3-1a1ec8a05f92';
  $display->content['new-f9e4ec6e-4900-400f-b6e3-1a1ec8a05f92'] = $pane;
  $display->panels['footer'][3] = 'new-f9e4ec6e-4900-400f-b6e3-1a1ec8a05f92';
  $pane = new stdClass();
  $pane->pid = 'new-5691a134-b784-4d31-bce0-975e098eda83';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5691a134-b784-4d31-bce0-975e098eda83';
  $display->content['new-5691a134-b784-4d31-bce0-975e098eda83'] = $pane;
  $display->panels['header'][0] = 'new-5691a134-b784-4d31-bce0-975e098eda83';
  $pane = new stdClass();
  $pane->pid = 'new-f1647a79-7e57-4a82-b806-0696c8da694f';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_nav';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f1647a79-7e57-4a82-b806-0696c8da694f';
  $display->content['new-f1647a79-7e57-4a82-b806-0696c8da694f'] = $pane;
  $display->panels['sidebar'][0] = 'new-f1647a79-7e57-4a82-b806-0696c8da694f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:toc:default:default'] = $panelizer;

  return $export;
}
