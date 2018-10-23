<?php
/**
 * @file
 * tax_article.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function tax_article_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => "Web Cards",
    'description' => NULL,
    'format' => 'panopoly_html_text',
    'weight' => 6,
    'uuid' => '0a149e65-dcd4-4afe-a3ad-3497befe93bb',
    'vocabulary_machine_name' => 'article',
    'field_content_title' => array(
      'en' => array(
        0 => array(
          'value' => 'Web Cards',
          'format' => NULL,
          'safe_value' => 'Web Cards',
        ),
      ),
    ),
    'field_url_title' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'panopoly_html_text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_field' => array(),
    'name_original' => 'Web Cards',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1267-0',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1267,
          'revision_id' => 1267,
          'language' => 'en',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459832134,
          'changed' => 1459832134,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Software Downloads",
    'description' => NULL,
    'format' => 'panopoly_html_text',
    'weight' => 5,
    'uuid' => '2e82d6a6-1aec-48ff-adea-5f3245d62023',
    'vocabulary_machine_name' => 'article',
    'field_content_title' => array(
      'en' => array(
        0 => array(
          'value' => 'Software Downloads',
          'format' => NULL,
          'safe_value' => 'Software Downloads',
        ),
      ),
    ),
    'field_url_title' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'panopoly_html_text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_field' => array(),
    'name_original' => 'Software Downloads',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1269-0',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1269,
          'revision_id' => 1269,
          'language' => 'en',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459832253,
          'changed' => 1459832253,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Firmware Downloads",
    'description' => NULL,
    'format' => 'panopoly_html_text',
    'weight' => 1,
    'uuid' => '356729d1-306d-4b82-b6aa-60122e826a4e',
    'vocabulary_machine_name' => 'article',
    'field_content_title' => array(
      'en' => array(
        0 => array(
          'value' => 'Firmware Downloads',
          'format' => NULL,
          'safe_value' => 'Firmware Downloads',
        ),
      ),
    ),
    'field_url_title' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'panopoly_html_text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_field' => array(),
    'name_original' => 'Firmware Downloads',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1270-0',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1270,
          'revision_id' => 1270,
          'language' => 'en',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459832271,
          'changed' => 1459832271,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "News",
    'description' => NULL,
    'format' => 'panopoly_wysiwyg_text',
    'weight' => 2,
    'uuid' => '502465d5-04e4-4e5f-8e17-fc7590c9dceb',
    'vocabulary_machine_name' => 'article',
    'field_content_title' => array(
      'en' => array(
        0 => array(
          'value' => 'News',
          'format' => NULL,
          'safe_value' => 'News',
        ),
      ),
    ),
    'field_url_title' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'panopoly_wysiwyg_text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_field' => array(),
    'name_original' => 'News',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1008-0',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1008,
          'revision_id' => 1008,
          'language' => 'en',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459832083,
          'changed' => 1459832083,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Press Releases",
    'description' => NULL,
    'format' => 'panopoly_html_text',
    'weight' => 3,
    'uuid' => '63eb1b12-35f3-4ea3-8ac9-1d1f3f681aae',
    'vocabulary_machine_name' => 'article',
    'field_content_title' => array(
      'en' => array(
        0 => array(
          'value' => 'Press Releases',
          'format' => NULL,
          'safe_value' => 'Press Releases',
        ),
      ),
    ),
    'field_url_title' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'panopoly_html_text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_field' => array(),
    'name_original' => 'Press Releases',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1265-0',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1265,
          'revision_id' => 1265,
          'language' => 'en',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459832102,
          'changed' => 1459832102,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Awards",
    'description' => NULL,
    'format' => 'panopoly_html_text',
    'weight' => 0,
    'uuid' => '777ec35e-8f53-4973-96cd-7738545c0139',
    'vocabulary_machine_name' => 'article',
    'field_content_title' => array(
      'en' => array(
        0 => array(
          'value' => 'Awards',
          'format' => NULL,
          'safe_value' => 'Awards',
        ),
      ),
    ),
    'field_url_title' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'panopoly_html_text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_field' => array(),
    'name_original' => 'Awards',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1266-0',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1266,
          'revision_id' => 1266,
          'language' => 'en',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459832122,
          'changed' => 1459832122,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Web Cards Lead Gen",
    'description' => NULL,
    'format' => 'panopoly_html_text',
    'weight' => 7,
    'uuid' => '8ab33b3c-89ce-4248-8958-a878ab2e2132',
    'vocabulary_machine_name' => 'article',
    'field_content_title' => array(
      'en' => array(
        0 => array(
          'value' => 'Web Cards Lead Gen',
          'format' => NULL,
          'safe_value' => 'Web Cards Lead Gen',
        ),
      ),
    ),
    'field_url_title' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'panopoly_html_text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_field' => array(),
    'name_original' => 'Web Cards Lead Gen',
    'entity_translation_handler_id' => 'taxonomy_term-eid-1268-0',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1268,
          'revision_id' => 1268,
          'language' => 'en',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459832149,
          'changed' => 1459832149,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => "Safety Recalls",
    'description' => NULL,
    'format' => 'panopoly_wysiwyg_text',
    'weight' => 4,
    'uuid' => 'e46371eb-3ae0-4ad9-943a-6fcb732fdd8d',
    'vocabulary_machine_name' => 'article',
    'field_content_title' => array(
      'en' => array(
        0 => array(
          'value' => 'Safety Recalls',
          'format' => NULL,
          'safe_value' => 'Safety Recalls',
        ),
      ),
    ),
    'field_url_title' => array(),
    'description_field' => array(
      'en-us' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'panopoly_wysiwyg_text',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_field' => array(),
    'name_original' => 'Safety Recalls',
    'entity_translation_handler_id' => 'taxonomy_term-eid-981-0',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 981,
          'revision_id' => 981,
          'language' => 'en',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1459832185,
          'changed' => 1459832185,
          'blocking' => 0,
        ),
      ),
    ),
    'description_original' => '',
    'path' => array(
      'pathauto' => 1,
    ),
    'url_alias' => array(),
  );
  return $terms;
}
