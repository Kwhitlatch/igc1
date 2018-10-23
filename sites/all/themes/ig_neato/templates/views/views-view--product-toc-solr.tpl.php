<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
global $language;
?>
<div class="<?php print $classes; ?>">
<?php print render($title_prefix); ?>
<?php if ($title): ?>
    <?php print $title; ?>
<?php endif; ?>
<?php print render($title_suffix); ?>
<?php if ($header): ?>
    <div class="view-header">
        <?php print $header; ?>
    </div>
<?php endif; ?>

<?php if ($exposed): ?>
    <div class="view-filters">
        <?php print $exposed; ?>
    </div>
<?php endif; ?>

<?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
        <?php print $attachment_before; ?>
    </div>
<?php endif; ?>

<?php if ($rows): ?>
    <div class="view-content">
        <?php
        //dpm(count($rows));
        $results = json_decode($rows);
        //dpm($results, 'view tpl');
        $content = '';
        $current_langauge_locale = $language->name;
        foreach ($results as $items) {

            foreach ($items as $item) {
                $images = json_decode($item->node->sm_product_slideshow);
                $image = isset($images->field_product_image_desktop->und[0]) ? $images->field_product_image_desktop->und[0] : NULL;
                $summary = isset($item->node->tm_summary) ? $item->node->tm_summary : NULL;
                $short_description = isset($item->node->ts_short_description_summary) ? $item->node->ts_short_description_summary : NULL;
                $url = igcommerce_utility_product_tocs_get_url($item);
                if(isset($item->node->ss_field_content_title )) {
                    $title = $item->node->ss_field_content_title ;
                }
                elseif (isset($item->node->ss_field_content_title )) {
                    $title = $item->node->ss_field_content_title ;
                }
                else {
                    $title = NULL;
                }
                $oracleid = isset($item->node->sku) ? $item->node->sku : NULL;
                $content .= '<div class="row col-md-12" style="display:none;"><div class="toc-listing-item-wrapper"><div class="toc-listing-image"><a href="'
                    . $url . '">' . igcommerce_utility_product_tocs_get_featured_image($image)
                    . '</a></div></div><div class="toc_article_card_large"><div class="toc_article_card_image_large"><a href="' . $url
                    . '"><h3 style="margin-top:0px">' . $title . '</h3></a><p>' . $short_description . '</p>';
                if ($oracleid != 0 && $current_langauge_locale == "en-us") {
                    $content .= '<div class="product-review-summary">
                  <div id="BVRRInlineRating-' . $oracleid . '"></div>
                  </div>';
                }
                $content .= '</div></div></div>';
            }
        }

        if ($current_langauge_locale == "en-us" && !empty($_igcommerce_utility_oracle_array)) {
            $content .= '<script src="https://display.ugc.bazaarvoice.com/static/Fluke/en_US/bvapi.js"></script>
              <script>
                $BV.ui("rr", "inline_ratings", {
                  productIds : [' . implode(',', $_igcommerce_utility_oracle_array) . '],
                  containerPrefix : "BVRRInlineRating"
                });
              </script>';
        }

        if (!empty($content)) {
            print $content;
        } else {
            print t('<h3>No products found in this category</h3>');
        }

        ?>
        <?php //print $rows; ?>
    </div>
<?php elseif ($empty): ?>
    <div class="view-empty">
        <?php print $empty; ?>
    </div>
<?php endif; ?>

<?php if ($pager): ?>
    <?php print $pager; ?>
<?php endif; ?>
    <div id="loadMore" style="display:none;padding-right: 20px;"><button><?php print t('Load more'); ?></button></div>
    <span class="number_of_items" style="display:none;">
      <?php print t('Showing'); ?> <span class="total_loaded"></span> /
      <span class="total_items"></span>
    </span>
    <div id="showLess" style="display:none;padding-left: 20px"><button><?php print t('Show less'); ?></button></div>

<?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
        <?php print $attachment_after; ?>
    </div>
<?php endif; ?>

<?php if ($more): ?>
    <?php print $more; ?>
<?php endif; ?>

<?php if ($footer): ?>
    <div class="view-footer">
        <?php print $footer; ?>
    </div>
<?php endif; ?>

<?php if ($feed_icon): ?>
    <div class="feed-icon">
        <?php print $feed_icon; ?>
    </div>
<?php endif; ?>

    </div><?php /* class view */ ?>
    <style>
      .ui-widget-content {
        border: none;
      }
      .ui-tabs .ui-tabs-panel {
        padding: 0px;
      }
      a h3 {
        color: #336699;
      }
      .ui-widget-header {
        border: none;
        background: none;
      }
      .ui-tabs .ui-tabs-nav li {
        display: inline-block;
        width: 33.3%;
        margin: 0;
        padding: 0;
      }
      .ui-tabs .ui-tabs-nav li.ui-state-default {
        border: none;
        background: none;
      }
      .ui-tabs .ui-tabs-nav li.ui-state-active a {
        border-bottom: 4px solid #336699;
      }
      .ui-tabs .ui-tabs-nav li a {
        border-bottom: 4px solid #eaeaea;
        font-family: "Roboto Slab";
        font-weight: 100;
        text-align: center;
        display: block;
        width: 100%;
        font-size: 23px;
        padding: 2px 10px 4px;
      }
    </style>
