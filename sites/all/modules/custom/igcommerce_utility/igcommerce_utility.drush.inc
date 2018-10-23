<?php

/**
 * Implements hook_drush_command.
 * @return mixed
 */
function igcommerce_utility_drush_command() {
  $commands['igcommerce-utility-cache-taxonomy'] = [
    'description' => t('Cache taxonomy vocab stat from Solr. '),
    'aliases' => ['iuct'],
  ];

  return $commands;
}

function drush_igcommerce_utility_cache_taxonomy() {
  $updated_count = 0;
  // Cache taxonomy vocabs in cache_igcommerce so we don't have to query Solr every time we need a term.
  $language_list = array(
    'en-us', 'en-au', 'es-es', 'fi-fi', 'fr-fr', 'id-id', 'it-it', 'ja-jp', 'ko-kr', 'nl-nl', 'no-no','pl-pl', 'pt-br', 'pt-pt', 'ru-ru', 'sv-se',
    'th-th', 'tr-tr', 'vi-vn', 'cn', 'cs-cz', 'da-dk', 'de-de', 'en', 'en-ca', 'en-gb', 'en-id', 'en-ie', 'en-in', 'en-my', 'en-ph',
    'en-sg', 'en-th', 'en-tt', 'en-vn', 'es-mx', 'zh-tw', 'zh-cn', 'ar', 'bn', 'el', 'he', 'hi', 'hu', 'kn', 'lt', 'lv', 'ml', 'ms', 'ro', 'sk',
    'sl', 'ta', 'et', 'es-mx', 'es-ar', 'es-bo', 'es-cl', 'es-co', 'es-cr', 'es-do', 'es-ec', 'es-gt', 'es-pe', 'es-sv', 'es-uy', 'es-ve', 'es-us',
    'de-de', 'de-at', 'de-ch', 'nl-nl','nl-be', 'fr-fr', 'fr', 'fr-be', 'fr-ca', 'fr-ch');
  
  $taxonomy_machine_names = array(
    'url_builder' => 'ecm',
    'manual_type' => 'dam',
    'document_type' => 'dam',
    'software' => 'ecm',
    'product_category' => 'ecm',
    'product_category' => 'dam',
    'cta_buttons' => 'ecm',
    'job_type' => 'dam',
    'applications_for_training' => 'dam',
    'industries_for_training' => 'dam',
    'measurements_for_training' => 'dam',
    'pain_points_for_training' => 'dam',
    'solutions_for_training' => 'dam',
  );

  foreach($language_list as $lang) {
    // Get vocab data for each vocab.
    foreach ($taxonomy_machine_names as $vocab => $env) {
      $filters['filters'] = array(
        'entity_type' => 'taxonomy_term',
        'ss_language' => $lang,
        'bundle' => $vocab,
        'ss_env_id' => $env,
      );
      
      $filters['rows'] = 300;
      $query = fluke_solr_get_connection();
      $query2 = fluke_solr_add_filters($query, $filters);
      $response = fluke_solr_query($query2);
      
      $terms = [];
      if (isset($response->response->docs) && count($response->response->docs) > 0) {
        foreach($response->response->docs as $doc) {
          $terms[] = $doc;
        }
        // Store the data in the cache table.
        $cache_id = 'taxonomy_' . $vocab . '_' . $lang . '_'. $env;
        cache_set($cache_id, $terms, 'cache_igcommerce', time() + 86400);
        $updated_count++;
        drush_print('Cached record for ' . $cache_id .  format_plural($updated_count, ' 1 cache record updated', ' @count cache records updated'));
      }
    }
  }
  drush_print('Cache updating completed, ' . format_plural($updated_count,'1 record cached', '@count records cached'));
}

