<?php
/**
 * @file
 * storiedmaps_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function storiedmaps_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function storiedmaps_core_views_api() {
  return array("version" => "3.0");
}
