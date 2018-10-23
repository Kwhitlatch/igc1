<?php if (isset($variables['blocks'])): ?>
    <?php
//       dpm($variables, '$variables');
    $blocks = $variables['blocks'];
    $accessories_page = $variables['accessories_page'] ? $variables['accessories_page'] : NULL;
    ?>

    <?php if ($accessories_page): ?>
    <div class="accessories-search-filter">
      <span class="row new-search">
          <div class="columns ten">
              <input type="text" name="searchKeyWords" id="searchKeyWords" value="">
          </div>
          <div class="columns six end">
              <input type="submit" class="button full-width" id="btnSearch" value="Search Accessories">
          </div>
          <span id="filter-count"></span>
      </span>
      <span>
      <div class="row collapse product-list-toolbar" style="border-bottom: 1px solid #cccccc;">
          <div class="columns four  offset-by-one ">
              <select id="selSort" class="aselSort">
                  <option data-custsort="" data-sort="name" value="name" selected="">Alpha: A-Z</option>
                  <option data-custsort="" data-sort="newest" value="newest">Newest</option>
                  <!--<option data-custsort="" data-sort="price" value="price">Price: Low to High</option>-->
                  <!--<option data-custsort="" data-sort="rating" value="rating">Rating: High to Low</option> -->
              </select>
          </div>
      </div>
      </span>
    </div>
    <div class="columns six offset-by-one end hide-for-small"></div>
    <?php endif; ?>

    <div id="tabs" class="pane-quicktabs-product-toc-listings">
        <ul>
            <?php if (isset($blocks['products_block']) && strlen(trim($blocks['products_block']['content'])) > 0): ?>
                <li>
                    <a href="#tabs-1" class="quicktabs-tabs quicktabs-style-arrows"><?php print t('Products'); ?>
                        <span class="toc_total toc_total_products">(<?php print $blocks['products_block']['total']; ?>)</span>
                    </a>
                </li>
            <?php endif; ?>

            <?php if (isset($blocks['accessory_block']) && strlen(trim($blocks['accessory_block']['content'])) > 0): ?>
                <li>
                    <a href="#tabs-2" class="quicktabs-tabs quicktabs-style-arrows"><?php print t('Accessories'); ?>
                        <span class="toc_total toc_total_products">(<?php print $blocks['accessory_block']['total']; ?>)</span>
                    </a>
                </li>
            <?php endif; ?>

            <?php if (isset($blocks['kit_block']) && strlen(trim($blocks['kit_block']['content'])) > 0): ?>
                <li>
                    <a href="#tabs-3" class="quicktabs-tabs quicktabs-style-arrows"><?php print t('Kits'); ?>
                        <span class="toc_total toc_total_products">(<?php print $blocks['kit_block']['total']; ?>)</span>
                    </a>
                </li>
            <?php endif; ?>
        </ul>

        <?php if (isset($blocks['products_block']) && strlen(trim($blocks['products_block']['content'])) > 0): ?>
        <div id="tabs-1" class="quicktabs-tabpage">
            <?php print $blocks['products_block']['content']; ?>
        </div>
        <?php endif; ?>

        <?php if (isset($blocks['accessory_block']) && strlen(trim($blocks['accessory_block']['content'])) > 0): ?>
        <div id="tabs-2" class="quicktabs-tabpage">
            <?php print $blocks['accessory_block']['content']; ?>
        </div>
        <?php endif; ?>

        <?php if (isset($blocks['kit_block']) && strlen(trim($blocks['kit_block']['content'])) > 0): ?>
        <div id="tabs-3" class="quicktabs-tabpage">
            <?php print $blocks['kit_block']['content']; ?>
        </div>
        <?php endif; ?>
    </div>
<?php endif; ?>
