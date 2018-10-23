(function ($) {
  /**
   * In node forms on Ctrl-S click the first action button.
   */
  Drupal.behaviors.igcommerce_dashbord = {
    attach: function (context, settings) {
      $('#start-link, #end-link, #cancel-link').attr('href','javascript:void(0)');
      
      $('#start-link').click(function(){
          $('#start-link, #end-link').hide();
          $('#change-all-start-dates,#btn-save,#cancel-link').show();
      });
      $('#end-link').click(function(){
          $('#start-link, #end-link').hide();
          $('#change-all-end-dates,#btn-save,#cancel-link').show();
      });
      $('#cancel-link').click(function(){
          $('#start-link, #end-link').show();
          $('#change-all-start-dates,#change-all-end-dates,#btn-save,#cancel-link').hide();
      });
      
    }
  };
})(jQuery);
