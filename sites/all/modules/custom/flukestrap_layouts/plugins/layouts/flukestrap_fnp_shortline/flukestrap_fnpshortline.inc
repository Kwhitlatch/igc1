<?php

/**
 * @file
 * Plugin definition.
 */

$plugin = array(
  'title' => t('FNP - Shortline'),
  'icon' => 'flukestrap-fnpshortline.png',
  'category' => t('flukestrap'),
  'theme' => 'flukestrap_fnpshortline',
  'regions' => array(
    'sidebar' => t('Sidebar Nav'),
    'contentleft' => t('Center Column'),
    'contentright' => t('Right Column'),
    'footer' => t('Footer for whatevs'),
  ),
);
