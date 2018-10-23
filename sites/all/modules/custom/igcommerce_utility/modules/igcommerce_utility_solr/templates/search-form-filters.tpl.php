<div class="custom-collapse utility-form-filters">
  <button class="btn btn-block collapse-toggle visible-xs visible-sm" type="button" data-toggle="collapse" data-parent="custom-collapse" data-target="#accordion-left" aria-expanded="false">
    <span class=""><?php print t('Filter by type'); ?></span>
    <span class="pull-right fluke-icon fluke-icon-fa-bars">
  </span>
  </button>
  <?php if (!empty($form['remove_filters'])): ?>
  <div class="panel-group collapse in" id="accordion" aria-expanded="true" role="menu">
  <div><h3><?php print t('Filter by type'); ?></h3></div>
  <div class="panel panel-default">
  <?php foreach ($form['filters'] as $key => $filters): ?>
  <?php if (substr($key, 0, 1) == '#') continue; ?>

    <?php if (!empty($form['filters'][$key]['#options'])): ?>
      
      <!--Accordion top level start-->
      <div class="panel-heading">
      <h4>
        <?php print t('@label', array('@label' => $key)); ?>
      </h4>
      <a data-toggle="collapse" class="collapsed plus-minus pull-right " data-parent="#accordion" href="#collapse-<?php print $form['filters'][$key]['#count'];?>">
      </a>
       </div>
      <!--Accordion top level End-->
      <div id="collapse-<?php print $form['filters'][$key]['#count'];?>" class="panel-collapse collapse" role="menuitem">
      <div class="panel-body">
      <div class="child-menu-item">
      <?php print render($form['filters'][$key]);?>
      </div>
      </div>
      </div>
      <?php endif; ?>

  <?php endforeach; ?>
  </div>
  <?php print render($form['remove_filters']); ?>
  </div>
<?php endif; ?>
<?php print drupal_render_children($form); ?>
</div>