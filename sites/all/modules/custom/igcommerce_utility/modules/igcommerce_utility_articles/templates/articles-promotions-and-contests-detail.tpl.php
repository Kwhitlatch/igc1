<?php
/* Somehow this template eneded up at the bottom of the products page.
 * The products page is built using 
 * /en-us/admin/structure/pages/nojs/operation/page-product_page/
 * The link to edit content and remove this block is broken.
 * To prevent it showing on the product page, I wrapped this template output
 * in a conditional.  RRN 4-5-18 for MIG-2243
 */
?>
<?php if(isset($items)): ?>
  <?php foreach ($items as $item) : ?>
    <div class="press-release-item-title">
      <h1><?php print($item->ss_field_content_title); ?></h1>
    </div>
    <div class="press-release-item-body">
      <?php print($item->ss_body); ?>
    </div>
  <?php endforeach; ?>
<?php endif; ?>

