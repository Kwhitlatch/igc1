<?php

/**
 * @file
 * Modified Default theme implementation to display the basic html structure of a single
 * Drupal page. This tpl is implented to allow for search result specific pages.
 *
 * MIG3832 - Added meta name="robots" content="noindex" to Search pages
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 */
?>
<!DOCTYPE html>
<!--[if IE 8]><html class="no-js lt-ie9" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>"> <!--<![endif]-->
<head>
    <link rel="dns-prefetch" href=" https://s1182545284.t.eloqua.com">
    <link rel="dns-prefetch" href="https://dam-assets.fluke.com">
    <link rel="dns-prefetch" href="https://dam-assets.fluke.com.cn">
    <link rel="dns-prefetch" href="https://a.fluke.com">
    <link rel="dns-prefetch" href="https://service.maxymiser.net">
    <link rel="dns-prefetch" href="https://www.googletagmanager.com">
    <link rel="dns-prefetch" href="https://img.en25.com">
    <link rel="dns-prefetch" href="https://stats.g.doubleclick.net">
    <link rel="dns-prefetch" href="https://www.google-analytics.com">

    <meta http-equiv="x-dns-prefetch-control" content="on">
    <meta name="robots" content="noindex">

    <!--Cookiebot EU Cookie consent banner-->
    <script id="Cookiebot" src="https://consent.cookiebot.com/uc.js" data-cbid="277ba973-e44a-43a0-8a48-1c46fc6c4dc8" type="text/javascript" async></script>

    <!-- Google Tag Manager -->
    <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0];var j=d.createElement(s);var dl=l!='dataLayer'?'&l='+l:'';j.src='//www.googletagmanager.com/gtm.js?id='+i+dl;j.async=true;f.parentNode.insertBefore(j,f);})(window,document,'script','dataLayer','GTM-PVXQ5Z');</script>

  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
    <?php drupal_add_js('/sites/all/themes/ig_neato/js/maxymiser.js'); ?>
  <?php if($language->language == 'cn'): ?>
  <!--Conditional Baidu load for CN -->
    <meta name="baidu-site-verification" content="fVxmolMVKX" /> 
  <?php endif; ?>

</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
<!-- Google Tag Manager -->
<noscript><iframe src="//www.googletagmanager.com/ns.html?id=GTM-PVXQ5Z" height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
<div id="mobile-indicator"></div>

  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
