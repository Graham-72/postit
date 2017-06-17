<?php

function postit_add_form($form, &$form_state, $postit) {
  $form['note'] = array(
    '#type' => 'textfield',
    '#title' => t('Note'),
    '#required' => TRUE,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  field_attach_form('postit', $postit, $form, $form_state);
  
  return $form;
}

function postit_add_form_validate($form, &$form_state) {
  $postit_submission = (object) $form_state['values'];
  field_attach_form_validate('postit', $postit_submission, $form, $form_state);
}
 
function postit_add_form_submit($form, &$form_state) {
  $postit_submission = (object) $form_state['values'];
  field_attach_submit('postit', $postit_submission, $form, $form_state);
  $postit = postit_save($postit_submission);
  $form_state['redirect'] = "postit/$postit->pid";
}

