(function ($) {
  /**
   * In node forms on Ctrl-S click the first action button.
   */
  Drupal.behaviors.igcommerce_utility_localization = {
    attach: function (context, settings) {
      var base_url = Drupal.settings.igcommerce_utility_localization.base_url;
      // Active and inactive images stored in module images folder to replace depending on status.
      var active_img = base_url + '/' +Drupal.settings.igcommerce_utility_localization.active_img;
      var inactive_img = base_url + '/' + Drupal.settings.igcommerce_utility_localization.inactive_img;

      // Call the datepicker event to capture date selection.
      jQuery.datepicker.setDefaults({
        onSelect: function () {

          var id= this.id;
          var data = id.split('-');
          var index = data[5];
          var start_date = '';
          var end_date = '';

          // After selection of end date we need to check for start date and compare with current date.
          if(data[7] == 'end' || data[7] == 'start') {

            // Gathering start date of selected end date.
            start_date = jQuery('#edit-field-url-aliases-und-'+index+'-field-start-date-und-0-value-datepicker-popup-0').val();
            end_date = jQuery('#edit-field-url-aliases-und-'+index+'-field-end-date-und-0-value-datepicker-popup-0').val();
            start_date_time = jQuery('#edit-field-url-aliases-und-'+index+'-field-start-date-und-0-value-timeEntry-popup-1').val();
            end_date_time= jQuery('#edit-field-url-aliases-und-'+index+'-field-end-date-und-0-value-timeEntry-popup-1').val();

            // Splitting the date time string so that we can get the hour and minute.
            var sdt_ary = start_date_time.split(':');
            var sdth = sdt_ary[0];

            // If we dont have any minute specified then take 00 by default.
            if(sdt_ary[1] == undefined){
              var sdtm = '00';
            }else{
              var sdtm = sdt_ary[1];
            }

            // Converting dates into timestamp for comparision. [0] => Month, [1] => Day, [2] => Year
            start_date_arr = start_date.split('/');
            // Converting into unix timestamp for standard date comparision.
            start_date_data = new Date(start_date_arr[2], parseInt(start_date_arr[0], 10) - 1, start_date_arr[1], sdth, sdtm);
            start_date_ts = start_date_data.getTime();

            end_date_arr = end_date.split('/');

            var edt_ary = end_date_time.split(':');
            var edth = edt_ary[0];

            // If we dont have any minute specified then take 00 by default.
            if(edt_ary[1] == undefined){
              var edtm = '00';
            }else{
              var edtm = edt_ary[1];
            }

            // Converting into unix timestamp for standard date comparision.
            end_date_data = new Date(end_date_arr[2], parseInt(end_date_arr[0], 10) - 1, end_date_arr[1], edth, edtm);
            end_date_ts = end_date_data.getTime();

            // Get today's UNIX timestamp.
            current_date_ts = new Date().getTime();

            // Getting languague locale so that we can replace correct red/green bubble.
            var locale = jQuery('#edit-field-url-aliases-und-'+index+'-field-language-locale-und-0-value').val();

            // If Content is not expired then add green bubble.
            if( start_date_ts < current_date_ts && end_date_ts > current_date_ts) {
              jQuery('#expiry_indicator_'+locale).prop('src',active_img);
            }else{ // If content is expired add red bubble.
              jQuery('#expiry_indicator_'+locale).prop('src',inactive_img);
            }
          }
        }
      });
    }
  };
})(jQuery);
