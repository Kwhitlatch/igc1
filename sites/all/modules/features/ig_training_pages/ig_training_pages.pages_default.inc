<?php
/**
 * @file
 * ig_training_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ig_training_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'event';
  $page->task = 'page';
  $page->admin_title = 'Tradeshows & Seminars';
  $page->admin_description = '';
  $page->path = 'training/tradeshows-and-seminars';
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
  $handler->name = 'page_event__panel_context_37e1adb1-b581-45da-88a2-dd13ae2993d7';
  $handler->task = 'page';
  $handler->subtask = 'event';
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
      'top' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array(
    'method' => 'page',
    'settings' => array(
      'lifetime' => '86400',
    ),
  );
  $display->title = '';
  $display->uuid = '64ba3d94-89c3-4eb0-83ca-6d04ab1d8882';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_event__panel_context_37e1adb1-b581-45da-88a2-dd13ae2993d7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3059668b-df20-48fe-8f05-24b959fc5028';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_event-tradeshows_and_seminars_title_description';
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
  $pane->uuid = '3059668b-df20-48fe-8f05-24b959fc5028';
  $display->content['new-3059668b-df20-48fe-8f05-24b959fc5028'] = $pane;
  $display->panels['contentmain'][0] = 'new-3059668b-df20-48fe-8f05-24b959fc5028';
  $pane = new stdClass();
  $pane->pid = 'new-303e20e0-049c-4588-acc5-87063f8adec0';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_event-tradeshows_and_seminars_body';
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
  $pane->uuid = '303e20e0-049c-4588-acc5-87063f8adec0';
  $display->content['new-303e20e0-049c-4588-acc5-87063f8adec0'] = $pane;
  $display->panels['contentmain'][1] = 'new-303e20e0-049c-4588-acc5-87063f8adec0';
  $pane = new stdClass();
  $pane->pid = 'new-f2abd70d-e7a3-456c-892d-9000b1e353d3';
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
  $pane->uuid = 'f2abd70d-e7a3-456c-892d-9000b1e353d3';
  $display->content['new-f2abd70d-e7a3-456c-892d-9000b1e353d3'] = $pane;
  $display->panels['sidebar'][0] = 'new-f2abd70d-e7a3-456c-892d-9000b1e353d3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['event'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'webinars';
  $page->task = 'page';
  $page->admin_title = 'Webinars';
  $page->admin_description = '';
  $page->path = 'training/webinars';
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
  $handler->name = 'page_webinars__panel';
  $handler->task = 'page';
  $handler->subtask = 'webinars';
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
  $display->uuid = '2f49e632-45fd-4bf6-9cfa-3b26b4708328';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_webinars__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d22bbbcd-9ef5-40c8-a06c-e8255580330d';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_event-webinars';
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
  $pane->uuid = 'd22bbbcd-9ef5-40c8-a06c-e8255580330d';
  $display->content['new-d22bbbcd-9ef5-40c8-a06c-e8255580330d'] = $pane;
  $display->panels['contentmain'][0] = 'new-d22bbbcd-9ef5-40c8-a06c-e8255580330d';
  $pane = new stdClass();
  $pane->pid = 'new-17fca5d0-cef9-4b23-be88-05304a665b35';
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
  $pane->uuid = '17fca5d0-cef9-4b23-be88-05304a665b35';
  $display->content['new-17fca5d0-cef9-4b23-be88-05304a665b35'] = $pane;
  $display->panels['sidebar'][0] = 'new-17fca5d0-cef9-4b23-be88-05304a665b35';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-17fca5d0-cef9-4b23-be88-05304a665b35';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['webinars'] = $page;

  return $pages;

}
