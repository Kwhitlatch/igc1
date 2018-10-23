<?php
/**
 * @file
 * misc_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function misc_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'flukestrap_daniel';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '75.02983984465466',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '24.970160155345344',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'left' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '40d0f9e0-32c9-40a6-a6d0-3d7231e7373d';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f3a9d362-14cd-4154-abba-b4a38eecdc2d';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_content_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => 'h1',
      'title_link' => '',
      'title_class' => '',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'block',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f3a9d362-14cd-4154-abba-b4a38eecdc2d';
  $display->content['new-f3a9d362-14cd-4154-abba-b4a38eecdc2d'] = $pane;
  $display->panels['contentmain'][0] = 'new-f3a9d362-14cd-4154-abba-b4a38eecdc2d';
  $pane = new stdClass();
  $pane->pid = 'new-55d1d19f-f609-4e3b-b588-4fde4c855996';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '55d1d19f-f609-4e3b-b588-4fde4c855996';
  $display->content['new-55d1d19f-f609-4e3b-b588-4fde4c855996'] = $pane;
  $display->panels['contentmain'][1] = 'new-55d1d19f-f609-4e3b-b588-4fde4c855996';
  $pane = new stdClass();
  $pane->pid = 'new-f72c8654-a3d7-470d-b964-6f23768cfc9b';
  $pane->panel = 'contentmain';
  $pane->type = 'views';
  $pane->subtype = 'related_items';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_3',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f72c8654-a3d7-470d-b964-6f23768cfc9b';
  $display->content['new-f72c8654-a3d7-470d-b964-6f23768cfc9b'] = $pane;
  $display->panels['contentmain'][2] = 'new-f72c8654-a3d7-470d-b964-6f23768cfc9b';
  $pane = new stdClass();
  $pane->pid = 'new-1fdb6739-2a87-46ff-9a47-a09fb1a62d61';
  $pane->panel = 'footer';
  $pane->type = 'views';
  $pane->subtype = 'related_items';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_5',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1fdb6739-2a87-46ff-9a47-a09fb1a62d61';
  $display->content['new-1fdb6739-2a87-46ff-9a47-a09fb1a62d61'] = $pane;
  $display->panels['footer'][0] = 'new-1fdb6739-2a87-46ff-9a47-a09fb1a62d61';
  $pane = new stdClass();
  $pane->pid = 'new-32ef6aa1-d086-47a4-8a22-fa1e41458ff2';
  $pane->panel = 'footer';
  $pane->type = 'views';
  $pane->subtype = 'related_items';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_2',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'container',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '32ef6aa1-d086-47a4-8a22-fa1e41458ff2';
  $display->content['new-32ef6aa1-d086-47a4-8a22-fa1e41458ff2'] = $pane;
  $display->panels['footer'][1] = 'new-32ef6aa1-d086-47a4-8a22-fa1e41458ff2';
  $pane = new stdClass();
  $pane->pid = 'new-9a175ed6-a35b-4a45-9926-1a0319472a52';
  $pane->panel = 'footer';
  $pane->type = 'views';
  $pane->subtype = 'card_footer_specifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
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
  $pane->uuid = '9a175ed6-a35b-4a45-9926-1a0319472a52';
  $display->content['new-9a175ed6-a35b-4a45-9926-1a0319472a52'] = $pane;
  $display->panels['footer'][2] = 'new-9a175ed6-a35b-4a45-9926-1a0319472a52';
  $pane = new stdClass();
  $pane->pid = 'new-f06f763b-1e78-4001-a201-e00503c711dc';
  $pane->panel = 'footer';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_card_id';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->uuid = 'f06f763b-1e78-4001-a201-e00503c711dc';
  $display->content['new-f06f763b-1e78-4001-a201-e00503c711dc'] = $pane;
  $display->panels['footer'][3] = 'new-f06f763b-1e78-4001-a201-e00503c711dc';
  $pane = new stdClass();
  $pane->pid = 'new-54753e1b-8615-4f3f-ba89-59f4465dcdc1';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_header_image_page';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'dam_uri_image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'classes' => '',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '54753e1b-8615-4f3f-ba89-59f4465dcdc1';
  $display->content['new-54753e1b-8615-4f3f-ba89-59f4465dcdc1'] = $pane;
  $display->panels['header'][0] = 'new-54753e1b-8615-4f3f-ba89-59f4465dcdc1';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:article:default:default'] = $panelizer;

  return $export;
}
