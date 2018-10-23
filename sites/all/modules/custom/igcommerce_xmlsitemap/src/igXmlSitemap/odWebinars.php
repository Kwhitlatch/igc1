<?php
/**
 * Created by PhpStorm.
 * User: trev
 * Date: 1/2/18
 * Time: 10:30 AM
 */

namespace igXmlSitemap;


class odWebinars extends igXmlSitemapItemBase {

  function __construct($lang, $urlSet, $webinarsUrl) {
    parent::__construct($lang, 'event', 'node');

    $this->urlSet = $urlSet;

    // @todo: od webinars are external links at this time.  Should be no need to index them.
    /*
    foreach ($this->docs as $doc) {
      $cta = json_decode($doc->sm_cta_left_coll[0]);
      // Add videos to the link for the webinars page
      $video = [
        'thumbnail' => '', //@todo: thumbnail is required
        'url' => $cta->url,
        'caption' => $doc->ss_field_content_title ,//title
        'alt' => $doc->ss_field_content_title//description
      ];

      // need to translate path in order to add these to the sitemap in the right place
      // We figure this out in URL Builder and pass it into this class
      $this->urlSet[$webinarsUrl]->images[] = $video;
    }*/
  }

  function alterFilters(&$filters){

    $event_types = igcommerce_event_types_taxonomy(TRUE, $this->lang);

    $filters['sm_event_type_name'] = $event_types['On-demand webinars'];

  }
}