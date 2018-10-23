(function ($) {
  Drupal.behaviors.igcommerce_utility_support = {
    attach: function (context, settings) {
      $( "#dwd_manual" ).on( "click", function(event) {
          var url = $( "#manual_to_dwd" ).val();
          $('#manual_to_dwd').removeClass('highlight');
          // If valid value is selected.
          if(url !== '0'){
            var win = window.open(url, '_blank');
            if (win) {
                //Browser has allowed it to be opened
                win.focus();
            } else {
                //Browser has blocked it
                alert(t('Please allow popups for this website'));
            }
          }else{
            $('#manual_to_dwd').addClass('highlight');
          }
         event.preventDefault();
      });
    }
  };
})(jQuery);
