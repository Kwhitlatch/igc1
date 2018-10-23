<?php

/**
 * @file
 * Solr handle TOC content types
 */

function igcommerce_utility_solr_toc_content_type($document, $entity, $entity_type) {
  $entitylanguage = $entity->language;

  /*  fields to include in solr:
      field_author_notes (long_text)
      field_owner (text)
      title_field (text)
      field_content_title (text)
      field_h1_title (text)
      description_field (long_text)
      field_meta_title (text)
      field_meta_keywords (text) 
      field_toc_related_articles (field_collection) multi
      field_toc_feat_article_page_solr (solr ref)
      field_special_event_img (dam uri)
      field_top_sellers_solr (solr ref) multi
      field_elink (solr ref) multi
      field_top_stories (solr ref) multi
      field_product_list_sort_solr (solr ref) multi
      field_kits_list_sort_solr (solr ref) multi
      field_accessories_list_sort_solr (solr ref) multi
      field_recommended_products_solr (solr ref) multi
      field_recommended_resources_coll (field_collection) multi
      field_promote_on_product (solr ref) multi
      field_display_on_prod_res_solr (solr ref) multi
      field_url_builder (taxonomy_term) 
      field_industry (taxonomy_term) multi
   */
  
  $document->addField("ts_field_author_notes", fluke_solr_fallback($entitylanguage, $entity, 'field_author_notes', "value", FALSE)); 
  $document->addField("ss_field_owner", fluke_solr_fallback($entitylanguage, $entity, 'field_owner', "value", FALSE));
  $document->addField("ss_title_field", fluke_solr_fallback($entitylanguage, $entity, 'title_field', "value", FALSE));
  $document->addField("ss_field_content_title", fluke_solr_fallback($entitylanguage, $entity, 'field_content_title', "value", FALSE));
  $document->addField("ss_field_h1_title", fluke_solr_fallback($entitylanguage, $entity, 'field_h1_title', "value", FALSE));
  $document->addField("ts_description_field", fluke_solr_fallback($entitylanguage, $entity, 'description_field', "value", FALSE));
  $document->addField("tm_meta_title", fluke_solr_fallback($entitylanguage, $entity, 'field_meta_title', "value", FALSE));
  $document->addField("tm_meta_keywords", fluke_solr_fallback($entitylanguage, $entity, 'field_meta_keywords', "value", FALSE));  
  $document->addField('sm_term_depth', fluke_solr_term_depth($entity->field_url_builder['und'][0]['tid']));  
  $document->addField("sm_url_path_builder", igcommerce_utility_solr_get_url_builder($entitylanguage, $entity));
  $document->addField("sm_field_industry", igcommerce_utility_solr_get_taxonomy_term_value($entitylanguage, $entity, 'field_industry'));
  
  // Recommended resources
  if ($resources = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_recommended_resources_coll')) {
    foreach ($resources as $key => $data) {
      if (!$recommended_resource_details = entity_revision_load('field_collection_item', $data['revision_id'])) {
        continue;
      }
      
      // Don't use fallback for dam_data
      if (isset($recommended_resource_details->field_related_digital_assets_uri[$entitylanguage][0])) {
        $dam_data = $recommended_resource_details->field_related_digital_assets_uri[$entitylanguage][0];
      } else {
        $dam_data = NULL;
      }
      $field = array(
        'article_data' => fluke_solr_fallback($entitylanguage, $recommended_resource_details, 'field_related_articles_solr', 'target_id', FALSE),
        'dam_data' => $dam_data,          
      );
      
      $field = json_encode($field);
      $document->addField('sm_related_resources', $field);
    }
  }
  
  // Recommended Products
  if ($products = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_recommended_products_solr')) {
    foreach ($products as $key => $product) {
      $document->addField('sm_related_resource_product', $product['target_id']);
    }
  }

  // Multiple article in TOC.
  if ($articles = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_toc_related_articles')) {
    foreach ($articles as $key => $article) {
      if (!$fci = entity_revision_load('field_collection_item', $article['revision_id'])) {
        continue;
      }
      
      if (!$target_id = fluke_solr_fallback($entitylanguage, $fci, 'field_related_articles_solr', 'target_id')) {
        continue;
      }
      
      $document->addField('sm_toc_related_article', $target_id);
    }
  }
  
  // feature article in TOC - TOC Builder -Feature Article Tab
  $document->addField('sm_toc_feature_article', fluke_solr_fallback($entitylanguage, $entity, 'field_toc_feat_article_page_solr', 'target_id'));

  // Special event in TOC - TOC Builder - Special Event Tab
  $image = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_special_event_img');
  $image = json_encode($image[0]);
  $document->addField('sm_toc_special_event', $image);

  // Cool Links in TOC - TOC Builder - Cool Links Tab
  if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_elink')) {
    foreach ($links as $key => $link) {
      $document->addField('sm_toc_cool_link', $link['target_id']);
    }
  }
    
  // Top stories in TOC - TOC Builder - Cool Links Tab
  if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_top_stories')) {
    foreach ($links as $key => $link) {
      $document->addField('sm_toc_top_stories', $link['target_id']);
    }
  }  
  
  // Top sellers
  if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_top_sellers_solr')) {
    foreach ($links as $key => $link) {
      $document->addField('sm_toc_top_sellers', $link['target_id']);
    }
  }
  
  // Products
  if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_product_list_sort_solr')) {
    foreach ($links as $key => $link) {
      $document->addField('sm_field_product_list_sort_solr', $link['target_id']);
    }
  }
  
  // Kits
  if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_kits_list_sort_solr')) {
    foreach ($links as $key => $link) {
      $document->addField('sm_field_kits_list_sort_solr', $link['target_id']);
    }
  }
  
  // Accessories
  if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_accessories_list_sort_solr')) {
    foreach ($links as $key => $link) {
      $document->addField('sm_field_accessories_list_sort_solr', $link['target_id']);
    }
  }
  
  // Promote on product
  if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_promote_on_product')) {
    foreach ($links as $key => $link) {
      $document->addField('sm_field_promote_on_product', $link['target_id']);
    }
  }
  
  // Display on product resources
  if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_display_on_prod_res_solr')) {
    foreach ($links as $key => $link) {
      $document->addField('sm_field_display_on_prod_res_solr', $link['target_id']);
    }
  }

    // Promotions
    if ($links = fluke_solr_fallback_field_multiple($entitylanguage, $entity, 'field_promotions')) {
        foreach ($links as $key => $link) {
            $document->addField('sm_field_promotions', $link['target_id']);
        }
    }
}
