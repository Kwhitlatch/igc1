<?php

/**
 * Main function for rendering the new products page
 */
function igcommerce_utility_product_new_products_page(){
    global $language;
    $lang = $language->language;

    $term = fluke_solr_get_term_by_name('New Fluke products', 'url_builder');

    if(!empty($term)) {
      igcommerce_utility_head_elements($term, TRUE);
    }

    drupal_add_css(drupal_get_path('module', 'igcommerce_utility_products') . '/css/igcommerce_utility_products_new.css');

    $filters = array(
        'ds_created' => '[NOW-8MONTHS TO NOW]', //@todo: We need to use something different for this date filter, possibly bases ond scheduling module
        "bs_is_new_product" => TRUE,
        "ss_language" => $lang,
        "bundle" => "product_display",
        'bs_status' => 1,
    );

    $sort = ['ds_created', 'desc']; //@todo: need to sort by the new field mentioned above

    $query = fluke_solr_get_connection();

    $query_options = fluke_solr_add_filters($query, array('filters' => $filters, 'sort' => $sort, 'rows' => 100));
    $response = fluke_solr_query($query_options);

    if(count($response->response->docs) < 1) {
        $filters = array(
            'ds_created' => '[NOW-12MONTHS TO NOW]', //@todo: We need to use something different for this date filter, possibly bases ond scheduling module
            "bs_is_new_product" => TRUE,
            "ss_language" => $lang,
            "bundle" => "product_display",
            'bs_status' => 1,
        );

        $sort = ['ds_created', 'desc']; //@todo: need to sort by the new field mentioned above

        $query = fluke_solr_get_connection();

        $query_options = fluke_solr_add_filters($query, array('filters' => $filters, 'sort' => $sort));
        $response = fluke_solr_query($query_options);
    }

    $output = '';
    foreach($response->response->docs as $doc){
        $product_url = igcommerce_utility_product_tocs_get_url($doc);

        $output .= '<div class="new-product-container">';

        if (!empty($doc->is_product_slideshow)) {
          $slideshow = fluke_solr_get_entity($doc->is_product_slideshow, 'node', 'slideshow', $lang);
          if (!empty($slideshow->sm_field_product_image_desktop[0])) {
            $images = json_decode($slideshow->sm_field_product_image_desktop[0], TRUE);
            
            $val = $images;
            $image = format_new_product_image($val);
            $output .= '<div class="new-product-img">' . l($image, $product_url, array('html' => TRUE)) . '</div>';
            
          }
        }

        $output .= '<h2>' . l($doc->ss_field_content_title, $product_url) . '</h2>';
        
        if(!empty($doc->tm_summary[0])){
            $output .= '<div class="new-product-summary">'.$doc->tm_summary[0].'</div>';
        }else{
            $output .= '<div class="new-product-summary">';
            $output .= !empty($doc->tm_short_description_summary[0]) ? '<p>'.$doc->tm_short_description_summary[0].'</p>' : '<p></p>';
            $output .= '</div>';
        }

        $output .= '</div>';
    }

    return $output;
}


function format_new_product_image($val){

    $s3_url = variable_get('s3_bucket_url', '');
    $default_assets_url = 'data.fluke.com/sites/default/files';


    if (strpos($val['url'], $default_assets_url)){

        $val['url'] = str_replace($default_assets_url, $s3_url, $val['url']);
        $val['url'] = str_replace("//http://", "http://", $val['url']);

    }

    $styles = igcommerce_utility_get_images($val['url']);
    
    return igcommerce_utility_determine_toc_image($styles['field_large_url'], FALSE, FALSE, $val['alt']);
}