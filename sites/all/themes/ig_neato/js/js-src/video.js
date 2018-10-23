// mig2321 - Moved this function from the following 2 identical functions in igcommerce_utility:
// 1) igcommerce_utility/js/video.js 
// 2) igcommerce_utility/modules/igcommerce_utility_training/js/video.js
//
(function ($) {
  Drupal.behaviors.igcommerce_utility_video = {
    attach: function (context, settings) {
      // Resize videos      
      $.colorbox.settings.onLoad = colorboxResize();

      $(window).resize(colorboxResize(true));

      function colorboxResize(resize) {
        var width = $(window).width() > 842 ? 675 : '95%';
        var height = $(window).height() > 700 ? 630: '95%';

        $.colorbox.settings.height = height;
        $.colorbox.settings.width = width;

        //if window is resized while lightbox open
        if(resize) {
          $.colorbox.resize({
            'height': height,
            'width': width
          });
        } 
      }
    }
  };
// Prevents videos from continuing to play in the background when colorbox loads.
// This was happening with download.fluke.com link
Drupal.behaviors.fix_colorbox_video = {
attach: function (context, settings) {
  $('body')
    .once('fix-colorbox-video', function () {
    $(document).bind('cbox_cleanup', function (e) {
    $('div#cboxLoadedContent iframe', this).attr('src', '');
    });
  });
}
};  
})(jQuery);