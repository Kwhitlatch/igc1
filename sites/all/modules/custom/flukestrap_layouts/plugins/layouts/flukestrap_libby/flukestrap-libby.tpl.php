<?php
/**
 * @file
 * Template for flukestrap libby.
 *
 * Built for the Beha-Amprobe Product Pages - drasticly revised for fluke ig
 * 
 * The flexbox wrapper is required, (.flexbox) because .libby-overview and 
 * .libby-overview-links switch places vertically on mobile devices,
 * and the alert boxes go above the carousel.  
 * Bootstrap framework does not natively support vertical
 * reordering, so we had to use flex. Styling found in P3-products.less
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 * title
 * header
 * slideshow
 * alert-panel
 * overview
 * overview-links
 * accessories
 * resources
 * related
 */
?>

<div class="panel-display libby clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="flukestrap-layouts-header">
    <?php print $content['header']; ?>
  </div>

  <div class="container">
    <div class="libby-title">
      <?php print $content['title']; ?>
    </div>

    <div class="libby-slideshow">
      <?php print $content['slideshow']; ?>
    </div>

    <div class="libby-alert-panel">
      <?php print $content['alert-panel']; ?>
    </div>

    <div class="libby-key-features">
      <?php print $content['key-features']; ?>
    </div>

  </div><!-- /.container -->
    <div class="libby-request-pricing">
      <?php print $content['libby-request-pricing']; ?>
    </div>
  
  <div class="gray-wrapper">
    <div class="container">

      <div class="libby-overview">
        <?php print $content['overview']; ?>
      </div>
      <div class="libby-prod-models">
        <?php print $content['prod-models']; ?>
      </div>

      <div class="libby-accessories">
        <?php print $content['prod-accessories']; ?>
      </div>
      
      <div class="libby-resources">
        <?php print $content['resources']; ?>
      </div>

      <div class="libby-related">
        <?php print $content['related']; ?>
      </div>

    </div><!-- /.container -->
  </div><!-- .gray-wrapper -->

</div><!-- /.libby -->