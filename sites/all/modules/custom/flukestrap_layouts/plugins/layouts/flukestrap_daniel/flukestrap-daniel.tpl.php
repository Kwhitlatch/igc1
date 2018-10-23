<?php
/**
 * @file
 * Template for flukestrap Daniel.
 *
 * This differs from Radix Boxton in that it has a fixed width container, not fluid.
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */

?>

<div class="panel-display daniel clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container">
    <div class="row">
      <div class="col-md-12 flukestrap-layouts-content panel-panel card-header">
        <div class="panel-panel-inner">
          <?php print $content['header']; ?>
        </div>
      </div>
    </div>
  </div>

   <div class="container">
    <div class="row">
      <div class="col-md-12 flukestrap-layouts-content panel-panel card-content">
        <div class="panel-panel-inner">
          <?php print $content['contentmain']; ?>
        </div>
      </div>
    </div>
  </div>
  
   <div class="container">
    <div class="row">
      <div class="col-md-12 flukestrap-layouts-content panel-panel card-footer">
        <div class="panel-panel-inner">
          <?php print $content['footer']; ?>
        </div>
      </div>
    </div>
  </div>  

</div><!-- /.daniel -->
