<?php
/**
 * @file
 * ig_wtb_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ig_wtb_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'where_to_buy';
  $page->task = 'page';
  $page->admin_title = 'Where to Buy';
  $page->admin_description = '';
  $page->path = 'where-to-buy';
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
  $handler->name = 'page_where_to_buy__panel';
  $handler->task = 'page';
  $handler->subtask = 'where_to_buy';
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
  $display->title = 'Where to Buy';
  $display->uuid = '09be22f0-2410-4200-b904-a5384aaf093b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_where_to_buy__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e5990a8d-7364-4ec2-af92-3088e0a172f5';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility-ig_user_location';
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
  $pane->uuid = 'e5990a8d-7364-4ec2-af92-3088e0a172f5';
  $display->content['new-e5990a8d-7364-4ec2-af92-3088e0a172f5'] = $pane;
  $display->panels['contentmain'][0] = 'new-e5990a8d-7364-4ec2-af92-3088e0a172f5';
  $pane = new stdClass();
  $pane->pid = 'new-5249a142-80e3-4244-956b-a9aa7c6a32cd';
  $pane->panel = 'contentmain';
  $pane->type = 'wtbTitleDescription';
  $pane->subtype = 'wtbTitleDescription';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5249a142-80e3-4244-956b-a9aa7c6a32cd';
  $display->content['new-5249a142-80e3-4244-956b-a9aa7c6a32cd'] = $pane;
  $display->panels['contentmain'][1] = 'new-5249a142-80e3-4244-956b-a9aa7c6a32cd';
  $pane = new stdClass();
  $pane->pid = 'new-110d4dcb-97f0-4d69-9871-4adb42acdc6c';
  $pane->panel = 'contentmain';
  $pane->type = 'wtbform';
  $pane->subtype = 'wtbform';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'site_language',
        'settings' => array(
          'language' => array(
            'default' => 'default',
            'en-us' => 'en-us',
            'da-dk' => 'da-dk',
            'en-au' => 'en-au',
            'en-id' => 'en-id',
            'en-in' => 'en-in',
            'en-my' => 'en-my',
            'en-ph' => 'en-ph',
            'en-sg' => 'en-sg',
            'en-th' => 'en-th',
            'en-tt' => 'en-tt',
            'en-vn' => 'en-vn',
            'es-mx' => 'es-mx',
            'es-ar' => 'es-ar',
            'es-bo' => 'es-bo',
            'es-cl' => 'es-cl',
            'es-co' => 'es-co',
            'es-cr' => 'es-cr',
            'es-do' => 'es-do',
            'es-ec' => 'es-ec',
            'es-gt' => 'es-gt',
            'es-pe' => 'es-pe',
            'es-sv' => 'es-sv',
            'es-us' => 'es-us',
            'es-uy' => 'es-uy',
            'es-ve' => 'es-ve',
            'fr' => 'fr',
            'id-id' => 'id-id',
            'ja-jp' => 'ja-jp',
            'ko-kr' => 'ko-kr',
            'ru-ru' => 'ru-ru',
            'th-th' => 'th-th',
            'tr-tr' => 'tr-tr',
            'vi-vn' => 'vi-vn',
            'zh-cn' => 'zh-cn',
            'cn' => 'cn',
            'zh-tw' => 'zh-tw',
            'cs-cz' => 0,
            'de-de' => 0,
            'de-at' => 0,
            'de-ch' => 0,
            'en' => 0,
            'en-ca' => 0,
            'en-gb' => 0,
            'en-ie' => 0,
            'es-es' => 0,
            'fi-fi' => 0,
            'fr-fr' => 0,
            'fr-be' => 0,
            'fr-ca' => 0,
            'fr-ch' => 0,
            'it-it' => 0,
            'nl-nl' => 0,
            'nl-be' => 0,
            'no-no' => 0,
            'pl-pl' => 0,
            'pt-br' => 0,
            'pt-pt' => 0,
            'sv-se' => 0,
          ),
        ),
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '110d4dcb-97f0-4d69-9871-4adb42acdc6c';
  $display->content['new-110d4dcb-97f0-4d69-9871-4adb42acdc6c'] = $pane;
  $display->panels['contentmain'][2] = 'new-110d4dcb-97f0-4d69-9871-4adb42acdc6c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['where_to_buy'] = $page;

  return $pages;

}
