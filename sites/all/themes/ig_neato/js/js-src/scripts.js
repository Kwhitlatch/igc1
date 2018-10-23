(function ($) {
    'use strict';
    Drupal.behaviors.igcommerce_collapsingMenus = {
        attach: function (context, settings) {
            /*  This toggle expects code something like this...
             <div class="custom-collapse">
                <div class="panel-heading">
                    <h4>Title Goes Here
                        <a data-parent="#accordion" href="#" data-toggle="collapse" class="collapsed plus-minus"></a>
                    </h4>
                </div>
                <div class="panel-body">
                    <div class="collapsed panel-collapse">
                        Accordion Guts go here
                    </div>
                </div>
            </div>
            */

            // this just adds classes to the styleguide so that it will work
            // like the rest of menus
            if ($('body.page-admin-appearance-styleguide').length > 0){
                $('#styleguide-header').addClass('custom-collapse');
                $('#styleguide-header h3').addClass('panel-heading').append('<a data-toggle="collapse" data-parent="#accordion" class="collapsed" href="#"></a>');
                $('#styleguide-header .item-list').addClass('collapse');
                $('#styleguide-header .item-list ul').addClass('panel-collapse collapse');
            }

            var collapseGroups = ['.panel-group', '.custom-collapse'];



            var buildToggle = function(menuGroup, menuTrigger, collapsible){
                var openMenus;
                var openHeight;


                $(menuTrigger).each(function(index, value){

                    // Prevent the href from just going to its link
                    $(this).unbind().on('click', function menuToggle (e){

                        // THIS AFFECTS ALL ACCORDIONS THAT HAVE A BUTTON TO OPEN THEM

                        if ($(e.target).is('button') || ($(e.target).parent().is('button'))){
                            $(e.target).parent().next(collapsible).slideToggle({easing: 'swing'});
                            $(e.target).next(collapsible).slideToggle({easing: 'swing'});
                            $(window).scrollTo(-100, 100);
                        }

                        // THIS AFFECTS ALL ACCORDIONS THAT HAVE A PLUS/MINUS
                        // IN PARTICULAR, THESE AFFECT THE SIDEBAR MENUS

                        else if ($(e.target).is('a') && $(e.target).hasClass('plus-minus')){
                            e.preventDefault();


                            // find all of the items with class expanded
                            openMenus = $(menuGroup).find('.expanded');
                            console.log($(menuGroup));

                            // for each expanded item, if they have an href property attached,
                            // remove the expanded wrapper and expanded classes

                            $(openMenus).each(function(index,value){
                                if ($(e.target).prop('href') !== $(value).prop('href')){
                                    openHeight = $(value).parent().next().outerHeight(true);
                                    $(value).parent().next().slideUp();
                                    $(value).parent().removeClass('expanded-wrapper');
                                    $(value).removeClass('expanded');
                                }
                            });

                            // add the class expanded, expanded wrapper
                            // toggle the next child

                            $(e.target).toggleClass('expanded');
                            $(e.target).parent().toggleClass('expanded-wrapper');
                            $(e.target).parent().next(collapsible).slideToggle({easing: 'swing'});

                            if (openHeight !== undefined){
                                console.log('openHeight');
                                $(window).animate({

                                    scrollTop: $(e.target).parent().offset().top - openHeight - 200
                                });
                            }


                        }

                        // THIS AFFECTS ALL ACCORDIONS THAT MIGHT BE INSIDE CONTENT
                        // Added .collapsed to the a, as it was preventing anchors in contents from working. -RRN
                        else if ($(e.target).is('a.collapsed') && $(e.target).data('toggle') == 'collapse'){
                            if ($(e.target).parents('.panel-group').length > 0){
                                $(e.target).parents('.panel-group').each( function(index,value){
                                    if ($(value).attr('aria-multiselectable')== 'true'){
                                        e.preventDefault();

                                    }
                                });

                            }
                            $(e.target).toggleClass('expanded');
                            $(e.target).parent().parent().toggleClass('expanded-wrapper');
                            $(e.target).parent().parent().next(collapsible).slideToggle({easing: 'swing'});
                            // $(window).scrollTo(-100, 100);

                        }
                    });
                })
            };

            $(collapseGroups).each(function(index,value){
                var menuGroup = $(value);
                var menuTrigger = menuGroup.find('a, button').data('toggle', 'collapse');
                var collapsible = '.collapse';

                buildToggle(menuGroup, menuTrigger, collapsible);

            });


        }
    };

    // Drupal.behaviors.igcommerce_languagePickerToggle = {
    //     attach: function (context, settings) {
    //
    //         var countryBlock = $('#block-views-country-picker-block');
    //         var pickerToggle = $('.language-picker');
    //
    //         $(countryBlock).hide();
    //
    //         $(document).click(function(e) {
    //
    //             if( $(e.target).parents('.language-picker-wrapper').length < 1 || $(e.target).hasClass('.language-picker-wrapper') == false ) {
    //                 $(countryBlock).hide();
    //                 $('.language-picker-wrapper').removeClass('active');
    //             }
    //
    //         });
    //
    //         $(pickerToggle).on('click', function languageToggle(e){
    //
    //             $('.language-picker-wrapper').addClass('active');
    //             $(countryBlock).slideDown();
    //         });
    //
    //
    //     }
    // };
    Drupal.behaviors.igcommerce_main_search_toggle = {
      attach: function (context, settings) {
        //MIG2063 - Changed to window.load to prevent bubbling -> $(document).ready(function () {
        $(window).load(function () {
            
        // When you click on the search icon, the search box will slidedown
        // and the icon gets an .active class to turn it yellow.
          $('.search-opener').click(function() {
            $('#mmenu_right').mmenu().trigger("close.mm"); //Close mobile navigation if search is clicked.
            $('#main-search').slideToggle('fast');
            $(this).toggleClass('active');
            if ($(this).hasClass('active')) {
                // Sets focus on the search input box
                $('#edit-search-block-form--2').focus();
                // Uses the jquery-clickout.js function to close the search 
                // box if you click outside the parent element
                $('#main-search, .search-opener').on('clickout', function (e) {
                  //console.log('click outside button');
                  $('#main-search').slideUp('fast');
                  $('.search-opener').removeClass('active');
                  $('#main-search, .search-opener').off('clickout');
                });
            } else {
                $('#main-search, .search-opener').off('clickout');
            }
            // If you scroll down the page after opening search, search will close
            $(window).bind("scroll", function() {
              if ($(window).scrollTop() > 60) {
                $('#main-search').slideUp('fast');
                $('.search-opener').removeClass('active');
                $('#main-search, .search-opener').off('clickout');
              }
            });
          });
        });
      }
    };


    Drupal.behaviors.igcommerce_languagePickerToggle = {
      attach: function (context, settings) {
        $(document).ready(function () {
        /** 
         * Controls language picker tab visiblity.
         * Adapted from http://refills.bourbon.io/ accordion-tabs-minimal example  
         */
        $('.accordion-tabs-minimal').on('click', 'li > a.tab-link', function(event) {
          if (!$(this).hasClass('is-active')) {
            event.preventDefault();
            var accordionTabs = $(this).closest('.accordion-tabs-minimal');
            accordionTabs.find('.is-open').removeClass('is-open').hide();

            $(this).next().toggleClass('is-open').toggle();
            accordionTabs.find('.is-active').removeClass('is-active');
            $(this).addClass('is-active');
          } 
          else {
            event.preventDefault();
          }
        });

        var countryBlockMobile = $('#country-picker-mobile');
        var countryBlockDesk = $('#flat-country-picker-block');
        var pickerToggle = $('.language-picker');
        var isMobile;
        var currentSelector;

        var indicatorCheck = function(){
          if ($('#mobile-indicator').css("display") == "none"){
            isMobile = false;
            currentSelector = countryBlockDesk;
          } 
          else {
            isMobile = true;
            currentSelector = countryBlockMobile;
          }
        };
        var boxCloser = function boxCloser(e){
          if ($(e.target).parents(currentSelector.selector).length < 1) {
            document.body.removeEventListener('click', boxCloser, false);
            $(currentSelector).slideUp('fast');
            $('.language-picker').removeClass('active');
            //Added default mmenu classes to html to prevent scrolling.
            $('body').removeClass('lang-overflow');
          }
        }
        var toggler = function(selector){
          $(pickerToggle).click(function(){
            $('#mmenu_right').mmenu().trigger("close.mm"); //Close mmenu on
            $('.language-picker').addClass('active');
            //Added default mmenu classes to html to prevent scrolling.
            $('body').addClass('lang-overflow');
            $(selector).slideDown('fast', function(){
              document.body.addEventListener('click', boxCloser, false);
              deskCloseOnScroll();
            });
          });
        };
        $(window).resize(function (e){
          indicatorCheck();
          
          // Prevents the main nav from getting stuck open when the user 
          // resizes the window.
          $('#mmenu_right').mmenu().trigger("close.mm");
          $('.navbar-toggle').removeClass('active');

          if (isMobile === true) {
            currentSelector = countryBlockMobile;
          }
          else {
            currentSelector = countryBlockDesk;
          }
          countryBlockMobile.removeAttr('style');
          countryBlockDesk.removeAttr('style');
          document.body.removeEventListener('click', boxCloser, false);
          $(pickerToggle).unbind();
          toggler(currentSelector);
        });

        // This watches the scrolling, and will fire off close if it drops
        // below 30px. This code was used to test the deskCloseOnScroll
        // function, and was left here for reference. -RRN
        // below 30px
        // $(window).scroll(function () {
        //   if ($(window).scrollTop() > 30) {
        //     boxCloser(false);
        //   }
        //   console.log($(window).scrollTop());
        // });

        // Closes the desktop language picker on scroll. Function
        // is called ONLY when the language picker is opened. -RRN
        // The scroll is not unbound afterward, because it would break .js
        // in other drupal modules that is bound to scroll.
        function deskCloseOnScroll(){
          if (isMobile === false) {
            $(window).bind("scroll", function() {
              if ($(window).scrollTop() > 30) {
                boxCloser(false);
              }
            });
          } 
        }

        indicatorCheck();

        toggler(currentSelector);

      });
    }
    };

    Drupal.behaviors.igcommerce_languagePickerMobileMenu = {
        attach: function (context, settings) {
            $(document).ready(function( $ ) {
                $("#country-picker-mobile").mmenu();
            });
        }
    };

    // Adds/removes active class to mmenu toggle. Clickout to mimic language
    // picker and search button functionality.
    Drupal.behaviors.igcommerce_main_burger_toggle = {
      attach: function (context, settings) {
        $(document).ready(function () {
          $('.navbar-toggle').click(function() {
            $(this).toggleClass('active');
            //Opens MMenu right - added here to prevent bug if mmenu is close with lang or search.
            $('#mmenu_right').mmenu().trigger("open.mm");
            if ($(this).hasClass('active')) {
                $('.navbar-toggle').on('clickout', function (e) {
                  $('.navbar-toggle').removeClass('active');
                });
            } 
          });
        });
      }
    };

    // MMenu is adding a counter of 0 to menu items with their children hidden. The > href is also bringing
    // us to a blank menu page, rather than the toc (Accessories and Intrinsically safe for example)
    // This removes the 0 counter, and the href for these items
    Drupal.behaviors.igcommerce_counterMobileMenu = {
      attach: function (context, settings) {
        $(document).ready(function( $ ) {
          var searchText = '0';

          $('em.mm-counter').filter(function () {
            return $(this).text() === searchText;
          }).next().remove(); //Removed href after '0' counter to prevent linking to blank child
          $('em.mm-counter').filter(function () {
            return $(this).text() === searchText;
          }).remove(); //Removed '0' counter
        });
      }
    };


    // Wraps all Copyright(©) and Registered(®) symbols in superscript tags.
    // The Trademark(™) html entity is superscripted by default, so it is omitted.
    // Based on this fiddle: http://jsfiddle.net/QTfxC/1/
    // Origionally found in this thread: https://stackoverflow.com/questions/19364581/adding-superscript-sup-tags-around-all-trademark-and-registered-trademark-symb
    // UPDATE: This script caused problems in ie11, it was causing Bazaarvoice to take 2-10 minutes to load.
    // I increased the specifity of the selector from body :not(script, sup, iframe)
    // to what it is now.  Mmenu was somehow involved in that mayhem, not sure exactly what went wrong, but this fixes it. RRN 9-14-18
    Drupal.behaviors.igcommerce_copyrightsuperscript = {
      attach: function (context, settings) {
        $(document).ready(function( $ ) {
          $('body :not(script, sup, iframe) .main-container, footer').contents().filter(function() {
              return this.nodeType === 3;
          }).replaceWith(function() {
              return this.nodeValue.replace(/[®©]/g, '<sup>$&</sup>');
          });
        });
      }
    };

    // Allows tabbing through main navigation flyout menus.
    // Applies accessability-tab class to top level, mimicing a hover effect
    //jQuery(document).ready(function($) {
    //
    //    $('.region-navigation').on('mouseenter focus', '.nav.navbar-nav > .dropdown', function(e) {
    //        var el = $(this);
    //        el.toggleClass('accessability-tab');
    //        // Show sub-menu
    //        el.parents('.dropdown-toggle').attr('aria-expanded', 'true');
    //    }).on('mouseleave blur', '.nav.navbar-nav > .dropdown', function(e) {
    //        var el = $(this);
    //        el.toggleClass('accessability-tab');
    //        // Only hide sub-menu after a short delay, so links get a chance to catch focus from tabbing
    //        setTimeout(function() {
    //            if (el.siblings('.nav.navbar-nav').attr('data-toggle') !== 'true') {
    //                el.parents('.dropdown-toggle').attr('aria-expanded', 'false');
    //            }
    //        }, 100);
    //    }).on('mouseenter focusin', '.nav.navbar-nav', function(e) {
    //        var el = $(this);
    //        el.attr('data-toggle', 'true');
    //    }).on('mouseleave focusout', '.nav.navbar-nav', function(e) {
    //        var el = $(this);
    //        setTimeout(function() {
    //            // Check if anything else has picked up focus (i.e. next link in sub-menu)
    //            if (el.find(':focus').length === 0) {
    //                el.attr('data-toggle', 'false');
    //                // Hide sub-menu on the way out if parent link doesn't have focus now
    //                if (el.siblings('.dropdown.accessability-tab').length === 0) {
    //                    el.parents('.dropdown').attr('aria-expanded', 'false');
    //                }
    //            }
    //        }, 100);
    //    });
    //});
  

}(jQuery));
console.log("scripts");
//# sourceMappingURL=maps/scripts.js.map


