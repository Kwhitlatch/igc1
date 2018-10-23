<?php
/**
 * @file
 * Template for flukestrap Darwin.
 *
 * Based on Radix brenham, the header area is not
 * inside a container so that the banner can span full width.
 * 
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display darwin clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="flukestrap-layouts-header panel-panel">
    <div class="panel-panel-inner">
      <?php print $content['header']; ?>
    </div>
  </div>

  <div>
    <div class="row">

      <div class="col-sm-12 flukestrap-layouts-content panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['contentmain']; ?>
        </div>
      </div>

    </div><!-- /.row -->
  </div><!-- /.container -->

</div><!-- /.darwin -->