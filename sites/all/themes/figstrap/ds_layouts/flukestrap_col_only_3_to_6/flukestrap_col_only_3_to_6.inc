<?php

  // Fuction name is ds_LAYOUT_KEY
  function ds_flukestrap_col_only_3_to_6() {
    return array(
      'label' => t('Flukestrap 3 Column Desktop, 6 Column Mobile (No row wrapper)'),
      'regions' => array(
        // The key of this region name is also the variable used in
        // the template to print the content of that region.
        'left' => t('Left'),
      ),
      // Add this if there is a default css file.
      'css' => FALSE,
      // Add this if there is a default preview image
      'image' => TRUE,
    );
  }
