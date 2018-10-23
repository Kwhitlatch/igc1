<?php

/**
 * @file
 * Build the left nav for article TOC pages that uses SOLR
 */
function igcommerce_utility_articles_build_category_toc_nav() {

  global $language;
  global $base_url;
  $output = '';

  $url_path = current_path();
  $url_path_parts = explode("/", $url_path);

  //check if current url is of article from ecm
  /*
  $current_path = current_path();
  $alias = explode('/', $current_path);
  if ($alias[0] == 'node') {
    $path_exist = drupal_lookup_path('alias', $current_path);
  }
  else {
   $alias = 'taxonomy/' . end($alias);
   $path_exist = drupal_lookup_path('source', $alias);
  }*/

  // If article page appear highlight the term
  if ((in_array('safety-notices', $url_path_parts) && count($url_path_parts) > 2) ||
    (in_array('press-releases', $url_path_parts) && count($url_path_parts)> 2) ||
    (in_array('software-downloads', $url_path_parts) && count($url_path_parts)> 2 )) {

    array_pop($url_path_parts);
    $url_path = implode('/', $url_path_parts);
  }


  // Before rebuilding the menu - look to see if a cached version exists
  // and return the cached version.
  //Note: The cache menu code is commented for now, because it
  //active, bold default menu tree open and other options not working correctly.
//  $cached_menu_name = 'ig_article_left_nav-' . $url_path_parts[0] .'-'. $language->language;
//  $cached_menu = cache_get($cached_menu_name, 'cache');
//  if ($cached_menu) {
//    return unserialize($cached_menu->data);
//    return $output;
//  }

  // the source of the menu tree is the second item in the path
  // such as solutions/industries  or solutions/applications
  
  $toc_menu_term = $url_path_parts[0];
  if (!$menu_term = _taxonomy_term_load_by_url_title_solr($toc_menu_term, 'url_builder', 'en-us')) {
    return $output;
  }

  $terms = igcommerce_utility_load_term_children($menu_term->entity_id);
  
  /* allows menu to appear as dropdown list on mobile */
  $output .= '<div class="custom-collapse">';
  /* mobile dropdown menu button */
  $output .= '
    <button class="btn btn-block collapse-toggle visible-xs visible-sm" type="button" data-toggle="collapse" data-parent="custom-collapse" data-target="#accordion-left" aria-expanded="false">
      <span class="">' . t('Choose your category') . '</span>
      <span class="pull-right fluke-icon fluke-icon-fa-bars">
      </span>
    </button>';

  $output .= '<div class="panel-group collapse in" id="accordion-left" aria-expanded="true" role="menu">';

  // On Fluke News Page, list only its own child items
  // mig-1315 : The behavior below was reported as a bug.  Commenting out in case this is supposed to be here
  /*
  if (in_array( "fluke-news" , $url_path_parts )) {
    foreach ($terms as $key => $value) {
      if ($value->label !== 'Fluke news') {
        unset($terms[$key]);
      }
    }
  }*/

  foreach ($terms as $menu_item) { //print_r($menu_item->field_hide_from_toc_left_navigat);
    //hide the menu if field_hide_from_toc_left_navigat is set
    if(!empty($menu_item->bs_field_hide_from_toc_left_navi)) {
      continue;
    }
    
    $children = igcommerce_utility_load_term_children($menu_item->entity_id);
    if ($children) {
      $display = '';
      $expand = '';
      $expand_wrapper = '';
      $active_class = array();
      if (!empty($menu_item->sm_field_url_title[0])) {
        $parent = $menu_item->sm_field_url_title[0];
        $parent_translated = $e_type = str_replace(' ', '-', $menu_item->label);
        $parent_translated = strtolower($parent_translated);
    
        //check if this is the parent of current term from the url.
        if (strpos($url_path, $parent_translated)) {
          $expand_wrapper = 'expanded-wrapper'; //adds a class to parent of current active term.
          $expand = 'expanded';
          $display = 'style="display: block;"'; // expands the block of current active term.
          $active_class = array('active-trail', 'active');
        }
      }
      $output .= '<div class="panel panel-default">';
      $output .= '<div class="panel-heading ' . $expand_wrapper . '">';
      $output .= '<h4 class="panel-title">';
    
      if (!empty($menu_item->ss_field_url)) {
        $path = new stdClass();        
        $path->type = NULL;
        $path->link = $menu_item->ss_field_url;        
      } else {
        $path = igcommerce_utility_articles_build_url($menu_item);        
      }

      if (isset($path->link)) {
        if ($path->type === 'auto') {
          $parent_path = $path->link;          
        }
        else {
          $parent_path = NULL;
        }
      }
      
      $url = $path->link;
      
      if (isset($menu_item->sm_field_content_title[0])) {
        $link_copy = $menu_item->sm_field_content_title[0];
      }
      else {
        $link_copy = $menu_item->label;
      }
    
      $output .= l($link_copy, $url, array('html' => TRUE, 'language' => $language, 'attributes' => array('class' => [$active_class])));
      $output .= '</h4>';
    
      if (!empty($path->link) && (strpos($url_path, $path->link) === FALSE)) {
        $output .= '<a data-toggle="collapse" class="collapsed plus-minus pull-right ' . $expand . '" data-parent="#accordion-left" href="#collapse-' . $menu_item->entity_id . '">';
      }
      else {
        $output .= '<a data-toggle="collapse" class="plus-minus pull-right ' . $expand . '" data-parent="#accordion-left" href="#collapse-' . $menu_item->entity_id . '" aria-expanded="true">';
      }
    
      $output .= '</a>';
      $output .= '</div>'; //panel-heading
    
      if (!empty($path->link) && (strpos($url_path, $path->link) === FALSE)) {
        $output .= '<div id="collapse-' . $menu_item->entity_id . '" class="panel-collapse collapse" ' . $display . ' role="menuitem">';
      }
      else {
        $output .= '<div id="collapse-' . $menu_item->entity_id . '" class="panel-collapse collapse in" ' . $display . ' aria-expanded="true" role="menuitem">';
      }
      $output .= '<div class="panel-body">';
    
      foreach ($children as $child) {
        //hide the menu if field_hide_from_toc_left_navigat is set
        if(!empty($child->bs_field_hide_from_toc_left_navigat)) {
          continue;
        }
    
        if (!empty($child->ss_path_alias_locale)) {
          $path = new stdClass();
          $path->type = NULL;
          $path->link = $child->ss_path_alias_locale;
        } else {
          $path = igcommerce_utility_articles_build_child_url($parent_path, $child);
        }
          
        if (!is_null($path)) {
          $output .= "<div class='child-menu-item'>";
          $active_class = array();
          if (!empty($child->sm_field_url_title[0])) {
            $child_title = $child->sm_field_url_title[0];
            $child_translated  = $e_type = str_replace(' ', '-', $child->label);
            $child_translated = strtolower($child_translated);

            if (end($url_path_parts) == $child_translated) {
              $active_class = array('active-trail', 'active');
            }
    
            if (end($url_path_parts) == $child_title) {
              $active_class = array('active-trail', 'active');
            }
    
            //Check if the parent menu is present in menu,if yes make it bold
            $parent_val = $url_path_parts;
            $current_menu_path = explode('/', $path->link);
            array_pop($parent_val);
            $parent_val = array_pop($parent_val);
    
            if ($parent_val === $child_title) {
              $active_class = array('active-trail', 'active');
            }
          }
          
          if (!empty($child->sm_field_content_title[0])) {
            $link_copy = $child->sm_field_content_title[0];
          }
          else {
            $link_copy = $child->label;
          }
          
          //MIG2169 - Applied external url logic to $child items
          if (!empty($child->ss_field_url)) {
            $path = new stdClass();
            $path->type = NULL;
            $path->link = $child->ss_field_url;
          }
          
          $output .= l($link_copy, $path->link, array('html' => TRUE, 'language' => $language, 'attributes' => array('class' => [$active_class])));
          $output .= "</div>";
        } // end of check to see if path is null
      } // end of processing children
    
      $output .= '</div>'; //body
      $output .= '</div>'; //collapse
      $output .= '</div>'; //default
    }
    else {
      //if (($menu_item->depth == 0 && !is_null($menu_item->depth) ) && sizeof($children) == 0) {  // its a parent term without children      
      $output .= '<div class="panel panel-default">';
      $output .= '<div class="panel-heading">';
      $output .= '<h4 class="panel-title">';
    
      if (!empty($menu_item->ss_field_url)) {
        $path2 = new stdClass();
        $path2->type = NULL;
        $path2->link = $menu_item->ss_field_url;
      } else {
        $path2 = igcommerce_utility_articles_build_url($menu_item);
      }
      
      $active_class = array();
    
      if ($url_path == $path2->link) {
        $expand_wrapper = 'expanded-wrapper'; //adds a class to parent of current active term.
        $expand = 'expanded';
        $display = 'style="display: block;'; // expands the block of current active term.
        $active_class = array('active-trail', 'active');
      }
    
      if (isset($menu_item->sm_field_content_title[0])) {
        $link_copy = $menu_item->sm_field_content_title[0];
      }
      else {
        $link_copy = $menu_item->label;
      }
    
      $output .= l($link_copy, $path2->link, array('html' => TRUE, 'language' => $language, 'attributes' => array('class' => [$active_class])));
      $output .= '</h4>';
      $output .= '</div>'; // end of heading
      $output .= '</div> ';  // end of default
    }    
  }

  $output .= "</div>"; // end of class panel-group
  $output .= "</div><!-- /.custom-collapse -->";

  // store the localized version of the menu in cache
  // cache_set($cached_menu_name, serialize($output), 'cache');

  return $output;
}

