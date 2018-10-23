(function ($) {
  Drupal.behaviors.latest = {
    attach: function (context, settings) {
      // Hides all the news items and rotates.
      var total_articles = $('p[id^="news-item-"]').length;
      // Only turns on rotator if there's more than 1 article.
      if (total_articles > 1) {
        var divs = $('p[id^="news-item-"]').hide(),
        i = 0;
        (function cycle() { 
          divs.eq(i).fadeIn(400)
          .delay(4000)
          .fadeOut(400, cycle);
          i = ++i % divs.length;
        })();
      } 
    }
  };
})(jQuery);
