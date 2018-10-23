<?php if (sizeof($items) < 1) { return; } ?>

<?php
    global $language;

    $lang_local = '/'.$language->language;
    $language_default = variable_get('language_default');
    if ($language_default->language == 'cn') {
        $lang_local = '';
    }
?>

<div id="homepage-alerts-link">
    <?php print "<a href='" . $lang_local . '/' . $items . "'>"; ?>
    <div id="homepage-alerts-notice">
    </div>
  </a>
  <h4 id="homepage-safety-recall">
    <?php print t('Safety Recall') . ":"; ?>
  </h4>
 <span id="homepage-alerts-notice-link">
  <?php print t('there are multiple product safety recalls.  Refer to the Product Recall page for details. '); ?>
  <?php print l(t('Read More'), $items); ?>
</span>
</div>
