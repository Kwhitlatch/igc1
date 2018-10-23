<?php

/**
 * @file
 * Solr Admin functions.
 *
 */
function igcommerce_utility_solr_404_setting_form() {
  $form = array();

  // Fieldset for empty result.
  $form['igcommerce_utility_solr_empty_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('404 Page Result Configuration'),
    '#weight' => 5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // Empty text for no result.
  $no_results_value = variable_get('igcommerce_utility_solr_empty_result_text', t('No Search Results available'));

  $form['igcommerce_utility_solr_empty_fieldset']['igcommerce_utility_solr_empty_result_text'] = array(
    '#type' => 'textfield',
    '#title' => 'Empty Text for No result',
    '#description' => t('The empty text for no result'),
    '#default_value' => t($no_results_value),
    '#required' => TRUE,
  );


  $tips_label = variable_get('igcommerce_utility_solr_empty_search_tips_label', t('Search tips'));

  // Tips label field.
  $form['igcommerce_utility_solr_empty_fieldset']['igcommerce_utility_solr_empty_search_tips_label'] = array(
    '#type' => 'textfield',
    '#title' => 'Search Tips Label',
    '#description' => t('Search Tips label if no result found'),
    '#default_value' => t($tips_label),
    '#required' => TRUE,
  );

  $description = '';
  $description .= '<ul><li>' . t('Check if your spelling is correct, or try removing filter.') . '</li>';
  $description .= '<li>' . t('Remove quotes around phrases to match each word individually: "blue drop" will match less than blue drop.') . '</li>';
  $description .= '<li>' . t('You can require or exclude terms using + and -:big + blue drop will require a match on blue while big blue -drop will exclude results that contain drop.') . '</li></ul>';

  $tips_description = variable_get('igcommerce_utility_solr_empty_search_tips_description', $description);

  // Event Description.
  $form['igcommerce_utility_solr_empty_fieldset']['igcommerce_utility_solr_empty_search_tips_description'] = array(
    '#type' => 'textarea',
    '#title' => 'Search Tips description',
    '#description' => t('Search Tips description if no result found'),
    '#default_value' => t($tips_description),
    '#required' => TRUE,
  );

  // Fieldset for empty result.
  $form['igcommerce_utility_solr_popular_product'] = array(
    '#type' => 'fieldset',
    '#title' => t('Popular Product Categories'),
    '#weight' => 5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $product = taxonomy_get_term_by_name('products', 'url_builder');
  $product_term = array_shift($product);
  $product_tree = taxonomy_get_tree($product_term->vid, $product_term->tid, $max_depth = 1, $load_entities = TRUE);
  $product_categories = array();
  foreach ($product_tree as $key => $value) {
    $product_categories[$value->tid] = $value->name;
  }


  $popular_term = variable_get('igcommerce_utility_solr_popular_product_term');

  // Product category term.
  $form['igcommerce_utility_solr_popular_product']['igcommerce_utility_solr_popular_product_term']=array(
    '#type' => 'select',
    '#title' => t('Popular Product Categories'),
    '#default_value' => $popular_term,
    '#options' => $product_categories,
    '#multiple' => TRUE,
    '#attributes' => array('size' => 4),
    '#weight' => 8,
  );

  return system_settings_form($form);
}
