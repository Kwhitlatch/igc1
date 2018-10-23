<?php
/**
 * @file
 * product_toc_solr.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function product_toc_solr_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'product_page';
  $page->task = 'page';
  $page->admin_title = 'Product page';
  $page->admin_description = '';
  $page->path = 'product';
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
  $handler->name = 'page_product_page__panel_context_efda2ed8-7623-4f9c-b3f2-ef812c4b48dd';
  $handler->task = 'page';
  $handler->subtask = 'product_page';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '',
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
      'title' => NULL,
      'header' => NULL,
      'slideshow' => NULL,
      'alert-panel' => NULL,
      'overview' => NULL,
      'overview-links' => NULL,
      'accessories' => NULL,
      'resources' => NULL,
      'related' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'prod-accessories' => NULL,
      'key-features' => NULL,
      'prod-models' => NULL,
      'libby-request-pricing' => NULL,
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
  $display->uuid = 'a432f23c-13e2-4640-9fb6-74ed732966ea';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_product_page__panel_context_efda2ed8-7623-4f9c-b3f2-ef812c4b48dd';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-24925c4d-02a0-4002-bc91-8f07fd4ba200';
  $pane->panel = 'contentmain';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'site_language',
        'settings' => array(
          'language' => array(
            'en-us' => 'en-us',
            'default' => 0,
            'cs-cz' => 0,
            'da-dk' => 0,
            'de-de' => 0,
            'de-at' => 0,
            'de-ch' => 0,
            'en-au' => 0,
            'en-ca' => 0,
            'en-ie' => 0,
            'en-gb' => 0,
            'en-id' => 0,
            'en-in' => 0,
            'en-my' => 0,
            'en-ph' => 0,
            'en-sg' => 0,
            'en-th' => 0,
            'en-tt' => 0,
            'en-vn' => 0,
            'en' => 0,
            'es-es' => 0,
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
            'fi-fi' => 0,
            'fr-fr' => 0,
            'fr' => 0,
            'fr-be' => 0,
            'fr-ca' => 0,
            'fr-ch' => 0,
            'id-id' => 0,
            'it-it' => 0,
            'ja-jp' => 0,
            'ko-kr' => 0,
            'nl-nl' => 0,
            'nl-be' => 0,
            'no-no' => 0,
            'pl-pl' => 0,
            'pt-br' => 0,
            'pt-pt' => 0,
            'ru-ru' => 0,
            'sv-se' => 0,
            'th-th' => 0,
            'tr-tr' => 0,
            'vi-vn' => 0,
            'zh-cn' => 0,
            'zh-tw' => 0,
          ),
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Pricespider Script',
    'title' => '',
    'body' => '<script src="//embedded.pricespider.com/WidgetScript.psjs?wc=b7fdc39d-2e11-40ae-8bfc-852f2b2cb907"></script>
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
  $pane->uuid = '24925c4d-02a0-4002-bc91-8f07fd4ba200';
  $display->content['new-24925c4d-02a0-4002-bc91-8f07fd4ba200'] = $pane;
  $display->panels['contentmain'][0] = 'new-24925c4d-02a0-4002-bc91-8f07fd4ba200';
  $pane = new stdClass();
  $pane->pid = 'new-bace1cac-defe-4d0a-9b4b-0e241df9f6cf';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_products-Product Detail Page';
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
  $pane->uuid = 'bace1cac-defe-4d0a-9b4b-0e241df9f6cf';
  $display->content['new-bace1cac-defe-4d0a-9b4b-0e241df9f6cf'] = $pane;
  $display->panels['contentmain'][1] = 'new-bace1cac-defe-4d0a-9b4b-0e241df9f6cf';
  $pane = new stdClass();
  $pane->pid = 'new-d5a5af56-caf1-48b0-8161-3b0f2780fb1a';
  $pane->panel = 'contentmain';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'site_language',
        'settings' => array(
          'language' => array(
            'en-us' => 'en-us',
            'default' => 0,
            'cs-cz' => 0,
            'da-dk' => 0,
            'de-de' => 0,
            'de-at' => 0,
            'de-ch' => 0,
            'en-au' => 0,
            'en-ca' => 0,
            'en-ie' => 0,
            'en-gb' => 0,
            'en-id' => 0,
            'en-in' => 0,
            'en-my' => 0,
            'en-ph' => 0,
            'en-sg' => 0,
            'en-th' => 0,
            'en-tt' => 0,
            'en-vn' => 0,
            'en' => 0,
            'es-es' => 0,
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
            'fi-fi' => 0,
            'fr-fr' => 0,
            'fr' => 0,
            'fr-be' => 0,
            'fr-ca' => 0,
            'fr-ch' => 0,
            'id-id' => 0,
            'it-it' => 0,
            'ja-jp' => 0,
            'ko-kr' => 0,
            'nl-nl' => 0,
            'nl-be' => 0,
            'no-no' => 0,
            'pl-pl' => 0,
            'pt-br' => 0,
            'pt-pt' => 0,
            'ru-ru' => 0,
            'sv-se' => 0,
            'th-th' => 0,
            'tr-tr' => 0,
            'vi-vn' => 0,
            'zh-cn' => 0,
            'zh-tw' => 0,
          ),
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Bazaarvoice Reviews',
    'title' => 'Reviews',
    'body' => '<div id="BVRRSearchContainer"></div>
<div id="BVRRContainer"></div>
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd5a5af56-caf1-48b0-8161-3b0f2780fb1a';
  $display->content['new-d5a5af56-caf1-48b0-8161-3b0f2780fb1a'] = $pane;
  $display->panels['contentmain'][2] = 'new-d5a5af56-caf1-48b0-8161-3b0f2780fb1a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['product_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products';
  $page->task = 'page';
  $page->admin_title = 'Products TOC - home';
  $page->admin_description = '';
  $page->path = 'products';
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
  $handler->name = 'page_products__panel';
  $handler->task = 'page';
  $handler->subtask = 'products';
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '[metatag:title] |[site:name]',
        ),
      ),
    ),
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
  $display->uuid = 'b9c4c88f-c973-453e-9272-9820a6bc70b1';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-43a7c7fa-fa5c-4f65-a8b4-0c2de1e486e5';
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
  $pane->uuid = '43a7c7fa-fa5c-4f65-a8b4-0c2de1e486e5';
  $display->content['new-43a7c7fa-fa5c-4f65-a8b4-0c2de1e486e5'] = $pane;
  $display->panels['contentmain'][0] = 'new-43a7c7fa-fa5c-4f65-a8b4-0c2de1e486e5';
  $pane = new stdClass();
  $pane->pid = 'new-ec94b20c-7045-41c9-b6cf-3f2e94fc3f8a';
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
  $pane->uuid = 'ec94b20c-7045-41c9-b6cf-3f2e94fc3f8a';
  $display->content['new-ec94b20c-7045-41c9-b6cf-3f2e94fc3f8a'] = $pane;
  $display->panels['contentmain'][1] = 'new-ec94b20c-7045-41c9-b6cf-3f2e94fc3f8a';
  $pane = new stdClass();
  $pane->pid = 'new-e93ac4e7-e609-45ba-a757-696947da186a';
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
  $pane->uuid = 'e93ac4e7-e609-45ba-a757-696947da186a';
  $display->content['new-e93ac4e7-e609-45ba-a757-696947da186a'] = $pane;
  $display->panels['contentmain'][2] = 'new-e93ac4e7-e609-45ba-a757-696947da186a';
  $pane = new stdClass();
  $pane->pid = 'new-cbfb2c09-5d27-4413-aaea-21c5cdfd03d9';
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
  $pane->uuid = 'cbfb2c09-5d27-4413-aaea-21c5cdfd03d9';
  $display->content['new-cbfb2c09-5d27-4413-aaea-21c5cdfd03d9'] = $pane;
  $display->panels['footer'][0] = 'new-cbfb2c09-5d27-4413-aaea-21c5cdfd03d9';
  $pane = new stdClass();
  $pane->pid = 'new-3c85882b-6f86-46be-9d51-608f159b1322';
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
  $pane->uuid = '3c85882b-6f86-46be-9d51-608f159b1322';
  $display->content['new-3c85882b-6f86-46be-9d51-608f159b1322'] = $pane;
  $display->panels['footer'][1] = 'new-3c85882b-6f86-46be-9d51-608f159b1322';
  $pane = new stdClass();
  $pane->pid = 'new-28fcb67d-73c4-4ab5-88bc-8902703db659';
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
  $pane->uuid = '28fcb67d-73c4-4ab5-88bc-8902703db659';
  $display->content['new-28fcb67d-73c4-4ab5-88bc-8902703db659'] = $pane;
  $display->panels['header'][0] = 'new-28fcb67d-73c4-4ab5-88bc-8902703db659';
  $pane = new stdClass();
  $pane->pid = 'new-df3d3734-03a8-4f7f-a2bb-5ef0b38ebf37';
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
  $pane->uuid = 'df3d3734-03a8-4f7f-a2bb-5ef0b38ebf37';
  $display->content['new-df3d3734-03a8-4f7f-a2bb-5ef0b38ebf37'] = $pane;
  $display->panels['sidebar'][0] = 'new-df3d3734-03a8-4f7f-a2bb-5ef0b38ebf37';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-28fcb67d-73c4-4ab5-88bc-8902703db659';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = TRUE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_products__de-de';
  $handler->task = 'page';
  $handler->subtask = 'products';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'de-de',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'de-de',
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => '[metatag:title] |[site:name]',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'de-de' => 'de-de',
              'default' => 0,
              'en-us' => 0,
              'cs-cz' => 0,
              'da-dk' => 0,
              'de-at' => 0,
              'de-ch' => 0,
              'en-au' => 0,
              'en-ca' => 0,
              'en-ie' => 0,
              'en-gb' => 0,
              'en-id' => 0,
              'en-in' => 0,
              'en-my' => 0,
              'en-ph' => 0,
              'en-sg' => 0,
              'en-th' => 0,
              'en-tt' => 0,
              'en-vn' => 0,
              'en' => 0,
              'es-es' => 0,
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
              'fi-fi' => 0,
              'fr-fr' => 0,
              'fr' => 0,
              'fr-be' => 0,
              'fr-ca' => 0,
              'fr-ch' => 0,
              'id-id' => 0,
              'it-it' => 0,
              'ja-jp' => 0,
              'ko-kr' => 0,
              'nl-nl' => 0,
              'nl-be' => 0,
              'no-no' => 0,
              'pl-pl' => 0,
              'pt-br' => 0,
              'pt-pt' => 0,
              'ru-ru' => 0,
              'sv-se' => 0,
              'th-th' => 0,
              'tr-tr' => 0,
              'vi-vn' => 0,
              'zh-cn' => 0,
              'zh-tw' => 0,
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->uuid = 'b9c4c88f-c973-453e-9272-9820a6bc70b1';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products__de-de';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-43a7c7fa-fa5c-4f65-a8b4-0c2de1e486e5';
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
  $pane->uuid = '43a7c7fa-fa5c-4f65-a8b4-0c2de1e486e5';
  $display->content['new-43a7c7fa-fa5c-4f65-a8b4-0c2de1e486e5'] = $pane;
  $display->panels['contentmain'][0] = 'new-43a7c7fa-fa5c-4f65-a8b4-0c2de1e486e5';
  $pane = new stdClass();
  $pane->pid = 'new-ec94b20c-7045-41c9-b6cf-3f2e94fc3f8a';
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
  $pane->uuid = 'ec94b20c-7045-41c9-b6cf-3f2e94fc3f8a';
  $display->content['new-ec94b20c-7045-41c9-b6cf-3f2e94fc3f8a'] = $pane;
  $display->panels['contentmain'][1] = 'new-ec94b20c-7045-41c9-b6cf-3f2e94fc3f8a';
  $pane = new stdClass();
  $pane->pid = 'new-e93ac4e7-e609-45ba-a757-696947da186a';
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
  $pane->uuid = 'e93ac4e7-e609-45ba-a757-696947da186a';
  $display->content['new-e93ac4e7-e609-45ba-a757-696947da186a'] = $pane;
  $display->panels['contentmain'][2] = 'new-e93ac4e7-e609-45ba-a757-696947da186a';
  $pane = new stdClass();
  $pane->pid = 'new-28fcb67d-73c4-4ab5-88bc-8902703db659';
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
  $pane->uuid = '28fcb67d-73c4-4ab5-88bc-8902703db659';
  $display->content['new-28fcb67d-73c4-4ab5-88bc-8902703db659'] = $pane;
  $display->panels['header'][0] = 'new-28fcb67d-73c4-4ab5-88bc-8902703db659';
  $pane = new stdClass();
  $pane->pid = 'new-df3d3734-03a8-4f7f-a2bb-5ef0b38ebf37';
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
  $pane->uuid = 'df3d3734-03a8-4f7f-a2bb-5ef0b38ebf37';
  $display->content['new-df3d3734-03a8-4f7f-a2bb-5ef0b38ebf37'] = $pane;
  $display->panels['sidebar'][0] = 'new-df3d3734-03a8-4f7f-a2bb-5ef0b38ebf37';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-28fcb67d-73c4-4ab5-88bc-8902703db659';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products_awards';
  $page->task = 'page';
  $page->admin_title = 'Products - Awards';
  $page->admin_description = '';
  $page->path = 'products/awards';
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
  $handler->name = 'page_products_awards__panel_context_e6694d71-917d-427b-8c9d-2514d4a69284';
  $handler->task = 'page';
  $handler->subtask = 'products_awards';
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
  $display->uuid = '269b87ab-1b54-4ba2-83a3-3b388831cf44';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products_awards__panel_context_e6694d71-917d-427b-8c9d-2514d4a69284';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6f2d1bd2-f7bf-49e1-b037-d7d6585a8de4';
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
  $pane->uuid = '6f2d1bd2-f7bf-49e1-b037-d7d6585a8de4';
  $display->content['new-6f2d1bd2-f7bf-49e1-b037-d7d6585a8de4'] = $pane;
  $display->panels['contentmain'][0] = 'new-6f2d1bd2-f7bf-49e1-b037-d7d6585a8de4';
  $pane = new stdClass();
  $pane->pid = 'new-f22d099a-9805-4008-985f-4ba4582b377a';
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
  $pane->uuid = 'f22d099a-9805-4008-985f-4ba4582b377a';
  $display->content['new-f22d099a-9805-4008-985f-4ba4582b377a'] = $pane;
  $display->panels['contentmain'][1] = 'new-f22d099a-9805-4008-985f-4ba4582b377a';
  $pane = new stdClass();
  $pane->pid = 'new-abd307b0-609f-40a2-ba7f-933dedff72c8';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'search_list_solr-products_awards';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'abd307b0-609f-40a2-ba7f-933dedff72c8';
  $display->content['new-abd307b0-609f-40a2-ba7f-933dedff72c8'] = $pane;
  $display->panels['contentmain'][2] = 'new-abd307b0-609f-40a2-ba7f-933dedff72c8';
  $pane = new stdClass();
  $pane->pid = 'new-e3299840-3bcd-4d23-98e5-751e5ce6ffbd';
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
  $pane->uuid = 'e3299840-3bcd-4d23-98e5-751e5ce6ffbd';
  $display->content['new-e3299840-3bcd-4d23-98e5-751e5ce6ffbd'] = $pane;
  $display->panels['header'][0] = 'new-e3299840-3bcd-4d23-98e5-751e5ce6ffbd';
  $pane = new stdClass();
  $pane->pid = 'new-c14bc722-4853-4552-84b9-cf8f22119677';
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
  $pane->uuid = 'c14bc722-4853-4552-84b9-cf8f22119677';
  $display->content['new-c14bc722-4853-4552-84b9-cf8f22119677'] = $pane;
  $display->panels['sidebar'][0] = 'new-c14bc722-4853-4552-84b9-cf8f22119677';
  $pane = new stdClass();
  $pane->pid = 'new-19c91c13-4105-490b-8305-1182a7a293a4';
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
  $pane->uuid = '19c91c13-4105-490b-8305-1182a7a293a4';
  $display->content['new-19c91c13-4105-490b-8305-1182a7a293a4'] = $pane;
  $display->panels['sidebar'][1] = 'new-19c91c13-4105-490b-8305-1182a7a293a4';
  $pane = new stdClass();
  $pane->pid = 'new-94f59e30-f7fc-4fd9-a585-9977fc39e9c7';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '94f59e30-f7fc-4fd9-a585-9977fc39e9c7';
  $display->content['new-94f59e30-f7fc-4fd9-a585-9977fc39e9c7'] = $pane;
  $display->panels['sidebar'][2] = 'new-94f59e30-f7fc-4fd9-a585-9977fc39e9c7';
  $pane = new stdClass();
  $pane->pid = 'new-ddc6487f-556c-41a8-9ef7-fcaa476f9cba';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-8WlXgxpRxIHVeoY0OHpGJGac6OYhjwHw';
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
  $pane->uuid = 'ddc6487f-556c-41a8-9ef7-fcaa476f9cba';
  $display->content['new-ddc6487f-556c-41a8-9ef7-fcaa476f9cba'] = $pane;
  $display->panels['sidebar'][3] = 'new-ddc6487f-556c-41a8-9ef7-fcaa476f9cba';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e3299840-3bcd-4d23-98e5-751e5ce6ffbd';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products_awards'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products_new_fluke_products';
  $page->task = 'page';
  $page->admin_title = 'Products - New Fluke Products';
  $page->admin_description = '';
  $page->path = 'products/new-fluke-products';
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
  $handler->name = 'page_products_new_fluke_products__panel_context_e7487802-6f68-4b22-8bc2-9d734d0d7f97';
  $handler->task = 'page';
  $handler->subtask = 'products_new_fluke_products';
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
  $display->uuid = '7a615461-8df0-4561-a9a6-fddfc05d23a6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products_new_fluke_products__panel_context_e7487802-6f68-4b22-8bc2-9d734d0d7f97';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2a71907c-e28f-4738-9b37-0eb1ef9a2892';
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
  $pane->uuid = '2a71907c-e28f-4738-9b37-0eb1ef9a2892';
  $display->content['new-2a71907c-e28f-4738-9b37-0eb1ef9a2892'] = $pane;
  $display->panels['contentmain'][0] = 'new-2a71907c-e28f-4738-9b37-0eb1ef9a2892';
  $pane = new stdClass();
  $pane->pid = 'new-cc82e7ed-24a8-4dcd-88c5-4ab29c2b12fb';
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
  $pane->uuid = 'cc82e7ed-24a8-4dcd-88c5-4ab29c2b12fb';
  $display->content['new-cc82e7ed-24a8-4dcd-88c5-4ab29c2b12fb'] = $pane;
  $display->panels['contentmain'][1] = 'new-cc82e7ed-24a8-4dcd-88c5-4ab29c2b12fb';
  $pane = new stdClass();
  $pane->pid = 'new-3cb3717d-7efb-45c5-a52e-464493f7b8f6';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_products-New Products Page';
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
  $pane->uuid = '3cb3717d-7efb-45c5-a52e-464493f7b8f6';
  $display->content['new-3cb3717d-7efb-45c5-a52e-464493f7b8f6'] = $pane;
  $display->panels['contentmain'][2] = 'new-3cb3717d-7efb-45c5-a52e-464493f7b8f6';
  $pane = new stdClass();
  $pane->pid = 'new-1ae26d82-5428-457f-8724-c375a077551d';
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
  $pane->uuid = '1ae26d82-5428-457f-8724-c375a077551d';
  $display->content['new-1ae26d82-5428-457f-8724-c375a077551d'] = $pane;
  $display->panels['header'][0] = 'new-1ae26d82-5428-457f-8724-c375a077551d';
  $pane = new stdClass();
  $pane->pid = 'new-c15507d2-d93f-4a2a-8c3b-f394fafd16e9';
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
  $pane->uuid = 'c15507d2-d93f-4a2a-8c3b-f394fafd16e9';
  $display->content['new-c15507d2-d93f-4a2a-8c3b-f394fafd16e9'] = $pane;
  $display->panels['sidebar'][0] = 'new-c15507d2-d93f-4a2a-8c3b-f394fafd16e9';
  $pane = new stdClass();
  $pane->pid = 'new-77019c69-3072-44e3-bb7d-75a179f112d5';
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
  $pane->uuid = '77019c69-3072-44e3-bb7d-75a179f112d5';
  $display->content['new-77019c69-3072-44e3-bb7d-75a179f112d5'] = $pane;
  $display->panels['sidebar'][1] = 'new-77019c69-3072-44e3-bb7d-75a179f112d5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1ae26d82-5428-457f-8724-c375a077551d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products_new_fluke_products'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products_promotions_and_contests';
  $page->task = 'page';
  $page->admin_title = 'Products - Promotions and contests';
  $page->admin_description = '';
  $page->path = 'products/promotions-and-contests';
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
  $handler->name = 'page_products_promotions_and_contests__panel_context_bd8fc42d-df5d-47e4-9e21-2265f4b89e64';
  $handler->task = 'page';
  $handler->subtask = 'products_promotions_and_contests';
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
  $display->uuid = '7a615461-8df0-4561-a9a6-fddfc05d23a6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products_promotions_and_contests__panel_context_bd8fc42d-df5d-47e4-9e21-2265f4b89e64';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2a71907c-e28f-4738-9b37-0eb1ef9a2892';
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
  $pane->uuid = '2a71907c-e28f-4738-9b37-0eb1ef9a2892';
  $display->content['new-2a71907c-e28f-4738-9b37-0eb1ef9a2892'] = $pane;
  $display->panels['contentmain'][0] = 'new-2a71907c-e28f-4738-9b37-0eb1ef9a2892';
  $pane = new stdClass();
  $pane->pid = 'new-cc82e7ed-24a8-4dcd-88c5-4ab29c2b12fb';
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
  $pane->uuid = 'cc82e7ed-24a8-4dcd-88c5-4ab29c2b12fb';
  $display->content['new-cc82e7ed-24a8-4dcd-88c5-4ab29c2b12fb'] = $pane;
  $display->panels['contentmain'][1] = 'new-cc82e7ed-24a8-4dcd-88c5-4ab29c2b12fb';
  $pane = new stdClass();
  $pane->pid = 'new-14f2c597-675b-4ec8-855e-79538e9d1df4';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'search_list_solr-products_new_fluke_products';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '14f2c597-675b-4ec8-855e-79538e9d1df4';
  $display->content['new-14f2c597-675b-4ec8-855e-79538e9d1df4'] = $pane;
  $display->panels['contentmain'][2] = 'new-14f2c597-675b-4ec8-855e-79538e9d1df4';
  $pane = new stdClass();
  $pane->pid = 'new-d0c9c3b2-a42b-463d-97ac-5c23955e575f';
  $pane->panel = 'contentmain';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '12488',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '<none>',
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
  $pane->uuid = 'd0c9c3b2-a42b-463d-97ac-5c23955e575f';
  $display->content['new-d0c9c3b2-a42b-463d-97ac-5c23955e575f'] = $pane;
  $display->panels['contentmain'][3] = 'new-d0c9c3b2-a42b-463d-97ac-5c23955e575f';
  $pane = new stdClass();
  $pane->pid = 'new-1ae26d82-5428-457f-8724-c375a077551d';
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
  $pane->uuid = '1ae26d82-5428-457f-8724-c375a077551d';
  $display->content['new-1ae26d82-5428-457f-8724-c375a077551d'] = $pane;
  $display->panels['header'][0] = 'new-1ae26d82-5428-457f-8724-c375a077551d';
  $pane = new stdClass();
  $pane->pid = 'new-c15507d2-d93f-4a2a-8c3b-f394fafd16e9';
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
  $pane->uuid = 'c15507d2-d93f-4a2a-8c3b-f394fafd16e9';
  $display->content['new-c15507d2-d93f-4a2a-8c3b-f394fafd16e9'] = $pane;
  $display->panels['sidebar'][0] = 'new-c15507d2-d93f-4a2a-8c3b-f394fafd16e9';
  $pane = new stdClass();
  $pane->pid = 'new-77019c69-3072-44e3-bb7d-75a179f112d5';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-2IgPmwdqQSGUkGbHDkRBTNj0IbDOOIiT';
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
  $pane->uuid = '77019c69-3072-44e3-bb7d-75a179f112d5';
  $display->content['new-77019c69-3072-44e3-bb7d-75a179f112d5'] = $pane;
  $display->panels['sidebar'][1] = 'new-77019c69-3072-44e3-bb7d-75a179f112d5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1ae26d82-5428-457f-8724-c375a077551d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products_promotions_and_contests'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products_toc_product_categories';
  $page->task = 'page';
  $page->admin_title = 'Products - TOC - Product Categories';
  $page->admin_description = '';
  $page->path = 'products/%family/%category';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'family' => array(
      'id' => 2,
      'identifier' => 'Family',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'category' => array(
      'id' => 3,
      'identifier' => 'Category',
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
  $handler->name = 'page_products_toc_product_categories__panel_context_cf9f2a79-467f-4403-a26d-be93a7d38995';
  $handler->task = 'page';
  $handler->subtask = 'products_toc_product_categories';
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(),
    ),
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
  $display->title = '%category:html_safe';
  $display->uuid = '538d338b-f58b-4203-80bf-d39076b7fdca';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products_toc_product_categories__panel_context_cf9f2a79-467f-4403-a26d-be93a7d38995';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-67a1125c-88df-4ea4-bf41-2ebac0d84d35';
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
  $pane->uuid = '67a1125c-88df-4ea4-bf41-2ebac0d84d35';
  $display->content['new-67a1125c-88df-4ea4-bf41-2ebac0d84d35'] = $pane;
  $display->panels['contentmain'][0] = 'new-67a1125c-88df-4ea4-bf41-2ebac0d84d35';
  $pane = new stdClass();
  $pane->pid = 'new-fb3c058d-0898-4f14-b89c-28b918e662cc';
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
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'fb3c058d-0898-4f14-b89c-28b918e662cc';
  $display->content['new-fb3c058d-0898-4f14-b89c-28b918e662cc'] = $pane;
  $display->panels['contentmain'][1] = 'new-fb3c058d-0898-4f14-b89c-28b918e662cc';
  $pane = new stdClass();
  $pane->pid = 'new-e48c7c48-8874-490d-ad48-62d94db9808b';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e48c7c48-8874-490d-ad48-62d94db9808b';
  $display->content['new-e48c7c48-8874-490d-ad48-62d94db9808b'] = $pane;
  $display->panels['contentmain'][2] = 'new-e48c7c48-8874-490d-ad48-62d94db9808b';
  $pane = new stdClass();
  $pane->pid = 'new-085611ec-e3b6-41d0-9dd0-1fcc05b320d6';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '085611ec-e3b6-41d0-9dd0-1fcc05b320d6';
  $display->content['new-085611ec-e3b6-41d0-9dd0-1fcc05b320d6'] = $pane;
  $display->panels['contentmain'][3] = 'new-085611ec-e3b6-41d0-9dd0-1fcc05b320d6';
  $pane = new stdClass();
  $pane->pid = 'new-d6db98b7-b3de-4e56-9ff4-28b95e862e92';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'quicktabs-product_toc_listings';
  $pane->shown = FALSE;
  $pane->access = array();
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
  $pane->uuid = 'd6db98b7-b3de-4e56-9ff4-28b95e862e92';
  $display->content['new-d6db98b7-b3de-4e56-9ff4-28b95e862e92'] = $pane;
  $display->panels['contentmain'][4] = 'new-d6db98b7-b3de-4e56-9ff4-28b95e862e92';
  $pane = new stdClass();
  $pane->pid = 'new-9018957d-eedd-4bdb-bb94-9415f70bbb4b';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '9018957d-eedd-4bdb-bb94-9415f70bbb4b';
  $display->content['new-9018957d-eedd-4bdb-bb94-9415f70bbb4b'] = $pane;
  $display->panels['contentmain'][5] = 'new-9018957d-eedd-4bdb-bb94-9415f70bbb4b';
  $pane = new stdClass();
  $pane->pid = 'new-a902da9e-d089-4125-a7c3-efae7c82f518';
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
  $pane->uuid = 'a902da9e-d089-4125-a7c3-efae7c82f518';
  $display->content['new-a902da9e-d089-4125-a7c3-efae7c82f518'] = $pane;
  $display->panels['contentmain'][6] = 'new-a902da9e-d089-4125-a7c3-efae7c82f518';
  $pane = new stdClass();
  $pane->pid = 'new-623e8afb-4798-4056-ac00-01751a4b68d1';
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
  $pane->uuid = '623e8afb-4798-4056-ac00-01751a4b68d1';
  $display->content['new-623e8afb-4798-4056-ac00-01751a4b68d1'] = $pane;
  $display->panels['footer'][0] = 'new-623e8afb-4798-4056-ac00-01751a4b68d1';
  $pane = new stdClass();
  $pane->pid = 'new-ef3e4a7f-fb97-42e5-9b93-4b4408ea5ca0';
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
  $pane->uuid = 'ef3e4a7f-fb97-42e5-9b93-4b4408ea5ca0';
  $display->content['new-ef3e4a7f-fb97-42e5-9b93-4b4408ea5ca0'] = $pane;
  $display->panels['footer'][1] = 'new-ef3e4a7f-fb97-42e5-9b93-4b4408ea5ca0';
  $pane = new stdClass();
  $pane->pid = 'new-604984e9-3329-4f9d-ad8f-2472b2260f22';
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
  $pane->uuid = '604984e9-3329-4f9d-ad8f-2472b2260f22';
  $display->content['new-604984e9-3329-4f9d-ad8f-2472b2260f22'] = $pane;
  $display->panels['header'][0] = 'new-604984e9-3329-4f9d-ad8f-2472b2260f22';
  $pane = new stdClass();
  $pane->pid = 'new-3121ce4c-3fd0-4e39-9488-9074239e883e';
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
  $pane->uuid = '3121ce4c-3fd0-4e39-9488-9074239e883e';
  $display->content['new-3121ce4c-3fd0-4e39-9488-9074239e883e'] = $pane;
  $display->panels['sidebar'][0] = 'new-3121ce4c-3fd0-4e39-9488-9074239e883e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products_toc_product_categories'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products_toc_product_subcategories';
  $page->task = 'page';
  $page->admin_title = 'Products - TOC - Product Subcategories';
  $page->admin_description = '';
  $page->path = 'products/%family/%category/%subcategory';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'family' => array(
      'id' => 2,
      'identifier' => 'Family',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'category' => array(
      'id' => 3,
      'identifier' => 'Category',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'subcategory' => array(
      'id' => 4,
      'identifier' => 'Subcategory',
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
  $handler->name = 'page_products_toc_product_subcategories__panel_context_54b9b84b-4b31-4601-9dbd-add61f8ac598';
  $handler->task = 'page';
  $handler->subtask = 'products_toc_product_subcategories';
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
  $display->uuid = '538d338b-f58b-4203-80bf-d39076b7fdca';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products_toc_product_subcategories__panel_context_54b9b84b-4b31-4601-9dbd-add61f8ac598';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-67a1125c-88df-4ea4-bf41-2ebac0d84d35';
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
  $pane->uuid = '67a1125c-88df-4ea4-bf41-2ebac0d84d35';
  $display->content['new-67a1125c-88df-4ea4-bf41-2ebac0d84d35'] = $pane;
  $display->panels['contentmain'][0] = 'new-67a1125c-88df-4ea4-bf41-2ebac0d84d35';
  $pane = new stdClass();
  $pane->pid = 'new-e48c7c48-8874-490d-ad48-62d94db9808b';
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
  $pane->uuid = 'e48c7c48-8874-490d-ad48-62d94db9808b';
  $display->content['new-e48c7c48-8874-490d-ad48-62d94db9808b'] = $pane;
  $display->panels['contentmain'][1] = 'new-e48c7c48-8874-490d-ad48-62d94db9808b';
  $pane = new stdClass();
  $pane->pid = 'new-62e377b3-f471-4217-a3e5-8e9265605d95';
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
  $pane->uuid = '62e377b3-f471-4217-a3e5-8e9265605d95';
  $display->content['new-62e377b3-f471-4217-a3e5-8e9265605d95'] = $pane;
  $display->panels['contentmain'][2] = 'new-62e377b3-f471-4217-a3e5-8e9265605d95';
  $pane = new stdClass();
  $pane->pid = 'new-38ec5024-236d-4808-9e76-73c83a4bf851';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'quicktabs-product_toc_listings';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '38ec5024-236d-4808-9e76-73c83a4bf851';
  $display->content['new-38ec5024-236d-4808-9e76-73c83a4bf851'] = $pane;
  $display->panels['contentmain'][3] = 'new-38ec5024-236d-4808-9e76-73c83a4bf851';
  $pane = new stdClass();
  $pane->pid = 'new-04a46496-28ff-4063-94ba-df7d32837031';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '04a46496-28ff-4063-94ba-df7d32837031';
  $display->content['new-04a46496-28ff-4063-94ba-df7d32837031'] = $pane;
  $display->panels['contentmain'][4] = 'new-04a46496-28ff-4063-94ba-df7d32837031';
  $pane = new stdClass();
  $pane->pid = 'new-60f7f733-e830-44fe-a559-b3a82d22f499';
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
  $pane->uuid = '60f7f733-e830-44fe-a559-b3a82d22f499';
  $display->content['new-60f7f733-e830-44fe-a559-b3a82d22f499'] = $pane;
  $display->panels['contentmain'][5] = 'new-60f7f733-e830-44fe-a559-b3a82d22f499';
  $pane = new stdClass();
  $pane->pid = 'new-01dfe1e3-9c77-4b90-a080-9a770cbbeeee';
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
  $pane->uuid = '01dfe1e3-9c77-4b90-a080-9a770cbbeeee';
  $display->content['new-01dfe1e3-9c77-4b90-a080-9a770cbbeeee'] = $pane;
  $display->panels['footer'][0] = 'new-01dfe1e3-9c77-4b90-a080-9a770cbbeeee';
  $pane = new stdClass();
  $pane->pid = 'new-9409c673-8f22-411a-afe1-c740cd312417';
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
  $pane->uuid = '9409c673-8f22-411a-afe1-c740cd312417';
  $display->content['new-9409c673-8f22-411a-afe1-c740cd312417'] = $pane;
  $display->panels['footer'][1] = 'new-9409c673-8f22-411a-afe1-c740cd312417';
  $pane = new stdClass();
  $pane->pid = 'new-604984e9-3329-4f9d-ad8f-2472b2260f22';
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
  $pane->uuid = '604984e9-3329-4f9d-ad8f-2472b2260f22';
  $display->content['new-604984e9-3329-4f9d-ad8f-2472b2260f22'] = $pane;
  $display->panels['header'][0] = 'new-604984e9-3329-4f9d-ad8f-2472b2260f22';
  $pane = new stdClass();
  $pane->pid = 'new-3121ce4c-3fd0-4e39-9488-9074239e883e';
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
  $pane->uuid = '3121ce4c-3fd0-4e39-9488-9074239e883e';
  $display->content['new-3121ce4c-3fd0-4e39-9488-9074239e883e'] = $pane;
  $display->panels['sidebar'][0] = 'new-3121ce4c-3fd0-4e39-9488-9074239e883e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-62e377b3-f471-4217-a3e5-8e9265605d95';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products_toc_product_subcategories'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'products_toc_specific_product';
  $page->task = 'page';
  $page->admin_title = 'Products - TOC - Product Families';
  $page->admin_description = '';
  $page->path = 'products/%categories';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'categories' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
      'keyword' => 'categories',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_products_toc_specific_product__panel';
  $handler->task = 'page';
  $handler->subtask = 'products_toc_specific_product';
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
  $display->uuid = '538d338b-f58b-4203-80bf-d39076b7fdca';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_products_toc_specific_product__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-67a1125c-88df-4ea4-bf41-2ebac0d84d35';
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
  $pane->uuid = '67a1125c-88df-4ea4-bf41-2ebac0d84d35';
  $display->content['new-67a1125c-88df-4ea4-bf41-2ebac0d84d35'] = $pane;
  $display->panels['contentmain'][0] = 'new-67a1125c-88df-4ea4-bf41-2ebac0d84d35';
  $pane = new stdClass();
  $pane->pid = 'new-e48c7c48-8874-490d-ad48-62d94db9808b';
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
  $pane->uuid = 'e48c7c48-8874-490d-ad48-62d94db9808b';
  $display->content['new-e48c7c48-8874-490d-ad48-62d94db9808b'] = $pane;
  $display->panels['contentmain'][1] = 'new-e48c7c48-8874-490d-ad48-62d94db9808b';
  $pane = new stdClass();
  $pane->pid = 'new-b5f0c882-25bf-4fb0-b4ff-9aa1485e1e9a';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b5f0c882-25bf-4fb0-b4ff-9aa1485e1e9a';
  $display->content['new-b5f0c882-25bf-4fb0-b4ff-9aa1485e1e9a'] = $pane;
  $display->panels['contentmain'][2] = 'new-b5f0c882-25bf-4fb0-b4ff-9aa1485e1e9a';
  $pane = new stdClass();
  $pane->pid = 'new-ff754233-7a81-4601-afad-682c28c1a62e';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ff754233-7a81-4601-afad-682c28c1a62e';
  $display->content['new-ff754233-7a81-4601-afad-682c28c1a62e'] = $pane;
  $display->panels['contentmain'][3] = 'new-ff754233-7a81-4601-afad-682c28c1a62e';
  $pane = new stdClass();
  $pane->pid = 'new-b04f87c3-0021-4cdd-bede-8bcc80a04aeb';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'igcommerce_utility_articles-promotions';
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
  $pane->uuid = 'b04f87c3-0021-4cdd-bede-8bcc80a04aeb';
  $display->content['new-b04f87c3-0021-4cdd-bede-8bcc80a04aeb'] = $pane;
  $display->panels['contentmain'][4] = 'new-b04f87c3-0021-4cdd-bede-8bcc80a04aeb';
  $pane = new stdClass();
  $pane->pid = 'new-8750f7d5-ad34-41e9-beed-ba57c371b3ab';
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
  $pane->uuid = '8750f7d5-ad34-41e9-beed-ba57c371b3ab';
  $display->content['new-8750f7d5-ad34-41e9-beed-ba57c371b3ab'] = $pane;
  $display->panels['footer'][0] = 'new-8750f7d5-ad34-41e9-beed-ba57c371b3ab';
  $pane = new stdClass();
  $pane->pid = 'new-927db623-9902-4ded-859b-d482fd9d4ac2';
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
  $pane->uuid = '927db623-9902-4ded-859b-d482fd9d4ac2';
  $display->content['new-927db623-9902-4ded-859b-d482fd9d4ac2'] = $pane;
  $display->panels['footer'][1] = 'new-927db623-9902-4ded-859b-d482fd9d4ac2';
  $pane = new stdClass();
  $pane->pid = 'new-604984e9-3329-4f9d-ad8f-2472b2260f22';
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
  $pane->uuid = '604984e9-3329-4f9d-ad8f-2472b2260f22';
  $display->content['new-604984e9-3329-4f9d-ad8f-2472b2260f22'] = $pane;
  $display->panels['header'][0] = 'new-604984e9-3329-4f9d-ad8f-2472b2260f22';
  $pane = new stdClass();
  $pane->pid = 'new-3121ce4c-3fd0-4e39-9488-9074239e883e';
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
  $pane->uuid = '3121ce4c-3fd0-4e39-9488-9074239e883e';
  $display->content['new-3121ce4c-3fd0-4e39-9488-9074239e883e'] = $pane;
  $display->panels['sidebar'][0] = 'new-3121ce4c-3fd0-4e39-9488-9074239e883e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['products_toc_specific_product'] = $page;

  return $pages;

}
