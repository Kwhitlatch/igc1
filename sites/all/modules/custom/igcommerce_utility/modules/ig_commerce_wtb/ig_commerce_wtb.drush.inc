<?php

function ig_commerce_wtb_drush_command(){
    $commands['wtb-fix-urls'] = [
        'description' => 'Fix url aliases for wtb.  Have them all point to the panel page',

    ];

    return $commands;
}

function drush_ig_commerce_wtb_wtb_fix_urls(){
    $term = array_pop(taxonomy_get_term_by_name('Where to buy','url_builder'));

    foreach ($term->field_url_title as $language => $values){
        $alias = $values[0]['value'];
        $sys_path = drupal_lookup_path('source', $alias, $language); //should result in node/12417

        if($sys_path){
            $system_path = $sys_path;
        }
        $path = [
          'source' => 'where-to-buy',
          'alias' => $alias,
          'language' => $language,
        ];

        path_save($path);
    }

}