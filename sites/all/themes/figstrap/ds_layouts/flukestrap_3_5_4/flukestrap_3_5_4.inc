<?php

  // Fuction name is ds_LAYOUT_KEY
  function ds_flukestrap_3_5_4() {
    return array(
      'label' => t('Flukestrap Three Columns 3-5-4'),
      'regions' => array(
        // The key of this region name is also the variable used in
        // the template to print the content of that region.
        'left' => t('Left'),
        'central' => t('Middle'),
        'right' => t('Right'),
      ),
      // Add this if there is a default css file.
      'css' => FALSE,
      // Add this if there is a default preview image
      'image' => TRUE,
    );
  }
