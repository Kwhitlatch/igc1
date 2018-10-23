<?php

$plugin = array(
'title' => t('Breadcrumb for comparison pages'),
'description' => t(''),
'category' => 'Widgets',
'icon' => '',
'render callback' => 'igc_compare_breadcrumb_block',
'defaults' => array(),
);

// render callback
function igc_compare_breadcrumb_block() {
    global $language, $ig_original_path;
    $lang = $language->language;

    $block = new stdClass();

    $toc_path = str_replace('/'.t('compare'), '', $ig_original_path);
    $toc_path = str_replace($lang.'/', '', $toc_path);
    $solr_doc = igc_compare_toc_by_path_alias_locale($toc_path, $lang);

    if($solr_doc) {
      $block->content = igc_compare_get_bread($solr_doc);
    } else {
      $block->content = '';
    }

    //Back to toc link
    $text = t('Back to products');

    $link = l($text, $toc_path);
    $block->content .= "<div class='compare-back-to-toc'>$link</div>";

    $block->id = 'igc-compare-breadcrumb';

    return $block;
}
