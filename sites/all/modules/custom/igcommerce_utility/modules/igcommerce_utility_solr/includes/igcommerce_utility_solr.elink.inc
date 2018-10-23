<?php

/**
 * @file
 * Solr handle ELink content types
 */

function igcommerce_utility_solr_elink_content_type($document, $entity, $entity_type) {
  $entity_language = $entity->language;

  if (!empty($entity->field_promote_on_product)) {
    if (isset($entity->field_promote_on_product[$entity_language])) {

    }
    else {
      $lang = LANGUAGE_NONE;
    }
    if(isset($entity->field_promote_on_product[$entity_language])) {
        foreach ($entity->field_promote_on_product[$entity_language] as $key => $result) {
            $document->addField('im_promote_product', $result['target_id']);
        }
    }
  }

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
  // Cool links
  if (!empty($entity->field_link_url[$entity_language])) {
    if (!empty($entity->field_link_url[$entity_language][0]['url'])) {
      $elink_cool_links_url = $entity->field_link_url[$entity_language][0]['url'];
      $document->addField('ss_cool_links_url', $elink_cool_links_url);
    }
    if (!empty($entity->field_link_url[$entity_language][0]['title'])) {
      $elink_cool_links_title = $entity->field_link_url[$entity_language][0]['title'];
      $document->addField('ss_cool_links_title', $elink_cool_links_title);
    }
  }
  // External Link.
  if (!empty($entity->field_link[$entity_language])) {
    if (!empty($entity->field_link[$entity_language][0]['url'])) {
      $external_links_url = $entity->field_link[$entity_language][0]['url'];
      $document->addField('ss_external_url', $external_links_url);
    }
  }

  // Elink Image.
  if (isset($entity->field_toc_image_large[$entity_language])) {
    $field_toc_image_large = '';
    foreach ($entity->field_toc_image_large[$entity_language] as $data) {
      $field_toc_image_large['id'] = $data['id'];
      $field_toc_image_large['url'] = $data['url'];
      $field_toc_image_large['caption'] = $data['caption'];
      $field_toc_image_large['alt'] = $data['alt'];
      $field_toc_image_large['thumbnail'] = $data['thumbnail'];
    }
    $image_large = json_encode($field_toc_image_large);
    $document->addField('sm_toc_image_large', $image_large);
  }
}
