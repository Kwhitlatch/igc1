<div class="custom-collapse utility-form-filters">
  <button class="btn btn-block collapse-toggle visible-xs visible-sm" type="button" data-toggle="collapse" data-parent="custom-collapse" data-target="#accordion-left" aria-expanded="false">
    <span class=""><?php print t('Filter by type'); ?></span>
    <span class="pull-right fluke-icon fluke-icon-fa-bars">
  </span>
  </button>
  <div class="panel-group collapse in" id="accordion" aria-expanded="true" role="menu">
  <!--Sidebar nav container START-->
    <div class="panel panel-default">
    <?php print render($form['header']);?>
    <!--Accordian items begin-->
      <!-- Product Begin-->
        <?php if (!empty($form['product_category']['#options'])): ?>
        <div class="panel-heading <?php print $form['product_category']['#wrapper_state'];?>" data-state="<?php print $form['product_category']['#data_state'];?>">
          <h4 class="form-label"><?php print t('Categories'); ?></h4>
          <a data-toggle="collapse" class="collapsed plus-minus pull-right <?php print $form['product_category']['#toggle_state'];?> " data-parent="#accordion" href="#collapse-product">
          </a>
        </div>  
      <div id="collapse-product" class="panel-collapse collapse" role="menuitem" style="<?php print $form['product_category']['#menuitem_state'];?>">
        <div class="panel-body">
          <div class="child-menu-item">        
        <?php print render($form['product_category']);?>
        </div></div></div>
        <?php endif; ?>
      <!-- Product End-->

      <!-- Job Begin-->
        <?php if (!empty($form['job_type']['#options'])): ?>
        <div class="panel-heading <?php print $form['job_type']['#wrapper_state'];?>" data-state="<?php print $form['job_type']['#data_state'];?>">
          <h4 class="form-label"><?php print t('Job Type'); ?></h4>
          <a data-toggle="collapse" class="collapsed plus-minus pull-right <?php print $form['job_type']['#toggle_state'];?>" data-parent="#accordion" href="#collapse-job">
          </a>
        </div>  
      <div id="collapse-job" class="panel-collapse collapse" role="menuitem" style="<?php print $form['job_type']['#menuitem_state'];?>">
        <div class="panel-body">
          <div class="child-menu-item">        
        <?php print render($form['job_type']);?>
        </div></div></div>
        <?php endif; ?>
      <!-- Job End-->

      <!-- Application Begin-->
        <?php if (!empty($form['applications_for_training']['#options'])): ?>
        <div class="panel-heading <?php print $form['applications_for_training']['#wrapper_state'];?>" data-state="<?php print $form['applications_for_training']['#data_state'];?>">
          <h4 class="form-label"><?php print t('Applications'); ?></h4>
          <a data-toggle="collapse" class="collapsed plus-minus pull-right <?php print $form['applications_for_training']['#toggle_state'];?>" data-parent="#accordion" href="#collapse-applications">
          </a>
        </div>  
      <div id="collapse-applications" class="panel-collapse collapse" role="menuitem" style="<?php print $form['applications_for_training']['#menuitem_state'];?>">
        <div class="panel-body">
          <div class="child-menu-item">        
        <?php print render($form['applications_for_training']);?>
        </div></div></div>
        <?php endif; ?>
      <!-- Application End-->

      <!-- Industries Begin-->
        <?php if (!empty($form['industries_for_training']['#options'])): ?>
        <div class="panel-heading <?php print $form['industries_for_training']['#wrapper_state'];?>" data-state="<?php print $form['industries_for_training']['#data_state'];?>">
          <h4 class="form-label"><?php print t('Industries'); ?></h4>
          <a data-toggle="collapse" class="collapsed plus-minus pull-right <?php print $form['industries_for_training']['#toggle_state'];?>" data-parent="#accordion" href="#collapse-industries">
          </a>
        </div>  
      <div id="collapse-industries" class="panel-collapse collapse" role="menuitem" style="<?php print $form['industries_for_training']['#menuitem_state'];?>">
        <div class="panel-body">
          <div class="child-menu-item">        
        <?php print render($form['industries_for_training']);?>
        </div></div></div>
        <?php endif; ?>
      <!-- Industries End-->

      <!-- Measurements Begin-->
        <?php if (!empty($form['measurements_for_training']['#options'])): ?>
        <div class="panel-heading <?php print $form['measurements_for_training']['#wrapper_state'];?>" data-state="<?php print $form['measurements_for_training']['#data_state'];?>">
          <h4 class="form-label"><?php print t('Measurements'); ?></h4>
          <a data-toggle="collapse" class="collapsed plus-minus pull-right <?php print $form['measurements_for_training']['#toggle_state'];?>" data-parent="#accordion" href="#collapse-measurements">
          </a>
        </div>  
      <div id="collapse-measurements" class="panel-collapse collapse" role="menuitem" style="<?php print $form['measurements_for_training']['#menuitem_state'];?>">
        <div class="panel-body">
          <div class="child-menu-item">        
        <?php print render($form['measurements_for_training']);?>
        </div></div></div>
        <?php endif; ?>
      <!-- Measurements End-->

      <!-- Pain Points Begin-->
        <?php if (!empty($form['pain_points_for_training']['#options'])): ?>
        <div class="panel-heading <?php print $form['pain_points_for_training']['#wrapper_state'];?>" data-state="<?php print $form['pain_points_for_training']['#data_state'];?>">
          <h4 class="form-label"><?php print t('Pain Points'); ?></h4>
          <a data-toggle="collapse" class="collapsed plus-minus pull-right <?php print $form['pain_points_for_training']['#toggle_state'];?>" data-parent="#accordion" href="#collapse-pain">
          </a>
        </div>  
      <div id="collapse-pain" class="panel-collapse collapse" role="menuitem" style="<?php print $form['pain_points_for_training']['#menuitem_state'];?>">
        <div class="panel-body">
          <div class="child-menu-item">        
        <?php print render($form['pain_points_for_training']);?>
        </div></div></div>
        <?php endif; ?>
      <!-- Pain Points End-->

      <!-- Solutions Begin-->
        <?php if (!empty($form['solutions_for_training']['#options'])): ?>
        <div class="panel-heading <?php print $form['solutions_for_training']['#wrapper_state'];?>" data-state="<?php print $form['solutions_for_training']['#data_state'];?>">
          <h4 class="form-label"><?php print t('Solutions'); ?></h4>
          <a data-toggle="collapse" class="collapsed plus-minus pull-right <?php print $form['solutions_for_training']['#toggle_state'];?>" data-parent="#accordion" href="#collapse-solutions">
          </a>
        </div>  
      <div id="collapse-solutions" class="panel-collapse collapse" role="menuitem" style="<?php print $form['solutions_for_training']['#menuitem_state'];?>">
        <div class="panel-body">
          <div class="child-menu-item">        
        <?php print render($form['solutions_for_training']);?>
        </div></div></div>
        <?php endif; ?>
      <!-- Solutions End-->

    <!--Accordian items END-->
    </div>
  <!--Sidebar nav container END-->
  </div>
  <?php print render($form['remove_filters']); ?>
  <?php print drupal_render_children($form); ?>
</div>