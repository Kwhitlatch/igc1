<?php

/**
 * @file
 * Solr handle survey content types
 */

function igcommerce_utility_solr_survey_content_type($document, $entity, $entity_type) {
    $entity_language = $entity->language;

    // global $language;
    $url = array();
    $parent_terms = '';
    $tid = '';

    // Content title.
    if (!empty($entity->field_content_title[$entity_language][0]['value'])) {
        $document->addField("ss_field_content_title", $entity->field_content_title[$entity_language][0]['value']);
    }
    else {
        if (isset($entity->field_content_title[LANGUAGE_NONE][0]['value']) &&
                strlen($entity->field_content_title[LANGUAGE_NONE][0]['value']) > 0) {
            $document->addField("ss_field_content_title", $entity->field_content_title[LANGUAGE_NONE][0]['value']);
        }
    }
    // Survey Link
    if (!empty($entity->field_survey_link[$entity_language])) {
        $survey_url = $entity->field_survey_link[$entity_language][0]['url'];
        $survey_title = $entity->field_survey_link[$entity_language][0]['title'];
        $survey_link = array('url' => $survey_url, 'title' => $survey_title);
        $survey_link_data = json_encode($survey_link);
        $document->addField('sm_survey_link', $survey_link_data);
    }
    elseif (!empty($entity->field_survey_link[LANGUAGE_NONE])) {
        $survey_url = $entity->field_survey_link[LANGUAGE_NONE][0]['url'];
        $survey_title = $entity->field_survey_link[LANGUAGE_NONE][0]['title'];
        $survey_link = array('url' => $survey_url, 'title' => $survey_title);
        $survey_link_data = json_encode($survey_link);
        $document->addField('sm_survey_link', $survey_link_data);
    }
    // Summary
    if (!empty($entity->field_summary[$entity_language])) {
        $document->addField("tm_survey_summary", $entity->field_summary[$entity_language][0]['value']);
    }
    elseif (!empty($entity->field_summary[LANGUAGE_NONE])) {
        $document->addField("tm_survey_summary", $entity->field_summary[LANGUAGE_NONE][0]['value']);
    }
}
