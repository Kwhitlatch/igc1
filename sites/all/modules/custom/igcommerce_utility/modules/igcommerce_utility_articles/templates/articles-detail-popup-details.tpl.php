<div id="overlay" ><?php print drupal_render($panel_page); ?>

  <!--    toc background page load complete.-->
  <?php //why is this here??? $close = $alias; ?>

  <div id="myModal" class="modal show">
    <!--Added close overlay button-->
    <?php print l(t(''), $item['close'], array('attributes' => array('class' => array('close-overlay')))); ?>
    <div class="modal-dialog article-webcard">
      <?php 
      // The publisher is defined in the #navbar in the template page.tpl.php
      // the itemref in the article itemtype decleration points there
      ?> 
      <article class="modal-content" itemscope itemtype="http://schema.org/Article" itemref="navbar">
        <meta itemprop="author" content="Fluke" />
        <meta itemprop="datePublished" content="<?php print $item['pub_date']; ?>"/>
        <meta itemprop="dateModified" content="<?php print $item['mod_date']; ?>"/>
        <meta itemprop="mainEntityOfPage" content="<?php print $item['node_title']; ?>" />
        <div id="overlay-close-wrapper" class="modal-header">
          <?php print l(t(''), $item['close'], array('attributes' => array('class' => array('close-button')))); ?>
        </div>
        
        <?php if(isset($item['pic'])): ?>
          <!--Header image.-->
          <figure class="card-header">
            <div class="article-header-img">
              <?php print $item['pic']; ?>
              </div>
            <!--Added for getting image alt and caption text.-->
            <?php if (!empty($item['header_img_caption'])): ?>
              <figcaption><?php print $item['header_img_caption']; ?></figcaption>
            <?php elseif (!empty($item['header_img_alt'])): ?>
              <figcaption><?php print $item['header_img_alt']; ?></figcaption>
            <?php endif; ?>
          </figure>
        <?php endif; ?>
        
        <div class="modal-body">
          <section>
            <!--Social Share-->
            <?php print $item['social_share']; ?>
            <!--Call for assistance-->
            <p class="assistance">
            <?php print t('Call for assistance');?>
            </p>
            <!--Title of node.-->
            <h1 itemprop="headline"><?php print urldecode($item['node_title']); ?></h1>
            
            <div itemprop="articleBody">
            <!--  body of node.-->
            <?php print $item['node_body']; ?>

            <!-- CTA Webcard link..-->
            <?php if (!empty($item['ctas_primary_url']) || !empty($item['ctas_secondary_url'])): ?>
              <?php if (isset($item['ctas_primary_url'])): ?>
                <a itemprop="potentialAction" href="<?php print $item['ctas_primary_url']; ?>" class="button button-primary webcard-cta">
                  <?php print $item['ctas_primary_button_text']; ?>
                </a>
              <?php endif; ?>
              <?php if (isset($item['ctas_secondary_url'])): ?>
                <a itemprop="potentialAction" href="<?php print $item['ctas_secondary_url']; ?>" class="button button-primary webcard-cta">
                  <?php print $item['ctas_secondary_button_text']; ?>
                </a>
              <?php endif; ?>
            <?php endif; ?>
            </div>
          </section>
          <!--Recommended product of article.-->
          <aside>
            <?php print $item['recommended_products']; ?>
          </aside>
          <!--recommended article.-->
          <aside>
            <?php print $item['recommended_resources']; ?>
          </aside>
          <!--Footer of article.-->
          <footer>
            <?php print $item['recommended_card']; ?>
          </footer>
        </div><!--/.modal-body-->
      </article><!-- /.modal-content -->
    </div><!-- /.modal-dialog -->
  </div><!-- /#my-modal -->
</div><!-- /#overlay -->
