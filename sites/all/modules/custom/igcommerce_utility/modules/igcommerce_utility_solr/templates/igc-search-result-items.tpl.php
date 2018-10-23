<div class="paginate search-result-items">
  <div class="num-results"><?php print t('Found @number results containing the words: ', array('@number' => $num_results)); ?><strong><?php print strtolower($keyword); ?></strong></div>
  <?php print $sort_form; ?>
  
  <ul class="search-result-list-items">
    <?php foreach ($items as $item) : ?>
    <li class="row" style="display:none;">
      <div class="search-result-item-wrapper"><?php print $item; ?></div>
    </li>  
    <?php endforeach; ?>
  </ul>
  <div class="pagination"></div>
</div>