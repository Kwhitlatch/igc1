(function ($){
  /**
   * In taxonomy node forms, on exit of Name field, copy it to Display Title and Url Title for Taxonomy form.
   */
  Drupal.behaviors.igcommerce_autopopulate ={
  attach: function (context, settings){
	  //jQuery event for taxonomies.
	  jQuery("#edit-name-field-und-0-value, #edit-name").on("change", function(){
			 var contents_taxonomy = jQuery("#edit-name-field-und-0-value, #edit-name").val();
			 var url_title_taxonomy = (contents_taxonomy).toLowerCase().replace(/^\s\s*/, '').replace(/\s\s*$/, '').replace(/([\s]+)/g, '-');
			jQuery("#edit-field-content-title-en-us-0-value").val(contents_taxonomy);
			jQuery("#edit-field-url-title-en-us-0-value").val(url_title_taxonomy);
			});
		}
	};
})(jQuery);