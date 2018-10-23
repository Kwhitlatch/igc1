<?php
/**
 * @file
 * tax_meas_harm.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function tax_meas_harm_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Neutral Current',
    'description' => NULL,
    'format' => NULL,
    'weight' => 3,
    'uuid' => '690c4648-8ee4-432b-a325-a6808c9c5ae7',
    'vocabulary_machine_name' => 'harmonics',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1778,
          'revision_id' => 1778,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413142,
          'changed' => 1460413142,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Voltage & Current',
    'description' => NULL,
    'format' => NULL,
    'weight' => 2,
    'uuid' => '8e001a58-1bec-4578-b49a-a43af3d044c2',
    'vocabulary_machine_name' => 'harmonics',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1941,
          'revision_id' => 1941,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498542,
          'changed' => 1460498542,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => 'a432144d-50ab-437f-9628-715b3cb4d2f4',
    ),
  );
  $terms[] = array(
    'name' => 'Current',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => '9f49b46a-053e-4a1a-aa81-2129e87b1824',
    'vocabulary_machine_name' => 'harmonics',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1940,
          'revision_id' => 1940,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498542,
          'changed' => 1460498542,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => 'a432144d-50ab-437f-9628-715b3cb4d2f4',
    ),
  );
  $terms[] = array(
    'name' => 'Harmonics',
    'description' => NULL,
    'format' => NULL,
    'weight' => 5,
    'uuid' => 'a432144d-50ab-437f-9628-715b3cb4d2f4',
    'vocabulary_machine_name' => 'harmonics',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1777,
          'revision_id' => 1777,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413142,
          'changed' => 1460413142,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  $terms[] = array(
    'name' => 'Voltage',
    'description' => NULL,
    'format' => NULL,
    'weight' => 1,
    'uuid' => 'd2adc312-acc1-4740-9dd5-79ee30ea2efd',
    'vocabulary_machine_name' => 'harmonics',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1939,
          'revision_id' => 1939,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460498542,
          'changed' => 1460498542,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
    'parent' => array(
      0 => 'a432144d-50ab-437f-9628-715b3cb4d2f4',
    ),
  );
  $terms[] = array(
    'name' => 'K-Factor',
    'description' => NULL,
    'format' => NULL,
    'weight' => 4,
    'uuid' => 'fcc69da6-a03a-4cc2-aad4-12f10c4dcb04',
    'vocabulary_machine_name' => 'harmonics',
    'translations' => array(
      'original' => 'en-us',
      'data' => array(
        'en-us' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 1779,
          'revision_id' => 1779,
          'language' => 'en-us',
          'source' => '',
          'uid' => 4,
          'status' => 1,
          'translate' => 0,
          'created' => 1460413142,
          'changed' => 1460413142,
          'blocking' => 0,
        ),
      ),
    ),
    'url_alias' => array(),
  );
  return $terms;
}
