(function ($) {
  Drupal.behaviors.igcommerce_utility_library_form = {
    attach: function (context, settings) {
      var filterForm = $('form[id*="igcommerce-utility-solr-form-filters"]', context);      
      var searchForm = $('form[id*="igcommerce-utility-solr-search-form"]', context);
      var submit;
      var hasFilters = $('form[id*="igcommerce-utility-solr-form-filters"] input[name*="filters"]').length;
      
      // Set submit to filter form if filter form exists, otherwise make it keyword
      // search form. 
      if (hasFilters) {
        submit = $(filterForm).find('input[id="edit-filter"]');
      } else {
        submit = $(searchForm).find('input[id="edit-search"]');
      }
        
      // Submit the form when filters are changed.
      $(filterForm).find('select, input[type="checkbox"]').change(function() {
        submitForm();
      });
      
      // Submit the filter form
      function submitForm() {                
        $(submit).click();   
        $(submit).attr('disabled', 'disabled');
      }
      
      // Update filter form with keyword/facets and use filter form submit for keyword search
      $(searchForm).submit(function(e) {        
        if (hasFilters) {
          e.preventDefault();
          var keyword = $(searchForm).find('input[name="keyword"]').val();
          $(filterForm).find('input[name="keyword"]').val(keyword);
          
          $(searchForm).find('div[id*="edit-facets"] input[type="checkbox"]').each(function(){
            var name = $(this).attr('name');
            var value = $(this).prop('checked');
            $(filterForm).find('input[name="' + name + '"]').prop('checked', value);
          });
        }
        submitForm();
      });
      
      $('select.search-sort').once(function() {
        $(this).change(function() {
          var sort = $(this).val();
          $(filterForm).find('input[name="sort"]').val(sort);
          submitForm();
        });
      });
      
      // Accordion
      $(filterForm).find('.accordion').once(function(){
        var isActive = $(this).attr('data-state') == 'active' ? 0 : false;
        $(this).accordion({
          collapsible: true,
          active: isActive
        });
      });
    }
  };
})(jQuery);