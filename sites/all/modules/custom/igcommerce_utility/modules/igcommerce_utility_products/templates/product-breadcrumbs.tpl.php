<?php
    global $base_url;
    global $language;
?>
<nav id="fluke-product-display-breadcrumbs">
<ol itemscope itemtype="http://schema.org/BreadcrumbList">
        <li itemprop="itemListElement" itemscope itemtype="http://schema.org/ListItem">
            <a itemscope itemtype="http://schema.org/Thing" itemprop="item" href="/<?php print $language->language; ?>">
                <span itemprop="name"><?php print t("Home"); ?></span>
            </a>
            <span class="fluke-icon fluke-icon-caret-right" aria-hidden="true"></span>
            <meta itemprop="position" content="1" />
        </li>
        <?php if(isset($content['breadcrumb_array']) && is_array($content['breadcrumb_array'])): ?>
            <?php foreach ($content['breadcrumb_array'] as $index => $crumb): ?>
            <li itemprop="itemListElement" itemscope itemtype="http://schema.org/ListItem">
                <?php $copy = '<span itemprop="name">' . $crumb['title'] . '</span>'; ?>
                <?php print l($copy, $crumb['link'], array('html'=>true, 'attributes' => array('itemscope' => '', 'itemtype' => 'http://schema.org/Thing', 'itemprop' => 'item', ))); ?>
                <span class="fluke-icon fluke-icon-caret-right" aria-hidden="true"></span>
                <meta itemprop="position" content="<?php print ($index + 2); ?>" />
            </li>
            <?php endforeach; ?><!--end foreach-->
        <?php endif; ?>
        <!--Adds the product name (no link) as the last breadcrumb-->
        <li itemprop="itemListElement" itemscope itemtype="http://schema.org/ListItem">
            <span itemscope itemtype="http://schema.org/Product" itemprop="item">
                <span itemprop="name"><?php print $content['title']; ?></span>
            </span>
            <meta itemprop="position" content="<?php print (count($content['breadcrumb_array']) + 2); ?>" />
        </li>
    </ol><!--end itemscope ol wrapper-->
</nav>