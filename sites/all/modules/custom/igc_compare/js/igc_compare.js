(function ($) {
    Drupal.behaviors.igc_compare = {
        attach: function (context, settings) {
            var category = Drupal.settings.igc_compare.termId;

            if(category) {

                igcCompareSelect.initBottomBar();

                var stored = sessionStorage.getItem('igc_compare_' + category);

                try {
                    stored = JSON.parse(stored);
                }catch (e) {
                    console.log('Comparison: Failed to load stored values.');
                    stored = false;
                }

                if (Array.isArray(stored)) {
                    igcCompareSelect.loadFromStorage(stored);
                    igcCompareSelect.renderSelected();
                }

                $('.compare-item input.unprocessed').unbind().click(igcCompareSelect.clickCheckBox).removeClass('unprocessed');
            }
        }
    };

    var arrayRealLength = function(list){
        var len = 0;

        for (var i = 0; i < list.length; i++) {
            if (list[i] !== undefined) {
                len++;
            }
        }

        return len;
    };

    var igcCompareSelect = {
        selected : [],
        maxItems : 3,

        initBottomBar: function () {
            if($(window).width() < 768){
                igcCompareSelect.maxItems = 2;
                var modal_title = Drupal.t('You may compare up to two items at a time.');
                var modal_description = '<p>'+ Drupal.t('Would you like to compare the first two items you selected?') + '</p>';
            }else{
                var modal_title = Drupal.t('You may compare up to three items at a time.');
                var modal_description = Drupal.t('Would you like to compare the first three items you selected?');
            }
            var compare_cta_text = igcCompareSelect.ctaText();

            $('#igc-compare-tooManyModal .modal-header h4').text(modal_title);

            $('#igc-compare-tooManyModal .modal-body').text(modal_description);

            $('#igc-compare-tooManyModal .modal-footer button').text(compare_cta_text);

            $('body').append(
                '<div id="igc-compare-bottom-bar" class="container" style="display: none;">' +
                    '<div id="igc-compare-inner">' +
                        '<div class="igc-compare-selected"></div>' +
                            '<div class="igc-compare-controls">' +
                                '<div class="igc-compare-controls-inner">' +
                                '<button name="igc-goto-compare-page" id="igc-goto-compare-page">' +
                                compare_cta_text +
                                '</button>' +
                                '<span class ="igc-compare-clear-all-wrapper">' +
                                    '<a name="igc-compare-clear-all" id="igc-compare-clear-all" href="javascript:;">' +
                                    Drupal.t('Clear all') +
                                    '</a>' +
                                '</span>' +
                            '</div>' +
                        '</div>' +
                    '</div>' +
                '</div>'
            );

            $('#igc-goto-compare-page').unbind().click(igcCompareSelect.gotoPageClick);

            $('#igc-compare-tooManyModal button.compare-cta').unbind().click(igcCompareSelect.gotoPageClick);

            $('#igc-compare-clear-all').unbind().click(igcCompareSelect.clearAllClick);
        },

        ctaText : function(){
            return Drupal.t('Compare @quantity1 / @quantity2 products',{
                '@quantity1' : igcCompareSelect.selected.length,
                '@quantity2' : igcCompareSelect.maxItems
            });
        },

        loadFromStorage : function(stored){
            igcCompareSelect.selected = stored;

            igcCompareSelect.selected.forEach(
                function(item, index, list){
                    // If coming from the compre page, there may be a Null item, remove the null item before renderingi
                    if(item === null || item.length === 0){
                        list.splice(index, 1);
                        return;
                    }

                    // Remove items that don't appear on the page
                    if($('#compare-item-' + item.id).length  < 1){
                        list.splice(index, 1);
                        return;
                    }
                }
            );

            igcCompareSelect.selected.forEach(function(item, index, list){
               $('input#compare-item-' + item.id).prop('checked', true);
            });

            $('#igc-compare-bottom-bar').show();
        },

        clickCheckBox: function (Event) {
            $('#igc-compare-bottom-bar').show();

            var checkbox = $(Event.target);

            var nid = checkbox.attr('data-nid');

            console.log('Checkbox checked = ' + checkbox.prop('checked'));

            if(checkbox.prop('checked') === true){
                if(arrayRealLength(igcCompareSelect.selected) === igcCompareSelect.maxItems){
                    $('#igc-compare-tooManyModal').modal('show');

                    console.log('unchecking because there are too many checked');
                    checkbox.prop('checked', false);
                }else {
                    igcCompareSelect.addSelection(checkbox);
                }
            }else{
                igcCompareSelect.removeSelection(checkbox);
            }
        },

        addSelection: function(item){
            var jqItem = $(item[0]);

            var selection = {
              'title' : jqItem.attr('data-title'),
              'url' : jqItem.attr('data-url'),
              'image' : jqItem.attr('data-image'),
              'id' : jqItem.attr('data-nid')
            };

            var valid = true;

            igcCompareSelect.selected.forEach(function(current, index, list){
                if(selection.id === current.id){
                    valid = false;
                }
            });

            if(valid) {
                igcCompareSelect.selected.push(selection);
            }

            igcCompareSelect.renderSelected();
        },

        renderSelected : function(){
          var items = '';

          igcCompareSelect.selected.forEach(
            function(current, index, list){
                if(current.length === 0){
                    list.splice(index, 1);
                    return;
                }

                var removeTxt = Drupal.t('Remove');

                items += "<div class = 'compare-selected-item'>" +
                     "<div class='compare-item-remove'><a class='remove-item' data-nid='" + current.id + "' href='javascript:;'>X "+ removeTxt + "</a></div>" +
                     "<div class='compare-item-img'><img src='"+ current.image + "' /></div>" +
                     "<div class='compare-item-title'> <a href='"+ current.url +"' >"+ current.title +"</a></div>" +
                     "</div>";
            }
          );

          $('.igc-compare-selected').html(items);
          $('.compare-selected-item .remove-item').unbind().click(igcCompareSelect.removeSelectionLink);
          $('#igc-compare-bottom-bar button#igc-goto-compare-page').text(igcCompareSelect.ctaText());
          $('#igc-compare-tooManyModal .modal-footer button').text(igcCompareSelect.ctaText());
          $('.compare-item input').unbind().click(igcCompareSelect.clickCheckBox);

          var category = Drupal.settings.igc_compare.termId;

          sessionStorage.setItem('igc_compare_' + category, JSON.stringify(igcCompareSelect.selected));
        },

        removeSelectionLink : function(Event){
            var target = $(Event.target);

            igcCompareSelect.removeSelection(target);
        },

        removeSelection: function(item){
            var id = item.attr('data-nid');

            igcCompareSelect.selected.forEach(
              function(current, index, items){
                if(current.id == id){
                   igcCompareSelect.selected.splice(index, 1);
                }
              }
            );

            $('input#compare-item-' + id).prop('checked', false);

            igcCompareSelect.renderSelected();

            if(igcCompareSelect.selected.length === 0){
                $('#igc-compare-bottom-bar').hide();
            }
        },
        gotoPageClick: function () {
            // take them to the page for comparison

            var path = Drupal.settings.igc_compare.comparePath + '?selected=';

            igcCompareSelect.selected.forEach(
              function(item, index, list){
                  path += item.id;
                  var count = index + 1;
                  if(list.length > count){
                      path += ',';
                  }
              }
            );
            location = path;
        },

        clearAllClick: function () {
            igcCompareSelect.selected.forEach(
              function(item, index, list){
                  var id = item.id;
                  $('input#compare-item-' + id).prop('checked', false);
              }
            );

            igcCompareSelect.selected = [];

            igcCompareSelect.renderSelected();

            $('#igc-compare-bottom-bar').hide();
        }
    };

})(jQuery);