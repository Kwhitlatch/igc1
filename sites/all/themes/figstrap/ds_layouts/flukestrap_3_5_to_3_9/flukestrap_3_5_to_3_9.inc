<?php

  // Fuction name is ds_LAYOUT_KEY
  function ds_flukestrap_3_5_to_3_9() {
    return array(
      'label' => t('Flukestrap 3-5 Desktop, 3-9 Mobile'),
      'regions' => array(
        // The key of this region name is also the variable used in
        // the template to print the content of that region.
        'left' => t('Left'),
        'right' => t('Right'),
      ),
      // Add this if there is a default css file.
      'css' => FALSE,
      // Add this if there is a default preview image
      'image' => TRUE,
    );
  }
