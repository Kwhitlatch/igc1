<?php
function igcommerce_utility_articles_get_awards() {
      global $language;
      $output = NULL;

      $lang = $language->language;

    // Do meta title and description
    $term = fluke_solr_get_term_by_name('Awards', 'url_builder');
    igcommerce_utility_head_elements($term, TRUE);

    /**
     * Example query:
     * https://fluke7-master.solrcluster.com/solr/fluke7/select?q=(path_alias:products/awards/*)&fq=ss_language:en-us&fq=bundle:article&fq=entity_type:node&wt=json&indent=true&start=0&rows=5
    **/
    // TO DO: We may need to find these contents using 'sm_url_path_builder' if the 'path_alias' does not work.
    // Example code is in this function:igcommerce_utility_load_toc_from_path()
    $fields = 'is_term_year,tm_related_products,ss_language,tm_awards_display_title,ss_field_content_title,ts_field_content_title,ss_path_alias,ds_created,ds_changed,entity_id,tm_short_desc_summary,ss_path_alias_locale,sm_url_product_category,sm_country_display_title,bs_status,ss_toc_large_img_url';
    $target_query = '*'; // Try to pick up items without an english url title by leaving out the trailing '/'
    $filter_title = '';

    $options = array(
        "ss_language" => $language->language,
        "bundle" => "awards",
        "entity_type" => "node",
    );
    if(isset($_GET['filter'])) {
      $filter_title = FALSE;
      if (!empty($_GET['filter'])) {
        $options['tm_awards_display_title'] = '*' . $_GET['filter'] . '*';
        $filter_title = $_GET['filter'];
      }
    }

    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query,
        array('q' => $target_query,
        'filters' => $options,
        'fl' => $fields,
        'rows' => 1000));

    $query->addParam('sort', 'is_term_year desc');

    $response = fluke_solr_query($filters);
    // If we get any content back, we then group them by is_term_year
    $sorted_content = array();
    if($response->response->numFound > 0) {
        $i = 0;
        foreach($response->response->docs as $key => $value){
          //Only show awards if they have related products OR custom award image.
          //Related products will add the hero image to left column, custom image will replace the image with the field in ss_toc_large_img_url
          //TODO: If we want to show ALL awards, we should request a generic fallback image from graphics for awards without either of the above.

          if (!empty($value->tm_related_products) || !empty($value->ss_toc_large_img_url)) {

            if (!empty($value->is_term_year)) {
              if ($value->is_term_year == 0) {
                $value->is_term_year = $value->ds_changed;
              }
              // Date value created based on is_term_year dropdown in ecm
              $date = $value->is_term_year;            

              $sorted_content[$date]['month'] = $date;
              $sorted_content[$date]['date_sort'] = date('Ym', $value->ds_created);
              
              // Add link
              if (empty($value->ss_field_content_title)) {
                watchdog('ig_awards', 'Missing ss_field_content_title: '. print_r($value, TRUE), array(), WATCHDOG_NOTICE);
                // Add a default title
                $value->ss_field_content_title = t('Awards')  . ' ' . $date;
              }
              
              //Related Products
              $products = json_decode($value->tm_related_products[0]);
              $prods = $products->$lang;
              // Get Product variables
              foreach ($prods as $product) {
                $title = $product->display_title;
                $url = $product->rel_prod_path_alias;
                $alt = $product->alt;
                $img_url = !empty($product->image) ? $product->image : '';
                $styles = igcommerce_utility_get_images($img_url);
              }
              $value->award_custom = $value->ss_toc_large_img_url;
              
              if (!empty($value->award_custom)) {
                $styles = igcommerce_utility_get_images($value->award_custom);
              }

              $value->award_img = igcommerce_utility_determine_toc_image($styles['field_original_url'], $styles['field_original_url'], $styles['field_medium_url'], $product->display_title);
              $value->url = $url;
              $value->title = $title;
              $value->alt = $alt;
              //If no related product, use award as title
              if (!empty($value->tm_related_products)) {
                $value->link = l($value->title, $value->url, array('attributes' => array('title' => $value->title)));
              }
              else{
                $value->link = $value->tm_awards_display_title[0];
              }
              $value->img_link = l($value->award_img, $value->url, array('attributes' => array('title' => $value->title)));
              $value->award_name = $value->tm_awards_display_title[0];
              // If there isn't a related product, replace the h2 with the award name. Replace the award name with the short description. Remove the link as it now
              // Goes nowhere.
              if (empty($value->tm_related_products)) {
                $value->award_name = $value->tm_short_desc_summary[0];
                $value->img_link = $value->award_img;
              }
              $value->descrip = $value->tm_short_desc_summary[0];
              $value->country = $value->sm_country_display_title[0];
              $value->year = $value->is_term_year;

              //$value->changed = $value->ds_changed;
              $sorted_content[$date]['data'][] = $value;

              $i++;
            }
          }
        }
    }
    // Sort publication date in descending order
    usort($sorted_content, function($a, $b) {
        $a = $a['date_sort'];
        $b = $b['date_sort'];
        return $b - $a;
    });

    $content = theme('articles_awards_listings',
        array('items' => $sorted_content,
            'language' => $language->language,
            'filter' => $filter_title,
            'total' => $response->response->numFound));
    // For ajax call, we need to exit here
    if(isset($_GET['filter'])) {
        exit($content);
    }
    return $content;
}

// This is a fallback function for individual download page
// we are not using this much since we mostly use accordion on the page
function igcommerce_utility_articles_get_awards_detail($path_alias) {
    global $language;
    /**
    Example query:
     **/
    $fields = '';
    $options = array(
        "ss_language" => $language->language,
        "bundle" => "article",
        "entity_type" => "node",
    );

    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query,
        array('q' => '(ss_field_url_title:'.$path_alias.')',
            'filters' => $options,
            'fl' => $fields));

    $response = fluke_solr_query($filters);
    return theme('articles_awards_detail',
        array('item' => $response->response->docs)
    );
}