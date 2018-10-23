<?php
/* 
 * This template puts out articles on the fluke news toc, and all of the 
 * Fluke news subcategories. (Subcategories like "Automotive", "Calibration", etc.)
 * The sub-categories should get the title "Recent stories" and the main toc
 * page should get the title "Top stories"
 */
?>
<div class="paginate fluke-news-top-stories-wrapper">
  <h2><?php print $section_title; ?></h2>  
  <ul class="">
    <?php foreach ($articles as $item) : ?>
    <li class="row" <?php if ($topic) { print 'style="display:none;"'; }?>>
      <div class="fluke-news-top-stories-item"><?php print $item; ?></div>
    </li>  
    <?php endforeach; ?>
  </ul>
  <div class="pagination"></div>
</div>