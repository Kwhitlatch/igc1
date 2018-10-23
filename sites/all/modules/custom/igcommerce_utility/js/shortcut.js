(function ($) {

  /**
   * In node forms on Ctrl-S click the first action button.
   */
  Drupal.behaviors.shortcuts = {
    attach: function (context, settings) {
      // Key codes: http://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
      //alert("Drupal Ctrl-S activated");
      $(window, context).keypress(function(event) {
        //console.log( event );
        if ((event.ctrlKey && event.which == 115) || (event.which == 19)) {
          event.preventDefault();
          //alert("Save");
          // Save is with Save as Draft module always at first position
          $('.node-form #edit-actions input').first().click();
          // Do not trigger default behaviour of Firefox
          // Ref: http://stackoverflow.com/questions/93695/best-cross-browser-method-to-capture-ctrls-with-jquery
          return false;
        }
      });
    }
  };

})(jQuery);
