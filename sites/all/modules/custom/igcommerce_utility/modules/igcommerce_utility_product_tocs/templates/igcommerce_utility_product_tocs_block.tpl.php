<?php if(count($items) > 0): ?>
    <?php
        global $language;
        $current_language_locale = $lang;
        $prod_type =  isset($type) ? $type: rand(1, 4);
        $node_nid =  isset($nid) ? $nid: 0;

          if ($language->language == "en-us" ) {
            // Options for external bazarrvoice script
            $options = array(
                'type' => 'external',
                'defer' => TRUE,
            );
            // After the page loads, this script populates the star and reviews sections
            //Staging environment
            // drupal_add_js('https://apps.bazaarvoice.com/deployments/Fluke/main_site/staging/en_US/bv.js', $options);
            // Production environment
             drupal_add_js('https://apps.bazaarvoice.com/deployments/fluke/main_site/production/en_US/bv.js', $options);
        }
    ?>

    <div class="paginate" data-type="<?php print $prod_type; ?>">
<!--        <input type="text" class="search" placeholder="Filter" />-->
        <ul id="toc_product_list_<?php print isset($type) ? $type: rand(1, 4);?>">
        <?php foreach ($items as $product): ?>

            <?php
                $image = '';
                if(!empty($product->ss_slideshow_main_img)){
                    $image = json_decode($product->ss_slideshow_main_img);
                }elseif(!empty($product->is_product_slideshow)) {
                  $slideshow = fluke_solr_get_entity($product->is_product_slideshow, 'node', 'slideshow', $lang);
                  if (!empty($slideshow->sm_field_product_image_desktop[0])) {
                    $image = json_decode($slideshow->sm_field_product_image_desktop[0]);             
                  }
                }
                $summary = isset($product->tm_summary) ? $product->tm_summary : NULL;
                $short_description = isset($product->tm_short_description_summary[0]) ? $product->tm_short_description_summary[0] : NULL;
                $url = igcommerce_utility_product_tocs_get_url($product);
                if(isset($product->ss_field_content_title)) {
                    $title = $product->ss_field_content_title;
                }
                elseif (isset($product->ss_field_content_title)) {
                    $title = $product->ss_field_content_title;
                }
                else {
                    $title = NULL;
                }
                $oracleid = isset($product->sku) ? $product->sku : NULL;
                $date = date_create($product->ds_created);
                $sort_order = 90;
                if(isset($product->sm_field_product_list_sort_solr)) {$sort_order = $product->sm_field_product_list_sort_solr;}
                if(isset($product->sm_field_accessories_list_sort_solr)) {$sort_order = $product->sm_field_accessories_list_sort_solr;}
                if(isset($product->sm_field_kits_list_sort_solr)) {$sort_order = $product->sm_field_kits_list_sort_solr;}

                if(module_exists('igc_compare')){
                    // Add markup if the compare module is enabled
                    $compare_markup = igc_compare_process_product_display($product, $title, $url, $image);
                }
            ?>
            <li class="row list toc_product_item toc_product_item_<?php print isset($type) ? $type: 'default';?>" style="display: none;"
                data-topseller="<?php print $sort_order; ?>"
                data-created="<?php print date_format($date, 'Y-m-d H:i:s'); ?>">

                <div class="toc-listing-item-wrapper">
                    <div class="toc-listing-image">
                        <?php print l(igcommerce_utility_format_image_product_toc($image->url, $image->alt, $image->caption), $url, array('html' => TRUE, 'language' => $language)); ?>
                    </div>
                </div>
                <div class="toc_article_card_large">
                    <div class="toc_article_card_image_large">
                        <?php 
                        print l('<h3 class="toc_product_title">' . $title . '</h3>', $url, array('html' => TRUE, 'language' => $language)); ?>
                        <p><?php print(strip_tags($short_description)); ?></p>
                        <?php
                          // Creates the bazaarvoice inline rating stars. 
                            if ($language->language == "en-us" && isset($url)) {
                                $lastchunk = explode('/', $url);
                                print '<div  class="bv-inline-stars"><div data-bv-show="inline_rating" data-bv-product-id="' .  end($lastchunk) . '" ></div></div>';
                            }
                        ?>
                        <?php if(isset($compare_markup) && !empty($compare_markup))  print $compare_markup ;?>
                    </div>
                </div>
            </li>
        <?php endforeach; ?>
        </ul>
        <div class="pagination"></div>
    </div>
<?php endif; ?>
