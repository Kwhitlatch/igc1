<?php

namespace igXmlSitemap;

use Thepixeldeveloper\Sitemap\Drivers\XmlWriterDriver;
use Thepixeldeveloper\Sitemap\Urlset;
use Thepixeldeveloper\Sitemap\Url;
use Thepixeldeveloper\Sitemap\Extensions\Image;

class igXmlSitemapMainHtml extends igXmlSitemapMain {

  function build() {

    $this->doUrlBuilder();

    $this->checkAssignments();

    $this->doToc();

    $this->doPages();

    $this->checkArticlePdAssignments();
    //$this->doTrainingVids();  //@todo: training videos use flash, so we aren't indexing them at this time

    //Manually add homepage link
    $this->doHomepage();

  }

  protected function doHomepage() {
    $hp = new igLink($this->lang, $this->lang, 'homepage', 'homepage', '0', '');

    $hp->changeFreq = 'daily';

    $hp->title = 'Fluke';

    $this->urlSet[$this->lang] = $hp;

  }

  function write() {
    ksort($this->urlSet);

    $map = [];

    foreach ($this->urlSet as $url => $link) {

      $id_parts = explode('|', $link->identifier);

      if($link->identifier === 'taxonomy_term|url_builder|2274'){
        // Don't display the sitemap link on the sitemap page
        continue;
      }

      if (!empty($this->excluded[$id_parts[0]])) {
        $etype = $this->excluded[$id_parts[0]];

        if (in_array($id_parts[2], $etype)) {
          continue;
        }
      }
      // @todo: begin building the map

      $this->buildMap($link, $map);
    }

    $data = $this->generateHtml($map); // transform the array to html


    $this->_save_data($data);

  }

  protected function buildMap($link, &$map) {
    $link_parts = explode('/', $link->link);

    if (!empty($link_parts[4])) {
      $map[$link_parts[0]]['children'][$link_parts[1]]['children'][$link_parts[2]]['children'][$link_parts[3]]['children'][$link_parts[4]]['parent'] = $link;
    } elseif (!empty($link_parts[3])) {
      $map[$link_parts[0]]['children'][$link_parts[1]]['children'][$link_parts[2]]['children'][$link_parts[3]]['parent'] = $link;
    } elseif (!empty($link_parts[2])) {
      $map[$link_parts[0]]['children'][$link_parts[1]]['children'][$link_parts[2]]['parent'] = $link;
    } elseif (!empty($link_parts[1])) {
      $map[$link_parts[0]]['children'][$link_parts[1]]['parent'] = $link;
    } else {
      $map[$link_parts[0]]['parent'] = $link;
    }
  }

  protected function generateHtml($map){
    $html = '';
    $html .= '<ul>';

    foreach($map as $item){
      $parent = $item['parent'];

      $html .= "<li><a href='/$parent->link'> {$parent->title}</a>";//<!--{$parent->identifier}-->";wd
      if(!empty($item['children'])) {
        $html .= $this->generateHtml($item['children']);
      }
      $html .= '</li>';
    }
    $html .= '</ul>';

    return $html;
  }

  protected function _save_data($data, $dest = NULL) {

    $head = <<<EOD
<html lang="{$this->lang}">
<head>
  <meta charset="utf-8">

  <title>HTML Sitemap for {$this->lang}</title>

</head>
<body>
EOD;

    $foot = "</body></html>";


    $dir = 'public://html-sitemap';
    file_prepare_directory($dir, FILE_CREATE_DIRECTORY);

    $dest = $dir . '/html-sitemap-' . $this->lang . '.htm';

    file_save_data($head.$data.$foot, $dest, FILE_EXISTS_REPLACE);
  }
}
