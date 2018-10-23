<?php
/**
 * @file
 * Handles getting manuals.
 */
function get_manuals_list() {
  global $language;
  $lang = $language->language;
  $language_to_get = explode('-', $lang);

  $keyword = "bundle:manual";
  $parameter[]['fl'] = 'sm_field_display_title';
  $parameter[]['fl'] = 'sm_vid_Asset_Category';
  $parameter[]['fl'] = 'tm_manuals_and_supplement';
  $parameter[]['rows'] = 1000;

  $filter[]['ss_language'] = $language_to_get[0];

  $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);
  $instrument_security_manuals_titles = array();

  $instrument_security_manuals_titles[0] = "Select Model";
  if (!empty($data->response->docs[0])) {
    $result = $data->response->docs;
    $categories_to_list = variable_get('instrument_sec_categories', 'Statement of Memory Volatility');
    $haystack = explode(',', $categories_to_list);

    foreach ( $result as $key => $values) {
      if (empty($values->sm_vid_Asset_Category)) {
        continue;        
      }
      
      if ( count(array_intersect($haystack, $values->sm_vid_Asset_Category)) > 0 ) {
        if ( !empty($values->tm_manuals_and_supplement[0]) ) {
          $manuals_supplements = json_decode($values->tm_manuals_and_supplement[0]);
          $instrument_security_manuals_files = current($manuals_supplements);
          $instrument_security_manuals_titles[$instrument_security_manuals_files->manual_file] = $values->sm_field_display_title[0];
          if ( isset($instrument_security_manuals_files->supplement_title) ) {
            $instrument_security_manuals_titles[$instrument_security_manuals_files->supplement_file] = $instrument_security_manuals_files->supplement_title;
          }
        }
      }
    }
    return array('titles' => $instrument_security_manuals_titles);
  }
}
