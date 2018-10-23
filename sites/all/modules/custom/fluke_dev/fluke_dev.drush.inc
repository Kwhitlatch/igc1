<?php

/**
 * Implementation of hook_drush_command
 *
 * @return mixed
 */
function fluke_dev_drush_command() {
  $commands['fluke-dev-replace-301-dest'] = [
    'description' => t('Replace records in Solr with new dest value.'),
    'aliases' => ['fdr3d'],
    'arguments' => [
      'source' => 'The solr field to query'
    ],
    'options' => [
      'limit' => 'The number of values to query',
    ],
  ];

  $commands['fluke-dev-delete-301'] = [
    'description' => t('Delete 301 records in Solr.'),
    'aliases' => ['fdd3'],
    'arguments' => [
      'field' => 'Specifies whether to use src or dest to search for records.'
    ],
    'options' => [
      'id' => 'The Solr record id to delete',
      'value' => 'The query value to use when looking for records'
    ],
  ];
  
  $commands['fluke-dev-301-report'] = [
    'description' => t('Generate list of src, dest, and id values for a specific list of redirects. Uses 301_report table'),
    'aliases' => ['fd3r'],
    'options' => [
      'limit' => 'A limit on how many records to get',
    ],
  ];
  
  $commands['301-add'] = [
    'description' => t('Add a new redirect to the Solr index.'),
    'aliases' => ['301add'],
    'arguments' => [
      'src' => 'The source URL',
      'dest' => 'The destination URL'
    ],
    'options' => [
      'encode' => 'Whether to URL encode the src. Enter "y".'
    ],
    'required-arguments' => TRUE,
  ];
  
  $commands['301-update-dest'] = [
    'description' => t('Update the destination for a given source URL'),
    'aliases' => ['301update'],
    'arguments' => [
      'dest' => 'The new destination URL',
      'type' => 'The type of value used for identifying the record - src or id'
    ],
    'options' => [
      'value' => 'The value to use for identifying the record.',
      'encode' => 'Whether to URL encode the src. Enter "y".'
    ],
    'required-arguments' => TRUE,
  ];
  
  $commands['301-delete'] = [
    'description' => t('Delete a redirect using the Solr recortd id.'),
    'aliases' => ['301delete'],
    'arguments' => [
      'id' => 'The Solr record ID',
    ],
    'required-arguments' => TRUE,
  ];

  $commands['301-find-duplicates'] = [
    'description' => t('Delete a redirect using the Solr recortd id.'),
    'aliases' => ['301duplicates'],
    'options' => [
      'pages' => 'The number of pages to query from Solr',
      'id' => 'A unique Solr id'
    ]
  ];
  
  return $commands;
}

/**
 * Query Solr to validate that what's in solr is what we expect
 */
function drush_fluke_dev_replace_301_dest($source) {
  $updated_count = 0;
  $not_found_count = 0;
  $null_count = 0;
  
  $limit = drush_get_option('limit', NULL);
  
  $query = db_select('301_validate', 'v');
  $query->fields('v', array('old', 'new'));
  if ($limit) {
    $query->range(0, $limit);
  }
  $result = $query->execute();
  
  foreach($result as $record) {
    // Query solr to see if record exists.
    switch ($source) {
      case 'src':
        $old = preg_replace('/^https:\/\//', '', $record->old);
        $old = urlencode($old);
  
        $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=src&fq=src:" . $old . "&q=*:*&wt=json";
        
        break;
      case 'id':
        //$url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=idfq=id:" . $record->old . "&q=*:*&wt=json";
        $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=id&q=id:" . $record->old . "&wt=json";
  
        break;
    }

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    $dest = json_decode(curl_exec($ch));
    curl_close($ch);
  
    if (isset($dest) && isset($dest->response) && isset($dest->response->numFound) && $dest->response->numFound > 0) {
      // There could be more than one doc, so we have to update each one.
      foreach($dest->response->docs as $doc) {
        // Get the record id
        $id = $doc->id;
        // Update the record.
        $data = array(
          'id' => $id,
          'dest' => array(
            'set' => $record->new
          )
        );
        $data_string = json_encode(array($data));
        $update_url = 'https://fluke2xl-replica3.solrcluster.com/solr/301/update?commit=true';
        $update_ch = curl_init($update_url);
        curl_setopt($update_ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($update_ch, CURLOPT_POST, 1);
        curl_setopt($update_ch, CURLOPT_HTTPHEADER, array('Content-type: application/json'));
        curl_setopt($update_ch, CURLOPT_POSTFIELDS, $data_string);
        $update_response = json_decode(curl_exec($update_ch));
        curl_close($update_ch);
        $updated_count++;
        drush_print('src ' . $doc->src . ' updated with new dest ' . $record->new);
      }
    }
    elseif (is_null($dest)) {
      $null_count++;
      drush_print('dest of ' . $record->old . ' returned NULL');
    }
    else {
      $not_found_count++;
      drush_print('No match found for dest ' . $record->old);
    }
  }
  drush_print(format_plural($updated_count, '1 dest record updated', '@count dest records updated'));
  drush_print(format_plural($not_found_count, '1 record not found', '@count records not found'));
  drush_print(format_plural($null_count, '1 record returned NULL', '@count records returned NULL'));
}

/**
 * Delete specified solr records from 301 index.
 *
 * @param src
 *   The source URL to search for.
 */
function drush_fluke_dev_delete_301($field) {
  $updated_count = 0;
  $id_option = drush_get_option('id', NULL);
  $value = drush_get_option('value', NULL);
  $solr = new DrupalApacheSolrService('https://fluke2xl-replica3.solrcluster.com/solr/301');
  
  if ($value) {
    $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=" . $field . "&fq=" . $field . ":" . $value . "&q=*:*&wt=json&rows=500";
  
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    $dest = json_decode(curl_exec($ch));
    curl_close($ch);
  
    if (isset($dest) && isset($dest->response) && isset($dest->response->numFound) && $dest->response->numFound > 0) {
      // There could be more than one doc, so we have to update each one.
      foreach ($dest->response->docs as $doc) {
        // Get the record id
        $id = $doc->id;
        // Delete the record
        $delete = $solr->deleteById($id);
        if ($delete->code == 200) {
          drush_print('ID ' . $id . ' , src = ' . $doc->src . ' successfully deleted');
          $updated_count++;
        }
      }
    }
  }
  else {
    if (!$id_option) {
      // Get the records from the 301_delete table.
      $query = db_select('301_delete', 'd');
      $query->fields('v', array('url'));
      $result = $query->execute();
    
      foreach ($result as $record) {
        // Get all of the Solr records that match the specified url
        $url = urlencode($record->url);
      
        $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=" . $field . "&fq=" . $field . ":" . $url . "&q=*:*&wt=json";
      
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        $dest = json_decode(curl_exec($ch));
        curl_close($ch);
      
        if (isset($dest) && isset($dest->response) && isset($dest->response->numFound) && $dest->response->numFound > 0) {
          // There could be more than one doc, so we have to update each one.
          foreach ($dest->response->docs as $doc) {
            // Get the record id
            $id = $doc->id;
            // Delete the record
            $delete = $solr->deleteById($id);
            if ($delete->code == 200) {
              drush_print('ID ' . $id . ', src = ' . $doc->src . ' successfully deleted');
              $updated_count++;
            }
          }
        }
      }
    }
    else {
      // We have an id value, so use that.
      $delete = $solr->deleteById($id_option);
      if ($delete->code == 200) {
        drush_print('ID ' . $id_option . ' successfully deleted');
        $updated_count++;
      }
    }
  }
  drush_print(format_plural($updated_count, '1 record deleted', '@count records deleted'));
}

/**
 * Get details from Solr for given src value.
 */
function drush_fluke_dev_301_report() {
  $updated_count = 0;
  
  $file_path = '/Users/SEDWARD1/Documents/301/301_report.csv';
  $handle = fopen($file_path, 'r');
  while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
    $url = urlencode($data[0]);
  /*  $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=src&fq=src:" . $url . "&q=*:*&wt=json"; */
    $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=src&q=" . $url . "&wt=json";
  
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    $dest = json_decode(curl_exec($ch));
    curl_close($ch);
  
    if (isset($dest) && isset($dest->response) && isset($dest->response->numFound) && $dest->response->numFound > 0) {
      // There could be more than one doc, so we have to update each one.
      foreach ($dest->response->docs as $doc) {
        db_insert('301_report')
          ->fields(array(
            'src' => $doc->src,
            'dest' => $doc->dest,
            'id' => $doc->id,
          ))
          ->execute();
        $updated_count++;
        drush_print('src of ' . $data[0] . ' updated with dest ' . $doc->dest);
      }
    }
    else {
      db_insert('301_report')
        ->fields(array(
          'src' => $data[0]
        ))
        ->execute();
      drush_print('src ' . $data[0] . ' not found in Solr');
    }
  }
  drush_print(format_plural($updated_count, '1 report record updated', '@count report records updated'));
}

/*************************************************************************************
 * Simple utilities for QA to use for CRUD operations on 301 redirects stored in Solr.
 *************************************************************************************/

/**
 * Add a new redirect record to Solr
 */
function drush_fluke_dev_301_add($src, $dest) {
  $encode = drush_get_option('encode', NULL);
  
  $src = preg_replace('/^https:\/\//', '', $src);
  if ($encode) {
    $src = urlencode($src);
  }
  
  // We first check to see if a record exists for this src.
  $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=src&q=" . $src . "&wt=json";
  
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $url);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  $result = json_decode(curl_exec($ch));
  curl_close($ch);
  
  if (isset($result) && isset($result->response) && isset($result->response->numFound) && $result->response->numFound > 0) {
    drush_set_error("Existing record(s) found", "There are existing records for this src: " . $src);
    foreach($result->response->docs as $doc) {
      drush_print('id: ' . $doc->id . ', dest: ' . $doc->dest);
    }
  }
  else {
    // No record exists, so add record.
    $data = array(
      "add" => array(
        "doc" => array(
          "src" => $src,
          "dest" => $dest
        ),
      ),
    );
  
    $data_string = json_encode($data);
    $add_url = 'https://fluke2xl-replica3.solrcluster.com/solr/301/update?commit=true&wt=json';
    $add_ch = curl_init($add_url);
    curl_setopt($add_ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($add_ch, CURLOPT_POST, 1);
    curl_setopt($add_ch, CURLOPT_HTTPHEADER, array('Content-type: application/json'));
    curl_setopt($add_ch, CURLOPT_POSTFIELDS, $data_string);
    $add_response = json_decode(curl_exec($add_ch));
    curl_close($add_ch);
  
    if (isset($add_response->responseHeader)) {
      drush_print('New record with src = ' . $src . ' and dest = ' . $dest . ' successfully added');
    }
    else {
      drush_print('There was an error adding the record to Solr');
    }
  }
}

/**
 * Update the destination for an existing redirect in Solr.
 */
function drush_fluke_dev_301_update_dest($dest, $type) {
  $value = drush_get_option('value', NULL);
  $encode = drush_get_option('encode', NULL);
  
  if (!$value) {
    drush_die('The value option is required');
  }
  
  // Query solr to see if record exists.
  switch ($type) {
    case 'src':
      $old = preg_replace('/^https:\/\//', '', $value);
      if ($encode) {
        $old = urlencode($old);
      }
      
      $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=src&q=" . $old . "&wt=json";
      
      break;
    case 'id':
      $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=id&q=id:" . $value . "&wt=json";
      
      break;
  }
  
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $url);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  $search_response = json_decode(curl_exec($ch));
  curl_close($ch);
  
  if (isset($search_response) && isset($search_response->response) && isset($search_response->response->numFound) && $search_response->response->numFound > 0) {
    // There could be more than one doc, so we have to update each one.
    foreach($search_response->response->docs as $doc) {
      // Get the record id
      $id = $doc->id;
      // Update the record.
      $data = array(
        'id' => $id,
        'dest' => array(
          'set' => $dest
        )
      );
      $data_string = json_encode(array($data));
      $update_url = 'https://fluke2xl-replica3.solrcluster.com/solr/301/update?commit=true';
      $update_ch = curl_init($update_url);
      curl_setopt($update_ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($update_ch, CURLOPT_POST, 1);
      curl_setopt($update_ch, CURLOPT_HTTPHEADER, array('Content-type: application/json'));
      curl_setopt($update_ch, CURLOPT_POSTFIELDS, $data_string);
      $update_response = json_decode(curl_exec($update_ch));
      curl_close($update_ch);
      
      if (isset($update_response->responseHeader) && $update_response->responseHeader->status == 0) {
        drush_print('src ' . $doc->src . ' updated with new dest ' . $dest);
      }
      else {
        drush_print('There was an error updating the record in Solr');
      }
    }
  }
  elseif (is_null($dest)) {
    drush_print('Search for ' . $value . ' returned NULL');
  }
  else {
    drush_print('No match found for ' .  $type . ' ' . $value);
  }
}

/**
 * Delete a redirect record by id.
 *
 * @param id
 *   The solr id for the record to delete.
 */
function drush_fluke_dev_301_delete($id) {
  $solr = new DrupalApacheSolrService('https://fluke2xl-replica3.solrcluster.com/solr/301');
  
  // Delete the record
  $delete = $solr->deleteById($id);
  if ($delete->code == 200) {
    drush_print('Record with ID ' . $id . ' successfully deleted');
  }
  else {
    drush_print('There was an error attempting to delete record with id of ' . $id);
  }
}

/**
 * Generate a list of all duplicate records based on src value.
 */
function drush_fluke_dev_301_find_duplicates() {
  $num_dupes = 0;
  $id = drush_get_option('id', NULL);
  $solr = new DrupalApacheSolrService('https://fluke2xl-replica3.solrcluster.com/solr/301');
  // Truncate the table.
  db_truncate('301_duplicates')->execute();
  
  // Get a count of all records in the index.
  $stats = $solr->getLuke();
  $num_docs = (int)$stats->index->numDocs;
  $num_pages = round(($num_docs/1000), 0);
  $num_pages_option = drush_get_option('pages', NULL);
  if ($num_pages_option) {
    $num_pages = $num_pages_option;
  }

  // Create batches of 1000 docs.
  for ($i = 0; $i < $num_pages; $i++) {
    // Calculate the next starting position.
    $start = ($i * 1000) + 1;
    if ($id) {
      $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=id&q=id:" . $id . "&wt=json*";
    }
    else {
      $url = "https://fluke2xl-replica3.solrcluster.com/solr/301/select?df=src&q=*:*&rows=1000&start=" . $start . "&wt=json*";
    }
  
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    $result = json_decode(curl_exec($ch));
    curl_close($ch);
  
    if (isset($result) && isset($result->response) && isset($result->response->numFound) && $result->response->numFound > 0) {
      $docs = [];
      foreach ($result->response->docs as $doc) {
        $docs[] = $doc;
      }
      $args = [
        'page' => $i,
        'page_count' => $num_pages,
        'docs' => $docs,
        [
          'details' => t('(Updating Solr page @page  of @count)', [
            '@page ' => $i,
            '@count' => $num_pages
          ])
        ]
      ];
      $operations[] = ["fluke_dev_301_duplicates_batch_ops", [$args]];
      drush_print("Adding operation for page " . $i . " of " . $num_pages);
    }
  }
  // Put all that information into our batch array
  $batch = [
    'operations' => $operations,
    'title' => t('Update nodes'),
    'init_message' => t('Initializing'),
    'error_message' => t('An error occurred'),
    'finished' => 'fluke_dev_301_dupicates_finished'
  ];
  //Get the batch process all ready!
  batch_set($batch);
  $batch =& batch_get();

  //Because we are doing this on the back end, we set progressive to false.
  $batch['progressive'] = FALSE;

  //Start processing the batch operations.
  drush_backend_batch_process();
}

function fluke_dev_301_duplicates_batch_ops($args, &$context) {
  // Accounting.
  if (!isset($context['results']['count'])) {
    $context['results']['count'] = 0;
  }
  
  // Loop through the docs for this set.
  foreach ($args['docs'] as $doc) {
    // First, check 301_duplicates table for an existing record with this source.
  /*$query = db_select('301_duplicates', 'd');
    $query->fields('d', array('src', 'dest', 'id'));
    $query->condition('d.src', $doc->src);
    $result = $query->execute();
    $result_count = $result->rowCount();
    
    if ($result_count > 0) {
      foreach ($result as $record) {
        // Insert the record with the id of the field it duplicates.
        $insert = db_insert('301_duplicates')
          ->fields(array(
            'src' => $doc->src,
            'dest' => $doc->dest,
            'id' => $doc->id,
            'dupe_id' => $record->id
          ))
          ->execute();
      }
    }
    else { */
      // Just insert record into db.
      if (isset($doc->src) && isset($doc->dest)) {
        // Change encoding to UTF-8..
        $src_code = mb_detect_encoding($doc->src);
        $dest_code = mb_detect_encoding($doc->dest);

        $src_value = $src_code == 'ASCII' ? mb_convert_encoding($doc->src, 'UTF-8', 'ASCII') : $doc->src;
        $dest_value = $dest_code == 'ASCII' ? mb_convert_encoding($doc->dest, 'UTF-8', 'ASCII') : $doc->dest;

        $insert = db_insert('301_duplicates')
          ->fields(array(
            'src' => $src_value,
            'dest' => $dest_value,
            'id' => $doc->id
          ))
          ->execute();
      }
  //}
    $context['results']['count']++;
  }
  drush_print('Completed page ' . ($args['page'] + 1) . ' of ' . $args['page_count']);
}

function fluke_dev_301_duplicates_finished($success, $results, $operations) {
  // The 'success' parameter means no fatal PHP errors were detected. All
  // other error management should be handled using 'results'.
  if ($success) {
    $message = drush_print(format_plural($results['count'], 'One record imported.', '@count total records imported.'));
  }
  else {
    $message = t('There were errors during the importing of the records.');
  }
  drush_print($message);
}