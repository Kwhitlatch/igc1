<?php $i = 1; ?>
<h3><?php print t("Latest News"); ?></h3>
<div id='latest-news'>
  <?php foreach ($items as $item): ?>
    <p id="news-item-<?php print $i; ?>"><?php print l($item->title, $item->url); ?></p>
    <?php $i++; ?>
  <?php endforeach; ?>
</div>
