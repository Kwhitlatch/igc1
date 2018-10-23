<?php

/**
 * Menu Callback. Handles the export of the translatable entities.
 */
function entity_translation_export_import_admin_export_form($form, $form_state){
  $form = array('#tree' => TRUE);

  // Get translatable entity types.
  $enabled = variable_get('entity_translation_entity_types', array());
  $info = entity_get_info();

  $entities_options = array();
  $bundles_options = array();
  $fields_options = array();

  // Get the translatable fields foreach translatable entity_type.
  foreach ($enabled as $entity_type) {
    if (entity_translation_enabled($entity_type)) {
      $bundles = !empty($info[$entity_type]['bundles']) ? array_keys($info[$entity_type]['bundles']) : array($entity_type);
      foreach ($bundles as $bundle) {
        $settings = entity_translation_settings($entity_type, $bundle);
        if (entity_translation_enabled_bundle($entity_type, $bundle) && ($handler = entity_translation_get_handler($entity_type, $bundle))) {
          $fields_info = field_info_instances($entity_type, $bundle);
          foreach ($fields_info as $field_name => $value) {
            $field = field_info_field($field_name);

            if(field_is_translatable($entity_type, $field) and in_array($field['type'], array('text', 'text_long', 'text_with_summary')) and $field['cardinality'] == 1){
              if(!array_key_exists($entity_type, $entities_options)){
                $entities_options[$entity_type] = $info[$entity_type]['label'];
              }

              if(!isset($bundles_options[$entity_type][$bundle])){
                $bundles_options[$entity_type][$bundle] = $info[$entity_type]['bundles'][$bundle]['label'];
              }

              $field_value = $entity_type . ':' . $bundle .  ':' . $field_name;
              if(!isset($fields_options[$entity_type][$bundle][$field_value])){
                $fields_options[$entity_type][$bundle][$field_value] = $value['label'];
              }
            }
          }
        }
      }
    }
  }

  // If there is no translatable field yet.
  if(empty($fields_options)){
    $form['no_result'] = array('#markup' => '<p>' . t('You need to enable entity translation for at least one field.') . '</p>');
  }
  else{
    drupal_set_title(t('Export entity translations'));

    $form['export'] = array(
      '#type' => 'fieldset',
      '#title' => t('Export Settings'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );

    $form['export']['entity_type'] = array(
      '#type' => 'checkboxes',
      '#options' => $entities_options,
      '#ajax' => array(
        'callback' => 'entity_translation_export_import_admin_export_bundle_callback',
        'wrapper' => 'entity-type-wrapper',
      ),
    );

    $form['export']['entity_type_wrapper'] = array(
      '#type' => 'container',
      '#id' => 'entity-type-wrapper',
    );

    if(isset($form_state['values']['export']['entity_type'])){
      foreach($form_state['values']['export']['entity_type'] as $entity_type => $entity_type_value){
        if($entity_type_value){
          $form['export']['entity_type_wrapper'][$entity_type] = array(
            '#type' => 'fieldset',
            '#title' => $entities_options[$entity_type],
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
          );

          foreach($bundles_options[$entity_type] as $bundle_option){
            $form['export']['entity_type_wrapper'][$entity_type]['bundle'] = array(
              '#type' => 'checkboxes',
              '#options' => $bundles_options[$entity_type],
              '#ajax' => array(
                'callback' => 'entity_translation_export_import_admin_export_fields_callback',
                'wrapper' => drupal_html_class($entity_type . '-bundle-wrapper'),
              ),
            );

            $form['export']['entity_type_wrapper'][$entity_type]['bundle_wrapper'] = array(
              '#type' => 'container',
              '#id' => drupal_html_class($entity_type . '-bundle-wrapper'),
            );

            if(isset($form_state['values']['export']['entity_type_wrapper'][$entity_type]['bundle'])){
              foreach($form_state['values']['export']['entity_type_wrapper'][$entity_type]['bundle'] as $bundle => $bundle_value){
                if($bundle_value){
                  $form['export']['entity_type_wrapper'][$entity_type]['bundle_wrapper'][$bundle] = array(
                    '#type' => 'fieldset',
                    '#title' => $bundles_options[$entity_type][$bundle],
                    '#collapsible' => TRUE,
                    '#collapsed' => FALSE,
                  );

                  foreach($bundles_options[$entity_type] as $bundle_option){
                    $form['export']['entity_type_wrapper'][$entity_type]['bundle_wrapper'][$bundle]['field'] = array(
                      '#type' => 'checkboxes',
                      '#options' => $fields_options[$entity_type][$bundle],
                    );
                  }
                }
              }
            }
          }
        }
      }
    }

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Export Translations'),
    );
  }
  return $form;
}

/**
 * Ajax callback.
 */
function entity_translation_export_import_admin_export_bundle_callback($form, $form_state){
  $parents = array_slice($form_state['triggering_element']['#array_parents'], 0, -2);
  $element = drupal_array_get_nested_value($form, $parents);

  return $element['entity_type_wrapper'];
}

/**
 * Ajax callback.
 */
function entity_translation_export_import_admin_export_fields_callback($form, $form_state){
  $parents = array_slice($form_state['triggering_element']['#array_parents'], 0, -2);
  $element = drupal_array_get_nested_value($form, $parents);

  return $element['bundle_wrapper'];
}

/**
 * Submit callback.
 */
function entity_translation_export_import_admin_export_form_validate($form, $form_state){
  // Get all entities to export.
  $at_least_one_field = FALSE;

  if(isset($form_state['values']['export']['entity_type_wrapper'])){
    foreach($form_state['values']['export']['entity_type_wrapper'] as $entity_type => $entity_type_value) {
      if($entity_type_value and isset($entity_type_value['bundle_wrapper'])){
        foreach($entity_type_value['bundle_wrapper'] as $bundle => $bundle_value) {
          if($bundle_value){
            foreach($bundle_value['field'] as $field_value){
              if($field_value){
                $at_least_one_field = TRUE;
              }
            }
          }
        }
      }
    }
  }

  if(!$at_least_one_field){
    form_set_error('', t('You need to select at least one field.'));
  }
}

/**
 * Submit callback.
 */
function entity_translation_export_import_admin_export_form_submit($form, $form_state){
  // Get all entities to export.
  $entities = array();
  foreach($form_state['values']['export']['entity_type_wrapper'] as $entity_type => $entity_type_value) {
    if($entity_type_value){
      foreach($entity_type_value['bundle_wrapper'] as $bundle => $bundle_value) {
        if($bundle_value){
          foreach($bundle_value['field'] as $field_value){
            if($field_value){
              $parts = explode(':', $field_value);
              $entities[$parts[0]][$parts[1]][] = $parts[2];
            }
          }
        }
      }
    }
  }

  $limit = 500;
  $filename = 'public://entity_translation_export.csv';
  variable_set('entity_translation_export_import_file', '');

  $batch = array(
    'operations' => array(
      array('entity_translation_export_import_export_process', array($entities, $limit, $filename)),
    ),
    'finished' => 'entity_translation_export_import_export_finished',
    'title' => t('Export Translations'),
    'init_message' => t('Retrieving Entities...'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Exporting has encountered an error.'),
    'file' => drupal_get_path('module', 'entity_translation_export_import') . '/entity_translation_export_import.admin.inc',
  );

  batch_set($batch);
  batch_process('admin/config/regional/entity_translation/export');
}

/**
 * Batch process callback.
 */
function entity_translation_export_import_export_process($entities, $limit, $filename, &$context){
  // Set the default progress data.
  if (!isset($context['sandbox']['progress'])) {
    $context['results']['file'] = file_save_data('', $filename);
    $context['sandbox']['progress'] = array();
    $context['sandbox']['progress_total']['max'] = 0;
    $context['sandbox']['progress_total']['current'] = 0;
    foreach($entities as $entity_type => $bundles){
      foreach($bundles as $bundle => $fields){
        $query = new EntityFieldQuery();
        $context['sandbox']['progress'][$entity_type][$bundle]['max'] = $query->entityCondition('entity_type', $entity_type)->entityCondition('bundle', $bundle)->count()->execute();
        $context['sandbox']['progress'][$entity_type][$bundle]['current'] = 0;
        $context['sandbox']['progress_total']['max'] += $context['sandbox']['progress'][$entity_type][$bundle]['max'];
      }
    }
  }

  if(!empty($context['sandbox']['progress'])){
    $entity_type = key($context['sandbox']['progress']);
    $bundle = key(current($context['sandbox']['progress']));
    $progress = current(current($context['sandbox']['progress']));

    // Receive items.
    $items = _entity_translation_export_import_export_entity($entity_type, $bundle, $progress['current'], $limit, $entities[$entity_type][$bundle]);
    $is_header = ($context['sandbox']['progress_total']['current'] === 0);
    $data = _entity_translation_export_import_csv($items, $is_header);
    file_put_contents($context['results']['file']->uri, $data, FILE_APPEND);

    $progress['current'] += $limit;
    $context['sandbox']['progress_total']['current'] += ($progress['current'] > $progress['max'] ? ($progress['max'] - ($progress['current']-$limit)) : $limit);
    $context['sandbox']['progress'][$entity_type][$bundle]['current'] = $progress['current'];
    if($progress['current'] >= $progress['max']){
      unset($context['sandbox']['progress'][$entity_type][$bundle]);
      if(empty($context['sandbox']['progress'][$entity_type])){
        unset($context['sandbox']['progress'][$entity_type]);
      }
    }
    if(!empty($context['sandbox']['progress'])){
      reset($context['sandbox']['progress']);
      $entity_type = key($context['sandbox']['progress']);
      $bundle = key(current($context['sandbox']['progress']));
      $progress = current(current($context['sandbox']['progress']));
      $percentage = '';
      if(isset($progress['current']) and $progress['current'] > 0){
        $percentage = ' (' . $progress['current'] . '/' . $progress['max'] . ')';
      }

      $info = entity_get_info();
      $context['message'] = t('Exporting ' . $info[$entity_type]['label'] . ' - ' . $info[$entity_type]['bundles'][$bundle]['label'] . $percentage);
    }
  }

  $context['finished'] = ($context['sandbox']['progress_total']['current']/$context['sandbox']['progress_total']['max']);
}

/**
 * batch process finish callback.
 */
function entity_translation_export_import_export_finished($success, $results){
  $link = file_create_url($results['file']->uri);
  drupal_set_message(t('Export has been created! Download the <a href="@link">file</a>.', array('@link' => $link)));
}

/**
 * Get the field values of an entity.
 */
function _entity_translation_export_import_export_entity($entity_type, $bundle, $limitstart, $limit, $fields){
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', $entity_type)
    ->entityCondition('bundle', $bundle)
    ->entityOrderBy('entity_id')
    ->range($limitstart, $limit)
    ->execute();

  // Force Default Language to be first.
  $languages = language_list();
  $language_default = language_default();
  unset($languages[$language_default->language]);
  $languages = array_merge(array($language_default->language => $language_default), $languages);

  $export = array();
  foreach($result as $entity_type => $items){
    foreach($items as $entity_id => $item){
      foreach($languages as $language){
        $entity = current(entity_load($entity_type, array($entity_id)));
        $export[$entity_id]['Entity Type (Not Editable)'] = $entity_type;
        $export[$entity_id]['Bundle (Not Editable)'] = $bundle;
        $export[$entity_id]['Entity ID (Not Editable)'] = $entity_id;
        $export[$entity_id]['uuid'] = $entity->uuid;
        // Added hack
        if ($entity_type == 'taxonomy_term') {
          $export[$entity_id]['Entity NAME (Not Editable)'] = $entity->name;
          $taxonomy = taxonomy_get_parents($entity->tid);
          $taxonomy_parent = current($taxonomy);
          $export[$entity_id]['parent'] = $taxonomy_parent->name;
        }
        else if($entity_type == 'node'){
          $export[$entity_id]['Entity NAME (Not Editable)'] = $entity->title;
        }
        $export[$entity_id]['uuid'] = $entity->uuid;

        $handler = entity_translation_get_handler($entity_type, $entity, TRUE);
        $translations = $handler->getTranslations();

        foreach($fields as $field){
          $value = '';
          if(isset($translations->data[$language->language])){
            $value = $entity->{$field}[$language->language][0]['value'];
          }
          $export[$entity_id][$field][$language->language] = $value;
        }
      }
    }
  }

  return $export;
}

/**
 * Format entity values as csv.
 */
function _entity_translation_export_import_csv($items, $is_header = FALSE){
  $data = '';

  // Render Header.
  if($is_header){
    $titles = array();
    foreach(reset($items) as $field_name => $value){
      if(is_array($value)){
        foreach($value as $lang_code => $language_value){
          $titles[] = $field_name . '_' . $lang_code;
        }
      }
      else{
        $titles[] = $field_name;
      }
    }
    $data .= implode(",", $titles) . "\n";
  }

  foreach($items as $item){
    $row = array();
    foreach($item as $field_name => $value){
      if(is_array($value)){
        foreach($value as $language_value){
          $row[] = '"' . str_replace('"', '""', $language_value) . '"';
        }
      }
      else{
        $row[] = '"' . str_replace('"', '""', $value) . '"';
      }
    }

    $data .= implode(",", $row) . "\n";
  }

  return $data;
}

/**
 * Import form callback.
 */
function entity_translation_export_import_admin_import_form($form, $form_state){
  $form = array('#attributes' => array('enctype' => "multipart/form-data"));

  $form['fid'] = array(
    '#type' => 'managed_file',
    '#title' => 'Translation File for Import',
    '#upload_validators' => array('file_validate_extensions' => array('csv')),
    '#description' => t('WARNING! Do not upload any file that is not formated as needed. Please try to export the translations first.'),
  );

  $fid = variable_get('entity_translation_export_import_file', '');
  if(file_load($fid)){
    $form['fid']['#default_value'] = $fid;
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Import Translations'
  );

  return $form;
}

/**
 * Import form submit callback.
 */
function entity_translation_export_import_admin_import_form_submit($form, $form_state){
  $file = file_load($form_state['values']['fid']);
  variable_set('entity_translation_export_import_file', $file->fid);

  $batch = array(
    'operations' => array(
      array('entity_translation_export_import_import_process', array($file)),
    ),
    'finished' => 'entity_translation_export_import_import_finished',
    'title' => t('Import Translations'),
    'init_message' => t('Retrieving Entities...'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Importing has encountered an error.'),
    'file' => drupal_get_path('module', 'entity_translation_export_import') . '/entity_translation_export_import.admin.inc',
  );

  batch_set($batch);
  batch_process('admin/config/regional/entity_translation/import');
}

/**
 * Batch process callback.
 */
function entity_translation_export_import_import_process($file, &$context){
  $log_directory = 'public://logs/export_import';
  file_prepare_directory($log_directory, FILE_CREATE_DIRECTORY);
  $logfile = fopen($log_directory.'/log.txt', 'a+');
  global $user;

  // Initialize Sandbox Data.
  if (!isset($context['sandbox']['current'])) {
    $context['sandbox']['total'] = filesize($file->uri);
    $context['sandbox']['current'] = 0;
    $start_info  = "\n=================================================================\n";
    $start_info .= "Log Generated on : ".date("F j, Y, g:i a") ." by " . $user->name ."\n";
    $start_info .= "=================================================================\n\n";
    fwrite($logfile, $start_info);
  }

  if($context['sandbox']['current'] < $context['sandbox']['total']){
    $fp = @fopen($file->uri, "r");

    // Set the current csv pointer.
    @fseek($fp, $context['sandbox']['current']);

    if($data = fgetcsv($fp)){
      if(!isset($context['sandbox']['header'])){
        $context['sandbox']['header'] = $data;
      }
      else{
        $log = entity_translation_export_import_import_translation(array_combine($context['sandbox']['header'], $data));
      }
    }

    // Get the current csv pointer.
    $context['sandbox']['current'] = @ftell($fp);
  }

  if(!empty($log)){

    fwrite($logfile, $log);
    $separator = "--------------------------------------------------------------------------------\n";
    fwrite($logfile, $separator);
    fclose($logfile);
  }
  $context['finished'] = ($context['sandbox']['current']/$context['sandbox']['total']);
}

/**
 * Batch process finish callback.
 */
function entity_translation_export_import_import_finished($success, $results, $operations){
  $log_directory = 'public://logs/export_import';
  $link = l('Logs', file_create_url($log_directory.'/log.txt'), array('attributes'=>array('target'=>'_blank')));
  drupal_set_message(t('Entity Translations have been imported successfully, Have a look at !log file.', array('!log' => $link)));
}

/**
 * Imports entity translations.
 */
function entity_translation_export_import_import_translation($data){
  $entity_type = $data['Entity Type (Not Editable)'];
  $bundle = $data['Bundle (Not Editable)'];
  $entity_id = $data['Entity ID (Not Editable)'];
  $entity_name = $data['Entity NAME (Not Editable)'];
  $uuid = $data['uuid'];
  $parent = $data['parent'];
  $uuid_d = '';
  $log = '';

  // If cannot load entity.
  if(empty($entity_id)){
    if ($entity_type == 'taxonomy_term') {
      // If Entity id not present but name is there.
      $vocab = taxonomy_vocabulary_machine_name_load($bundle);
      if (!empty($entity_name)) {
        $entities = entity_load($entity_type, FALSE, array('vid' => $vocab->vid, 'name' => $entity_name));

        if(empty($entities)) {
          $log .= "[ERROR] - Taxonomy term with name = ".$entity_name." does not exist in destination system for vocabulary = ".$vocab->name."\n";
        }

        foreach($entities as $tid => $term_data) {
          $tax_parents = taxonomy_get_parents($term_data->tid);
          $current_tax_parents = current($tax_parents);

          $tax = taxonomy_term_load($term_data->tid);
          $tax->uuid = $uuid;
          $uuid_d = $tax->uuid;
          taxonomy_term_save($tax);

          if(isset($current_tax_parents->name)) {
            if ($current_tax_parents->name == $parent) {

              if(isset($current_tax_parents->name)){
                $curr_tax_parent = $current_tax_parents->name;
              }else{
                $curr_tax_parent = 'NA';
              }
              $log .= "Term " . $term_data->name . " (Parent: ".$curr_tax_parent.") with vocabulary ".$vocab->name. " has been updated where source UUID is ".$uuid. " and destination uuid is ". $tax->uuid."\n";
              $all_entities = entity_load($entity_type, FALSE, array('vid' => $vocab->vid, 'name' => $entity_name, 'tid' => $term_data->tid));
              if(isset($all_entities)) {
                if(!empty($all_entities)){
                  $translation = _entity_translation_export_import_update_traslations($all_entities, $entity_type, $bundle, $data, $log);
                }else{
                  watchdog('entity_translation_export_import', 'No data present for @entity_name , Parent : @parent where source UUID is @uuid_s and destination UUID is @uuid_d', array('@entity_name' => $entity_name, '@parent' => $parent, '@uuid_s' => $uuid, '@uuid_d' => $uuid_d));
                }
              }
            }
          }else{
            if( empty($current_tax_parents->name) && !empty($tax)){
              $log .= "Term " . $term_data->name . " (Parent: ".$term_data->name.") with vocabulary ".$vocab->name. " has been updated where source UUID is ".$uuid. " and destination uuid is ". $tax->uuid."\n";
              $all_entities = entity_load($entity_type, FALSE, array('vid' => $vocab->vid, 'name' => $entity_name, 'tid' => $term_data->tid));
              if(isset($all_entities)) {
                if(!empty($all_entities)){
                  $translation = _entity_translation_export_import_update_traslations($all_entities, $entity_type, $bundle, $data, $log);
                }else{
                  watchdog('entity_translation_export_import', 'No data present for @entity_name , Parent : @parent where source UUID is @uuid_s and destination UUID is @uuid_d', array('@entity_name' => $entity_name, '@parent' => $parent, '@uuid_s' => $uuid, '@uuid_d' => $uuid_d));
                }
              }
            }
          }
        }
      }
      else{
        // Both Entity id and entity name not present.
        // Handle taxonomy term entity.
        $term = new stdClass();
        $term->name = '';
        $term->vid = $vocab->vid;
        $term->uuid = $uuid;
        taxonomy_term_save($term);
        $entities = entity_load($entity_type, array($term->tid));
        $translation = _entity_translation_export_import_update_traslations($entities, $entity_type, $bundle, $data, $log);
      }
    }
    else if($entity_type == 'node'){
      // If Entity id not present but name is there.
      if (!empty($entity_name)) {
        $entities = entity_load($entity_type, FALSE, array('type' => $bundle, 'title' => $entity_name));
        $node = current($entities);
        $node->uuid = $uuid;
        node_save($node);
      }
      else{
        // Both Entity id and entity name not present.
        // Handle node entity.
        $node = new stdClass();
        $node->type = $bundle;
        node_object_prepare($node);  //Set some default values
        $node->status = 1;
        $node->promote = 0;
        $node->sticky = 0;
        $node->uid = $user->uid;
        $node->uuid = $uuid;
        node_save($node);
        $entities = entity_load($entity_type, array($node->nid));
        $translation = _entity_translation_export_import_update_traslations($entities, $entity_type, $bundle, $data, $log);
      }
    }
  }
  else {
    $entities = entity_load($entity_type, array($entity_id));
    $translation = _entity_translation_export_import_update_traslations($entities, $entity_type, $bundle, $data, $log);
  }
  return $log;
}

function _entity_translation_export_import_update_traslations($entities, $entity_type, $bundle, $data, &$log){

  // Get the entity.
  $entity = current($entities);

  // Get the default entity's language.
  $source_language = entity_language($entity_type, $entity);

  // Get the current entity's field info.
  $fields_info = field_info_instances($entity_type, $bundle);

  $values = array();
  $languages = array();

  if(empty($data)) {
    watchdog('entity_translation_export_import', 'No data to import for @entity_name and @bundle', array('@entity_name' => $entity->name, '@bundle' => $bundle));
    return FALSE;
  }

  foreach($data as $key => $value){
    if(strstr($key, '_') and !empty($value)){
      $parts = explode('_', $key);
      $field_language = array_pop($parts);
      $field_name = implode('_', $parts);

      // If field is translatable.
      if(array_key_exists($field_name, $fields_info)){
        $field = field_info_field($field_name);

        if(field_is_translatable($entity_type, $field) and in_array($field['type'], array('text', 'text_long', 'text_with_summary')) and $field['cardinality'] == 1){
          if(!in_array($field_language, $languages)){
            $languages[] = $field_language;
          }

          if(!isset($entity->{$field_name}[$field_language])){
            $entity->{$field_name}[$field_language] = $entity->{$field_name}[$source_language];
          }

          $entity->{$field_name}[$field_language][0]['value'] = $value;
          $log .= "Entity Name : " . $entity->name . " and its field [".$fields_info[$field_name]['label']. "][".$field_language."] = ".$value."\n";
        }
      }
    }
  }

  $handler = entity_translation_get_handler($entity_type, $entity, TRUE);
  if($handler){
    foreach($languages as $langcode){
      $translation = array(
        'translate' => 0,
        'status' => 1,
        'source' => ($source_language != $langcode) ? $source_language : '',
        'language' => $langcode,
      );

      $handler->setTranslation($translation);

      // If original entity and module title exists then do the replacements.
      if($source_language == $langcode and module_exists('title')){
        $fr_info = title_field_replacement_info($entity_type);
        foreach($fr_info as $legacy_field => $info) {
          if(isset($entity->{$info['field']['field_name']})){
            drupal_static_reset('field_language');
            title_field_sync_get($entity_type, $entity, $legacy_field, $info, $langcode);
          }
        }
      }
    }
  }
  entity_save($entity_type, $entity);

  return $log;
}