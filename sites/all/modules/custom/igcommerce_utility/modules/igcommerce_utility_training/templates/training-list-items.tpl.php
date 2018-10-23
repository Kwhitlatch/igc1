<?php if (empty($items)): ?>
<div class"no-results"><?php print t('No results found'); ?></div>
<?php endif; ?>
<div class="paginate training-library-list-items">
  <ul class="">
    <?php foreach ($items as $item) : ?>
    <li class="row" style="display:none;">
      <div class="training-library-list-item"><?php print $item; ?></div>
    </li>  
    <?php endforeach; ?>
  </ul>
  <div class="pagination"></div>
</div>