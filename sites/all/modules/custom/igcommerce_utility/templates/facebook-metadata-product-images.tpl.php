<?php
/**
 * @file
 * Template implementation of facebook opengraph image data for products.
 *
 * Available variables:
 * - $fb_image_set: array of images used in the slideshow
 *
 * The bulk of the OG data is added using igcommerce_utility.modules, and it 
 * puts the basic required OG attributes on each page. This template is for 
 * extending those core attributes with product images.  
 * TODO: If we optimize product images, we'll need to update the hardcoded
 * width and height below. -RRN 4-24-18
 *
 */
?>
<?php if(isset($fb_image_set)): ?>
  <?php foreach($fb_image_set as $fb_image): ?>
    <?php if(isset($fb_image['url'])): ?>

      <?php $file_type_check = substr($fb_image['url'], -3); ?>
      
      <?php if(($file_type_check == 'jpg') || ($file_type_check == 'png') || ($file_type_check == 'gif')): ?>
        <meta property="og:image" content="http:<?php print $fb_image['url'] ?>" />
        <meta property="og:image:secure_url" content="https:<?php print $fb_image['url'] ?>" />
        <meta property="og:image:type" content="image/<?php print $file_type_check ?>" />
        <meta property="og:image:width" content="1500" />
        <meta property="og:image:height" content="1000" />
        <?php if(isset($fb_image['alt'])): ?>
          <meta property="og:image:alt" content="<?php print $fb_image['alt'] ?>" />
        <?php endif; ?>
    
      <?php elseif(substr($fb_image['url'], 0, 24) == '//players.brightcove.net'): ?>
        <meta property="og:video" content="http:<?php print $fb_image['url'] ?>" />
        <meta property="og:video:secure_url" content="https:<?php print $fb_image['url'] ?>" />
      <?php endif; ?>

    <?php endif; ?>

  <?php endforeach; ?>
<?php endif; ?>
