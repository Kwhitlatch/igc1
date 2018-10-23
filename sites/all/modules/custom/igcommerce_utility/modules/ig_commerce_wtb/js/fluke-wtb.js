(function ($) {
    Drupal.behaviors.fluke_geosearch = {
        attach: function(context, settings) {

             // Add margin to the form-section if no results are shown
            if($('.results-column').length === 0){
                $('#form-section-inner').addClass('no-results');
            }else{
                $('#form-section-inner').removeClass('no-results');
            }
        }
    }
})(jQuery);