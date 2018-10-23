<?php
/**
 * @file
 * Template for flukestrap robert.
 *
 * This differs from Radix Sutro in that the header area is not
 * inside a container, so the banner can span full width.
 * 
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display robert clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="flukestrap-layouts-header panel-panel">
    <?php print $content['header']; ?>
  </div>

  <div class="container">
    <div class="row">

      <div class="col-md-6 robert-left">
        <?php print $content['left']; ?>
      </div>

      <div class="col-md-6 robert-right">
        <?php print $content['right']; ?>
      </div>

    </div><!-- /.row -->
  </div><!-- /.container -->

  <div class="col-xs-12 robert-foot-panel">
    <?php print $content['foot-panel']; ?>
  </div>
  
</div><!-- /.robert -->