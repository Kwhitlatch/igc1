<?php
/**
 * @file
 * tax_meas_air_quality.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function tax_meas_air_quality_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'CO',
    'description' => NULL,
    'format' => NULL,
    'weight' => 7,
    'uuid' => '124d159f-1a3c-4d6c-ac0a-aa73858bbf08',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1852,
          'revision_id' => 1852,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460414127,
          'changed' => 1460414127,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '0 fpm',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '35df3794-573e-4efc-90ae-79916cd32c09',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1861,
          'revision_id' => 1861,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417264,
          'changed' => 1460417264,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => 'a23d89b5-6d18-4837-b322-52e9e564b2d6',
    ),
  );
  $terms[] = array(
    'name' => '250 fpm',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => '39c81306-5bd4-4244-a860-be4e5d2c0a9a',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1863,
          'revision_id' => 1863,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417264,
          'changed' => 1460417264,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => 'a23d89b5-6d18-4837-b322-52e9e564b2d6',
    ),
  );
  $terms[] = array(
    'name' => 'CO2',
    'description' => NULL,
    'format' => NULL,
    'weight' => 5,
    'uuid' => '3b0e1e0e-5c6b-4dfc-86c1-68709df91e2d',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1853,
          'revision_id' => 1853,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460414127,
          'changed' => 1460414127,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Humidity',
    'description' => NULL,
    'format' => NULL,
    'weight' => 9,
    'uuid' => '4124ef8d-98ab-4873-9f90-2497851a1153',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1855,
          'revision_id' => 1855,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460414127,
          'changed' => 1460414127,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Air flow',
    'description' => NULL,
    'format' => NULL,
    'weight' => 8,
    'uuid' => '4ee08e27-07af-4bba-8803-51c1d318a213',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1850,
          'revision_id' => 1850,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460414127,
          'changed' => 1460414127,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Particles',
    'description' => NULL,
    'format' => NULL,
    'weight' => 10,
    'uuid' => '7f43425a-8581-46d2-89b5-b769ca76af6a',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1854,
          'revision_id' => 1854,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460414127,
          'changed' => 1460414127,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Air velocity',
    'description' => NULL,
    'format' => NULL,
    'weight' => 6,
    'uuid' => 'a23d89b5-6d18-4837-b322-52e9e564b2d6',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1851,
          'revision_id' => 1851,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460414127,
          'changed' => 1460414127,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '0.50 fpm',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'b1969e81-a6c5-4358-a440-97048453067c',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1862,
          'revision_id' => 1862,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417264,
          'changed' => 1460417264,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => 'a23d89b5-6d18-4837-b322-52e9e564b2d6',
    ),
  );
  $terms[] = array(
    'name' => '16000 fpm',
    'description' => NULL,
    'format' => NULL,
    'weight' => 4,
    'uuid' => 'b28780c1-e767-4323-b704-e0fcc1f97fb1',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1865,
          'revision_id' => 1865,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417264,
          'changed' => 1460417264,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => 'a23d89b5-6d18-4837-b322-52e9e564b2d6',
    ),
  );
  $terms[] = array(
    'name' => '3000 fpm',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => 'deabb154-a363-4a51-b3c9-3c359f611edb',
    'vocabulary_machine_name' => 'air_quality',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1864,
          'revision_id' => 1864,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460417264,
          'changed' => 1460417264,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => 'a23d89b5-6d18-4837-b322-52e9e564b2d6',
    ),
  );
  return $terms;
}
