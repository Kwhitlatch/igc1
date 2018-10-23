<?php

/*
 * @file
 *
 * Handle the Event listing page functionality.
 */

/*
 * Handle event listing page.
 */

function igcommerce_event_listing_page_details() {
  $output = NULL;
  // Handle the filter of event page.
  $output .= igcommerce_event_listing_page_details_filter();

  // Handle the view of event listing.
  $output .= igcommerce_event_listing_page_details_view();

  return $output;
}

/*
 * Handle filter of listing page.
 */

function igcommerce_event_listing_page_details_filter() {
  $output = NULL;

  $form = drupal_get_form('igcommerce_event_listing_page_details_filter_form');
  $output .= drupal_render($form);

  return $output;
}

/*
 * A callback igcommerce_event_listing_page_details_filter_form(). for filtering
 * events.
 */

function igcommerce_event_listing_page_details_filter_form($form, &$form_state) {
  $form = array();

  // Query parameter from url.
  $parameter = drupal_get_query_parameters();

  $form['#attributes']['class'] = 'form-group';

  // Query to get result count.
  $data = igcommerce_event_query(NULL, NULL, NULL);
  $count = count($data->response->docs);

  if ($count >= 10) {
    $location = array();
    $location['all'] = t('Choose Location');
    foreach ($data->response->docs as $key => $value) {
      if (!empty($value->sm_field_event_location)) {
        $location_key = $value->sm_field_event_location[0];
        $location[$location_key] = $value->sm_field_event_location_actual[0];
      }
    }
    // Location.
    $form['event']['location'] = array(
      '#title' => t(''),
      '#type' => 'select',
      '#options' => $location,
      '#default_value' => !empty($parameter['location']) ?  $parameter['location'] : '',
    );
  }

  // Sort by.
  $form['event']['sort'] = array(
    '#title' => t(''),
    '#type' => 'select',
    '#options' => array('' => t('Sort By'), 'date' => t('Date'), 'price' => t('Price')),
    '#default_value' => !empty($parameter['sort']) ?  $parameter['sort'] : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/*
 * Submit handler for event listing filter.
 */
function igcommerce_event_listing_page_details_filter_form_submit($form, &$form_state) {
  // Query parameter from url.
  $parameter = drupal_get_query_parameters();

  if (!empty($form_state['values'])) {
    // Location filter.
    $location = !empty($form_state['values']['location']) ? $form_state['values']['location'] : NULL;
    $sort = !empty($form_state['values']['sort']) ? $form_state['values']['sort'] : NULL;

    $query_builder = array();
    if (!empty($parameter['f'])) {
      $query_builder['f'] = $parameter['f'];
    }
    if (!empty($location)) {
      $query_builder['location'] = $location;
    }
    if (!empty($sort)) {
      $query_builder['sort'] = $sort;
    }

    drupal_goto('training/tradeshows-seminars', array('query' => $query_builder));
  }
}

/*
 * Handle View of listing page.
 */

function igcommerce_event_listing_page_details_view() {
  global $language;

  $output = NULL;
  $html_output = NULL;
  // Output based on pager need.
  $pager_output = array();

  // Query parameter from url.
  $parameter = drupal_get_query_parameters();

  if (!empty($parameter)) {
    $location = !empty($parameter['location']) ? $parameter['location'] : NULL;
    $sort = !empty($parameter['sort']) ? $parameter['sort'] : NULL;
    $facet_filter = !empty($parameter['f']) ? $parameter['f'] : NULL;
    // Filter value present
    $data = igcommerce_event_query($facet_filter, $location, $sort);
  }
  else {
    // Filter value not present
    $data = igcommerce_event_query(NULL, NULL, NULL);
  }
  
  $curr_date = new DateTime();
  $currdate_ts = $curr_date->getTimestamp();

  if (!empty($data->response->docs)) {

    foreach ($data->response->docs as $data_key => $data_value) {
      $output = '';

      // Date of event.
      //@todo: calling the function causes a critical erro
      $locale_data = ['start_date' => 0, 'end_date' => 0];//_igcommerce_get_start_end_date_node($data_value->ss_language, $data_value->entity_id);

      /**
       * Check conditions :
       * a) If end date is greater then current date , This means we need future date events.
       *    We will not be showing the events whose end date is passed.
       * b) We are also displaying the events whose start and end dates are not set using URL
       *    Alias localization module(PATH - admin/content/dashboard/show-aliases/settings)
       * c) If start date is greater then current date, then also display.
       */
      if (( $locale_data['start_date'] < $currdate_ts && $locale_data['end_date'] > $currdate_ts) || (empty($locale_data['start_date']) && empty($locale_data['end_date']))) {
        // Outer wrapper for event listing.
        $output .= '<div class = "event-list-wrapper">';
        // Event desciption wrapper.
        $output .= '<div class = "event-decription-wrapper">';
        // Header of event.
        $output .= '<h2>' . $data_value->ss_field_content_title . '</h2>';

      if (!empty($data_value->ds_event_start_date) ) {
        $output .= '<div class = "event-date">';
        $output .= '<span><label>' . t('Date:') . '</label></span>';
        $event_date_timestamp = strtotime($data_value->ds_event_start_date);
        $output .= '<span>' . format_date($event_date_timestamp, $type = 'medium', $format = 'm/d/Y') . '</span>';
        if (!empty($data_value->ds_event_end_date)) {
          $event_date_end_timestamp = strtotime($data_value->ds_event_end_date);
          $output .= ' - <span>' . format_date($event_date_end_timestamp, $type = 'medium', $format = 'm/d/Y') . '</span>';
        }
        $output .= '</div>';
      }

      //Event Location.
      if (!empty($data_value->tm_field_event_location[0])) {
        $output .= '<div class = "event-location">';
        $output .= '<label>' . t('Location:') . '</label>';
        $output .= '<span>' . $data_value->tm_field_event_location[0] . '</span>';
        $output .= '</div>';
      }

      //Event Price.
      if (!empty($data_value->sm_event_currency_indicator) && !empty($data_value->fts_field_event_price)) {
        $output .= '<div class = "event-price">';
        $output .= '<label>' . t('Price:') . '</label>';
        $indicator = !empty($data_value->sm_event_currency_indicator[0]) ? $data_value->sm_event_currency_indicator[0] : NULL;
        $output .= '<span>' . $indicator . ' ' . $data_value->fts_field_event_price . '</span>';
        $output .= '</div>';
      }

      //Event What you will learn.
      if (isset($data_value->ss_event_what_you_will_learn)) {
        $output .= '<div class = "event-what-you-will-learn">';
        $output .= '<label><strong>' . t('What you will learn:') . '</strong></label>';
        $output .= '<span>' . $data_value->ss_event_what_you_will_learn . '</span>';
        $output .= '</div>';
      }

      //Event What you will get.
      if (isset($data_value->ss_event_what_you_will_be_get)) {
        $output .= '<div class = "event-what-you-will-get">';
        $output .= '<label><strong>' . t('What you will get:') . '</strong></label>';
        $output .= '<span>' . $data_value->ss_event_what_you_will_be_get . '</span>';
        $output .= '</div>';
      }

      //Event sponsor.
      if (!empty($data_value->ss_event_sponsor)) {
        $output .= '<div class = "event-sponsor">';
        $output .= '<label><strong>' . t('Sponsor:') . '</strong></label>';
        $output .= '<span>' . $data_value->ss_event_sponsor . '</span>';
        $output .= '</div>';
      }

      // Register Link
      $cta_left_coll_data = NULL;
      if (!empty($data_value->sm_event_cta_left_coll[0])) {
        $cta_left_coll_data = json_decode($data_value->sm_event_cta_left_coll[0]);
        $output .= '<div class = "event-register">';
        $output .= '<a class ="btn btn-blue" target="_blank" href = "' . $cta_left_coll_data->url . '" >' . $cta_left_coll_data->label . '</a>';
        $output .= '</div>';
      }

      // Event description wrapper end
      $output .= '</div>';

      // Graphics requested the register button be moved to the bottom of the
      // event description, because trade shows usually do not have images.
      // Eventually the trade show image will be removed after this page has
      // been redesigned for launch phase 2, post 3-20-17 -rrn

      // Event image wrapper.
      $output .= '<div class = "event-image-wrapper">';
      // Event image.
      if (!empty($data_value->tm_event_image)) {
        $image_details = json_decode($data_value->tm_event_image[0]);
        $image_url = $image_details->url;
        // Generate the output using the igcommerce_utility_fomrat_image
        $pic = igcommerce_utility_determine_banner_image($image_url);

        $output .= '<div class = "event-image">';
        $output .= '<div>' . $pic . '</div>';
        $output .= '</div>';
      }

      // Event image wrapper end.
      $output .='</div>';

      $output .= '</div>';

      // End Outer Wrapper.
      $pager_output[] = $output;
      } // END of IF Condition.
    } // END for loop

    // Adding pager.
    $per_page = 10;
    // Initialise the pager
    $current_page = pager_default_initialize(count($pager_output), $per_page);

    // Split your list into page sized chunks
    $chunks = array_chunk($pager_output, $per_page, TRUE);

  // Counter for page result count.
    if (!empty($parameter) && isset($parameter['page'])) {
      $start_result_count = ($per_page * $current_page) + 1;
      $end_result = count($chunks[$current_page]) + ($per_page * $parameter['page']);
      $total_result_count = count($pager_output);

      // Checking result less than pager count.
      if ($end_result > $total_result_count) {
        $end_result_count = (count($chunks[$current_page]) + 1) + $per_page;
      }
      else {
        $end_result_count = $end_result;
      }

      $result_count_per_page = '';
      $result_count_per_page .= '<div class = "result-count">';
      $result_count_per_page .= $start_result_count . ' - ' . $end_result_count . ' of ' . $total_result_count . ' Events';
      $result_count_per_page .= '</div>';
    }
    else {
      $start_result_count = 1;
      $end_result_count =  count($chunks[0]);
      $total_result_count = count($pager_output);
      $result_count_per_page = '';
      $result_count_per_page .= '<div class = "result-count">';
      $result_count_per_page .= $start_result_count . ' - ' . $end_result_count . ' of ' . $total_result_count . ' Events';
      $result_count_per_page .= '</div>';
    }
    if (!empty($result_count_per_page)) {
      $html_output .= $result_count_per_page;
    }
    // Show the appropriate items from the list
    $html_output .= theme('item_list', array('items' => $chunks[$current_page]));

    $html_output .= theme('pager', array('quantity', count($pager_output)));
  }
  else {
    $html_output .= '<div class ="event-empty">No Event Found.</div>';
  }
  
  return $html_output;
}

/*
 * Query to get data.
 */
function igcommerce_event_query($facet_condition = NULL, $location_condition = NULL, $sort_condition = NULL) {
  global $language;

  //Query to get list of Events.
  $keyword = "entity_type:node";
  $parameter[]['rows'] = '1000';

  $parameter[]['fl'] = 'ss_field_content_title';
  $parameter[]['fl'] = 'entity_id';
  $parameter[]['fl'] = 'dm_field_event_date';
  $parameter[]['fl'] = 'dm_field_event_date_end';
  $parameter[]['fl'] = 'ds_event_start_date';
  $parameter[]['fl'] = 'ds_event_end_date';
  $parameter[]['fl'] = 'sm_field_event_location';
  $parameter[]['fl'] = 'sm_field_event_location_actual';
  $parameter[]['fl'] = 'sm_event_currency_indicator';
  $parameter[]['fl'] = 'fts_field_event_price';
  $parameter[]['fl'] = 'im_field_event_application';
  $parameter[]['fl'] = 'im_field_event_product_category';
  $parameter[]['fl'] = 'im_field_event_type';
  $parameter[]['fl'] = 'ss_event_what_you_will_learn';
  $parameter[]['fl'] = 'ss_event_what_you_will_be_get';
  $parameter[]['fl'] = 'ss_event_sponsor';
  $parameter[]['fl'] = 'tm_event_image';
  $parameter[]['fl'] = 'sm_event_cta_left_coll';
  $parameter[]['fl'] = 'is_event_feature';
  $parameter[]['fl'] = 'path_alias';
  $parameter[]['fl'] = 'ss_language';
  $filter[]['bundle'] = 'event';
  $filter[]['ss_language'] = $language->language;
  //$filter[]['bs_event_status'] = TRUE;
  $sort = NULL;
  // Facet condition present.
  if (!empty($facet_condition)) {
    $facet = array();
    foreach ($facet_condition as $key => $val) {
      $facet_key_value = explode(':', $val);
      $facet[$facet_key_value[1]] = $facet_key_value[0];
    }

    // For application.
    if (in_array('im_field_event_application', $facet)) {
      $application_term_id = '';
      foreach ($facet as $facet_key => $facet_value) {
        if ('im_field_event_application' == $facet_value) {
          if (empty($application_term_id)) {
            $application_term_id .= '(' . $facet_key;
          }
          else {
            $application_term_id .= ' OR ' . $facet_key;
          }
        }
      }
      $application_term_id .= ')';
      $filter[]['im_field_event_application'] = $application_term_id;
    }
    // For Industry.
    if (in_array('im_field_event_industry', $facet)) {
      $industry_term_id = '';
      foreach ($facet as $facet_key => $facet_value) {
        if ('im_field_event_industry' ==  $facet_value) {
          if (empty($industry_term_id)) {
            $industry_term_id .= '(' . $facet_key;
          }
          else {
            $industry_term_id .= ' OR ' . $facet_key;
          }
        }
      }
      $industry_term_id .= ')';
      $filter[]['im_field_event_industry'] = $industry_term_id;
    }
    // For product category.
    if (in_array('im_field_event_product_category', $facet)) {
      $product_category_term_id = '';
      foreach ($facet as $facet_key => $facet_value) {
        if ('im_field_event_product_category' == $facet_value) {
          if (empty($product_category_term_id)) {
            $product_category_term_id .= '(' . $facet_key;
          }
          else {
            $product_category_term_id .= ' OR ' . $facet_key;
          }
        }
      }
      $product_category_term_id .= ')';
      $filter[]['im_field_event_product_category'] = $product_category_term_id;
    }
    // For Event Type.
    if (in_array('im_field_events_type', $facet)) {
      $event_type_term_id = '';
      foreach ($facet as $facet_key => $facet_value) {
        if ( 'im_field_events_type' == $facet_value) {
          if (empty($event_type_term_id)) {
            $event_type_term_id .= '(' . $facet_key;
          }
          else {
            $event_type_term_id .= ' OR ' . $facet_key;
          }
        }
      }
      $event_type_term_id .= ')';
      $filter[]['im_field_events_type'] = $event_type_term_id;
    }
  }

  // Location filter present.
  if (!empty($location_condition) && ($location_condition != 'all')) {
    $filter[]['sm_field_event_location'] = $location_condition;
  }

  if ($sort_condition) {
    if ($sort_condition == 'price') {
      $sort = 'fts_field_event_price desc';
  }
    elseif ($sort_condition == 'date') {
      $sort = 'ds_event_start_date Asc';
    }
    elseif ($sort_condition == 'feature') {
      $sort = 'is_event_feature desc';
    }
  }

  $data = igcommerce_event_solr_query($keyword, $parameter, $filter, $sort);

  return $data;
}
