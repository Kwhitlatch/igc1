(function ($) {
    Drupal.behaviors.igcommerce_event = {
        attach: function (context, settings) {
            //convert timestamps to the users timezone
            $('.ig-tzdate.unprocessed').each(function(key, value){
                var client_tz = moment().format("Z");
                var event_time = $(value).text();

                var guess = moment.tz.guess();

                var tz_abbr = moment().tz(guess).format('z');

                $(value).text(moment(event_time).tz(client_tz).format('lll') + ' ' + tz_abbr);

                $(value).removeClass('unprocessed');

            });

            var filters = ['live','od','ts','ws'];

            filters.forEach(
              function(value){
                  $('#edit-category-' + value).change(
                      function(event){
                          var selected = $(this).val();
                          var form = $(this).closest('form');
                          
                          if(selected !== '0') {
                              $(form).find('table tbody tr').hide();

                              $(form).find('table tbody tr.' + selected).show();
                          }else{
                            $(form).find('table tbody tr').show();
                          }

                      }
                  );
              }
            );


        }
    };

})(jQuery);