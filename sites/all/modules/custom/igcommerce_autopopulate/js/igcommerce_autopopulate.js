(function ($){
  /**
   * In node forms, on exit of Title field copy it to Display Title and Url Title for Content Types form and on exit of 
   * Display Title field copy it to Url Title for Translation Forms.
   */
Drupal.behaviors.igcommerce_autopopulate ={
  attach: function (context, settings){
			// jQuery change event for content types.
		jQuery("#edit-title-field-und-0-value").on("change", function(){
			var contents = jQuery("#edit-title-field-und-0-value").val();
			jQuery("#edit-field-content-title-und-0-value").val(contents);
			var url_title = (contents).toLowerCase().replace(/^\s\s*/, '').replace(/\s\s*$/, '').replace(/([\s]+)/g, '-');
			jQuery("#edit-field-url-title-und-0-value").val(url_title);
		});
		
			// jQuery change event for translations.
		jQuery("#edit-field-content-title").on("change", function(){
			var contents_trans = jQuery("#edit-field-content-title input:text").val();
			var url_title_trans = (contents_trans).toLowerCase().replace(/^\s\s*/, '').replace(/\s\s*$/, '').replace(/([\s]+)/g, '-');
			jQuery("#edit-field-url-title input:text").val(url_title_trans);		 
		});
	}
	
};

})(jQuery);