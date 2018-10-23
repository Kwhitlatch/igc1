<?php

/**
 * @file
 * Solr handle promotion content types
 */

function igcommerce_utility_solr_promotion_content_type($document, $entity, $entity_type) {
  $entity_language = $entity->language;

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

  $image_large = '';
  $image_medium = '';
  $image_small = '';
  $featured_image = '';

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
  }
  $document->addField('sm_toc_image_large', $image_large);

  if (isset($entity->field_toc_image_medium[$entity_language])) {
    $field_toc_image_medium = '';
    foreach ($entity->field_toc_image_medium[$entity_language] as $data) {
      $field_toc_image_medium['id'] = $data['id'];
      $field_toc_image_medium['url'] = $data['url'];
      $field_toc_image_medium['caption'] = $data['caption'];
      $field_toc_image_medium['alt'] = $data['alt'];
      $field_toc_image_medium['thumbnail'] = $data['thumbnail'];
    }
    $image_medium = json_encode($field_toc_image_medium);
  }
  $document->addField('sm_toc_image_medium', $image_medium);

  if (isset($entity->field_toc_image_small[$entity_language])) {
    $field_toc_image_small = '';
    foreach ($entity->field_toc_image_small[$entity_language] as $data) {
      $field_toc_image_small['id'] = $data['id'];
      $field_toc_image_small['url'] = $data['url'];
      $field_toc_image_small['caption'] = $data['caption'];
      $field_toc_image_small['alt'] = $data['alt'];
      $field_toc_image_small['thumbnail'] = $data['thumbnail'];
    }
    $image_small = json_encode($field_toc_image_small);
  }
  $document->addField('sm_toc_image_small', $image_small);

  if (isset($entity->field_toc_featured_image_for_col[$entity_language])) {
    $field_toc_featured_image_for_col = '';
    foreach ($entity->field_toc_featured_image_for_col[$entity_language] as $data) {
      $field_toc_featured_image_for_col['id'] = $data['id'];
      $field_toc_featured_image_for_col['url'] = $data['url'];
      $field_toc_featured_image_for_col['caption'] = $data['caption'];
      $field_toc_featured_image_for_col['alt'] = $data['alt'];
      $field_toc_featured_image_for_col['thumbnail'] = $data['thumbnail'];
    }
    $featured_image = json_encode($field_toc_featured_image_for_col);
  }
  $document->addField('sm_toc_featured_image', $featured_image);

  // Added node path and long discription.
  if (isset($entity->field_long_description[$entity_language])) {
    $document->addField('ts_long_description', $entity->field_long_description[$entity_language][0]['value']);
  }
  $alias = drupal_get_path_alias('node/' . $entity->nid);

  if (!empty($alias)) {
    $document->addField('ts_promotion_alias', $alias);
  }
}
