 <?php if(is_array($items) && count($items) > 0):?>
 <div class="toc-listing-image-wrapper">
   <h3 class="recommended-products-title"><?php print t("Recommended products"); ?></h3>
  <div class="recommended-products-wrapper">
      <?php foreach ($items as $item): ?>
      <?php if(isset($item['path_url'])): ?> 

        <div class="toc-listing-item-wrapper">
          <div class="toc-listing-image">
            <a href="<?php print $item['path_url']; ?>"><?php print $item['image']; ?></a>
          </div>
          <div class="toc-listing-title">
            <a href="<?php print $item['path_url']; ?>">
              <h3 class="toc-listing-title-h3"><?php print $item['title']; ?></h3>
            </a>
          </div>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
 </div>
<?php endif; ?>
<div class="clear"><br/></div>
