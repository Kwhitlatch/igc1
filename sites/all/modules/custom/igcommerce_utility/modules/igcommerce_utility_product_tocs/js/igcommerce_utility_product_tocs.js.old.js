(function ($) {
    'use strict';
    Drupal.behaviors.igcommerce_tocs = {
        attach: function (context, settings) {
            // Function to show all on the page
            var showAll = function (page) {
                if (typeof console !== "undefined"){
                    console.log(page.attr('class'));
                }
                page.find('.toc_product_item').show();
            }

            var limitVisible = function() {
              $('.quicktabs-tabpage', context).on().each(function () {
              //$('.paginate', context).on().each(function () {
                  var shown = 10;
                  var totalPages, previousPage, currentPage, nextPage, showNextHighestItemNumber, totalPagesFloat, last_visible_element, floatNumber;
                  var paginationLinks = '';
                  var currentPage = 1;
                  var tabContent = $(this);

                  // Only show first 10
                  tabContent.find('.toc_product_item:lt('+ shown +')').show();
                  var items =  $(this).find('.toc_product_item').size();
                  // Add total number of items
                  if (typeof console !== "undefined"){
                      var id = $(this).attr('id');
                      console.log("Div " + id + " has (" + items + ") total items");
                  }

                  if(items <= shown) {
                      totalPages = 1;
                  }
                  if (items > 1) {
                      $(this).find(".number_of_items").css("display", "inline-block");
                      $(this).find(".total_items").text(items);
                  }
                  if(items >= (shown + 1)) {
                      totalPages = Math.ceil(items / shown);
                      totalPagesFloat = items / shown;
                      currentPage = 1;
                      nextPage = currentPage + 1;

                      // Get the decimal number
                      floatNumber = parseInt(totalPagesFloat.toString().split('.')[1]);
                      // Variable for default active state
                      //var active = '';
                      for (var i = 1; i < (totalPages + 1); i++) {
                          var active = (i == 1) ? " list_active_page" : "";
                          paginationLinks = paginationLinks + '<a href="#page:' + i + '" title="Page ' + i + '" rel="' + i + '" class="toc-page-link' + active + '">' + i + '</a>';
                      }
                      var showAllButton = Drupal.t('Show all');
                      paginationLinks = paginationLinks + '<span class="toc_show_all"><button value="Show all">' + showAllButton + '</button></span>';
                  }

                  // Add pagination
                  $(this).find('.pagination').html(paginationLinks);
                  // Sort by date created
                  //sortResults(tabContent, 'newest');
                  // Add click function for each page number
                  $(this).on("click",  "a.toc-page-link",  function() {

                      if (typeof console !== "undefined"){
                          console.log("Total pages" + totalPages);
                          console.log("Total pages Float" + totalPagesFloat);
                          console.log("Page clicked: " + $(this).text());
                      }
                      showNextHighestItemNumber = $(this).text() * shown;
                      // Hide everything
                      tabContent.find('.toc_product_item').not('.product-list-toolbar').hide();

                      // Get the last visible element
                      if (typeof(totalPages) != "undefined" && totalPages !== null) {
                          if (typeof console !== "undefined"){
                              console.log('Total Pages Set to: ' + totalPages);
                          }
                          // Then show the selected page content if divisible by 10
                          //if (showNextHighestItemNumber < items && (showNextHighestItemNumber / 10)  % 1 == 0) {
                          if (parseInt($(this).text()) === 1) {
                              tabContent.find('.toc_product_item:lt(10)').show();
                          }
                          if ((showNextHighestItemNumber / shown)  % 1 == 0 && parseInt($(this).text()) > 1) {
                              var lastItem = $(this).parents('.paginate').find('.toc_product_item:visible:last');
                              var lowestNumberToShow = showNextHighestItemNumber - shown;
                              if (typeof console !== "undefined"){
                                  console.log('Showing index: ' + tabContent.find( ".toc_product_item:nth-child("+ lowestNumberToShow +")").index() + ' - ' + tabContent.find( ".toc_product_item:nth-child("+ showNextHighestItemNumber +")").index());
                              }
                              $(this).parents('.paginate').find(".toc_product_item:nth-child("+ lowestNumberToShow +")").nextUntil('.toc_product_item:nth-child('+ (showNextHighestItemNumber + 1) +')' , "li.toc_product_item" ).show();
                          }
                          // If we have reached the last set of items and the are less than ten
                          // Then get the last number and show down to the least number divisible by 10
                          if (totalPagesFloat % 1 != 0 && floatNumber < shown && parseInt($(this).text()) === items) {
                              if (typeof console !== "undefined"){
                                  console.log('Total items to show last: ' + floatNumber);
                              }
                              $(this).parents('.paginate').find('.toc_product_item:nth-last-child(-n+' + floatNumber + ')').show();
                          }
                          currentPage = $(this).text();
                      }
                      $(this).parent().find(".toc-page-link").removeClass('list_active_page');
                      $(this).addClass('list_active_page');

                  });

                  // Click function to show all on the page
                  $(this).on("click",  "span.toc_show_all button",  function() {
                      showAll(tabContent);
                  });

                  //$('#toc-pager').html();

                  // Add result sort functionality
                  // $(this).on("change",  "select.selSort",  function(e) {
                  //     e.preventDefault(); // prevent the default action
                  //     e.stopPropagation(); // stop the click from bubbling
                  //     var sortValue = $('option:selected',this).val();
                  //     var prod_type = $(this).data('type');
                  //     var original_path = $(this).data('originalpath');
                  //     sortResults(tabContent, sortValue, prod_type, original_path);
                  // });

                  // Add result filter functionality
                  $(this).on("keyup",  "input.searchKeyWords",  function() {
                      searchFilterResults(this);
                  });
              });
            };

            // Add result sort functionality
            $('select.selSort').on("change",  function(e) {
                e.preventDefault(); // prevent the default action
                e.stopPropagation(); // stop the click from bubbling
                var sortValue = $('option:selected',this).val();
                var prod_type = $(this).data('type');
                var original_path = $(this).data('originalpath');
                sortResults(this, sortValue, prod_type, original_path);
            });

            var sortResults = function (tabContent, sortValue, prod_type, original_path) {
                $.get("/igcommerce_utility_product_tocssort", { sort_type: sortValue, prod_type: prod_type, original_path: original_path, ajax_sort: 'sort'}, function (data){
                    //console.log(data);
                    // $(tabContent).find('ul').first().empty().html(data);
                    // $(tabContent).find('ul:nth-child(2) > a:first-child').trigger( "click" );

                    $(tabContent).parents('.quicktabs-tabpage').find('.toc-listing-content').empty().html(data);
                    limitVisible();
                    $(tabContent).parents('.quicktabs-tabpage').find('.toc-listing-content ul:nth-child(2) > a:first-child').trigger( "click" );
                    return false;

                });
            };

            var searchFilterResults = function (filterValue) {
                // Search accessories function
                // Retrieve the input field text and reset the count to zero
                var filter = $(filterValue).val(), count = 0;
                // Loop through the products list
                // Check for older IE browser
                if (typeof console !== "undefined"){
                    console.log($(filterValue).val().length);
                }
                if($(filterValue).val().length > 2) {
                    $(filterValue).parents('.quicktabs-tabpage').find(".toc_product_title").each(function(){

                        // If the list item does not contain the text phrase fade it out
                        if ($(this).text().search(new RegExp(filter, "i")) < 0) {
                            $(this).parents('.toc_product_item').fadeOut();

                            // Show the list item if the phrase matches and increase the count by 1
                        } else {
                            $(this).parents('.toc_product_item').show();
                            count++;
                        }
                    });
                }

                // Update the count
                var numberItems = count;
                var countDiv = '#' + $(filterValue).parents('.quicktabs-tabpage').attr('id');
                $('a[href="'+countDiv+'"] .toc_total_products').text("(" + numberItems + ")");
                limitVisible();
            };

            limitVisible();
        }
    }
}(jQuery));
