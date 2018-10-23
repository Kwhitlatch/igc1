
(function ($) {
  Drupal.behaviors.igcommerce_utility_products = {
    attach: function (context, settings) {
      /**
       * Custom Js for Product Slideshow
       * On Page Load Flexslider Intilize
       */


      $(document).ready(function() {

        // tiny helper function to add breakpoints
        function getGridSize() {
          return (window.innerWidth < 576) ? 2 :(window.innerWidth < 1033) ? 3 : 4;
        }

        // Instantiates the image zooming from elevatezoom
        function startZoom() {
           $('.zoom.flex-active-slide img').elevateZoom({
           // gallery:'ig-product-flexslider', 
           //  galleryActiveClass: 'active-slide',
            //galleryActiveClass: 'flex-active-slide',
            zoomWindowFadeIn: 500,
            zoomWindowFadeOut: 500,
            easing : true,
            cursor: 'pointer', 
            imageCrossfade: true,
            zoomWindowWidth:500,
            zoomWindowHeight:400
          });
        }

        // Handles window resizing for Overview image zooming.
        $(window).on("resize", function() {
          if (getGridSize() == 4) {
            if($('.zoomContainer').length == 0) {
              startZoom();
            }
          } else {
            $('.zoomContainer').remove();
          }
        });

        // Product Slideshow
        // Also starts up the imagezooming after the slider loads on desktop 
          $('.ig-product-flexslider').flexslider({
            // animation: "slide", // the slide animation breaks the zoom, so we have to use fade instead.
            animation: "fade",
            controlNav: "thumbnails",
            slideshow: false,
            animationLoop: false,
            start: function() {
              if (getGridSize() == 4) {
              startZoom();
              }
            },
            before: function(){
              if (getGridSize() == 4) {
                $('.zoomContainer').remove();
              }
            },           
            after: function(){
              if (getGridSize() == 4) {
                startZoom();
              }
            },  
          });

         //Product  Overview Slideshow
        $('.ig-overview-flexslider').flexslider({
          animation: "slide",
          controlNav: false,
          slideshow: false,
          animationLoop: false,          
        });

        // Related Product & Top-pick accessory Slideshow
        $('.ig-related-flexslider').flexslider({
          animation: "slide",
          animationLoop: false,
          slideshow: false,
          controlNav: false,
          itemWidth: 111, 
          // itemMargin: 5,
          //minItems: 2,
          //maxItems: 4
          minItems: getGridSize(), // use function to pull in initial value
          maxItems: getGridSize() // use function to pull in initial value
        });
        $(window).on("resize", function(){
          if($('.ig-related-flexslider .ig-related-flexslider').length > 0) {
            var gridSize = getGridSize();
            flexslider.vars.minItems = gridSize;
            flexslider.vars.maxItems = gridSize;
          }
        });

        // If pricespider for a model fails, reveal a link to the online store if one exists
        $('.product-model a.hide.buy-now-cta').each(
          function(){
            var model = $(this).closest('.product-model');

            var ps = $(model).find('.ps-widget');

            if($(ps).hasClass('ps-no-sku')){
              $(this).removeClass('hide');
            }else if(!$(ps).hasClass('ps-enabled')){
                setTimeout(modelPriceSpiderCheck, 1000, ps, this);
            }
          }
        );

        // When clicking the manual link, this will open the tab and scroll to the section.
        $( "#fluke-product-display-manuals" ).click(function() {
          var gridSize = getGridSize();
          // Mobile
          if(gridSize <= 3) {
            $('#resources-tab-collapse').collapse('show');
          } else {
          // Desktop
            $('#myTab a[href="#resources-tab"]').tab('show');
            $('#resources-accordion #fluke-product-display-manuals-title .collapsed').click();
          }
          // Scrolling for both mobile and desktop.
          $(window).scrollTo('#resources-label', {
            axis: 'y',
            duration: 800
          });
        });

        // By default, the 'Product Overview' tab is hardcoded as active, so that
        // desktop users don't see a weird layout while waiting for tab logic to
        // apply. Some tabs don't have an overview tab, so this logic will set
        // the first tab to display after page load.
        // For mobile devices, we want to load the page with accordions closed.
        // We strip off the tags that are used to hardcode 'active' before the 
        // accordion is instantiated.
        // When colorbox opens a model, the browser perceives it as an 'onload' 
        // event. This caused the tabs to reset when a modal was opened, so we
        // added the colorbox display check logic. -RRN 9-34-18
        if (getGridSize() == 4 && $('#colorbox').css('display') !== 'block') {
          $('#myTab a:first').tab('show');
        } else {
          $('#overview-tab').removeClass('active in');
          $('.overview-list-item').removeClass('active');
        }
        
        // This is mostly for Fluke reviewers, when they resize the window it resets to the first tab.
        $(window).on("resize", function() {
          if (getGridSize() == 4) {
            $('#myTab a:first').tab('show');
          }
        });

        // Instantiates tab-collapse for mobile and tablet devices
        $('#myTab').tabCollapse({
            tabsClass: 'hidden-tabs',
            accordionClass: 'visible-accordion'
        });

        // On mobile and tablet, some resources and related products accordions should be fully open.
        // We're borrowing the gridSize() function used for slideshows to get the screen width.
        if($('#resources-accordion').length > 0) {
          var gridSize = getGridSize();
          //console.log(gridSize);
          if(gridSize <= 3) {
            $('#resources-accordion .collapse').collapse('show');
          } else {
            $('#resources-accordion .collapse').collapse('hide');
          }
        }
        if($('#accessory-accordion').length > 0) {
          var gridSize = getGridSize();
          if(gridSize <= 3) {
            $('#accessory-accordion .collapse').collapse('show');
          } else {
            $('#accessory-accordion .collapse').collapse('hide');
          }
        }
        if($('#accessories-compatible-products-accordion').length > 0) {
          var gridSize = getGridSize();
          if(gridSize <= 3) {
            $('#accessories-compatible-products-accordion .collapse').collapse('show');
          } else {
            $('#accessories-compatible-products-accordion .collapse').collapse('hide');
          }
        }


        // this sets the accordions on page resize
        $(window).on("resize", function(){
          if($('#resources-accordion').length > 0) {
            var gridSize = getGridSize();
            //console.log(gridSize);
            if(gridSize <= 3) {
              $('#resources-accordion .collapse').collapse('show');
            } else {
              $('#resources-accordion .collapse').collapse('hide');
            }
          }
          if($('#accessory-accordion').length > 0) {
            var gridSize = getGridSize();
            if(gridSize <= 3) {
              $('#accessory-accordion .collapse').collapse('show');
            } else {
              $('#accessory-accordion .collapse').collapse('hide');
            }
          }
          if($('#accessories-compatible-products-accordion').length > 0) {
            var gridSize = getGridSize();
            if(gridSize <= 3) {
              $('#accessories-compatible-products-accordion .collapse').collapse('show');
            } else {
              $('#accessories-compatible-products-accordion .collapse').collapse('hide');
            }
          }
        });
      });


      // Get first datasheet from Resources section
      var first_datasheet = $('#datasheets-ul').first().find('a').attr('href');
      if($('#datasheets-ul').length) {
        $('#specification_link').attr('href',first_datasheet);
      }else{
        $('#specification_link').hide();
      }

      // Translations for the 'read more' and 'read less' buttons
      var readMoreTranslated = Drupal.t('Read more');
      var readLessTranslated = Drupal.t('Read less');
      
      // Add Read more& Less for Key Feature
      // uses the readmore.js library
      $('#keyfeature_content').readmore({
        speed: 150,
        moreLink: '<a class="event-features" href="#">' + readMoreTranslated + '</a>',
        lessLink: '<a href="#.">' + readLessTranslated + '</a>',
        collapsedHeight:150,
        afterToggle: function(trigger, element, expanded) {
          if(! expanded) { // The "Close" link was clicked
            $('html, body').animate( { scrollTop: element.offset().top - 175 }, {duration: 600 } );
          }
        }
      });

      // Fixes Aria toggling for accordions in Accessories and Related sections
      // Must be wrapped in a function tag, otherwise it executes too early.
      // $(function() {
      //   $('.panel-group h4 > a').click(function(){
      //     if ($(this).attr('aria-expanded') == 'true') {
      //       $(this).attr('aria-expanded', false);
      //     } else {
      //       $(this).attr('aria-expanded', true);
      //     }
      //   });
      // });

      // Models accordions
      $('.ig-product-models .accordion').click(function(){
        if( $(this).siblings('.panel').is( ":hidden" )) {
          $(this).siblings('.panel').slideDown("fast");
        } else {
          $(this).siblings('.panel').slideUp("fast");
        }
      });
      
      var acc = document.getElementsByClassName("accordion");
      var i;
      for (i = 0; i < acc.length; i++) {
        acc[i].onclick = function(){
          this.classList.toggle("active");
        }
      }

    } 
  };

  function modelPriceSpiderCheck(priceSpider, onlineStore){
    if($(priceSpider).hasClass('ps-no-sku')){
      $(onlineStore).removeClass('hide');
    }else if(!$(this).hasClass('ps-enabled')){
      setTimeout(modelPriceSpiderCheck, 1000, priceSpider, onlineStore);
    }
  }
})(jQuery);
