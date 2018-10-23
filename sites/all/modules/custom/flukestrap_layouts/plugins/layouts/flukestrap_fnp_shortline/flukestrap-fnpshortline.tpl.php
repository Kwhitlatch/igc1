<?php
/**
 * @file
 * Modifed Template for flukestrap pascal, fnp shortline
 *
 * This template is a pretty standard 3/9 split. THe main content should only
 * be 6 columns wide on desktop, so that the line lenght becomes more readable.
 * This should only be applied to Fluke news plus articles.

 * 
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display fnpshortline clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container">
    <div class="row">
      
      <div class="col-md-3 flukestrap-layouts-sidebar panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['sidebar']; ?>
        </div>
      </div>

      <div class="col-md-9 flukestrap-layouts-content panel-panel">

          <div class="panel-panel-inner fnpshortline-center">
            <article itemscope itemtype="http://schema.org/Article" itemref="navbar">
              <meta itemprop="author" content="Fluke" />
              <?php print $content['contentleft']; ?>
            </article>
          </div>

          <div class="panel-panel-inner fnpshortline-right">
            <?php print $content['contentright']; ?>
          </div>

          <div class="panel-panel-inner fnpshortline-footer">
            <?php print $content['footer']; ?>
          </div>
      </div>
    </div><!-- /.row -->
  </div><!-- /.container -->

</div><!-- /.fnpshortline -->