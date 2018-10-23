<?php if (isset($variables['blocks'])): ?>
    <?php
//       dpm($variables, '$variables');
    $blocks = $variables['blocks'];
    $accessories_page = $variables['accessories_page'] ? $variables['accessories_page'] : NULL;
    $sort = '';
    $total = $blocks['products_block']['total'] + $blocks['kit_block']['total'] + $blocks['accessory_block']['total'];
    $disclaimer = '';
    ?>
    <?php if ($total): ?>
    <div id="tabs" class="pane-quicktabs-product-toc-listings">
        <ul>
            <?php if (isset($blocks['products_block']) && strlen(trim($blocks['products_block']['content'])) > 0): ?>
                <li>
                    <a href="#tabs-1" class="quicktabs-tabs"><?php print t('Products'); ?>
                        <span class="toc_total toc_total_products">(<?php print $blocks['products_block']['total']; ?>)</span>
                    </a>
                </li>
            <?php endif; ?>

            <?php if (isset($blocks['accessory_block']) && strlen(trim($blocks['accessory_block']['content'])) > 0): ?>
                <li>
                    <a href="#tabs-2" class="quicktabs-tabs"><?php print t('Accessories'); ?>
                        <span class="toc_total toc_total_products">(<?php print $blocks['accessory_block']['total']; ?>)</span>
                    </a>
                </li>
            <?php endif; ?>

            <?php if (isset($blocks['kit_block']) && strlen(trim($blocks['kit_block']['content'])) > 0): ?>
                <li>
                    <a href="#tabs-3" class="quicktabs-tabs"><?php print t('Kits'); ?>
                        <span class="toc_total toc_total_products">(<?php print $blocks['kit_block']['total']; ?>)</span>
                    </a>
                </li>
            <?php endif; ?>
        </ul>

        <?php if (isset($blocks['products_block']) && strlen(trim($blocks['products_block']['content'])) > 0): ?>
        <div id="tabs-1" class="quicktabs-tabpage">
          <div class="accessories-search-filter">
            <div class="row collapse product-list-toolbar">
                <div class="product-filter">
                    <label><?php print t("Sort By: "); ?></label>
                    <select name="selSort" data-type="products" data-originalpath="<?php print $blocks['original_path']; ?>" class="selSort aselSort">
                        <option data-custsort="" data-sort="topseller" value="topseller" selected=""><?php print t("Top Seller"); ?></option>
                        <option data-custsort="" data-sort="newest" value="newest"><?php print t("Newest"); ?></option>
                        <option data-custsort="" data-sort="name" value="name"><?php print t("Alpha: A-Z"); ?></option>
                    </select>
                </div>
            </div>
          </div>
        
          <div class="toc-listing-content">
              <?php print $blocks['products_block']['content']; ?>
          </div>

        </div>
            <?php
                if(isset($blocks['products_block']['disclaimer']) && !empty($blocks['products_block']['disclaimer'])) {
                    $disclaimer = $blocks['products_block']['disclaimer'];
                }
            ?>
        <?php endif; ?>

        <?php if (isset($blocks['accessory_block']) && strlen(trim($blocks['accessory_block']['content'])) > 0): ?>
            <div id="tabs-2" class="quicktabs-tabpage">
                <div class="accessories-search-filter">
                    <div class="row collapse product-list-toolbar">
                        <div class="product-filter">
                            <label><?php print t("Sort By: "); ?></label>
                            <select name="selSort" data-type="accessories" data-originalpath="<?php print $blocks['original_path']; ?>" class="selSort aselSort">
                                <option data-custsort="" data-sort="topseller" value="topseller" selected=""><?php print t("Top Seller"); ?></option>
                                <option data-custsort="" data-sort="newest" value="newest"><?php print t("Newest"); ?></option>
                                <option data-custsort="" data-sort="name" value="name"><?php print t("Alpha: A-Z"); ?></option>
                            </select>
                        </div>
                    </div>
                </div>
                <div class="toc-listing-content">
                    <?php print $blocks['accessory_block']['content']; ?>
                </div>
            </div>
            <?php
                if(isset($blocks['accessory_block']['disclaimer']) && !empty($blocks['accessory_block']['disclaimer'])) {
                    $disclaimer = $blocks['accessory_block']['disclaimer'];
                }
            ?>
        <?php endif; ?>

        <?php if (isset($blocks['kit_block']) && strlen(trim($blocks['kit_block']['content'])) > 0): ?>
            <div id="tabs-3" class="quicktabs-tabpage">
                <div class="accessories-search-filter">
                    <div class="row collapse product-list-toolbar">
                        <div class="product-filter">
                            <label><?php print t("Sort By: "); ?></label>
                            <select name="selSort" data-type="kits" data-originalpath="<?php print $blocks['original_path']; ?>" class="selSort aselSort">
                                <option data-custsort="" data-sort="topseller" value="topseller" selected=""><?php print t("Top Seller"); ?></option>
                                <option data-custsort="" data-sort="newest" value="newest"><?php print t("Newest"); ?></option>
                                <option data-custsort="" data-sort="name" value="name"><?php print t("Alpha: A-Z"); ?></option>
                            </select>
                        </div>
                    </div>
                </div>

                <div class="toc-listing-content">
                    <?php print $blocks['kit_block']['content']; ?>
                </div>

            </div>
            <?php
                if(isset($blocks['kit_block']['disclaimer']) && !empty($blocks['kit_block']['disclaimer'])) {
                    $disclaimer = $blocks['kit_block']['disclaimer'];
                }
            ?>
        <?php endif; ?>
    </div>
    <?php endif; ?>
<?php endif; ?>
<?php if(!empty($disclaimer)): ?>
    <div class="disclaimer"><?php print $disclaimer; ?></div>
<?php endif; ?>
