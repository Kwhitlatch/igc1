<?php
/**
 * @file
 * tax_meas_press.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function tax_meas_press_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Pressure sourcing',
    'description' => NULL,
    'format' => NULL,
    'weight' => 10,
    'uuid' => '2522c427-0a58-44ed-837c-af0880c831d7',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1814,
          'revision_id' => 1814,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413412,
          'changed' => 1460413412,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '500 psi',
    'description' => NULL,
    'format' => NULL,
    'weight' => 5,
    'uuid' => '28ba135c-6c39-4f40-b710-5e95abdd654d',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1871,
          'revision_id' => 1871,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417994,
          'changed' => 1460417994,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '76b10d3d-6290-4138-830e-4d9337797694',
    ),
  );
  $terms[] = array(
    'name' => '-15 psi',
    'description' => '',
    'format' => 'panopoly_html_text',
    'weight' => 0,
    'uuid' => '35be59ed-4725-44ad-9ebf-8f1a81461fc5',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1866,
          'revision_id' => 1866,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460418493,
          'changed' => 1460418493,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '76b10d3d-6290-4138-830e-4d9337797694',
    ),
  );
  $terms[] = array(
    'name' => 'Pressure type',
    'description' => '',
    'format' => 'panopoly_html_text',
    'weight' => 11,
    'uuid' => '397d6f19-42a2-41b0-ae82-80aff2538dce',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1815,
          'revision_id' => 1815,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460496747,
          'changed' => 1460496747,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '0 psi',
    'description' => '',
    'format' => 'panopoly_html_text',
    'weight' => 1,
    'uuid' => '6944e19e-14c1-42b3-afb1-404fa719e3c5',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1867,
          'revision_id' => 1867,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460496128,
          'changed' => 1460496128,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '76b10d3d-6290-4138-830e-4d9337797694',
    ),
  );
  $terms[] = array(
    'name' => 'Pressure range',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '76b10d3d-6290-4138-830e-4d9337797694',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1813,
          'revision_id' => 1813,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413412,
          'changed' => 1460413412,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '200 psi',
    'description' => NULL,
    'format' => NULL,
    'weight' => 4,
    'uuid' => '7beb89d1-8877-4a44-ace0-c7c3a34462c5',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1870,
          'revision_id' => 1870,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417994,
          'changed' => 1460417994,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '76b10d3d-6290-4138-830e-4d9337797694',
    ),
  );
  $terms[] = array(
    'name' => '50 psi',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => 'a3b04321-ccea-42dd-9f26-2e468b039aed',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1869,
          'revision_id' => 1869,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417994,
          'changed' => 1460417994,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '76b10d3d-6290-4138-830e-4d9337797694',
    ),
  );
  $terms[] = array(
    'name' => '1000 psi',
    'description' => NULL,
    'format' => NULL,
    'weight' => 6,
    'uuid' => 'a4997678-9ba9-4343-ae7a-42412ed80d85',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1872,
          'revision_id' => 1872,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417994,
          'changed' => 1460417994,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '76b10d3d-6290-4138-830e-4d9337797694',
    ),
  );
  $terms[] = array(
    'name' => '10 psi',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => 'b175d4da-6f5b-4083-bd55-460c02921470',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1868,
          'revision_id' => 1868,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417994,
          'changed' => 1460417994,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '76b10d3d-6290-4138-830e-4d9337797694',
    ),
  );
  $terms[] = array(
    'name' => 'Absolute',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd1636212-b20f-4545-af3b-760f7b4ac395',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1873,
          'revision_id' => 1873,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460418041,
          'changed' => 1460418041,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '397d6f19-42a2-41b0-ae82-80aff2538dce',
    ),
  );
  $terms[] = array(
    'name' => 'Differential',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'dbf6fd28-0775-4f68-9389-58a2537b8787',
    'vocabulary_machine_name' => 'pressure',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1874,
          'revision_id' => 1874,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460418041,
          'changed' => 1460418041,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '397d6f19-42a2-41b0-ae82-80aff2538dce',
    ),
  );
  return $terms;
}
