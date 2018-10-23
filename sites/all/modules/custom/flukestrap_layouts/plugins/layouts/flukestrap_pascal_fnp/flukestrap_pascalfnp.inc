<?php

/**
 * @file
 * Plugin definition.
 */

$plugin = array(
  'title' => t('FS Pascal - FNP'),
  'icon' => 'flukestrap-pascalfnp.png',
  'category' => t('flukestrap'),
  'theme' => 'flukestrap_pascalfnp',
  'regions' => array(
    'header' => t('Header'),
    'sidebar' => t('Sidebar Nav'),
    'contenttop' => t('Content Top - Featured Stories'),
    'contentleft' => t('Content Left - Top Stories'),
    'contentright' => t('Content Right - Surveys'),
    'footer' => t('Footer - Recent Stories'),
  ),
);
