<?php
function igcommerce_utility_articles_get_press_releases() {
    global $language;

    // Do meta title and description
    $term = fluke_solr_get_term_by_name('Press releases', 'url_builder');

    igcommerce_utility_head_elements($term, TRUE);

    /**
     * Example query:
     * https://fluke7-master.solrcluster.com/solr/fluke7/select?q=(path_alias:support/press-releases/*)&fq=ss_language:en-us&fq=bundle:article&fq=entity_type:node&wt=json&indent=true&start=0&rows=5
    **/
    // TO DO: We may need to find these contents using 'sm_url_path_builder' if the 'path_alias' does not work.
    // Example code is in this function:igcommerce_utility_load_toc_from_path()
    $fields = 'ss_language,ds_created,tm_article_display_title,ss_field_content_title,tm_field_content_title,path_alias,ss_field_url_title,ss_publication_date,ds_publication_date,entity_id,ts_article_body,ss_path_alias_locale';
    $target_query = 'ss_path_alias:support/press-releases*'; // Try to pick up items without an english url title by leaving out the trailing '/'
    $filter_title = '';

    $options = array(
        "ss_language" => $language->language,
        "bundle" => "article",
        "entity_type" => "node",
    );
    if(isset($_GET['filter'])) {
      $filter_title = FALSE;
      if (!empty($_GET['filter'])) {
        $options['tm_article_display_title'] = '*' . $_GET['filter'] . '*';
        $filter_title = $_GET['filter'];
      }
    }

    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query,
        array('q' => $target_query,
        'filters' => $options,
        'fl' => $fields,
        'rows' => 1000));

    $query->addParam('sort', 'ds_publication_date desc');

    $response = fluke_solr_query($filters);
    // If we get any content back, we then group them by publication month
    $sorted_content = array();
    if($response->response->numFound > 0) {
        $i = 0;
        foreach($response->response->docs as $key => $value){
          if (!empty($value->ss_publication_date)) {
            if (strtotime($value->ss_publication_date) == 0) {
              $value->ss_publication_date = $value->ds_created;
            }
            // Create a PHP DateObject
            $date = new DateObject($value->ss_publication_date);
            // Get the translated month and year.

            if($language->language == 'cn') {
              // Avoid translation issues with the China format of the date
              $month = date_format_date($date, 'custom', 'n');
              $year = date_format_date($date, 'custom', 'Y');

              // @todo : we would need a translation for month to use t()
              $date = $year.' '.t('Year').' '.$month.' 月';//t('Month');

              // @todo: look into how we can use the normal drupal approach to this with chinese dates

            }else{
              $date = date_format_date($date, 'custom', 'F Y');
            }

            $sorted_content[$date]['month'] = $date;
            $sorted_content[$date]['date_sort'] = date('Ym', strtotime($value->ss_publication_date));
            
            // Add link
            if (empty($value->ss_field_content_title)) {
              watchdog('ig_press_release', 'Missing ss_field_content_title: '. print_r($value, TRUE), array(), WATCHDOG_NOTICE);
              // Add a default title
              $value->ss_field_content_title = t('Press Release')  . ' ' . $date;
            }
            
            $value->link = l($value->ss_field_content_title, $value->ss_path_alias_locale, array('attributes' => array('title' => $value->ss_field_content_title)));
            $sorted_content[$date]['data'][] = $value;
            $i++;
          }
        }
    }
    // Sort publication date in descending order
    usort($sorted_content, function($a, $b) {
        $a = strtotime($a['date_sort']);
        $b = strtotime($b['date_sort']);
        return $b - $a;
    });

    $content = theme('articles_press_release_listings',
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
function igcommerce_utility_articles_get_press_release_detail($path_alias) {
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
    return theme('articles_press_release_detail',
        array('item' => $response->response->docs)
    );
}