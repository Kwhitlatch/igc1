<?php
/**
 * @file
 * tax_meas_data.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function tax_meas_data_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Waveform capture',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '12b89885-1654-47e9-9200-5a7c602a8988',
    'vocabulary_machine_name' => 'data',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1806,
          'revision_id' => 1806,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413262,
          'changed' => 1460413262,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'True-rms',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '2c5ff478-872f-4278-8060-10e6a004c736',
    'vocabulary_machine_name' => 'data',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1807,
          'revision_id' => 1807,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413262,
          'changed' => 1460413262,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'HART communication',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '831cf8ba-5edd-49e0-91d0-256d6cd99056',
    'vocabulary_machine_name' => 'data',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1802,
          'revision_id' => 1802,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413262,
          'changed' => 1460413262,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Log data',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'adb03547-2271-41cf-af20-8e5f284df6f7',
    'vocabulary_machine_name' => 'data',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1805,
          'revision_id' => 1805,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413262,
          'changed' => 1460413262,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Min-max',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'c6e5497c-1f52-4b8e-8424-6ce8af4c04a4',
    'vocabulary_machine_name' => 'data',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1803,
          'revision_id' => 1803,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413262,
          'changed' => 1460413262,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Min-max-avg',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'cbb90121-b22e-4951-a062-0a4a3bd6ec07',
    'vocabulary_machine_name' => 'data',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1804,
          'revision_id' => 1804,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413262,
          'changed' => 1460413262,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  return $terms;
}
