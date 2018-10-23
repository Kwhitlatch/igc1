<?php 
/**
 * Creates the homepage slideshow.
 *
 * The slide content comes from a solr query found in igcommerce_utility.module
 * function igcommerce_utility_homepage_slideshow().  The function uses the 
 * flexslider api's flexslider_add() to instantiate the required javascript.
 *
 * The flexslider settings are unusual, in that they are set through the GUI at 
 * admin/config/media/flexslider (This the flexslider recommended method). 
 * The html must be structured to support the flexslider specific settings.
 * Woothemes bought flexslider. You can see their site for the html structures.
 * Instantiating flexslider programatically instead of using Drupal Views is 
 * not well documented.  I used the html pattern found on this page:
 * http://flexslider.woothemes.com/thumbnail-controlnav.html
 *
 * The themeing is in the theme layer in 
 * _pane-igcommerce-utility-homepage-slideshow.scss
 * 
 */ 

//dpm($slides, 'Here are the variables'); 
?>

<div id="homepage-flexslider" class="flexslider">
  <ul class="slides">
    
    <?php foreach ($slides as $slide) : ?>
      <li data-thumb="<?php print $slide->image_thumb_url; ?>">  
        <div class="slide-image <?php print $slide->text_position; ?>">
          <?php print $slide->image; ?>
        </div>

        <div class="slide-text-wrapper">
          <div class="slide-gradient-wrapper <?php print $slide->text_position . ' ' . $slide->text_color;?>">  
            <h2 class="slide-title">
              <?php print $slide->title; ?>
            </h2>
            <div class="slide-subtitle">
              <?php print $slide->subtitle; ?>
            </div>            
            <?php print l($slide->cta_text, $slide->cta_link, array('absolute' => TRUE, 'attributes' => array('class'=> array('button')))); ?>
          </div>
        </div>

      </li>
    <?php endforeach; ?>

  </ul>
</div>