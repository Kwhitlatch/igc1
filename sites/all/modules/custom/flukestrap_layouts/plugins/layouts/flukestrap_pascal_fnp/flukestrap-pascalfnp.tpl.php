<?php
/**
 * @file
 * Modifed Template for flukestrap pascal, pascal fnp.
 *
 * This template differs from pascal, adding a right side bar and footer
 * to match Fluke New Plus requirements. If there is no content in the right
 * sidebar, the left content area should be full width.
 * 
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display pascalfnp clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="flukestrap-layouts-header panel-panel">
    <div class="panel-panel-inner">
      <?php print $content['header']; ?>
    </div>
  </div>

  <div class="container">
    <div class="row">
      
      <div class="col-md-3 flukestrap-layouts-sidebar panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['sidebar']; ?>
        </div>
      </div>

      <div class="col-md-9 flukestrap-layouts-content panel-panel">
        
          <div class="panel-panel-inner fnp-top">
            <?php print $content['contenttop']; ?>
          </div>

          <div class="panel-panel-inner fnp-left">
            <?php print $content['contentleft']; ?>
          </div>

          <div class="panel-panel-inner fnp-right">
            <?php print $content['contentright']; ?>
          </div>

          <div class="panel-panel-inner fnp-bottom">
            <?php print $content['footer']; ?>
          </div>
      </div>
    </div><!-- /.row -->
  </div><!-- /.container -->

</div><!-- /.pascal -->