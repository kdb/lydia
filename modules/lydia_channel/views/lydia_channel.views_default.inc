<?php

/**
 * Implements hook_views_default_views().
 */
function lydia_channel_views_default_views() {
  $views = array();
  
  $view = new view;
  $view->name = 'lydia_channel_file_formatter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Lydia channel file formatter';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'filename' => 'filename',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'filename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: File Usage: Content */
  $handler->display->display_options['relationships']['file_to_node']['id'] = 'file_to_node';
  $handler->display->display_options['relationships']['file_to_node']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['file_to_node']['field'] = 'file_to_node';
  $handler->display->display_options['relationships']['file_to_node']['required'] = 0;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['external'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['filename']['alter']['html'] = 0;
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filename']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['filename']['hide_empty'] = 0;
  $handler->display->display_options['fields']['filename']['empty_zero'] = 0;
  $handler->display->display_options['fields']['filename']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['filename']['link_to_file'] = 1;
  /* Field: File: Playtime in seconds */
  $handler->display->display_options['fields']['lydia_channel_playtime']['id'] = 'lydia_channel_playtime';
  $handler->display->display_options['fields']['lydia_channel_playtime']['table'] = 'field_data_lydia_channel_playtime';
  $handler->display->display_options['fields']['lydia_channel_playtime']['field'] = 'lydia_channel_playtime';
  $handler->display->display_options['fields']['lydia_channel_playtime']['label'] = 'Playtime';
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['external'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['alter']['html'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['lydia_channel_playtime']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['lydia_channel_playtime']['hide_empty'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['empty_zero'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['lydia_channel_playtime']['type'] = 'lydia_channel_audio_duration';
  $handler->display->display_options['fields']['lydia_channel_playtime']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['lydia_channel_playtime']['field_api_classes'] = 0;
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['external'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['filesize']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['filesize']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['filesize']['alter']['html'] = 0;
  $handler->display->display_options['fields']['filesize']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['filesize']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['filesize']['hide_empty'] = 0;
  $handler->display->display_options['fields']['filesize']['empty_zero'] = 0;
  $handler->display->display_options['fields']['filesize']['hide_alter_empty'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'file_to_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'audio';
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: File Usage: Entity type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'file_usage';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = 'node';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'file_rss';
  $handler->display->display_options['path'] = 'node/%/audio-feed';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
  );

  $views[$view->name] = $view;

  return $views;
}
