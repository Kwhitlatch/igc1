<?php

/*
 * @file
 * Utility popup model for displaying article detail page.
 */

function igcommerce_utility_articles_webcard_article_detail_popup_details($request_url = NULL) {
  // bail if we are in an admin or panels page
  if (in_array(arg(0), array('admin', 'panels'))) {
    return;
  }
  
  drupal_add_css(drupal_get_path('module', 'igcommerce_utility_articles') . '/css/igcommerce_utility_articles.css');
  drupal_add_js(drupal_get_path('module', 'igcommerce_utility_articles') . '/js/igcommerce_utility_articles.js');

  global $language;
  global $base_url;
  $path = current_path();
  $output = NULL;
  $image_url_desktop = NULL;
  $image_url_tablet = NULL;
  $image_url_mobile = NULL;
  $nid = '';
  $parent_path = array();
  $item = array();

  $filters = array();
  
  $filters = array(
      "ss_path_alias" => '"'. $path . '"',
      "ss_language" => $language->language,
      "bundle" => "article"
  );
  
  $query = fluke_solr_get_connection();
  
  $query_options = fluke_solr_add_filters($query, array('filters' => $filters));
  $response = fluke_solr_query($query_options);
  
  if (empty($response->response->docs)) {
    drupal_not_found();
  }
    
  $doc = $response->response->docs[0];
  
  // Add metatags
  igcommerce_utility_head_elements($doc);
  
  $node_title = '';
  $node_id = $doc->entity_id;
  // Title of article content type.
  //If H1 title is set use it or else use display title.
  if (!empty($doc->ss_article_h1_title)) {
    $node_title = $doc->ss_article_h1_title;
  }
  else {
    $node_title = $doc->ss_field_content_title;
  }
  
  // Body of article content type.
  $node_body = !empty($doc->tm_article_body[0]) ?
  $doc->tm_article_body[0] : $doc->ts_article_body;
  
  $node_body = token_replace($node_body);
  
  // recommended resource for article.
  $recommended_resource_article = !empty($doc->tm_recommended_resource_article[0]) ? json_decode($doc->tm_recommended_resource_article[0]) : array();
  // recommended product for article.
  $recommended_product_article = !empty($doc->tm_recommended_product_article[0]) ? json_decode($doc->tm_recommended_product_article[0]) : NULL;
  
  // Card id
  $article_card_id = !empty($doc->ss_field_card_id) ? json_decode($doc->ss_field_card_id) : NULL;

  igcommerce_utility_head_elements($doc, TRUE);
  
  if (!$request_url) {
    $url_builder = json_decode($doc->sm_url_path_builder[0]);
    $url_builder = array_reverse($url_builder);
    array_shift($url_builder);
    $request_url = implode('/', $url_builder);
    
    // Don't redirect to the current page
    if ($request_url == $doc->ss_path_alias_locale) {
      array_pop($url_builder);
      $request_url = implode('/', $url_builder);
    }
  }
  
  $item['close'] = $request_url;
  
  // Add facebook metadata to the head
  igcommerce_utility_head_elements($doc);

  //Set the page title
  igcommerce_utility_head_elements($doc, TRUE);
  
  // Header image.
  if (!empty($doc->sm_article_header_img[0])) {
    $header_img = json_decode($doc->sm_article_header_img[0]);  
    // Send either image or video content
    // check if string ends with image extension
  
    if (preg_match('/(\.jpg|\.png|\.bmp)$/', $header_img->header_img_url)) {
      $item['pic'] = "<img itemprop='image' src='" . $header_img->header_img_url . "' alt='" . $header_img->header_img_alt . "' />";
    }
    if (preg_match('/(\.mp4|\.mov|\.m4v|\.flv|\.mpg)$/', $header_img->header_img_url)) { // check if there is video extension in string
      // show as html5 video
      $item['pic'] = "<video id='article_header_video' style='width:100%;' src='" . $header_img->header_img_url . "' alt='" . $header_img->header_img_alt . "' controls></video>";
    }
   
    if (strpos($header_img->header_img_url, 'brightcove') !== FALSE) {
      // If brightcove video, use that template  
      $item['pic'] = theme('brightcove_video_player', array('url' => $header_img->header_img_url));
    }
    if (strpos($header_img->header_img_url, "youtube") !== false ||
      strpos($header_img->header_img_url, "vimeo.com") !== false ) { // check if there is video extension in string
      $item['pic'] = "<div class='video-responsive'><iframe width='560' height='315' src='" . $header_img->header_img_url . "' frameborder='0'></iframe></div>";
    }
    
    // Added for getting image alt and caption text.
    $item['header_img_caption'] = '';
    $item['header_img_alt'] = '';    
    if (!empty($doc->ts_field_caption)) {
      $item['header_img_caption'] = $doc->ts_field_caption;
    }
    if (!empty($header_img->header_img_alt)) {
      $item['header_img_alt'] = $header_img->header_img_alt;    
    }
  }
    
  // Social Share
  $item['social_share'] = igcommerce_utility_articles_solr_build_social_share();
  // Title of node.
  $item['node_title'] = $node_title;
  // body of node.
  $item['node_body'] = $node_body;
  // CTA Webcard link..
  if (isset($doc->tm_webcard_cta)) {
    $ctas = json_decode($doc->tm_webcard_cta[0]);
     
    if (!empty($ctas->primary)) {
      $cta_text = fluke_solr_get_cta_text($language->language, $ctas->primary->tid);
      $item['ctas_primary_url'] = $ctas->primary->url;
      $item['ctas_primary_button_text'] = $cta_text;
    }
    if (!empty($ctas->secondary)) {
      $cta_text = fluke_solr_get_cta_text($language->language, $ctas->secondary->tid);
      $item['ctas_secondary_url'] = $ctas->secondary->url;
      $item['ctas_secondary_button_text'] = $cta_text;
    }
  }
  
  // Publication Data for schema.org microdata markup
  // User defined publication date is checked first
  if (isset($doc->ss_publication_date) && substr($doc->ss_publication_date, 0, 4) > 1990) {
    $pub_date = $doc->ss_publication_date;
  }
  // If there is no user defined publication date or it wasn't filled in,
  // use the node creation date instead.
  else {
    $pub_date = $doc->ds_created;
  }
  
  // Date of last modification or comment
  if (isset($doc->ds_last_comment_or_change)) {
    $mod_date = $doc->ds_last_comment_or_change;
  }
  // // If there is no last comment date, fall back to last date changed
  else if (isset($doc->ds_changed)) {
    $mod_date = $doc->ds_changed;
  }
  // // Fall back to creation date if no modification date
  else {
    $mod_date = $doc->ds_created;
  }
  
  // Publication Date
  $item['pub_date'] = $pub_date;
  
  // Last modification Date
  $item['mod_date'] = $mod_date;
  
  // Recommended product of article.
  $item['recommended_products'] = igcommerce_utility_articles_products($recommended_product_article);
  // recommended article.
  $item['recommended_resources'] = igcommerce_utility_articles_resources($recommended_resource_article);
  
  // Footer of article.
  $item['recommended_card'] = igcommerce_utility_articles_solr_build_article_card_id($article_card_id);
  
  return theme('articles_detail_popup_details', array('item' => $item));
}


/*
 * Show the article card id of particular article resource.
 */

function igcommerce_utility_articles_solr_build_article_card_id($article_card_id) {
  global $language;

  $output = NULL;

  if (!empty($article_card_id)) {
    // Solr query to fetch data.
    $keyword = "entity_type:taxonomy_term";
    $parameter[]['rows'] = '1';
    $parameter[]['fl'] = 'ss_field_content_title';
    $filter[]['bundle'] = 'web_card_footer';
    $filter[]['ss_language'] = $language->language;
    $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);
    //Drupal function (accounts for user selected time zone)
    $datetime = date_now();
    //Drupal function to generate formated date/time output.
    $current_year = date_format_date($datetime, $type = 'custom', 'Y');
    $footer_text = NULL;
    if (!empty($data->response->docs)) {
      // Making year come first after message test.
      $footer_text .= '<b>&copy;' . $current_year . ' ' . t("Fluke Corporation.") . '</b> ';
      $footer_text .= $data->response->docs[0]->ss_field_content_title . ' ' . $article_card_id;
      $output .= $footer_text;
    }
  }
  return $output;
}

/**
 * Show the recommended article/toc of particular article resource.
 * Generates the related products on webcards. Uses the same
 * image styles for those as found on blog toc related stories.
 *
 */
function igcommerce_utility_articles_products($recommended_product_article_list) {

  global $language;

  $output = NULL;
  $i = 0;

  if (sizeof($recommended_product_article_list) > 0) {

    $output .= '<h3 class="pane-title">' . t("Recommended products") . '</h3>';
    $output .= '<div class="resource-wrapper">';

    foreach ($recommended_product_article_list as $product) {

      foreach ($product as $prod) {

        $rec_prod = igcommerce_utility_articles_get_product($prod->entity_id);

            if (!empty($rec_prod->url) && !empty($rec_prod->title)) {
                $output .= '<div class="toc-article-related-resource-wrapper">';
                $output .= '<div class="card">';
                $pic = igcommerce_utility_get_images($rec_prod->image);
                $alt = (!empty($rec_prod->alt)) ? $rec_prod->alt : $rec_prod->title;
                if (!is_null($rec_prod->image)) {
                   $output .= '<a href="/' . $language->language . '/' . $rec_prod->url . '">';
                   $output .= igcommerce_utility_format_image_blog_recent_stories($pic, $alt);
                   $output .= '</a>';
                }
                $output .= '<h5 class="toc-article-related-resource-title">';
                $output .= '<a href="/' . $language->language . '/' . $rec_prod->url . '">';
                $output .= $rec_prod->title;
                $output .= '</a>';
                $output .= '</h5>';

                /* taken out with mig-666
                if (!is_null($rec_prod->specs)) {
                   $output .= "<div class='article-related-product-see-spec'>";
                   $output .= '<a  data-toggle="modal" data-target="#specification-' . $i . '"  alt="" cursor="pointer" style="cursor:pointer">';
                   $output .= t('See specification') . '</a>';
                   $output .= '<div id="specification-' . $i . '" class="modal fade" role="dialog">
                                    <div class="modal-dialog">
                                       <div class="modal-content">
                                         <div class="modal-header">
                                           <a class="close" data-dismiss="modal" aria-label="Close">
                                             <span class="fluke-icon fluke-icon-close" aria-hidden="true">&nbsp;</span></a>
                                         </div>
                                         <div class="modal-body" id="specification_content">'
                        . $rec_prod->specs .
                        '</div>
                                        </div>
                                      </div>
                                    </div>';
                  $output .= "</div>";
                }
                */

              if (!is_null($rec_prod->datasheets)) {
                $output .= '<div class="article-related-product-download">';
                $output .= '<a href="' . $rec_prod->datasheets . '" target="_blank"  download>' . t('Download the datasheet') .  '</a>';
                $output .= '</div>';
              }

              /* taken out with mig666
              if (!empty($rec_prod->webcard)) {
                 $output .= "<div class='webcard'>";
                 $output .= '<a href = "' . $rec_prod->webcard['url'] . '">';
                 $output .= $rec_prod->webcard['alt'];
                 $output .= "</a>";
                 $output .= "</div>";
              }
              */

              $output .= '</div>';
              $output .= '</div>';
            }
      $i++;

      if ($i == 5) {
        return $output;
      }

     } // end of for-each product as prod

    } // end of for-each
    $output .= "</div>";
  } // end of is size > 0

  return $output;

} // end of function



/**
 * Show the recommended article/toc of particular article resource.
 */
function igcommerce_utility_articles_resources($recommended_resource_article_list) {

  global $language;

  $recommended_resources = array();

  foreach($recommended_resource_article_list as $resource) {

    if (is_object($resource)) {

      if (is_object($resource->dam_data)) {
        $resrc = new stdClass;
        $resrc->url = $resource->dam_data->url;
        $resrc->title = $resource->dam_data->alt;
        $resrc->alt = $resource->dam_data->alt;
        $resrc->image = $resource->dam_data->thumbnail;
        $recommended_resources[] = $resrc;
      }
      else if (!empty($resource->article_data)) {
        $recommended_resources[] = igcommerce_utility_articles_get_article($resource->article_data);
      }
      else {
          // it wasn't an article or a DAM item - should never happen
      }
    }
  }

  $output = NULL;

  if (sizeof($recommended_resources) > 0) {
    $output = '<h3>' . t('Recommended resources') . '</h3>';
    $output .= '<div class="webcard-recommended-resources-wrapper">';
    foreach ($recommended_resources as $resource) {
      $url  =  $resource->url;
      $output .= '<div class="toc-article-related-resource-wrapper">';
      $output .= '<div class="card">';
      $output .= '<h5 class="toc-article-related-resource-title">';
      $output .= '<a href="' . $url . '">';
      $output .= $resource->title;
      $output .= '</a>';
      $output .= '</h5>';
      $output .= '</div>';
      $output .= '</div>';
    } // end foreach
    $output .= '</div>';
  } // end if

  return $output;
}

/*
 * Show the CTA web card lead gen data for nevigation of particular page.
 */

function igcommerce_utility_articles_cta_links($cta_entity_reference_id) {
  global $language;
  $output = NULL;

  if (!empty($cta_entity_reference_id)) {
    $keyword = "entity_type:node";
    $parameter[]['rows'] = '1';
    $parameter[]['fl'] = 'sm_cta_left_coll';
    $parameter[]['fl'] = 'sm_cta_right_coll';
    $parameter[]['fl'] = 'ss_language';
    $filter[]['bundle'] = 'cta_web_card_lead_gen';
    $filter[]['entity_id'] = $cta_entity_reference_id;
    $filter[]['ss_language'] = $language->language;
    $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);

    if (!empty($data->response->docs[0]->sm_cta_left_coll[0])) {
      $cta_left_coll_data = json_decode($data->response->docs[0]->sm_cta_left_coll[0]);
    }

    if (!empty($data->response->docs[0]->sm_cta_right_coll[0])) {
      $cta_right_coll_data = json_decode($data->response->docs[0]->sm_cta_right_coll[0]);
    }
    // Panel Content wrapper start.
    $output .= '<div class = "pane-related-items"><div class = "pane-content">';

    // Show left col link button.
    $output .= '<div>';
    $output .= '<a class ="btn btn-primary" target="_blank" href = "' . $cta_left_coll_data->url . '" >' . $cta_left_coll_data->label . '</a>';
    $output .= '</div>';

    // Show right col link button.
    $output .= '<div>';
    $output .= '<a class ="btn btn-blue" target="_blank" href = "' . $cta_right_coll_data->url . '" >' . $cta_right_coll_data->label . '</a>';
    $output .= '</div>';

    $output .= '<div class = "clearfix"></div>';

    // Panel content Wrapper end
    $output .= '</div></div>';
  }

  return $output;
}

function igcommerce_utility_articles_get_product($entity_id) {

    global $language;
    $content = NULL;

    $options = array(
            "entity_id" => $entity_id,
            "ss_language" => $language->language,
            "bundle" => "product_display",
    );

    $fields = 'path_alias, tm_field_content_title, path_alias, tm_specs, tm_datasheets, tm_web_card_details, is_product_slideshow';

    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query, array('filters' => $options, 'rows' => 1));
    $response = fluke_solr_query($filters);
    $items = json_decode($response->data);

    if (is_object($items->response->docs[0])) {
        $resrc = new stdClass;
        $resrc->url = $items->response->docs[0]->path_alias;
        $resrc->title = $items->response->docs[0]->ss_field_content_title;
        $resrc->alt = $items->response->docs[0]->ss_field_content_title;
        $resrc->image = NULL;
        
        if (!empty($items->response->docs[0]->is_product_slideshow)) {
          $slideshow = fluke_solr_get_entity($items->response->docs[0]->is_product_slideshow, 'node', 'slideshow', $language->language);
          if (!empty($slideshow->sm_field_product_image_desktop[0])) {
             $slide = json_decode($slideshow->sm_field_product_image_desktop[0]);
             $resrc->image = $slide->url;
          }
        }
        if (isset($items->response->docs[0]->tm_datasheets) &&
            sizeof($items->response->docs[0]->tm_datasheets) > 0) {
             $data_sheet = json_decode($items->response->docs[0]->tm_datasheets[0]);

             // Should be an object
             if (is_object($data_sheet)) {
               $resrc->datasheets = $data_sheet->url;
             }
             // Leaving in just in case these are sent through as arrays
             if (is_array($data_sheet) && !empty($data_sheet[0]->url)) {
               $resrc->datasheets = $data_sheet[0]->url;
             }
        }
        else {
           $resrc->datasheets = NULL;
        }

        if (isset($items->response->docs[0]->tm_specs)) {
           $resrc->specs = $items->response->docs[0]->tm_specs[0];
        }
        else {
           $resrc->specs = NULL;
        }

        if (isset($items->response->docs[0]->tm_web_card_details) &&
            sizeof($items->response->docs[0]->tm_web_card_details) > 0) {
           $webcard = json_decode($items->response->docs[0]->tm_web_card_details[0]);
           $resrc->webcard['url'] = $webcard->url;
           if (strlen($webcard->alt) > 0) {
             $resrc->webcard['alt'] = $webcard->alt;
           }
           else {
             $resrc->webcard['alt'] = t('Webcard');
           }

        }

        return $resrc;

     }
     else {
       return NULL;
     }
}


function igcommerce_utility_articles_get_article($entity_id) {

    global $language;
    $content = NULL;

    $options = array(
            "entity_id" => $entity_id,
            "ss_language" => $language->language,
            "bundle" => "article",
    );

    $fields = 'path_alias, tm_field_content_title, ss_toc_featured_img_url';

    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query, array('filters' => $options, 'fl' => $fields, 'rows' => 5));
    $response = fluke_solr_query($filters);

    $items = json_decode($response->data);

    if (is_object($items->response->docs[0])) {
        $resrc = new stdClass;
        $resrc->url = "/" . $language->language . "/" . $items->response->docs[0]->path_alias;
        $resrc->title = $items->response->docs[0]->tm_field_content_title[0];
        $resrc->alt = $items->response->docs[0]->tm_field_content_title[0];
        $resrc->image = $items->response->docs[0]->ss_toc_featured_img_url;
        return $resrc;
     }
     else {
       return NULL;
     }

}
