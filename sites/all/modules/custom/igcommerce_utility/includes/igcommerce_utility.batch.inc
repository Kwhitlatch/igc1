<?php

/*
 * @file
 * Handle the batch process for creating url aliases.
 */

/**
 * Form builder function to allow choice of which batch to run.
 */
function igcommerce_utility_url_alias_fix_form() {
  $form['description'] = array(
    '#type' => 'markup',
    '#markup' => t('This batch job takes all the terms in URL Builder and makes URL Alias point to english version so that we can have TOC Pages render correctly for other locales.'),
  );
  $form['batch'] = array(
    '#type' => 'select',
    '#title' => 'Choose batch',
    '#options' => array(
      'toc' => t('Fix URL ALiases for TOC to point localized urls.'),
      'article' => t('Fix URL ALiases for Article to point localized urls.'),
      'products' => t('Fix URL ALiases for product to point localized urls.'),
      'support' => t('Fix URL ALiases for Support to point localized urls.'),
      'training' => t('Fix URL ALiases for Training to point localized urls.'),
      'solutions' => t('Fix URL ALiases for Solutions to point localized urls.'),
      'footer' => t('Fix URL ALiases for Footer to point localized urls.'),
      'compare' => t('Create path aliases for compare pages'),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Go',
  );
  return $form;
}

/**
 * Submit handler.
 *
 * @param array $form
 *   Form API form.
 * @param array $form_state
 *   Form API form.
 */
function igcommerce_utility_url_alias_fix_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['batch']) && $form_state['values']['batch'] == 'article') {
    // Fixing url aliase for localization for article content type.
    $function = 'igcommerce_utility_url_alias_fix_for_content_type_localization';
    $batch = $function($form_state['values']['batch']);
    batch_set($batch);
  }
  if (!empty($form_state['values']['batch']) && $form_state['values']['batch'] == 'toc') {
        // Fixing url aliase for localization for article content type.
        $function = 'igcommerce_utility_url_alias_fix_for_toc_content_type_localization';
        $batch = $function($form_state['values']['batch']);
        batch_set($batch);
  }elseif(!empty($form_state['values']['batch']) && $form_state['values']['batch'] == 'compare'){
    $batch = array(
      'operations' => array(
        ['igcommerce_utility_url_alias_fix_compare_pages', []],
      ),
      'finished' => 'igcommerce_utility_url_alias_batch_fix_finished',
      'title' => t('Batch fix'),
      'init_message' => t('Fix is starting...'),
      'progress_message' => t('Processed @current out of @total.'),
      'error_message' => t('Fix has encountered an error.'),
      'file' => drupal_get_path('module', 'igcommerce_utility') . '/includes/igcommerce_utility.batch.inc',
    );



    batch_set($batch);
    batch_process('admin/settings/batch_fix');

  } else {
    //$function = 'url_alias_fix_' . $form_state['values']['batch'];
    // Fixing the url for localization for "url builder" terms.
    $function = 'igcommerce_utility_url_alias_fix_for_category_localization';
    $batch = $function($form_state['values']['batch']);
    batch_set($batch);
  }
}

function igcommerce_utility_url_alias_fix_for_toc_content_type_localization($cursorMark = "*") {

    $batch = array(
        'operations' => array(),
        'finished' => 'igcommerce_utility_url_alias_batch_fix_finished',
        'title' => t('Batch fix'),
        'init_message' => t('Fix is starting...'),
        'progress_message' => t('Processed @current out of @total.'),
        'error_message' => t('Fix has encountered an error.'),
        'file' => drupal_get_path('module', 'igcommerce_utility') . '/includes/igcommerce_utility.batch.inc',
    );

//    $filters = array();
//    $max = 30; // max number of records to process in batches
//
//    $filters['filters'] = array(
//        'entity_type' => 'node',
//        //'bundle' => '(toc)', // only interested in articles or toc bundles
//        'bundle' => '(toc OR product_display OR article)', // only interested in articles or toc bundles or product displays
//        'ss_language' => 'en-us', // only interested to grab en-us first
//        //'bs_status' => TRUE, // only interested in published nodes
//    );
//
//    // Sorting by id as it is unique enough for this operation
//    $filters['sort'] = array('id' => 'asc');
//    $filters['rows'] = $max;
//    $filters['fl'] = 'path_alias,ss_path_alias,entity_id,bundle,entity_type,ss_language';
//    // We use 'cursorMark' to track which page we are on in the query
//    if(isset($cursorMark) && !empty($cursorMark)) {
//        $filters['cursorMark'] = $cursorMark;
//    }
//
//    // Check for updated nodes
//    if (!empty($settings['start'])) {
//        $date = $settings['start'];
//        $filters['filters']['ds_changed'] = '{' . $date . ' TO *}';
//    }
//
//    $query = fluke_solr_get_connection();
//    $query = fluke_solr_add_filters($query, $filters);
//    $response = fluke_solr_query($query);
//
//    $docs = $response->response->docs;
//    if(count($response->response->docs) > 0) {
//        // Get the cursoMark for the next request
//        $cursoMark = $response->nextCursorMark;
//    }
    $max = 30; // max number of records to process in batches

    $batch['operations'][] = array(
        'igcommerce_utility_save_update_alias_process', array(
            $max
        )
    );
    batch_set($batch);
    batch_process('admin/settings/batch_fix'); // The path to redirect to when done.
}

function igcommerce_utility_save_update_alias_process($max, &$context) {

    // Delete url_alias where source = ''
    db_query("DELETE FROM url_alias WHERE source = ''");

    $filters = array();
    $source = '';
    $path = '';
    // Sorting by id as it is unique enough for this operation
    $filters['q'] = 'entity_type:node AND bs_status:1 AND bundle:("toc" OR "product_display" OR "article") AND ss_language:en-us';
    $filters['fl'] = 'path_alias,ss_path_alias,entity_id,bundle,entity_type,ss_language';
    $filters['rows'] = $max;
    $filters['sort'] = "id asc";
    // We use 'cursorMark' to track which page we are on in the query
    $filters['cursorMark'] = "*";

    $query = fluke_solr_get_connection();
    $query = fluke_solr_add_filters($query, $filters);
    $response = fluke_solr_query($query);

    $docs = $response->response->docs;

    $page = 0;
    while(count($docs) > 0) {
        // Get the cursorMark for the next request
        $cursorMark = $response->nextCursorMark;
        foreach ($docs as $doc) {
            // These are all published so make sure there are path aliases
            // Get translated entities
            $entities = igcommerce_utility_get_entity_translations($doc->entity_type, $doc->bundle, $doc->entity_id);

            // TO DO: I am doing this here because TOCs switched translated url to ss_path_alias while the rest are different
            if ($doc->bundle == 'toc' || $doc->ss_language == 'en_us') {
                $source = isset($doc->path_alias) ? $doc->path_alias : '';
            } else {
                $source = isset($doc->ss_path_alias) ? $doc->ss_path_alias : '';
            }
            // Log content with empty sources
            if (empty(trim($source))) {
                watchdog('Module',
                    "No source found for: Entity_id:%eid | Bundle:%bundle | Type:%entity_type | Lang:%lang",
                    array('%eid' => $doc->entity_id, '%bundle' => $doc->bundle, '%entity_type' => $doc->entity_type, '%lang' => $doc->ss_language),
                    WATCHDOG_NOTICE
                );
            }
            if (!empty(trim($source))) {

                // Loop through each translated entity and ensure that there is a path alias
                foreach ($entities as $entity) {
                    if ($entity->ss_language == 'en-us') {
                        continue; // skip en-us
                    }
                    if (isset($entity->path_alias)) {

                        // This is the alias that should be in IGC
                        if ($entity->bundle == 'toc') {
                            $path = $entity->ss_path_alias;
                        } else {
                            $path = $entity->path_alias;
                        }

                        // Delete alias if this entity isn't published
                        if (!$entity->bs_status) {
                            $criteria = array('source' => $path, 'language' => $entity->ss_language);
                            path_delete($criteria);
                            continue;
                        }

                        // Create alias for each level of url for each translated local

                        // Skip if it doesn't appear to be translated
                        if ($path == $source) {
                            continue;
                        }

                        $local_path = explode('/', $path);
                        $source_path = explode('/', $source);

                        if (isset($local_path[0]) && isset($source_path[0])) {
                            igcommerce_utility_save_update_alias_commit(
                                $source_path[0],
                                $local_path[0],
                                $entity->ss_language);

                        }
                        if (isset($local_path[1]) && isset($source_path[1])) {
                            igcommerce_utility_save_update_alias_commit(
                                $source_path[0] . '/' . $source_path[1],
                                $local_path[0] . '/' . $local_path[1],
                                $entity->ss_language
                            );
                        }
                        if (isset($local_path[2]) && isset($source_path[2])) {
                            igcommerce_utility_save_update_alias_commit(
                                $source_path[0] . '/' . $source_path[1] . '/' . $source_path[2],
                                $local_path[0] . '/' . $local_path[1] . '/' . $local_path[2],
                                $entity->ss_language);
                        }
                        if (isset($local_path[3]) && isset($source_path[3])) {
                            igcommerce_utility_save_update_alias_commit(
                                $source_path[0] . '/' . $source_path[1] . '/' . $source_path[2] . '/' . $source_path[3],
                                $local_path[0] . '/' . $local_path[1] . '/' . $local_path[2] . '/' . $local_path[3],
                                $entity->ss_language);
                        }
                        if (isset($local_path[4]) && isset($source_path[4])) {
                            igcommerce_utility_save_update_alias_commit(
                                $source_path[0] . '/' . $source_path[1] . '/' . $source_path[2] . '/' . $source_path[3] . '/' . $source_path[4],
                                $local_path[0] . '/' . $local_path[1] . '/' . $local_path[2] . '/' . $local_path[3] . '/' . $local_path[4],
                                $entity->ss_language);
                        }
                        if (isset($local_path[5]) && isset($source_path[5])) {
                            igcommerce_utility_save_update_alias_commit(
                                $source_path[0] . '/' . $source_path[1] . '/' . $source_path[2] . '/' . $source_path[3] . '/' . $source_path[4] . '/' . $source_path[5],
                                $local_path[0] . '/' . $local_path[1] . '/' . $local_path[2] . '/' . $local_path[3] . '/' . $local_path[4] . '/' . $local_path[5],
                                $entity->ss_language);
                        }
                        if (isset($local_path[6]) && isset($source_path[6])) {
                            igcommerce_utility_save_update_alias_commit(
                                $source_path[0] . '/' . $source_path[1] . '/' . $source_path[2] . '/' . $source_path[3] . '/' . $source_path[4] . '/' . $source_path[5] . '/' . $source_path[6],
                                $local_path[0] . '/' . $local_path[1] . '/' . $local_path[2] . '/' . $local_path[3] . '/' . $local_path[4] . '/' . $local_path[5] . '/' . $local_path[6],
                                $entity->ss_language);
                        }
                    }
                    $message = 'page: ' .$page.' | source: '.$source.' | Local: '. $entity->ss_language .' | '. $path;
                    $context['message'] = "Now processing $message...";
                    watchdog('Path_alias',
                        "Running Page: %page | source:%source | Local:%local_path",
                        array('%page' => $page, '%source' => $source, '%local_path' => $path)
                    );
                }
            }

        }
        // We run this query again with the next cursormarker pointer
        // Sorting by id as it is unique enough for this operation
        // We use 'cursorMark' to track which page we are on in the query
        $filters['q'] = 'entity_type:node AND bs_status:1 AND bundle:("toc" OR "product_display" OR "article") AND ss_language:en-us';
        $filters['fl'] = 'path_alias,ss_path_alias,entity_id,bundle,entity_type,ss_language';
        $filters['rows'] = $max;
        $filters['sort'] = "id asc";
        $filters['cursorMark'] = $cursorMark;

        $query = fluke_solr_get_connection();
        $query = fluke_solr_add_filters($query, $filters);
        $response = fluke_solr_query($query);
        $docs = $response->response->docs;
        $page++;
    }
}

// Process path alias
function igcommerce_utility_save_update_alias_commit($source, $local_path, $lang) {

    // Check if an alias exists
    $conditions = array('source' => $source, 'language' => $lang);
    if(!$alias = path_load($conditions)) {
        // Doesn't exist, so add the alias
        $alias = array('source' => $source, 'alias' => $local_path, 'language' => $lang);
        path_save($alias);
    } else {
        // Ensure the IGC alias here matches $path
        if ($alias['alias'] != $local_path) {
            // Not a match, so update the local alias
            $alias['alias'] = $local_path;
            path_save($alias);
        }
    }
}

/**
 * Batch 1 definition: Load the node with the lowest nid 1000 times.
 *
 * This creates an operations array defining what batch 1 should do, including
 * what it should do when it's finished. In this case, each operation is the
 * same and by chance even has the same $nid to operate on, but we could have
 * a mix of different types of operations in the operations array.
 */
function igcommerce_utility_url_alias_fix_for_category_localization($param) {
  $batch = array(
    'operations' => array(),
    'finished' => 'url_alias_batch_fix_finished',
    'title' => t('Batch fix'),
    'init_message' => t('Fix is starting...'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Fix has encountered an error.'),
    'file' => drupal_get_path('module', 'igcommerce_utility') . '/includes/igcommerce_utility.batch.inc',
  );

  $results = array();
  global $language;
  //set skip_term  value true if parameter is footer
  //reason to skip : uncessary alias is creating ,as there is no need to create alias for Footer,Site Map, Saftey notices
  // Footer : There is no page
  //Saftey notices : pointing to support page. Aleardy aliases is created when you run Support Bacth process
  //Site Map : No page linked to this Menu

  if ($param == 'footer') {
    $skip_term = TRUE;
  }
  else {
    $skip_term = FALSE;
  }
  $menu_terms = taxonomy_get_term_by_name($param, 'url_builder');
  $menu_term = current($menu_terms);

  $parents_only = _igcommerce_parents_only($menu_term, $skip_term);
  $results = $parents_only;

  $vocab = taxonomy_vocabulary_machine_name_load('url_builder');
  $terms = taxonomy_get_tree($vocab->vid, $menu_term->tid, 1, TRUE); // Use the correct vocabulary id.
  foreach ($terms as $menu_item) {
    $parent_child_only = _igcommerce_parent_child_only($menu_item, $skip_term);
    if (count($parent_child_only) > 0) {
      $results += $parent_child_only;
    }
    $parent_child_subchild_only = _igcommerce_parent_child_subchild_only($menu_item, $skip_term);
    if (count($parent_child_subchild_only) > 0) {
      $results += $parent_child_subchild_only;
    }
  }

  foreach ($results as $result) {
    if (isset($result['en']) || isset($result['en-us'])) {
      // Check if we have english translation available for en or en-us.
      if (!empty($result['en-us'])) {
        $source = $result['en-us'];
      }
      elseif (!empty($result['en'])) {
        $source = $result['en'];
      }
      $batch['operations'][] = array('igcommerce_utility_url_alias_batch_fix_process', array($result, $source));
    }
  }
  batch_set($batch);
  batch_process('admin/settings/batch_fix'); // The path to redirect to when done.
}

/*
 * Handle the content type url aliase fixing having different local language
 * point to english languge, so that all article popup would work because its
 * point to english panel page.Making entry in url alias to work ecm article
 * content in igcommerce.
 */

function igcommerce_utility_url_alias_fix_for_content_type_localization() {
  $batch = array(
    'operations' => array(),
    'finished' => 'igcommerce_utility_url_alias_batch_fix_finished',
    'title' => t('Batch fix'),
    'init_message' => t('Fix is starting...'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Fix has encountered an error.'),
    'file' => drupal_get_path('module', 'igcommerce_utility') . '/includes/igcommerce_utility.batch.inc',
  );

  $result = array();

  // Query to fetch article data havinng article type "Press Release",
  // "Software Download" , "safety Notice", "News", "Web card".
  $keyword = "entity_type:node";
  $parameter[]['rows'] = '100000';
  $parameter[]['fl'] = 'path_alias';
  $parameter[]['fl'] = 'ss_language';
  $parameter[]['fl'] = 'entity_id';
  $filter[]['bundle'] = 'article';
  //$filter[]['entity_id'] = '5385';
  // Need to add following filter onces all article page havce proper "article type" selected.
  //$filter[]['sm_vid_Article'] = '("Web Cards" OR "Software Downloads" OR "Safety Notices" OR "News" OR "Press Releases")';

  $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);
  $result = $data->response->docs;

  $data_result = array();
  foreach ($result as $key => $data_value) {
    $data_result[$data_value->entity_id][$data_value->ss_language] = array('path_alias' => $data_value->path_alias);
  }

  // Processing data for creating url of different language pointing to english.
  if (!empty($data_result)) {
    foreach ($data_result as $key => $value) {
      if (isset($value['en']) || isset($value['en-us'])) {
        // Check if we have english translation available for en or en-us.
        if (!empty($value['en-us'])) {
          $source = $value['en-us'];
        }
        elseif (!empty($value['en'])) {
          $source = $value['en'];
        }
        $batch['operations'][] = array('igcommerce_utility_url_alias_batch_fix_process', array($value, $source));
      }
    }
  }
  batch_set($batch);
  batch_process('admin/settings/batch_fix'); // The path to redirect to when done.
}

/**
 * The batch processor.
 */
function igcommerce_utility_url_alias_batch_fix_process($word, $source, &$context) {
  //watchdog("debug", 'Values are  <pre>' . print_r( $word, true) . '</pre>');

  $link_source = array();
  module_load_include('inc', 'pathauto');
  if (!empty($word['en-us'])) {
    $link_source = implode('/', $word['en-us']);
  }
  elseif (!empty($word['en'])) {
    $link_source = implode('/', $word['en']);
  }

  $source = rtrim($link_source, '/');
  foreach ($word as $locale => $values) {
    if ($values['path_alias']) {
      // This is done for article content type.
      $destination = $values['path_alias'];
    }
    else {
      // This done for url builder term.
      $link_dest = implode('/', $values);
      $destination = rtrim($link_dest, '/');
    }

    if (!empty($source) && !empty($destination)) {
      // Checking url alias having valid node or not.
      //If alias have valid url, then don't created non-us local alias.
      $source_path = drupal_lookup_path("source", $source, 'en-us');
      $source_node = menu_get_object('node', 1, $source_path);
      if (empty($source_node->nid)) {
        // Build the new path alias array and send it off to be created.
        $path = array(
          'source' => $source,
          'alias' => $destination,
          'language' => $locale,
        );

        $existing_alias = _pathauto_existing_alias_data($source, $locale);

        if (!empty($existing_alias)) {
          // If alias is updated then update table with new alias.
          if ($destination !== $existing_alias['alias']) {

            $pid = $existing_alias['pid'];

            if (!empty($pid)) {
              $alias_update = db_update('url_alias')
                  ->fields(array('alias' => $destination, ))
                  ->condition('pid', $pid, '=')
                  ->execute();
            }
          }
        }
        else {
          if ($source !== $destination) {
            path_save($path);
          }
        }
      }
    }
    $context['message'] = "Now processing $destination...";
  }
}

/**
 * The batch finish handler.
 */
function igcommerce_utility_url_alias_batch_fix_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message(t('Fix is complete!'));
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE)
    ));
    drupal_set_message($message, 'error');
  }
}

/*
 * Collect parent terms for provided url builder taxonomy.
 */

function _igcommerce_parents_only($terms, $skip_term = FALSE) {
  $parent_data = array();
  // Get the term name which all we want skip. Applicable to Footer and it categories term
  $termname_list = variable_get('igonore_term_names');
  $termname_list_arr = explode(',', $termname_list);
  foreach ($terms->field_url_title as $locale => $term_data) {
    if (in_array($terms->name, $termname_list_arr) && ($skip_term == 1)) {
      continue;
    }
    else {
      if ($locale !== 'und') {
        $parent_data[$terms->tid][$locale]['parent'] = $term_data[0]['safe_value'];
        $parent_data[$terms->tid][$locale]['child'] = "";
        $parent_data[$terms->tid][$locale]['subchild'] = "";
      }
    }
  }
  return $parent_data;
}

/*
 * Collect parent and child terms for provided url builder taxonomy.
 */

function _igcommerce_parent_child_only($menu_item, $skip_term = FALSE) {
  global $language;
  $lang = $language->language;
  $parent_child = array();
  $parents = array_reverse(taxonomy_get_parents_all($menu_item->tid));
  array_pop($parents);
  array_shift($parents);
  // Get the term name which all we want skip. Applicable to Footer and it categories term
  $termname_list = variable_get('igonore_term_names');
  $termname_list_arr = explode(',', $termname_list);
  foreach ($menu_item->field_url_title as $locale => $values) {
    // check if term found in array and $skip_term set to True
    if (in_array($menu_item->name, $termname_list_arr) && ($skip_term == 1)) {
      continue;
    }
    else {
      if ($locale !== 'und') {
        //For Footer Categories Term set parent as 'site' Else for take Parent what it is set.
        // site word will remain in english for Language Locale
        if ($skip_term == 1) {
          $parent_child[$menu_item->tid][$locale]['parent'] = 'site';
        }
        else {
          $parent_child[$menu_item->tid][$locale]['parent'] = $parents[0]->field_url_title[$locale][0]['safe_value'];
        }
        $parent_child[$menu_item->tid][$locale]['child'] = $menu_item->field_url_title[$locale][0]['safe_value'];
        $parent_child[$menu_item->tid][$locale]['subchild'] = '';
      }
    }
  }

  return $parent_child;
}

/*
 * Collect parent and child and there subchild terms for provided url builder
 * taxonomy.
 */

function _igcommerce_parent_child_subchild_only($menu_item, $skip_term = FALSE) {
  $parent_child_subchild = array();
  $children = taxonomy_get_children($menu_item->tid);
  $parents = array_reverse(taxonomy_get_parents_all($menu_item->tid));
  array_pop($parents);
  array_shift($parents);
  // Get the term name which all we want skip. Applicable to Footer and it categories term
  $termname_list = variable_get('igonore_term_names');
  $termname_list_arr = explode(',', $termname_list);
  if (sizeof($children) > 0) {
    foreach ($children as $k => $v) {

      foreach ($v->field_url_title as $locale => $values) {
        // check if term found in array and $skip_term set to True
        if (in_array($menu_item->name, $termname_list_arr) && ($skip_term == 1)) {
          continue;
        }
        else {
          if ($locale !== 'und') {
            //For Footer Categories Term set parent as 'site' Else for take Parent what it is set.
            // site word will remain in english for Language Locale
            if ($skip_term == 1) {
              $parent_child_subchild[$v->tid][$locale]['parent'] = 'site';
            }
            else {
              $parent_child_subchild[$v->tid][$locale]['parent'] = $parents[0]->field_url_title[$locale][0]['safe_value'];
            }
            $parent_child_subchild[$v->tid][$locale]['child'] = $menu_item->field_url_title[$locale][0]['safe_value'];
            $parent_child_subchild[$v->tid][$locale]['subchild'] = $values[0]['safe_value'];
          }
        }
      }
    }
  }
  return $parent_child_subchild;
}


function igcommerce_utility_url_alias_fix_compare_pages(&$context){
  if(empty($context['sandbox']['tocs'])){
    // Query for TOCs with products assigned

    $filters['filters'] = array(
      //'ss_language' => 'en-us',  //@todo: remove this filter when we are ready to do other langauges.
      'bundle' => 'toc',
      'entity_type' => 'node',
      'sm_field_product_list_sort_solr' => "['' TO *]"
    );

    $filters['rows'] = 4000;

    $query = fluke_solr_get_connection();
    $query = fluke_solr_add_filters($query, $filters);
    $data = fluke_solr_query($query);

    $context['sandbox']['tocs'] = $data->response->docs;
    $context['finished'] = 1;
    $context['sandbox']['total'] = count($data->response->docs);
  }

  // Check each toc for products that are marked as available for comparison.
  for($x = 0; $x <= 50; $x ++) {
    if (count($context['sandbox']['tocs'])) {
      $toc = array_pop($context['sandbox']['tocs']);
    } else {
      break;
    }

    $products = igc_compare_fetch_products($toc);
    $comparable = FALSE;
    foreach ($products as $product) {
      if ($product->bs_available_for_comparison) {
        $comparable = TRUE;
        break;
      }
    }

    //The toc, has products for comparison, create a path alias in the language locale.
    if ($comparable) {
      $alias = $toc->ss_path_alias_locale . '/' . t('compare');
      $source = 'products/pages/compare';
      $lang = $toc->ss_language;

      if(igc_compare_lang_check($lang)) {
        // create the alias, if it doesn't already exist
        // don't use igcommerce_utility_save_update_alias_commit because we use the same source for all our paths, and it won't work
        // Check if an alias exists

        $conditions = array('language' => $lang, 'alias' => $alias);

        if (!$path = path_load($conditions)) {
          $path = array('source' => $source, 'alias' => $alias, 'language' => $lang);
          path_save($path);
        } else {
          if ($path['source'] != $source) {

            $path['source'] = $source;
            path_save($path);
          }
        }
      }
    }
  }

  if(count($context['sandbox']['tocs'])) {
    $context['finished'] = ($context['sandbox']['total'] - count($context['sandbox']['tocs'])) / $context['sandbox']['total'];
  }else{
    $context['finished'] = 1;
  }
}
