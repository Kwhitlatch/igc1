
<meta property="og:url" content="<?php print $url ?>" />
<meta property="og:type" content="<?php print $type ?>" />
<meta property="og:title" content="<?php print $title ?>" />
<meta property="og:description" content="<?php print $description ?>" />

<?php if(!empty($image)) : ?>
  <meta property="og:image" content="<?php print $image ?>" />
<?php endif; ?>

<?php if(!empty($appid)) : // It appears we are no longer using App_id for facebook analytics.?>
  <meta property="fb:app_id" content="<?php print $appid ?>" />
<?php endif; ?>

<meta property="og:locale" content="<?php print $locale ?>" />

<?php // Only articles should get this og tag ?>
<?php if($type == 'article') : ?>
  <meta property="article:publisher" content="https://www.facebook.com/fluke.corporation/" />
<?php endif; ?>
