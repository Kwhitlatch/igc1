(function ($) {
  Drupal.behaviors.igcommerce_utility_library_form = {
    attach: function (context, settings) {
      var form = $('form[id*="igcommerce-utility-training-form-filters"]', context);
      var submit = $(form).find('input[id*="edit-filter"]');
      var searchForm = $('form[id*="igcommerce-utility-training-form-search"]', context);
        
      // Submit the form when filters are changed.
      $(form).find('select, input[type="checkbox"]').change(function() {
        submitForm();
      });
      
      // Submit the filter form
      function submitForm() {                
        $(submit).click();   
        $(submit).attr('disabled', 'disabled');
      }
      
      // Update filter form with keyword and use filter form submit for keyword search
      $(searchForm).submit(function(e) {
        var field = $(searchForm).find('input[name="keyword"]');
        var keyword = $(field).val();
        $(field).removeClass('error');
        
        if (!keyword) {
          $(field).addClass('error');
          e.preventDefault();
          return;
        }
        
        e.preventDefault();        
        $(form).find('input[name="keyword"]').val(keyword);
        submitForm();
      });
      
      // Accordion
      $(form).find('.accordion').once(function(){
        var isActive = $(this).attr('data-state') == 'active' ? 0 : false;
        $(this).accordion({
          collapsible: true,
          active: isActive
        });
      });
      
      // Add count to each tab
      $('#quicktabs-training_library_content', context).once(function() {
        var qt = $(this);
        
        $(qt).find('div[id*="quicktabs-tabpage-training_library_content-"]').each(function(){
          var index = $(this).index();
          var count = $(this).find('.paginate>ul>li').length;
          $(qt).find('ul.quicktabs-tabs>li').eq(index).find('a').append(' (' + count + ')');
        });
        
      });
    }
  };
})(jQuery);