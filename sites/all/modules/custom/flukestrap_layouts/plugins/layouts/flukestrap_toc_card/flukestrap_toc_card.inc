<?php

/**
 * @file
 * Plugin definition.
 */

$plugin = array(
  'title' => t('FS Toc Card'),
  'icon' => 'flukestrap-toc-card.png',
  'category' => t('flukestrap'),
  'theme' => 'flukestrap_toc_card',
  'regions' => array(
    'header' => t('Header'),
    'sidebar' => t('Content Sidebar'),
    'contentmain' => t('Content'),
    'footer' => t('Footer'),    
  ),
);
