<?php

/**
 * @file
 * Solr handle List content types
 */

function igcommerce_utility_solr_list_content_type($document, $entity, $entity_type) {

    $entity_language = $entity->language;

    $entitylanguage = $entity->language;
    // instead of loading tokens 56 times per node, cache them and use the cached value
    if ($cached_tokens = cache_get('ecm_tokens')) {
        $ecm_tokens = $cached_tokens->data;
    } else {
        $ecm_tokens = token_custom_load_multiple();
        cache_set('ecm_tokens', $ecm_tokens, 'cache', CACHE_PERMANENT);
    }
    $document->addField("ss_env_id", 'ig');
  $news_data = NULL;

  $i = 0;

  if (isset($entity->field_latest_news_coll) && isset($entity->field_latest_news_coll[$entity_language])) {

    foreach($entity->field_latest_news_coll[$entity_language] as $key => $news) {

       $data = entity_load_single('field_collection_item', $news['value']);

       if (sizeof($data->field_news_articles_solr[$entity_language]) > 0) {
           $news_data[$i++] = get_solr_content($entity_language, $data->field_news_articles_solr[$entity_language][0]['target_id']);;
       }

       if (sizeof($data->field_news_digital_assets_uri[$entity_language]) > 0) {
           $news_data[$i++] = "<a href='" . $data->field_news_digital_assets_uri[$entity_language][0]['url'] . "' alt='" .
                                           $data->field_news_digital_assets_uri[$entity_language][0]['alt'] . "'>" .
                                           $data->field_news_digital_assets_uri[$entity_language][0]['alt'] . "</a>";
       }

       if (sizeof($data->field_news_products_solr[$entity_language]) > 0) {
           $result = get_solr_content($entity_language, $data->field_news_products_solr[$entity_language][0]['target_id']);
           $news_data[$i++] = $result;
       }

       if (sizeof($data->field_news_promo_toc_event[$entity_language]) > 0) {
           $url = 'node/' . $data->field_news_promo_toc_event[$entity_language][0]['entity']->nid;
           $url_alias = drupal_get_path_alias($url, $entity_language);
           $news_data[$i++] = "<a href='" . trim($url_alias) . "' alt='" .
                                       $data->field_news_promo_toc_event[$entity_language][0]['entity']->field_content_title[$entity_language][0]['value'] . "'>" .
                                       $data->field_news_promo_toc_event[$entity_language][0]['entity']->field_content_title[$entity_language][0]['value'] . "</a>";
       }

    }
  }

  $document->addField('sm_latest_news', json_encode($news_data));

  $feature_data = NULL;
  if (!empty($entity->field_featured_items_home_coll[$entity_language])) {
    $feature_arr = array();
    $i = 0;

    foreach ($entity->field_featured_items_home_coll[$entity_language] as $data) {
      $resource_details = entity_load('field_collection_item', array($data['value']));
      foreach ($resource_details as $key => $resource) {
        if (!empty($resource->field_product_one_solr[$entity_language][0]['target_id'])) {
          $feature_arr[$i]['product'] = $resource->field_product_one_solr[$entity_language][0]['target_id'];
        }
        if (!empty($resource->field_article_one_solr[$entity_language][0]['target_id'])) {
          $feature_arr[$i]['article'] = $resource->field_article_one_solr[$entity_language][0]['target_id'];
        }
        if (!empty($resource->field_promotion_one[$entity_language][0]['target_id'])) {
          $feature_arr[$i]['promotion'] = $resource->field_promotion_one[$entity_language][0]['target_id'];
        }
        if (!empty($resource->field_e_link_featured[$entity_language][0]['target_id'])) {
          $feature_arr[$i]['elink'] = $resource->field_e_link_featured[$entity_language][0]['target_id'];
        }
        ++$i;
      }
    }
    if (count($feature_arr) > 0) {
      $feature_data = json_encode($feature_arr);
    }
  }
  $document->addField('sm_featured_article_home', $feature_data);
}


function get_solr_content($lang, $entity_id) {

    $keyword = "entity_id:" . $entity_id;
    $parameter[]['fl'] = 'path_alias';
    $parameter[]['fl'] = 'tm_field_content_title';
    $filter[]['ss_language'] = $lang;
    $result = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);

    if ($result->code == 200) {
       return "<a href='" . $result->response->docs[0]->path_alias . "' alt='" . $result->response->docs[0]->tm_field_content_title[0] . "'>" . $result->response->docs[0]->tm_field_content_title[0] . "</a>";
    }
    else {
      return array();
    }

}



