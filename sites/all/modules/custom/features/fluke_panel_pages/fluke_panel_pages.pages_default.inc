<?php
/**
 * @file
 * fluke_panel_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function fluke_panel_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'custom_faceted_search_page';
  $page->task = 'page';
  $page->admin_title = 'Search';
  $page->admin_description = '';
  $page->path = 'search/page';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_custom_faceted_search_page__panel_context_c2449c37-dd01-49f3-b275-9fdd50ea4db7';
  $handler->task = 'page';
  $handler->subtask = 'custom_faceted_search_page';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-srch',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_toc';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '40e1fa99-d9a7-462c-83b2-75b12b4aac30';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_custom_faceted_search_page__panel_context_c2449c37-dd01-49f3-b275-9fdd50ea4db7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-65ed0cc6-d604-45a0-b5cc-6b8ef204f0ea';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_solr-search_keyword';
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
  $pane->uuid = '65ed0cc6-d604-45a0-b5cc-6b8ef204f0ea';
  $display->content['new-65ed0cc6-d604-45a0-b5cc-6b8ef204f0ea'] = $pane;
  $display->panels['contentmain'][0] = 'new-65ed0cc6-d604-45a0-b5cc-6b8ef204f0ea';
  $pane = new stdClass();
  $pane->pid = 'new-76b83273-4930-4e08-9d0d-3f4560c13d1a';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_solr-search_results';
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
  $pane->uuid = '76b83273-4930-4e08-9d0d-3f4560c13d1a';
  $display->content['new-76b83273-4930-4e08-9d0d-3f4560c13d1a'] = $pane;
  $display->panels['contentmain'][1] = 'new-76b83273-4930-4e08-9d0d-3f4560c13d1a';
  $pane = new stdClass();
  $pane->pid = 'new-b9df28f9-5664-4227-b6e5-89c452a909fb';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_solr-search_filters';
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
  $pane->uuid = 'b9df28f9-5664-4227-b6e5-89c452a909fb';
  $display->content['new-b9df28f9-5664-4227-b6e5-89c452a909fb'] = $pane;
  $display->panels['sidebar'][0] = 'new-b9df28f9-5664-4227-b6e5-89c452a909fb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['custom_faceted_search_page'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'fluke_companies';
  $page->task = 'page';
  $page->admin_title = 'fluke-companies';
  $page->admin_description = 'Fluke Companies Panelizer';
  $page->path = '/fluke-companies';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_fluke_companies__panel';
  $handler->task = 'page';
  $handler->subtask = 'fluke_companies';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_pascal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c480e4ba-52ce-47ec-934f-980252f5dd68';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_fluke_companies__panel';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['fluke_companies'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'fluke_homepage_footer_pages_';
  $page->task = 'page';
  $page->admin_title = 'Fluke (homepage footer pages)';
  $page->admin_description = 'Home page footer pages template';
  $page->path = 'fluke/%display_url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'display_url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_fluke_homepage_footer_pages___panel';
  $handler->task = 'page';
  $handler->subtask = 'fluke_homepage_footer_pages_';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_todd';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4cbfa113-745c-4f04-9ce0-1f432612bea2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_fluke_homepage_footer_pages___panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d0b867c2-cf42-4d7e-b47e-efc5ca349634';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_support_pages';
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
  $pane->uuid = 'd0b867c2-cf42-4d7e-b47e-efc5ca349634';
  $display->content['new-d0b867c2-cf42-4d7e-b47e-efc5ca349634'] = $pane;
  $display->panels['contentmain'][0] = 'new-d0b867c2-cf42-4d7e-b47e-efc5ca349634';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['fluke_homepage_footer_pages_'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'fluke_news_toc_page_home';
  $page->task = 'page';
  $page->admin_title = 'Fluke News TOC page - home';
  $page->admin_description = '';
  $page->path = 'solutions/fluke-news';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_fluke_news_toc_page_home__panel';
  $handler->task = 'page';
  $handler->subtask = 'fluke_news_toc_page_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->title = '';
  $display->uuid = '04b7647d-15bf-4272-983c-4647bbed8e38';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_fluke_news_toc_page_home__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-79624a09-d1df-4d90-82ab-0e640144ef85';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_subcategory_header';
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
  $pane->uuid = '79624a09-d1df-4d90-82ab-0e640144ef85';
  $display->content['new-79624a09-d1df-4d90-82ab-0e640144ef85'] = $pane;
  $display->panels['contentmain'][0] = 'new-79624a09-d1df-4d90-82ab-0e640144ef85';
  $pane = new stdClass();
  $pane->pid = 'new-af4f238b-e423-4e56-83d5-57d787488557';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'af4f238b-e423-4e56-83d5-57d787488557';
  $display->content['new-af4f238b-e423-4e56-83d5-57d787488557'] = $pane;
  $display->panels['contentmain'][1] = 'new-af4f238b-e423-4e56-83d5-57d787488557';
  $pane = new stdClass();
  $pane->pid = 'new-490d51cb-df5c-4f18-9ad8-a65ded4cb140';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '490d51cb-df5c-4f18-9ad8-a65ded4cb140';
  $display->content['new-490d51cb-df5c-4f18-9ad8-a65ded4cb140'] = $pane;
  $display->panels['contentmain'][2] = 'new-490d51cb-df5c-4f18-9ad8-a65ded4cb140';
  $pane = new stdClass();
  $pane->pid = 'new-bf96eca9-a891-4222-9c33-1788770b792a';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'bf96eca9-a891-4222-9c33-1788770b792a';
  $display->content['new-bf96eca9-a891-4222-9c33-1788770b792a'] = $pane;
  $display->panels['contentmain'][3] = 'new-bf96eca9-a891-4222-9c33-1788770b792a';
  $pane = new stdClass();
  $pane->pid = 'new-2c11cee2-1ddd-4d4b-b801-b87db40dc551';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2c11cee2-1ddd-4d4b-b801-b87db40dc551';
  $display->content['new-2c11cee2-1ddd-4d4b-b801-b87db40dc551'] = $pane;
  $display->panels['contentmain'][4] = 'new-2c11cee2-1ddd-4d4b-b801-b87db40dc551';
  $pane = new stdClass();
  $pane->pid = 'new-adf03291-ba4d-45e7-a3a2-387a035513cf';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'adf03291-ba4d-45e7-a3a2-387a035513cf';
  $display->content['new-adf03291-ba4d-45e7-a3a2-387a035513cf'] = $pane;
  $display->panels['footer'][0] = 'new-adf03291-ba4d-45e7-a3a2-387a035513cf';
  $pane = new stdClass();
  $pane->pid = 'new-88fa0c80-c8d3-4989-87a0-5953220b8243';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_sub_rel_articles_solr';
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
  $pane->uuid = '88fa0c80-c8d3-4989-87a0-5953220b8243';
  $display->content['new-88fa0c80-c8d3-4989-87a0-5953220b8243'] = $pane;
  $display->panels['footer'][1] = 'new-88fa0c80-c8d3-4989-87a0-5953220b8243';
  $pane = new stdClass();
  $pane->pid = 'new-bca98df2-c632-414c-a874-78d8e74419ec';
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
  $pane->uuid = 'bca98df2-c632-414c-a874-78d8e74419ec';
  $display->content['new-bca98df2-c632-414c-a874-78d8e74419ec'] = $pane;
  $display->panels['header'][0] = 'new-bca98df2-c632-414c-a874-78d8e74419ec';
  $pane = new stdClass();
  $pane->pid = 'new-fdc16b07-eeec-4c1e-931b-b835cbf3872c';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_banner_solr';
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
  $pane->uuid = 'fdc16b07-eeec-4c1e-931b-b835cbf3872c';
  $display->content['new-fdc16b07-eeec-4c1e-931b-b835cbf3872c'] = $pane;
  $display->panels['header'][1] = 'new-fdc16b07-eeec-4c1e-931b-b835cbf3872c';
  $pane = new stdClass();
  $pane->pid = 'new-82e0a389-bd19-4b7a-bff5-d02ffab16658';
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
  $pane->uuid = '82e0a389-bd19-4b7a-bff5-d02ffab16658';
  $display->content['new-82e0a389-bd19-4b7a-bff5-d02ffab16658'] = $pane;
  $display->panels['sidebar'][0] = 'new-82e0a389-bd19-4b7a-bff5-d02ffab16658';
  $pane = new stdClass();
  $pane->pid = 'new-27d1144f-63fe-4a4a-933d-f67e64b532b0';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_nav_solr';
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
  $pane->uuid = '27d1144f-63fe-4a4a-933d-f67e64b532b0';
  $display->content['new-27d1144f-63fe-4a4a-933d-f67e64b532b0'] = $pane;
  $display->panels['sidebar'][1] = 'new-27d1144f-63fe-4a4a-933d-f67e64b532b0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['fluke_news_toc_page_home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'fluke_news_toc_page_specific_article_web_card';
  $page->task = 'page';
  $page->admin_title = 'Learn - Blog - Specific Article Page';
  $page->admin_description = '';
  $page->path = 'learn/blog/%category/%article_alias';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'category' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'article_alias' => array(
      'id' => 2,
      'identifier' => 'String 2',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_fluke_news_toc_page_specific_article_web_card__panel_context_3b5dea9f-8f3c-42aa-a29c-03c953fade50';
  $handler->task = 'page';
  $handler->subtask = 'fluke_news_toc_page_specific_article_web_card';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_fnpshortline';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b0e1800f-4976-4558-b11e-ca01a7507740';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_fluke_news_toc_page_specific_article_web_card__panel_context_3b5dea9f-8f3c-42aa-a29c-03c953fade50';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-eb3fee41-66fe-434f-b484-886c3232d09f';
  $pane->panel = 'contentleft';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_title';
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
  $pane->uuid = 'eb3fee41-66fe-434f-b484-886c3232d09f';
  $display->content['new-eb3fee41-66fe-434f-b484-886c3232d09f'] = $pane;
  $display->panels['contentleft'][0] = 'new-eb3fee41-66fe-434f-b484-886c3232d09f';
  $pane = new stdClass();
  $pane->pid = 'new-d97be7a3-2e43-4ab8-a627-805db83eb47e';
  $pane->panel = 'contentleft';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_topic';
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
  $pane->uuid = 'd97be7a3-2e43-4ab8-a627-805db83eb47e';
  $display->content['new-d97be7a3-2e43-4ab8-a627-805db83eb47e'] = $pane;
  $display->panels['contentleft'][1] = 'new-d97be7a3-2e43-4ab8-a627-805db83eb47e';
  $pane = new stdClass();
  $pane->pid = 'new-e1298771-46e9-47ec-acbc-74590eecca47';
  $pane->panel = 'contentleft';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_header_image';
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
  $pane->uuid = 'e1298771-46e9-47ec-acbc-74590eecca47';
  $display->content['new-e1298771-46e9-47ec-acbc-74590eecca47'] = $pane;
  $display->panels['contentleft'][2] = 'new-e1298771-46e9-47ec-acbc-74590eecca47';
  $pane = new stdClass();
  $pane->pid = 'new-47e5701b-61ae-468b-b969-a1044fff16e4';
  $pane->panel = 'contentleft';
  $pane->type = 'views';
  $pane->subtype = 'share_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'social_share_block',
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
  $pane->uuid = '47e5701b-61ae-468b-b969-a1044fff16e4';
  $display->content['new-47e5701b-61ae-468b-b969-a1044fff16e4'] = $pane;
  $display->panels['contentleft'][3] = 'new-47e5701b-61ae-468b-b969-a1044fff16e4';
  $pane = new stdClass();
  $pane->pid = 'new-00774266-64eb-4081-9eef-89d26ac9d42d';
  $pane->panel = 'contentleft';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_subtitle';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '00774266-64eb-4081-9eef-89d26ac9d42d';
  $display->content['new-00774266-64eb-4081-9eef-89d26ac9d42d'] = $pane;
  $display->panels['contentleft'][4] = 'new-00774266-64eb-4081-9eef-89d26ac9d42d';
  $pane = new stdClass();
  $pane->pid = 'new-660c00e5-0e98-4fa0-af50-c5858238cf35';
  $pane->panel = 'contentleft';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_desc';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '660c00e5-0e98-4fa0-af50-c5858238cf35';
  $display->content['new-660c00e5-0e98-4fa0-af50-c5858238cf35'] = $pane;
  $display->panels['contentleft'][5] = 'new-660c00e5-0e98-4fa0-af50-c5858238cf35';
  $pane = new stdClass();
  $pane->pid = 'new-229ba998-c67f-4d9f-9a31-32506a499d57';
  $pane->panel = 'contentleft';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_recent_article';
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
  $pane->uuid = '229ba998-c67f-4d9f-9a31-32506a499d57';
  $display->content['new-229ba998-c67f-4d9f-9a31-32506a499d57'] = $pane;
  $display->panels['contentleft'][6] = 'new-229ba998-c67f-4d9f-9a31-32506a499d57';
  $pane = new stdClass();
  $pane->pid = 'new-0f0dbe57-5818-4736-b322-e24191f194a5';
  $pane->panel = 'contentleft';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_recommended_product';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '0f0dbe57-5818-4736-b322-e24191f194a5';
  $display->content['new-0f0dbe57-5818-4736-b322-e24191f194a5'] = $pane;
  $display->panels['contentleft'][7] = 'new-0f0dbe57-5818-4736-b322-e24191f194a5';
  $pane = new stdClass();
  $pane->pid = 'new-b8d79dd2-2a20-482f-a90c-392a8c9aae6d';
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
  $pane->uuid = 'b8d79dd2-2a20-482f-a90c-392a8c9aae6d';
  $display->content['new-b8d79dd2-2a20-482f-a90c-392a8c9aae6d'] = $pane;
  $display->panels['sidebar'][0] = 'new-b8d79dd2-2a20-482f-a90c-392a8c9aae6d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['fluke_news_toc_page_specific_article_web_card'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'fluke_platinum_technical_distributors';
  $page->task = 'page';
  $page->admin_title = 'Fluke Platinum Technical Distributors';
  $page->admin_description = 'It will show article page for Press Releases, Software Downloads, Safety Notices';
  $page->path = 'where-to-buy/fluke-platinum-technical-distributors';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_fluke_platinum_technical_distributors__panel_context_4546d841-8496-4ac0-8d47-f48eae3c819f';
  $handler->task = 'page';
  $handler->subtask = 'fluke_platinum_technical_distributors';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_toc';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2ffe58f6-e3b8-4392-81fc-c005d6bbecb9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_fluke_platinum_technical_distributors__panel_context_4546d841-8496-4ac0-8d47-f48eae3c819f';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5719ed3f-8683-4b5a-b851-aa66c695d458';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_title';
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
  $pane->uuid = '5719ed3f-8683-4b5a-b851-aa66c695d458';
  $display->content['new-5719ed3f-8683-4b5a-b851-aa66c695d458'] = $pane;
  $display->panels['contentmain'][0] = 'new-5719ed3f-8683-4b5a-b851-aa66c695d458';
  $pane = new stdClass();
  $pane->pid = 'new-62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_desc';
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
  $pane->uuid = '62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $display->content['new-62f2f829-b823-415a-82d6-4f4dbc06a8e4'] = $pane;
  $display->panels['contentmain'][1] = 'new-62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $pane = new stdClass();
  $pane->pid = 'new-907f6a7f-680c-4963-be91-ccabd518a999';
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
  $pane->uuid = '907f6a7f-680c-4963-be91-ccabd518a999';
  $display->content['new-907f6a7f-680c-4963-be91-ccabd518a999'] = $pane;
  $display->panels['sidebar'][0] = 'new-907f6a7f-680c-4963-be91-ccabd518a999';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['fluke_platinum_technical_distributors'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'footer_pages';
  $page->task = 'page';
  $page->admin_title = 'Footer Pages';
  $page->admin_description = '';
  $page->path = 'site/%url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_footer_pages__panel_context_344b9fbf-aa25-4a8f-ac88-aa0acfcb475f';
  $handler->task = 'page';
  $handler->subtask = 'footer_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array(
    'method' => '0',
    'settings' => array(),
  );
  $display->title = '';
  $display->uuid = '718582de-c8a5-4a36-927a-15abd579ce4a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_footer_pages__panel_context_344b9fbf-aa25-4a8f-ac88-aa0acfcb475f';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1eed2ca3-0a11-47f3-881f-9bf795993b4e';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'support_page_view-footer_pages_desc';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1eed2ca3-0a11-47f3-881f-9bf795993b4e';
  $display->content['new-1eed2ca3-0a11-47f3-881f-9bf795993b4e'] = $pane;
  $display->panels['contentmain'][0] = 'new-1eed2ca3-0a11-47f3-881f-9bf795993b4e';
  $pane = new stdClass();
  $pane->pid = 'new-e82b05e1-f2fa-4e35-9571-7182ddb83a0a';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_banner';
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
  $pane->uuid = 'e82b05e1-f2fa-4e35-9571-7182ddb83a0a';
  $display->content['new-e82b05e1-f2fa-4e35-9571-7182ddb83a0a'] = $pane;
  $display->panels['header'][0] = 'new-e82b05e1-f2fa-4e35-9571-7182ddb83a0a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['footer_pages'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'instrument_security';
  $page->task = 'page';
  $page->admin_title = 'Instrument Security';
  $page->admin_description = '';
  $page->path = 'support/instrument-security';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_instrument_security__panel_context_2c6b6c81-c12a-471e-a9ca-a4481747bca6';
  $handler->task = 'page';
  $handler->subtask = 'instrument_security';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F18',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_toc';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'title' => NULL,
      'header' => NULL,
      'slideshow' => NULL,
      'alert-panel' => NULL,
      'key-features' => NULL,
      'libby-request-pricing' => NULL,
      'overview' => NULL,
      'prod-models' => NULL,
      'prod-accessories' => NULL,
      'resources' => NULL,
      'related' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Instrument Security';
  $display->uuid = 'fb7c39ba-4e06-4a36-ad05-48adbb4c94a1';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_instrument_security__panel_context_2c6b6c81-c12a-471e-a9ca-a4481747bca6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b469434d-5307-44f2-9298-b797db75f09a';
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
  $pane->uuid = 'b469434d-5307-44f2-9298-b797db75f09a';
  $display->content['new-b469434d-5307-44f2-9298-b797db75f09a'] = $pane;
  $display->panels['contentmain'][0] = 'new-b469434d-5307-44f2-9298-b797db75f09a';
  $pane = new stdClass();
  $pane->pid = 'new-633d8d36-a811-4449-b9fb-cd63ac39065f';
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
  $pane->uuid = '633d8d36-a811-4449-b9fb-cd63ac39065f';
  $display->content['new-633d8d36-a811-4449-b9fb-cd63ac39065f'] = $pane;
  $display->panels['contentmain'][1] = 'new-633d8d36-a811-4449-b9fb-cd63ac39065f';
  $pane = new stdClass();
  $pane->pid = 'new-17b89f63-47d1-4368-9a3d-d321e5e41206';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_support-instrument_security_page';
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
  $pane->uuid = '17b89f63-47d1-4368-9a3d-d321e5e41206';
  $display->content['new-17b89f63-47d1-4368-9a3d-d321e5e41206'] = $pane;
  $display->panels['contentmain'][2] = 'new-17b89f63-47d1-4368-9a3d-d321e5e41206';
  $pane = new stdClass();
  $pane->pid = 'new-ae51cd98-547d-4357-910e-8b8c3ab615ab';
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
  $pane->uuid = 'ae51cd98-547d-4357-910e-8b8c3ab615ab';
  $display->content['new-ae51cd98-547d-4357-910e-8b8c3ab615ab'] = $pane;
  $display->panels['sidebar'][0] = 'new-ae51cd98-547d-4357-910e-8b8c3ab615ab';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['instrument_security'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'layout_tester';
  $page->task = 'page';
  $page->admin_title = 'layout-tester';
  $page->admin_description = '';
  $page->path = 'layout-tester';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_layout_tester__panel';
  $handler->task = 'page';
  $handler->subtask = 'layout_tester';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_pascal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
      'slideshow' => NULL,
      'secondary-nav' => NULL,
      'homepage-articles' => NULL,
      'center' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd551fb76-4202-46f4-9d6f-449383cd7072';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_layout_tester__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5f110277-b481-4849-9d36-f6c270476ff4';
  $pane->panel = 'contentmain';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Cicero Was here',
    'title' => 'Lorem',
    'body' => '<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
<div>
	&nbsp;</div>
<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
<div>
	&nbsp;</div>
<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
<div>
	&nbsp;</div>
<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
<div>
	&nbsp;</div>
<div>
	&nbsp;</div>
<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
<div>
	&nbsp;</div>
<div>
	&nbsp;</div>
<div>
	Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod</div>
<div>
	tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,</div>
<div>
	quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo</div>
<div>
	consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse</div>
<div>
	cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non</div>
<div>
	proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</div>
',
    'format' => 'filtered_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5f110277-b481-4849-9d36-f6c270476ff4';
  $display->content['new-5f110277-b481-4849-9d36-f6c270476ff4'] = $pane;
  $display->panels['contentmain'][0] = 'new-5f110277-b481-4849-9d36-f6c270476ff4';
  $pane = new stdClass();
  $pane->pid = 'new-f61cb763-c603-49e6-be01-133e70b67479';
  $pane->panel = 'sidebar';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Test sidebar nav',
    'title' => 'Test sidebar nav',
    'body' => '<pre style="box-sizing: border-box; overflow: auto; font-family: Menlo, Monaco, Consolas, \'Courier New\', monospace; font-size: 13px; padding: 0px; margin-top: 0px; margin-bottom: 0px; line-height: 1.42857; color: rgb(51, 51, 51); word-break: normal; word-wrap: break-word; border: 0px; border-radius: 4px; white-space: nowrap; background-color: transparent;">
<code class="language-html" data-lang="html" style="box-sizing: border-box; font-family: Menlo, Monaco, Consolas, \'Courier New\', monospace; font-size: inherit; padding: 0px 45px 0px 0px; border-radius: 0px; white-space: pre-wrap; display: inline-block; background-color: transparent;"><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-group"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">id=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"accordion"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"tablist"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-multiselectable=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"true"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
  <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel panel-default"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-heading"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"tab"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">id=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"headingOne"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;h4</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-title"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
        <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;a</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"button"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">data-toggle=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapse"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">data-parent=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"#accordion"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">href=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"#collapseOne"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-expanded=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"true"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-controls=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapseOne"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
          Collapsible Group Item #1
        <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/a&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/h4&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">id=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapseOne"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-collapse collapse in"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"tabpanel"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-labelledby=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"headingOne"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-body"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
        Anim pariatur cliche reprehenderit, enim eiusmod high life accusamus terry richardson ad squid. 3 wolf moon officia aute, non cupidatat skateboard dolor brunch. Food truck quinoa nesciunt laborum eiusmod. Brunch 3 wolf moon tempor, sunt aliqua put a bird on it squid single-origin coffee nulla assumenda shoreditch et. Nihil anim keffiyeh helvetica, craft beer labore wes anderson cred nesciunt sapiente ea proident. Ad vegan excepteur butcher vice lomo. Leggings occaecat craft beer farm-to-table, raw denim aesthetic synth nesciunt you probably haven\'t heard of them accusamus labore sustainable VHS.
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
  <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
  <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel panel-default"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-heading"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"tab"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">id=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"headingTwo"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;h4</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-title"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
        <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;a</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapsed"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"button"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">data-toggle=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapse"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">data-parent=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"#accordion"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">href=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"#collapseTwo"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-expanded=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"false"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-controls=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapseTwo"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
          Collapsible Group Item #2
        <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/a&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/h4&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">id=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapseTwo"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-collapse collapse"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"tabpanel"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-labelledby=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"headingTwo"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-body"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
        Anim pariatur cliche reprehenderit, enim eiusmod high life accusamus terry richardson ad squid. 3 wolf moon officia aute, non cupidatat skateboard dolor brunch. Food truck quinoa nesciunt laborum eiusmod. Brunch 3 wolf moon tempor, sunt aliqua put a bird on it squid single-origin coffee nulla assumenda shoreditch et. Nihil anim keffiyeh helvetica, craft beer labore wes anderson cred nesciunt sapiente ea proident. Ad vegan excepteur butcher vice lomo. Leggings occaecat craft beer farm-to-table, raw denim aesthetic synth nesciunt you probably haven\'t heard of them accusamus labore sustainable VHS.
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
  <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
  <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel panel-default"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-heading"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"tab"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">id=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"headingThree"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;h4</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-title"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
        <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;a</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapsed"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"button"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">data-toggle=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapse"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">data-parent=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"#accordion"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">href=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"#collapseThree"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-expanded=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"false"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-controls=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapseThree"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
          Collapsible Group Item #3
        <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/a&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/h4&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">id=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"collapseThree"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-collapse collapse"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">role=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"tabpanel"</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">aria-labelledby=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"headingThree"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;div</span> <span class="na" style="box-sizing: border-box; color: rgb(79, 159, 207);">class=</span><span class="s" style="box-sizing: border-box; color: rgb(212, 73, 80);">"panel-body"</span><span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&gt;</span>
        Anim pariatur cliche reprehenderit, enim eiusmod high life accusamus terry richardson ad squid. 3 wolf moon officia aute, non cupidatat skateboard dolor brunch. Food truck quinoa nesciunt laborum eiusmod. Brunch 3 wolf moon tempor, sunt aliqua put a bird on it squid single-origin coffee nulla assumenda shoreditch et. Nihil anim keffiyeh helvetica, craft beer labore wes anderson cred nesciunt sapiente ea proident. Ad vegan excepteur butcher vice lomo. Leggings occaecat craft beer farm-to-table, raw denim aesthetic synth nesciunt you probably haven\'t heard of them accusamus labore sustainable VHS.
      <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
    <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
  <span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span>
<span class="nt" style="box-sizing: border-box; color: rgb(47, 111, 159);">&lt;/div&gt;</span></code></pre>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f61cb763-c603-49e6-be01-133e70b67479';
  $display->content['new-f61cb763-c603-49e6-be01-133e70b67479'] = $pane;
  $display->panels['sidebar'][0] = 'new-f61cb763-c603-49e6-be01-133e70b67479';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['layout_tester'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'open_solr_test_page';
  $page->task = 'page';
  $page->admin_title = 'Open Solr Test Page';
  $page->admin_description = '';
  $page->path = 'admin/open-solr-test';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_open_solr_test_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'open_solr_test_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f58ee81b-f9a0-4139-91f9-30a699036c5c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_open_solr_test_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-43cc341a-4405-40d9-ae89-97309f5d3140';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Testing Open Solr Queries',
    'title_heading' => 'h2',
    'body' => '<?php

$start = microtime(TRUE);
$output = file_get_contents("https://fluke70.solrcluster.com/solr/fluke/select?q=entity_type:node&json.nl=map&fl=entity_id,ss_field_url_title,path_alias,tm_article_display_title,ss_article_h1_title,tm_article_meta_tag_title,tm_article_meta_tag_description,tm_article_meta_tag_keyword,ss_article_short_summary&start=0&fq=bundle:article&fq=ss_language:en-us&fq=path_alias:training/electrical-safety/basic-safety-procedures/core-tools-for-live-electrical-measurement&rows=10&wt=json");

echo $output;

$end = microtime(TRUE);

$time = $end - $start;

echo "Took: " . number_format($time) . " milliseconds";
?>
',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '43cc341a-4405-40d9-ae89-97309f5d3140';
  $display->content['new-43cc341a-4405-40d9-ae89-97309f5d3140'] = $pane;
  $display->panels['center'][0] = 'new-43cc341a-4405-40d9-ae89-97309f5d3140';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-43cc341a-4405-40d9-ae89-97309f5d3140';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['open_solr_test_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products_catalogs';
  $page->task = 'page';
  $page->admin_title = 'Products - Catalogs';
  $page->admin_description = 'It will show article page for Press Releases, Software Downloads, Safety Notices';
  $page->path = 'products/catalogs';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_products_catalogs__panel_context_63454888-375b-4694-b1ce-0df376760f3a';
  $handler->task = 'page';
  $handler->subtask = 'products_catalogs';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_toc';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2ffe58f6-e3b8-4392-81fc-c005d6bbecb9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products_catalogs__panel_context_63454888-375b-4694-b1ce-0df376760f3a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5719ed3f-8683-4b5a-b851-aa66c695d458';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_title';
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
  $pane->uuid = '5719ed3f-8683-4b5a-b851-aa66c695d458';
  $display->content['new-5719ed3f-8683-4b5a-b851-aa66c695d458'] = $pane;
  $display->panels['contentmain'][0] = 'new-5719ed3f-8683-4b5a-b851-aa66c695d458';
  $pane = new stdClass();
  $pane->pid = 'new-62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_desc';
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
  $pane->uuid = '62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $display->content['new-62f2f829-b823-415a-82d6-4f4dbc06a8e4'] = $pane;
  $display->panels['contentmain'][1] = 'new-62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $pane = new stdClass();
  $pane->pid = 'new-907f6a7f-680c-4963-be91-ccabd518a999';
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
  $pane->uuid = '907f6a7f-680c-4963-be91-ccabd518a999';
  $display->content['new-907f6a7f-680c-4963-be91-ccabd518a999'] = $pane;
  $display->panels['sidebar'][0] = 'new-907f6a7f-680c-4963-be91-ccabd518a999';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products_catalogs'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products_test_tool_catalog';
  $page->task = 'page';
  $page->admin_title = 'Products - Test Tool Catalog';
  $page->admin_description = '';
  $page->path = 'products/test-tool-catalog';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_products_test_tool_catalog__panel_context_402f82ee-9cf8-4b65-8d14-556f1beba9f5';
  $handler->task = 'page';
  $handler->subtask = 'products_test_tool_catalog';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->title = '';
  $display->uuid = 'd180fe4c-5b82-4ddf-a572-6bc3fc0b9a74';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products_test_tool_catalog__panel_context_402f82ee-9cf8-4b65-8d14-556f1beba9f5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-78b40742-0e69-4e62-915e-13385ea7b09d';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_product_details';
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
  $pane->uuid = '78b40742-0e69-4e62-915e-13385ea7b09d';
  $display->content['new-78b40742-0e69-4e62-915e-13385ea7b09d'] = $pane;
  $display->panels['contentmain'][0] = 'new-78b40742-0e69-4e62-915e-13385ea7b09d';
  $pane = new stdClass();
  $pane->pid = 'new-66a76115-9526-4189-ba5b-0c49a21452d5';
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
  $pane->uuid = '66a76115-9526-4189-ba5b-0c49a21452d5';
  $display->content['new-66a76115-9526-4189-ba5b-0c49a21452d5'] = $pane;
  $display->panels['sidebar'][0] = 'new-66a76115-9526-4189-ba5b-0c49a21452d5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products_test_tool_catalog'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'promotions_and_contests';
  $page->task = 'page';
  $page->admin_title = 'Where to buy / Promos - Promotions and contests Pages';
  $page->admin_description = '';
  $page->path = 'where-to-buy/promotions-and-contests/%promos';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'promos' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_promotions_and_contests__panel';
  $handler->task = 'page';
  $handler->subtask = 'promotions_and_contests';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F25',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '9d486f22-547f-4fe1-904c-892042b94068';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_promotions_and_contests__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-13a161c0-6bac-43f1-a32e-0cc3d3e37381';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_banner';
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
  $pane->uuid = '13a161c0-6bac-43f1-a32e-0cc3d3e37381';
  $display->content['new-13a161c0-6bac-43f1-a32e-0cc3d3e37381'] = $pane;
  $display->panels['header'][0] = 'new-13a161c0-6bac-43f1-a32e-0cc3d3e37381';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-13a161c0-6bac-43f1-a32e-0cc3d3e37381';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['promotions_and_contests'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'sitemap';
  $page->task = 'page';
  $page->admin_title = 'Sitemap';
  $page->admin_description = 'A page used to display a manually curated sitemap';
  $page->path = 'sitemap';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_sitemap__panel';
  $handler->task = 'page';
  $handler->subtask = 'sitemap';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-???',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '372dce80-cd02-481a-b505-d201479031ac';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_sitemap__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9aeb79d0-b821-4f93-bf70-0d29bd79ed24';
  $pane->panel = 'contentmain';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Sitemap',
    'body' => '<pre>
<a href="/">Home<"/">
     <a href="/products">Products</a>
     <a href="/solutions">Solutions</a>
     <a href="/training">Training</a>
     <a href="/support">Support</a>
     <a href="/where-to-buy">Where to buy</a>
</pre>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9aeb79d0-b821-4f93-bf70-0d29bd79ed24';
  $display->content['new-9aeb79d0-b821-4f93-bf70-0d29bd79ed24'] = $pane;
  $display->panels['contentmain'][0] = 'new-9aeb79d0-b821-4f93-bf70-0d29bd79ed24';
  $pane = new stdClass();
  $pane->pid = 'new-309510bc-31f6-4ba6-a6e5-2bd615cd63e5';
  $pane->panel = 'header';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<img class="lazyload" src="//data.fluke.com/sites/default/files/banner-products-banner-PLACEHOLDER-1920x290.jpg" alt="">',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '309510bc-31f6-4ba6-a6e5-2bd615cd63e5';
  $display->content['new-309510bc-31f6-4ba6-a6e5-2bd615cd63e5'] = $pane;
  $display->panels['header'][0] = 'new-309510bc-31f6-4ba6-a6e5-2bd615cd63e5';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-9aeb79d0-b821-4f93-bf70-0d29bd79ed24';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['sitemap'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solutions_toc_page_completely_your_toolbelt';
  $page->task = 'page';
  $page->admin_title = 'Solutions TOC Page - Completely Your Toolbelt';
  $page->admin_description = '';
  $page->path = 'solutions/complete-your-toolbelt';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_solutions_toc_page_completely_your_toolbelt__panel';
  $handler->task = 'page';
  $handler->subtask = 'solutions_toc_page_completely_your_toolbelt';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_pascal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '08a2b4ab-20cf-42dc-9d1c-341d7e3b074c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_solutions_toc_page_completely_your_toolbelt__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ac398704-ce32-4cf0-9e62-d3c2c473b6b3';
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
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ac398704-ce32-4cf0-9e62-d3c2c473b6b3';
  $display->content['new-ac398704-ce32-4cf0-9e62-d3c2c473b6b3'] = $pane;
  $display->panels['sidebar'][0] = 'new-ac398704-ce32-4cf0-9e62-d3c2c473b6b3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ac398704-ce32-4cf0-9e62-d3c2c473b6b3';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['solutions_toc_page_completely_your_toolbelt'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solutions_toc_page_industry';
  $page->task = 'page';
  $page->admin_title = 'Solutions TOC page - Industry';
  $page->admin_description = '';
  $page->path = 'solutions/industries/%industry';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'industry' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_solutions_toc_page_industry__panel_context_d6b2f7ca-09d7-4f50-90e1-3fbcd9bc18d5';
  $handler->task = 'page';
  $handler->subtask = 'solutions_toc_page_industry';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_pascal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%topic:field-content-title';
  $display->uuid = '27f017da-cb8f-4bcf-8c51-dabd3bcf9757';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_solutions_toc_page_industry__panel_context_d6b2f7ca-09d7-4f50-90e1-3fbcd9bc18d5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fb9325d9-e3a1-4546-a59b-36a0384c93eb';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_header';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fb9325d9-e3a1-4546-a59b-36a0384c93eb';
  $display->content['new-fb9325d9-e3a1-4546-a59b-36a0384c93eb'] = $pane;
  $display->panels['contentmain'][0] = 'new-fb9325d9-e3a1-4546-a59b-36a0384c93eb';
  $pane = new stdClass();
  $pane->pid = 'new-4ca309a7-331e-454e-98ed-c2545bc68e1b';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'url_builder-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4ca309a7-331e-454e-98ed-c2545bc68e1b';
  $display->content['new-4ca309a7-331e-454e-98ed-c2545bc68e1b'] = $pane;
  $display->panels['contentmain'][1] = 'new-4ca309a7-331e-454e-98ed-c2545bc68e1b';
  $pane = new stdClass();
  $pane->pid = 'new-7c11e6d9-a8e9-45f5-afd8-9243fdf16f93';
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
  $pane->uuid = '7c11e6d9-a8e9-45f5-afd8-9243fdf16f93';
  $display->content['new-7c11e6d9-a8e9-45f5-afd8-9243fdf16f93'] = $pane;
  $display->panels['sidebar'][0] = 'new-7c11e6d9-a8e9-45f5-afd8-9243fdf16f93';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['solutions_toc_page_industry'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solutions_toc_page_preventive_maintenance';
  $page->task = 'page';
  $page->admin_title = 'Solutions TOC Page - Preventive Maintenance';
  $page->admin_description = '';
  $page->path = 'solutions/preventive-maintenance';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_solutions_toc_page_preventive_maintenance__panel';
  $handler->task = 'page';
  $handler->subtask = 'solutions_toc_page_preventive_maintenance';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_pascal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b94ee2f7-5b36-460b-a82b-c5dbe818dbb2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_solutions_toc_page_preventive_maintenance__panel';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['solutions_toc_page_preventive_maintenance'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solutions_toc_page_safety';
  $page->task = 'page';
  $page->admin_title = 'Learn TOC page - Best Practices - Safety - subcategory';
  $page->admin_description = '';
  $page->path = 'learn/best-practices/safety/%topic';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'topic' => array(
      'id' => 2,
      'identifier' => 'String 2',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_solutions_toc_page_safety__panel_context_1f91d5b5-b757-412d-be0f-ad95cdf15074';
  $handler->task = 'page';
  $handler->subtask = 'solutions_toc_page_safety';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F10',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_pascal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%topic:field-content-title';
  $display->uuid = '27f017da-cb8f-4bcf-8c51-dabd3bcf9757';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_solutions_toc_page_safety__panel_context_1f91d5b5-b757-412d-be0f-ad95cdf15074';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3e9bce3d-978a-42f5-b949-3155c36f5c76';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '3e9bce3d-978a-42f5-b949-3155c36f5c76';
  $display->content['new-3e9bce3d-978a-42f5-b949-3155c36f5c76'] = $pane;
  $display->panels['contentmain'][0] = 'new-3e9bce3d-978a-42f5-b949-3155c36f5c76';
  $pane = new stdClass();
  $pane->pid = 'new-12e59198-aa48-4900-9160-0ee4258261a4';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '12e59198-aa48-4900-9160-0ee4258261a4';
  $display->content['new-12e59198-aa48-4900-9160-0ee4258261a4'] = $pane;
  $display->panels['contentmain'][1] = 'new-12e59198-aa48-4900-9160-0ee4258261a4';
  $pane = new stdClass();
  $pane->pid = 'new-e4f7000b-beae-4d4c-903f-1165a3816d18';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'e4f7000b-beae-4d4c-903f-1165a3816d18';
  $display->content['new-e4f7000b-beae-4d4c-903f-1165a3816d18'] = $pane;
  $display->panels['contentmain'][2] = 'new-e4f7000b-beae-4d4c-903f-1165a3816d18';
  $pane = new stdClass();
  $pane->pid = 'new-63906ae4-5b01-4345-8801-f99d00ca91e6';
  $pane->panel = 'contentmain';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '63906ae4-5b01-4345-8801-f99d00ca91e6';
  $display->content['new-63906ae4-5b01-4345-8801-f99d00ca91e6'] = $pane;
  $display->panels['contentmain'][3] = 'new-63906ae4-5b01-4345-8801-f99d00ca91e6';
  $pane = new stdClass();
  $pane->pid = 'new-6a0b2dfa-f197-4a29-99d6-1ec5d1b3059a';
  $pane->panel = 'contentmain';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '6a0b2dfa-f197-4a29-99d6-1ec5d1b3059a';
  $display->content['new-6a0b2dfa-f197-4a29-99d6-1ec5d1b3059a'] = $pane;
  $display->panels['contentmain'][4] = 'new-6a0b2dfa-f197-4a29-99d6-1ec5d1b3059a';
  $pane = new stdClass();
  $pane->pid = 'new-0aee4448-d50d-4145-a18e-2d61dd9d03a2';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '0aee4448-d50d-4145-a18e-2d61dd9d03a2';
  $display->content['new-0aee4448-d50d-4145-a18e-2d61dd9d03a2'] = $pane;
  $display->panels['contentmain'][5] = 'new-0aee4448-d50d-4145-a18e-2d61dd9d03a2';
  $pane = new stdClass();
  $pane->pid = 'new-e84447c4-1262-46e3-819f-c4e6f185d495';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_product_tocs-top_sellers';
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
  $pane->uuid = 'e84447c4-1262-46e3-819f-c4e6f185d495';
  $display->content['new-e84447c4-1262-46e3-819f-c4e6f185d495'] = $pane;
  $display->panels['contentmain'][6] = 'new-e84447c4-1262-46e3-819f-c4e6f185d495';
  $pane = new stdClass();
  $pane->pid = 'new-f0066405-c034-4458-b211-5f00eccfeebf';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_subcategory_header';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'f0066405-c034-4458-b211-5f00eccfeebf';
  $display->content['new-f0066405-c034-4458-b211-5f00eccfeebf'] = $pane;
  $display->panels['contentmain'][7] = 'new-f0066405-c034-4458-b211-5f00eccfeebf';
  $pane = new stdClass();
  $pane->pid = 'new-afc1e415-a6ae-45f1-b5ab-dc9805d3e884';
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
  $pane->uuid = 'afc1e415-a6ae-45f1-b5ab-dc9805d3e884';
  $display->content['new-afc1e415-a6ae-45f1-b5ab-dc9805d3e884'] = $pane;
  $display->panels['sidebar'][0] = 'new-afc1e415-a6ae-45f1-b5ab-dc9805d3e884';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['solutions_toc_page_safety'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solutions_toc_page_tools_basics';
  $page->task = 'page';
  $page->admin_title = 'Learn TOC page - Best Practices - Test Tool Basics - subcategory';
  $page->admin_description = '';
  $page->path = 'learn/best-practices/test-tools-basics/%topic';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'topic' => array(
      'id' => 2,
      'identifier' => 'String 2',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_solutions_toc_page_tools_basics__panel_context_f98e5661-14a3-41ac-b744-a980c8d4d254';
  $handler->task = 'page';
  $handler->subtask = 'solutions_toc_page_tools_basics';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F10',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_pascal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%topic:field-content-title';
  $display->uuid = '27f017da-cb8f-4bcf-8c51-dabd3bcf9757';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_solutions_toc_page_tools_basics__panel_context_f98e5661-14a3-41ac-b744-a980c8d4d254';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3e9bce3d-978a-42f5-b949-3155c36f5c76';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '3e9bce3d-978a-42f5-b949-3155c36f5c76';
  $display->content['new-3e9bce3d-978a-42f5-b949-3155c36f5c76'] = $pane;
  $display->panels['contentmain'][0] = 'new-3e9bce3d-978a-42f5-b949-3155c36f5c76';
  $pane = new stdClass();
  $pane->pid = 'new-12e59198-aa48-4900-9160-0ee4258261a4';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '12e59198-aa48-4900-9160-0ee4258261a4';
  $display->content['new-12e59198-aa48-4900-9160-0ee4258261a4'] = $pane;
  $display->panels['contentmain'][1] = 'new-12e59198-aa48-4900-9160-0ee4258261a4';
  $pane = new stdClass();
  $pane->pid = 'new-e4f7000b-beae-4d4c-903f-1165a3816d18';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'e4f7000b-beae-4d4c-903f-1165a3816d18';
  $display->content['new-e4f7000b-beae-4d4c-903f-1165a3816d18'] = $pane;
  $display->panels['contentmain'][2] = 'new-e4f7000b-beae-4d4c-903f-1165a3816d18';
  $pane = new stdClass();
  $pane->pid = 'new-63906ae4-5b01-4345-8801-f99d00ca91e6';
  $pane->panel = 'contentmain';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '63906ae4-5b01-4345-8801-f99d00ca91e6';
  $display->content['new-63906ae4-5b01-4345-8801-f99d00ca91e6'] = $pane;
  $display->panels['contentmain'][3] = 'new-63906ae4-5b01-4345-8801-f99d00ca91e6';
  $pane = new stdClass();
  $pane->pid = 'new-6a0b2dfa-f197-4a29-99d6-1ec5d1b3059a';
  $pane->panel = 'contentmain';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '6a0b2dfa-f197-4a29-99d6-1ec5d1b3059a';
  $display->content['new-6a0b2dfa-f197-4a29-99d6-1ec5d1b3059a'] = $pane;
  $display->panels['contentmain'][4] = 'new-6a0b2dfa-f197-4a29-99d6-1ec5d1b3059a';
  $pane = new stdClass();
  $pane->pid = 'new-0aee4448-d50d-4145-a18e-2d61dd9d03a2';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '0aee4448-d50d-4145-a18e-2d61dd9d03a2';
  $display->content['new-0aee4448-d50d-4145-a18e-2d61dd9d03a2'] = $pane;
  $display->panels['contentmain'][5] = 'new-0aee4448-d50d-4145-a18e-2d61dd9d03a2';
  $pane = new stdClass();
  $pane->pid = 'new-e84447c4-1262-46e3-819f-c4e6f185d495';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_product_tocs-top_sellers';
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
  $pane->uuid = 'e84447c4-1262-46e3-819f-c4e6f185d495';
  $display->content['new-e84447c4-1262-46e3-819f-c4e6f185d495'] = $pane;
  $display->panels['contentmain'][6] = 'new-e84447c4-1262-46e3-819f-c4e6f185d495';
  $pane = new stdClass();
  $pane->pid = 'new-f0066405-c034-4458-b211-5f00eccfeebf';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_subcategory_header';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'f0066405-c034-4458-b211-5f00eccfeebf';
  $display->content['new-f0066405-c034-4458-b211-5f00eccfeebf'] = $pane;
  $display->panels['contentmain'][7] = 'new-f0066405-c034-4458-b211-5f00eccfeebf';
  $pane = new stdClass();
  $pane->pid = 'new-afc1e415-a6ae-45f1-b5ab-dc9805d3e884';
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
  $pane->uuid = 'afc1e415-a6ae-45f1-b5ab-dc9805d3e884';
  $display->content['new-afc1e415-a6ae-45f1-b5ab-dc9805d3e884'] = $pane;
  $display->panels['sidebar'][0] = 'new-afc1e415-a6ae-45f1-b5ab-dc9805d3e884';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['solutions_toc_page_tools_basics'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_about_page';
  $page->task = 'page';
  $page->admin_title = 'Support - aboutus Page';
  $page->admin_description = '';
  $page->path = 'support/about-us/%url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_about_page__panel_context_350f15b3-d09b-40e7-961e-19fbdcf21dc5';
  $handler->task = 'page';
  $handler->subtask = 'support_about_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1b548ebc-5761-4899-a292-562826d0ec78';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_about_page__panel_context_350f15b3-d09b-40e7-961e-19fbdcf21dc5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-53982a16-40b8-4e03-9170-a1960b0101cc';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_support_pages';
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
  $pane->uuid = '53982a16-40b8-4e03-9170-a1960b0101cc';
  $display->content['new-53982a16-40b8-4e03-9170-a1960b0101cc'] = $pane;
  $display->panels['contentmain'][0] = 'new-53982a16-40b8-4e03-9170-a1960b0101cc';
  $pane = new stdClass();
  $pane->pid = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
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
  $pane->uuid = '9fcef467-58dc-497c-ae4d-adee84139ac1';
  $display->content['new-9fcef467-58dc-497c-ae4d-adee84139ac1'] = $pane;
  $display->panels['sidebar'][0] = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_about_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_aboutus';
  $page->task = 'page';
  $page->admin_title = 'Support - aboutus';
  $page->admin_description = '';
  $page->path = 'support/about-us';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_aboutus__panel_context_77d9ca0a-9f1d-4346-9ad1-1706e53eb02e';
  $handler->task = 'page';
  $handler->subtask = 'support_aboutus';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F9',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1b548ebc-5761-4899-a292-562826d0ec78';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_aboutus__panel_context_77d9ca0a-9f1d-4346-9ad1-1706e53eb02e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-381a92ec-0977-4b97-a11b-07b6c7edc6ad';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '381a92ec-0977-4b97-a11b-07b6c7edc6ad';
  $display->content['new-381a92ec-0977-4b97-a11b-07b6c7edc6ad'] = $pane;
  $display->panels['contentmain'][0] = 'new-381a92ec-0977-4b97-a11b-07b6c7edc6ad';
  $pane = new stdClass();
  $pane->pid = 'new-8112f575-7df2-4a99-a6a2-e029f0c0eeb9';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '8112f575-7df2-4a99-a6a2-e029f0c0eeb9';
  $display->content['new-8112f575-7df2-4a99-a6a2-e029f0c0eeb9'] = $pane;
  $display->panels['contentmain'][1] = 'new-8112f575-7df2-4a99-a6a2-e029f0c0eeb9';
  $pane = new stdClass();
  $pane->pid = 'new-b75c7274-d3ed-4d5e-acfc-0a91fd71cf41';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'b75c7274-d3ed-4d5e-acfc-0a91fd71cf41';
  $display->content['new-b75c7274-d3ed-4d5e-acfc-0a91fd71cf41'] = $pane;
  $display->panels['contentmain'][2] = 'new-b75c7274-d3ed-4d5e-acfc-0a91fd71cf41';
  $pane = new stdClass();
  $pane->pid = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
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
  $pane->uuid = '9fcef467-58dc-497c-ae4d-adee84139ac1';
  $display->content['new-9fcef467-58dc-497c-ae4d-adee84139ac1'] = $pane;
  $display->panels['sidebar'][0] = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_aboutus'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_after_sales_china';
  $page->task = 'page';
  $page->admin_title = 'Support - After Sales - CHINA';
  $page->admin_description = '';
  $page->path = 'support/after-sales-service-and-repair';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_after_sales_china__panel_context_6680de4e-b9c3-4797-b904-c3569d4ae452';
  $handler->task = 'page';
  $handler->subtask = 'support_after_sales_china';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F9',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1b548ebc-5761-4899-a292-562826d0ec78';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_after_sales_china__panel_context_6680de4e-b9c3-4797-b904-c3569d4ae452';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-381a92ec-0977-4b97-a11b-07b6c7edc6ad';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '381a92ec-0977-4b97-a11b-07b6c7edc6ad';
  $display->content['new-381a92ec-0977-4b97-a11b-07b6c7edc6ad'] = $pane;
  $display->panels['contentmain'][0] = 'new-381a92ec-0977-4b97-a11b-07b6c7edc6ad';
  $pane = new stdClass();
  $pane->pid = 'new-8112f575-7df2-4a99-a6a2-e029f0c0eeb9';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '8112f575-7df2-4a99-a6a2-e029f0c0eeb9';
  $display->content['new-8112f575-7df2-4a99-a6a2-e029f0c0eeb9'] = $pane;
  $display->panels['contentmain'][1] = 'new-8112f575-7df2-4a99-a6a2-e029f0c0eeb9';
  $pane = new stdClass();
  $pane->pid = 'new-b75c7274-d3ed-4d5e-acfc-0a91fd71cf41';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'b75c7274-d3ed-4d5e-acfc-0a91fd71cf41';
  $display->content['new-b75c7274-d3ed-4d5e-acfc-0a91fd71cf41'] = $pane;
  $display->panels['contentmain'][2] = 'new-b75c7274-d3ed-4d5e-acfc-0a91fd71cf41';
  $pane = new stdClass();
  $pane->pid = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
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
  $pane->uuid = '9fcef467-58dc-497c-ae4d-adee84139ac1';
  $display->content['new-9fcef467-58dc-497c-ae4d-adee84139ac1'] = $pane;
  $display->panels['sidebar'][0] = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_after_sales_china'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_after_sales_china_page';
  $page->task = 'page';
  $page->admin_title = 'Support - After Sales - CHINA Page';
  $page->admin_description = '';
  $page->path = 'support/after-sales-service-and-repair/%url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_after_sales_china_page__panel_context_8d69349c-6f9f-404d-97c6-909fffdd24e4';
  $handler->task = 'page';
  $handler->subtask = 'support_after_sales_china_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1b548ebc-5761-4899-a292-562826d0ec78';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_after_sales_china_page__panel_context_8d69349c-6f9f-404d-97c6-909fffdd24e4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-53982a16-40b8-4e03-9170-a1960b0101cc';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_support_pages';
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
  $pane->uuid = '53982a16-40b8-4e03-9170-a1960b0101cc';
  $display->content['new-53982a16-40b8-4e03-9170-a1960b0101cc'] = $pane;
  $display->panels['contentmain'][0] = 'new-53982a16-40b8-4e03-9170-a1960b0101cc';
  $pane = new stdClass();
  $pane->pid = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
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
  $pane->uuid = '9fcef467-58dc-497c-ae4d-adee84139ac1';
  $display->content['new-9fcef467-58dc-497c-ae4d-adee84139ac1'] = $pane;
  $display->panels['sidebar'][0] = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9fcef467-58dc-497c-ae4d-adee84139ac1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_after_sales_china_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_article_listing_pages';
  $page->task = 'page';
  $page->admin_title = 'Support Article Listing Pages';
  $page->admin_description = 'It will show article page for Press Releases, Software Downloads, Safety Notices';
  $page->path = 'support/%category/%article_alias';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'category' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'article_alias' => array(
      'id' => 2,
      'identifier' => 'String 2',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_article_listing_pages__panel_context_0901f3b3-dc2a-4be3-93c6-c5e9df90ddb4';
  $handler->task = 'page';
  $handler->subtask = 'support_article_listing_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_toc';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2ffe58f6-e3b8-4392-81fc-c005d6bbecb9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_article_listing_pages__panel_context_0901f3b3-dc2a-4be3-93c6-c5e9df90ddb4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5719ed3f-8683-4b5a-b851-aa66c695d458';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_title';
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
  $pane->uuid = '5719ed3f-8683-4b5a-b851-aa66c695d458';
  $display->content['new-5719ed3f-8683-4b5a-b851-aa66c695d458'] = $pane;
  $display->panels['contentmain'][0] = 'new-5719ed3f-8683-4b5a-b851-aa66c695d458';
  $pane = new stdClass();
  $pane->pid = 'new-62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_desc';
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
  $pane->uuid = '62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $display->content['new-62f2f829-b823-415a-82d6-4f4dbc06a8e4'] = $pane;
  $display->panels['contentmain'][1] = 'new-62f2f829-b823-415a-82d6-4f4dbc06a8e4';
  $pane = new stdClass();
  $pane->pid = 'new-907f6a7f-680c-4963-be91-ccabd518a999';
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
  $pane->uuid = '907f6a7f-680c-4963-be91-ccabd518a999';
  $display->content['new-907f6a7f-680c-4963-be91-ccabd518a999'] = $pane;
  $display->panels['sidebar'][0] = 'new-907f6a7f-680c-4963-be91-ccabd518a999';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_article_listing_pages'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_manuals';
  $page->task = 'page';
  $page->admin_title = 'Manuals';
  $page->admin_description = '';
  $page->path = 'support/manuals';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_manuals__panel';
  $handler->task = 'page';
  $handler->subtask = 'support_manuals';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->title = '';
  $display->uuid = 'd4cee9ac-a827-4293-91d7-948f997f2104';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_manuals__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-98395b8b-c95b-4c3e-9f89-3282c736f213';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility-ig_manuals_search_form';
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
  $pane->uuid = '98395b8b-c95b-4c3e-9f89-3282c736f213';
  $display->content['new-98395b8b-c95b-4c3e-9f89-3282c736f213'] = $pane;
  $display->panels['contentmain'][0] = 'new-98395b8b-c95b-4c3e-9f89-3282c736f213';
  $pane = new stdClass();
  $pane->pid = 'new-334204e2-2535-4626-afbf-82c21199e4fd';
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
  $pane->uuid = '334204e2-2535-4626-afbf-82c21199e4fd';
  $display->content['new-334204e2-2535-4626-afbf-82c21199e4fd'] = $pane;
  $display->panels['sidebar'][0] = 'new-334204e2-2535-4626-afbf-82c21199e4fd';
  $pane = new stdClass();
  $pane->pid = 'new-af0dd2c2-515f-40f1-8824-6867fed185e8';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility-ig_manuals_search_filter';
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
  $pane->uuid = 'af0dd2c2-515f-40f1-8824-6867fed185e8';
  $display->content['new-af0dd2c2-515f-40f1-8824-6867fed185e8'] = $pane;
  $display->panels['sidebar'][1] = 'new-af0dd2c2-515f-40f1-8824-6867fed185e8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-af0dd2c2-515f-40f1-8824-6867fed185e8';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_manuals'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_page';
  $page->task = 'page';
  $page->admin_title = 'Support Page';
  $page->admin_description = '';
  $page->path = 'support/%url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_page__panel_context_d6136f87-ed22-4b14-8a6a-86bcb569e063';
  $handler->task = 'page';
  $handler->subtask = 'support_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1cb27600-cae3-4b2c-b764-170750c62f6b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_page__panel_context_d6136f87-ed22-4b14-8a6a-86bcb569e063';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ff967d67-6109-46f9-9818-0e602f321f37';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_support_pages';
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
  $pane->uuid = 'ff967d67-6109-46f9-9818-0e602f321f37';
  $display->content['new-ff967d67-6109-46f9-9818-0e602f321f37'] = $pane;
  $display->panels['contentmain'][0] = 'new-ff967d67-6109-46f9-9818-0e602f321f37';
  $pane = new stdClass();
  $pane->pid = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
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
  $pane->uuid = '907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $display->content['new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6'] = $pane;
  $display->panels['sidebar'][0] = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_press_releases';
  $page->task = 'page';
  $page->admin_title = 'support - Press Releases';
  $page->admin_description = '';
  $page->path = 'support/press-releases';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_press_releases__panel_context_eae01552-16a8-4d17-8e20-0f61602c2978';
  $handler->task = 'page';
  $handler->subtask = 'support_press_releases';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F20',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = 'dbed1bcf-be1e-4774-a8f6-3624508c1393';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_press_releases__panel_context_eae01552-16a8-4d17-8e20-0f61602c2978';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-44fed5f9-9919-4347-8ff2-1369d4fc2815';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_support-support_display_title';
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
  $pane->uuid = '44fed5f9-9919-4347-8ff2-1369d4fc2815';
  $display->content['new-44fed5f9-9919-4347-8ff2-1369d4fc2815'] = $pane;
  $display->panels['contentmain'][0] = 'new-44fed5f9-9919-4347-8ff2-1369d4fc2815';
  $pane = new stdClass();
  $pane->pid = 'new-c09437b5-92cd-4268-afea-1d562d20caf2';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_press_release_listings';
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
  $pane->uuid = 'c09437b5-92cd-4268-afea-1d562d20caf2';
  $display->content['new-c09437b5-92cd-4268-afea-1d562d20caf2'] = $pane;
  $display->panels['contentmain'][1] = 'new-c09437b5-92cd-4268-afea-1d562d20caf2';
  $pane = new stdClass();
  $pane->pid = 'new-33c88b21-1067-4da8-9339-e15b7f0c960f';
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
  $pane->uuid = '33c88b21-1067-4da8-9339-e15b7f0c960f';
  $display->content['new-33c88b21-1067-4da8-9339-e15b7f0c960f'] = $pane;
  $display->panels['sidebar'][0] = 'new-33c88b21-1067-4da8-9339-e15b7f0c960f';
  $pane = new stdClass();
  $pane->pid = 'new-075d7a7b-48c6-4ffa-aef0-34c8398fd438';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-k8P5LFBBEWVphfg4jm6AtnaY3XucKMLV';
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
  $pane->uuid = '075d7a7b-48c6-4ffa-aef0-34c8398fd438';
  $display->content['new-075d7a7b-48c6-4ffa-aef0-34c8398fd438'] = $pane;
  $display->panels['sidebar'][1] = 'new-075d7a7b-48c6-4ffa-aef0-34c8398fd438';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_press_releases'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_safety_notices';
  $page->task = 'page';
  $page->admin_title = 'Support - Safety Notices';
  $page->admin_description = '';
  $page->path = 'support/safety-notices';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_safety_notices__panel_context_4ac24c0b-d771-4602-ae4e-5dcff3ffb577';
  $handler->task = 'page';
  $handler->subtask = 'support_safety_notices';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F21',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1bc892f0-1ac6-401c-aad7-9b7ed52e2b69';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_safety_notices__panel_context_4ac24c0b-d771-4602-ae4e-5dcff3ffb577';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-65811e88-2f1f-4443-b3e4-b981da7e4c87';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_support-support_display_title';
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
  $pane->uuid = '65811e88-2f1f-4443-b3e4-b981da7e4c87';
  $display->content['new-65811e88-2f1f-4443-b3e4-b981da7e4c87'] = $pane;
  $display->panels['contentmain'][0] = 'new-65811e88-2f1f-4443-b3e4-b981da7e4c87';
  $pane = new stdClass();
  $pane->pid = 'new-aa519275-9948-4aad-872f-fb62ef3deab8';
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
  $pane->uuid = 'aa519275-9948-4aad-872f-fb62ef3deab8';
  $display->content['new-aa519275-9948-4aad-872f-fb62ef3deab8'] = $pane;
  $display->panels['contentmain'][1] = 'new-aa519275-9948-4aad-872f-fb62ef3deab8';
  $pane = new stdClass();
  $pane->pid = 'new-66a1f431-c5b5-4944-8a59-b636fa8036e4';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_safety_notice_content';
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
  $pane->uuid = '66a1f431-c5b5-4944-8a59-b636fa8036e4';
  $display->content['new-66a1f431-c5b5-4944-8a59-b636fa8036e4'] = $pane;
  $display->panels['contentmain'][2] = 'new-66a1f431-c5b5-4944-8a59-b636fa8036e4';
  $pane = new stdClass();
  $pane->pid = 'new-ad4662d3-d8be-477f-b972-2ccd7f97bb50';
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
  $pane->uuid = 'ad4662d3-d8be-477f-b972-2ccd7f97bb50';
  $display->content['new-ad4662d3-d8be-477f-b972-2ccd7f97bb50'] = $pane;
  $display->panels['sidebar'][0] = 'new-ad4662d3-d8be-477f-b972-2ccd7f97bb50';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_safety_notices'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_software_downloads';
  $page->task = 'page';
  $page->admin_title = 'Support - Software Downloads';
  $page->admin_description = '';
  $page->path = 'support/software-downloads';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_software_downloads__panel_context_c5f88e4c-8b9b-4141-8ab0-d824221fe3ac';
  $handler->task = 'page';
  $handler->subtask = 'support_software_downloads';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'Template-F22',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = 'e528f670-3328-4245-acca-4b40527fa95a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_software_downloads__panel_context_c5f88e4c-8b9b-4141-8ab0-d824221fe3ac';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b3201207-daa2-444d-bbc0-c0434fede772';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_support-support_display_title';
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
  $pane->uuid = 'b3201207-daa2-444d-bbc0-c0434fede772';
  $display->content['new-b3201207-daa2-444d-bbc0-c0434fede772'] = $pane;
  $display->panels['contentmain'][0] = 'new-b3201207-daa2-444d-bbc0-c0434fede772';
  $pane = new stdClass();
  $pane->pid = 'new-1b2b9fee-6fb9-4f82-8d4a-8a0d4dae942a';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '1b2b9fee-6fb9-4f82-8d4a-8a0d4dae942a';
  $display->content['new-1b2b9fee-6fb9-4f82-8d4a-8a0d4dae942a'] = $pane;
  $display->panels['contentmain'][1] = 'new-1b2b9fee-6fb9-4f82-8d4a-8a0d4dae942a';
  $pane = new stdClass();
  $pane->pid = 'new-42978b98-484b-4def-9e89-7b407948070e';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_software_download_listings';
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
  $pane->uuid = '42978b98-484b-4def-9e89-7b407948070e';
  $display->content['new-42978b98-484b-4def-9e89-7b407948070e'] = $pane;
  $display->panels['contentmain'][2] = 'new-42978b98-484b-4def-9e89-7b407948070e';
  $pane = new stdClass();
  $pane->pid = 'new-e9a43a19-a7b6-4fac-929b-d84378f4c1e0';
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
  $pane->uuid = 'e9a43a19-a7b6-4fac-929b-d84378f4c1e0';
  $display->content['new-e9a43a19-a7b6-4fac-929b-d84378f4c1e0'] = $pane;
  $display->panels['sidebar'][0] = 'new-e9a43a19-a7b6-4fac-929b-d84378f4c1e0';
  $pane = new stdClass();
  $pane->pid = 'new-1add5d98-a420-4740-8c74-1b169f94bd0f';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-2IgPmwdqQSGUkGbHDkRBTNj0IbDOOIiT';
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
  $pane->uuid = '1add5d98-a420-4740-8c74-1b169f94bd0f';
  $display->content['new-1add5d98-a420-4740-8c74-1b169f94bd0f'] = $pane;
  $display->panels['sidebar'][1] = 'new-1add5d98-a420-4740-8c74-1b169f94bd0f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_software_downloads'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'support_toc_home';
  $page->task = 'page';
  $page->admin_title = 'Support TOC - home';
  $page->admin_description = '';
  $page->path = 'support';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_support_toc_home__panel';
  $handler->task = 'page';
  $handler->subtask = 'support_toc_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F9',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1cb27600-cae3-4b2c-b764-170750c62f6b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_support_toc_home__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-75d08cee-743a-42fe-aeff-c03f48981beb';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '75d08cee-743a-42fe-aeff-c03f48981beb';
  $display->content['new-75d08cee-743a-42fe-aeff-c03f48981beb'] = $pane;
  $display->panels['contentmain'][0] = 'new-75d08cee-743a-42fe-aeff-c03f48981beb';
  $pane = new stdClass();
  $pane->pid = 'new-8f4b1783-3878-464e-8608-4deb3b8ae998';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '8f4b1783-3878-464e-8608-4deb3b8ae998';
  $display->content['new-8f4b1783-3878-464e-8608-4deb3b8ae998'] = $pane;
  $display->panels['contentmain'][1] = 'new-8f4b1783-3878-464e-8608-4deb3b8ae998';
  $pane = new stdClass();
  $pane->pid = 'new-b6fb9e5b-143a-41cc-a478-0cda8ddf69ac';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'b6fb9e5b-143a-41cc-a478-0cda8ddf69ac';
  $display->content['new-b6fb9e5b-143a-41cc-a478-0cda8ddf69ac'] = $pane;
  $display->panels['contentmain'][2] = 'new-b6fb9e5b-143a-41cc-a478-0cda8ddf69ac';
  $pane = new stdClass();
  $pane->pid = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
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
  $pane->uuid = '907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $display->content['new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6'] = $pane;
  $display->panels['sidebar'][0] = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['support_toc_home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'tax_information';
  $page->task = 'page';
  $page->admin_title = 'Tax Information';
  $page->admin_description = '';
  $page->path = 'tax-information';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_tax_information__panel';
  $handler->task = 'page';
  $handler->subtask = 'tax_information';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '577e6754-0f61-4ae3-9dfb-57beb2c7f734';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_tax_information__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4b6f1c2c-04aa-4a34-9d31-ab953c9a3b86';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_title';
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
  $pane->uuid = '4b6f1c2c-04aa-4a34-9d31-ab953c9a3b86';
  $display->content['new-4b6f1c2c-04aa-4a34-9d31-ab953c9a3b86'] = $pane;
  $display->panels['contentmain'][0] = 'new-4b6f1c2c-04aa-4a34-9d31-ab953c9a3b86';
  $pane = new stdClass();
  $pane->pid = 'new-42e4cccf-f611-485f-b62c-5cbfadf0a270';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_desc';
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
  $pane->uuid = '42e4cccf-f611-485f-b62c-5cbfadf0a270';
  $display->content['new-42e4cccf-f611-485f-b62c-5cbfadf0a270'] = $pane;
  $display->panels['contentmain'][1] = 'new-42e4cccf-f611-485f-b62c-5cbfadf0a270';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4b6f1c2c-04aa-4a34-9d31-ab953c9a3b86';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tax_information'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'test123';
  $page->task = 'page';
  $page->admin_title = 'Test 123';
  $page->admin_description = '';
  $page->path = 'solutions/industry/%mytest';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'mytest' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test123__panel';
  $handler->task = 'page';
  $handler->subtask = 'test123';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'en-us' => 'en-us',
              'default' => 0,
              'en' => 0,
              'cs-cz' => 0,
              'da-dk' => 0,
              'de-de' => 0,
              'de-at' => 0,
              'de-ch' => 0,
              'en-au' => 0,
              'en-ca' => 0,
              'en-gb' => 0,
              'en-id' => 0,
              'en-ie' => 0,
              'en-in' => 0,
              'en-my' => 0,
              'en-ph' => 0,
              'en-sg' => 0,
              'en-th' => 0,
              'en-tt' => 0,
              'en-vn' => 0,
              'es-mx' => 0,
              'es-ar' => 0,
              'es-bo' => 0,
              'es-cl' => 0,
              'es-co' => 0,
              'es-cr' => 0,
              'es-do' => 0,
              'es-ec' => 0,
              'es-gt' => 0,
              'es-pe' => 0,
              'es-sv' => 0,
              'es-uy' => 0,
              'es-ve' => 0,
              'pt-pt' => 0,
              'ro-ro' => 0,
              'ru-ru' => 0,
              'sv-se' => 0,
              'th-th' => 0,
              'tr-tr' => 0,
              'vi-vn' => 0,
              'zh-cn' => 0,
              'zh-tw' => 0,
              'es-es' => 0,
              'fi-fi' => 0,
              'fr-fr' => 0,
              'fr-be' => 0,
              'fr-ca' => 0,
              'fr-ch' => 0,
              'id-id' => 0,
              'it-it' => 0,
              'it-ch' => 0,
              'ja-jp' => 0,
              'ko-kr' => 0,
              'nl-nl' => 0,
              'nl-be' => 0,
              'no-no' => 0,
              'pl-pl' => 0,
              'pt-br' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Test Page';
  $display->uuid = '8fff2e0a-0fa5-4da5-b605-a01f8dd8a7cd';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_test123__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-921da2e1-ae22-4a9c-b798-7e8a57d18959';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Just Testing',
    'body' => '<p>Test 123</p>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '921da2e1-ae22-4a9c-b798-7e8a57d18959';
  $display->content['new-921da2e1-ae22-4a9c-b798-7e8a57d18959'] = $pane;
  $display->panels['middle'][0] = 'new-921da2e1-ae22-4a9c-b798-7e8a57d18959';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-921da2e1-ae22-4a9c-b798-7e8a57d18959';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_test123__panel_context_7faeae35-ca89-4cd0-8c9e-766d3cd76843';
  $handler->task = 'page';
  $handler->subtask = 'test123';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'de-de' => 'de-de',
              'default' => 0,
              'en' => 0,
              'en-us' => 0,
              'cs-cz' => 0,
              'da-dk' => 0,
              'de-at' => 0,
              'de-ch' => 0,
              'en-au' => 0,
              'en-ca' => 0,
              'en-gb' => 0,
              'en-id' => 0,
              'en-ie' => 0,
              'en-in' => 0,
              'en-my' => 0,
              'en-ph' => 0,
              'en-sg' => 0,
              'en-th' => 0,
              'en-tt' => 0,
              'en-vn' => 0,
              'es-mx' => 0,
              'es-ar' => 0,
              'es-bo' => 0,
              'es-cl' => 0,
              'es-co' => 0,
              'es-cr' => 0,
              'es-do' => 0,
              'es-ec' => 0,
              'es-gt' => 0,
              'es-pe' => 0,
              'es-sv' => 0,
              'es-uy' => 0,
              'es-ve' => 0,
              'pt-pt' => 0,
              'ro-ro' => 0,
              'ru-ru' => 0,
              'sv-se' => 0,
              'th-th' => 0,
              'tr-tr' => 0,
              'vi-vn' => 0,
              'zh-cn' => 0,
              'zh-tw' => 0,
              'es-es' => 0,
              'fi-fi' => 0,
              'fr-fr' => 0,
              'fr-be' => 0,
              'fr-ca' => 0,
              'fr-ch' => 0,
              'id-id' => 0,
              'it-it' => 0,
              'it-ch' => 0,
              'ja-jp' => 0,
              'ko-kr' => 0,
              'nl-nl' => 0,
              'nl-be' => 0,
              'no-no' => 0,
              'pl-pl' => 0,
              'pt-br' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'test';
  $display->uuid = '936cb168-2e31-486d-af9b-16541173e5bc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_test123__panel_context_7faeae35-ca89-4cd0-8c9e-766d3cd76843';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['test123'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'thank_you_for_contacting_fluke';
  $page->task = 'page';
  $page->admin_title = 'Thank you for contacting Fluke';
  $page->admin_description = '';
  $page->path = 'thank-you-for-contacting-fluke';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_thank_you_for_contacting_fluke__panel';
  $handler->task = 'page';
  $handler->subtask = 'thank_you_for_contacting_fluke';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3462cf46-1911-4ee4-ae0b-1130d4b46069';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_thank_you_for_contacting_fluke__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $pane->panel = 'contentmain';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => 'A representative will contact you shortly.',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $display->content['new-44727990-3adf-4b07-a9ee-a51a59f4a2fd'] = $pane;
  $display->panels['contentmain'][0] = 'new-44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['thank_you_for_contacting_fluke'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'thank_you_for_contacting_fluke_2';
  $page->task = 'page';
  $page->admin_title = 'Thank you for contacting Fluke 2';
  $page->admin_description = '';
  $page->path = 'thank-you-for-contacting-fluke-2';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_thank_you_for_contacting_fluke_2__panel_context_c9c86728-0491-44df-b5c3-2bcb0c3044c4';
  $handler->task = 'page';
  $handler->subtask = 'thank_you_for_contacting_fluke_2';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'thank-you-for-contacting-fluke',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'thank-you-for-contacting-fluke/*',
          ),
          'context' => 'empty',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3462cf46-1911-4ee4-ae0b-1130d4b46069';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_thank_you_for_contacting_fluke_2__panel_context_c9c86728-0491-44df-b5c3-2bcb0c3044c4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $pane->panel = 'contentmain';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => 'Instructions on how to activate the licensed features will be sent to you by email shortly.',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $display->content['new-44727990-3adf-4b07-a9ee-a51a59f4a2fd'] = $pane;
  $display->panels['contentmain'][0] = 'new-44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['thank_you_for_contacting_fluke_2'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'thank_you_for_registering_your_fluke_product_438ii';
  $page->task = 'page';
  $page->admin_title = 'Thank you for registering your Fluke product - 438II';
  $page->admin_description = '';
  $page->path = 'thank-you-for-registering-your-fluke-product-438II';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_thank_you_for_registering_your_fluke_product_438ii__panel_context_0c95c2a2-782e-41d0-bb82-a2be66922f06';
  $handler->task = 'page';
  $handler->subtask = 'thank_you_for_registering_your_fluke_product_438ii';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3462cf46-1911-4ee4-ae0b-1130d4b46069';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_thank_you_for_registering_your_fluke_product_438ii__panel_context_0c95c2a2-782e-41d0-bb82-a2be66922f06';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $pane->panel = 'contentmain';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => 'Instructions on how to activate the licensed features will be sent to you by email shortly.',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $display->content['new-44727990-3adf-4b07-a9ee-a51a59f4a2fd'] = $pane;
  $display->panels['contentmain'][0] = 'new-44727990-3adf-4b07-a9ee-a51a59f4a2fd';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['thank_you_for_registering_your_fluke_product_438ii'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_library';
  $page->task = 'page';
  $page->admin_title = 'Learn - Library';
  $page->admin_description = '';
  $page->path = 'learn/library';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_library__panel_context_01b44459-73f7-4c41-bed9-54609eb70261';
  $handler->task = 'page';
  $handler->subtask = 'training_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F16',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->title = '';
  $display->uuid = 'c1201d13-7998-45bb-923a-c2a5ad430852';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_library__panel_context_01b44459-73f7-4c41-bed9-54609eb70261';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-17d62cca-d088-4e77-866b-784989d582df';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_support-support_display_title';
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
  $pane->uuid = '17d62cca-d088-4e77-866b-784989d582df';
  $display->content['new-17d62cca-d088-4e77-866b-784989d582df'] = $pane;
  $display->panels['contentmain'][0] = 'new-17d62cca-d088-4e77-866b-784989d582df';
  $pane = new stdClass();
  $pane->pid = 'new-d69f8feb-cc13-4c30-a3d7-27941487094b';
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
  $pane->uuid = 'd69f8feb-cc13-4c30-a3d7-27941487094b';
  $display->content['new-d69f8feb-cc13-4c30-a3d7-27941487094b'] = $pane;
  $display->panels['contentmain'][1] = 'new-d69f8feb-cc13-4c30-a3d7-27941487094b';
  $pane = new stdClass();
  $pane->pid = 'new-c2a910f2-41c1-4735-86ca-11a6cd17d5bd';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_training-training_library_search';
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
  $pane->uuid = 'c2a910f2-41c1-4735-86ca-11a6cd17d5bd';
  $display->content['new-c2a910f2-41c1-4735-86ca-11a6cd17d5bd'] = $pane;
  $display->panels['contentmain'][2] = 'new-c2a910f2-41c1-4735-86ca-11a6cd17d5bd';
  $pane = new stdClass();
  $pane->pid = 'new-5d84a6bd-5a15-4d0b-be21-302aff7f989d';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_training-training_library_content';
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
  $pane->uuid = '5d84a6bd-5a15-4d0b-be21-302aff7f989d';
  $display->content['new-5d84a6bd-5a15-4d0b-be21-302aff7f989d'] = $pane;
  $display->panels['contentmain'][3] = 'new-5d84a6bd-5a15-4d0b-be21-302aff7f989d';
  $pane = new stdClass();
  $pane->pid = 'new-707fc914-4651-4692-b931-0ef1d7fc1b1c';
  $pane->panel = 'header';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_banner';
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
  $pane->uuid = '707fc914-4651-4692-b931-0ef1d7fc1b1c';
  $display->content['new-707fc914-4651-4692-b931-0ef1d7fc1b1c'] = $pane;
  $display->panels['header'][0] = 'new-707fc914-4651-4692-b931-0ef1d7fc1b1c';
  $pane = new stdClass();
  $pane->pid = 'new-48ddeb94-ec75-419d-917a-749a41dd334c';
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
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '48ddeb94-ec75-419d-917a-749a41dd334c';
  $display->content['new-48ddeb94-ec75-419d-917a-749a41dd334c'] = $pane;
  $display->panels['sidebar'][0] = 'new-48ddeb94-ec75-419d-917a-749a41dd334c';
  $pane = new stdClass();
  $pane->pid = 'new-3d7b128c-e8e5-4f28-8916-215da197c1f5';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_training-training_library_filter_form';
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
  $pane->uuid = '3d7b128c-e8e5-4f28-8916-215da197c1f5';
  $display->content['new-3d7b128c-e8e5-4f28-8916-215da197c1f5'] = $pane;
  $display->panels['sidebar'][1] = 'new-3d7b128c-e8e5-4f28-8916-215da197c1f5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-707fc914-4651-4692-b931-0ef1d7fc1b1c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_library'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_page';
  $page->task = 'page';
  $page->admin_title = 'Learn - Article';
  $page->admin_description = '';
  $page->path = 'learn/%url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_page__panel_context_a48cf31b-aa20-421d-a2ae-befdf9ddc519';
  $handler->task = 'page';
  $handler->subtask = 'training_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1cb27600-cae3-4b2c-b764-170750c62f6b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_page__panel_context_a48cf31b-aa20-421d-a2ae-befdf9ddc519';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ff967d67-6109-46f9-9818-0e602f321f37';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-article_support_pages';
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
  $pane->uuid = 'ff967d67-6109-46f9-9818-0e602f321f37';
  $display->content['new-ff967d67-6109-46f9-9818-0e602f321f37'] = $pane;
  $display->panels['contentmain'][0] = 'new-ff967d67-6109-46f9-9818-0e602f321f37';
  $pane = new stdClass();
  $pane->pid = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
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
  $pane->uuid = '907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $display->content['new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6'] = $pane;
  $display->panels['sidebar'][0] = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-907bd4d6-45f5-4e8f-8b27-c380ff5535d6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_page'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_article_pages';
  $page->task = 'page';
  $page->admin_title = 'Training TOC - Article Pages';
  $page->admin_description = '';
  $page->path = 'training/%url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_article_pages__panel_context_ee591632-b81e-4198-b5e6-61bd0b429742';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_article_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-xxx',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '92e789a1-72cf-4378-ba0b-09c882fd76e6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_article_pages__panel_context_ee591632-b81e-4198-b5e6-61bd0b429742';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a9d9cefe-8db4-4f0e-a8fd-1b23e76a9c7e';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'support_page_view-training_pages_desc';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a9d9cefe-8db4-4f0e-a8fd-1b23e76a9c7e';
  $display->content['new-a9d9cefe-8db4-4f0e-a8fd-1b23e76a9c7e'] = $pane;
  $display->panels['contentmain'][0] = 'new-a9d9cefe-8db4-4f0e-a8fd-1b23e76a9c7e';
  $pane = new stdClass();
  $pane->pid = 'new-04c522d5-575c-4a47-b2a7-261bf71febf9';
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
  $pane->uuid = '04c522d5-575c-4a47-b2a7-261bf71febf9';
  $display->content['new-04c522d5-575c-4a47-b2a7-261bf71febf9'] = $pane;
  $display->panels['sidebar'][0] = 'new-04c522d5-575c-4a47-b2a7-261bf71febf9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_article_pages'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_educators_pages';
  $page->task = 'page';
  $page->admin_title = 'Learn TOC page - student discounts and resources - article page';
  $page->admin_description = '';
  $page->path = 'learn/student-discounts-and-resources/%url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_educators_pages__panel_context_ae7c0ade-44b1-4ce7-972a-c36156154650';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_educators_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = 'eee7569a-d79c-4cca-a84e-563dc1fe227c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_educators_pages__panel_context_ae7c0ade-44b1-4ce7-972a-c36156154650';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d6589328-4623-4b93-a2c6-0796a5d2f29d';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_title';
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
  $pane->uuid = 'd6589328-4623-4b93-a2c6-0796a5d2f29d';
  $display->content['new-d6589328-4623-4b93-a2c6-0796a5d2f29d'] = $pane;
  $display->panels['contentmain'][0] = 'new-d6589328-4623-4b93-a2c6-0796a5d2f29d';
  $pane = new stdClass();
  $pane->pid = 'new-53f8e7b2-7f01-4731-8b1d-1ca740787eda';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_desc';
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
  $pane->uuid = '53f8e7b2-7f01-4731-8b1d-1ca740787eda';
  $display->content['new-53f8e7b2-7f01-4731-8b1d-1ca740787eda'] = $pane;
  $display->panels['contentmain'][1] = 'new-53f8e7b2-7f01-4731-8b1d-1ca740787eda';
  $pane = new stdClass();
  $pane->pid = 'new-ed9e0d13-68fa-4d75-a93c-3cdcfc79f6da';
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
  $pane->uuid = 'ed9e0d13-68fa-4d75-a93c-3cdcfc79f6da';
  $display->content['new-ed9e0d13-68fa-4d75-a93c-3cdcfc79f6da'] = $pane;
  $display->panels['sidebar'][0] = 'new-ed9e0d13-68fa-4d75-a93c-3cdcfc79f6da';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_educators_pages'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_online_courses';
  $page->task = 'page';
  $page->admin_title = 'Learn TOC - Online Courses';
  $page->admin_description = '';
  $page->path = 'learn/online-courses';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_online_courses__panel';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_online_courses';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F9',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->title = '';
  $display->uuid = '8d880cdd-de6c-4945-9531-51b5b31634a0';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_online_courses__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7ce931ef-5b1f-4c6a-b28f-d7f9a0c6e4c0';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '7ce931ef-5b1f-4c6a-b28f-d7f9a0c6e4c0';
  $display->content['new-7ce931ef-5b1f-4c6a-b28f-d7f9a0c6e4c0'] = $pane;
  $display->panels['contentmain'][0] = 'new-7ce931ef-5b1f-4c6a-b28f-d7f9a0c6e4c0';
  $pane = new stdClass();
  $pane->pid = 'new-337e1f70-e6c4-41f8-ac17-147df8f73284';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '337e1f70-e6c4-41f8-ac17-147df8f73284';
  $display->content['new-337e1f70-e6c4-41f8-ac17-147df8f73284'] = $pane;
  $display->panels['contentmain'][1] = 'new-337e1f70-e6c4-41f8-ac17-147df8f73284';
  $pane = new stdClass();
  $pane->pid = 'new-c352be21-2cd6-43f6-8479-be6ebb290fea';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'c352be21-2cd6-43f6-8479-be6ebb290fea';
  $display->content['new-c352be21-2cd6-43f6-8479-be6ebb290fea'] = $pane;
  $display->panels['contentmain'][2] = 'new-c352be21-2cd6-43f6-8479-be6ebb290fea';
  $pane = new stdClass();
  $pane->pid = 'new-3230a38b-3e1e-4155-ba9e-6c5ff3f580fc';
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
  $pane->uuid = '3230a38b-3e1e-4155-ba9e-6c5ff3f580fc';
  $display->content['new-3230a38b-3e1e-4155-ba9e-6c5ff3f580fc'] = $pane;
  $display->panels['sidebar'][0] = 'new-3230a38b-3e1e-4155-ba9e-6c5ff3f580fc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_online_courses'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_online_courses_pages';
  $page->task = 'page';
  $page->admin_title = 'Learn TOC - Online Courses - Articles';
  $page->admin_description = '';
  $page->path = 'learn/online-courses/%url_title';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'url_title' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_online_courses_pages__panel';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_online_courses_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F14',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->title = '';
  $display->uuid = 'ea415412-1b4f-4a24-beb0-cc510d75435e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_online_courses_pages__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7d958614-a499-4603-88b6-3a7a1654d28e';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_title';
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
  $pane->uuid = '7d958614-a499-4603-88b6-3a7a1654d28e';
  $display->content['new-7d958614-a499-4603-88b6-3a7a1654d28e'] = $pane;
  $display->panels['contentmain'][0] = 'new-7d958614-a499-4603-88b6-3a7a1654d28e';
  $pane = new stdClass();
  $pane->pid = 'new-6ef165ad-4f33-45d3-9b57-67737645883a';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_desc';
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
  $pane->uuid = '6ef165ad-4f33-45d3-9b57-67737645883a';
  $display->content['new-6ef165ad-4f33-45d3-9b57-67737645883a'] = $pane;
  $display->panels['contentmain'][1] = 'new-6ef165ad-4f33-45d3-9b57-67737645883a';
  $pane = new stdClass();
  $pane->pid = 'new-d9fe368f-464f-4c35-8452-fd09ce35dd9c';
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
  $pane->uuid = 'd9fe368f-464f-4c35-8452-fd09ce35dd9c';
  $display->content['new-d9fe368f-464f-4c35-8452-fd09ce35dd9c'] = $pane;
  $display->panels['sidebar'][0] = 'new-d9fe368f-464f-4c35-8452-fd09ce35dd9c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_online_courses_pages'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_all_training_library_articles';
  $page->task = 'page';
  $page->admin_title = 'Training TOC page - All training library Articles';
  $page->admin_description = '';
  $page->path = '/training/training-library/%article_alias';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'article_alias' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_all_training_library_articles__panel_context_45caeb45-f9df-4d3c-983d-2c0e2955a7db';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_all_training_library_articles';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e3f5072d-a4ad-4f5e-9d90-7877d8986621';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_all_training_library_articles__panel_context_45caeb45-f9df-4d3c-983d-2c0e2955a7db';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f7fe5e51-efdc-43e0-8877-41e4028149db';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_web_card_popup_article';
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
  $pane->uuid = 'f7fe5e51-efdc-43e0-8877-41e4028149db';
  $display->content['new-f7fe5e51-efdc-43e0-8877-41e4028149db'] = $pane;
  $display->panels['contentmain'][0] = 'new-f7fe5e51-efdc-43e0-8877-41e4028149db';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f7fe5e51-efdc-43e0-8877-41e4028149db';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_all_training_library_articles'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_electrical_safety';
  $page->task = 'page';
  $page->admin_title = 'Training TOC page - Electrical Safety';
  $page->admin_description = '';
  $page->path = 'training/electrical-safety';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_electrical_safety__panel_context_646da026-1a44-4594-a4fd-a8505d8514f4';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_electrical_safety';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F9',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '0477a8fe-83c7-4baa-9c1b-4576f781f886';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_electrical_safety__panel_context_646da026-1a44-4594-a4fd-a8505d8514f4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a834597d-9418-4f0e-8563-02ec22efb156';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = 'a834597d-9418-4f0e-8563-02ec22efb156';
  $display->content['new-a834597d-9418-4f0e-8563-02ec22efb156'] = $pane;
  $display->panels['contentmain'][0] = 'new-a834597d-9418-4f0e-8563-02ec22efb156';
  $pane = new stdClass();
  $pane->pid = 'new-eddf6dbd-d3ce-40aa-821c-f6bb3735a5fe';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = 'eddf6dbd-d3ce-40aa-821c-f6bb3735a5fe';
  $display->content['new-eddf6dbd-d3ce-40aa-821c-f6bb3735a5fe'] = $pane;
  $display->panels['contentmain'][1] = 'new-eddf6dbd-d3ce-40aa-821c-f6bb3735a5fe';
  $pane = new stdClass();
  $pane->pid = 'new-1e0f7c01-e39f-44ff-b02a-596216e8162c';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = '1e0f7c01-e39f-44ff-b02a-596216e8162c';
  $display->content['new-1e0f7c01-e39f-44ff-b02a-596216e8162c'] = $pane;
  $display->panels['contentmain'][2] = 'new-1e0f7c01-e39f-44ff-b02a-596216e8162c';
  $pane = new stdClass();
  $pane->pid = 'new-45d9156c-a914-47ee-8105-9b0802088709';
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
  $pane->uuid = '45d9156c-a914-47ee-8105-9b0802088709';
  $display->content['new-45d9156c-a914-47ee-8105-9b0802088709'] = $pane;
  $display->panels['sidebar'][0] = 'new-45d9156c-a914-47ee-8105-9b0802088709';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-45d9156c-a914-47ee-8105-9b0802088709';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_electrical_safety'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_for_educators';
  $page->task = 'page';
  $page->admin_title = 'Learn TOC - Student Discounts';
  $page->admin_description = '';
  $page->path = 'learn/student-discounts-and-resources';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_for_educators__panel';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_for_educators';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F9',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = 'e012a030-8055-4b49-aa3f-c131e9672730';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_for_educators__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e7488e8c-3732-49b0-b456-b77b78d836ab';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = 'e7488e8c-3732-49b0-b456-b77b78d836ab';
  $display->content['new-e7488e8c-3732-49b0-b456-b77b78d836ab'] = $pane;
  $display->panels['contentmain'][0] = 'new-e7488e8c-3732-49b0-b456-b77b78d836ab';
  $pane = new stdClass();
  $pane->pid = 'new-71be7218-5327-472b-9058-9a8d3b59b6e6';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '71be7218-5327-472b-9058-9a8d3b59b6e6';
  $display->content['new-71be7218-5327-472b-9058-9a8d3b59b6e6'] = $pane;
  $display->panels['contentmain'][1] = 'new-71be7218-5327-472b-9058-9a8d3b59b6e6';
  $pane = new stdClass();
  $pane->pid = 'new-37461294-f11b-47ac-9865-59149543e618';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = '37461294-f11b-47ac-9865-59149543e618';
  $display->content['new-37461294-f11b-47ac-9865-59149543e618'] = $pane;
  $display->panels['contentmain'][2] = 'new-37461294-f11b-47ac-9865-59149543e618';
  $pane = new stdClass();
  $pane->pid = 'new-cc734549-8302-422b-b9b8-f14c209a6058';
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
  $pane->uuid = 'cc734549-8302-422b-b9b8-f14c209a6058';
  $display->content['new-cc734549-8302-422b-b9b8-f14c209a6058'] = $pane;
  $display->panels['sidebar'][0] = 'new-cc734549-8302-422b-b9b8-f14c209a6058';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_for_educators'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_home';
  $page->task = 'page';
  $page->admin_title = 'Training TOC page - home';
  $page->admin_description = '';
  $page->path = 'training';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_home__panel';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F9',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = 'b70ab2dd-8dad-48a0-a3ba-6c0663283c28';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_home__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-efc28d51-62bb-4b3d-9810-dcde33b92144';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = 'efc28d51-62bb-4b3d-9810-dcde33b92144';
  $display->content['new-efc28d51-62bb-4b3d-9810-dcde33b92144'] = $pane;
  $display->panels['contentmain'][0] = 'new-efc28d51-62bb-4b3d-9810-dcde33b92144';
  $pane = new stdClass();
  $pane->pid = 'new-8a1f2faa-ee67-47b1-902b-7e8c1dcfea5a';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '8a1f2faa-ee67-47b1-902b-7e8c1dcfea5a';
  $display->content['new-8a1f2faa-ee67-47b1-902b-7e8c1dcfea5a'] = $pane;
  $display->panels['contentmain'][1] = 'new-8a1f2faa-ee67-47b1-902b-7e8c1dcfea5a';
  $pane = new stdClass();
  $pane->pid = 'new-b2bd9465-37d8-4534-a028-f21e8a6e90db';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'b2bd9465-37d8-4534-a028-f21e8a6e90db';
  $display->content['new-b2bd9465-37d8-4534-a028-f21e8a6e90db'] = $pane;
  $display->panels['contentmain'][2] = 'new-b2bd9465-37d8-4534-a028-f21e8a6e90db';
  $pane = new stdClass();
  $pane->pid = 'new-3ee49b9d-00d3-4216-b4b5-0ed2c9334493';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_taxo_url_builder_product';
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
  $pane->uuid = '3ee49b9d-00d3-4216-b4b5-0ed2c9334493';
  $display->content['new-3ee49b9d-00d3-4216-b4b5-0ed2c9334493'] = $pane;
  $display->panels['footer'][0] = 'new-3ee49b9d-00d3-4216-b4b5-0ed2c9334493';
  $pane = new stdClass();
  $pane->pid = 'new-53a87945-a7c5-4f99-a3ca-9e8111c3b74f';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_taxo_url_builder_resources';
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
  $pane->uuid = '53a87945-a7c5-4f99-a3ca-9e8111c3b74f';
  $display->content['new-53a87945-a7c5-4f99-a3ca-9e8111c3b74f'] = $pane;
  $display->panels['footer'][1] = 'new-53a87945-a7c5-4f99-a3ca-9e8111c3b74f';
  $pane = new stdClass();
  $pane->pid = 'new-63b4fdd8-f92a-44e8-b5ed-4e1a68684e7d';
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
  $pane->uuid = '63b4fdd8-f92a-44e8-b5ed-4e1a68684e7d';
  $display->content['new-63b4fdd8-f92a-44e8-b5ed-4e1a68684e7d'] = $pane;
  $display->panels['sidebar'][0] = 'new-63b4fdd8-f92a-44e8-b5ed-4e1a68684e7d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_specific_electrical_safety_article';
  $page->task = 'page';
  $page->admin_title = 'Training TOC page - Specific Electrical Safety Article';
  $page->admin_description = '';
  $page->path = 'training/electrical-safety/%electrical';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'electrical' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_specific_electrical_safety_article__panel_context_f903f757-5502-4b65-aded-5b12954e5c76';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_specific_electrical_safety_article';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F10',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '0477a8fe-83c7-4baa-9c1b-4576f781f886';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_specific_electrical_safety_article__panel_context_f903f757-5502-4b65-aded-5b12954e5c76';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2d444a27-367b-461d-a99a-5214e2250b17';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '2d444a27-367b-461d-a99a-5214e2250b17';
  $display->content['new-2d444a27-367b-461d-a99a-5214e2250b17'] = $pane;
  $display->panels['contentmain'][0] = 'new-2d444a27-367b-461d-a99a-5214e2250b17';
  $pane = new stdClass();
  $pane->pid = 'new-c0d1c1c4-04e6-48f5-8801-287c48115ba3';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = 'c0d1c1c4-04e6-48f5-8801-287c48115ba3';
  $display->content['new-c0d1c1c4-04e6-48f5-8801-287c48115ba3'] = $pane;
  $display->panels['contentmain'][1] = 'new-c0d1c1c4-04e6-48f5-8801-287c48115ba3';
  $pane = new stdClass();
  $pane->pid = 'new-bf817c2b-02c7-42bc-9b5f-19309183fabb';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'bf817c2b-02c7-42bc-9b5f-19309183fabb';
  $display->content['new-bf817c2b-02c7-42bc-9b5f-19309183fabb'] = $pane;
  $display->panels['contentmain'][2] = 'new-bf817c2b-02c7-42bc-9b5f-19309183fabb';
  $pane = new stdClass();
  $pane->pid = 'new-ef6167b9-f899-49d3-8b61-609512c92498';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_url_products_solr';
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
  $pane->uuid = 'ef6167b9-f899-49d3-8b61-609512c92498';
  $display->content['new-ef6167b9-f899-49d3-8b61-609512c92498'] = $pane;
  $display->panels['footer'][0] = 'new-ef6167b9-f899-49d3-8b61-609512c92498';
  $pane = new stdClass();
  $pane->pid = 'new-e3f993d8-5a4d-43ad-b083-27a929435c64';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_url_resources_solr';
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
  $pane->uuid = 'e3f993d8-5a4d-43ad-b083-27a929435c64';
  $display->content['new-e3f993d8-5a4d-43ad-b083-27a929435c64'] = $pane;
  $display->panels['footer'][1] = 'new-e3f993d8-5a4d-43ad-b083-27a929435c64';
  $pane = new stdClass();
  $pane->pid = 'new-56f816af-e301-4f87-8111-748f3afee13b';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_taxo_url_builder_product';
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
  $pane->uuid = '56f816af-e301-4f87-8111-748f3afee13b';
  $display->content['new-56f816af-e301-4f87-8111-748f3afee13b'] = $pane;
  $display->panels['footer'][2] = 'new-56f816af-e301-4f87-8111-748f3afee13b';
  $pane = new stdClass();
  $pane->pid = 'new-648155d8-4e4f-4c3f-a16b-9930fba86bab';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_taxo_url_builder_resources';
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
  $pane->uuid = '648155d8-4e4f-4c3f-a16b-9930fba86bab';
  $display->content['new-648155d8-4e4f-4c3f-a16b-9930fba86bab'] = $pane;
  $display->panels['footer'][3] = 'new-648155d8-4e4f-4c3f-a16b-9930fba86bab';
  $pane = new stdClass();
  $pane->pid = 'new-45d9156c-a914-47ee-8105-9b0802088709';
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
  $pane->uuid = '45d9156c-a914-47ee-8105-9b0802088709';
  $display->content['new-45d9156c-a914-47ee-8105-9b0802088709'] = $pane;
  $display->panels['sidebar'][0] = 'new-45d9156c-a914-47ee-8105-9b0802088709';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-45d9156c-a914-47ee-8105-9b0802088709';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_specific_electrical_safety_article'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_specific_electrical_safety_article_web_card';
  $page->task = 'page';
  $page->admin_title = 'Learn TOC page - Best Practices - category - article';
  $page->admin_description = '';
  $page->path = 'learn/best-practices/%category/%article_alias';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'category' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'article_alias' => array(
      'id' => 2,
      'identifier' => 'String 2',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_specific_electrical_safety_article_web_card__panel_context_5a488956-40e9-42f4-91e9-d4d130e2d0d8';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_specific_electrical_safety_article_web_card';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F11',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a376a195-13a4-4f40-9f1b-64f26c996886';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_specific_electrical_safety_article_web_card__panel_context_5a488956-40e9-42f4-91e9-d4d130e2d0d8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8bbf6f79-4049-4897-a499-7981e68ebcb0';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_web_card_popup_article';
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
  $pane->uuid = '8bbf6f79-4049-4897-a499-7981e68ebcb0';
  $display->content['new-8bbf6f79-4049-4897-a499-7981e68ebcb0'] = $pane;
  $display->panels['contentmain'][0] = 'new-8bbf6f79-4049-4897-a499-7981e68ebcb0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8bbf6f79-4049-4897-a499-7981e68ebcb0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_specific_electrical_safety_article_web_card'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_specific_t_m_basics_article_web_card';
  $page->task = 'page';
  $page->admin_title = 'Training TOC page - Specific  T & M basics Article web card';
  $page->admin_description = '';
  $page->path = 'training/test-and-measurement-basics/%category/%sub_category/%article_alias';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'category' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'sub_category' => array(
      'id' => 2,
      'identifier' => 'String 2',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'article_alias' => array(
      'id' => 3,
      'identifier' => 'String 3',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_specific_t_m_basics_article_web_card__panel_context_717fd1b5-7686-4909-b184-c45e6392d8cc';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_specific_t_m_basics_article_web_card';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F11',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_darwin';
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '614ebbac-2a92-4a9f-95e4-5c416738999d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_specific_t_m_basics_article_web_card__panel_context_717fd1b5-7686-4909-b184-c45e6392d8cc';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-49dd96bb-fa39-447e-91e0-4719c5d4544a';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_solr_web_card_popup_article';
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
  $pane->uuid = '49dd96bb-fa39-447e-91e0-4719c5d4544a';
  $display->content['new-49dd96bb-fa39-447e-91e0-4719c5d4544a'] = $pane;
  $display->panels['contentmain'][0] = 'new-49dd96bb-fa39-447e-91e0-4719c5d4544a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-49dd96bb-fa39-447e-91e0-4719c5d4544a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_specific_t_m_basics_article_web_card'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_specific_training';
  $page->task = 'page';
  $page->admin_title = 'Training TOC page - Specific Training';
  $page->admin_description = '';
  $page->path = 'training/test-and-measurement-basics/%basics';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'basics' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 1,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_specific_training__panel_context_e3296b66-bae8-4362-9fe1-fc85b9059086';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_specific_training';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F10',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
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
  $display->title = '';
  $display->uuid = '0e7420d6-2cf2-4dfc-bf06-c3cbe37a5a17';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_specific_training__panel_context_e3296b66-bae8-4362-9fe1-fc85b9059086';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f60c2a36-1e82-4732-9586-7c89a88c143d';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = 'f60c2a36-1e82-4732-9586-7c89a88c143d';
  $display->content['new-f60c2a36-1e82-4732-9586-7c89a88c143d'] = $pane;
  $display->panels['contentmain'][0] = 'new-f60c2a36-1e82-4732-9586-7c89a88c143d';
  $pane = new stdClass();
  $pane->pid = 'new-12387ff6-5968-4a0f-9c85-c227e06f0503';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '12387ff6-5968-4a0f-9c85-c227e06f0503';
  $display->content['new-12387ff6-5968-4a0f-9c85-c227e06f0503'] = $pane;
  $display->panels['contentmain'][1] = 'new-12387ff6-5968-4a0f-9c85-c227e06f0503';
  $pane = new stdClass();
  $pane->pid = 'new-c584c35d-f6ef-409f-9386-6f5a651b5d74';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = 'c584c35d-f6ef-409f-9386-6f5a651b5d74';
  $display->content['new-c584c35d-f6ef-409f-9386-6f5a651b5d74'] = $pane;
  $display->panels['contentmain'][2] = 'new-c584c35d-f6ef-409f-9386-6f5a651b5d74';
  $pane = new stdClass();
  $pane->pid = 'new-1a444aec-7e73-452d-bb13-d6086f406f46';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1a444aec-7e73-452d-bb13-d6086f406f46';
  $display->content['new-1a444aec-7e73-452d-bb13-d6086f406f46'] = $pane;
  $display->panels['footer'][0] = 'new-1a444aec-7e73-452d-bb13-d6086f406f46';
  $pane = new stdClass();
  $pane->pid = 'new-6d93f43b-6fe9-4497-8152-0e175911c2c9';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6d93f43b-6fe9-4497-8152-0e175911c2c9';
  $display->content['new-6d93f43b-6fe9-4497-8152-0e175911c2c9'] = $pane;
  $display->panels['footer'][1] = 'new-6d93f43b-6fe9-4497-8152-0e175911c2c9';
  $pane = new stdClass();
  $pane->pid = 'new-79182a65-6bd0-4e11-a81b-733c79557188';
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
  $pane->uuid = '79182a65-6bd0-4e11-a81b-733c79557188';
  $display->content['new-79182a65-6bd0-4e11-a81b-733c79557188'] = $pane;
  $display->panels['sidebar'][0] = 'new-79182a65-6bd0-4e11-a81b-733c79557188';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-79182a65-6bd0-4e11-a81b-733c79557188';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_specific_training'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_toc_page_t_m_basics';
  $page->task = 'page';
  $page->admin_title = 'Training TOC page - T & M basics';
  $page->admin_description = '';
  $page->path = 'training/test-and-measurement-basics';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_training_toc_page_t_m_basics__panel';
  $handler->task = 'page';
  $handler->subtask = 'training_toc_page_t_m_basics';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'template-F9',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '0477a8fe-83c7-4baa-9c1b-4576f781f886';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_toc_page_t_m_basics__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-79a94597-6d18-496f-b44f-bea0ae4b003e';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_h1_solr';
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
  $pane->uuid = '79a94597-6d18-496f-b44f-bea0ae4b003e';
  $display->content['new-79a94597-6d18-496f-b44f-bea0ae4b003e'] = $pane;
  $display->panels['contentmain'][0] = 'new-79a94597-6d18-496f-b44f-bea0ae4b003e';
  $pane = new stdClass();
  $pane->pid = 'new-3659383e-378d-4d20-8c79-d63640adb1cb';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_desc_solr';
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
  $pane->uuid = '3659383e-378d-4d20-8c79-d63640adb1cb';
  $display->content['new-3659383e-378d-4d20-8c79-d63640adb1cb'] = $pane;
  $display->panels['contentmain'][1] = 'new-3659383e-378d-4d20-8c79-d63640adb1cb';
  $pane = new stdClass();
  $pane->pid = 'new-9ffeab52-5bec-44f5-b328-056d475985ce';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing_solr';
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
  $pane->uuid = '9ffeab52-5bec-44f5-b328-056d475985ce';
  $display->content['new-9ffeab52-5bec-44f5-b328-056d475985ce'] = $pane;
  $display->panels['contentmain'][2] = 'new-9ffeab52-5bec-44f5-b328-056d475985ce';
  $pane = new stdClass();
  $pane->pid = 'new-9f362fd7-0c5a-46cd-aeed-b1dbb6e2e46e';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_taxo_url_builder_product';
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
  $pane->uuid = '9f362fd7-0c5a-46cd-aeed-b1dbb6e2e46e';
  $display->content['new-9f362fd7-0c5a-46cd-aeed-b1dbb6e2e46e'] = $pane;
  $display->panels['footer'][0] = 'new-9f362fd7-0c5a-46cd-aeed-b1dbb6e2e46e';
  $pane = new stdClass();
  $pane->pid = 'new-1ce32afe-e1f3-4718-a659-4407af7fa5a2';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_taxo_url_builder_resources';
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
  $pane->uuid = '1ce32afe-e1f3-4718-a659-4407af7fa5a2';
  $display->content['new-1ce32afe-e1f3-4718-a659-4407af7fa5a2'] = $pane;
  $display->panels['footer'][1] = 'new-1ce32afe-e1f3-4718-a659-4407af7fa5a2';
  $pane = new stdClass();
  $pane->pid = 'new-45d9156c-a914-47ee-8105-9b0802088709';
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
  $pane->uuid = '45d9156c-a914-47ee-8105-9b0802088709';
  $display->content['new-45d9156c-a914-47ee-8105-9b0802088709'] = $pane;
  $display->panels['sidebar'][0] = 'new-45d9156c-a914-47ee-8105-9b0802088709';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-45d9156c-a914-47ee-8105-9b0802088709';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_toc_page_t_m_basics'] = $page;

  return $pages;

}
