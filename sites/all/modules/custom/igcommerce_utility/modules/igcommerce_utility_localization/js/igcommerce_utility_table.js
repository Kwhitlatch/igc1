/**
 * @file
 * This is a javascript written to handle the event which is responsible for expand and collapse functionality, This file
 * will have the functionality like when we press expand what to show , when we press collapse what to hide and so on. This
 * will also take care of placing the red and green dot depending on the current status of locale on node.
 *
 * @author anshul.jain@fluke.com
 */
 (function ($) {
  Drupal.behaviors.igcommerce_utility_table = {
    attach: function (context, settings) {
      // Getting variables from module file for use in jquery.
      var base_url = Drupal.settings.igcommerce_utility_table.base_url;
      var expand_img = base_url + '/' +Drupal.settings.igcommerce_utility_table.expand_img;
      var collapse_img = base_url + '/' + Drupal.settings.igcommerce_utility_table.collapse_img;
      var inactive_img = base_url + '/' +Drupal.settings.igcommerce_utility_table.inactive_img;
      var active_img = base_url + '/' + Drupal.settings.igcommerce_utility_table.active_img;
      var preview_img = base_url + '/' + Drupal.settings.igcommerce_utility_table.preview_img;

     // Getting current default language.
     var lang = Drupal.settings.igcommerce_utility_table.defaultlocal;

     // Perform operation when the Expand/Collapse button is clicked.
     $('.collapsibleimg').click(function() {
       // Checking number of Live and Expired Statuses under the content for purpose of applying Generic Green Dot if any one of the
       // child has LIVE Statuse or Generic Red dot (On top of every Row) if all of the childs have Expired statuses.
       var status_inactive = $(this).closest('.collapsitablesection').nextUntil('.collapsitablesection').find('.red').length;
       var status_active = $(this).closest('.collapsitablesection').nextUntil('.collapsitablesection').find('.green').length;

       // If the rows are already expanded then apply red or green dot according to requirement.
       if($(this).closest('.collapsitablesection').hasClass('open') ) {
         if(parseInt(status_active) > 0){
          $(this).closest('.collapsitablesection').find("td:nth-child(3) img").attr("src",active_img);
        }else{
          $(this).closest('.collapsitablesection').find("td:nth-child(3) img").attr("src",inactive_img);
        }
		// On Collapse the tabe row which  having class 'collapsitablesection'  in that 4th,5th,6th,7th,8th,9th,10th column(locale) replace the text with '---'.
    $(this).closest('.collapsitablesection').find("td:nth-child(4),td:nth-child(5),td:nth-child(6),td:nth-child(7),td:nth-child(8),td:nth-child(9),td:nth-child(10)").html("---");
    $(this).closest('.collapsitablesection').nextUntil('.collapsitablesection').addClass('hide');
    $(this).closest('.collapsitablesection').removeClass('open');
    $(this).closest('.collapsitablesection').find('img.collapsibleimg').prop("src", collapse_img);
  }else{
	    // Get stored data in variable of a row
      var current_statusimg = $(this).closest('.collapsitablesection').find("td:nth-child(3)").attr("data-image");
      var current_source = $(this).closest('.collapsitablesection').find("td:nth-child(5)" ).attr("data-source");
      var current_startdate = $(this).closest('.collapsitablesection').find("td:nth-child(6)" ).attr("data-startdate");
      var current_enddate = $(this).closest('.collapsitablesection').find("td:nth-child(7)" ).attr("data-enddate");
      var current_modifydate = $(this).closest('.collapsitablesection').find("td:nth-child(8)" ).attr("data-modifydate");
      var current_modifyby = $(this).closest('.collapsitablesection').find("td:nth-child(9)" ).attr("data-modifyby");
      var current_preview = '/'+lang+'/'+$(this).closest('.collapsitablesection').find("td:nth-child(10)" ).attr("data-preview");

      $(this).closest('.collapsitablesection').find("td:nth-child(3) img").attr("src",current_statusimg);
      $(this).closest('.collapsitablesection').find("td:nth-child(4)" ).html(lang);

	   //check source present or not when we expand the default language(en-us) strip
    if(current_source == ''){
     $(this).closest('.collapsitablesection').find("td:nth-child(5)" ).html('---');
   }else{
     $(this).closest('.collapsitablesection').find("td:nth-child(5)" ).html(current_source);
   }

   $(this).closest('.collapsitablesection').find("td:nth-child(6)" ).html(current_startdate);
   $(this).closest('.collapsitablesection').find("td:nth-child(7)" ).html(current_enddate);

		//check modify date present or not when we expand the default language(en-us) strip
		if(current_modifydate == ''){
			$(this).closest('.collapsitablesection').find("td:nth-child(8)" ).html('---');
    }else{
     $(this).closest('.collapsitablesection').find("td:nth-child(8)" ).html(current_modifydate);
   }
	   //check modify by present or not when we expand the default language(en-us) strip
    if(current_modifyby == ''){
     $(this).closest('.collapsitablesection').find("td:nth-child(9)" ).html('---');
   }else{
     $(this).closest('.collapsitablesection').find("td:nth-child(9)" ).html(current_modifyby);
   }

   $(this).closest('.collapsitablesection').find("td:nth-child(10)" ).html('<a class="View-links" target="_blank" href="'+current_preview+'"><img src="'+preview_img+'"/></a>');

   $(this).closest('.collapsitablesection').nextUntil('tr.collapsitablesection').removeClass('hide');
   $(this).closest('.collapsitablesection').addClass('open');
   $(this).closest('.collapsitablesection').find('img.collapsibleimg').prop("src", expand_img);
 }
});

    // On page load storing status image path in variable 'data-image'. So that  what is actual status for that locale will come to know.
    $('.alias_table tr').each(function(){
      var img = $(this).find("td:nth-child(3) img").attr("src");
      $(this).find("td:nth-child(3)").attr("data-image",img);
    });
       // create array to know how many unique node id we have.
       var nodeid_array=[];
       var numOfVisibleRowsID = $('tr.collapsitablesection:visible').attr('id');
       $("tr.collapsitablesection:visible").filter(function() {
        nodeid_array.push(this.id);
      }).length;

    // To know how many active and inactive loacle we have for each node
    for(var i=0;i<nodeid_array.length;i++){
      var local_status_active = $('.alias_table tr#'+nodeid_array[i]+' td img.green').length;
      var local_status_inactive = $('.alias_table tr#'+nodeid_array[i]+' td img.red').length;
      if(parseInt(local_status_active) > 0){
        $('.alias_table tr#'+nodeid_array[i] + ':first').find("td:nth-child(3) img").attr("src",active_img);
      }else{
        $('.alias_table tr#'+nodeid_array[i] + ':first').find("td:nth-child(3) img").attr("src",inactive_img);
      }
    }
    // On page load the tabe row which  having class 'collapsitablesection'  in that 4th,5th,6th,7th,8th,9th,10th column(locale) replace the text with '---'.
    $( ".alias_table tr.collapsitablesection  td:nth-child(4),.alias_table tr.collapsitablesection  td:nth-child(5),.alias_table tr.collapsitablesection  td:nth-child(6),.alias_table tr.collapsitablesection  td:nth-child(7),.alias_table tr.collapsitablesection  td:nth-child(8),.alias_table tr.collapsitablesection  td:nth-child(9),.alias_table tr.collapsitablesection  td:nth-child(10)" ).html("---");
  }
};
})(jQuery);
