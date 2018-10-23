<?php
/**
 * @file
 * tax_industry.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function tax_industry_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => "Communication - Data Centers",
    'description' => NULL,
    'format' => 'text',
    'weight' => 0,
    'uuid' => '17f292ac-38be-4c35-9a7c-2f7ecc3dbbb1',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Communication - Data Centers',
          'format' => 'text',
          'safe_value' => 'Communication - Data Centers',
        ),
      ),
    ),
    'field_url_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Communication - Data Centers',
          'format' => 'text',
          'safe_value' => 'Communication - Data Centers',
        ),
      ),
    ),
    'name_field' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Communication - Data Centers',
          'format' => 'text',
          'safe_value' => 'Communication - Data Centers',
        ),
      ),
    ),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Communication - Data Centers',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1262-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1262,
          'revision_id' => 1262,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459831361,
          'changed' => 1459831361,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'f4ed37d5-c6bd-4591-bba5-98b5713b2b55',
    ),
  );
  $terms[] = array(
    'name' => "Chemical Processing",
    'description' => NULL,
    'format' => 'text',
    'weight' => 2,
    'uuid' => '18ab0673-9363-4691-a307-46e56776c1fa',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Chemical Processing',
          'format' => 'text',
          'safe_value' => 'Chemical Processing',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Chemical Processing',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1256-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1256,
          'revision_id' => 1256,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830512,
          'changed' => 1459830512,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'e5ab3106-2fe2-4c62-a142-79ab5afbd8bc',
    ),
  );
  $terms[] = array(
    'name' => "Glass",
    'description' => NULL,
    'format' => 'text',
    'weight' => 3,
    'uuid' => '18d1d042-a017-4d63-87b5-b549cc1877c5',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Glass',
          'format' => 'text',
          'safe_value' => 'Glass',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Glass',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1246-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1246,
          'revision_id' => 1246,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830253,
          'changed' => 1459830253,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Other",
    'description' => NULL,
    'format' => 'text',
    'weight' => 6,
    'uuid' => '24818587-8a86-46d2-944d-6024a54d93e6',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Other',
          'format' => 'text',
          'safe_value' => 'Other',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Other',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1257-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1257,
          'revision_id' => 1257,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830528,
          'changed' => 1459830528,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'e5ab3106-2fe2-4c62-a142-79ab5afbd8bc',
    ),
  );
  $terms[] = array(
    'name' => "Healthcare",
    'description' => NULL,
    'format' => 'text',
    'weight' => 2,
    'uuid' => '28200023-3909-4a22-85b5-6cff0dc02f11',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
        ),
      ),
    ),
    'name_original' => 'Healthcare',
    'entity_translation_handler_id' => 'taxonomy_term-eid-646-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 646,
          'revision_id' => 646,
          'language' => 'en-us',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1459968134,
          'changed' => 1459968134,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => NULL,
    'url_alias' => array(),
    'parent' => array(
      0 => '58440887-48c8-4275-8e83-6af2abf47ba6',
    ),
  );
  $terms[] = array(
    'name' => "Mining",
    'description' => NULL,
    'format' => 'text',
    'weight' => 32,
    'uuid' => '2a412c62-0ebd-4e7c-8ed8-3f235440ad7e',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
        ),
      ),
    ),
    'name_original' => 'Mining',
    'entity_translation_handler_id' => 'taxonomy_term-eid-643-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 643,
          'revision_id' => 643,
          'language' => 'en-us',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1459968134,
          'changed' => 1459968134,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => NULL,
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Alternative Fuel",
    'description' => NULL,
    'format' => 'text',
    'weight' => 0,
    'uuid' => '2bd49744-bd44-4d4d-8267-61da79675de3',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Alternative Fuel',
          'format' => 'text',
          'safe_value' => 'Alternative Fuel',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Alternative Fuel',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1253-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1253,
          'revision_id' => 1253,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830468,
          'changed' => 1459830468,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'e5ab3106-2fe2-4c62-a142-79ab5afbd8bc',
    ),
  );
  $terms[] = array(
    'name' => "Automation",
    'description' => NULL,
    'format' => 'text',
    'weight' => 1,
    'uuid' => '314bdb80-b7c7-45c4-92d1-7c1320ced0e2',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
        ),
      ),
    ),
    'name_original' => 'Automation',
    'entity_translation_handler_id' => 'taxonomy_term-eid-645-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 645,
          'revision_id' => 645,
          'language' => 'en-us',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1459968134,
          'changed' => 1459968134,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => NULL,
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Building & Construction",
    'description' => NULL,
    'format' => 'text',
    'weight' => 13,
    'uuid' => '31b0317e-7f13-4121-abd0-bb2c4343ae4c',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Building & Construction',
          'format' => 'text',
          'safe_value' => 'Building &amp; Construction',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Building & Construction',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1237-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1237,
          'revision_id' => 1237,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459829979,
          'changed' => 1459829979,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Ports",
    'description' => NULL,
    'format' => 'text',
    'weight' => 0,
    'uuid' => '33caba06-9e1a-4d1f-9be0-d95769275dfd',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Ports',
          'format' => 'text',
          'safe_value' => 'Ports',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Ports',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1259-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1259,
          'revision_id' => 1259,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459831283,
          'changed' => 1459831283,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => '4d64c331-e235-4dc7-87bc-5e7f44ad7dfe',
    ),
  );
  $terms[] = array(
    'name' => "Education",
    'description' => NULL,
    'format' => 'text',
    'weight' => 0,
    'uuid' => '37fb4db7-5464-4fc3-8f3e-4e3ce974325f',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
        ),
      ),
    ),
    'name_original' => 'Education',
    'entity_translation_handler_id' => 'taxonomy_term-eid-650-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 650,
          'revision_id' => 650,
          'language' => 'en-us',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1459968135,
          'changed' => 1459968135,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => NULL,
    'url_alias' => array(),
    'parent' => array(
      0 => '58440887-48c8-4275-8e83-6af2abf47ba6',
    ),
  );
  $terms[] = array(
    'name' => "Mining & Mineral Processing",
    'description' => NULL,
    'format' => 'text',
    'weight' => 0,
    'uuid' => '3dbbf03d-a8de-4cdf-9a2d-668611d9eea3',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Mining & Mineral Processing',
          'format' => 'text',
          'safe_value' => 'Mining &amp; Mineral Processing',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Mining & Mineral Processing',
    'entity_translation_handler_id' => 'taxonomy_term-eid-628-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 628,
          'revision_id' => 628,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830175,
          'changed' => 1459830175,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => '2a412c62-0ebd-4e7c-8ed8-3f235440ad7e',
    ),
  );
  $terms[] = array(
    'name' => "Machinery, Instrumentation & Appliances",
    'description' => NULL,
    'format' => 'text',
    'weight' => 4,
    'uuid' => '412f65c8-a3d3-4258-a2bf-61df8e6578ce',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Machinery, Instrumentation & Appliances',
          'format' => 'text',
          'safe_value' => 'Machinery, Instrumentation &amp; Appliances',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Machinery, Instrumentation & Appliances',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1245-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1245,
          'revision_id' => 1245,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830232,
          'changed' => 1459830232,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Building Products",
    'description' => NULL,
    'format' => 'text',
    'weight' => 2,
    'uuid' => '492e5b70-11bd-4820-868d-a0e7176d9992',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Building Products',
          'format' => 'text',
          'safe_value' => 'Building Products',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Building Products',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1247-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1247,
          'revision_id' => 1247,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830263,
          'changed' => 1459830263,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Transportation",
    'description' => NULL,
    'format' => 'text',
    'weight' => 35,
    'uuid' => '4d64c331-e235-4dc7-87bc-5e7f44ad7dfe',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Transportation',
          'format' => 'text',
          'safe_value' => 'Transportation',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Transportation',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1240-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1240,
          'revision_id' => 1240,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830032,
          'changed' => 1459830032,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Other",
    'description' => NULL,
    'format' => 'text',
    'weight' => 37,
    'uuid' => '508706ea-dcbb-48c6-9079-4b54c04b249a',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Other',
          'format' => 'text',
          'safe_value' => 'Other',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Other',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1263-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1263,
          'revision_id' => 1263,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459831376,
          'changed' => 1459831376,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Cement",
    'description' => NULL,
    'format' => 'text',
    'weight' => 1,
    'uuid' => '5101bbd1-c7f3-4b8a-a830-c906d6eba618',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Cement',
          'format' => 'text',
          'safe_value' => 'Cement',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Cement',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1252-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1252,
          'revision_id' => 1252,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830459,
          'changed' => 1459830459,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'e5ab3106-2fe2-4c62-a142-79ab5afbd8bc',
    ),
  );
  $terms[] = array(
    'name' => "Institutional",
    'description' => NULL,
    'format' => 'text',
    'weight' => 30,
    'uuid' => '58440887-48c8-4275-8e83-6af2abf47ba6',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Institutional',
          'format' => 'text',
          'safe_value' => 'Institutional',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Institutional',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1264-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1264,
          'revision_id' => 1264,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459831542,
          'changed' => 1459831542,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Utilities",
    'description' => NULL,
    'format' => 'text',
    'weight' => 36,
    'uuid' => '6fc20bfa-1e4c-4805-acdb-cb47fbac4055',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Utilities',
          'format' => 'text',
          'safe_value' => 'Utilities',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Utilities',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1236-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1236,
          'revision_id' => 1236,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459829963,
          'changed' => 1459829963,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Plastic & Rubber",
    'description' => NULL,
    'format' => 'text',
    'weight' => 5,
    'uuid' => '82c1c068-ad85-4b91-a043-c9534946384c',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Plastic & Rubber',
          'format' => 'text',
          'safe_value' => 'Plastic &amp; Rubber',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Plastic & Rubber',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1250-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1250,
          'revision_id' => 1250,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830306,
          'changed' => 1459830306,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Residential & Commercial",
    'description' => NULL,
    'format' => 'text',
    'weight' => 0,
    'uuid' => '867f4e68-9e7a-4f0f-8c18-872f5de33638',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Residential & Commercial',
          'format' => 'text',
          'safe_value' => 'Residential &amp; Commercial',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Residential & Commercial',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1244-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1244,
          'revision_id' => 1244,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830212,
          'changed' => 1459830212,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => '31b0317e-7f13-4121-abd0-bb2c4343ae4c',
    ),
  );
  $terms[] = array(
    'name' => "Rail",
    'description' => NULL,
    'format' => 'text',
    'weight' => 1,
    'uuid' => '8b214ba3-7e13-48c5-a0c6-b3a2abb4817d',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Rail',
          'format' => 'text',
          'safe_value' => 'Rail',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Rail',
    'entity_translation_handler_id' => 'taxonomy_term-eid-652-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 652,
          'revision_id' => 652,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459831888,
          'changed' => 1459831888,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => '4d64c331-e235-4dc7-87bc-5e7f44ad7dfe',
    ),
  );
  $terms[] = array(
    'name' => "Communication - Telecom",
    'description' => NULL,
    'format' => 'text',
    'weight' => 1,
    'uuid' => '94ad63d2-8a73-4cfe-b58a-bb443d806838',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Communication - Telecom',
          'format' => 'text',
          'safe_value' => 'Communication - Telecom',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Communication - Telecom',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1260-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1260,
          'revision_id' => 1260,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459831309,
          'changed' => 1459831309,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'f4ed37d5-c6bd-4591-bba5-98b5713b2b55',
    ),
  );
  $terms[] = array(
    'name' => "Pharmaceutical & Biotech",
    'description' => NULL,
    'format' => 'text',
    'weight' => 4,
    'uuid' => 'a047f080-b6af-40bd-991a-06fd14d6ce4c',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Pharmaceutical & Biotech',
          'format' => 'text',
          'safe_value' => 'Pharmaceutical &amp; Biotech',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Pharmaceutical & Biotech',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1255-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1255,
          'revision_id' => 1255,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830495,
          'changed' => 1459830495,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'e5ab3106-2fe2-4c62-a142-79ab5afbd8bc',
    ),
  );
  $terms[] = array(
    'name' => "Manufacturing",
    'description' => NULL,
    'format' => 'text',
    'weight' => 31,
    'uuid' => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
        ),
      ),
    ),
    'name_original' => 'Manufacturing',
    'entity_translation_handler_id' => 'taxonomy_term-eid-624-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 624,
          'revision_id' => 624,
          'language' => 'en-us',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1459968145,
          'changed' => 1459968145,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => NULL,
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Agriculture",
    'description' => NULL,
    'format' => 'text',
    'weight' => 1,
    'uuid' => 'b281dee5-e4d6-4338-9965-da22e2b5346b',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Agriculture',
          'format' => 'text',
          'safe_value' => 'Agriculture',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Agriculture',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1235-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1235,
          'revision_id' => 1235,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459829730,
          'changed' => 1459829730,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Facilities Maintenance",
    'description' => NULL,
    'format' => 'text',
    'weight' => 24,
    'uuid' => 'b4ac7c21-12b3-4d5d-9296-c63c24529d85',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Facilities Maintenance',
          'format' => 'text',
          'safe_value' => 'Facilities Maintenance',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Facilities Maintenance',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1238-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1238,
          'revision_id' => 1238,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830007,
          'changed' => 1459830007,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Pulp, Paper & Wood",
    'description' => NULL,
    'format' => 'text',
    'weight' => 5,
    'uuid' => 'b9027c48-1b5b-4d9d-a16c-e981b46cbbec',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Pulp, Paper & Wood',
          'format' => 'text',
          'safe_value' => 'Pulp, Paper &amp; Wood',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Pulp, Paper & Wood',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1254-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1254,
          'revision_id' => 1254,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830483,
          'changed' => 1459830483,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'e5ab3106-2fe2-4c62-a142-79ab5afbd8bc',
    ),
  );
  $terms[] = array(
    'name' => "Aerospace",
    'description' => NULL,
    'format' => 'text',
    'weight' => 0,
    'uuid' => 'c89d6c47-5f6a-46e5-9a61-44cf092bae67',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
        ),
      ),
    ),
    'name_original' => 'Aerospace',
    'entity_translation_handler_id' => 'taxonomy_term-eid-642-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 642,
          'revision_id' => 642,
          'language' => 'en-us',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1459968148,
          'changed' => 1459968148,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => NULL,
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Oil and Gas",
    'description' => NULL,
    'format' => 'text',
    'weight' => 33,
    'uuid' => 'cdf1139e-f83c-44b1-9953-9cab1bed858d',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
        ),
      ),
    ),
    'name_original' => 'Oil and Gas',
    'entity_translation_handler_id' => 'taxonomy_term-eid-633-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 633,
          'revision_id' => 633,
          'language' => 'en-us',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1459968148,
          'changed' => 1459968148,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => NULL,
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Textile",
    'description' => NULL,
    'format' => 'text',
    'weight' => 7,
    'uuid' => 'e1f46ceb-438d-4d6a-891b-5d9f9c8ec76b',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Textile',
          'format' => 'text',
          'safe_value' => 'Textile',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Textile',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1248-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1248,
          'revision_id' => 1248,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830271,
          'changed' => 1459830271,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Process Manufacturing",
    'description' => NULL,
    'format' => 'text',
    'weight' => 34,
    'uuid' => 'e5ab3106-2fe2-4c62-a142-79ab5afbd8bc',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Process Manufacturing',
          'format' => 'text',
          'safe_value' => 'Process Manufacturing',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Process Manufacturing',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1239-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1239,
          'revision_id' => 1239,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830023,
          'changed' => 1459830023,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Government & Defense",
    'description' => NULL,
    'format' => 'text',
    'weight' => 1,
    'uuid' => 'ec3db0eb-f92c-4e16-bc5f-969ad22c7b2b',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Government & Defense',
          'format' => 'text',
          'safe_value' => 'Government &amp; Defense',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Government & Defense',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1261-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1261,
          'revision_id' => 1261,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459831333,
          'changed' => 1459831333,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => '58440887-48c8-4275-8e83-6af2abf47ba6',
    ),
  );
  $terms[] = array(
    'name' => "Food & Beverage",
    'description' => NULL,
    'format' => 'text',
    'weight' => 3,
    'uuid' => 'f0d93919-d4c5-44b1-83da-b800c3ba65f8',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Food & Beverage',
          'format' => 'text',
          'safe_value' => 'Food &amp; Beverage',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Food & Beverage',
    'entity_translation_handler_id' => 'taxonomy_term-eid-644-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 644,
          'revision_id' => 644,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830658,
          'changed' => 1459830658,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'e5ab3106-2fe2-4c62-a142-79ab5afbd8bc',
    ),
  );
  $terms[] = array(
    'name' => "Communications",
    'description' => NULL,
    'format' => 'text',
    'weight' => 21,
    'uuid' => 'f4ed37d5-c6bd-4591-bba5-98b5713b2b55',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Communications',
          'format' => 'text',
          'safe_value' => 'Communications',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Communications',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1241-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1241,
          'revision_id' => 1241,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830040,
          'changed' => 1459830040,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Semiconductors & Computer",
    'description' => NULL,
    'format' => 'text',
    'weight' => 6,
    'uuid' => 'fb8ed5ac-4578-4c6f-96ff-b88daee6e591',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Semiconductors & Computer',
          'format' => 'text',
          'safe_value' => 'Semiconductors &amp; Computer',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Semiconductors & Computer',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1249-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1249,
          'revision_id' => 1249,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830293,
          'changed' => 1459830293,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Other",
    'description' => NULL,
    'format' => 'text',
    'weight' => 8,
    'uuid' => 'fdd37538-c306-4c82-be18-8060759fa4cf',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Other',
          'format' => 'text',
          'safe_value' => 'Other',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Other',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1251-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1251,
          'revision_id' => 1251,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459830319,
          'changed' => 1459830319,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => 'a3aafa08-ff73-4709-9546-d57a1acded9c',
    ),
  );
  $terms[] = array(
    'name' => "Transit",
    'description' => NULL,
    'format' => 'text',
    'weight' => 2,
    'uuid' => 'fe5131ff-c454-41f3-8555-8644a98a80c3',
    'vocabulary_machine_name' => 'industry_segment',
    'field_content_title' => array(
      'en-us' => array(
        0 => array(
          'value' => 'Transit',
          'format' => 'text',
          'safe_value' => 'Transit',
        ),
      ),
    ),
    'field_url_title' => array(),
    'name_field' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Transit',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1258-0',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1258,
          'revision_id' => 1258,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459831266,
          'changed' => 1459831266,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
    'parent' => array(
      0 => '4d64c331-e235-4dc7-87bc-5e7f44ad7dfe',
    ),
  );
  return $terms;
}
