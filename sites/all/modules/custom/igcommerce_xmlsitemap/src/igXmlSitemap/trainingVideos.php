<?php
/**
 * Created by PhpStorm.
 * User: trev
 * Date: 1/2/18
 * Time: 10:30 AM
 */

namespace igXmlSitemap;


class trainingVideos extends igXmlSitemapItemBase {

  function __construct($lang, $urlSet, $trainingLibUrl) {
    parent::__construct($lang, 'video', 'node');

    $this->urlSet = $urlSet;

    foreach ($this->docs as $doc) {
      if(!empty($doc->bs_noindex)){
        continue;
      }

      if(empty($doc->im_training_filter)){
        continue;
      }

      if (!empty($doc->ss_field_content_url)) {
        $video_url = $doc->ss_field_content_url . '&';
      } elseif (!empty($doc->ss_field_youtube_video)) {
        if (strpos($doc->ss_field_youtube_video, 'youtube.com/watch') !== FALSE) {
          $doc->ss_field_youtube_video = str_replace('youtube.com/watch', 'youtube.com/embed', $doc->ss_field_youtube_video);
        }
        $video_url = $doc->ss_field_youtube_video . '&';
      } elseif (!empty($doc->ss_field_demo_url)) {
        $video_url = $doc->ss_field_demo_url . '?';
      } else {
        // No video so skip this
        continue;
      }

      if(isset($video_url)) {
        $video_url .= 'iframe=true';

        if(strpos($video_url, '//') === 0){
          $video_url = 'https:'.$video_url;
        }

        // Add videos to the link for the webinars page
        $video = [
          'thumbnail' => $doc->ss_field_image,
          'url' => $video_url,
          'caption' => $doc->ss_field_content_title,//title
          'alt' => $doc->ss_field_content_title,//description
          'video' => TRUE,
        ];

        // need to translate path in order to add these to the sitemap in the right place
        // We figure this out in URL Builder and pass it into this class

        $this->urlSet[$trainingLibUrl]->images[] = $video;
      }

    }
  }

  function alterFilters(&$filters){
    $filters += array(
      'entity_type' => 'node',
      'im_training_filter' => '[* TO *]',
      '-is_field_restricted_to_internal_use' => 1,
      '-is_field_restricted_to_author_of_as' => 1,
      '-is_field_pp_confidential' => 1,
      '-is_field_pp_do_not_show_item_on_t' => 1,
    );


  }
}