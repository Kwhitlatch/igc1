      <div class='card'>
      <div class='title'>
        <h1><?php print (isset($item->ss_field_content_title)) ? $item->ss_field_content_title: ''; ?></h1>
      </div>
        <div class='toc_article_body'>
          <?php print (isset($item->tm_article_body)) ? $item->tm_article_body: ''; ?>
        </div>
        <div class='toc_article_body'>
          <?php print (isset($item->ts_article_body)) ? $item->ts_article_body: ''; ?>
        </div>
      </div>
<div class="clear"><br/></div>
