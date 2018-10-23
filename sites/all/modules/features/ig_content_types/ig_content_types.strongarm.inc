<?php
/**
 * @file
 * ig_content_types.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ig_content_types_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__article';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'featured' => array(
        'custom_settings' => FALSE,
      ),
      'article_a1_viewmode_fluke_news_p' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_list' => array(
        'custom_settings' => TRUE,
      ),
      'article_cb04v1_vm_fnp_full_page' => array(
        'custom_settings' => TRUE,
      ),
      'article_bl01v1_vm_fnp_topic_feat' => array(
        'custom_settings' => TRUE,
      ),
      'article_bl01v1_vm_fnp_topic_foot' => array(
        'custom_settings' => TRUE,
      ),
      'article_bl01v1_vm_fnp_topic_body' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_article_feat_image' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_image_only' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_article_foot_image' => array(
        'custom_settings' => FALSE,
      ),
      'article_a1d' => array(
        'custom_settings' => FALSE,
      ),
      'digitial_asset_video_only' => array(
        'custom_settings' => FALSE,
      ),
      'accessory_bl06v1' => array(
        'custom_settings' => FALSE,
      ),
      'digital_assets_slideshow' => array(
        'custom_settings' => FALSE,
      ),
      'full_width_page_banner' => array(
        'custom_settings' => FALSE,
      ),
      'product_top_pick_accessory_image' => array(
        'custom_settings' => FALSE,
      ),
      'article_toc' => array(
        'custom_settings' => TRUE,
      ),
      'subcategory_toc_image_only' => array(
        'custom_settings' => FALSE,
      ),
      'banner_for_pages' => array(
        'custom_settings' => FALSE,
      ),
      'home_page_slider' => array(
        'custom_settings' => FALSE,
      ),
      'home_slider_v2' => array(
        'custom_settings' => FALSE,
      ),
      'product_category_listing' => array(
        'custom_settings' => FALSE,
      ),
      'software_listing' => array(
        'custom_settings' => FALSE,
      ),
      'related_products' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_announcement_toc' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_product_subcategor' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_product_toc' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_relatd_prod_deskto' => array(
        'custom_settings' => FALSE,
      ),
      'homepage_slideshow' => array(
        'custom_settings' => FALSE,
      ),
      'home_slideshow' => array(
        'custom_settings' => FALSE,
      ),
      'product_featured_images' => array(
        'custom_settings' => FALSE,
      ),
      'related_products_mobile' => array(
        'custom_settings' => FALSE,
      ),
      'related_products_mobile_only' => array(
        'custom_settings' => FALSE,
      ),
      'search_result_highlighting_input' => array(
        'custom_settings' => TRUE,
      ),
      'product_sub_category_listing' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '63',
        ),
        'path' => array(
          'weight' => '64',
        ),
        'metatags' => array(
          'weight' => '85',
        ),
        'flag' => array(
          'weight' => '84',
        ),
        'locations' => array(
          'weight' => '87',
        ),
        'language' => array(
          'weight' => '65',
        ),
        'xmlsitemap' => array(
          'weight' => '86',
        ),
      ),
      'display' => array(
        'language' => array(
          'article_bl01v1_vm_fnp_topic_foot' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'article_bl01v1_vm_fnp_topic_list' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'article_cb04v1_vm_fnp_full_page' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'article_toc' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '22',
            'visible' => FALSE,
          ),
          'search_result_highlighting_input' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__distributor';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'accessory_bl06v1' => array(
        'custom_settings' => FALSE,
      ),
      'article_a1d' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_body' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_feat' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_foot' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_list' => array(
        'custom_settings' => FALSE,
      ),
      'article_cb04v1_vm_fnp_full_page' => array(
        'custom_settings' => FALSE,
      ),
      'digital_assets_slideshow' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_article_feat_image' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_article_foot_image' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_image_only' => array(
        'custom_settings' => FALSE,
      ),
      'digitial_asset_video_only' => array(
        'custom_settings' => FALSE,
      ),
      'full_width_page_banner' => array(
        'custom_settings' => FALSE,
      ),
      'product_top_pick_accessory_image' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'article_toc' => array(
        'custom_settings' => FALSE,
      ),
      'product_category_listing' => array(
        'custom_settings' => FALSE,
      ),
      'software_listing' => array(
        'custom_settings' => FALSE,
      ),
      'home_page_slider' => array(
        'custom_settings' => FALSE,
      ),
      'banner_for_pages' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_announcement_toc' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_product_subcategor' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_product_toc' => array(
        'custom_settings' => FALSE,
      ),
      'homepage_slideshow' => array(
        'custom_settings' => FALSE,
      ),
      'home_slider_v2' => array(
        'custom_settings' => FALSE,
      ),
      'home_slideshow' => array(
        'custom_settings' => FALSE,
      ),
      'product_featured_images' => array(
        'custom_settings' => FALSE,
      ),
      'related_products' => array(
        'custom_settings' => FALSE,
      ),
      'subcategory_toc_image_only' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_relatd_prod_deskto' => array(
        'custom_settings' => FALSE,
      ),
      'product_sub_category_listing' => array(
        'custom_settings' => FALSE,
      ),
      'related_products_mobile' => array(
        'custom_settings' => FALSE,
      ),
      'related_products_mobile_only' => array(
        'custom_settings' => FALSE,
      ),
      'search_result_highlighting_input' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '8',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'language' => array(
          'weight' => '9',
        ),
        'xmlsitemap' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(
        'language' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'search_result_highlighting_input' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__event';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '15',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'locations' => array(
          'weight' => '20',
        ),
        'xmlsitemap' => array(
          'weight' => '16',
        ),
        'language' => array(
          'weight' => '21',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__promotion';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_body' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_feat' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_foot' => array(
        'custom_settings' => FALSE,
      ),
      'article_bl01v1_vm_fnp_topic_list' => array(
        'custom_settings' => FALSE,
      ),
      'article_cb04v1_vm_fnp_full_page' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_article_feat_image' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_article_foot_image' => array(
        'custom_settings' => FALSE,
      ),
      'digital_asset_image_only' => array(
        'custom_settings' => FALSE,
      ),
      'product_bl01v1_vm_product_list' => array(
        'custom_settings' => FALSE,
      ),
      'product_ccb00v1_detail_page' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '1',
        ),
        'title' => array(
          'weight' => '5',
        ),
        'path' => array(
          'weight' => '7',
        ),
        'locations' => array(
          'weight' => '5',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
        'language' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__promotion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__resource';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '6',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '7',
        ),
        'locations' => array(
          'weight' => '8',
        ),
        'xmlsitemap' => array(
          'weight' => '7',
        ),
        'language' => array(
          'weight' => '14',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_article';
  $strongarm->value = '4';
  $export['language_content_type_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_distributor';
  $strongarm->value = '4';
  $export['language_content_type_distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_event';
  $strongarm->value = '4';
  $export['language_content_type_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_promotion';
  $strongarm->value = '4';
  $export['language_content_type_promotion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_resource';
  $strongarm->value = '4';
  $export['language_content_type_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_article';
  $strongarm->value = array();
  $export['menu_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_distributor';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_event';
  $strongarm->value = array();
  $export['menu_options_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_promotion';
  $strongarm->value = array();
  $export['menu_options_promotion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_resource';
  $strongarm->value = array();
  $export['menu_options_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_distributor';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_event';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_promotion';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_promotion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_resource';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_distributor';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_event';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_promotion';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_promotion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_resource';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_article';
  $strongarm->value = '1';
  $export['node_preview_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_distributor';
  $strongarm->value = '1';
  $export['node_preview_distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_event';
  $strongarm->value = '1';
  $export['node_preview_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_promotion';
  $strongarm->value = '1';
  $export['node_preview_promotion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_resource';
  $strongarm->value = '1';
  $export['node_preview_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_article';
  $strongarm->value = 0;
  $export['node_submitted_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_distributor';
  $strongarm->value = 0;
  $export['node_submitted_distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_event';
  $strongarm->value = 0;
  $export['node_submitted_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_promotion';
  $strongarm->value = 0;
  $export['node_submitted_promotion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_resource';
  $strongarm->value = 0;
  $export['node_submitted_resource'] = $strongarm;

  return $export;
}
