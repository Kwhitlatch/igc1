<div <?php print $attributes;?> class="<?php print $classes;?>">
  <?php if($section == 'frontend') :?>
      <?php global $language; ?>
      <a class="logo pull-left" href="/<?php print $language->language; ?>/" title="<?php print t('Home'); ?>">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>

    <button data-target=".nav-collapse" data-toggle="collapse" class="btn btn-navbar tb-megamenu-button" type="button">
     <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
     <span class="fluke-icon fluke-icon-fa-bars"></span>
   </button>
   <div class="nav-collapse <?php print $block_config['always-show-submenu'] ? ' always-show' : '';?>">
   <?php endif;?>
   <?php print $content;?>
   <?php if($section == 'frontend') :?>
   </div>
 <?php endif;?>
</div>
