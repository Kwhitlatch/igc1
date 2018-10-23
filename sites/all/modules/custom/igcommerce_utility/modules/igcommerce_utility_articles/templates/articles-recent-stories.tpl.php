<div class="fluke-news-recent-stories-wrapper">
  <h2><?php print t('Recent stories'); ?></h2>  
  <?php foreach ($articles as $item) : ?>
  <div class="fluke-news-recent-stories-item">
    <?php print $item; ?>
  </div>  
  <?php endforeach; ?>
</div>