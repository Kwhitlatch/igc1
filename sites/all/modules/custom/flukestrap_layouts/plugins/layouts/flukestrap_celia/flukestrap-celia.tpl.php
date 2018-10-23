<?php
/**
 * @file
 * Template for flukestrap celia.
 *
 * Used for the Amprobe-Beha Home page
 * 
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display celia clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="celia-slideshow">
    <?php print $content['slideshow']; ?>
  </div>
  
  <div class="celia-secondary-nav">
    <div class="container">
      <div class="row">
        <?php print $content['secondary-nav']; ?>
      </div><!-- /.container -->
    </div><!-- /.row -->
  </div>

  <div class="homepage-articles">
    <div class="container">
      <div class="row">
        <?php print $content['homepage-articles']; ?>
      </div><!-- /.row -->
    </div><!-- /.container -->
  </div>

</div><!-- /.celia -->