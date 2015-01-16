<?php
/**
 * @file
 * storiedmaps_story.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function storiedmaps_story_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function storiedmaps_story_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function storiedmaps_story_node_info() {
  $items = array(
    'story' => array(
      'name' => t('Story'),
      'base' => 'node_content',
      'description' => t('A story is a descriptive piece that is related to a particular location. It can be posted by an authenticated user for approval by a site moderator.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
