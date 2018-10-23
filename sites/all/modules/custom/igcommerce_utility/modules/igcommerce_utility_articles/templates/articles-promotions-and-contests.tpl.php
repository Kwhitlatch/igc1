<?php
//$items : Array of contents

?>
<?php if(is_array($items) && count($items) > 0): ?>
<div class="panel-display">
    <div class="pane-igcommerce-utility-articles-promotions">
        <div class="pane-content">
            <?php foreach ($items as $item): ?>
            <div class="toc-listing-item-wrapper">
                <a href="<?php print $item['path']; ?>" target="<?php print $item['target']; ?>"><?php print $item['image']; ?></a>
                <h4><a href="<?php print $item['path']; ?>" target="<?php print $item['target']; ?>"><?php print $item['title']; ?></a></h4>
            </div>
            <?php endforeach; ?>
        </div>
    </div>
</div>
<?php endif; ?>