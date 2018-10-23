(function ($) {
	Drupal.behaviors.mmenu_mobile = {
		attach: function (context, settings) {
			// Make sure the active trail is followed by mmenu
			if($('#mmenu_right').length) {
				var urlPath = window.location.pathname;
				$('#mmenu_right li, #mmenu_right ul').removeClass('active-trail');
				//$('#mmenu_right li a[href="' + urlPath + '"]').parents().addClass('active-trail');
				$('#mmenu_right').find('li a[href="' + urlPath + '"]').parents().addClass('active-trail');
			}
		}
	};

})(jQuery);
