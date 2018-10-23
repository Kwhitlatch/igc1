<?php

/**
 * Implements template_preprocess_html().
 */
function ig_neato_preprocess_html(&$variables) {

  // Used to check for china and add Tealium script accordingly.
  global $base_url;
  global $language;

  $brand_theme = theme_get_setting('ig_neato_theme_selector');
  if ($brand_theme){
    $brand_css_path = path_to_theme().'/'.'css/'.$brand_theme.'.css';
    $options = array(
      'type' => 'file',
      'group' => CSS_THEME,
      'every_page' => TRUE,
      'weight' => '100',
    );
    drupal_add_css($brand_css_path, $options);
  }
   // IE Fixes with http-equiv
  $data = array(
     '#tag' => 'meta',
     '#attributes' => array(
       'http-equiv' => "X-UA-Compatible",
       'content' => "IE=edge",
       //Chrome=1 flag has been depricated and will be flagged as invalid by w3c
       //'content' => "IE=edge,chrome=1",
       )
     );

   drupal_add_html_head($data,'key');

  // Adding json_ld schema to every page except home page
  if (!drupal_is_front_page()) {
      $schema = igcommerce_utility_breadcrumbs_json_ld();
      if(!empty(trim($schema))) {
        // This is a vulgar way to add a script, but some tags were getting stripped: 
        // https://www.drupal.org/project/structured_data/issues/2527346
        $json_ld_script = array(
        '#type' => 'markup',
        '#markup' => '<script type="application/ld+json">' . $schema . '</script>' . "\n",
      );
    drupal_add_html_head($json_ld_script, 'structured_data_json_ld');
    }
  }

  // Only add cached version of cache-control header if the page isn't set to false in drupal_page_is_cachable
  // Cloudflare won't cache the page if cache-control is set to no-cache, must-revalidate
  // Pages that use Drupal ajax forms (such as wtb ) can't be cached since they
  // use the csrf token, which needs to be regenerated every time page is served.
  if(drupal_page_is_cacheable() !== FALSE){
    drupal_add_http_header("cache-control","max-age=2549000", FALSE);
  }

  // We want to add the Tealium scripts to the live china site only.
  if ($language->language == 'cn') {
    
    $tealium_environment = "dev";
    $url_chunk_to_check = $base_url;
    
    $position = strpos($base_url, '//');
    // If there's a // in the url, get the part after it for checking.
    // Note our use of ===.  Simply == would not work as expected
    // because the position of '//' could be the 0th (first) character.
    if (!$position === false) {
      $string_start = $position + 2;
      $url_chunk_to_check = substr($url_chunk_to_check, $string_start);
    }
  
    // Check to see if we're in a live the live environment 
    if ($url_chunk_to_check == 'fluke.com.cn' || $url_chunk_to_check == 'fluke.com.cn' ) {
      // Set the tealium enviornment accordingly.
      $tealium_environment = "prod";
    }
    // This .js looks broken, but that's how we got it from Marike, and it seems to work.
    drupal_add_js('jQuery(document).ready(function () { 
      var utag_data = {

      }
      });', array(
        'type' => 'inline',
        'scope' => 'footer',
        'weight' => 9,
    ));

    drupal_add_js("jQuery(document).ready(function () { 

      (function(a,b,c,d){ 
    a='//tags.tiqcdn.com/utag/fluke/main/" . $tealium_environment . "/utag.js'; 
    b=document;c='script';d=b.createElement(c);d.src=a;d.type='text/java'+c;d.async=true; 
    a=b.getElementsByTagName(c)[0];a.parentNode.insertBefore(d,a); 
    })(); 
      
    });", array(
      'type' => 'inline',
      'scope' => 'footer',
      'weight' => 10,
    ));

  }
  else {
    // The maxymiser script borks performance in china, so use it on every other locale instead. MIG2225.
    //drupal_add_js(drupal_get_path('theme', 'ig_neato') . '/js/maxymiser.js');
  }
}

/**
 * Implements template_preprocess_page.
 */
function ig_neato_preprocess_page(&$variables) {

  // Get the entire main menu tree
  $main_menu_tree = menu_tree_all_data('menu-primary-nav');

  // Add the rendered output to the $main_menu_expanded variable
  $variables['main_menu_expanded'] = menu_tree_output($main_menu_tree);

  // Gets the last 2 chars of the language code (Ex: en-us) which should
  // correspond to the two letter ISO3166 country code
  $country = substr($variables['language']->language, -2);
  // This variable is used by page.tpl.php to add the correct flag icon,
  $variables['user_country_flag'] = $country;

  // This styles the content-type "promotions"
  if (!empty($variables['node'])) {
    if ($variables['node']->type == 'promotion') {

    // $promotion_country is used to support translations
    $promotion_country = $variables['language']->language;

    // Adds the custom head html field to the html head, if the field is not empty
    if (!empty($variables['node']->field_custom_meta_head_element)) {
      $element = array(
        '#type' => 'markup',
        '#markup' => $variables['node']->field_custom_meta_head_element[$promotion_country][0]['value'],
        '#weight' => '1000');
      drupal_add_html_head($element, 'promotion-custom-head-element');
    }

      // This adds a variable that page--promotion.tpl.php uses to show/hide the
      // header or footer.  The show/hide fields also has an N/A option, which will
      // result in an empty array, which is why the logic checks for !empty && == 1.
      $variables['hidden_header'] = '';
      $variables['hidden_footer'] = '';
      if (!empty($variables['node']->field_show_global_header_nav_on_) && $variables['node']->field_show_global_header_nav_on_[$promotion_country][0]['value'] == 1) {
        $variables['hidden_header'] = 1;
      }
      if (!empty($variables['node']->field_show_global_footer_on_prom) && $variables['node']->field_show_global_footer_on_prom[$promotion_country][0]['value'] == 1) {
        $variables['hidden_footer'] = 1;
      }
    }
  }

  /** special handling of page titles **/
  igcommerce_utility_head_elements();
}

/**
 * Implements template_preprocess_node.
 */
function ig_neato_preprocess_node(&$variables) {
}

/* The country module has a variable for continents that only needs to be changed
  once.  If you need to update or add continent names, uncomment this code, load a page that uses template.php, then comment out this code again.  Detailed instructions can be found on line 264 of the README.txt in the countries module:
  \igcommerce\profiles\commerce_kickstart\modules\contrib\countries\README.txt
*/

/*
variable_set('countries_continents', array(
  'NA' => t('North America'),
  'AF' => t('Africa'),
  'EU' => t('Europe'),
  // These are not official content codes, They are custom for Fluke
  'F1' => t('South and Central America'),
  'F2' => t('Russia/CIS countries'),
  'F3' => t('Middle East'),
  'F4' => t('Asia Pacific'),
));
*/

function ig_neato_preprocess_views_view(&$vars) {
    $view = &$vars['view'];
    //dpm($view);
    if ($view->name == 'product_toc_solr') {
        // add needed javascript
        drupal_add_js(drupal_get_path('theme', 'ig_neato') . '/js/js-src/tocs.js');
    }
}

/**
 * Implements hook_form_alter.
 */
function ig_neato_form_alter(&$form, &$form_state, $form_id) {

}

/**
 * Implements theme_html_tag
 */
function ig_neato_process_html_tag(&$vars) {
  $el = &$vars['element'];
  // The attribute type="..." in <script> and <style> tags has been depericated
  // in html5. This will remove them.
  if ($el['#tag'] === 'script' || $el['#tag'] === 'style') {
    unset($el['#attributes']['type']);
  }
}

/**
 * Implements hook_html_head_alter().
 */
function ig_neato_html_head_alter(&$head_elements)
{

    global $language;

    // Removes <meta name="Generator" content="Drupal 7 (http://drupal.org)" />
    if (isset($head_elements['system_meta_generator'])) {
        unset($head_elements['system_meta_generator']);
    }
    // Also Removes <meta name="Generator" content="Drupal 7 (http://drupal.org)" />
    if (isset($head_elements['metatag_generator_0'])) {
        unset($head_elements['metatag_generator_0']);
    }
    // Removes <link rel="shortlink" href="XX">
    // Removal requested by Francisco, Marika <marika.francisco@fluke.com>)
    if (isset($head_elements['metatag_shortlink'])) {
        unset($head_elements['metatag_shortlink']);
    }

    // rewriting the canonicals for es-languages
    // if the language-locale is one of the minor es language sites, then set the canonical for any product, learn, or
    // support page to es-mx
    if (isset($head_elements['metatag_canonical'])) {
        $es_languages = array('es-us', 'es-gt', 'es-sv', 'es-co', 'es-do', 'es-ec', 'es-pe', 'es-cr', 'es-bo', 'es-uy',
            'es-ar', 'es-cl', 'es-us');
        $fr_langauges = array('fr-fr', 'fr-be', 'fr-ca', 'fr-ch');
        if (in_array($language->language, $es_languages)) {
            if (strpos(strtolower($head_elements['metatag_canonical']['#value']), "productos") > 0 ||
                strpos(strtolower($head_elements['metatag_canonical']['#value']), "producto") > 0 ||
                strpos(strtolower($head_elements['metatag_canonical']['#value']), "producto") > 0 ||
                strpos(strtolower($head_elements['metatag_canonical']['#value']), "soporte") > 0) {
                    $head_elements['metatag_canonical']['#value'] =
                        str_replace($language->language, "es-mx", $head_elements['metatag_canonical']['#value']);
            } elseif (strpos(strtolower($head_elements['metatag_canonical']['#value']), "informacion") > 0) {
                $head_elements['metatag_canonical']['#value'] =
                    str_replace($language->language, "es-es", $head_elements['metatag_canonical']['#value']);
            }
        }
        // added for MIG-4502 - handling FR-FR canonicals
        elseif (in_array($language->language, $fr_langauges)) {
            if ($language->language == "fr-ca" &&
                (strpos(strtolower($head_elements['metatag_canonical']['#value']), 'apprendre') > 0)) {
                $head_elements['metatag_canonical']['#value'] =
                    str_replace($language->language, "fr", $head_elements['metatag_canonical']['#value']);
            }
            elseif (!drupal_is_front_page() && $language->language != 'fr-ca') {
                $head_elements['metatag_canonical']['#value'] =
                    str_replace($language->language, "fr", $head_elements['metatag_canonical']['#value']);
            }
        }
    }

}


/**
 * Implements theme_button - Fixed blank name field for W3C validation.
 */
function ig_neato_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  $attributes = array('id', 'value');
  if (!empty($element['#name'])) {
    $attributes[] = 'name';
  }
  element_set_attributes($element, $attributes);  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }
  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

function ig_neato_preprocess_link(&$vars) {
  if (!empty($vars['options']['query'])) {
    $vars['options']['attributes']['rel'] = 'nofollow';
  }
}

function ig_neato_link($variables) {
  
  return '<a href="' . rawurldecode(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . ($variables['options']['html'] ? $variables['text'] : rawurldecode($variables['text'])) . '</a>';
  //return '<a href="' . url($variables['path'], $variables['options']) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])) . '</a>';
}
