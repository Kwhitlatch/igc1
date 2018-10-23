(function ($) {
  Drupal.behaviors.igcommerce_utility_library_video = {
    attach: function (context, settings) {
      // Resize videos      
      $.colorbox.settings.onLoad = colorboxResize();

      $(window).resize(colorboxResize(true));

      function colorboxResize(resize) {
        var width = $(window).width() > 842 ? 800 : '95%';
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
})(jQuery);