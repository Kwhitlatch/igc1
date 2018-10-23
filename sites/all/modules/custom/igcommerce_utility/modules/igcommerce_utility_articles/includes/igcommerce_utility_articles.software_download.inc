<?php
function igcommerce_utility_articles_get_software_download_listings($search = FALSE) {
    global $language;
    $output = '';
    
    if (!$search) {
      $output .= theme('articles_software_download_form');
    }
    
    /**
    Example query:
    https://fluke7-master.solrcluster.com/solr/fluke7/select?q=(path_alias:support/software-downloads/*)&wt=json&indent=true&start=0&rows=5
    **/
    // TO DO: We may need to find these contents using 'sm_url_path_builder' if the 'path_alias' does not work.
    // Example code is in this function:igcommerce_utility_load_toc_from_path()
    $fields = 'ss_language,tm_article_display_title,tm_field_content_title,path_alias,ss_field_url_title,ds_created,entity_id,ts_article_body';
    
    $target_query = !empty($_GET['filter']) ? $_GET['filter'] : NULL;

    $options = array(
        "ss_language" => $language->language,
        "bundle" => "article",
        "entity_type" => "node",
        'ss_path_alias' => 'support/software-downloads/*',
    );

    $filter_options = array(
        'filters' => $options,
        'fl' => $fields,
        'rows' => 300,
        'sort' => 'ss_field_content_title ASC'
    );
    
    if ($target_query) {
      $filter_options['q'] = "*" . $target_query . "*";
      unset($filter_options['sort']);
    }


    // Added by TT on May 29, 2018 to improve search relevancy -- updates end line 79

    // Add bias for specific fields for custom CJK fields.
    if (in_array($language->language, array('cn', 'ko-kr', 'ja-jp'))) {
        // Add qf params if required by language and add bias values
        $bias = array(
            'display_title_cjk' => 50,
            'body_cjk' => 1,
        );
    }
    else {
        // Boost title fields as they are most important
        $bias = array(
            'tm_field_content_title' => 50,
            'ts_article_body' => 1,
        );

    }

    $qf = array();

    foreach ($bias as $field => $bias_value) {
        $qf[] = $field . '^' . $bias_value;
    }

    $qf = implode(' ', $qf);
    // Use pf here to boost instead of query these fields as it will return 0 results since these fields aren't in all bundles
    $qf = trim($qf);
    $filter_options['params']['pf'] = $qf;

    // End of added on May 29th

    $query = fluke_solr_get_connection();
    $filters = fluke_solr_add_filters($query, $filter_options);
    


    $response = fluke_solr_query($filters);
    $lang_local = igcommerce_utility_get_local();
    $output .= theme('articles_software_download',
        array('items' => $response->response->docs,
            'language' => $lang_local,
            'filter' => $target_query,
            'total' => count($response->response->docs)));
    
    return $output;
}
// This is a fallback function for individual download page
// we are not using this much since we mostly use accordion on the page
function igcommerce_utility_articles_get_software_download_detail($path_alias) {
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

    return theme('articles_software_download_detail',
        array('item' => $response->response->docs)
    );
}