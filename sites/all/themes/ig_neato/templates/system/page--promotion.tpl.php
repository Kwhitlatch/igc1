<?php
/**
 * @file
 * Displays the content type of "promotion".
 *
 * Promotions have an option to show/hide/na the header and footer.
 * This differs from page.tpl.php in that it checks the $variables['hidden_header']
 * to see if they should be shown.  $variables['hidden_header'] is set in 
 * template.php.  
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
<?php if (empty($hidden_header)): ?>

  <div class="container shopping-cart">
    <?php print render($page['shopping-cart']); ?>
  </div>

  <header id="navbar" class="navbar navbar-fixed-top">
    <div class="container">

      <div class="navbar-header" itemscope itemprop="publisher" itemtype="http://schema.org/Organization" itemref="block-views-social-links-block-1">
        <meta itemprop="name" content="Fluke" />
        <?php if ($logo): ?>
          <a itemprop="url" class="logo navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <span itemprop="logo" itemscope itemtype="https://schema.org/ImageObject">
            <img itemprop="url" src="<?php print $logo; ?>" alt="<?php print t('Fluke Industrial Group'); ?>" />
            <meta itemprop="width" content="199">
            <meta itemprop="height" content="60">
            </span>
          </a>
        <?php endif; ?>

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
<?php endif; ?>

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
<?php if (empty($hidden_footer)): ?>

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
            
              <div class="slogan">
                <span id="fluke-slogan">
                <?php print t('Fluke. '); ?>
                </span>
                <?php print t('Keeping your world up and running.'); ?>&reg;
              </div>
            </div>

            <?php print render($page['footer']); ?>
            
            <div class="clearfix"></div>
            <div>
              <small id="copyright">Copyright &copy;<?php print date('Y'); ?> Fluke Inc.
              </small>
            </div>
        </div><!-- /.container -->
      </div><!-- /#black-footer -->
    <?php endif; ?>

  </footer>
<?php endif; ?>
<?php endif; ?>