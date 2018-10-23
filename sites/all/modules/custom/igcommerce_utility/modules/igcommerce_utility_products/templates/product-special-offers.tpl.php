<?php //dpm($content); ?>
<?php if(isset($content) && is_array($content) && sizeof($content) > 0) : ?>

<div id="fluke-product-display-special-offers">

<h2 class="special-offers">
<?php print t("Special offers"); ?>
</h2>

<?php foreach($content as $offer): ?>
  <div class="product-special-offer-link">
     <?php print $offer; ?>
  </div>
<?php endforeach; ?>

</div>

<?php endif; ?>
