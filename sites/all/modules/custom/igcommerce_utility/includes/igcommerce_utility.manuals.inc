<?php 

function igcommerce_utility_manuals_form_filter($form, &$form_state) {
  global $language;
  global $training_library_keyword;
  
  drupal_add_css(drupal_get_path('module', 'igcommerce_utility') . '/css/manuals.css');
  
  $form = array();

  drupal_add_js(drupal_get_path('module', 'igcommerce_utility') . '/js/manuals.js');
  drupal_add_library('system', 'ui.accordion');

  // Store in global static state so it can be used elsewhere
  $filters_selected = &drupal_static("igc_training_library_terms", array());

  if (!empty($form_state['filters'])) {
    $filters_selected = $form_state['filters'];
  }
  
  if (!empty($form_state['values']['keyword'])) {
    $training_library_keyword = $form_state['values']['keyword'];

    if ($terms_available = igcommerce_utility_manuals_get_terms_available($filters_selected)) {
      // Load all options
      $options = igcommerce_utility_manuals_get_filter_options($terms_available, $language->language);
    
      foreach ($options['manual_type'] as $tid => $name) {
        if (empty($form_state['manual_types'][$tid])) {
          unset($options['manual_type'][$tid]);
          continue;
        }
        $options['manual_type'][$tid] = $name . ' (' . $form_state['manual_types'][$tid] . ')';
      }
      
      if (!empty($options['manual_type'])) {
        // Remove filters
        $form['remove_filters'] = array(
            '#type' => 'submit',
            '#value' => t('Remove Filters'),
            '#submit' => array('igcommerce_utility_manuals_form_filter_remove_filters'),
            //'#prefix' => '<p>' . t('Filter by type') . '</p>',
        );
      }      
      
      $active = array_intersect($filters_selected, array_flip($options['manual_type']));
      $form['manual_type'] = array(
          '#type' => 'checkboxes',
          '#options' => $options['manual_type'],
          '#data_state' => !empty($active) ? 'active' : 'inactive',
      );
      
    } 
    
    if (empty($options['manual_type'])) {
      $form['no_results']['#markup'] = '<p class="no-filters">' . t('No filters available') . '</p>';
    }
    
  } else {
    $form['#attributes']['class'][] = 'no-filters';
  }
    
  // Keyword *hidden*
  $form['keyword'] = array(
      '#type' => 'hidden',
      '#default_value' => $training_library_keyword,
  );

  // Submit *hidden*
  $form['filter'] = array(
      '#type' => 'submit',
      '#value' => t('Filter'),
      '#attributes' => array('style' => 'display:none;'),
  );
  
  return $form;
}

function igcommerce_utility_manuals_form_filter_submit(&$form, &$form_state) {
  global $training_library_keyword;

  $values = $form_state['values'];
  $filters = array();

  // If there's a keyword, then add to global variable
  if (!empty($values['keyword'])) {
    $training_library_keyword = $values['keyword'];
  }

  $form_state['rebuild'] = TRUE;

  $tids = array();
    
  if (!empty($form_state['values']['manual_type'])) {
    foreach ($form_state['values']['manual_type'] as $tid => $selected) {
      if ($selected) {
        $tids[$tid] = $tid;
        $form_state['filters'][$tid] = $tid;
      }
    }
  }  

  if (empty($tids)) {
    $form_state['filters'] = array();
  }
  
  global $manual_search_results;
  
  $docs = igcommerce_utility_manuals_search_entities($tids, 'manual');
  $form_state['manual_types'] = array();
  
  $manual_search_results = igcommerce_utility_manuals_search_results_view($docs);

  // Store the result count
  global $search_filter_results;
  $form_state['manual_types'] = $search_filter_results;
}

/**
 * Keyword search for manuals
 */
function igcommerce_utility_manuals_form_search($form, &$form_state) {
  global $training_library_keyword;
  global $manual_search_results;
  global $ig_original_path, $language;

  $url_parts = explode('/', $ig_original_path);

  $term = _taxonomy_term_load_by_url_title_solr(end($url_parts), 'url_builder', $language->language);

  igcommerce_utility_head_elements($term, TRUE);
    
  $form = array();
  $form_state['rebuild'] = TRUE;

  $form['keyword'] = array(
      '#type' => 'textfield',
      '#attributes' => array('placeholder' => t('Search')),
      '#default_value' => $training_library_keyword,
      //TODO: mig2315 - Manuals isn't pulling from solr like software downloads and other similar pages.
      '#prefix' => '<h1 class="search-title">' . t('Manuals') . '</h1>' .'<p>' . t('Please enter a product name or number to find your manual.') . '</p>' ,
      '#required' => TRUE,
      //'#description' => t('Can\'t find what you are looking for? Try using quotes (") around your search.'),
  );

  $form['search'] = array(
      '#type' => 'submit',
      '#value' => t('Search'),
  );

  if (!empty($manual_search_results)) {
    drupal_add_js(drupal_get_path('module', 'igcommerce_utility') . '/js/paginate.js');
    $form['results']['#markup'] = $manual_search_results;
  } 
  
  return $form;
}

/**
 * Submit handler for manuals search form
 * This submit callback shouldn't be called as keyword search handled through filter form
 */
function igcommerce_utility_manuals_form_search_submit($form, &$form_state) {
  global $training_library_keyword;
  $form_state['rebuild'] = TRUE;

  $training_library_keyword = $form_state['values']['keyword'];

  if (empty($training_library_keyword)) {
    return;
  }  
}

/**
 * Returns entities filtered by is_manual_type_tid terms
 * @param array $tids an array of term tids
 */
function igcommerce_utility_manuals_search_entities($tids, $bundle) {
  global $language;
  global $training_library_keyword;

  if (!$training_library_keyword) {
    $training_library_keyword = '';
  }
  $cache = &drupal_static(__FUNCTION__);
  $hash = md5(serialize($tids));
  if (!empty($cache[$bundle][$hash][$training_library_keyword])) {
    return $cache[$bundle][$hash][$training_library_keyword];
  }

  $filter = '[* TO *]';

  if (!empty($tids)) {
    $filter = '(' . implode(' AND ', $tids) . ')';
  }

  $filters = array(
      'entity_type' => 'node',
      'bundle' => $bundle,
      'ss_language' => $language->language,
      'bs_status' => TRUE, // only interested in published
      'is_field_manual_type_tid' => $filter,      
  );

  $options = array(
      'rows' => 200,
      'filters' => $filters,
      'sort' => 'ss_field_content_title asc',
  );

  if ($training_library_keyword) {
    $t = $training_library_keyword;
    $options['q'] = $t;
    unset($options['sort']);
    
    $options['params']['defType'] = 'edismax';
    
    // Add bias for specific fields for custom CJK fields.
    if (in_array($language->language, array('cn', 'ko-kr', 'ja-jp'))) {
      // Add qf params if required by language and add bias values
      $bias = array(
          'display_title_cjk' => 50,
          'body_cjk' => 1,
          'short_description_summary_cjk' => 1,
//          'h1_title_cjk' => 50,
//          'overview_cjk' =>40,
//          'compare_key_features_cjk' => 20,
//          'description_cjk' => 10,
      );

    } else {
        // Boost title fields as they are most important
        $bias = array(
            'tm_field_content_title' => 50,
            'ts_article_body' => 1,
            'tm_short_description_summary' => 1,
//          'tm_features' => 1,
//          'tm_overview' => 1,
//          'ts_description_field' => 1,
//          'tm_description_field' => 1,
        );

    }

    $qf = array();

    foreach ($bias as $field => $bias_value) {
      $qf[] = $field . '^' . $bias_value;
    }

    $qf = implode(' ', $qf);
    $qf = trim($qf);
    // Use pf here to boost instead of query these fields as it will return 0 results since these fields aren't in all bundles
    $options['params']['pf'] = $qf;
  }
  
  $query = fluke_solr_get_connection();
  $filters = fluke_solr_add_filters($query, $options);
  $response = fluke_solr_query($filters);

  $cache[$bundle][$hash][$training_library_keyword] = $response->response->docs;

  if (empty($response->response->docs[0])) {
    return;
  }

  $docs = $response->response->docs;
  
  foreach ($docs as $key => $doc) {
    if (empty($doc->ss_field_content_title) && empty($doc->tm_field_content_title[0])) {
      unset($docs[$key]);
    }
    if (empty($doc->url)) {
      unset($docs[$key]);
    }
  }
  
  return $docs;
}

function igcommerce_utility_manuals_get_filter_options($terms_available, $lang = 'en-us') {
  // Job Type
  $terms = _taxonomy_terms_load_by_vocabulary_solr('manual_type', $lang, 'dam');
  foreach ($terms as $term) {
    // don't continue if this isn't FIG
    if (!in_array('Fluke Industrial Group', $term->sm_term_parent_names)) {
      continue;
    }

    if (!in_array($term->entity_id, $terms_available)) {
      continue;
    }
    if (count($term->sm_term_parent_names) == 2) {
      $options['manual_type'][$term->entity_id] = $term->tm_field_display_title[0];
    }
  }

  asort($options['manual_type']);

  return $options;
}

/**
 * Submit callback to remove all filters on manuals search form
 */
function igcommerce_utility_manuals_form_filter_remove_filters(&$form, &$form_state) {
  // A little redundant, but just in case
  $form_state['rebuild'] = FALSE;
}

/**
 * Queries manuals with selected filters and returns available terms to use in filter form.
 * @param array $filters an array of tids to use to query manuals content
 */
function igcommerce_utility_manuals_get_terms_available($tids) {
  global $language;
  global $training_library_keyword;

  $filter = '[* TO *]';

  if (!empty($tids)) {
    $filter = '(' . implode(' AND ', $tids) . ')';
  }

  $filters['filters'] = array(
      'entity_type' => 'node',
      'bundle' => '(manual)',
      'ss_language' => $language->language,
      'bs_status' => TRUE, // only interested in published
      'is_field_manual_type_tid' => $filter,
  );

  $filters['fl'] = 'is_field_manual_type_tid';

  if (!empty($training_library_keyword)) {
    $t = $training_library_keyword;
    //$options['q'] = $t;
    $filters['q'] = "$t OR $t" . "* OR *" . $t . ' OR *' . $t . '*';
  }
  
  $filters['rows'] = 1000;
  $filters['sort'] = array('ds_created' => 'desc');
  
  $query = fluke_solr_get_connection();
  $filters = fluke_solr_add_filters($query, $filters);
  $response = fluke_solr_query($filters);

  if (empty($response->response->docs[0])) {
    return;
  }

  $docs = $response->response->docs;
  $return = array();

  foreach ($docs as $doc) {
    if (empty($doc->is_field_manual_type_tid)) {
      continue;
    }

    $tid = $doc->is_field_manual_type_tid;
    $return[$tid] = $tid;
  }

  return $return;
}

function igcommerce_utility_manuals_search_results_view($docs) {
  $items = array();
  global $language;
  global $training_library_keyword;
  global $search_filter_results;
  
  if (empty($docs)) {
    return '<p class="no-results">' . t('No search results available: ') . '<strong>' . $training_library_keyword . '</strong></p>';
  }
  
  // MIG-2042 Sort by Users manuals first 
  usort($docs, function ($a, $b) {
    global $language;
    $a_term = _taxonomy_term_load_solr($a->is_field_manual_type_tid, $language->language, 'dam');
    $b_term = _taxonomy_term_load_solr($b->is_field_manual_type_tid, $language->language, 'dam');
    $name = 'Users manual';
    if (empty($a->ss_field_content_title)) {
      return 1;
    }
    if (empty($b->ss_field_content_title)) {
      return -1;
    }
    
    $a_title = strtolower($a->ss_field_content_title);     
    $b_title = strtolower($b->ss_field_content_title);
    
    if ($a_term->label == $name && $b_term->label == $name) {
      if ($a_title == $b_title) {
        return 0;
      } else {
        return $a_title > $b_title ? 1 : -1;
      }
    }
    
    if ($a_term->label == $name && $b_term->label != $name) {
      return -1;
    }
    
    if ($b_term->label == $name && $a_term->label != $name) {
      return 1;
    }
       
    return $a_title > $b_title ? 1 : -1;
  });
  
  foreach ($docs as $doc) {
    $vars['doc'] = $doc;
    if (empty($doc->url)) {
      continue;
    }
    if (empty($doc->ss_field_content_title) && empty($doc->tm_field_content_title[0])) {
      continue;
    }
    
    $date = new DateTime($doc->ds_created);
    $term = _taxonomy_term_load_solr($doc->is_field_manual_type_tid, $language->language, 'dam');
    $tid = $doc->is_field_manual_type_tid;
    $type = str_replace('&#039;', '', $term->sm_field_display_title[0]);
    
    $title_text = !empty($doc->ss_field_content_title) ? $doc->ss_field_content_title : $doc->tm_field_content_title[0];
    $vars['title'] = l($title_text . ' | ' . $type, $doc->url, array('attributes' => array('class' => array('event-manuals'))));
    
    $desc = '';
    if (!empty($doc->ts_short_description_summary)) {
      $desc = $doc->ts_short_description_summary;
    }
    $vars['desc'] = $desc . '<div class="date-type">' . $date->format('m/Y') . ' | ' . $type . '</div>';
    
    //$items[] = theme('training_doc_list_item', $vars);
    if (!empty($doc->tm_manuals_and_supplement)) {
      $json = json_decode($doc->tm_manuals_and_supplement[0], TRUE);
      $supp = array_shift($json);

      if (!empty($supp['manual_file'])) {
        $vars['title'] = l($title_text . ' | ' . $type, $supp['manual_file'], array('attributes' => array('class' => array('event-manuals'))));
        //$vars['desc'] = '<div class="date-type">' . $date->format('m/Y') . ' | ' . $type . '</div>';
        $search_filter_results[$tid] = empty($search_filter_results[$tid]) ? 1 : $search_filter_results[$tid] + 1;
        
        $items[] = theme('training_doc_list_item', $vars);
      }
      
      if (!empty($supp['supplement_file'])) {
        $title_text = !empty($supp['supplement_title']) ? $supp['supplement_title'] : $title_text;
        $vars['title'] = l($title_text . ' | ' . $type . ' ' . t('supplement'), $supp['supplement_file']);
        $vars['desc'] = $desc . '<div class="date-type">' . $date->format('m/Y') . ' | ' . $type . ' ' . t('supplement') . '</div>';        
        $vars['desc'] = $supp['supplement_description'] . $vars['desc'];
        $search_filter_results[$tid] = empty($search_filter_results[$tid]) ? 1 : $search_filter_results[$tid] + 1;
        
        $items[] = theme('training_doc_list_item', $vars);      
      }
    }
    //tm_manuals_and_supplement
  }

  return theme('training_list_items', array('items' => $items));
}