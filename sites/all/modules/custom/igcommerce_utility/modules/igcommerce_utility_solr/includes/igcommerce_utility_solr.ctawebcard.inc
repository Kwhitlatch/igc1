<?php

/**
 * @file
 * Apache handler for TOC webcards
 *
 */

function igcommerce_utility_solr_ctawebcard_content_type($document, $entity, $entity_type) {
    $entity_language = $entity->language;
    $document->addField("ss_env_id", 'ig');
    // Get value of "cta_letf_coll" and "cta_right_coll" field collection.
    $field_cta_left_coll = $entity->field_cta_left_coll[$entity_language][0]['value'];
    $field_cta_right_coll = $entity->field_cta_right_coll[$entity_language][0]['value'];

    // Get cta_left_coll field collection value.
    $cta_left_coll_field_colection = entity_load('field_collection_item', array(
        $field_cta_left_coll
    ));

    foreach ($cta_left_coll_field_colection as $field_colllection_key => $field_collection_value) {
        $taxonomy_cta = taxonomy_term_load($field_collection_value->field_cta_button_text[$entity_language][0]['tid']);
        $button['label'] = $taxonomy_cta->name;
        $button['url'] = $field_collection_value->field_link[$entity_language][0]['url'];
        $cta_left_coll = json_encode($button);
        $document->addField('sm_cta_left_coll', $cta_left_coll);
    }
    // Get cta_right_coll field collection value.
    $cta_right_coll_field_colection = entity_load('field_collection_item', array(
        $field_cta_right_coll
    ));
    foreach ($cta_right_coll_field_colection as $field_colllection_key => $field_collection_value) {
        $taxonomy_cta = taxonomy_term_load($field_collection_value->field_cta_button_text[$entity_language][0]['tid']);
        $button['label'] = $taxonomy_cta->name;
        $button['url'] = $field_collection_value->field_link[$entity_language][0]['url'];
        $cta_right_coll = json_encode($button);
        $document->addField('sm_cta_right_coll', $cta_right_coll);
    }
}
