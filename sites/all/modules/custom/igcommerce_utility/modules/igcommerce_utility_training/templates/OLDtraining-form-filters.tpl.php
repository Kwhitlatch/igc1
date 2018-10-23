<?php print render($form['remove_filters']); ?>
<div class="accordion" data-state="<?php print $form['product_category']['#data_state'];?>">
  <?php if (!empty($form['product_category']['#options'])): ?>
    <h3 class="form-label"><?php print t('Categories'); ?></h3>
    <?php print render($form['product_category']);?>
  <?php endif; ?>
</div> 
<div class="accordion" data-state="<?php print $form['job_type']['#data_state'];?>">
  <?php if (!empty($form['job_type']['#options'])): ?>
    <h3 class="form-label"><?php print t('Job Type'); ?></h3>
    <?php print render($form['job_type']);?>
  <?php endif; ?>
</div>  
<div class="accordion" data-state="<?php print $form['applications_for_training']['#data_state'];?>">
  <?php if (!empty($form['applications_for_training']['#options'])): ?>
    <h3 class="form-label"><?php print t('Applications'); ?></h3>
    <?php print render($form['applications_for_training']);?>
  <?php endif; ?>
</div>  
<div class="accordion" data-state="<?php print $form['industries_for_training']['#data_state'];?>">
<?php if (!empty($form['industries_for_training']['#options'])): ?>
  <h3 class="form-label"><?php print t('Industries'); ?></h3>
  <?php print render($form['industries_for_training']);?>
  <?php endif; ?>
</div>  
<div class="accordion" data-state="<?php print $form['measurements_for_training']['#data_state'];?>">  
  <?php if (!empty($form['measurements_for_training']['#options'])): ?>
  <h3 class="form-label"><?php print t('Measurements'); ?></h3>
  <?php print render($form['measurements_for_training']);?>
  <?php endif; ?>
</div>  
<div class="accordion" data-state="<?php print $form['pain_points_for_training']['#data_state'];?>">  
  <?php if (!empty($form['pain_points_for_training']['#options'])): ?>
  <h3 class="form-label"><?php print t('Pain Points'); ?></h3>
  <?php print render($form['pain_points_for_training']);?>
  <?php endif; ?>
</div>  
<div class="accordion" data-state="<?php print $form['solutions_for_training']['#data_state'];?>">  
  <?php if (!empty($form['solutions_for_training']['#options'])): ?>
  <h3 class="form-label"><?php print t('Solutions'); ?></h3>
  <?php print render($form['solutions_for_training']);?>
  <?php endif; ?>
</div>
<?php print drupal_render_children($form); ?>