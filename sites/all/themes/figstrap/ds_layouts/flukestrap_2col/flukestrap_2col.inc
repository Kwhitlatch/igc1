<?php

  // Fuction name is ds_LAYOUT_KEY
  function ds_flukestrap_2col() {
    return array(
      'label' => t('Flukestrap 2col'),
      'regions' => array(
        // The key of this region name is also the variable used in
        // the template to print the content of that region.
        'left' => t('left'),
        'right' => t('right'),
      ),
      // Add this if there is a default css file.
      'css' => FALSE,
      // Add this if there is a default preview image
      'image' => FALSE,
    );
  }
