<?php

/*
 * @file
 * New functions added to fetch the data from solr for
 * category, sub category, Article list , banner image, and left menu bar , Recommened resources and products.
*/

/**
 * Render the appropriate Banner for TOCs
 */
function igcommerce_utility_articles_solr_toc_banner()
{
    $output = NULL;
    global $language;
    $path = '';
    $path = array_reverse(explode('/', current_path()));
    $arg = count($path);
    ++$arg;
    $desktop_banner_image_uri = NULL;
    $tablet_banner_image_uri = NULL;
    $mobile_banner_image_uri = NULL;
    $desktop_image = FALSE;
    $tablet_image = FALSE;
    $mobile_image = FALSE;
    $alt = NULL;

    foreach ($path as $filter_1) {
        $filter = '';

        // if there is a banner on the term associated with this page then load the URLs.
        // If not, the look for the banner image ofthe parent term of this pages term
        $keyword = "bundle:url_builder";
        $parameter[]['fl'] = 'tm_header_banner_image_desktop';
        $parameter[]['fl'] = 'tm_header_banner_image_tablet';
        $parameter[]['fl'] = 'tm_header_banner_image_mobile';
        $filter[]['sm_url_path_builder'] = $filter_1;
        $filter[]['sm_term_depth'] = $arg;
        $filter[]['ss_language'] = $language->language;
        $result = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);        --$arg;

        if (!empty($result->response->docs)) {
            $data = $result->response->docs[0];

            igcommerce_utility_head_elements($data, true);

            if (isset($data->tm_header_banner_image_desktop[0])) {
                $desktop_banner = json_decode($data->tm_header_banner_image_desktop[0]);
                $desktop_image = $desktop_banner->url;
            }
            if (isset($data->tm_header_banner_image_tablet[0])) {
                $tablet_banner = json_decode($data->tm_header_banner_image_tablet[0]);
                $tablet_image = $tablet_banner->url;
            }
            if (!empty($data->tm_header_banner_image_mobiles)) {
                $mobile_banner = json_decode($data->tm_header_banner_image_mobile[0]);
                $mobile_image = $mobile_banner->url;
            }
            $alt = $filter_1;
            $output = igcommerce_utility_determine_banner_image($desktop_image, $tablet_image, $mobile_image, $alt);
        }
        //if the banner is found return the output else look for the parent term banner
        if (isset($output)) {
            return $output;
        }
    }

    if (empty($output)) {
        $default_banner = variable_get('default_banner_image', FALSE);
        $alt = $filter_1;
        $output = igcommerce_utility_determine_banner_image($default_banner, $default_banner, $default_banner, $alt);
    }
    return $output;
}

/**
 * Render the appropriate Display Title as an H1 for TOCs
 * If H1 title is empty, use content title - MIG1015
 */
function igcommerce_utility_articles_solr_toc_h1() {
  $toc = igcommerce_utility_load_toc_from_path();

  igcommerce_utility_head_elements($toc, TRUE);
  
  $term = igcommerce_utility_load_term_from_path();

  if (!empty($toc->ss_field_h1_title)) {
    return '<h1 class="toc-title">' . $toc->ss_field_h1_title .'</h1>';
  }
  if (!empty($toc->ss_field_content_title)) {
    return '<h1 class="toc-title">' . $toc->ss_field_content_title .'</h1>';
  }
  
  if (!empty($term->ss_url_builder_term_h1_title)) {
    return '<h1 class="toc-title">' . $term->ss_url_builder_term_h1_title .'</h1>';
  }
  if (!empty($term->sm_field_content_title[0])) {
    return '<h1 class="toc-title">' . $term->sm_field_content_title[0] .'</h1>';
  }
  
	return;
}

/**
 * Return the toc for a given path. If no path specified, the current url is used.
 */
function igcommerce_utility_load_toc_from_path($path = NULL, $lang = NULL, $reset = FALSE, $bundle = 'toc', $entity_type = 'node') {
  if (!$lang) {
    global $language;
    $lang = $language->language;
  }
  if (!$path) {
    $path = current_path();
  }

  if (!$reset) {
    if ($cache = &drupal_static(__FUNCTION__, NULL)) {
      if (!empty($cache[$path])) {
        return $cache[$path];
      }
    }
  }

  $filters['filters'] = array(
    'ss_path_alias' => '"' . $path . '"',
    'ss_language' => $lang,
    'bundle' => $bundle,
    'entity_type' => $entity_type,
  );

  $query = fluke_solr_get_connection();
  $query = fluke_solr_add_filters($query, $filters);
  $data = fluke_solr_query($query);

  if (!empty($data->response->docs[0])) {
    // Add metatags
    igcommerce_utility_head_elements($data->response->docs[0]);
    
    $cache[$path] = $data->response->docs[0];
    return $cache[$path];
  }
}

/**
 * Return the url_builder taxonomy term for a given path. If no path specified, the current url is used.
 */
function igcommerce_utility_load_term_from_path($original_path = NULL, $lang = NULL, $reset = FALSE) {
  if (!$lang) {
    global $language;
    $lang = $language->language;
  }
  
  if (!$original_path) {
     $original_path = current_path();
  }
  
  if (!$reset) {
    if ($cache = &drupal_static(__FUNCTION__, NULL)) {
      if (!empty($cache[$original_path])) {
        return $cache[$original_path];
      }
    }
  }
  
  $filters['filters'] = array(
      'ss_path_alias' => $original_path,
      'ss_language' => $lang,
      'bundle' => 'url_builder',
  );
  
  $query = fluke_solr_get_connection();
  $query = fluke_solr_add_filters($query, $filters);
  $data = fluke_solr_query($query);
  
  if (!empty($data->response->docs[0])) {
    $cache[$original_path] = $data->response->docs[0];
    return $cache[$original_path];
  }
}

/**
 * Output the appropriate Description for TOCs
 */
function igcommerce_utility_articles_solr_toc_description() {
  global $language;
  global $base_url;
  $output = NULL;

  $term = igcommerce_utility_load_term_from_path();
  $toc = igcommerce_utility_load_toc_from_path();

  igcommerce_utility_head_elements($toc, TRUE);

  $vars = array();
  // Try loading the toc description first
  if (!empty($toc->ts_description_field)) {
    $vars['content'] = $toc->ts_description_field;
  } elseif (!empty($term->sm_description)) {
    $vars['content'] = $term->sm_description[0];
  } else {
    $vars['content'] = '';
    //return '';
  }
  
  $matches = array();
  preg_match_all('~(["\']node\/\d.*?[\'"])~', $vars['content'], $matches, PREG_PATTERN_ORDER);
  if (!empty($matches[0])) {
    foreach ($matches[0] as $match) {
      $path = trim($match, '/');
      $path = trim($match, '"');
      $parts = explode('/', $path);
      if (!empty($parts[1])) {
        $entity_id = $parts[1];
      } else {
        continue;
      }
      $alias = NULL;
      if (!$entity = fluke_solr_get_entity($entity_id, 'node', 'e_link', $language->language, 'ecm')) {
        continue;
      }
      if ($entity->bundle == 'e_link') {
        if (!empty($entity->ss_external_url)) {
          $alias = $entity->ss_external_url;
        }
      } else {
        if (!empty($entity->ss_path_alias_locale)) {
          $alias = $entity->ss_path_alias_locale;
        }
      }
      
      if ($alias && $alias != $path) {
        $alias = url($alias, array('absolute' => TRUE));
        $vars['content'] = str_replace($match, "'$alias'", $vars['content']);
      }
    }
  }
  
  // Adding CTA link under description of TOCs
  if(isset($term->bs_field_toc_type) && $term->bs_field_toc_type == TRUE) {
    $term_cta = fluke_solr_get_toc_cta($language->language, $term->entity_id, $term->entity_type);
    if($term_cta != NULL) {
      $vars['cta'] = json_decode($term_cta->sm_cta_left_coll[0]);
    }
  } else {
    $toc_cta = fluke_solr_get_toc_cta($language->language, $toc->entity_id, $toc->entity_type);
    if($toc_cta != NULL) {
      $vars['cta'] = json_decode($toc_cta->sm_cta_left_coll[0]);
    }
  }
  
  return theme('articles_toc_description', $vars);
}

//TODO remove this?
function igcommerce_utility_articles_solr_check_toc_tokens($string, $lang = NULL) {
  return;
  
  if (!$lang) {
    global $language;
    $lang = $language->language;
  }
  
  $tokens = token_scan($string);
  
  if (empty($tokens)) {
    return $string;
  }
  
  foreach ($tokens as $type => $children) {
    foreach ($children as $key => $token) {
      if ($type == 'toc') {
        $alias = '/' . $lang . '/' . drupal_get_path_alias($key, $lang);
        $string = str_replace($token, $alias, $string);
      }
    }
  }
  
  return $string;
}

/**
 * Function to get sub category list on in main content.
 *
 */
function igcommerce_utility_articles_solr_category_toc_listing() {
  global $language;
  $output = NULL;

  // If we're on an admin page ie: panels, then skip this function
  if (in_array(arg(0), array('admin', 'panels'))) {
    return;
  }
  
  // If viewing a toc render the articles
  if ($toc = igcommerce_utility_load_toc_from_path()) {
    return igcommerce_utility_articles_solr_build_category_toc_articles($toc);
  }
  
  // We aren't on a toc, instead display subcategories and link to toc page
  // TODO move to a tpl template ?
  if (!$term = igcommerce_utility_load_term_from_path($original_path = NULL, $lang = NULL, $reset = TRUE)) {
    // 404
    drupal_not_found();
  }
  
  if (!$children = igcommerce_utility_load_term_children($term->entity_id)) {
    // 404
    drupal_not_found();
  }
  
  $output .= "<div class='toc-listing-image-wrapper'>";

  igcommerce_utility_head_elements($term, TRUE);
  
  $has_children = FALSE;
  foreach ($children as $term) {
    //hide the menu if field_hide_from_toc_left_navigat is set
    if(!empty($term->bs_field_hide_from_toc_left_navigat)) {
      continue;
    }
    
    $has_children = TRUE;
    $class = array();
    // Allow for external links in ss_field_url
    if(empty($term->ss_field_url)) {
      $toc_item_url = igcommerce_utility_articles_build_url($term);
      
      $tmp = explode('/', $term->ss_path_alias);
      $class[] = 'event-' . array_shift($tmp);
    }else{
      $toc_item_url = new stdClass();
      // Check if the url should be translated
      $url = $term->ss_field_url;
      if ($path = igcommerce_utility_url_get_locale_path($url, $language->language)) {
        $url = $path;
      }
      $toc_item_url->link = $url;
    }
  
    if (empty($term->ts_cat_img_toc_desktop)) {
      $pic = igcommerce_utility_determine_toc_image();
    } else {
      $img = json_decode($term->ts_cat_img_toc_desktop);
      $images = igcommerce_utility_get_images($img->img_url);
      $pic = igcommerce_utility_format_image_product_category($images, $img->alt, $term->sm_field_content_title[0]);
    }
  
    // Output the TOC item
    $output .= "<div class='toc-listing-item-wrapper'>";
  
    $output .= "<div class='toc-listing-image'>";
    $output .= l($pic, urldecode($toc_item_url->link), array('html' => TRUE, 'language' => $language, 'attributes' => array('class' => $class)));
    $output .= "</div>"; // end of image
  
    if (!empty($term->sm_field_content_title[0])) {
      $output .= "<div class='toc-listing-title'>";
      $link_copy = "<h3 class='toc-listing-title-h3'>";
      $link_copy .= $term->sm_field_content_title[0];
      $link_copy .= "</h3>";
      $output .= l($link_copy, $toc_item_url->link, array('html' => TRUE, 'language' => $language, 'attributes' => array('class' => $class)));
      $output .= "</div>"; // end of title wrapper
    }
    $output .= "</div>"; // end of item wrapper
  }
  
  if (!$has_children) {
    //404
    drupal_not_found();
  }
  
  $output .= "</div>"; // end of image wrapper
  
  return $output;
}

/**
 * Returns a themed output of webcard article links and images. These are found on solutions/%/% pages
 */
function igcommerce_utility_articles_solr_build_category_toc_articles($doc)
{
  global $base_url, $language;

  drupal_add_css(drupal_get_path('module', 'igcommerce_utility_articles') . '/css/igcommerce_utility_articles.css');
  drupal_add_js(drupal_get_path('module', 'igcommerce_utility_articles') . '/js/igcommerce_utility_articles.js');

  // May need this down there somewhere
  $fallback_lang = fluke_solr_fallback_get_fallback_language($language->language);
  
  $output = NULL;
  $image_url_desktop = NULL;
  $image_url_tablet = NULL;
  $image_url_mobile = NULL;
  $card_size = NULL;
  $items = array();
  
  // Fetching toc article and card size.
  if (!empty($doc->sm_toc_related_article[0])) {
    // Making article listing array.
    $article_details = array();
    $article_string = NULL;
    $target_query = NULL;
    $articles_order = array();
    foreach ($doc->sm_toc_related_article as $target) {
      $target_query .= $target . ' ';
      array_push($articles_order, $target);
    }

    // TODO add a helper function that'll query these so we can reuse it elsewhere
    $target_query = 'entity_id:(' . str_replace(' ', ' OR ', trim($target_query)) . ')';
  
    if (!empty($target_query) && ($target_query != ")")) {
      // Feching data from article.
      // Query to fetch data from article pbased on $article_string from toc.
      $options = array(
          "bundle" => "article",
          "bs_status" => TRUE,
          "entity_type" => 'node',
          "ss_language" => $language->language,
      );
  
      $query = fluke_solr_get_connection();
      $filters = fluke_solr_add_filters($query,
          array(
              'q' => $target_query,
              'rows' => 100,
              'filters' => $options,
              'fl' => 'entity_id,ss_toc_large_img_url,ss_toc_medium_img_url,ss_toc_small_img_url,ss_field_content_title,sm_url_path_builder,path_alias,ss_path_alias,ss_path_alias_locale,ss_language',
          )
      );
      $article_data = fluke_solr_query($filters);
  
      // Adding article value in article_details array.
      if (!empty($article_data->response->docs)) {
        // Used Reverse array because in "OR" condition of solr retuning value in  reversed order.
        // $article = array_reverse($article_data->response->docs);
        foreach ($articles_order as $order) {
          foreach ($article_data->response->docs as $article_key => $article_value) {
            if ($order == $article_value->entity_id) {
              $article_details[$article_value->entity_id]['article'] = $article_value;
            }
          }
        }
      }
      // Display the article list.
      if (!empty($article_details)) {
        $i = 0;
        $size_count = 0;
        foreach ($article_details as $article_listing_key => $article_listing_value) {
          if (!empty($article_listing_value['article']->ss_field_content_title)) {
            // Images for article listing.
            $image_url = !empty($article_listing_value['article']->ss_toc_large_img_url) ? $article_listing_value['article']->ss_toc_large_img_url : '';
            
            // Title of article.
            $node_title = $article_listing_value['article']->ss_field_content_title;
            
            // Making path for webcard.
            $node_path = '';
            if (!empty($article_listing_value['article']->path_alias)) {
              $node_path = '/' . $language->language . '/' . $article_listing_value['article']->path_alias;
            }
  
            if (isset($node_path)) {
              // Output the TOC item
              $items[$i]['size'] = 'data-inner-width="75%" data-inner-height="90%"';
              $items[$i]['path'] = $node_path;
              $items[$i]['title'] = $node_title;
              
              // Card Size.
              if ($i == 0) {
                $card_size = 'Large';
                array_shift($article_details);
              }
              if ($i > 0) {
                if ($size_count <= 2) {
                  $card_size = 'Medium';
                  $size_count ++;
                }
                if ($size_count > 2 || $size_count == 4) {
                  $card_size = 'Large';
                  $size_count ++;
                }
                if ($size_count == 5) {
                  $size_count = 0;
                }
              }
              //                                $items[$i]['card_size'] = $article_listing_value['card_size'];
              if ($card_size == 'Large') {
                $pic = igcommerce_utility_format_image_webcard_large($image_url, $node_title);
              } else {
                $pic = igcommerce_utility_format_image_webcard_small($image_url, $node_title);
              }
              $items[$i]['image'] = $pic;
              $items[$i]['card_size'] = $card_size;
            }
          }
          $i++;
  
        } // End of foreach.
      } // End of article.
    }
  }
  return theme('articles_categories', array('items' => $items));
  
}

//For Recommended resources, first the TOC node is fetch from Solr
//using last taxonomy term and the parent term from url path.
//The node contains reference ids of the products from ECM under the Related Articles\Resources\Products
//In second query we fetch the articles from solr using reference ids.
function igcommerce_utility_articles_solr_build_toc_url_products()
{
  global $language;

  $count = 0;
  $path = '';
  $items = array();
  $fields = '';
  $article_details = array();
  
  if (!$doc = igcommerce_utility_load_toc_from_path()) {
    return;
  }

  igcommerce_utility_head_elements($doc, TRUE);
  
  // Don't display if we are in the products tree
  // Uncomment and re-code if  this is needed
  /*
  $child_tid = $node->field_url_builder[LANGUAGE_NONE][0]['tid'];
  $ancestors = taxonomy_get_parents_all($child_tid);
  
  foreach($ancestors as $parent){
    if($parent->name === 'Products'){
      return '';
    }
  }
  
  if (!$doc = fluke_solr_get_entity($node->nid, 'node', 'toc', $language->language)) {
    return;
  }
  */
  
  // Fetching toc article and card size.
  $product_string = NULL;
  $articles_order = array();
  if(isset($doc->sm_related_resource_product) && !empty($doc->sm_related_resource_product)) {
    foreach ($doc->sm_related_resource_product as $target) {
      if (empty($product_string)) {
        $product_string .= "entity_id:(" . $target;
      } else {
        $product_string .= " OR " . $target;
      }
      array_push($articles_order, $target);
    }
    $product_string .= ")";
  }
  if (!empty($product_string) && $product_string != ")") {
    // Fetching data from article.
    // Query to fetch data from article based on $product_string from toc.
    $options = array(
        "bs_status" => TRUE,
        "ss_group" => 'product', //MIG2490: Prevents unpublished products from showing blank.
        "bundle" => "product_display",
        "ss_language" => $language->language,
        "entity_type" => 'node'
    );
  
    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query,
        array(
            'q' => $product_string,
            'rows' => 100,
            'filters' => $options,
            //'fl' => 'entity_id,ss_field_content_title,sm_url_path_builder,ss_language,path_alias,tm_web_card_details,is_product_slideshow,tm_specs,tm_datasheets',
        )
    );
    $article_product_data = fluke_solr_query($filters);
  
    foreach ($articles_order as $order) {
      foreach ($article_product_data->response->docs as $article_key => $article_value) {
        if ($order == $article_value->entity_id) {
          $article_details[$article_value->entity_id] = $article_value;
        }
      }
    }
  
    $i = 0;
    if (!empty($article_details)) {
      foreach ($article_details as $article_product_key => $article_product) {
        if (!empty($article_product)) {
  
          // Display product result.
          //display only 4 products
          if ($count < 4) {

            // Datasets.
            if (!empty($article_product->tm_datasheets[0])) {
              $datasheet_data = json_decode($article_product->tm_datasheets[0]);
              $items[$i]['datasheet_url'] = isset($datasheet_data->url) ? $datasheet_data->url : '';
              $items[$i]['datasheet_alt'] = isset($datasheet_data->alt) ? $datasheet_data->alt : '';
            }
  
            $path_url = igcommerce_utility_product_tocs_get_url($article_product);

            $lang_local = igcommerce_utility_get_local();
            $items[$i]['path_url'] = $lang_local.'/'.$path_url;
            $items[$i]['language'] = $language->language;
  
            if (isset($path_url)) {
              $items[$i]['link'] = $path_url;
              $items[$i]['alt'] = (!empty($alt)) ? $alt : $article_product->ss_field_content_title;
            }

            // Get the images
            if (!empty($article_product->is_product_slideshow)) {
              $nid = $article_product->is_product_slideshow;
              $slideshow = fluke_solr_get_entity($nid, 'node', 'slideshow', $language->language);
              if (empty($slideshow->sm_field_product_image_desktop[0])) {
                $pic = igcommerce_utility_determine_toc_image();
              } else {
                $img = json_decode($slideshow->sm_field_product_image_desktop[0]);
                $images = $img->url;
                // If they don't set an alt tag for the image, use the alt tag from above.
                if(!empty($img->alt)) {
                  $alt = $img->alt;
                }
                // Use the same picture tag styling as found on the blog homepage recent stories section.
                $pic = igcommerce_utility_format_image_blog_recent_stories($images, $alt);
              }
              $items[$i]['image'] = $pic;
            }
  
            if (!empty($article_product->ss_field_content_title)) {
              $items[$i]['title'] = $article_product->ss_field_content_title;
            }
            //creates a pop up of the product details using model.
            if (!empty($article_product->tm_specs[0])) {
              $items[$i]['specs'] = $article_product->tm_specs[0];
              $items[$i]['count'] = $count;
            }
  
            // Web card
            if (!empty($article_product->tm_web_card_details)) {
              $webcard_arr = json_decode($article_product->tm_web_card_details[0]);
              $items[$i]['webcard_url'] = $webcard_arr->url;
              $items[$i]['webcard_alt'] = $webcard_arr->alt;
            }
            ++$count;
          }
          $i++;
        }
      }
    }
  }
  
  
  return theme('articles_recommended_products', array('items' => $items));
}

//For Recommended resources, first the TOC node is fetch from Solr
//using last taxonomy term and the parent term from url path.
//The node contains reference ids of the articles under the Related Articles\Resources\Products
//In second query we fetch the articles from solr using refernce ids.
function igcommerce_utility_articles_solr_build_toc_url_resources() {
  global $language;

  $count = 0;
  $path = '';
  $items = array();
  $fields = '';
  $card = array();
  $article_details = array();
  
  if (!$doc = igcommerce_utility_load_toc_from_path()) {
    return '';
  }

  igcommerce_utility_head_elements($doc, TRUE);
  
  $target_query = '';
  $articles_order = array();
  if (!empty($doc->sm_related_resources)) {
    $i = 0;
    foreach ($doc->sm_related_resources as $json) {
      $data = json_decode($json);
      // If Articles, Collect all referenced nodes for solr query
      if ($target = $data->article_data) {
        $target_query .= $target . ' ';
        array_push($articles_order, $target);
      }
      
      // If digital assets, add them to items for display
      if ($target = $data->dam_data) {
        $items[$i]['webcard_url'] = $target->url;
        $items[$i]['webcard_alt'] = t($target->alt);
        $i++;
      }
    }
    
    $target_article_query = 'entity_id:(' . str_replace(' ', ' OR ', trim($target_query)) . ')';
    $options = array(
        "ss_language" => $language->language,
        "bundle" => "article",
        "entity_type" => "node",
    );
  
    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query, array('q' => $target_article_query, 'filters' => $options, 'fl' => $fields, 'rows' => 5));
    $response = fluke_solr_query($filters);

    foreach ($articles_order as $order) {
      foreach ($response->response->docs as $article_key => $article_value) {
        if ($order == $article_value->entity_id) {
          $article_details[$article_value->entity_id] = $article_value;
        }
      }
    }
    if (!empty($article_details)) {
      foreach ($article_details as $article_key => $article_data) {
        if (!empty($article_details)) {
          // Display product result.
          //display only 4 products
          if ($count < 4) {
            // Datasets.
            if (isset($article_data->tm_datasheets)) {
              $datasheet_data = json_decode($article_data->tm_datasheets[0]);
              $items[$i]['datasheet_url'] = $datasheet_data[0]->url;
              $items[$i]['datasheet_alt'] = $datasheet_data[0]->alt;
            }
  
            //TODO Need a helper function to handle this as it's done all over the place surely
            $path =
            $url_builder = json_decode($article_data->sm_url_path_builder[0]);
            array_pop($url_builder);
            $url_builder = array_reverse($url_builder);
            $path = implode('/', $url_builder) . '/' . $article_data->ss_field_url_title;
            
            if (isset($article_data->path_alias)) {
              $items[$i]['link'] = '/' . $language->language . '/' . $path;
            }
  
            if (!empty($article_data->ss_field_content_title)) {
              $items[$i]['title'] = $article_data->ss_field_content_title;
              $items[$i]['alt'] = (!empty($alt)) ? $alt : $article_data->ss_field_content_title;
            }
            //creates a pop up of the product details using model.
            if (!empty($article_data->tm_specs[0])) {
              $items[$i]['specs'] = $article_data->tm_specs[0];
              $items[$i]['count'] = $count;
            }
            ++$count;
          }
          $i++;
        }
      }
    }
    
    return theme('articles_recommended_resources', array('items' => $items));
  }
  
  return NULL;
}

//
function igcommerce_utility_articles_solr_toc_sub_rel_articles()
{
    global $language;
    global $base_url;
    $output = NULL;
    $path = explode('/', current_path());
    $depth = count($path);
    ++$depth;

    $filter_1 = end($path);
    $keyword = "bundle:url_builder";
    $parameter[]['fl'] = 'tm_related_resource';
    $filter[]['sm_term_depth'] = $depth;
    $filter[]['sm_url_path_builder'] = $filter_1;
    $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);

    //if this taxonmy (Category) have sub category
    if (!empty($data->response->docs)) {
        foreach ($data->response->docs as $result) {
            $output .= $result->tm_related_resource[0];
        }
    }
    return $output;
}

/**
 * Article Solr - Description /Summary
 * Will be use if article pages (checking with url_title).
 */
function igcommerce_utility_articles_solr_desc() {
  global $language;

  $data = igcommerce_utility_articles_load_article(NULL, $language->language);
  
  // If we're on an admin page ie: panels, then skip this function
  if (in_array(arg(0), array('admin', 'panels'))) {
    return;
  }
  
  if (empty($data->ts_article_body)) {
    drupal_not_found();
  }
  
  $output = '<div itemprop="articleBody">';
  $output .= $data->ts_article_body;
  $output .= '</div>';

  igcommerce_utility_head_elements($data, TRUE);

  return $output;
}

/**
 * Article Solr - Sub title
 * Will be use if article pages (checking with url_title).
 */
function igcommerce_utility_articles_solr_subtitle()
{
  global $language;
  $output = '';

  $data = igcommerce_utility_articles_load_article(NULL, $language->language);

  if (!empty($data->ss_article_subtitle)) {
    $output .= "<h2>".$data->ss_article_subtitle."</h2>";
  }

  return $output;
}

/**
 * Returns an article solr object or false if none found
 * @param string $path_alias
 * @param string $lang
 * @param string $status
 */
function igcommerce_utility_articles_load_article($path = NULL, $lang = 'en-us', $status = TRUE) {
  $cache = &drupal_static(__FUNCTION__, array());
  
  if (!$path) {
    $path = current_path();
  }
  
  if (!empty($cache[$path][$lang][$status])) {
    return $cache[$path][$lang][$status];
  }
  
  $filters['filters'] = array(
      'entity_type' => 'node',
      'bundle' => "article",
      'ss_language' => $lang,
      //'sm_article_type' => $article_term->entity_id,
      'bs_status' => $status, // only interested in published articles
      //'ss_toc_featured_img_url' => '[" TO *]', // uncomment if only want to return articles with images
      'ss_path_alias' => '"' . $path . '"',
  );
  
  $filters['rows'] = 1;
  
  $query = fluke_solr_get_connection();
  $query = fluke_solr_add_filters($query, $filters);
  $response = fluke_solr_query($query);

  if (empty($response->response->docs)) {
    return;
  }
  
  $cache[$path][$lang][$status] = $response->response->docs[0];
  return $response->response->docs[0];
}

/**
 * Article Solr - Display Title / H1
 * Will be use if article pages (checking with url_title).
 */
function igcommerce_utility_articles_solr_title() {
  global $language;
  $output = NULL;

  $data = igcommerce_utility_articles_load_article(NULL, $language->language);
  
  if (!empty($data->ss_article_h1_title)) {
    $output = "<h1 itemprop='headline'>" . $data->ss_article_h1_title . "</h1>";
    $output .= "<meta itemprop='mainEntityOfPage' content='" . $data->ss_article_h1_title . "' />";
  } else {
    if (!empty($data->ss_field_content_title)) {
      $output = "<h1 itemprop='headline'>" . $data->ss_field_content_title . "</h1>";
      $output .= "<meta itemprop='mainEntityOfPage' content='" . $data->ss_field_content_title . "' />";
      $output .= igcommerce_utility_articles_solr_build_social_share();
    }
  }
  
  return $output;
}

/**
 * Removes language from a given path.
 * @param string $arg (optional) will use current path if none provided
 * @return the current relative path without a language prefix
 */
function igcommerce_utility_get_relative_path($arg = NULL) {
  if (!$arg) {
    $arg = request_uri();
  }
  
  $path_alias = explode("/", ltrim($arg, '/'));
  $path_check = array_shift($path_alias);
  $path_alias = implode('/', $path_alias);
  
  return $path_alias;
}

/**
 * Article Publish Date
 * Returns HTML markup for article publish date
 */
function igcommerce_utility_articles_publish_date() {
  global $language;
  $output = NULL;

  $doc = igcommerce_utility_articles_load_article(NULL, $language->language);
  
  if (empty($doc->ds_created)) {
    return;
  }
  
  $date = new DateObject($doc->ds_created);
  $date_text = date_format_date($date, 'ig_article_date', NULL, $language->language);

  $output = '<div class="article-date">' . $date_text . '</div>';

  return $output;
}

function igcommerce_utility_articles_solr_header_image() {
  global $language;
  
  $doc = igcommerce_utility_articles_load_article(NULL, $language->language);
  
  if (empty($doc->sm_article_header_img[0])) {
    return;
  }
  
  $data = json_decode($doc->sm_article_header_img[0]);
  
  $img = array('path' => NULL, 'alt' => $doc->tm_article_display_title[0]);
  
  if (!empty($data->header_img_url)) {
    $img['path'] = $data->header_img_url;
    if (!empty($data->header_img_alt)) {
      $img['alt'] = $data->header_img_alt;
    }
    $image = theme('image', $img);
  }
  
  $output = '<div class="article-header-image">' . $image . '</div>';

  $img_caption = NULL;
  
  if (!empty($doc->ts_field_caption)) {
    $img_caption = $doc->ts_field_caption;
  }
  
  if ($img_caption) {
    $output .= '<div class="article-header-image-caption">' . $img_caption . '</div>';
  }
  return $output;
}

/**
 * Article Solr - Banner
 * Banner Logic apply to all support ,Training ,Footer content page
 * Or if it just article pages (checking with path_alias and url_title).
 */
function igcommerce_utility_articles_solr_banner() {
  global $language;
  $desktop_banner_image_uri = NULL;
  $tablet_banner_image_uri = NULL;
  $mobile_banner_image_uri = NULL;
  $output = NULL;
  $alt = NULL;
  $path_alias = current_path();
  $path = explode('/', $path_alias);
  $page = page_manager_get_current_page();

  // For  footer pages & support page & Support about-us page &training page & training -for educatore pages  fetching data from url title .
  if (!empty($page['name']) && ($page['name'] == 'page-products_test_tool_catalog' ||
      $page['name'] == 'page-footer_pages' ||
      $page['name'] == 'page-support_page' ||
      $page['name'] == 'page-support_about_page' ||
      $page['name'] == 'page-training_toc_article_pages' ||
      $page['name'] == 'page-page-training_toc_educators_pages')
  ) {

    $filter_1 = end($path);
  } else {
    $arg = request_uri();
    $path_alias = explode("/", ltrim($arg, '/'));
    $path_check = array_shift($path_alias);
    $path_alias = implode('/', $path_alias);
    $filter_1 = $path_alias;
  }
  $keyword = "bundle:article";
  $parameter[]['fl'] = 'tm_header_banner_image_desktop';
  $parameter[]['fl'] = 'tm_header_banner_image_tablet';
  $parameter[]['fl'] = 'tm_header_banner_image_mobile';

  if (!empty($page['name']) && ($page['name'] == 'page-products_test_tool_catalog' ||
      $page['name'] == 'page-footer_pages' ||
      $page['name'] == 'page-support_page' ||
      $page['name'] == 'page-support_about_page' ||
      $page['name'] == 'page-training_toc_article_pages' ||
      $page['name'] == 'page-page-training_toc_educators_pages')
  ) {
    $filter[]['ss_field_url_title'] = $filter_1;
  } else {
    $filter[]['path_alias'] = $filter_1;
  }
  $filter[]['ss_language'] = $language->language;
  $filter[]['bs_status'] = "true";


  $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);

  if (!empty($data->response->docs)) {
    if (!empty($data->response->docs[0]->tm_header_banner_image_desktop[0])) {
      $desktop_banner = json_decode($data->response->docs[0]->tm_header_banner_image_desktop[0]);
      $desktop_banner_image_uri = $desktop_banner->url;
    }
    if (!empty($data->response->docs[0]->tm_header_banner_image_tablet[0])) {
      $tablet_banner = json_decode($data->response->docs[0]->tm_header_banner_image_tablet[0]);
      $tablet_banner_image_uri = $tablet_banner->url;
    }
    if (!empty($data->response->docs[0]->tm_header_banner_image_mobile[0])) {
      $mobile_banner = json_decode($data->response->docs[0]->tm_header_banner_image_mobile[0]);
      $mobile_banner_image_uri = $mobile_banner->url;
    }
    // If banner found in article.it is override-able at the page level, then the Parent taxonomy term, then the last default of the site banner
    if ($desktop_banner_image_uri != '' || $tablet_banner_image_uri != '' || $mobile_banner_image_uri != '') {
      $output = igcommerce_utility_determine_banner_image($desktop_banner_image_uri, $tablet_banner_image_uri, $mobile_banner_image_uri, $alt);
    } else {
      // If no banner image found in Article .It will check for banner in term at the page level.If banner not found in term, then it will check for Parent taxonomy term ,If no banner found in Parent Taxonomy term then the last default of the site banner will show.
      //$output = igcommerce_utility_articles_toc_banner();
    }
  } else {
    // If result empty .It will check for banner in term at the page level.If banner not found in term, then it will check for Parent taxonomy term ,If no banner found in Parent Taxonomy term then the last default of the site banner will show.
    //$output = igcommerce_utility_articles_toc_banner();
  }
  return $output;
}

/**
 * current_path is pointing to english path that's why it is showing english path insted of actual path.
 * This because batch process is written for Taxonomy .Other language Locale path will call internally to en-us path.
 * Fetch Tittle and description from URL Title
 *  Page : products/test-tool-catalog
 */
function igcommerce_utility_articles_product_details()
{
    global $language;
    $output = NULL;
    $path = explode('/', current_path());
    $url_title = array_pop($path);
    $keyword = "bundle:article";
    $parameter[]['fl'] = 'ss_field_content_title';
    $parameter[]['fl'] = 'ss_article_h1_title';
    $parameter[]['fl'] = 'tm_article_body';
    $filter[]['ss_field_url_title'] = $url_title;
    $filter[]['ss_language'] = $language->language;
    $filter[]['bs_status'] = "true";
    $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);

    if (!empty($data->response->docs[0])) {
        if (!empty($data->response->docs[0]->ss_article_h1_title)) {
            $output .= "<h3>" . $data->response->docs[0]->ss_article_h1_title . "</h3>";
        } else {
            if (!empty($data->response->docs[0]->ss_field_content_title)) {
                $output .= "<h3>" . $data->response->docs[0]->ss_field_content_title . "</h3>";
            }
        }
        if (!empty($data->response->docs[0]->tm_article_body[0])) {
            $output .= '<div class="article_body">' . $data->response->docs[0]->tm_article_body[0] . '</div>';
        }
    }

    return $output;
}
