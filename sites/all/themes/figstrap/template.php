<?php
/**
* @file
* The primary PHP file for this theme.
*/

/**
* Overrides theme_menu_tree() for the footer links.
* Add bootstrap nav classes to footer menu.
*/
function figstrap_menu_tree__menu_footer_navigation(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
* hook preprocess page
*/
function figstrap_preprocess_page(&$variables) { 

  if (isset($variables['node'])) { 
    if (isset($variables['node']->field_content_title['und'][0]['value'])) {
      $variables['title'] = $variables['node']->field_content_title['und'][0]['value'];
    }
  }

// If the user is logged in, this adds a class that has extra top padding
// so that the admin tabs arent' hidden by the site navbar.
if ($variables['logged_in'] == TRUE) {
    $variables['admin_banner_bumper'] = 'admin-banner-bumper';
  }
  else {
    $variables['admin_banner_bumper'] = '';
  }
}

/**
* hook preprocess node
*/
function figstrap_preprocess_node(&$variables) { 

}

/**
* hook preprocess field
*/

function figstrap_preprocess_field(&$variables) { 

}

/**
 * Implements hook_preprocess_image().
 * Remove width and height attributes from all images.
 */
function figstrap_preprocess_image(&$variables) {
  unset($variables['width']);
  unset($variables['height']);
}

/**
 * Implements theme_bef_checkbox().
 * Remove class .form-control from BEF checkboxes.
 *
 * BEF checkboxes are automaticaly generated with class .form-control,
 * which will break the Bootstrap theme stying.
 * https://www.drupal.org/node/2121203#comment-10834738
 * https://www.drupal.org/node/1404656
 */
function figstrap_preprocess_select_as_checkboxes(&$variables) {
  $element = &$variables['element'];
  //Remove form-control class added to original "select" element
  if (($key = array_search('form-control', $element['#attributes']['class'])) !== false) {
      unset($element['#attributes']['class'][$key]);
  }    
}




// theme_select
function figstrap_select($variables) {
  $element = $variables['element'];

  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-select'));
  return '<select' . drupal_attributes($element['#attributes']) . '>' . figstrap_form_select_options($element) . '</select>';

}

/**
 *
 * @param type $element
 * @param type $choices
 * @return string 
 */
function figstrap_form_select_options($element, $choices = NULL) {

  if (!isset($choices)) {
    $choices = $element['#options'];
  }

  // array_key_exists() accommodates the rare event where $element['#value'] is NULL.
  // isset() fails in this situation.
  $value_valid = isset($element['#value']) || array_key_exists('#value', $element);
  $value_is_array = $value_valid && is_array($element['#value']);
  $options = '';
  foreach ($choices as $key => $choice) {

    if (is_array($choice)) {
      $options .= '<optgroup label="' . $key . '">';
      $options .= figstrap_form_select_options($element, $choice);
      $options .= '</optgroup>';
    }
    elseif (is_object($choice)) {
      $options .= figstrap_form_select_options($element, $choice->option);
    }
    else {
      $key = (string) $key;
      if ($value_valid && (!$value_is_array && (string) $element['#value'] === $key || ($value_is_array && in_array($key, $element['#value'])))) {
        $selected = ' selected="selected"';
      }
      else {
        $selected = '';
      }
       
      if ($element['#id'] === 'edit-language-choice') { 
         $options .= '<option class="language-selector ' . drupal_clean_css_identifier($key) . '"  value="' . check_plain($key) . '"' . $selected . '>' . check_plain($choice) . '</option>';
      } else { 
         $options .= '<option class="' . drupal_clean_css_identifier($key) . '"  value="' . check_plain($key) . '"' . $selected . '>' . check_plain($choice) . '</option>';
      }
    }
  }
  return $options;
}

function figstrap_preprocess(&$variables, $hook) {
// This will show you the load order of all items on the page
// static $i;
// kpr($i . " " . $hook);
// $i++;
}


function figstrap_preprocess_tb_megamenu(&$variables) {
  // The tb_megamenu gets processed before page.tpl.php, so we
  // make the logo variable availble ahead of schedule.
  //$variables['logo'] = theme_get_setting('logo');
}
