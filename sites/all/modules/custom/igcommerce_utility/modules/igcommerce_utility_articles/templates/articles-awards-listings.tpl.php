<?php
/**
param $filter : Used to filter results with $_GET request;
param $language : Current language local;
param $total : Total number of items found;
param $items : An object of items to be displayed;
*/
?>
<?php if(empty($filter) && $filter !== FALSE): ?>
<div class="awards-search-results articles-search-results">
<?php endif; ?>
<?php if(count($items) > 0): ?>
    <?php foreach ($items as $article_group): ?>
        <!-- ACCORDION ITEM -->
        <div class="awards-items articles-search-result-item">
            <h3 class="awards-items-date"><?php print t($article_group['month']); ?></h3>
            <div class="awards-items-content">
            <?php foreach ($article_group['data'] as $article): ?>
                <?php if (isset($article->ss_field_content_title) && !empty($article->ss_field_content_title)): ?>
                    <div class="awards-item <?php print($article->entity_id); ?>">
                        <div class="awards-image">
                            <?php print $article->img_link; ?>
                        </div>
                        <div class="awards-detail">
                            <h2> <?php print $article->link; ?></h2>
                            <p><b><?php print t('Country:'); ?></b> <?php print $article->country; ?></p>
                            <p><b><?php print t('Award:'); ?></b> <?php print $article->award_name; ?></p>
                        </div>
                    </div>
                <?php endif; ?>
            <?php endforeach; ?>
            </div>
        </div>
    <?php endforeach; ?>
<?php else: ?>
    <div class="awards-items-no-results articles-search-result-none"><?php print t('Sorry no downloads match your filter '). "<b>(". $filter .")</b>"; ?></div>
<?php endif; ?>
<?php if(empty($filter)): ?>
</div>
<?php endif; ?>
