<?php
/**
 * @file
 * tax_meas_resis.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function tax_meas_resis_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Earth ground resistance',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '17d43f9e-b4e1-49de-89aa-b1195b4debfa',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1808,
          'revision_id' => 1808,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413298,
          'changed' => 1460413298,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Resistance',
    'description' => NULL,
    'format' => NULL,
    'weight' => 8,
    'uuid' => '35f4aab9-f0b4-4fe2-88d9-ac9d0fd283ef',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1810,
          'revision_id' => 1810,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413298,
          'changed' => 1460413298,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Insulation resistance',
    'description' => NULL,
    'format' => NULL,
    'weight' => 4,
    'uuid' => '37bd9966-19fc-4c84-88b1-0c42816caf6b',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1809,
          'revision_id' => 1809,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413298,
          'changed' => 1460413298,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '0.01 MOhms',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => '6f716a0c-3ccb-4a9d-9f53-6becf42839f9',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1945,
          'revision_id' => 1945,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498712,
          'changed' => 1460498712,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '37bd9966-19fc-4c84-88b1-0c42816caf6b',
    ),
  );
  $terms[] = array(
    'name' => 0,
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '8d331ded-a46a-4c67-b467-1020059ca194',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1942,
          'revision_id' => 1942,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498712,
          'changed' => 1460498712,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '17d43f9e-b4e1-49de-89aa-b1195b4debfa',
    ),
  );
  $terms[] = array(
    'name' => 'Resistance sourcing',
    'description' => NULL,
    'format' => NULL,
    'weight' => 12,
    'uuid' => '98ded01b-cee8-4aa5-878d-e8117557905a',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1811,
          'revision_id' => 1811,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413298,
          'changed' => 1460413298,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Lo ohms',
    'description' => NULL,
    'format' => NULL,
    'weight' => 11,
    'uuid' => 'a6024ea5-fe0f-48c0-922d-0f064cd08ba6',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1812,
          'revision_id' => 1812,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413298,
          'changed' => 1460413298,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '10 GOhms',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => 'd1c3d754-15cd-4372-901f-5e38a51e4994',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1947,
          'revision_id' => 1947,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498712,
          'changed' => 1460498712,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '37bd9966-19fc-4c84-88b1-0c42816caf6b',
    ),
  );
  $terms[] = array(
    'name' => '300k Ohms',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'd3feb314-87ee-48da-87a0-962854040f6e',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1943,
          'revision_id' => 1943,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498712,
          'changed' => 1460498712,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '17d43f9e-b4e1-49de-89aa-b1195b4debfa',
    ),
  );
  $terms[] = array(
    'name' => '2 GOhms',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => 'd8ba43bc-3003-4917-b06e-e7c9266df2ef',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1946,
          'revision_id' => 1946,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498712,
          'changed' => 1460498712,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '37bd9966-19fc-4c84-88b1-0c42816caf6b',
    ),
  );
  $terms[] = array(
    'name' => '50 MOhms',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'e279041a-b70e-4172-b45e-be4e2c7b11e9',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1949,
          'revision_id' => 1949,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498712,
          'changed' => 1460498712,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '35f4aab9-f0b4-4fe2-88d9-ac9d0fd283ef',
    ),
  );
  $terms[] = array(
    'name' => 0,
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'e3980ca8-4c86-452a-8314-09cff046fd5a',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1944,
          'revision_id' => 1944,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498712,
          'changed' => 1460498712,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '37bd9966-19fc-4c84-88b1-0c42816caf6b',
    ),
  );
  $terms[] = array(
    'name' => 0,
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'e97361d2-6bc5-4e96-ab27-1f8346228d8b',
    'vocabulary_machine_name' => 'resistance',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1948,
          'revision_id' => 1948,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498712,
          'changed' => 1460498712,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '35f4aab9-f0b4-4fe2-88d9-ac9d0fd283ef',
    ),
  );
  return $terms;
}
