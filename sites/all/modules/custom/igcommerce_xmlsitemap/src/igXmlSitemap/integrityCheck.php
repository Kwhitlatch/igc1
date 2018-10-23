<?php
/**
 * Created by PhpStorm.
 * User: trev
 * Date: 08/03/18
 * Time: 11:59 AM
 */

namespace igXmlSitemap;

use GuzzleHttp\Client;
use GuzzleHttp\Psr7\Response;
use GuzzleHttp\Promise\EachPromise;
use Symfony\Component\Config\Definition\Exception\Exception;
use pQuery;


class integrityCheck {
  public $failures = [];

  function check($language) {
    $this->lang = $language->language;

    $links = db_select('igsitemap_links', 'l')
      ->fields('l')
      ->condition('language', $language->language)
      ->execute()->fetchAll();

    $this->links = $links;

    // No need to use try/catch if we set throwing exceptions to FALSE
    $client = new Client(['exceptions' => FALSE, 'allow_redirects' => FALSE]);

    $this->total = count($links);
    $this->completed = 0;

    if (drupal_is_cli()) {
      echo PHP_EOL . "Checking {$language->language}";
    }

    $promises = (function () use ($links, $client) {
      foreach ($links as $link) {
        yield $client->requestAsync('GET', $link->url);
      }
    })();

    $ep = new EachPromise($promises, [
      'concurrency' => 30,
      'fulfilled' => function (Response $response, $id, $promise) use ($links) {
        $this->processResponse($response, $links[$id]);

      },
    ]);

    $ep->promise()->wait();
  }

  function processResponse($result, $link){
    if ($result->getStatusCode() != 200) {
      $link->failure = $result->getStatusCode();
      $this->failures[] = $link;
    } else {
      // check that the url is the canonical link
      if (TRUE) {

        $dom = pQuery::parseStr($result->getBody()->__toString());

        $result = $dom->query('[rel="canonical"]');

        $href = $result->attr('href');

        if ($href !== $link->url) {
          $link->failure = 'Canonical Mismatch';
          $this->failures[] = $link;
        }
      }

      // Check if the url is translated for china, don't do this test for the product section
      // Disabled for now, but we may want to run this check again at some point
      /*if($this->lang === 'cn'  && strpos($link->url, 'product') === FALSE){
        $parts = explode('/', $link->url);

        $count = count($parts);

        if(!empty($parts[$count - 1])) {
          $result = preg_match("/\p{Han}+/u", $parts[$count - 1]);

          if($result === 0){
            $link->failure = 'English in URL Title';
            $this->failures[] = $link;
          }
        }
      }*/
    }

    $this->completed++;
    if (drupal_is_cli()) {
      echo '.';
    }

    if ($this->completed % 20 == 0) {
      if (drupal_is_cli()) {
        echo PHP_EOL . "Tested $this->completed out of $this->total links in {$this->lang}";
      }
    }
  }
}