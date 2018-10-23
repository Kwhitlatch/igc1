<?php
/**
 * @file
 * misc_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function misc_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'home';
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
  $handler->name = 'page_homepage__panel_context_bc227caf-969b-406c-afaa-786afbd0ba24';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Primary',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => 'Fluke test and measurement tools are the most trusted tools in the world! Digital multimeters, clamp meters, thermal imagers for troubleshooting and industrial applications.',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flukestrap_ryan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '14400',
    ),
  );
  $display->title = 'Fluke test and measurement tools';
  $display->uuid = 'fcb48813-4d72-4b22-b2c9-a0a8adee9b2b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_homepage__panel_context_bc227caf-969b-406c-afaa-786afbd0ba24';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-43c1e2fe-a358-4673-b22c-94d192d0b06c';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'slideshow-panel_pane_3';
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
  $pane->uuid = '43c1e2fe-a358-4673-b22c-94d192d0b06c';
  $display->content['new-43c1e2fe-a358-4673-b22c-94d192d0b06c'] = $pane;
  $display->panels['contentmain'][0] = 'new-43c1e2fe-a358-4673-b22c-94d192d0b06c';
  $pane = new stdClass();
  $pane->pid = 'new-de13af68-e481-408d-bf9a-5e841f4201b7';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'menu-secondary-navigation';
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
  $pane->uuid = 'de13af68-e481-408d-bf9a-5e841f4201b7';
  $display->content['new-de13af68-e481-408d-bf9a-5e841f4201b7'] = $pane;
  $display->panels['contentmain'][1] = 'new-de13af68-e481-408d-bf9a-5e841f4201b7';
  $pane = new stdClass();
  $pane->pid = 'new-7790d427-ee15-4e91-9471-6af00881e7d1';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-homepage_featured_articles';
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
  $pane->uuid = '7790d427-ee15-4e91-9471-6af00881e7d1';
  $display->content['new-7790d427-ee15-4e91-9471-6af00881e7d1'] = $pane;
  $display->panels['contentmain'][2] = 'new-7790d427-ee15-4e91-9471-6af00881e7d1';
  $pane = new stdClass();
  $pane->pid = 'new-c8c6b0a9-c951-4f03-bb94-39dff9959435';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility-homepage_latest_news';
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
  $pane->uuid = 'c8c6b0a9-c951-4f03-bb94-39dff9959435';
  $display->content['new-c8c6b0a9-c951-4f03-bb94-39dff9959435'] = $pane;
  $display->panels['contentmain'][3] = 'new-c8c6b0a9-c951-4f03-bb94-39dff9959435';
  $pane = new stdClass();
  $pane->pid = 'new-9328fbc2-1306-43d3-acd4-c8bcc246a27f';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility-homepage_alerts';
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
  $pane->uuid = '9328fbc2-1306-43d3-acd4-c8bcc246a27f';
  $display->content['new-9328fbc2-1306-43d3-acd4-c8bcc246a27f'] = $pane;
  $display->panels['contentmain'][4] = 'new-9328fbc2-1306-43d3-acd4-c8bcc246a27f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solutions_toc_about';
  $page->task = 'page';
  $page->admin_title = 'Solutions TOC - about';
  $page->admin_description = '';
  $page->path = 'support/about';
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
  $handler->name = 'page_solutions_toc_about__panel';
  $handler->task = 'page';
  $handler->subtask = 'solutions_toc_about';
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
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '1b548ebc-5761-4899-a292-562826d0ec78';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_solutions_toc_about__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c87da094-df12-4e1a-9fb7-2230b2e1b5d2';
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
  $pane->uuid = 'c87da094-df12-4e1a-9fb7-2230b2e1b5d2';
  $display->content['new-c87da094-df12-4e1a-9fb7-2230b2e1b5d2'] = $pane;
  $display->panels['contentmain'][0] = 'new-c87da094-df12-4e1a-9fb7-2230b2e1b5d2';
  $pane = new stdClass();
  $pane->pid = 'new-3889490c-ef4c-4ead-aa9c-2b0b562b598c';
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
  $pane->uuid = '3889490c-ef4c-4ead-aa9c-2b0b562b598c';
  $display->content['new-3889490c-ef4c-4ead-aa9c-2b0b562b598c'] = $pane;
  $display->panels['contentmain'][1] = 'new-3889490c-ef4c-4ead-aa9c-2b0b562b598c';
  $pane = new stdClass();
  $pane->pid = 'new-1f191129-2f5d-490c-a580-6424c9e37d2f';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-articles_toc_category_listing';
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
  $pane->uuid = '1f191129-2f5d-490c-a580-6424c9e37d2f';
  $display->content['new-1f191129-2f5d-490c-a580-6424c9e37d2f'] = $pane;
  $display->panels['contentmain'][2] = 'new-1f191129-2f5d-490c-a580-6424c9e37d2f';
  $pane = new stdClass();
  $pane->pid = 'new-920673dd-b3f0-4bb7-b3ec-4ec545f29a2c';
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
  $pane->uuid = '920673dd-b3f0-4bb7-b3ec-4ec545f29a2c';
  $display->content['new-920673dd-b3f0-4bb7-b3ec-4ec545f29a2c'] = $pane;
  $display->panels['header'][0] = 'new-920673dd-b3f0-4bb7-b3ec-4ec545f29a2c';
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
  $pages['solutions_toc_about'] = $page;

  return $pages;

}
