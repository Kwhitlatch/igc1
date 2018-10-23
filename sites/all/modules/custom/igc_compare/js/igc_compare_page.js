(function ($) {
    Drupal.behaviors.igc_compare_page = {
        attach: function (context, settings) {
            $('.compare-remove-link').unbind().click(function(Event){
                Event.preventDefault();

               var target = $(Event.target).attr('data-target')

               var button = $("input[name='" + target + "']");
               button.trigger('mousedown');
            });

            $('#compare-accordion tr').each(function(){
                    var texts = [];

                    $(this).find('td').each(
                        function(y){
                            texts[y] = $(this).html();
                        }
                    );

                    if($(window).width() < 768 && texts[1] === texts[2]){
                        $(this).addClass('matched');
                    }else if(texts[1] === texts[2] && texts[2] === texts[3]){
                        $(this).addClass('matched');
                    }else if(texts[1] === texts[3] && texts[2] === '&nbsp;'){
                        $(this).addClass('matched');
                    }else if(texts[2] === texts[3] && texts[1] === '&nbsp;'){
                        $(this).addClass('matched');
                    }else if(texts[1] === texts[2] && texts[3] === '&nbsp;'){
                        $(this).addClass('matched');
                    }
                }
            );

            showOnly($('.form-item-show-only input'));

            var allPanels = $('#compare-accordion div.panel');

            $(allPanels).each(
               function(){
                   var totalItems = $(this).find('.panel-body tbody tr');

                   var matchedItems = $(this).find('.panel-body tbody tr.matched');

                   if(totalItems.length === matchedItems.length){
                       $(this).addClass('matched');
                   }
               }
            );

            $('.form-item-show-only input').unbind().click(
                showOnly
            );

            // Update url
            var state = $('#igc-compare-push-state').attr('value');

            if(state){
                history.pushState(null, null, state);
            }

            // Update session storage
            var selected = $('#igc-compare-selected-products').attr('value');

            var category = $('#igc-compare-category').attr('value');

            if(selected && category){
                sessionStorage.setItem('igc_compare_' + category, selected);
            }

            $('#compare-accordion .panel-heading a.plus-minus').unbind().click(
                function(Event){
                     var target = $(this).attr('data-target');

                     $(this).toggleClass('expanded');

                     $(target + ' .collapsible').toggleClass('panel-collapse');
                }
            );

            $('.igc-compare-print-page').unbind().click(
                function(Event){
                    Event.preventDefault();
                    var printCSS = Drupal.settings.igc_compare.comparePrintCSS;

                    $('#block-system-main').printThis({
                        importCSS : true,
                        importStyle : true,
                        loadCSS : printCSS
                    });
                }
            );
        }
    };

    function showOnly(obj){
        var target;

        // passed variable may be jquery or an event
        if(obj.target){
            target = obj.target;
        }else{
            target = obj;
        }

        if($(target).prop('checked') === true){
            $('#compare-accordion').addClass('hide-matched');

            $('.form-item-show-only input').prop('checked', true);
        }else{
            $('#compare-accordion').removeClass('hide-matched');

            $('.form-item-show-only input').prop('checked', false);
        }
    }
})(jQuery);