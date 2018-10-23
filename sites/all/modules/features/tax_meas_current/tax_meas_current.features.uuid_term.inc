<?php
/**
 * @file
 * tax_meas_current.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function tax_meas_current_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'dc',
    'description' => NULL,
    'format' => NULL,
    'weight' => 18,
    'uuid' => '0faf32b8-4a84-435d-bdcf-aee41c3cee3c',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1817,
          'revision_id' => 1817,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'THD measurement',
    'description' => NULL,
    'format' => NULL,
    'weight' => 24,
    'uuid' => '1abe7bff-b2cb-4906-ab8d-ee7a6cedaad2',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1820,
          'revision_id' => 1820,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'In-rush',
    'description' => NULL,
    'format' => NULL,
    'weight' => 21,
    'uuid' => '1adbe8e9-2522-456f-9a7e-daff80d14096',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1822,
          'revision_id' => 1822,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'ac+dc',
    'description' => NULL,
    'format' => NULL,
    'weight' => 19,
    'uuid' => '28dc89cc-225b-489a-8b43-088985860d45',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1818,
          'revision_id' => 1818,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '600 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => '2c41f99b-7d28-432f-a9c8-dc8f10ee51fb',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1881,
          'revision_id' => 1881,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497268,
          'changed' => 1460497268,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '3c4f8f5c-dde8-4e6f-9f82-7954e8e1d759',
    ),
  );
  $terms[] = array(
    'name' => '4-20mA signal',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => '38484932-4327-4aa2-8527-24c9d32b754a',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1821,
          'revision_id' => 1821,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'ac',
    'description' => NULL,
    'format' => NULL,
    'weight' => 9,
    'uuid' => '3c4f8f5c-dde8-4e6f-9f82-7954e8e1d759',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1816,
          'revision_id' => 1816,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => '10 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => '44fc42cc-e1ad-4c98-8761-cfa7c16c49c6',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1888,
          'revision_id' => 1888,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497276,
          'changed' => 1460497276,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '28dc89cc-225b-489a-8b43-088985860d45',
    ),
  );
  $terms[] = array(
    'name' => '10 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => '57a47290-4199-4ebe-98d4-4a706d265ee7',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1884,
          'revision_id' => 1884,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497276,
          'changed' => 1460497276,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '0faf32b8-4a84-435d-bdcf-aee41c3cee3c',
    ),
  );
  $terms[] = array(
    'name' => '600 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => '5d8b1a7a-1604-42f8-9c83-ffff6751d497',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1889,
          'revision_id' => 1889,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497276,
          'changed' => 1460497276,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '28dc89cc-225b-489a-8b43-088985860d45',
    ),
  );
  $terms[] = array(
    'name' => '2500 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => '618df871-8ba0-4ad8-8900-f2a4c271e930',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1882,
          'revision_id' => 1882,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497268,
          'changed' => 1460497268,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '3c4f8f5c-dde8-4e6f-9f82-7954e8e1d759',
    ),
  );
  $terms[] = array(
    'name' => '2500 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => '79a7aaca-a601-48e2-ba7f-058049fb82b7',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1890,
          'revision_id' => 1890,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497276,
          'changed' => 1460497276,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '28dc89cc-225b-489a-8b43-088985860d45',
    ),
  );
  $terms[] = array(
    'name' => 'Source + measure',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => '802b08cc-1ea4-49bd-b7a5-96025e229556',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1893,
          'revision_id' => 1893,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497310,
          'changed' => 1460497310,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '38484932-4327-4aa2-8527-24c9d32b754a',
    ),
  );
  $terms[] = array(
    'name' => 0,
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '8df04933-76b3-4e3e-8c47-953e6f8178a3',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1883,
          'revision_id' => 1883,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497276,
          'changed' => 1460497276,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '0faf32b8-4a84-435d-bdcf-aee41c3cee3c',
    ),
  );
  $terms[] = array(
    'name' => 'Current channels',
    'description' => NULL,
    'format' => NULL,
    'weight' => 20,
    'uuid' => 'a68865f7-90a0-41de-90c2-4b1a20ecb173',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1819,
          'revision_id' => 1819,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Measure',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'ad2c9416-e22a-444d-9716-a1673a2bb657',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1892,
          'revision_id' => 1892,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497310,
          'changed' => 1460497310,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '38484932-4327-4aa2-8527-24c9d32b754a',
    ),
  );
  $terms[] = array(
    'name' => 'Microamps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 22,
    'uuid' => 'afd56cb6-c509-4854-a038-5efdd537e38d',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1823,
          'revision_id' => 1823,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Source',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => 'b858844c-22c7-421a-8ecf-afbf0111ea34',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1891,
          'revision_id' => 1891,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497310,
          'changed' => 1460497310,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '38484932-4327-4aa2-8527-24c9d32b754a',
    ),
  );
  $terms[] = array(
    'name' => 0,
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'cb49d62c-2bd6-4d69-af42-0890913552d3',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1887,
          'revision_id' => 1887,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497276,
          'changed' => 1460497276,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '28dc89cc-225b-489a-8b43-088985860d45',
    ),
  );
  $terms[] = array(
    'name' => '600 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => 'cd8d996f-f9ce-42f2-8b2f-a97b36bb67ee',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1885,
          'revision_id' => 1885,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497276,
          'changed' => 1460497276,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '0faf32b8-4a84-435d-bdcf-aee41c3cee3c',
    ),
  );
  $terms[] = array(
    'name' => 'Measure with clamp',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'cfc1ffb0-6f87-4252-98aa-2d0ee9a695c0',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1894,
          'revision_id' => 1894,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497310,
          'changed' => 1460497310,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '38484932-4327-4aa2-8527-24c9d32b754a',
    ),
  );
  $terms[] = array(
    'name' => 0,
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd03bf4bf-2ef9-4883-969c-cd29a39c1eaf',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1879,
          'revision_id' => 1879,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497268,
          'changed' => 1460497268,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '3c4f8f5c-dde8-4e6f-9f82-7954e8e1d759',
    ),
  );
  $terms[] = array(
    'name' => '10 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'd5977eb2-630e-4f0c-9e1b-7624ed3cff67',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1880,
          'revision_id' => 1880,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497268,
          'changed' => 1460497268,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '3c4f8f5c-dde8-4e6f-9f82-7954e8e1d759',
    ),
  );
  $terms[] = array(
    'name' => '2500 amps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => 'f44a1aae-0f94-4df6-87f0-84a544925db7',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1886,
          'revision_id' => 1886,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460497276,
          'changed' => 1460497276,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => '0faf32b8-4a84-435d-bdcf-aee41c3cee3c',
    ),
  );
  $terms[] = array(
    'name' => 'Miliamps',
    'description' => NULL,
    'format' => NULL,
    'weight' => 23,
    'uuid' => 'f66bf2bd-8a8c-4e4d-8411-c9239cbdeb8f',
    'vocabulary_machine_name' => 'current',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1824,
          'revision_id' => 1824,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413490,
          'changed' => 1460413490,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  return $terms;
}
