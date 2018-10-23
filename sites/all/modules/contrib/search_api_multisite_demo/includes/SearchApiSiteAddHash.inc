<?php
/**
 * @file
 * This was largely copied from the sandbox module search_api_site.
 */

/**
 * Search API data alteration callback that adds an URL field for all items.
 */
class SearchApiSiteAddHash extends SearchApiAbstractAlterCallback {

  public function alterItems(array &$items) {
    $new_items = array();
    foreach ($items as $id => &$item) {
      $item->search_api_multisite_demo_hash = search_api_multisite_demo_hash();
      $item->search_api_id = search_api_multisite_demo_hash() . $id;
      $new_items[search_api_multisite_demo_hash() . $id] = $item;
    }
    #$items = $new_items;
  }

  public function propertyInfo() {
    return array(
      'search_api_multisite_demo_hash' => array(
        'label' => t('Site Hash'),
        'description' => t('The hash of the site which can then be used to limit results.'),
        'type' => 'string',
      ),
      'search_api_multisite_demo_id' => array(
        'label' => t('Site item id'),
        'description' => t('A unique id for the item.'),
        'type' => 'string',
      ),
    );
  }

}
