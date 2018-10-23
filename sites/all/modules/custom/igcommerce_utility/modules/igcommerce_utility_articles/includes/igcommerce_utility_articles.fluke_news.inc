<?php

/**
 * @file
 * Utility file for handing all fluke news related functionality.
 */

function igcommerce_utility_articles_get_full_article_data($article_entity_id, $type) {
  global $language;

  $output = NULL;
  $article_sort = NULL;
  $article_parameter = array();
  $article_filter = array();
  if (!empty($article_entity_id) || isset($type)) {
    $article_keyword = "entity_type:node";
    $article_parameter[]['fl'] = 'entity_id';
    $article_parameter[]['fl'] = 'sm_field_content_title';
    $article_parameter[]['fl'] = 'ss_article_h1_title';
    $article_parameter[]['fl'] = 'tm_article_summary';
    $article_parameter[]['fl'] = 'ts_toc_featured_img_alt';
    $article_parameter[]['fl'] = 'ts_toc_featured_img_caption';
    $article_parameter[]['fl'] = 'ss_toc_featured_img_url';
    $article_parameter[]['fl'] = 'ts_toc_large_img_alt';
    $article_parameter[]['fl'] = 'ts_toc_large_img_caption';
    $article_parameter[]['fl'] = 'ss_toc_large_img_url';
    $article_parameter[]['fl'] = 'ts_toc_medium_img_alt';
    $article_parameter[]['fl'] = 'ts_toc_medium_img_caption';
    $article_parameter[]['fl'] = 'ss_toc_medium_img_url';
    $article_parameter[]['fl'] = 'ts_toc_small_img_alt';
    $article_parameter[]['fl'] = 'ts_toc_small_img_caption';
    $article_parameter[]['fl'] = 'ss_toc_small_img_url';
    $article_parameter[]['fl'] = 'sm_article_specialevent_img';
    $article_parameter[]['fl'] = 'path_alias';
    $article_parameter[]['fl'] = 'sm_vid_News_Topic';
    $article_parameter[]['fl'] = 'dm_field_publication_date';
    $article_filter[]['bundle'] = 'article';
    $article_filter[]['ss_language'] = $language->language;
    $article_filter[]['bs_status'] = "true";
    if (!empty($article_entity_id)) {
      $article_filter[]['entity_id'] = $article_entity_id;
    } elseif (isset($type) && ($type == t('recent_stories'))) {
      $article_filter[]['sm_vid_News_Topic'] = '[* TO *]';
      $article_sort = 'ds_changed desc';
    }

    $article_query = igcommerce_event_solr_query($article_keyword, $article_parameter, $article_filter, $article_sort);
//    dpm($article_query);
    $output = $article_query->response->docs;
  }

  return $output;
}

/*
 * Callback function for showing top stories.
 */

function igcommerce_utility_articles_toc_top_stories() {
  global $language;
  $output = NULL;
  $parameter = array();
  $filter = array();
  $path = explode('/', current_path());
  if (!empty($path) && ($path[0] == 'node') && !empty($path[1]) && !in_array('panels', $path)) {
    // Feching toc article and card size.
    $node_id = $path[1];
    //Parameters and filters for solr query
    $keyword = "bundle:toc";
    $parameter[]['rows'] = '1';
    $parameter[]['fl'] = 'sm_toc_top_stories';
    $filter[]['entity_id'] = $node_id;

    $toc_data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);

    // Getting product list from toc.
    if (!empty($toc_data->response->docs) && !empty($toc_data->response->docs[0]->sm_toc_top_stories[0])) {

      $toc_top_stories_data = json_decode($toc_data->response->docs[0]->sm_toc_top_stories[0]);
      // Making article listing array.
      $top_stories_details = array();
      $top_stories_string = NULL;

      foreach ($toc_top_stories_data as $key => $value) {
        $top_stories_details[$value->target_id]['top_stories'] = NULL;
        if (empty($top_stories_string)) {
          $top_stories_string .= "(" . $value->target_id;
        } else {
          $top_stories_string .= " OR " . $value->target_id;
        }
      }
      $top_stories_string .= ")";


      if (!empty($top_stories_string) && $top_stories_string != ")") {
        // Feching data from article.
        $top_stories_data = igcommerce_utility_articles_get_full_article_data($top_stories_string, NULL);

        foreach ($top_stories_data as $top_stories_data_key => $top_stories_data_value) {
          $top_stories[$top_stories_data_value->entity_id]['top_stories'] = $top_stories_data_value;
        }
        if (!empty($top_stories)) {
          $output .= '<h2 class= "pane-title">' . t('Top stories') . '</h2>';
          $count = 1;
          foreach ($top_stories as $top_stories_key => $top_stories_value) {
            if ($count <= 5 && !empty($top_stories_value['top_stories'])) {
              $desktop_thumb = NULL;
              $tablet_thumb = NULL;
              $mobile_thumb = NULL;
              $alt = NULL;
              //desktop image.
              if (!empty($top_stories_value->ss_toc_large_img_url)) {
                $desktop_thumb = $top_stories_value->ss_toc_large_img_url;
                $alt = $top_stories_value->ts_toc_large_img_alt;
              }
              //tablet image
              if (!empty($top_stories_value->ss_toc_medium_img_url)) {
                $tablet_thumb = $top_stories_value->ss_toc_medium_img_url;
                $alt = $top_stories_value->ts_toc_medium_img_alt;
              }
              //mobile image
              if (!empty($top_stories_value->ss_toc_small_img_url)) {
                $mobile_thumb = $top_stories_value->ss_toc_small_img_url;
                $alt = $top_stories_value->ts_toc_small_img_alt;
              }
              // generate the output using the igcommerce_utility_fomrat_image
              $pic = igcommerce_utility_determine_toc_image($desktop_thumb, $tablet_thumb, $mobile_thumb, $alt);

              $path_url = '';
              if (!empty($top_stories_value['top_stories']->path_alias)) {
                $path_url = $top_stories_value['top_stories']->path_alias;
              }

              $output .= "<div class='toc-feature-article-wrapper'>";

              // Image Wrapper.
              $output .= "<div class='toc-feature-article-image-wrapper'>";
              $output .= "<div class='toc-feature-article-image'>";
              $output .= '<a href="/' . $language->language . '/' . $path_url . '">';
              $output .= $pic;
              $output .= "</a>";
              $output .= "</div>"; // end of image
              $output .= "</div>"; // end of image wrapper.

              $output .= "<div class='toc-feature-article-detail-wrapper'>";
              $output .= "<div class='toc-feature-article-detail-title-wrapper'>";
              // Title of article.
              if (!empty($top_stories_value['top_stories']->ss_field_content_title)) {
                $output .= "<h3 class='toc-article-related-resource-title'>";
                $title = $top_stories_value['top_stories']->ss_field_content_title;
                $output .= '<a href= "/' . $language->language . '/' . $path_url . '" alt="' . $title . '">';
                $output .= $title;
                $output .= "</a>";
                $output .= "</h3>";
              }
              $output .= "</div>";

              // Description of article
              if (!empty($top_stories_value['top_stories']->tm_article_summary)) {
                $output .= "<div class='toc-feature-article-detail-description-wrapper'>";
                $output .= $top_stories_value['top_stories']->tm_article_summary[0];
                $output .= "</div>";
              }

              //Date and topic link.
              $output .= "<div class='toc-feature-article-date-topic-wrapper'>";
              if (!empty($top_stories_value['top_stories']->dm_field_publication_date)) {
                $date_formatted = explode('T', $top_stories_value['top_stories']->dm_field_publication_date[0]);
                $date_str = date('m-d-Y', strtotime($date_formatted[0]));
                $output .= '<span>' . $date_str . '</span>';
              }

              if (!empty($top_stories_value['top_stories']->sm_vid_News_Topic)) {
                $topic_category = $top_stories_value['top_stories']->sm_vid_News_Topic;
                // alphabetically order
                asort($topic_category);
                $topic_category_link = array();
//                foreach ($topic_category as $topic_key => $topic_value) {
//                  $term_data = taxonomy_get_term_by_name(strtolower($topic_value), 'url_builder');
//                  $term = array_shift($term_data);
//                  if (!empty($term)) {
//                    $topic_category_link[] = l(t('@name', array('@name' => $term->field_content_title[$language->language][0]['value'])), 'solutions/fluke-news/' . $term->field_url_title[$language->language][0]['value']);
//                  }
//                }
                foreach ($topic_category as $topic_key => $topic_value) {
                  $term_data = taxonomy_get_term_by_name(strtolower($topic_value), 'url_builder');
                  $term = array_shift($term_data);
                  $term_parent = taxonomy_get_parents_all($term->tid);
                  $flukenewsurl = NULL;
                  foreach ($term_parent as $term_key => $term_value) {
                    $flukenewsurl .= $term_value->field_url_title[$language->language][0]['value'] . '/';
                  }
                  $url = rtrim($flukenewsurl, "/");
                  $url_arr = explode('/', $url);
                  array_pop($url_arr);
                  $flukenews_url = implode('/', array_reverse($url_arr));
                  if (!empty($term)) {
                    $topic_category_link[] = l(t('@name', array('@name' => $term->field_content_title[$language->language][0]['value'])), $flukenews_url);
                  }
                }
                $output .= ' | <span>' . implode(', ', $topic_category_link) . '</span>';
              }
              $output .= "</div>";

              $output .= "</div>"; //End detail wrapper.

              $output .= "</div>"; // End of main wrapper.
              ++$count;
            }
          }
        }
      }
    }
  }

  return $output;
}

/*
 * Articles listing in top stories section.
 */

function igcommerce_utility_articles_fluke_news_toc_top_stories($arg) {

  global $language, $base_url;

  $output = NULL;
  $html_output = NULL;
  $parameter = [];
  $filter = [];
  $block_title = NULL;
  $path_alias = explode("/", $arg);
  $node_alias = array_pop($path_alias);

  $vocabulary = 'topic';
  $term = igcommerce_utility_articles_flukenews_get_term($vocabulary);

  if (!empty($term)) {
    if (isset($term->field_content_title[$language->language][0]['value'])) {
      $taxonomy_name = $term->field_content_title[$language->language][0]['value'];

      $keyword = "entity_type:node";
      $parameter[]['fl'] = 'ss_toc_large_img_url';
      $parameter[]['fl'] = 'ss_toc_medium_img_url';
      $parameter[]['fl'] = 'ss_toc_small_img_url';
      $parameter[]['fl'] = 'ss_field_content_title';
      $parameter[]['fl'] = 'tm_article_summary';
      $parameter[]['fl'] = 'sm_vid_News_Topic';
      $parameter[]['fl'] = 'dm_field_publication_date';
      $parameter[]['fl'] = 'path_alias';
      $parameter[]['fl'] = 'ss_language';
      $parameter[]['fl'] = 'entity_id';
      $filter[]['bundle'] = 'article';
      $filter[]['ss_language'] = $language->language;
      $filter[]['sm_vid_News_Topic'] = $taxonomy_name;
      $filter[]['bs_status'] = "true";

      $article_data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);
    }
    // Display the article list.
    if (!empty($article_data->response->docs)) {
      $block_title = '<h3 class= "pane-title">' . t('Top stories') . '</h3>';
      foreach ($article_data->response->docs as $result) {
        $pager_output = array();
        $image_url_desktop = NULL;
        $image_url_tablet = NULL;
        $image_url_mobile = NULL;
        $topic_date_str = '';
        // Images for article listing.
        $image_url_desktop = !empty($result->ss_toc_large_img_url) ? $result->ss_toc_large_img_url : '';
        $image_url_tablet = !empty($result->ss_toc_medium_img_url) ? $result->ss_toc_medium_img_url : '';
        $image_url_mobile = !empty($result->ss_toc_small_img_url) ? $result->ss_toc_small_img_url : '';

        //Generate the output using the igcommerce_utility_format_image
        $pic = igcommerce_utility_determine_toc_image($image_url_desktop, $image_url_tablet, $image_url_mobile);
        // Title of article.
        $node_title = $result->ss_field_content_title;
        // Summary of article.
        if (!empty($result->tm_article_summary)) {
          $summary = $result->tm_article_summary[0];
        }
        if (!empty($result->dm_field_publication_date)) {
          $date_formatted = explode('T', $result->dm_field_publication_date[0]);
          $date_str = date('m-d-Y', strtotime($date_formatted[0]));
          $topic_date = '<span>' . $date_str . '</span>';
        }

        // Listing topics for articles.

        if (!empty($result->sm_vid_News_Topic)) {
          $topic_category = $result->sm_vid_News_Topic;
          // alphabetically order
          asort($topic_category);
          $topic_category_link = array();
//          foreach ($topic_category as $topic_key => $topic_value) {
//            $term_data = taxonomy_get_term_by_name(strtolower($topic_value), 'url_builder');
//            $term = array_shift($term_data);
//            if (!empty($term)) {
//              $topic_category_link[] = l(t('@name', array('@name' => $term->field_content_title[$language->language][0]['value'])), 'solutions/fluke-news/' . $term->field_url_title[$language->language][0]['value']);
//            }
//          }

          foreach ($topic_category as $topic_key => $topic_value) {
            $term_data = taxonomy_get_term_by_name(strtolower($topic_value), 'url_builder');
            $term = array_shift($term_data);
            $term_parent = taxonomy_get_parents_all($term->tid);
            $flukenewsurl = NULL;
            foreach ($term_parent as $term_key => $term_value) {
              $flukenewsurl .= $term_value->field_url_title[$language->language][0]['value'] . '/';
            }
            $url = rtrim($flukenewsurl, "/");
            $url_arr = explode('/', $url);
            array_pop($url_arr);
            $flukenews_url = implode('/', array_reverse($url_arr));
            if (!empty($term)) {
              $topic_category_link[] = l(t('@name', array('@name' => $term->field_content_title[$language->language][0]['value'])), $flukenews_url);
            }
          }
          $topic_str = ' | <span>' . implode(', ', $topic_category_link) . '</span>';
        }

        // Output the TOC item
        $output .= "<div class='toc-feature-article-wrapper'>";

        // Image Wrapper.
        $output .= "<div class='toc-feature-article-image-wrapper'>";
        $output .= "<div class='toc-feature-article-image'>";
        $output .= '<a href="/' . $language->language . '/' . $result->path_alias . '">';
        $output .= $pic;
        $output .= "</a>";
        $output .= "</div>"; // end of image
        $output .= "</div>"; // end of image wrapper.
        // Title of node.
        $output .= "<div class='flukenews_article_card_title'>";
        $output .= '<a  href="' . $base_url . "/" . $language->language . "/" . $result->path_alias . '"  alt="' . $node_title . '">';
        $output .= $node_title;
        $output .= "</a>";
        $output .= "</div>"; // end of title
        // Summary of node.
        $output .= "<div class='flukenews_article_short_summary'>";
        $output .= $summary;
        $output .= "</div>";

        // Summary of node.
        $output .= "<div class='flukenews_article_date_topic'>";
        $output .= $topic_date . $topic_str;
        $output .= "</div>";

        $output .= "</div>"; // end of wrapper


        $pager_output[] = $output;
      }
      // Adding pager.
      $per_page = 5;
      // Initialise the pager
      $current_page = pager_default_initialize(count($pager_output), $per_page);

      // Split your list into page sized chunks
      $chunks = array_chunk($pager_output, $per_page, TRUE);
      // Counter for page result count.
      if (!empty($path_alias) && isset($_GET['page'])) {
        $start_result_count = ($per_page * $current_page) + 1;
        $end_result = count($chunks[$current_page]) + ($per_page * $_GET['page']);
        $total_result_count = count($pager_output);

        // Checking result less than pager count.
        if ($end_result > $total_result_count) {
          $end_result_count = (count($chunks[$current_page]) + 1) + $per_page;
        } else {
          $end_result_count = $end_result;
        }
      }
      // Show the appropriate items from the list
      $html_output .= theme('item_list', array('items' => $chunks[$current_page]));
      $html_output .= theme('pager', array('quantity', count($pager_output)));
    } else {
      $html_output .= '<div class ="event-empty">' . t("No Top Stories found.") . '</div>';
    }
  }

  return $block_title . $html_output;
}

/**
 * Cool Links
 */

function igcommerce_utility_articles_fluke_news_get_cool_links() {
  global $language;

  $filters['filters'] = array(
    'entity_type' => 'node',
    'bundle' => 'e_link',
    'ss_language' => $language->language,
    'bs_status' => TRUE, // only interested in published
    'ss_external_url' => '[" TO *]',
    'ss_field_content_title' => '[" TO *]',
  );

  $filters['sort'] = array('ds_created' => 'asc');
  $filters['rows'] = 4;

  $query = fluke_solr_get_connection();
  $query = fluke_solr_add_filters($query, $filters);
  $response = fluke_solr_query($query);

  if (empty($response->response->docs)) {
    return;
  }

  return $response->response->docs;
}

function igcommerce_utility_articles_fluke_news_cool_links() {
  global $language;

  $output = '';

  if (!$links = igcommerce_utility_articles_fluke_news_get_cool_links()) {
    return;
  }

  $output .= '<h3 class= "pane-title">' . t('Cool links') . '</h3>';

  foreach ($links as $link) {
    $title = '';
    $output .= "<div class='link-feature-article-wrapper'>";
    $output .= "<div class='link-feature-article-detail-wrapper'>";
    // Title of article.
    if (!empty($link->ss_field_content_title) && !empty($link->ss_external_url)) {
      $output .= "<p>";
      $url = $link->ss_external_url;
      $title = $link->ss_field_content_title;
      $output .= '<a href= "' . $url . '" title="' . $title . '">';
      $output .= $title;
      $output .= "</a>";
      $output .= "</p>";
    }
    $output .= "</div>";

    $output .= "</div>"; //End detail wrapper.

  }
  return $output;

  // OLD CODE

  global $language;

  $output = NULL;
  $parameter = array();
  $filter = array();
  $path = explode('/', current_path());
  if (!empty($path) && ($path[0] == 'node') && !empty($path[1]) && !in_array('panels', $path)) {
    // Feching toc article and card size.
    $node_id = $path[1];
    //Parameters and filters for solr query
    $keyword = "bundle:toc";
    $parameter[]['rows'] = '1';
    $parameter[]['fl'] = 'sm_toc_cool_link';
    $filter[]['entity_id'] = $node_id;

    $toc_data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);

    // Getting cool links list from toc fluke news.
    if (!empty($toc_data->response->docs) && !empty($toc_data->response->docs[0]->sm_toc_cool_link[0])) {

      $toc_e_link_data = json_decode($toc_data->response->docs[0]->sm_toc_cool_link[0]);
      // Making article listing array.
      $e_link_data_details = array();
      $e_link_string = NULL;

      foreach ($toc_e_link_data as $key => $value) {
        $e_link_data_details[$value->target_id]['e_link'] = NULL;
        if (empty($e_link_string)) {
          $e_link_string .= "(" . $value->target_id;
        } else {
          $e_link_string .= " OR " . $value->target_id;
        }
      }
      $e_link_string .= ")";

      if (!empty($e_link_string) && $e_link_string != ")") {
        // Feching data from article.
        $e_link_data = igcommerce_utility_articles_get_full_e_link_data($e_link_string);

        foreach ($e_link_data as $e_link_data_key => $e_link_data_value) {
          $e_link[$e_link_data_value->entity_id]['e_link'] = $e_link_data_value;
        }
        if (!empty($e_link)) {
          $output .= '<h3 class= "pane-title">' . t('Cool links') . '</h3>';

          $count = 1;
          foreach ($e_link as $e_link_key => $e_link_value) {
            if ($count <= 3) {
              $cool_links_title = '';
              $output .= "<div class='link-feature-article-wrapper'>";
              $output .= "<div class='link-feature-article-detail-wrapper'>";
              // Title of article.
              if (!empty($e_link_value['e_link']->ss_cool_links_title) && !empty($e_link_value['e_link']->ss_cool_links_url)) {
                $output .= "<p>";
                $cool_links_url = $e_link_value['e_link']->ss_cool_links_url;
                $cool_links_title = $e_link_value['e_link']->ss_cool_links_title;
                $output .= '<a href= "' . $cool_links_url . '" title="' . $cool_links_title . '">';
                $output .= $cool_links_title;
                $output .= "</a>";
                $output .= "</p>";
              }
              $output .= "</div>";

              $output .= "</div>"; //End detail wrapper.


              ++$count;
            }
          }
        }
      }
    }
  }
  return $output;
}

/*
 * Handler for getting E Link data.
 */

function igcommerce_utility_articles_get_full_e_link_data($e_link_entity_id) {
  global $language;

  $output = NULL;
  $link_parameter = array();
  $link_filter = array();
  if (!empty($e_link_entity_id)) {
    $link_keyword = "entity_type:node";
    $link_parameter[]['fl'] = 'entity_id';
    $link_parameter[]['fl'] = 'ss_field_content_title';
    $link_parameter[]['fl'] = 'ss_cool_links_url';
    $link_parameter[]['fl'] = 'ss_cool_links_title';
    $link_filter[]['bundle'] = 'e_link';
    $link_filter[]['ss_language'] = $language->language;
    $link_filter[]['entity_id'] = $e_link_entity_id;
    $link_filter[]['bs_status'] = "true";
    $link_query = igcommerce_utility_articles_solr_toc_sol_query($link_keyword, $link_parameter, $link_filter);

    $output = $link_query->response->docs;
  }

  return $output;
}

/**
 * Fetch term name
 * @return type
 */
function igcommerce_utility_articles_flukenews_get_term($vocabulary) {

  $tid = NULL;
  $term = NULL;
  $alias = drupal_get_path_alias($_GET['q']);
  $alias_parts = explode("/", $alias);
  $category = array_pop($alias_parts);
  $term_results = get_term_data($category, $vocabulary);

  if (!empty($term_results)) {
    foreach ($term_results['taxonomy_term'] as $key => $value) {
      $temp_parent = array_keys(taxonomy_get_parents($key));

      if (!isset($parent_results['taxonomy_term']) || $temp_parent[0] == $parent_id) {
        $tid = $key;
      }
    }
    $term = taxonomy_term_load($tid);
  }

  return $term;
}

function get_term_data($category, $vocabulary) {
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', $vocabulary)
    ->fieldCondition('field_url_title', 'value', $category, '=');
  $term_results = $query->execute();

  return $term_results;
}

/**
 * Handel - Recent articles
 * Visible only on Fluke news sub categories
 * 4 max
 *
 */
function igcommerce_utility_articles_solr_recent_article() {

  global $language;
  $output = NULL;

  $data = igcommerce_utility_articles_load_article(NULL, $language->language);
  $current_url_path = drupal_get_path_alias();

  if (!empty($data->sm_field_topic[0])) {

    $alt = '';
    $image_url_desktop = NULL;
    $image_url_tablet = NULL;
    $image_url_mobile = NULL;
    $heading = 1;
    $keyword = "bundle:article";
    $parameter[]['rows'] = '10';
    $parameter[]['fl'] = 'ds_created';
    $parameter[]['fl'] = 'dm_field_publication_date';
    $parameter[]['fl'] = 'ss_toc_large_img_url';
    $parameter[]['fl'] = 'ss_toc_medium_img_url';
    $parameter[]['fl'] = 'ss_toc_small_img_url';
    $parameter[]['fl'] = 'ss_field_content_title';
    $parameter[]['fl'] = 'ss_path_alias_locale';
    $filter[]['sm_field_topic'] = $data->sm_field_topic[0];
    $filter[]['ss_language'] = $language->language;
    $filter[]['bs_status'] = "true";
    $sort = 'ds_created Desc';
    $data = igcommerce_event_solr_query($keyword, $parameter, $filter, $sort);
    if (!empty($data->response->docs)) {
      $count = 1;
      foreach ($data->response->docs as $data_key => $data_value) {
        if ($current_url_path != $data_value->ss_path_alias_locale && $count <= 4) {
          if ($heading == 1) {
            $output .= '<h3 class= "pane-title">' . t('Recent articles') . '</h3>';
            $heading++;
          }
          // Images for article listing.

          $large_image = !empty($data_value->ss_toc_large_img_url) ? $data_value->ss_toc_large_img_url : '';
          $styles = igcommerce_utility_get_images($large_image);
          
          $recent_article_path = '/' . $data_value->ss_path_alias_locale;
          $output .= "<div class='toc-article-related-resource-wrapper'>";
          $output .= "<div class='card'>";
          $link_copy = igcommerce_utility_determine_toc_image($styles['field_large_url'], $styles['field_large_url'], $styles['field_medium_url'], $alt);
          
          $output .= l($link_copy, $recent_article_path, array('html' => TRUE, 'language' => $language));
          $output .= "<h3 class='toc-article-related-resource-title'>";
          $output .= l($data_value->ss_field_content_title, $recent_article_path, array('html' => TRUE, 'language' => $language));
          $output .= "</h3>";
          if (!empty($data_value->dm_field_publication_date)) {
            $date_formatted = explode('T', $data_value->dm_field_publication_date[0]);
            $date_str = date('m-d-Y', strtotime($date_formatted[0]));
            $output .= '<span>' . $date_str . '</span>';
          }
          if (!empty($data_value->sm_vid_News_Topic)) {

            $topic_category_link = array();
            $topic_category = $data_value->sm_vid_News_Topic;
            // alphabetically order
            asort($topic_category);
//            foreach ($topic_category as $topic_key => $topic_value) {
//              $term_data = taxonomy_get_term_by_name(strtolower($topic_value), 'url_builder');
//              $term = array_shift($term_data);
//              $topic_category_link[] = l(t('@name', array('@name' => $term->field_content_title[$language->language][0]['value'])), 'solutions/fluke-news/' . $term->field_url_title[$language->language][0]['value']);
//            }
            foreach ($topic_category as $topic_key => $topic_value) {
              $term_data = taxonomy_get_term_by_name(strtolower($topic_value), 'url_builder');
              $term = array_shift($term_data);
              $term_parent = taxonomy_get_parents_all($term->tid);
              $flukenewsurl = NULL;
              foreach ($term_parent as $term_key => $term_value) {
                $flukenewsurl .= $term_value->field_url_title[$language->language][0]['value'] . '/';
              }
              $url = rtrim($flukenewsurl, "/");
              $url_arr = explode('/', $url);
              array_pop($url_arr);
              $flukenews_url = implode('/', array_reverse($url_arr));
              if (!empty($term)) {
                $topic_category_link[] = l(t('@name', array('@name' => $term->field_content_title[$language->language][0]['value'])), $flukenews_url);
              }
            }
            $output .= ' | ' . '<span>' . implode(', ', $topic_category_link) . '</span>';
          }
          $output .= "</div>";
          $output .= "</div>";
        }
        ++$count;
      }
    }

  }
  return $output;
}

/**
 * Handel Related Product
 * Select data from  Article content type ->Related Tab ->Related Product
 * 4 max
 */
function igcommerce_utility_articles_solr_fluke_news_recommended_product() {
  global $language;
  $output = NULL;

  $data = igcommerce_utility_articles_load_article(NULL, $language->language);

  if (empty($data->tm_recommended_product_article[0])) {
    return;
  }

  $products = json_decode($data->tm_recommended_product_article[0]);

  return igcommerce_utility_articles_products($products);
}

/*
 * Show the related product from article.
 * 4 max
 */

function igcommerce_utility_articles_solr_build_fluke_news_recommanded_product($recommaned_product_article_list) {
  global $language;
  $output = NULL;
  $heading = 1;

  if (!empty($recommaned_product_article_list)) {
    // Create entity_id list required for solr search.
    $entity_id = '';
    foreach ($recommaned_product_article_list as $key => $value) {
      if (empty($entity_id)) {
        $entity_id .= '(' . $value->entity_id;
      } else {
        $entity_id .= ' OR ' . $value->entity_id;
      }
    }
    $entity_id .= ')';

    // Solr query to fetch data.
    $keyword = "entity_type:node";
    $parameter[]['fl'] = 'sm_vid_URL_Builder';
    $parameter[]['fl'] = 'path_alias';
    $parameter[]['fl'] = 'is_product_slideshow';
    $parameter[]['fl'] = 'ss_field_content_title';
    $filter[]['entity_id'] = $entity_id;
    $filter[]['ss_language'] = $language->language;
    $data = igcommerce_utility_articles_solr_toc_sol_query($keyword, $parameter, $filter);
    // Feching data.
    if (!empty($data->response->docs)) {
      $count = 0;
      foreach ($data->response->docs as $data_key => $data_value) {
        if ($heading == 1) {
          $output .= '<h3 class= "pane-title">' . t('Recommended products') . '</h3>';
          $heading++;
        }
        // max 4 product need to show
        if ($count < 4) {
          $recommaned_product_path = $language->language . '/' . $data_value->path_alias;
          $recommaned_product_label = !empty($data_value->ss_field_content_title) ? $data_value->ss_field_content_title : NULL;
          // Show only four recommaned resource.
          $output .= "<div class='toc-article-related-resource-wrapper'>";
          $output .= "<div class='card'>";
          // Taking first image from slideshow
          if (!empty($data_value->is_product_slideshow)) {
            $slideshow = fluke_solr_get_entity($data_value->is_product_slideshow, 'node', 'slideshow', $language->language);

            if (empty($slideshow->sm_field_product_image_desktop[0])) {
              continue;
            }

            $product_slideshow_image = json_decode($slideshow->sm_field_product_image_desktop[0], TRUE);
            if (!empty($product_slideshow_image['url'])) {
              $image = $product_slideshow_image['url'];
            }
          }
          $output .= '<a href="/' . $recommaned_product_path . '">';
          $output .= igcommerce_utility_determine_toc_image($image);
          $output .= "</a>";
          $output .= "<h3 class='toc-article-related-resource-title'>";
          if (isset($recommaned_product_path)) {
            $output .= '<a href="/' . $recommaned_product_path . '" alt="' . $recommaned_product_label . '">';
          }
          $output .= $recommaned_product_label;
          $output .= "</a>";
          $output .= "</h3>";
          $output .= "</div>";
          $output .= "</div>";
        }
        ++$count;
      }
    }
  }

  return $output;
}

/**
 * Handel Display Topic & publication date
 * If Topic category & Publication date is selected it will appear in the format (mm-dd-yyyy | topic)
 */
function igcommerce_utility_articles_solr_topic() {
  global $language;
  $output = NULL;

  $data = igcommerce_utility_articles_load_article(NULL, $language->language);
  if (!empty($data)) {

    if (!empty($data->ss_publication_date)) {
      $date_formatted = $data->ss_publication_date;
      $date_str = date('m-d-Y', strtotime($date_formatted));
      $output .= '<span>' . $date_str . '</span>';
    }
    if (!empty($data->sm_field_topic)) {
      $topic_category_link = array();
      $topic_category = $data->sm_field_topic;

      //splice off the last two elements of the url to get the parent url
			$path_alias = igcommerce_utility_url_get_locale_path(current_path(), $language->language);
      $path_alias = explode('/', $path_alias);

      array_splice($path_alias, -2, 2);
      $flukenews_url = implode('/', $path_alias);

      foreach ($topic_category as $topic_key => $term) {
        $term_data = _taxonomy_term_load_solr($term);

        if(!empty($term_data->ss_url_builder_url_title)) {
          $topic_url_title = $term_data->ss_url_builder_url_title;
          $topic_category_link[] = l(t('@name', array('@name' => $term_data->sm_field_content_title[0])), $flukenews_url . '/'. $topic_url_title);
        }
      }
      $output .= ' | ' . '<span>' . implode(', ', $topic_category_link) . '</span>';
    }
  }

  return $output;
}

/**
 * Survey Blocks
 * Only appears on Fluke news page
 */
function igcommerce_utility_articles_fluke_news_get_surveys() {
  global $language;

  $filters['filters'] = array(
    'entity_type' => 'node',
    'bundle' => 'survey',
    'ss_language' => $language->language,
    'bs_status' => TRUE, // only interested in published
    'tm_survey_summary' => '[* TO *]',
    'ss_field_content_title' => '[" TO *]',
  );

  $filters['sort'] = array('ds_created' => 'asc');
  $filters['rows'] = 4;

  $query = fluke_solr_get_connection();
  $query = fluke_solr_add_filters($query, $filters);
  $response = fluke_solr_query($query);

  if (empty($response->response->docs)) {
    return;
  }

  return $response->response->docs;
}

function igcommerce_utility_articles_fluke_news_surveylink() {
  global $language;

  $output = '';

  if (!$links = igcommerce_utility_articles_fluke_news_get_surveys()) {
    return;
  }

  $title_field = 'ss_field_content_title';
  foreach ($links as $link) {
    $title = '';
    $output .= "<div class='link-feature-article-wrapper'>";
    $output .= "<div class='link-feature-article-detail-wrapper'>";
    // Display title
    if (!empty($link->{$title_field})) {
      $title = $link->{$title_field};
      $output .= '<h3 class="link-article-related-resource-title">' . $title . '</h3>';
    }
    // summary
    if (!empty($link->tm_survey_summary)) {
      $output .= '<div class="survey_summary">' . igcommerce_utility_convert_links_to_alias($link->tm_survey_summary[0], $language->language) . '</div>';
    }
    // Survey Links
    if (!empty($link->sm_survey_link)) {
      $survey_link = json_decode($link->sm_survey_link[0]);


      if (!empty($survey_link->url) && !empty($survey_link->title)) {
        $url = igcommerce_utility_convert_links_to_alias($survey_link->url, $language->language); 
        $title = $survey_link->title;
        $output .= '<a href= "' . $url . '" title="' . $title . '" class="btn-survey">';
        $output .= $title;
        $output .= "</a>";
      }
    }
    $output .= "</div>";

    $output .= "</div>"; //End detail wrapper.
  }

  return $output;
}

/**
 * Returns HTML markup for translated Fluke News title
 */
function igcommerce_utility_articles_fluke_news_title() {
  global $language;

  // TODO is there a better way to search for this term?
  $filters = array(
    "label" => '"Fluke news"',
    "ss_language" => $language->language,
    "bundle" => "url_builder"
  );

  $query = fluke_solr_get_connection();
  $filters = fluke_solr_add_filters($query, array('filters' => $filters));
  $response = fluke_solr_query($filters);

  if (empty($response->response->docs[0])) {
    return;
  }

  $doc = $response->response->docs[0];

  if (!empty($doc->ss_url_builder_term_h1_title)) {
    $title = $doc->ss_url_builder_term_h1_title;
  } else {
    $title = $doc->sm_field_content_title[0];
  }

  $content = '<h1>' . $title . '</h1>';

  if (!empty($doc->sm_description[0])) {
    $content .= $doc->sm_description[0];
  }

  igcommerce_utility_head_elements($doc, TRUE);

  return $content;
}

/**
 * Returns HTML markup for Fluke News banner
 */
function igcommerce_utility_articles_fluke_news_banner() {
  global $language;

  // Init a static array of articles to skip in subsequent loads
  $skip_articles = &drupal_static('igc_skip_articles', array());

  // Banner should only show with article type of "Fluke News" and News Topic of "Special event"
  $article_term = _taxonomy_term_load_by_name_solr('Fluke News', 'article', 'en-us');
  $news_topic_term = _taxonomy_term_load_by_name_solr('Special event', 'topic', 'en-us');

  $filters = array(
    'entity_type' => 'node',
    'bundle' => "article",
    'ss_language' => $language->language,
    'bs_status' => TRUE, // only interested in published articles
    'sm_article_type' => $article_term->entity_id, // make sure this is a fluke news type article
    'sm_field_topic' => $news_topic_term->entity_id,
    'ss_toc_featured_img_url' => '[" TO *]',
  );

  $query = fluke_solr_get_connection();
  $filters = fluke_solr_add_filters($query, array('filters' => $filters, 'sort' => array('ds_created' => 'desc')));
  $response = fluke_solr_query($filters);

  if (empty($response->response->docs[0])) {
    return;
  }

  $doc = $response->response->docs[0];

  $skip_articles[] = $doc->entity_id;

  $img = array('path' => NULL, 'alt' => $doc->tm_article_display_title[0]);
  $img_caption = NULL;

  if (!empty($doc->ss_toc_featured_img_url)) {
    $img['path'] = $doc->ss_toc_featured_img_url;
    if (!empty($doc->ts_toc_featured_img_caption)) {
      $img_caption = $doc->ts_toc_featured_img_caption;
    }
    if (!empty($doc->ts_toc_featured_img_alt)) {
      $img['alt'] = $doc->ts_toc_featured_img_alt;
    }
    $image = theme('image', $img);
    $image = l($image, $doc->path_alias, array('html' => TRUE));
  } else {
    return;
  }

  $output = '<div class="fluke-news-banner-img">' . $image . '</div>';
  $output .= '<div class="fluke-news-banner-img-caption">' . $img_caption . '</div>';

  return $output;
}


/**
 * Returns HTML markup for the featured article on Fluke News page
 */
function igcommerce_utility_articles_fluke_news_featured_article() {
  global $language;
  $vars = array();
  $vars['featured'] = TRUE;

  // Init a static array of articles to skip in subsequent loads
  $skip_articles = &drupal_static('igc_skip_articles', array());

  $article_term = _taxonomy_term_load_by_name_solr('Fluke News', 'article', 'en-us');

  $filters['filters'] = array(
    'entity_type' => 'node',
    'bundle' => "article",
    'ss_language' => $language->language,
    'bs_status' => TRUE, // only interested in published articles
    //'bs_translation_status' => TRUE,
    //MIG1391 - 'ss_toc_featured_img_url' => '[" TO *]', // only interested if there's a featured img
    'ss_field_feature_article' => 1,
    'sm_article_type' => $article_term->entity_id,
  );
  $filters['sort'] = array('ds_created' => 'desc');

  $query = fluke_solr_get_connection();
  $query = fluke_solr_add_filters($query, $filters);
  $response = fluke_solr_query($query);

  // If no featured articles then, query again omiting featured filter
  // We could have sorted the original query by ss_field_feature_article desc but ss_field_feature_article is
  // not a sortable field

  if (empty($response->response->docs[0])) {
    unset($filters['filters']['ss_field_feature_article']);
    $query = fluke_solr_get_connection();
    $query = fluke_solr_add_filters($query, $filters);
    $response = fluke_solr_query($query);

    if (empty($response->response->docs[0])) {
      return;
    }
  }

  // Make sure featured item isn't also the event banner
  $doc = NULL;
  foreach ($response->response->docs as $d) {
    if (in_array($d->entity_id, $skip_articles)) {
      continue;
    }

    $skip_articles[] = $d->entity_id;
    $doc = $d;
    break;
  }

  if (!$doc) {
    return;
  }

  $vars['title_tag'] = 'h2';
  $vars['featured'] = TRUE;
  $vars['doc'] = $doc;
  $vars['article_type'] = 'featured';
  
  return theme('articles_news_item', $vars);
}

/**
 * Sorts an array by ss_field_top_story_position
 */
function _igc_sort_top_story_position($a, $b) {
  $a_weight = is_object($a) && isset($a->ss_field_top_story_position) && isset($a->ss_field_top_story) ? $a->ss_field_top_story_position : 1000;
  $b_weight = is_object($b) && isset($b->ss_field_top_story_position) && isset($b->ss_field_top_story) ? $b->ss_field_top_story_position : 1000;

  if ($a_weight == $b_weight) {
    return 0;
  }

  return $a_weight < $b_weight ? -1 : 1;
}

/**
 * Returns HTML markup for the featured article on Fluke News page
 */
function igcommerce_utility_articles_fluke_news_top_stories($topic = NULL, $total = 10) {
  global $language;

  // Init a static array of articles to skip in subsequent loads
  $skip_articles = &drupal_static('igc_skip_articles', array());

  // If this is generating content for a subcategory like "Automotive" then 
  // the title should be "Recent stories." If it's for the Fluke News TOC, then
  // the title should be "Top stories"
  $section_title = t('Top stories');
  if ($topic) {
    // Load the entity_id of topic for searching
    // $topic is the en-us version because current_path() grabs the source which is en-us
    if (!$topic_term = _taxonomy_term_load_news_topic_by_url_title_solr($topic, 'en-us')) {
      return;
    }
    $section_title = t('Recent stories');
  }

  $article_term = _taxonomy_term_load_by_name_solr('Fluke News', 'article', 'en-us');

  $filters['filters'] = array(
    'entity_type' => 'node',
    'bundle' => "article",
    'ss_language' => $language->language,
    'sm_article_type' => $article_term->entity_id,
    'bs_status' => TRUE, // only interested in published articles
    //'bs_translation_status' => TRUE,
    //'ss_toc_featured_img_url' => '[" TO *]', // uncomment if only want to return articles with images
    'ss_field_top_story' => 1, //TODO uncomment this as nothing is tagged with this yet
  );

  // Add filter for topic if applicable
  if ($topic) {
    // TODO uncomment this when it goes live
    // so far nothing is tagged
    $filters['filters']['sm_field_topic'] = $topic_term->entity_id;
  }

  // Sorting by creation date
  $filters['sort'] = array('ds_created' => 'desc');

  $filters['rows'] = 1000;
  if ($total) {
    $filters['rows'] = $total * 2;
  }

  $query = fluke_solr_get_connection();
  $query = fluke_solr_add_filters($query, $filters);
  $response = fluke_solr_query($query);

  // If no top story articles then, query again omiting top story filter
  // We could have sorted the original query by ss_field_top_story desc but ss_field_top_story is
  // not a sortable field TODO make it sortable
  $docs = $response->response->docs;
  $count = count($docs);

  if (($total && $count < $total) || (!$total)) {
    unset($filters['filters']['ss_field_top_story']);
    $query = fluke_solr_get_connection();
    $query = fluke_solr_add_filters($query, $filters);
    $response = fluke_solr_query($query);

    $docs = array_merge($docs, $response->response->docs);
  }

  if (empty($docs)) {
    return;
  }

  // Sort by top story position 
  stable_uasort($docs, '_igc_sort_top_story_position');

  $i = 0;
  $vars = array('title_tag' => 'h3', 'topic' => $topic);
  $articles = array();

  foreach ($docs as $doc) {
    if (in_array($doc->entity_id, $skip_articles)) {
      continue; // Skip if this was already featured
    }

    $skip_articles[] = $doc->entity_id;

    $vars['doc'] = $doc;
    $vars['article_type'] = 'top'; 
    $articles[] = theme('articles_news_item', $vars);

    $i++;
    if ($total && $i === $total) {
      break; // We at max, so break from this loop
    }
  }

  return theme('articles_top_stories', array('articles' => $articles, 'topic' => $topic, 'section_title' => $section_title));
}

/**
 * Returns HTML markup for the featured article on Fluke News page
 */
function igcommerce_utility_articles_fluke_news_recent_stories() {
  global $language;

  // Init a static array of articles to skip in subsequent loads
  $skip_articles = &drupal_static('igc_skip_articles', array());

  $total = 4; // Total stories to show TODO make this dynamic in a block setting?

  $article_term = _taxonomy_term_load_by_name_solr('Fluke News', 'article', 'en-us');

  $filters['filters'] = array(
    'entity_type' => 'node',
    'bundle' => "article",
    'ss_language' => $language->language,
    'bs_status' => TRUE, // only interested in published articles
    //'ss_toc_featured_img_url' => '[" TO *]', // only interested if there's a featured img
    'sm_article_type' => $article_term->entity_id,
  );

  $filters['sort'] = array('ds_created' => 'desc');
  $filters['rows'] = 10; // enough rows in case we have duplicate articles

  $query = fluke_solr_get_connection();
  $query = fluke_solr_add_filters($query, $filters);
  $response = fluke_solr_query($query);

  // If no top story articles then, query again omiting top story filter
  // We could have sorted the original query by ss_field_top_story desc but ss_field_top_story is
  // not a sortable field
  $docs = $response->response->docs;
  $count = count($docs);

  if ($count === 0) {
    return;
  }

  $i = 0;
  $vars = array('title_tag' => 'h4');
  $articles = array();

  foreach ($docs as $doc) {
    if (in_array($doc->entity_id, $skip_articles)) {
      continue;
    }

    $skip_articles[] = $doc->entity_id;

    $vars['doc'] = $doc;
    $vars['article_type'] = 'recent';    
    $articles[] = theme('articles_news_item', $vars);

    $i++;
    if ($i == $total) {
      break; // We at max, so break from this loop
    }
  }

  return theme('articles_recent_stories', array('articles' => $articles));
}