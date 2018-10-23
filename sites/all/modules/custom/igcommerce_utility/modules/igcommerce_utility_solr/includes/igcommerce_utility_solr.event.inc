<?php

/**
 * @file
 * Solr handle Event content types
 */

function igcommerce_utility_solr_event_content_type($document, $entity, $entity_type) {

  $entitylanguage = $entity->language;

/*  fields to  include in solr

   field_content_title  (text) (done)
   field_short_description_summary (long text) (done)
   field_meta_title (text) (done)
   field_meta_keywords (text) (done)
   field_event_date (date) (done)
   field_trade_show_website (link) (done)
   field_venue (text) (done)
   field_event_location (long text) (done)
   field_event_currency_indicator (text) (done)
   field_event_price (float) (done)
   field_event_sponsor (long text) (done)
   field_cta_left_coll (field collection) (done)
   field_contact_email (text) (done)
   field_phone_number (text) (done)
   field_events_type (taxonomy term) (done)
   field_events_webinar_type (taxonomy term) (done)
   field_industry (taxonomy term) (done) (done)
   field_application (taxonomy term) (done)
   field_event_product_cateory (taxonomy term) (done)
   field_url_builder (taxonomy term) (done)
   field_category_image_toc_uri (DAM URI) (done)
   field_event_feature (text list) (not done -- not sure if its still valid)
*/

    $document->addField("tm_article_display_title", fluke_solr_fallback($entitylanguage, $entity, 'field_content_title', "value", FALSE)); // Display title of article.
    $document->addField("ss_field_content_title", fluke_solr_fallback($entitylanguage, $entity, 'field_content_title', "value", FALSE)); // Content title of article.
    $document->addField("tm_field_content_title", fluke_solr_fallback($entitylanguage, $entity, 'field_content_title', "value", FALSE)); //content title in "tm_" type
    $document->addField("tm_short_description_summary", fluke_solr_replace_tokens($ecm_tokens, fluke_solr_fallback($entitylanguage, $entity, 'field_short_description_summary', "value", FALSE)));
    $document->addField("tm_meta_title", fluke_solr_fallback($entitylanguage, $entity, 'field_meta_title', "value", FALSE));
    $document->addField("tm_meta_keywords", fluke_solr_fallback($entitylanguage, $entity, 'field_meta_keywords', "value", FALSE));
    $document->addField("tm_event_date", fluke_solr_fallback($entitylanguage, $entity, 'field_event_date', "value", FALSE));
    $document->addField("tm_event_website_url", fluke_solr_fallback($entitylanguage, $entity, 'field_trade_show_website', "url", FALSE));
    $document->addField("tm_event_website_title", fluke_solr_fallback($entitylanguage, $entity, 'field_trade_show_website', "title", FALSE));
    $document->addField("tm_event_venue", fluke_solr_fallback($entitylanguage, $entity, 'field_venue', "value", FALSE));
    $document->addField("tm_event_location", fluke_solr_fallback($entitylanguage, $entity, 'field_event_location', "value", FALSE));
    $document->addField("tm_event_currency_indicator", fluke_solr_fallback($entitylanguage, $entity, 'field_event_currency_indicator', "value", FALSE));
    $document->addField("tm_event_price", fluke_solr_fallback($entitylanguage, $entity, 'field_event_price', "value", FALSE));
    $document->addField("tm_event_sponsor", fluke_solr_fallback($entitylanguage, $entity, 'field_event_sponsor', "value", FALSE));
    $document->addField('sm_cta_left_coll', fluke_solr_get_cta_web_card($entitylanguage, $entity, 'field_cta_left_coll', 'value'));
    $document->addField("tm_contact_email", fluke_solr_fallback($entitylanguage, $entity, 'field_contact_email', "value", FALSE));
    $document->addField("tm_event_email", fluke_solr_fallback($entitylanguage, $entity, 'field_event_email', "email", FALSE));
    $document->addField("tm_contact_phone_number", fluke_solr_fallback($entitylanguage, $entity, 'field_phone_number', "value", FALSE));

// taxonomy
// Use the local taxonomy as TIDs are likely different on Solr
//

     $document->addField("sm_event_type_name", _get_taxonomy_term_value($entitylanguage, $entity, 'field_events_type'));
     $document->addField("sm_event_webinar_type_name", _get_taxonomy_term_value($entitylanguage, $entity, 'field_events_webinar_type'));
     $document->addField("sm_event_webinar_category_name", _get_taxonomy_term_value($entitylanguage, $entity, 'field_events_webinar_category'));
     $document->addField("sm_industry_name", _get_taxonomy_term_value($entitylanguage, $entity, 'field_industry'));
     $document->addField("sm_application_name", _get_taxonomy_term_value($entitylanguage, $entity, 'field_application'));
     $document->addField("sm_product_category_name", _get_taxonomy_term_value($entitylanguage, $entity, 'field_event_product_category'));
     $document->addField('sm_term_depth', fluke_solr_term_depth($entity->field_url_builder['und'][0]['tid']));

    // get taxonomy term display titles


    if (isset($entity->field_category_image_toc_uri) &&
        sizeof($entity->field_category_image_toc_uri) > 0) {
          $toc_image = array();
          $toc_image['url'] = $entity->field_category_image_toc_uri[LANGUAGE_NONE][0]['url'];
          $toc_image['alt'] = $entity->field_category_image_toc_uri[LANGUAGE_NONE][0]['alt'];
          $toc_image['caption'] = $entity->field_category_image_toc_uri[LANGUAGE_NONE][0]['caption'];
          $document->addField('tm_event_toc_image', json_encode($toc_image));
    }

}

function _get_taxonomy_term_value($entitylanguage, $entity, $field_machine_name) {

     if (isset($entity->{$field_machine_name}[LANGUAGE_NONE][0]['tid'])) {
        $term = taxonomy_term_load($entity->{$field_machine_name}[LANGUAGE_NONE][0]['tid']);
        if ($term) {
            return $term->field_content_title[$entitylanguage][0]['value'];
        }

     }

}

