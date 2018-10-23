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
  $parameter[]['fl'] = 'ss_field_content_title';
  $parameter[]['fl'] = 'is_field_manual_type_tid';
  $parameter[]['fl'] = 'is_field_manual_type';
  $parameter[]['fl'] = 'tm_manuals_and_supplement';
  $parameter[]['fl'] = 'ss_field_manual_type';
  $parameter[]['rows'] = 5000;

  $filter[]['ss_language'] = $language_to_get[0];

  $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);
  $instrument_security_manuals_titles = array();

  $instrument_security_manuals_titles[0] = " Select Model";
  if (!empty($data->response->docs[0])) {
    $result = $data->response->docs;
    $categories_to_list = variable_get('instrument_sec_categories', '1450');
    $haystack = explode(',', $categories_to_list);
    $haystack = array_map('strtolower', $haystack);
    
    foreach ( $result as $key => $values) {
      if (empty($values->ss_field_manual_type)) {
        continue;
      }
      $needle = $values->ss_field_manual_type;
      if(in_array($needle, $haystack)) {
        if ( !empty($values->tm_manuals_and_supplement[0]) ) {
          $manuals_supplements = json_decode($values->tm_manuals_and_supplement[0]);
          $instrument_security_manuals_files = current($manuals_supplements);
          $instrument_security_manuals_titles[$instrument_security_manuals_files->manual_file] = $values->ss_field_content_title;
          if ( isset($instrument_security_manuals_files->supplement_title) ) {
            $instrument_security_manuals_titles[$instrument_security_manuals_files->supplement_file] = $instrument_security_manuals_files->supplement_title;
          }
        }
      }
    }
    asort($instrument_security_manuals_titles); //Sort manuals by alpha
    return array('titles' => $instrument_security_manuals_titles);
  }
}
