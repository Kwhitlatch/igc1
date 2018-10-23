(function ($) {
    'use strict';
    Drupal.behaviors.igcommerce_tocs = {
        attach: function (context, settings) {
            $('h3.slider-trigger').once('myslider', function() {
                $('h3.slider-trigger').click(function(){
                    $('.slider').slideToggle();
                });
            });

            var lastAdded, originalItems;
            if (typeof console !== "undefined"){
                console.log("Module loaded file");
            }
            $('.quicktabs-tabpage', context).each(function () {
                var shown =  10;
                $(this).find('.row:lt('+ shown +')').show();
                $(this).find('#showLess').hide();
                var items =  $(this).find('.row').size();
                if (typeof console !== "undefined"){
                    var id = $(this).attr('id');
                    console.log("Div " + id + " has (" + items + ") total items");
                }
                if(items <= 9) {
                    $(this).find('#loadMore').hide();
                    $(this).find(".total_loaded").text(items);
                }
                if (items > 1) {
                  $(this).find(".number_of_items").css("display", "inline-block");
                  $(this).find(".total_items").text(items);
                }
                if(items >= 10) {
                    $(this).find('#loadMore').css("display", "inline-block");
                    $(this).find(".total_loaded").text(shown);
                }

                $(this).children().find( "#loadMore" ).once().on({
                    click: function() {

                        if (typeof console !== "undefined"){
                            console.log("LoadMore clicked");
                        }
                        var loadMore = $(this);
                        items =  loadMore.parents('.quicktabs-tabpage').find('.row').size();
                        shown = loadMore.parents('.quicktabs-tabpage').find('.row:visible').size()+10;

                        loadMore.parents('.quicktabs-tabpage').find(".total_loaded").empty().text(shown);
                        // Add less to number of loaded items
                        var remaining = loadMore.parents('.quicktabs-tabpage').find('.row:hidden').size()
                        if(remaining < 10) {
                          loadMore.parents('.quicktabs-tabpage').find(".total_loaded").empty().text(items);
                          loadMore.parents('.quicktabs-tabpage').find('#showLess').css("display", "inline-block");
                        }

                        if(shown >= items) {
                            loadMore.parents('.quicktabs-tabpage').find('#showLess').css("display", "inline-block");
                        }
                        if(shown < items) {
                            loadMore.parents('.quicktabs-tabpage').find('.row:lt('+shown+')').slideDown( 'fast', function() {
                                var lastshown = loadMore.parents('.quicktabs-tabpage').find('.row:visible').size();
                                loadMore.parents('.quicktabs-tabpage').find('#showLess').css("display", "inline-block");
                                if(lastshown >= items) {
                                    loadMore.hide();
                                }
                            });
                        }
                        else {
                            loadMore.parents('.quicktabs-tabpage').find('.row:lt('+items+')').slideDown("fast");
                            loadMore.hide();
                        }
                    }
                });

                $(this).children().find( "#showLess" ).once().on({
                    click: function() {

                        if (typeof console !== "undefined"){
                            console.log("Showless clicked");
                        }
                        var showLess = $(this);
                        items =  showLess.parents('.quicktabs-tabpage').find('.row:visible').size();

                        // Hide items not divisible by 10 first
                        if(items > 10) {
                          var itemsDivided = items / 10;
                          if(itemsDivided % 1 == 0) {
                            // Check for older IE browser
                            items = (items-10<0) ? shown : items-10;
                            showLess.parents('.quicktabs-tabpage').find('.row').not(':lt(' + items + ')').slideUp(1000, function() {
                              items = showLess.parents('.quicktabs-tabpage').find('.row:visible').size();
                              $(this).parents('.quicktabs-tabpage').find(".total_loaded").empty().text(items);

                              if(showLess.parents('.quicktabs-tabpage').find('.row:visible').size() <= 10) {
                                  showLess.hide();
                              }

                            });
                          }
                          else {
                            items = itemsDivided.toString().split('.')[1];
                            showLess.parents('.quicktabs-tabpage').find('.row:visible').slice(-items).slideUp(1000, function() {
                              items = showLess.parents('.quicktabs-tabpage').find('.row:visible').size();
                              showLess.parents('.quicktabs-tabpage').find(".total_loaded").empty().text(items);
                            });
                          }
                        }

                        showLess.parents('.quicktabs-tabpage').find('#loadMore').css("display", "inline-block");

                    }

                });
            });
        }
    }

}(jQuery));
