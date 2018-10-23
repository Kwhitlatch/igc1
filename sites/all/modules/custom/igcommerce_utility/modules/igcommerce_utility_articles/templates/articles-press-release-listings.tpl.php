<?php
/**
param $filter : Used to filter results with $_GET request;
param $language : Current language local;
param $total : Total number of items found;
param $items : An object of items to be displayed;
*/
?>
<?php if(empty($filter) && $filter !== FALSE): ?>
<div class="views-exposed-widgets clearfix">
    <div id="edit-tm-article-display-title-wrapper2" class="views-exposed-widget views-widget-filter-tm_article_display_title">

        <div class="views-widget">
            <div class="form-item form-type-textfield form-item-tm-article-display-title">
                <input type="text" id="article-press-release-search" name="tm_article_display_title" value="" size="30" maxlength="128" class="form-text">
            </div>
        </div>
    </div>
    <div class="views-exposed-widget views-submit-button">
        <input type="submit" id="edit-submit-search-list-solr" value="<?php print t('Search Press Releases'); ?>" class="form-submit">    </div>
    <div class="views-exposed-widget views-widget-sort-order solr-sort-order">
    </div>

</div>
<div class="press-release-search-results articles-search-results">
<?php endif; ?>
<?php if(count($items) > 0): ?>
    <?php foreach ($items as $article_group): ?>
        <!-- ACCORDION ITEM -->
        <div class="press-release-items articles-search-result-item">
            <h3 class="press-release-items-date"><?php print t($article_group['month']); ?></h3>
            <div class="press-release-items-content">
            <?php foreach ($article_group['data'] as $article): ?>
                <?php if (isset($article->ss_field_content_title) && !empty($article->ss_field_content_title)): ?>
                    <div class="press-release-item <?php print($article->entity_id); ?>">
                        <?php 
                        // The date before articles was removed 3-8-18 because it is redundant -RRN.
                        /*<div class="press-release-pub-date"><?php print(t($article_group['month'])); ?></div> */ 
                        ?>
                        <p class="press-release-title"><?php print $article->link; ?></p> 
                    </div>
                <?php endif; ?>
            <?php endforeach; ?>
            </div>
        </div>
    <?php endforeach; ?>
<?php else: ?>
    <div class="press-release-items-no-results articles-search-result-none"><?php print t('Sorry no downloads match your filter '). "<b>(". $filter .")</b>"; ?></div>
<?php endif; ?>
<?php if(empty($filter)): ?>
</div>
<?php endif; ?>
