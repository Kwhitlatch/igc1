<?php
/**
 * @file
 * This file defines the function necessary for exporting the schema of URL Alias and the deletion and addition of field
 * field collection field for content type dynamically from configuration form.
 *
 * @author anshul.jain@fluke.com
 */

/**
 * Adds a field collection schema.
 *
 * @param array $data This is the schema of field collection field with fieldgroup to add.
 * @return void
 */
function _add_field_collection_schema($data) {
  $modules = module_list();
  $bundle = '';

  // Getting default settings for the url aliases.
  $settings = variable_get('ig_localized_ctypes', array());

  // Create or update fields and their instances
  if (isset($data['fields'])) {
    foreach ($data['fields'] as $key => $field) {
      if (!empty($field['bundles']['node'])) {
        $bundle = $field['bundles']['node'][0];
      }

      // Check if the field module exists.
      $module = $field['module'];
      if (!isset($modules[$module])) {
        drupal_set_message(t('%field_name field could not be created because the module %module is disabled or missing.', array('%field_name' => $key, '%module' => $module)), 'error');
        continue;
      }

      if (isset($data['instances'][$key])) {

        // Create or update field.
        $prior_field = field_read_field($field['field_name'], array('include_inactive' => TRUE));
        if (!$prior_field) {
          field_create_field($field);
          drupal_set_message(t('%field_name field has been created.', array('%field_name' => $key)));
          if (!empty($bundle)) {
            $settings[$bundle] = $bundle;
            variable_set('ig_localized_ctypes', $settings);
          }
        }
        else {
          $field['id'] = $prior_field['id'];
          field_update_field($field);
          if (!empty($bundle)) {
            $settings[$bundle] = $bundle;
            variable_set('ig_localized_ctypes', $settings);
          }
          //drupal_set_message(t('%field_name field has been updated.', array('%field_name' => $key)));
        }

        // Create or update field instances.
        foreach ($data['instances'][$key] as $ikey => $instance) {
          $bundle = $instance['bundle'];
          // Make sure the needed key exists.
          if (!isset($instance['field_name'])) {
            continue;
          }

          $prior_instance = field_read_instance($instance['entity_type'], $instance['field_name'], $instance['bundle']);
          if (!$prior_instance) {
            field_create_instance($instance);
            if (!empty($bundle)) {
              $settings[$bundle] = $bundle;
              variable_set('ig_localized_ctypes', $settings);
            }
            drupal_set_message(t('%field_name instance has been created for @bundle in @entity_type.', array('%field_name' => $key, '@bundle' => $instance['bundle'], '@entity_type' => $instance['entity_type'])));
          }
          else {
            $instance['id'] = $prior_instance['id'];
            $instance['field_id'] = $prior_instance['field_id'];
            field_update_instance($instance);
            if (!empty($bundle)) {
              $settings[$bundle] = $bundle;
              variable_set('ig_localized_ctypes', $settings);
            }
            //drupal_set_message(t('%field_name instance has been updated for @bundle in @entity_type.', array('%field_name' => $key, '@bundle' => $instance['bundle'], '@entity_type' => $instance['entity_type'])));
          }
        }
      }
    }
  }

  // Create / update fieldgroups.
  if (isset($data['fieldgroups'])) {
    if (module_exists('field_group')) {
      ctools_include('export');
      $existing_field_groups = field_group_info_groups();
      foreach ($data['fieldgroups'] as $identifier => $fieldgroup) {
        if (isset($existing_field_groups[$fieldgroup->entity_type][$fieldgroup->bundle][$fieldgroup->mode][$fieldgroup->group_name])) {
          $existing = $existing_field_groups[$fieldgroup->entity_type][$fieldgroup->bundle][$fieldgroup->mode][$fieldgroup->group_name];
          $fieldgroup->id = $existing->id;
          if (!isset($fieldgroup->disabled)) {
            $fieldgroup->disabled = FALSE;
          }
          ctools_export_crud_save('field_group', $fieldgroup);
          ctools_export_crud_set_status('field_group', $fieldgroup, $fieldgroup->disabled);
          //drupal_set_message(t('%fieldgroup fieldgroup has been updated for @bundle in @entity_type.', array('%fieldgroup' => $fieldgroup->label, '@bundle' => $fieldgroup->bundle, '@entity_type' => $fieldgroup->entity_type)));
        }
        else {
          unset($fieldgroup->id);
          unset($fieldgroup->export_type);
          if (!isset($fieldgroup->disabled)) {
            $fieldgroup->disabled = FALSE;
          }
          ctools_export_crud_save('field_group', $fieldgroup);
          $fieldgroup->export_type = 1;
          ctools_export_crud_set_status('field_group', $fieldgroup, $fieldgroup->disabled);
          drupal_set_message(t('%fieldgroup fieldgroup has been saved for @bundle in @entity_type.', array('%fieldgroup' => $fieldgroup->label, '@bundle' => $fieldgroup->bundle, '@entity_type' => $fieldgroup->entity_type)));
        }
      }
    }
    else {
      drupal_set_message(t('The fieldgroups could not be saved because the <em>Field group</em> module is disabled or missing.'), 'error');
    }
  }
}

/**
 * Removes a field collection schema.
 *
 * @param array $data This is the schema of field collection field with fieldgroup to add.
 */
function _remove_field_collection_schema($data) {
  $settings = variable_get('ig_localized_ctypes', array());
  $bundle = '';

  if (isset($data['fields'])) {
    foreach ($data['fields'] as $key => $field) {
      if (!empty($field['bundles']['node'])) {
        $bundle = $field['bundles']['node'][0];
      }
      if ( isset($field['bundles']['node']) ) {
        $prior_field =  field_info_instance('node', $field['field_name'], $field['bundles']['node'][0]);
        if ($prior_field) {
          field_delete_instance($prior_field, FALSE);
         drupal_set_message(t('%field_name field has been deleted for content type %ctype.', array('%field_name' => $key, '%ctype' => $field['bundles']['node'][0])));
          if ( !empty($bundle)) {
            $settings[$bundle] = 0;
            variable_set('ig_localized_ctypes', $settings);
          }
        }
      }
    }
    // Create or update field instances.
    foreach ($data['instances'][$key] as $ikey => $instance) {
       $bundle = $instance['bundle'];
       $prior_instance = field_read_instance($instance['entity_type'], $instance['field_name'], $instance['bundle']);
        if ($prior_instance) {
        field_delete_instance($instance);
        if ( !empty($bundle)) {
          $settings[$bundle] = 0;
          variable_set('ig_localized_ctypes', $settings);
        }
        //drupal_set_message(t('%field_name instance has been deleted for content type', array('%field_name' => $key)));
        }
    }
  }

  if (isset($data['fieldgroups'])) {
    if (module_exists('field_group')) {
      ctools_include('export');
      foreach ($data['fieldgroups'] as $identifier => $fieldgroup) {
        $existing_field_groups = field_group_info_groups();
        if (isset($existing_field_groups[$fieldgroup->entity_type][$fieldgroup->bundle][$fieldgroup->mode][$fieldgroup->group_name])) {
          $group = field_group_load_field_group($fieldgroup->group_name, $fieldgroup->entity_type, $fieldgroup->bundle, $fieldgroup->mode);
          ctools_include('export');
          field_group_group_export_delete($group, FALSE);
          drupal_set_message(t('%fieldgroup fieldgroup has been deleted for @bundle in @entity_type.', array('%fieldgroup' => $fieldgroup->label, '@bundle' => $fieldgroup->bundle, '@entity_type' => $fieldgroup->entity_type)));
        }
      }
    }
  }
}

/**
 * Gets the field collection fields schema.
 *
 * @param string $bundle bundle for which field collection field to export.
 */
function _get_field_collection_fields($bundle) {
  $data = array(
     'fields' => array(
      'field_url_aliases' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'hide_blank_items' => 1,
        'path' => '',
        'entity_translation_sync' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_url_aliases' => array(
                'value' => 'field_url_aliases_value',
                'revision_id' => 'field_url_aliases_revision_id',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_url_aliases' => array(
                'value' => 'field_url_aliases_value',
                'revision_id' => 'field_url_aliases_revision_id',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'revision_id' => array(
          0 => 'revision_id',
        ),
      ),
      'field_name' => 'field_url_aliases',
      'type' => 'field_collection',
      'module' => 'field_collection',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '-1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'int',
          'not null' => FALSE,
          'description' => 'The field collection item id.',
        ),
        'revision_id' => array(
          'type' => 'int',
          'not null' => FALSE,
          'description' => 'The field collection item revision id.',
        ),
      ),
      'bundles' => array(
        'node' => array(
          0 => $bundle,
        ),
      ),
    ),
    'field_start_date' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'granularity' => array(
          'month' => 'month',
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'year' => 'year',
          'second' => 0,
        ),
        'tz_handling' => 'site',
        'timezone_db' => 'UTC',
        'cache_enabled' => 0,
        'cache_count' => '4',
        'todate' => '',
        'entity_translation_sync' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_start_date' => array(
                'value' => 'field_start_date_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_start_date' => array(
                'value' => 'field_start_date_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_name' => 'field_start_date',
      'type' => 'datetime',
      'module' => 'date',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'datetime',
          'mysql_type' => 'datetime',
          'pgsql_type' => 'timestamp without time zone',
          'sqlite_type' => 'varchar',
          'sqlsrv_type' => 'smalldatetime',
          'not null' => FALSE,
          'sortable' => TRUE,
          'views' => TRUE,
        ),
      ),
      'bundles' => array(
        'field_collection_item' => array(
          0 => 'field_url_aliases',
        ),
      ),
    ),
    'field_end_date' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'granularity' => array(
          'month' => 'month',
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'year' => 'year',
          'second' => 0,
        ),
        'tz_handling' => 'site',
        'timezone_db' => 'UTC',
        'cache_enabled' => 0,
        'cache_count' => '4',
        'todate' => '',
        'entity_translation_sync' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_end_date' => array(
                'value' => 'field_end_date_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_end_date' => array(
                'value' => 'field_end_date_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_name' => 'field_end_date',
      'type' => 'datetime',
      'module' => 'date',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'datetime',
          'mysql_type' => 'datetime',
          'pgsql_type' => 'timestamp without time zone',
          'sqlite_type' => 'varchar',
          'sqlsrv_type' => 'smalldatetime',
          'not null' => FALSE,
          'sortable' => TRUE,
          'views' => TRUE,
        ),
      ),
      'bundles' => array(
        'field_collection_item' => array(
          0 => 'field_url_aliases',
        ),
      ),
    ),
    'field_person' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => 255,
        'entity_translation_sync' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_person' => array(
                'value' => 'field_person_value',
                'format' => 'field_person_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_person' => array(
                'value' => 'field_person_value',
                'format' => 'field_person_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_name' => 'field_person',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'field_collection_item' => array(
          0 => 'field_url_aliases',
        ),
      ),
    ),
    'field_date_created' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'granularity' => array(
          'month' => 'month',
          'day' => 'day',
          'hour' => 'hour',
          'minute' => 'minute',
          'year' => 'year',
          'second' => 0,
        ),
        'tz_handling' => 'site',
        'timezone_db' => 'UTC',
        'cache_enabled' => 0,
        'cache_count' => '4',
        'todate' => '',
        'entity_translation_sync' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_date_created' => array(
                'value' => 'field_date_created_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_date_created' => array(
                'value' => 'field_date_created_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'field_name' => 'field_date_created',
      'type' => 'datetime',
      'module' => 'date',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'datetime',
          'mysql_type' => 'datetime',
          'pgsql_type' => 'timestamp without time zone',
          'sqlite_type' => 'varchar',
          'sqlsrv_type' => 'smalldatetime',
          'not null' => FALSE,
          'sortable' => TRUE,
          'views' => TRUE,
        ),
      ),
      'bundles' => array(
        'field_collection_item' => array(
          0 => 'field_url_aliases',
        ),
      ),
    ),
    'field_url_generated' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '255',
        'entity_translation_sync' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_url_generated' => array(
                'value' => 'field_url_generated_value',
                'format' => 'field_url_generated_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_url_generated' => array(
                'value' => 'field_url_generated_value',
                'format' => 'field_url_generated_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_name' => 'field_url_generated',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '255',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'field_collection_item' => array(
          0 => 'field_url_aliases',
        ),
      ),
    ),
    'field_language_locale' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'max_length' => '10',
        'entity_translation_sync' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_language_locale' => array(
                'value' => 'field_language_locale_value',
                'format' => 'field_language_locale_format',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_language_locale' => array(
                'value' => 'field_language_locale_value',
                'format' => 'field_language_locale_format',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(
        'format' => array(
          'table' => 'filter_format',
          'columns' => array(
            'format' => 'format',
          ),
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'field_name' => 'field_language_locale',
      'type' => 'text',
      'module' => 'text',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => '10',
          'not null' => FALSE,
        ),
        'format' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'field_collection_item' => array(
          0 => 'field_url_aliases',
        ),
      ),
    ),
    'field_source_language_locale' => array(
      'translatable' => '0',
      'entity_types' => array(),
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => '',
        'entity_translation_sync' => FALSE,
      ),
      'storage' => array(
        'type' => 'field_sql_storage',
        'settings' => array(),
        'module' => 'field_sql_storage',
        'active' => '1',
        'details' => array(
          'sql' => array(
            'FIELD_LOAD_CURRENT' => array(
              'field_data_field_source_language_locale' => array(
                'value' => 'field_source_language_locale_value',
              ),
            ),
            'FIELD_LOAD_REVISION' => array(
              'field_revision_field_source_language_locale' => array(
                'value' => 'field_source_language_locale_value',
              ),
            ),
          ),
        ),
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'field_name' => 'field_source_language_locale',
      'type' => 'list_text',
      'module' => 'list',
      'active' => '1',
      'locked' => '0',
      'cardinality' => '1',
      'deleted' => '0',
      'columns' => array(
        'value' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => FALSE,
        ),
      ),
      'bundles' => array(
        'field_collection_item' => array(
          0 => 'field_url_aliases',
        ),
      ),
    ),
  ),
  'instances' => array(
    'field_date_created' => array(
      0 => array(
        'label' => 'Date Created',
        'widget' => array(
          'weight' => '5',
          'type' => 'date_popup',
          'module' => 'date',
          'active' => 1,
          'settings' => array(
            'input_format' => 'm/d/Y - H:i:s',
            'input_format_custom' => '',
            'year_range' => '-3:+3',
            'increment' => '15',
            'label_position' => 'above',
            'text_parts' => array(),
            'no_fieldset' => 0,
          ),
        ),
        'settings' => array(
          'default_value' => 'now',
          'default_value_code' => '',
          'default_value2' => 'same',
          'default_value_code2' => '',
          'user_register_form' => FALSE,
          'entity_translation_sync' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'date_default',
            'settings' => array(
              'format_type' => 'long',
              'multiple_number' => '',
              'multiple_from' => '',
              'multiple_to' => '',
              'fromto' => 'both',
              'show_remaining_days' => FALSE,
            ),
            'module' => 'date',
            'weight' => 4,
          ),
        ),
        'required' => 0,
        'description' => '',
        'fences_wrapper' => 'div_div_div',
        'field_name' => 'field_date_created',
        'entity_type' => 'field_collection_item',
        'bundle' => 'field_url_aliases',
        'deleted' => '0',
      ),
    ),
    'field_end_date' => array(
      0 => array(
        'label' => 'End Date',
        'widget' => array(
          'weight' => '3',
          'type' => 'date_popup',
          'module' => 'date',
          'active' => 1,
          'settings' => array(
            'input_format' => 'm/d/Y - H:i:s',
            'input_format_custom' => '',
            'year_range' => '-3:+20',
            'increment' => '15',
            'label_position' => 'above',
            'text_parts' => array(),
            'no_fieldset' => 0,
          ),
        ),
        'settings' => array(
          'default_value' => 'strtotime',
          'default_value_code' => '+83 years december 31',
          'default_value2' => 'same',
          'default_value_code2' => '',
          'user_register_form' => FALSE,
          'entity_translation_sync' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'date_default',
            'settings' => array(
              'format_type' => 'long',
              'multiple_number' => '',
              'multiple_from' => '',
              'multiple_to' => '',
              'fromto' => 'both',
              'show_remaining_days' => FALSE,
            ),
            'module' => 'date',
            'weight' => 1,
          ),
        ),
        'required' => 0,
        'description' => 'Select the date when this language-locale alias should expire for site visitors.   Note:  the URL will still be active for site administrators and content editors.',
        'fences_wrapper' => 'div_div_div',
        'field_name' => 'field_end_date',
        'entity_type' => 'field_collection_item',
        'bundle' => 'field_url_aliases',
        'deleted' => '0',
      ),
    ),
    'field_language_locale' => array(
      0 => array(
        'label' => 'Language-Locale',
        'widget' => array(
          'weight' => '0',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '60',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => FALSE,
          'entity_translation_sync' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'text_default',
            'settings' => array(),
            'module' => 'text',
            'weight' => 6,
          ),
        ),
        'required' => 0,
        'description' => 'The language-locale to build an alias for.',
        'fences_wrapper' => 'div_div_div',
        'default_value' => NULL,
        'field_name' => 'field_language_locale',
        'entity_type' => 'field_collection_item',
        'bundle' => 'field_url_aliases',
        'deleted' => '0',
      ),
    ),
    'field_person' => array(
      0 => array(
        'label' => 'Person who Implemented',
        'widget' => array(
          'type' => 'text_textfield',
          'weight' => '4',
          'settings' => array(
            'size' => 60,
          ),
          'module' => 'text',
        ),
        'settings' => array(
          'text_processing' => 0,
          'user_register_form' => FALSE,
          'entity_translation_sync' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'text_default',
            'settings' => array(),
            'module' => 'text',
            'weight' => 3,
          ),
        ),
        'required' => FALSE,
        'description' => '',
        'field_name' => 'field_person',
        'entity_type' => 'field_collection_item',
        'bundle' => 'field_url_aliases',
        'deleted' => '0',
        'default_value' => NULL,
      ),
    ),
    'field_source_language_locale' => array(
      0 => array(
        'label' => 'Source Language-Locale',
        'widget' => array(
          'weight' => '1',
          'type' => 'options_select',
          'module' => 'options',
          'active' => 1,
          'settings' => array(
            'apply_chosen' => '',
          ),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
          'entity_translation_sync' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'list_default',
            'settings' => array(),
            'module' => 'list',
            'weight' => 7,
          ),
        ),
        'required' => 0,
        'description' => '',
        'fences_wrapper' => 'div_div_div',
        'default_value' => NULL,
        'field_name' => 'field_source_language_locale',
        'entity_type' => 'field_collection_item',
        'bundle' => 'field_url_aliases',
        'deleted' => '0',
      ),
    ),
    'field_start_date' => array(
      0 => array(
        'label' => 'Start Date',
        'widget' => array(
          'weight' => '2',
          'type' => 'date_popup',
          'module' => 'date',
          'active' => 1,
          'settings' => array(
            'input_format' => 'm/d/Y - H:i:s',
            'input_format_custom' => '',
            'year_range' => '-3:+20',
            'increment' => '15',
            'label_position' => 'above',
            'text_parts' => array(),
            'no_fieldset' => 0,
          ),
        ),
        'settings' => array(
          'default_value' => 'strtotime',
          'default_value_code' => '+33 years december 31',
          'default_value2' => 'same',
          'default_value_code2' => '',
          'user_register_form' => FALSE,
          'entity_translation_sync' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'date_default',
            'settings' => array(
              'format_type' => 'long',
              'multiple_number' => '',
              'multiple_from' => '',
              'multiple_to' => '',
              'fromto' => 'both',
              'show_remaining_days' => FALSE,
            ),
            'module' => 'date',
            'weight' => 0,
          ),
        ),
        'required' => 1,
        'description' => 'Select a start date for when this language-locale will be "published" and available for site visitors.',
        'fences_wrapper' => 'div_div_div',
        'field_name' => 'field_start_date',
        'entity_type' => 'field_collection_item',
        'bundle' => 'field_url_aliases',
        'deleted' => '0',
      ),
    ),
    'field_url_aliases' => array(
      0 => array(
        'label' => 'URL Aliases',
        'widget' => array(
          'weight' => '81',
          'type' => 'field_collection_embed',
          'module' => 'field_collection',
          'active' => 0,
          'settings' => array(),
        ),
        'settings' => array(
          'user_register_form' => FALSE,
          'entity_translation_sync' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '7',
            'settings' => array(),
          ),
          'article_as_a_web_card' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '34',
            'settings' => array(),
          ),
          'article_toc' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '7',
            'settings' => array(),
          ),
          'full' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '34',
            'settings' => array(),
          ),
          'cta_lead_gen_web_card' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '7',
            'settings' => array(),
          ),
          'article_as_lead_gen_web_card' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '7',
            'settings' => array(),
          ),
          'todds_test' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '7',
            'settings' => array(),
          ),
          'web_card_toc' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '8',
            'settings' => array(),
          ),
          'search_index' => array(
            'label' => 'hidden',
            'type' => 'hidden',
            'weight' => '39',
            'settings' => array(),
          ),
          'search_result' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '7',
            'settings' => array(),
          ),
          'article_bl01v1_vm_fnp_topic_list' => array(
            'label' => 'above',
            'type' => 'hidden',
            'weight' => '43',
            'settings' => array(),
          ),
          'teaser' => array(
            'type' => 'hidden',
            'label' => 'above',
            'settings' => array(),
            'weight' => 0,
          ),
        ),
        'required' => 0,
        'description' => 'The following is the list of existing aliases that have been created through the alias tool.    ',
        'default_value' => NULL,
        'fences_wrapper' => 'div_div_div',
        'field_name' => 'field_url_aliases',
        'entity_type' => 'node',
        'bundle' => $bundle,
        'deleted' => '0',
      ),
    ),
    'field_url_generated' => array(
      0 => array(
        'label' => 'URL generated',
        'widget' => array(
          'weight' => '6',
          'type' => 'text_textfield',
          'module' => 'text',
          'active' => 1,
          'settings' => array(
            'size' => '130',
          ),
        ),
        'settings' => array(
          'text_processing' => '0',
          'user_register_form' => FALSE,
          'entity_translation_sync' => FALSE,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'text_default',
            'settings' => array(),
            'module' => 'text',
            'weight' => 5,
          ),
        ),
        'required' => 0,
        'description' => '',
        'fences_wrapper' => 'div_div_div',
        'default_value' => NULL,
        'field_name' => 'field_url_generated',
        'entity_type' => 'field_collection_item',
        'bundle' => 'field_url_aliases',
        'deleted' => '0',
      ),
    ),
  ),
    'fieldgroups' => array(
      'group_localizations|node|' . $bundle . '|form' => (object) array(
        'id' => '161',
        'identifier' => 'group_localizations|node|' . $bundle . '|form',
        'group_name' => 'group_localizations',
        'entity_type' => 'node',
        'bundle' => $bundle,
        'mode' => 'form',
        'parent_name' => '',
        'table' => 'field_group',
        'type' => 'Normal',
        'export_type' => 1,
        'disabled' => FALSE,
        'label' => 'Localizations',
        'weight' => '2',
        'children' => array(
          0 => 'field_url_aliases',
        ),
        'format_type' => 'tab',
        'format_settings' => array(
          'formatter' => 'closed',
          'instance_settings' => array(
            'description' => '',
            'classes' => 'group-localizations field-group-tab',
            'required_fields' => 1,
          ),
        ),
      ),
    ),
  );
return $data;
}
