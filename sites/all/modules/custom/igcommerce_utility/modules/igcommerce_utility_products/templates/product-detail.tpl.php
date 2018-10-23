<?php //dpm($content); ?>
<article id="fluke-product-display" itemscope itemtype="http://schema.org/Product" class="template-F4">
  <?php //print $content['banner']; ?>
  <div class="container">
    <?php print $content['bread']; ?>
    <h1 id="fluke-product-display-title" itemprop="name"><?php print $content['title']; ?></h1>
    <?php print $content['reviews_stars']; ?><!--Bazaarvoice stars-->
    <section id="fluke-product-display-slideshow">
      <?php print $content['slideshow']; ?>
    </section><!-- end #fluke-product-display-slideshow -->
    <section id="fluke-product-alerts">
      <?php print $content['alerts']; ?><!-- fluke-product-display-alerts-->
      <?php print $content['replaced']; ?><!-- fluke-product-display-replaced-by-->
    </section><!--end #fluke-product-alerts -->

    <section id="fluke-product-display-key-features">
      <?php print $content['features']; ?><!--Key features title and content-->
      <?php if (isset($content['manual'])): ?>
        <?php print $content['manual']; ?><!--Link to manuals-->
      <?php endif; ?>
      <?php //print $content['awards']; // Awards removed 9-6-18 MIG4282 ?>
      <?php print $content['safety']; ?><!--safety certifications-->
      <?php print $content['special_offers']; ?><!--special offers-->
      <?php print $content['cta']; ?><!--CTA buttons-->
    </section><!--end #fluke-product-display-key-features -->
  </div><!--end .container -->

  <div id="fluke-product-display-content-tabs">
    <div class="container tab-wrapper">
      <!-- Nav tabs -->
      <ul id="myTab" class="nav nav-tabs nav-justified" role="tablist">
        <?php if (!empty($content['overview'])): ?> 
          <li role="presentation" class="overview-list-item active">
            <a id="overview-label" href="#overview-tab" aria-controls="overview-tab" role="tab" data-toggle="tab"><?php print t("Product overview"); ?></a>
          </li>
        <?php endif; ?>
        <?php if (!empty($content['specs'])): ?> 
          <li role="presentation">
            <a id="specs-label" href="#specs-tab" aria-controls="specs-tab" role="tab" data-toggle="tab"><?php print t("Specifications"); ?></a>
          </li>
        <?php endif; ?>
        <?php if (!empty($content['models'])): ?> 
          <li role="presentation">
            <a id="models-label" href="#models-tab" aria-controls="models-tab" role="tab" data-toggle="tab"><?php print t("Models"); ?></a>
          </li>
        <?php endif; ?>
        <?php if (!empty($content['reviews'])): ?> 
          <li role="presentation">
            <a id="reviews-label" href="#reviews-tab" aria-controls="reviews-tab" role="tab" data-toggle="tab"><?php print t("Reviews"); ?></a>
          </li>
        <?php endif; ?>

        <li role="presentation">
          <a id="resources-label" href="#resources-tab" aria-controls="resources-tab" role="tab" data-toggle="tab"><?php print t("Resources") ?></a>
        </li>

        <?php //Only products will have the accessory tab, Accesories will get a Related Products tab instead ?>
        <?php if (!empty($content['accordion_access']) && isset($product_type) && ($product_type != 1534)): ?>
          <li role="presentation">
            <a id="accessories-label" href="#accordion-access-tab" aria-controls="accordion-access-tab" role="tab" data-toggle="tab"><?php print t("Accessories"); ?></a>
          </li>
        <?php endif; ?>

        <?php if (!empty($content['accessories_related_prod']) && isset($product_type) && ($product_type == 1534)): ?>
        <li role="presentation">
          <a id="related-prod-label" href="#accessories-related-prod-tab" aria-controls="accessories-related-prod-tab" role="tab" data-toggle="tab"><?php print t('Compatible products'); ?></a>
        </li>
      <?php endif; ?>
    </ul>
  </div>
  <div class="gray-wrapper">
    <div class="container">

      <div class="tab-content">

        <!-- TODO: CAN WE ATTACH THE TABS TO THE SECTION WRAPPER AFTER THEMING IS DONE? -->
        <?php if (!empty($content['overview'])): ?>
          <div role="tabpanel" aria-labelledby="overview-label" class="tab-pane fade in active" id="overview-tab" tabindex="0">      
            <?php print $content['overview']; ?>
          </div>
        <?php endif; ?>

        <?php if (!empty($content['specs'])): ?>
          <div role="tabpanel" aria-labelledby="specs-label" class="tab-pane fade" id="specs-tab" tabindex="0">    
            <?php print $content['specs']; ?>
          </div>
        <?php endif; ?>    

        <?php if (!empty($content['models'])): ?>
          <div role="tabpanel" aria-labelledby="models-label" class="tab-pane fade" id="models-tab" tabindex="0">    
            <?php print $content['models']; ?>
          </div>
        <?php endif; ?>

        <?php if (!empty($content['reviews'])): ?>
          <div role="tabpanel" aria-labelledby="reviews-label" class="tab-pane fade" id="reviews-tab" tabindex="0">    
            <?php print $content['reviews']; ?>
          </div>
        <?php endif; ?>

        <div role="tabpanel" aria-labelledby="resources-label" class="tab-pane fade" id="resources-tab" tabindex="0">    
          <?php print $content['resources']; ?>
        </div>

        <?php if (!empty($content['accordion_access']) && isset($product_type) && ($product_type != 1534)): ?>
          <div role="tabpanel" aria-labelledby="accessories-label" class="tab-pane fade" id="accordion-access-tab" tabindex="0">    
            <?php print $content['accordion_access']; ?>
          </div>
        <?php endif; ?>

        <?php if (!empty($content['accessories_related_prod']) && isset($product_type) && ($product_type == 1534)): ?>
          <div role="tabpanel" aria-labelledby="related-prod-label" class="tab-pane fade" id="accessories-related-prod-tab" tabindex="0">
            <?php print $content['accessories_related_prod']; ?>
          </div>
        <?php endif; ?>

      </div><!-- end .tab-content -->

      <!-- Only Products will get this section -->
      <?php if (isset($product_type) && ($product_type != 1534)): ?>
      <?php print $content['top_pick_access']; ?>
      <?php print $content['related_prod']; ?>
      <?php  endif; ?>

      <footer id="fluke-product-display-footer">
        <?php print $content['footer']; ?>
      </footer>

      </div><!--end .container-->
      </div><!--end .gray-wrapper-->
    </div><!-- end #fluke-product-display-content-tabs -->
  </article><!--end #fluke-product-display-->
