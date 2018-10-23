jQuery(document).ready(function(){
  //alert("script loaded");
  
  jQuery(function($) {
    $('.navbar .dropdown').hover(function() {
      $(this).find('.dropdown-menu').first().stop(true, true).delay(100).slideDown();

    }, function() {
      $(this).find('.dropdown-menu').first().stop(true, true).delay(100).slideUp();

    });

    $('.navbar .dropdown > a').click(function(){
      location.href = this.href;
    });

  });
  // This wraps the products section in the main nav in columns to get a multi-column dropdown.
  // jQuery('.second-lvl-0, .second-lvl-1, .second-lvl-2, .second-lvl-3, .second-lvl-4, .second-lvl-5 ').wrapAll('<div class="col-md-3">');
  // jQuery('.second-lvl-6, .second-lvl-7 ').wrapAll('<div class="col-md-3">');
  // jQuery('.second-lvl-8, .second-lvl-9, .second-lvl-10, .second-lvl-11 ').wrapAll('<div class="col-md-3">');
  // jQuery('.second-lvl-12').wrapAll('<div class="col-md-3">');
  
  // This collapses the Sidebar navigation on the Product TOC for Mobile and Tablet
  if (parseInt(jQuery(window).width()) < 1024) {
    jQuery( "#accordion" ).collapse();
    // Used for styling the background behind the sidebar on mobile & tablet
    jQuery( ".flukestrap-layouts-sidebar" ).addClass("mobile-nav-gray-bg");
  }

});