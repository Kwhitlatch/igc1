<?php

/**
 * @file
 *
 * Handle the recommaned resource and related article of taxonomy
 *  of {url_builder} of igcommerce.
 */

/*
 * Handle Recommaned Resource of url builder taxonomy
 */
function igcommerce_utility_articles_url_builder_recommanded_resources() {
  $output = NULL;
  global $language;

  $url_parts = explode('/', $_GET['q']);
  $category = array_pop($url_parts);

  $tid = NULL;

  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', 'url_builder')
      ->fieldCondition('field_url_title', 'value', $category, '=');

  $results = $query->execute();

  if (!$results || sizeof($results) < 1) {
    return $output;
  }

  foreach ($results['taxonomy_term'] as $key => $value) {
    $tid = $key;
  }

  if (is_null($tid)) {
    return $output;
  }

  $term = taxonomy_term_load($tid);

  $articles_exist = NULL;

  if (!empty($term->field_recommended_resources_coll[$language->language]) && sizeof($term->field_recommended_resources_coll) > 0) {
    $output .= '<h3> ' . t('Recommended resources') . '</h3>';
    foreach ($term->field_recommended_resources_coll[$language->language] as $resources) {
      $resource_details = entity_load('field_collection_item', array($resources['value']));
      foreach ($resource_details as $resource) {
        if (!empty($resource->field_related_articles_solr[$language->language])) {
          //$node = node_load($resource->field_related_articles['und'][0]['target_id']);
          module_load_include('inc', 'igcommerce_utility_articles', 'includes/igcommerce_utility_articles.fluke_news');
          $article_data = igcommerce_utility_articles_get_full_article_data($resource->field_related_articles_solr[$language->language][0]['target_id'], NULL);
          if ($article_data) {
            $path_alias = $language->language . '/' . $article_data[0]->path_alias;
            $output .= "<div class='toc-article-related-resource-wrapper'>";
            $output .= "<div class='card'>";
            $output .= "<h5 class='toc-article-related-resource-title'>";
            $output .= '<a href="/' . $path_alias . '" alt="' . $article_data[0]->sm_field_content_title[0]  . '">';
            $output .= $article_data[0]->sm_field_content_title[0] ;
            $output .= "</a>";
            $output .= "</h5>";
            $output .= "</div>";
            $output .= "</div>";
            $articles_exist = TRUE;
          }
        }
        elseif (isset($resource->field_related_digital_assets_uri[$language->language]) && sizeof($resource->field_related_digital_assets_uri) > 0) {
          $output .= "<div class='toc-article-related-resource-wrapper'>";
          $output .= "<div class='card'>";
          $output .= "<h5 class='toc-article-related-resource-title'>";
          $output .= '<a href="' . $resource->field_related_digital_assets_uri[$language->language][0]['url'] . '" alt="' . $resource->field_related_digital_assets_uri[$language->language][0]['alt'] . '">';
          $output .= $resource->field_related_digital_assets_uri[$language->language][0]['alt'];
          $output .= "</a>";
          $output .= "</h5>";
          $output .= "</div>";
          $output .= "</div>";
          $articles_exist = TRUE;
        }
      }
    }
  }

  if ($articles_exist) {
    return $output;
  }

  return NULL;
}

/*
 * Handle Recommaned product of url builder taxonomy.
 */
function igcommerce_utility_articles_url_builder_recommanded_product() {
  $output = NULL;
  global $language;

  $url_parts = explode('/', $_GET['q']);
  $category = array_pop($url_parts);

  $tid = NULL;

  $query = new EntityFieldQuery();
  $query
      ->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', 'url_builder')
      ->fieldCondition('field_url_title', 'value', $category, '=');

  $results = $query->execute();

  if (!$results || sizeof($results) < 1) {
    return $output;
  }

  foreach ($results['taxonomy_term'] as $key => $value) {
    $tid = $key;
  }

  if (is_null($tid)) {
    return $output;
  }

  $term = taxonomy_term_load($tid);
  if (!empty($term->field_related_products_solr[$language->language]) && sizeof($term->field_related_products_solr) > 0) {
    $product_details = array();
    $product_string = NULL;
    foreach ($term->field_related_products_solr[$language->language] as $key => $related_product) {
      $product_details[$value]['product'] = '';
        if (empty($product_string)) {
          $product_string .= "(" . $related_product['target_id'];
        }
        else {
          $product_string .= " OR " . $related_product['target_id'];
        }
    }
    $product_string .= ")";
    if (!empty($product_string) && $product_string != ")" ) {
      // Feching data from article.
      // Query to fetch data from article based on $product_string from toc.
      $article_keyword = "entity_type:node";
      $article_parameter[]['fl'] = 'entity_id';
      $article_parameter[]['fl'] = 'ss_field_content_title';
      $article_parameter[]['fl'] = 'path_alias';
      $article_parameter[]['fl'] = 'is_product_slideshow';
      $article_parameter[]['fl'] = 'tm_specs';
      $article_parameter[]['fl'] = 'tm_datasheets';
      $article_filter[]['entity_id'] = $product_string;
      $article_filter[]['bundle'] = 'product_display';
      $article_filter[]['ss_language'] = $language->language;
      $article_product_data = igcommerce_utility_articles_solr_toc_sol_query($article_keyword, $article_parameter, $article_filter);

      $article_product_data = $article_product_data->response->docs;
      foreach ($article_product_data as $article_product_key => $article_product_value) {
        $product_details[$article_product_value->entity_id]['product'] = $article_product_value;
      }
      $output .= "<h3>Recommended products</h3>";
      $count = 1;
      if (!empty($product_details)) {
        foreach ($product_details as $product_key => $product_value) {
          if (!empty($product_value['product']->is_product_slideshow)) {
            $tablet_thumb = NULL;
            $mobile_thumb = NULL;
            $desktop_thumb = NULL;
            $datasheet = NULL;

            $slideshow = fluke_solr_get_entity($product_value['product']->is_product_slideshow, 'node', 'slideshow', $language->language);
            if (empty($slideshow->sm_field_product_image_desktop[0])) {
              continue;
            }
            
            $image = json_decode($slideshow->sm_field_product_image_desktop[0]);
            //desktop image.
            $desktop_thumb = $image->url;
            $alt = $image->alt;            
            // generate the output using the igcommerce_utility_fomrat_image
            $pic = igcommerce_utility_determine_toc_image($desktop_thumb, $tablet_thumb, $mobile_thumb, $alt);
          }
          // Datasets.
          if (isset($product_value['product']->tm_datasheets)) {
            $datasheet_data = json_decode($product_value['product']->tm_datasheets[0]);
            $datasheet = '<a href="' . $datasheet_data[0]->url . '" target="_blank"  download>' . $datasheet_data[0]->alt . '</a>';
          }

          // Display product result.
          //display only 4 products
          if ($count < 4) {
            $path_url = '';
            if (!empty($product_value['product']->path_alias)) {
              $path_url = $product_value['product']->path_alias;
            }

            $output .= "<div class='toc-article-related-resource-wrapper'>";
            $output .= "<div class='card'>";
            $output .= "<div class='toc-article-related-product-image'>";
            $output .= '<a href="/' . $language->language . '/' . $path_url . '" alt="' . $alt . '">';
            $output .= $pic;
            $output .= "</a>";
            $output .= "</div>"; // end of image

            $output .= "<h5 class='toc-article-related-resource-title'>";
            $output .= '<a href= "/' . $language->language . '/' . $path_url . '" alt="' . $product_value['product']->ss_field_content_title . '">';
            $output .= $product_value['product']->ss_field_content_title;
            $output .= "</a>";
            $output .= "</h5>";
            //creates a pop up of the product details using model.
            $output .= "<div class='toc-article-related-product-see-spec'>";
            if (!empty($product_value['product']->tm_specs[0])) {
              $output .= '<a  data-toggle="modal" data-target="#specification-' . $count . '"  alt="" cursor="pointer" style="cursor:pointer">';
              $output .= 'See specification</a>';
              $output .= '<div id="specification-' . $count . '" class="modal fade" role="dialog">
                            <div class="modal-dialog">
                              <div class="modal-content">
                                <div class="modal-header">
                                  <a class="close" data-dismiss="modal" aria-label="Close">
                                    <span class="fluke-icon fluke-icon-close" aria-hidden="true">&nbsp;</span></a>
                                </div>
                                <div class="modal-body" id="specification_content">'
                  . $product_value['product']->tm_specs[0] .
                  '</div>
                              </div>
                            </div>
                          </div>';
            }
            $output .= "</div>";
            $output .= "<div class='toc-article-related-product-download'>";
            $output .= $datasheet;
            $output .= "</div>";

            $output .= "</div>";
            $output .= "</div>";
            ++$count;
          }
        }
      }
    }
  }

  return $output;
}
