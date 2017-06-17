<?php

function postit_uri($postit){
  return array(
    'path' => 'postit/' . $postit->id,
  );
}

function postit_load($pid = NULL, $reset = FALSE){
  $pids = (isset ($pid) ? array($pid) : array());
  $postit = postit_load_multiple($pids, $reset);
  return $postit ? reset ($postit) : FALSE;
}
 
function postit_load_multiple($pids = array(), $conditions = array(), $reset = FALSE){
  return entity_load('postit', $pids, $conditions, $reset);
}
