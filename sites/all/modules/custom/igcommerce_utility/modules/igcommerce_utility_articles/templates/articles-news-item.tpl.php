<?php 
  $class = 'fluke-news-article-wrapper';
  if (isset($featured)) {
    $class .= ' featured';
  }
?>

<div class="<?php print $class; ?>">
  <div class="fluke-news-article-image"><?php print $image; ?></div>
  <div class="fluke-news-article-content">
  <div class="fluke-news-article-title"><<?php print $title_tag; ?>><?php print $title; ?></<?php print $title_tag; ?>></div>
  <div class="fluke-news-article-desc"><?php print $desc; ?></div>
  <?php if (isset($featured) && isset($cta)) : ?>
    <div class="fluke-news-article-cta"><?php print $cta; ?></div>
  <?php endif; ?>
  <div class="fluke-news-footer">
    <span class="fluke-news-date"><?php print $date; ?></span> |  
    <span class="fluke-news-topics"><?php print $topics; ?></span>  
  </div>
</div>
</div>