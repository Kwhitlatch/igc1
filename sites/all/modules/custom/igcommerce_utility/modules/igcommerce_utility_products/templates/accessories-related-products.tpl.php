<?php 
  /*
   * This will only be used when displaying an accessory. A list of compatible
   * products will be displayed instead of a list of related accessories. This
   * uses the readmore module to show/hide content. Readmore is instantiated 
   * through /sites/all/modules/custom/igcommerce_utility/modules/igcommerce_utility_products/js/igcommerce_utility_products.js
   *
   */
?>
<section id="fluke-product-display-compatible-products-section">
  <h2>
    <?php print t('Compatible products') . ': ' . $translated_title; ?>
  </h2>
  <div id="fluke-product-display-compatible-products">
  <div id="compatible-products-list">
    <!-- <div class="custom-collapse"> -->
      <div aria-multiselectable="true" class="panel-group" id="accessories-compatible-products-accordion" role="tablist">

      <?php
      // We need the ID's in the accordion to be unique, so we are using a counter.
      $counter = 0;
      foreach ($content as $key => $value) {
        print '<div class="panel panel-default">
                <div class="panel-heading" id="heading-related-prod-' . $counter .'" role="tab">
                  <h4 class="panel-title">';
                  print '<a aria-controls="collapse-related-prod-' . $counter .'" aria-expanded="false" class="collapsed" data-parent="#accessories-compatible-products-accordion" href="#collapse-related-prod-' . $counter .'" role="button">';
                  print $key;
                    // If there's more than one product in each accorion toggle, put out the count.
                    if (count($value) > 1) {
                      print ' (' . count($value) . ')';
                    }
                  print '</a></h4>
                  </div>
                  <div aria-labelledby="heading-related-prod-' . $counter .'" class="panel-collapse collapse" id="collapse-related-prod-' . $counter .'" role="tabpanel" aria-expanded="false">
                    <div class="panel-body"><ul>';
                      sort($value); // Lets' alphebatize the array before putting out the products.
                      foreach ($value as $output_link) {
                        print '<li>' . $output_link . '</li>';
                       } 
                   print '</ul>
                   </div>
                 </div>
               </div><!-- /.panel -->'; 
               $counter++;
             } ?>
        </div><!-- /.panel-group -->
      <!-- </div> --><!-- /.custom-collapse -->
    </div>
  </div>
</section>
