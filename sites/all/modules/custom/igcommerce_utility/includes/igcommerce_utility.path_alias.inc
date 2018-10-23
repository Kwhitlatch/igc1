<?php

function igcommerce_utility_path_alias_form($form, &$form_state) {
    global $language;

    $form['system'] = array(
        '#type' => 'textfield',
        '#title' => t('URL Source'),
        '#default_value' => '',
        '#maxlength' => 255,
        '#description' => t('Enter the en-us path here. No trailing slash'),
    );
    $form['language'] = array(
        '#type' => 'select',
        '#title' => t('Language'),
        '#options' => array(LANGUAGE_NONE => t('All languages')) + locale_language_list('name'),
        '#default_value' => $language->language,
        //'#weight' => -10,
        '#description' => t('Path alias Local.'),
    );
    $form['alias'] = array(
        '#type' => 'textfield',
        '#title' => t('URL Alias'),
        '#default_value' => '',
        '#maxlength' => 255,
        '#description' => t('Add the local path for this page, no trailing slash.'),
    );

    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save Alias'),
    );

    return $form;
}

/**
 * Form element validation handler for URL alias form element.
 *
 * @see path_form_node_form_alter()
 */
function igcommerce_utility_path_alias_form_validate($form, &$form_state) {
    // Trim the submitted value.
    $alias = trim($form_state['values']['alias']);
    if (!empty($alias)) {
        $alias = $form_state['values']['alias'];
        $system = $form_state['values']['system'];
        $language = $form_state['values']['language'];

        // Ensure that the submitted alias does not exist yet.
        $query = db_select('url_alias')
            ->condition('alias', $alias)
            ->condition('language', $language);
        if (!empty($path['source'])) {
            $query->condition('source', $system, '<>');
        }
        $query->addExpression('1');
        $query->range(0, 1);
        if ($query->execute()->fetchField()) {
            form_set_error('alias', t('The path alias you are trying to create is already in use.'));
        }
    }
}

function igcommerce_utility_path_alias_form_submit($form, &$form_state) {

    $local_path = $form_state['values']['alias'];
    $source = $form_state['values']['system'];
    $lang = $form_state['values']['language'];
    //$alias = array('source' => $source, 'alias' => $local_path, 'language' => $lang);
    //path_save($alias);
    igcommerce_utility_save_update_alias($source, $local_path, $lang);
    drupal_goto($lang. '/'.$local_path);
}