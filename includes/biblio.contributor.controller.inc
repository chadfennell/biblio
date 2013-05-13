<?php

/**
 * Contributor class.
 */
class BiblioContributor extends Entity {

  public function __construct($values = array()) {
    $name = $values['name'];
    if (empty($name)) {
      throw new Exception('Contributor given or family name is missing.');
    }

    parent::__construct($values, 'biblio_contributor');
    $wrapper = entity_metadata_wrapper('biblio_contributor', $this);

    // @todo: Add fields if not yet added.
    if ($name['family']) {
      $wrapper->contributor_family = $name['family'];
    }

    if ($name['family']) {
      $wrapper->contributor_given = $name['given'];
    }

  }
}

