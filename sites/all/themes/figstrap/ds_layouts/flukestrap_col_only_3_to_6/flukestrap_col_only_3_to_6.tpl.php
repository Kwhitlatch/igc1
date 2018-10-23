<?php
/**
 * @file
 * Bootstrap 3-6 template for Display Suite.
 *
 * Row wrapper was removed, this if for single column styels
 * Switches from 3 column to 6 column on mobile
 */
?>


<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])): ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
 
    <<?php print $left_wrapper; ?> class="col-sm-3 col-xs-6<?php print $left_classes; ?>">
      <?php print $left; ?>
    </<?php print $left_wrapper; ?>>

</<?php print $layout_wrapper ?>>


<!-- Needed to activate display suite support on forms -->
<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
