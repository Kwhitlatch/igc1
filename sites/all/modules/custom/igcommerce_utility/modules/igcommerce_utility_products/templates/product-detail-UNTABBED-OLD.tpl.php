<?php //dpm($content); ?>
<?php //if(!empty($content['slideshow'])): ?>
    <article id='fluke-product-display' itemscope itemtype='http://schema.org/Product' class='template-F4'>
       <?php //print $content['banner']; ?>
       <div class='container'>
          <?php print $content['bread']; ?>
          <h1 id='fluke-product-display-title' itemprop='name'><?php print $content['title']; ?></h1>
          <section id='fluke-product-display-slideshow'>
             <?php print $content['slideshow']; ?>
          </section><!-- end of slideshow-->
          <section id='fluke-product-alerts'>
             <?php print $content['alerts']; ?><!-- fluke-product-display-alerts-->
             <?php print $content['replaced']; ?><!-- fluke-product-display-replaced-by-->
          </section><!--end of fluke-product-alerts-->

          <section id='fluke-product-display-key-features'>
             <?php print $content['features']; ?><!--Key features title and content-->
             <?php if (isset($content['manual'])): ?>
               <?php print $content['manual']; ?><!--Link to manuals-->
             <?php endif; ?>
             <?php print $content['awards']; ?><!--icon indicating awards won-->
             <?php print $content['safety']; ?><!--safety certifications-->
             <?php print $content['reviews_stars']; ?><!--Bazaarvoice stars-->
             <?php print $content['special_offers']; ?><!--special offers-->
             <?php print $content['cta']; ?><!--CTA buttons-->
          </section><!--end of key-features-->
       </div><!--end of container-->
       <div class='gray-wrapper'>
          <div class='container'>
             <section id='fluke-product-display-overview-section'>
                <div id='fluke-product-display-overview'>
                  <?php print $content['overview']; ?>
                </div><!--end of overview-->
             </section><!--end of overview-section-->
             <?php print $content['models']; ?>
             <?php print $content['specs']; ?>
             <?php print $content['resources']; ?>
            <!-- Only print accessories_related_prod for Accessory products. -->
             <?php if (isset($product_type) && ($product_type == 1534)): ?>
               <?php print $content['accessories_related_prod']; ?>
             <?php  else: ?>
               <?php print $content['access']; ?>
               <?php print $content['related_prod']; ?>
             <?php  endif; ?>
             <?php print $content['reviews']; ?><!--Bazaarvoice reviews-->
             <footer id='fluke-product-display-footer'>
                <?php print $content['footer']; ?>
             </footer><!--end of accessories-->
          </div><!--end of container-->
       </div><!--end of gray-wrapper-->
    </article><!--end of fluke product display div-->
<?php // endif; ?>