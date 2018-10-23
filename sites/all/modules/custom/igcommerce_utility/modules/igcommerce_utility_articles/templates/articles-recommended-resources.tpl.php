<?php if(is_array($items) && count($items) > 0):?>
  <h3><?php print t('Recommended Resources'); ?></h3>
    <!--<? // dpm($items, '$items'); ?>-->
  <?php foreach ($items as $item): ?>
    <div class='toc-article-related-resource-wrapper'>
        <div class='card'>
          <?php if(isset($item['title'])): ?>
            <h5 class='toc-article-related-resource-title'>
              <a href= "<?php print $item['link']; ?>" title="<?php print $item['alt']; ?>"><?php print $item['title']; ?></a>
            </h5>
          <?php endif; ?>
          <?php if (isset($item['datasheet_url'])): ?>
            <!-- creates a pop up of the product details using model. -->
            <h5><div class='toc-article-related-product-download'><a href="<?php print $item['datasheet_url']; ?>" target="_blank"  download><?php print $item['datasheet_alt']; ?></a></div></h5>
          <?php endif; ?>
          <?php if (isset($item['webcard_url'])): ?>
            <!-- Web card -->
            <h5><a href = "<?php print $item['webcard_url']; ?>"><?php print $item['webcard_alt']; ?></a></h5>
          <?php endif; ?>
        </div>
    </div>
  <?php endforeach; ?>
<?php endif; ?>
<div class="clear"><br/></div>