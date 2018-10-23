<?php
/**
 * @file
 * mmenu_configuration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function mmenu_configuration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mmenu_item_mmenu_left';
  $strongarm->value = array(
    'enabled' => '0',
    'title' => 'Left menu',
    'name' => 'mmenu_left',
    'blocks' => array(
      0 => array(
        'module_delta' => 'igcommerce_utility|ig_primary_mobile_nav',
        'menu_parameters' => array(
          'min_depth' => '1',
        ),
        'title' => '',
        'collapsed' => '1',
        'wrap' => '0',
        'module' => 'igcommerce_utility',
        'delta' => 'ig_primary_mobile_nav',
      ),
    ),
    'options' => array(
      'classes' => 'mm-basic',
      'effects' => array(
        'mm-fullscreen' => 'mm-fullscreen',
        'mm-slide' => 'mm-slide',
      ),
      'slidingSubmenus' => TRUE,
      'clickOpen' => array(
        'open' => TRUE,
        'selector' => '.navbar-toggle',
      ),
      'counters' => array(
        'add' => TRUE,
        'update' => TRUE,
      ),
      'dragOpen' => array(
        'open' => TRUE,
        'pageNode' => 'body',
        'threshold' => 100.0,
        'maxStartPos' => 50.0,
      ),
      'footer' => array(
        'add' => TRUE,
        'content' => '',
        'title' => '<a href="#mmenu_left"><button type="button" class="mmenu-close navbar-toggle" href="#mmenu_left"></button></a>',
        'update' => FALSE,
      ),
      'header' => array(
        'add' => TRUE,
        'content' => '',
        'title' => '',
        'update' => TRUE,
      ),
      'labels' => array(
        'collapse' => FALSE,
      ),
      'offCanvas' => array(
        'enabled' => TRUE,
        'modal' => FALSE,
        'moveBackground' => TRUE,
        'position' => 'left',
        'zposition' => 'front',
      ),
      'searchfield' => array(
        'add' => FALSE,
        'addTo' => '',
        'search' => FALSE,
        'placeholder' => '',
        'noResults' => 'No results found.',
        'showLinksOnly' => FALSE,
      ),
    ),
    'configurations' => array(
      'clone' => FALSE,
      'preventTabbing' => FALSE,
      'panelNodetype' => 'div, ul, ol',
      'transitionDuration' => 400.0,
      'classNames' => array(
        'label' => 'Label',
        'panel' => 'Panel',
        'selected' => 'active-trail',
        'buttonbars' => array(
          'buttonbar' => 'anchors',
        ),
        'counters' => array(
          'counter' => 'Counter',
        ),
        'fixedElements' => array(
          'fixedTop' => 'FixedTop',
          'fixedBottom' => 'FixedBottom',
        ),
        'footer' => array(
          'panelFooter' => 'Footer',
        ),
        'header' => array(
          'panelHeader' => 'Header',
          'panelNext' => 'Next',
          'panelPrev' => 'Prev',
        ),
        'labels' => array(
          'collapsed' => 'Collapsed',
        ),
        'toggles' => array(
          'toggle' => 'Toggle',
          'check' => 'Check',
        ),
      ),
      'dragOpen' => array(
        'width' => array(
          'perc' => 0.80000000000000004,
          'min' => 140.0,
          'max' => 440.0,
        ),
        'height' => array(
          'perc' => 0.80000000000000004,
          'min' => 140.0,
          'max' => 880.0,
        ),
      ),
      'offCanvas' => array(
        'menuInjectMethod' => 'prepend',
        'menuWrapperSelector' => 'body',
        'pageNodetype' => 'div',
        'pageSelector' => 'body > div',
      ),
    ),
  );
  $export['mmenu_item_mmenu_left'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mmenu_item_mmenu_right';
  $strongarm->value = array(
    'enabled' => '1',
    'title' => 'Right menu',
    'name' => 'mmenu_right',
    'blocks' => array(
      0 => array(
        'module_delta' => 'igcommerce_utility|ig_primary_mobile_nav',
        'menu_parameters' => array(
          'min_depth' => '1',
        ),
        'title' => '',
        'collapsed' => '1',
        'wrap' => '0',
        'module' => 'igcommerce_utility',
        'delta' => 'ig_primary_mobile_nav',
      ),
    ),
    'options' => array(
      'classes' => 'mm-basic',
      'effects' => array(
        'mm-fullscreen' => 'mm-fullscreen',
      ),
      'slidingSubmenus' => TRUE,
      'clickOpen' => array(
        'open' => TRUE,
        'selector' => '.navbar-toggle',
      ),
      'counters' => array(
        'add' => TRUE,
        'update' => TRUE,
      ),
      'dragOpen' => array(
        'open' => TRUE,
        'pageNode' => 'body',
        'threshold' => 100.0,
        'maxStartPos' => 50.0,
      ),
      'footer' => array(
        'add' => FALSE,
        'content' => '',
        'title' => '<button type="button" class="mmenu-close navbar-toggle" href="#mmenu_right"></button>',
        'update' => FALSE,
      ),
      'header' => array(
        'add' => TRUE,
        'content' => '',
        'title' => '',
        'update' => TRUE,
      ),
      'labels' => array(
        'collapse' => FALSE,
      ),
      'offCanvas' => array(
        'enabled' => TRUE,
        'modal' => FALSE,
        'moveBackground' => TRUE,
        'position' => 'right',
        'zposition' => 'front',
      ),
      'searchfield' => array(
        'add' => FALSE,
        'addTo' => '',
        'search' => FALSE,
        'placeholder' => '',
        'noResults' => 'No results found.',
        'showLinksOnly' => FALSE,
      ),
    ),
    'configurations' => array(
      'clone' => FALSE,
      'preventTabbing' => FALSE,
      'panelNodetype' => 'div, ul, ol',
      'transitionDuration' => 400.0,
      'classNames' => array(
        'label' => 'Label',
        'panel' => 'Panel',
        'selected' => 'active-trail',
        'buttonbars' => array(
          'buttonbar' => 'anchors',
        ),
        'counters' => array(
          'counter' => 'Counter',
        ),
        'fixedElements' => array(
          'fixedTop' => 'FixedTop',
          'fixedBottom' => 'FixedBottom',
        ),
        'footer' => array(
          'panelFooter' => 'Footer',
        ),
        'header' => array(
          'panelHeader' => 'Header',
          'panelNext' => 'Next',
          'panelPrev' => 'Prev',
        ),
        'labels' => array(
          'collapsed' => 'Collapsed',
        ),
        'toggles' => array(
          'toggle' => 'Toggle',
          'check' => 'Check',
        ),
      ),
      'dragOpen' => array(
        'width' => array(
          'perc' => 0.80000000000000004,
          'min' => 140.0,
          'max' => 440.0,
        ),
        'height' => array(
          'perc' => 0.80000000000000004,
          'min' => 140.0,
          'max' => 880.0,
        ),
      ),
      'offCanvas' => array(
        'menuInjectMethod' => 'prepend',
        'menuWrapperSelector' => 'body',
        'pageNodetype' => 'div',
        'pageSelector' => 'body > div',
      ),
    ),
  );
  $export['mmenu_item_mmenu_right'] = $strongarm;

  return $export;
}
