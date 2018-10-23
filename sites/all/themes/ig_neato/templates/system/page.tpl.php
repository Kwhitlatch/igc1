<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>

  <div class="container shopping-cart">
    <?php print render($page['shopping-cart']); ?>
  </div>

  <header id="navbar" class="navbar navbar-fixed-top">
    <div class="container">
      <?php /* For proper schema validation on webcards, the attribute itemprop="publisher"
             * must be added to .navbar-header. However, this will cause Schema
             * validation errors on all non-webcard pages. Add this attribute back
             * in once you figure out how to do it condionally. RRN 1-27-18
             */ ?> 
      <div class="navbar-header" itemscope itemtype="https://schema.org/Organization" itemref="block-views-social-links-block-1">
        <meta itemprop="name" content="Fluke" />
          <a itemprop="url" class="navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <span itemprop="logo" itemscope itemtype="https://schema.org/ImageObject">
              <!--[if gte IE 9]><!-->
              <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 183 55">
                <?php /*<title id="fluke-logo-title"><?php print t('Fluke Industrial Group'); ?></title> */ ?>
                <path fill="#ffc20e" d="M0 0h183v55H0z"/>
                <path d="M27.7 17.6H49v3.8H32.2v2.8h16.9v4.2H32.2v6.8h-4.5zm24.2 0h4.4v13.2h14.3v4.4H51.9zm32.8 17.6h-8.6s-3-.1-3.3-3.3V17.6h4.4v13.5h15.4V17.6H97v14.3c-.4 3.2-3.3 3.3-3.3 3.3h-9zm16.7-17.6v17.6h4.4v-6.6l10.5 6.6h7.9l-14-9 13.3-8.6h-7.8l-9.9 6.1v-6.1zm25.3 0v17.6h22.2v-4.1h-17.8v-2.5h17.8v-4.1h-17.8v-2.7h17.8v-4.2zM157 30c-1.4 0-2.6 1.2-2.6 2.6 0 1.4 1.2 2.6 2.6 2.6 1.4 0 2.6-1.2 2.6-2.6 0-1.4-1.2-2.6-2.6-2.6zm-.1.4c.1 0 .1 0 0 0 1.3 0 2.2.9 2.2 2.2 0 1.2-.9 2.2-2.1 2.2-1.2 0-2.1-1-2.1-2.2 0-1.2.8-2.1 2-2.2zm-.9.7v3h.5v-1.3h.5l.8 1.3h.4l-.8-1.3c.4-.1.7-.4.7-.8 0-.6-.4-.9-1-.9H156zm.4 1.3v-.9h.6c.5 0 .6.1.6.5 0 .3-.2.5-.5.5h-.7v-.1z" class="st1"/>
              </svg>
              <!--<![endif]-->
              <!--[if lte IE 8]>
                <img alt="<?php print t('Fluke Industrial Group'); ?>" title="Fluke Industrial Group" src="<?php print $logo; ?>">
              <![endif]-->
            <meta itemprop="url" content="<?php print $logo; ?>">
            <meta itemprop="width" content="199">
            <meta itemprop="height" content="60">
            </span>
          </a>

        <?php if (!empty($site_name)): ?>
          <a class="name brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
        <?php endif; ?>
      </div>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="main-nav-desktop-set">
        <div class="navbar-collapse collapse">
            <div class="region region-navigation">
              <?php if (!empty($primary_nav)): ?>
                <?php print render($primary_nav); ?>
              <?php endif; ?>
              <?php if (!empty($secondary_nav)): ?>
                <?php print render($secondary_nav); ?>
              <?php endif; ?>
              <?php if (!empty($page['navigation'])): ?>
                <?php print render($page['navigation']); ?>
              <?php endif; ?>
            </div>
        </div>
      <?php endif; ?>
        <a class='search-opener' href='#'>
          <span class='fluke-icon fluke-icon-search-fa-search'></span>
        </a>
        <a class='language-picker' href='#'>
          <span class='fluke-icon fluke-icon-globe'></span>
        </a>
        <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
          <div id="mmenu">

            <?php // The standard bootstrap mobile hamburger button has been re-wired to
                // open the mmenu module ?>
              <button type="button" class="navbar-toggle">
                <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
                <span class="fluke-icon fluke-icon-fa-bars"></span>
              </button>

          </div>
        <?php endif; ?>

      </div>
    </div><!-- /.container -->
    <div class="topbar" role="presentation"></div>
  </header>
  
<?php print render($page['mobile_navigation']); ?>

<div class="main-container <?php //print $admin_banner_bumper; ?> <?php //print $container_class; ?>">
     
  <?php if (!empty($page['search-box'])): ?>
    <div id="main-search">
      <?php print render($page['search-box']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($page['sidebar_first'])): ?>
    <aside role="complementary">
      <?php print render($page['sidebar_first']); ?>
    </aside>  <!-- /#sidebar-first -->
  <?php endif; ?>

  <?php if (!empty($page['highlighted'])): ?>
    <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
  <?php endif; ?>
  <?php //if (!empty($breadcrumb)): print $breadcrumb; endif;?>
  <a id="main-content"></a>

  <?php print $messages; ?>
  <?php if (!empty($tabs)): ?>
    <?php print render($tabs); ?>
  <?php endif; ?>
  <?php if (!empty($page['help'])): ?>
    <?php print render($page['help']); ?>
  <?php endif; ?>
  <?php if (!empty($action_links)): ?>
    <ul class="action-links"><?php print render($action_links); ?></ul>
  <?php endif; ?>
  <?php print render($page['content']); ?>

<?php if (!empty($page['sidebar_second'])): ?>
  <aside role="complementary">
    <?php print render($page['sidebar_second']); ?>
  </aside>  <!-- /#sidebar-second -->
<?php endif; ?>

</div><!-- /.main-container -->

<?php if (!empty($page['footer']) || !empty($page['white-footer'])): ?>
  <footer id="site-footer" class="inverse">

    <?php if (!empty($page['white-footer'])): ?>
      <div class="footer-top">
        <div class="container">
          <div class="row">
            <?php print render($page['white-footer']); ?>
          </div><!-- /.row -->
        </div><!-- /.container -->
      </div><!-- /#white-footer -->
    <?php endif; ?>

    <?php if (!empty($page['footer'])): ?>
      <div class="footer footer-bottom navbar-inverse primary">
        <div class="container">
          <div class="row">

              <?php if ($is_front) {
                  print "<h1 class='h1-no-style'>";
              } ?>
              <div class="slogan">
                <span id="fluke-slogan">
                <?php print t('Fluke. '); ?>
                </span>
                <?php print t('Keeping your world up and running.'); ?>&reg;
              </div>
              <?php if ($is_front) {
                  print "</h1>";
              } ?>
            </div>

            <?php print render($page['footer']); ?>
            
            <div class="clearfix"></div>
            <div>
              <small id="copyright">&copy;1995 - <?php print date('Y'); ?> Fluke Corporation
              </small>
            </div>
        </div><!-- /.container -->
      </div><!-- /#black-footer -->
    <?php endif; ?>

  </footer>
<?php endif; ?>