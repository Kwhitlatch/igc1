<?php
/*
 * This is a template for all footer menu links
 * it is used by _igcommerce_utility_get_footer_links() in igcommerce_utility.module to generate html output
*/
?>
<?php if(isset($items) && !empty($items)): ?>
    <?php if($bundle == 'social_links'): ?>
        <div id="block-views-social-links-block-1" class="block block-views col-sm-4 <?php print $bundle; ?>">
            <div class="view view-social-links view-id-social_links view-display-id-block_1">
                <div class="view-content">
                    <?php foreach ($items as $item): ?>
                    <div class="views-row views-row-1 views-row-odd views-row-first">
                        <div>
                            <div>
                                <a itemprop="sameAs" href="<?php print $item['link']; ?>" title="<?php print $item['title']; ?>" class="fluke-icon event-<?php print $item['class']; ?>" target="_blank">
                                    <span aria-hidden="true" class="fluke-icon fluke-icon-<?php print $item['class']; ?>">
                                        <span class="hide"><?php print $item['title']; ?></span>
                                    </span>
                                </a>
                            </div>
                        </div>
                    </div>
                    <?php endforeach; ?>
                </div>
            </div>
        </div>
    <?php elseif ($bundle == 'footer_column_4_fluke_newsletters_signup'): ?>
        <div id="block-menu-menu-footer-column-4-fluke-new" class="block block-menu col-sm-2 <?php print $bundle; ?>">
          <ul class="menu">
            <?php foreach ($items as $item): ?>
            <li class="last leaf">
              <!--Replace Newsletter CTA with QR code in china-->
              <?php if($language->language == 'cn'): ?>
                <?php print $item['qrchina']; ?>
              <!--Replace Newsletter CTA with iframe form in en-us -->
              <?php elseif($language->language == 'en-us'): ?>
                <iframe style="border:0 none; width: 100%; height: 330px;" src="https://forms.fluke.com/IG-GL-MULTI-2018-NEWSLETTER-LP-1-A?lcid=6b91a4ea-a448-e811-80c8-00155d027404&lrpf=MULTI&plt=200000001&cra=100000019&scl=2256&redir=https://www.fluke.com/en-us/fluke/thank-you-for-contacting-us"></iframe>
              <?php elseif($language->language !== 'cn' && $language->language !== 'en-us'): ?>
                  <?php
                      print l(t($item['title']), $item['link'],
                          array('html' => TRUE,
                              'language' => $language,
                              'attributes' => array(
                                  'title' => $item['title'],
                                  'target' => $item['target'],
                                  'id' => 'fluke-newsletters-signup-button',
                                  'class' => ['btn', 'btn-blue', 'btn-lg', 'btn-block', 'event-newsletter-signup'],
                              )
                          )
                      );
                  ?>
              <?php endif; ?>
            </li>
            <?php endforeach; ?>
          </ul>
        </div>
    <?php elseif($bundle == 'footer_terms'): ?>
        <div id="footer-t-and-c" class="<?php print $bundle; ?>">
            <ul class="menu">
                <?php foreach ($items as $item): ?>
                    <li class="leaf">
                        <?php
                            $class = 'event-' . drupal_html_class($item['title']);
                            print l(t($item['title']), $item['link'],
                                array('html' => TRUE,
                                    'language' => $language,
                                    'attributes' => array(
                                        'title' => $item['title'],
                                        'target' => $item['target'],
                                        'class' => array($class),
                                    )
                                )
                            );
                        ?>
                    </li>
                <?php endforeach; ?>
            </ul>
        </div>
    <?php else: ?>
        <div id="block-menu-menu-<?php print $bundle; ?>" class="block block-menu col-sm-2 <?php print $bundle; ?>">
            <ul class="menu">
                <?php foreach ($items as $item): ?>
                <li class="leaf">
                    <?php
                    $class = 'event-nav-' . drupal_html_class($item['label']?$item['label']:'');
                    
                    print l(t($item['title']), $item['link'],
                        array('html' => TRUE,
                            'language' => $language,
                            'attributes' => array(
                                'title' => $item['title'],
                                'target' => $item['target'],
                                'class' => array($class),
                            )
                        )
                    );
                    ?>
                </li>
                <?php endforeach; ?>
            </ul>
        </div>
    <?php endif; ?>
<?php endif; ?>
