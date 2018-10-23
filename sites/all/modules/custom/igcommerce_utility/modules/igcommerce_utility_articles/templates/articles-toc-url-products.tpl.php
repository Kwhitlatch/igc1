 <?php if(is_array($items) && count($items) > 0):?>
 <div class='toc-listing-image-wrapper'>
  <?php foreach ($items as $item): ?>
    <?php //dpm($item, '$item'); ?>
      <!-- Output the TOC item -->
      <div class='toc-listing-item-wrapper'>
        <div class='toc-listing-image'>
          <a href='<?php print $item['link']; ?>'><?php print $item['image']; ?></a>
        </div><!-- end of image -->
        <div class='toc-listing-title'>
          <a href='<?php print $item['link']; ?>'>
            <h3 class='toc-listing-title-h3'><?php print $item['title']; ?></h3>
          </a>
        </div><!-- end of title wrapper -->
      </div><!-- end of item wrapper -->
  <?php endforeach; ?>
 </div>
<?php endif; ?>
<div class="clear"><br/></div>
