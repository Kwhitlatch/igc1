<?php
/**
 * @file
 * fluke_articles.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fluke_articles_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_ig_article_date';
  $strongarm->value = 'F Y';
  $export['date_format_ig_article_date'] = $strongarm;

  return $export;
}
