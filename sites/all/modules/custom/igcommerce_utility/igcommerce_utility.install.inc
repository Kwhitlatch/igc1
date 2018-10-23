<?php

/*
 * @file
 * Handle utility
 */

/**
 * Adds variables to the list of multilingual variables.
 *
 * @param array $variables
 *   Array of variables need to add to list of multilingual variables.
 *
 */
function igcommerce_utilities_solr_install_variables_i18n($variables) {
  // Make the variables multilingual.
  $current_translatable_vars = variable_get('variable_realm_list_language', array());
  variable_set('variable_realm_list_language', array_merge($current_translatable_vars, $variables));

  // Initialise the languages values.
  $languages = language_list();
  foreach ($variables as $variable) {
    if (!empty($variable)) {
      $current_global_value = i18n_variable_global($variable);
      if (is_null($current_global_value)) {
        continue;
      }
    }


    foreach ($languages as $langcode => $langobj) {
      $current_language_value = i18n_variable_get($variable, $langcode);
      if (is_null($current_language_value)) {
        i18n_variable_set($variable, $current_global_value, $langcode);
      }
    }
  }
}
