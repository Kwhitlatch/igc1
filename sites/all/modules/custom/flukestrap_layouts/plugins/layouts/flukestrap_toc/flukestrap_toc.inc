<?php

/**
 * @file
 * Plugin definition.
 */

$plugin = array(
  'title' => t('FS Toc'),
  'icon' => 'flukestrap-toc.png',
  'category' => t('flukestrap'),
  'theme' => 'flukestrap_toc',
  'regions' => array(
    'header' => t('Header'),
    'sidebar' => t('Content Sidebar'),
    'contentmain' => t('Content'),
    'footer' => t('Footer'),    
  ),
);
