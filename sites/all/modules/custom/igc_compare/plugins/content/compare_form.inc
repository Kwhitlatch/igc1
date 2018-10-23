<?php

$plugin = array(
'title' => t('Comparison Page'),
'description' => t(''),
'category' => 'Widgets',
'icon' => '',
'render callback' => 'igc_compare_page_block',
'defaults' => array(),
);

// render callback
function igc_compare_page_block() {
    global $language, $ig_original_path;
    $lang = $language->language;

    $toc_path = str_replace('/'. t('compare'), '', $ig_original_path);
    $toc_path = str_replace($lang.'/', '', $toc_path);
    $toc = igc_compare_toc_by_path_alias_locale($toc_path, $lang);
    $term = _taxonomy_term_load_solr($toc->im_url_path_builder[0], $lang, 'ecm');

    $category_name = $term->sm_field_content_title[0];
    $category = $term->entity_id;

    $summary = !empty($term->ts_compare_summary) ? '<div class="compare-summary">'.$term->ts_compare_summary.'</div>' : '';

    $block = new stdClass();

    $title = t('Product Selection Guide'). ': '.$category_name;
    //$block->title = $title;
    $block->content['title']['#markup'] = "<h1>$title</h1>";

    $block->content['form'] = drupal_get_form('igc_compare_page_form', $summary, $category);

    igcommerce_utility_head_elements_alt($title, $summary);

    $block->id = 'igc-compare-page-block';

    return $block;
}
