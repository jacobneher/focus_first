<?php

/**
 * Callback for admin/config/user-interface/focus-first.
 */
function focus_first_admin_settings() {
  $form['visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Focus first textfield on specific pages'),
    '#options' => array(
      '0' => t('All pages except those listed'),
      '1' => t('Only the listed pages'),
    ),
    '#default_value' => variable_get('focus_first_visibility', 0),
  );
  
  $form['pages'] = array(
    '#type'          => 'textarea',
    '#description'   => t("Specify pages by using their paths. Enter one path
                          per line. The '*' character is a wildcard. Example
                          paths are blog for the blog page and blog/* for every
                          personal blog. <em>&lt;front&gt;</em> is the front page."),
    '#default_value' => variable_get('focus_first_pages'),
  );
  
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save configuration',
  );
  
  $form['#submit'] = array('focus_first_admin_settings_submit');
  
  return $form;
}

/**
 * Submission handler for focus_first_admin_settings().
 */
function focus_first_admin_settings_submit(&$form, &$form_state) {
  variable_set('focus_first_visibility', $form_state['values']['visibility']);
  variable_set('focus_first_pages', $form_state['values']['pages']);
  
  drupal_set_message('Configuration settings have been saved.');
}