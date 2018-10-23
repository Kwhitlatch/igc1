<?php global $language; ?>
<?php if(!empty($items) && is_array($items)): ?>
    <div class="row col-md-12">
      <h3><?php print t("Top Sellers"); ?></h3>
    </div>
    <div class="pane-content">
      <div class="toc-listing-image-wrapper">
         <?php foreach($items as $top_seller): ?>
         <div class="toc-listing-item-wrapper">
          <div class="toc-listing-image">
            <?php print l($top_seller['image'] . '<h3>' . $top_seller['title'] . '</h3>', $top_seller['url'], array('html' => TRUE, 'language' => $language)); ?>
          </div>
        </div>
        <?php endforeach; ?>
      </div>
    </div>
<?php endif; ?>
