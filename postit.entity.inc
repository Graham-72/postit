<?php

/**
 * @postit
 * Entity controller and class for postits.
 */

/**
 * Defines the postit entity class.
 */
class Postit extends Entity {

  /**
   * The postit ID.
   *
   * @var integer
   */
  public $pid;

  /**
   * The postit language code.
   *
   * @var string
   */
  public $langcode = LANGUAGE_NONE;

  /**
   * The uid of the user who is associated with the postit.
   *
   * @var integer
   */
  public $uid;
	

  /**
   * The postit published status indicator.
   *
   * Unpublished postits are only visible to their authors and to administrators.
   * The value is either POSTIT_PUBLISHED or POSTIT_NOT_PUBLISHED.
   *
   * @var integer
   */
  public $status;

  /**
   * The postit creation timestamp.
   *
   * @var integer
   */
  public $created;


  /**
   * Constructor for postit entities.
   */
  public function __construct(array $values = array()) {

    parent::__construct($values);
		
		// Set the created time to now.
    if (empty($this->created)) {
      $this->created = REQUEST_TIME;
    }
		
		// Set the user identity
		if (empty($this->uid)) {
      $this->uid = $GLOBALS['user']->uid;
    }
  }

  /**
   * Implements EntityInterface::id().
   */
  public function id() {
    return isset($this->pid) ? $this->pid : NULL;
  }

  /**
   * Implements EntityInterface::entityType().
   */
  public function entityType() {
    return 'postit';
  }

  /**
   * Implements EntityInterface::label().
   */
  public function label() {
    return $this->postitname;
  }
	
  /**
   * Implements EntityInterface::bundle().
   */
  public function bundle() {
    return 'postit';
  }
	
	/**
   * Returns the URI elements of the entity.
   *
   * @return
   *   An array containing the 'path' and 'options' keys used to build the URI
   *   of the entity, and matching the signature of url(). NULL if the entity
   *   has no URI of its own.
   */

  /**
   * Implements EntityInterface::uri().
   */
  public function uri() {
    return array(
      'path' => 'postit/' . $this->pid,
      'options' => array(),
    );
  }
}


/**
 * Controller class for postits.
 *
 * This extends the EntityDatabaseStorageController class, adding required
 * special handling for postit objects.
 */

class PostitController extends EntityDatabaseStorageController{

  /**
   * Overrides EntityDatabaseStorageController::save().
   *
   * @param Postit $entity
   *   The postit entity to be saved.
   */
  public function save(EntityInterface $entity) {
    if (empty($entity->pid)) {
      $entity->pid = db_next_id(db_query('SELECT MAX(pid) FROM {postit}')->fetchField());
      $entity->is_new = TRUE;
    }
    return parent::save($entity);
  }
}


