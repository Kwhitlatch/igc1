<?php if(is_array($items) && count($items) > 0): ?>

  <?php foreach ($items as $item): ?>
    
    <a href="<?php print $item['path']; ?>"  title="<?php print $item['title']; ?>" class='toc_article_card_<?php print strtolower($item['card_size']); ?> card'>
      <div class='toc_article_card_image_<?php print strtolower($item['card_size']); ?>'>
        <?php print $item['image']; ?>
      </div>
      <h2 class='toc_article_card_title'>
        <?php print $item['title']; ?>
      </h2>
    </a>
  
  <?php endforeach; ?>

<?php endif; ?>
