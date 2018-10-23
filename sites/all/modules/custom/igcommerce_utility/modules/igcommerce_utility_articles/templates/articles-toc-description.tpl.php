<div class="toc-description">
  <?php print $content; ?>
  <?php if(isset($cta)): ?>
  <div class="toc-cta">
    <a class="button" href="<?php print $cta->url; ?>" target="_blank"><?php print $cta->label; ?></a>
  </div>
  <?php endif; ?>
</div>
