<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>

<?php foreach ($fields as $id => $field): ?>
 <div id="PSpider" class="CTA">
  <div id="PS<?php print $field->content; ?>" style="color: #ebebeb;">
    <script>
      var ps_widget_options = new Object();
      ps_widget_options.widgetConfigurationId = 'b7fdc39d-2e11-40ae-8bfc-852f2b2cb907'; 
      ps_widget_options.container = document.getElementById('PS<?php print $field->content; ?>'); 
      ps_widget_options.sku = 'US_<?php print $field->content; ?>'; 
      ps_widget_options.lightboxButtonClass = 'button-primary buy-now-cta'; 
      ps_widget_options.lightboxButtonText = 'Buy Now';
      if(screen.availWidth<=780){
        ps_widget_options.layout = 'mobile';
      }
      ps_Show(ps_widget_options);
    </script>
  </div>
 
</div>
<?php endforeach; ?>
    