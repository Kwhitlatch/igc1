(function ($) {
  Drupal.behaviors.igcommerce_utility_articles = {
    attach: function (context, settings) {
      /** 
      * View : Share Block 
      * Onclick of social icon open url in new window  
      */
      $("div.figstrap-social-share .figstrap-share-link").unbind().click(function(event) {
        var additionalclass= $(this).attr('data-additionalclass');
        if(additionalclass !== 'figstrap-mail'){
          var height = $(this).attr('data-height');
          var width = $(this).attr('data-width');
          var scrollbars = $(this).attr('data-scrollbars');
          var url = this.href;
          var strWindowFeatures = "height="+height+",width="+width+",scrollbars="+scrollbars+"";	
          window.open(url, "_blank", strWindowFeatures);
          return false;
        }
      }); 
      //on toc popup model pages set the main navigation to go behind the popup.
      //set the height of popup to whole page content , so that no link from background can be click.
      $(document).ready(function(){

        if($('body').find('.pane-igcommerce-utility-articles-articles-solr-web-card-popup-article').length) {
          $('#navbar').css('position' , 'absolute');
          $('#admin-menu').css('margin' , '0px !mportant');
          //we attched the class as max-width is not gettind added to the container class.
          $('.flukestrap-darwin > .container').addClass("auto-resize-model");
          var margin = $('.modal-dialog').css('margin-top');
          $('#myModal').height($(document).height() + parseInt(margin));
        }
      });
        
/*SOFTWARE DOWNLOADS*/
      // Perform search filter for software downloads
      $('#article-software-downloads-search', context).once(function(){
        var timeout = null;
        
        $(this).on('keyup paste', function() {
          // MIG-1964 remove auto-search
          //searchDownloads();
        });
        //MIG4384 - Search when Enter is pressed
        $(this).keypress(function (e) {
          if (e.which == 13) {
            searchDownloads();
          }       
        });
        $(this).closest('.views-exposed-widgets').find('#edit-submit-search-list-solr').click(function(){
          searchDownloads();
        });
        
        function searchDownloads() {
          var filter = $('#article-software-downloads-search', context).val();
          $.get('/' + Drupal.settings.pathPrefix + "igcommerce_utility_article_software-downloads/search", { filter: filter}, function (data){
            $('.articles-search-results').empty().html(data);
          });
          return;
          // Old code when using autosearch
          clearTimeout(timeout);
          timeout = setTimeout(function () {
            if(filter.length == 0) {
              $('.articles-search-results').empty();
              return;
            }

            //ajax code
            $.get('/' + Drupal.settings.pathPrefix + "igcommerce_utility_article_software-downloads/search", { filter: filter}, function (data){
              $('.articles-search-results').empty().html(data);
            });
          }, 500);
          
        }
      });
    }
  };
  
  Drupal.behaviors.igcommerce_utility_articles_press_release_results = {
      attach: function (context, settings) {
        /*PRESS RELEASE*/
        // Accordion for press release
          $('.press-release-items-content', context).hide();
          $('.press-release-items', context).first().find('.press-release-items-content').show();
          $('.press-release-items-date', context).first().addClass('expanded');
          $('.press-release-items-date', context).on().click(function(e) {
              e.preventDefault(); // prevent the default action
              e.stopPropagation(); // stop the click from bubbling
              // If the panel is closed, open it, and close sibling panels.
              if($(this).next('.press-release-items-content').is(":hidden")) {
                  $('.press-release-items-content').slideUp(); // Close sibling panels
                  $('.press-release-items-date').removeClass('expanded'); // Remove class from sibiling panel
                  $(this).next('.press-release-items-content').slideDown();
                  $(this).addClass('expanded');
              }
              // The panel is already open, so close it and remove the expanded class
              else {
                  $(this).next('.press-release-items-content').slideUp();
                  $(this).removeClass('expanded');
              }
          });
      }
  };
  
  Drupal.behaviors.igcommerce_utility_articles_awards_results = {
      attach: function (context, settings) {
        /*AWARDS*/
        // Accordion for awards
          $('.awards-items-content', context).hide();
          $('.awards-items', context).first().find('.awards-items-content').show();
          $('.awards-items-date', context).first().addClass('expanded');
          $('.awards-items-date', context).on().click(function(e) {
              e.preventDefault(); // prevent the default action
              e.stopPropagation(); // stop the click from bubbling
              // If the panel is closed, open it, and close sibling panels.
              if($(this).next('.awards-items-content').is(":hidden")) {
                  $('.awards-items-content').slideUp(); // Close sibling panels
                  $('.awards-items-date').removeClass('expanded'); // Remove class from sibiling panel
                  $(this).next('.awards-items-content').slideDown();
                  $(this).addClass('expanded');
              }
              // The panel is already open, so close it and remove the expanded class
              else {
                  $(this).next('.awards-items-content').slideUp();
                  $(this).removeClass('expanded');
              }
          });
      }
  };

  Drupal.behaviors.igcommerce_utility_articles_press_release_search = {
      attach: function (context, settings) {
        $('#article-press-release-search', context).once('ajax', function() {
          var timeout = null;
          
          $('#edit-submit-search-list-solr', context).once('ajax', function() {
            $(this).click(function() {
              var filter = $('#article-press-release-search').val();
              $.get('/' + Drupal.settings.pathPrefix + "igcommerce_utility_article_press_release/search", { filter: filter}, function (data){
                $('.articles-search-results').empty().html(data);
                Drupal.behaviors.igcommerce_utility_articles_press_release_results.attach(context, settings);                      
              });
            });
          });
          
          $(this).on('keyup paste', function() {            
            var filter = $(this).val();
            clearTimeout(timeout);
            timeout = setTimeout(function () {
              //ajax code
              console.log(filter);
              // MIG-1964 no auto-search
              //$('#edit-submit-search-list-solr').click();
            }, 500);
            
          });
          //MIG4384 - Search when Enter is pressed
          $(this).keypress(function (e) {
          if (e.which == 13) {
            $('#edit-submit-search-list-solr').click();
          }       
        });
        });
      }
  };
})(jQuery);