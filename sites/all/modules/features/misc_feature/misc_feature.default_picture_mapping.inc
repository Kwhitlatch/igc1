<?php
/**
 * @file
 * misc_feature.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function misc_feature_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'article-a1d-';
  $picture_mapping->machine_name = 'article_a1d_';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article_a1d_breakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article_a1d_breakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article_a1d_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article_a1d_breakpoints_theme_flukestrap_mobile_1x',
      ),
    ),
  );
  $export['article_a1d_'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'article-topic-foot';
  $picture_mapping->machine_name = 'article_topic_foot';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-listbreakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-listbreakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-listbreakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-footbreakpoints_theme_flukestrap_mobile_1x',
      ),
    ),
  );
  $export['article_topic_foot'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'article-topic-head';
  $picture_mapping->machine_name = 'article_topic_head';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-headbreakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-headbreakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-headbreakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-headbreakpoints_theme_flukestrap_mobile_1x',
      ),
    ),
  );
  $export['article_topic_head'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'article-topic-list';
  $picture_mapping->machine_name = 'article_topic_list';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-listbreakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-listbreakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-listbreakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'article-topic-listbreakpoints_theme_flukestrap_mobile_1x',
      ),
    ),
  );
  $export['article_topic_list'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Product Category & Subcategory TOC T02v1-D';
  $picture_mapping->machine_name = 'clone_of_subcategory_toc';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_empty image_',
      ),
    ),
  );
  $export['clone_of_subcategory_toc'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Full-Width-Page-Banner';
  $picture_mapping->machine_name = 'full_width_page_banner';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full_width_banner_breakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full_width_banner_breakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full_width_banner_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'full_width_banner_breakpoints_theme_flukestrap_mobile_1x',
      ),
    ),
  );
  $export['full_width_page_banner'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'home_slider_v2';
  $picture_mapping->machine_name = 'home_slider_v2';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'home_slider_v2_breakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'home_slider_v2_breakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'home_slider_v2_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'home_slider_v2_breakpoints_theme_flukestrap_mobile_1x',
      ),
    ),
  );
  $export['home_slider_v2'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Banner for most pages';
  $picture_mapping->machine_name = 'homepage_slider_banner';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'homepage_slider_breakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'homepage_slider_breakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'homepage_slider_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_empty image_',
      ),
    ),
  );
  $export['homepage_slider_banner'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'picutre-map-announcement-toc';
  $picture_mapping->machine_name = 'picutre_map_announcement_toc';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '12-9-nest_5-col_3to2-ratio_desktop-lg_365x243',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '12-9-nest_5-col_3to2-ratio_desktop-md_283x188',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '5-col_3to2-ratio_tablet_400x266',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '12-col_3to2-ratio_mobile_737x491',
      ),
    ),
  );
  $export['picutre_map_announcement_toc'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Product Image CCB01v2';
  $picture_mapping->machine_name = 'product_image_ccb01v2';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '7-col_3to2-ratio_desktop-lg_705x470',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '6-col_3to2-ratio_desktop-md_471x314',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '7-col_3to2-ratio_tablet_572x381',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '12-col_3to2-ratio_mobile_737x491',
      ),
    ),
  );
  $export['product_image_ccb01v2'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Product Recommended Product Desktop Slides';
  $picture_mapping->machine_name = 'product_recommended_product_desktop_slides';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '4-col_3to2-ratio_desktop-lg_390x260',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '4-col_3to2-ratio_desktop-md_304x202',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_empty image_',
      ),
    ),
  );
  $export['product_recommended_product_desktop_slides'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Product Recommended Product Mobile Slides';
  $picture_mapping->machine_name = 'product_recommended_product_mobile_slides';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_empty image_',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_empty image_',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '_empty image_',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '12-col_3to2-ratio_mobile_737x491',
      ),
    ),
  );
  $export['product_recommended_product_mobile_slides'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Product Subcategory TOC List BL01V1-D';
  $picture_mapping->machine_name = 'product_subcategory_toc_list_bl01v1_d';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '12-9-nest_5-col_3to2-ratio_desktop-lg_365x243',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '12-9-nest_5-col_3to2-ratio_desktop-md_283x188',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => '6-col_3to2-ratio_mobile_354x236',
      ),
    ),
  );
  $export['product_subcategory_toc_list_bl01v1_d'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Product TOC T02v1-D';
  $picture_mapping->machine_name = 'subcategory_toc';
  $picture_mapping->breakpoint_group = 'flukestrap';
  $picture_mapping->mapping = array(
    'breakpoints.theme.flukestrap.desktop_large' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_desktop_large_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.desktop_medium' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_desktop_medium_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
    'breakpoints.theme.flukestrap.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'subcategory_toc_breakpoints_theme_flukestrap_tablet_1x',
      ),
    ),
  );
  $export['subcategory_toc'] = $picture_mapping;

  return $export;
}
