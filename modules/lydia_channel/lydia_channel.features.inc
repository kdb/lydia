<?php
/**
 * @file
 * lydia_channel.features.inc
 */

/**
 * Implements hook_node_info().
 */
function lydia_channel_node_info() {
  $items = array(
    'lydia_channel' => array(
      'name' => t('Channel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Chanel name'),
      'help' => '',
    ),
  );
  return $items;
}
