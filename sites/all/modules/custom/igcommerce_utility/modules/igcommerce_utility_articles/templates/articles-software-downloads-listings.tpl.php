<?php
/**
param $filter : Used to filter results with $_GET request;
param $language : Current language local;
param $total : Total number of items found;
param $items : An object of items to be displayed;
 */
?>

<div class="software-downloads-search-results articles-search-results">
    <?php if(count($items) > 0): ?>
      <nav>
        <ul class="article-list">
        <?php foreach ($items as $article): ?>
         
            <li class="software-downloads-item articles-search-result-item <?php print $article->ss_field_url_title; ?>">
                <a class="event-download-software software-downloads-item-title articles-search-result-title" title="<?php print($article->tm_article_display_title[0]); ?>" href="<?php print $language.'/'.$article->path_alias; ?>"><?php print($article->tm_article_display_title[0]); ?></a>
                <?php /* This used to output the content of the article in an accoridon body, but has since been removed

                <div class="software-downloads-item-body articles-search-result-body" style="display: none;"><?php print isset($article->ts_article_body) ? $article->ts_article_body : 'No content found'; ?></div>
                
                */ ?>
            </li>
        <?php endforeach; ?>
        </ul>
      </nav>
    <?php else: ?>
        <div class="software-download-items-no-results articles-search-result-none"><?php print t('Sorry no downloads match your filter '). "<b>(". $filter .")</b>"; ?></div>
    <?php endif; ?>
</div>
