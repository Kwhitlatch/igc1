<?php
/**
 * @file
 * Template for flukestrap Ryan.
 *
 * This differs from Radix Boxton in that it has a no full width container, so 
 * that there will be no margins or padding.
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display ryan clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="ryan-content">
    <?php print $content['contentmain']; ?>
  </div>
</div><!-- /.ryan -->
