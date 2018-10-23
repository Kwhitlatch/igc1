<div class="custom-collapse utility-form-filters">
  <button class="btn btn-block collapse-toggle visible-xs visible-sm" type="button" data-toggle="collapse" data-parent="custom-collapse" data-target="#accordion-left" aria-expanded="false">
    <span class=""><?php print t('Filter by type'); ?></span>
    <span class="pull-right fluke-icon fluke-icon-fa-bars">
  </span>
  </button>
  <?php if (!empty($form['manual_type']['#options'])): ?>
  <div class="panel-group collapse in" id="accordion" aria-expanded="true" role="menu">
  <div><h3><?php print t('Filter by type'); ?></h3></div>
    <?php print render($form['manual_type']);?>
</div> 
<?php endif; ?>
<?php print drupal_render_children($form); ?>
</div>