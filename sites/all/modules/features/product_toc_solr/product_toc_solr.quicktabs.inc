<?php
/**
 * @file
 * product_toc_solr.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function product_toc_solr_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'product_toc_listings';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Product TOC - Listings';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'igcommerce_utility_product_tocs_delta_toc_products',
      'hide_title' => 1,
      'title' => 'Products',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'igcommerce_utility_product_tocs_delta_toc_accessories',
      'hide_title' => 1,
      'title' => 'Accessories',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'igcommerce_utility_product_tocs_delta_toc_kits',
      'hide_title' => 1,
      'title' => 'Kits',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Arrows';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Accessories');
  t('Kits');
  t('Product TOC - Listings');
  t('Products');

  $export['product_toc_listings'] = $quicktabs;

  return $export;
}
