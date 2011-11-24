<?php

/**
 * @file
 * Frontend page callbacks for lydia channel module.
 */

/**
 * Download a audio file (not play it in the browser).
 */
function lydia_channel_download_audio($file) {
  drupal_add_http_header('Content-Type', 'application/force-download');
  drupal_add_http_header('Content-Disposition', 'attachment; filename="' . $file->filename . '"');
  ob_clean();
  flush();
  readfile($file->uri);
}

/**
 * Download a playlist file for the files on the node.
 */
function lydia_channel_download_playlist($node) {
  if ($node->type != 'lydia_channel') {
    return drupal_not_found();
  }
  $playlist = '';
  $node_wrapper = entity_metadata_wrapper('node', $node);
  foreach ($node_wrapper->lydia_channel_audio->value() as $file) {
    $playlist .= file_create_url($file['uri']) . PHP_EOL;
  }
  if ($playlist) {
    drupal_add_http_header('Content-Type', 'audio/x-mpegurl; charset=utf-8');
    drupal_add_http_header('Content-Disposition', 'attachment; filename="' . check_plain($node->title) .'.m3u"');
      echo $playlist;
      exit;
  }
  return drupal_not_found();
}

/**
 * Download a zip file containing the files on the node.
 */
function lydia_channel_download_zip($node) {
  if ($node->type != 'lydia_channel') {
    return drupal_not_found();
  }
  $files = array();
  $node_wrapper = entity_metadata_wrapper('node', $node);
  foreach ($node_wrapper->lydia_channel_audio->value() as $file) {
    $files[] = array(
      'path' => drupal_realpath($file['uri']),
      'name' => $file['filename'],
    );
  }
  $dir = 'public://lydia-channel-zip/';
  $destination = $dir . trim(check_plain($node->title), '.') . '.zip';
  if (file_prepare_directory($dir, FILE_CREATE_DIRECTORY)) {
    $result = lydia_channel_create_zip($files, drupal_realpath($destination));
    if ($result === TRUE || $result === 'file exists') {
      return drupal_goto(file_create_url($destination));
    }
    $e = new Exception();
    $e->error = 'Could not create zip file';
    throw $e;
  }
  $e = new Exception();
  $e->error = 'Could not create new directory';
  throw $e;
}

/**
 * creates a compressed zip file
 */
function lydia_channel_create_zip($files = array(), $destination = '', $overwrite = FALSE) {
  // If the zip file already exists and overwrite is false, return false.
  if (file_exists($destination) && !$overwrite) {
    return 'file exists';
  }
  $valid_files = array();
  // Check that files are valid.
  foreach ($files as $file) {
    if (file_exists($file['path'])) {
      $valid_files[] = $file;
    }
  }
  // If we have good files...
  if (count($valid_files)) {
    // Create the archive
    $zip = new ZipArchive();
    if ($zip->open($destination, $overwrite ? ZIPARCHIVE::OVERWRITE : ZIPARCHIVE::CREATE) !== TRUE) {
      return 'could not open zip archive';
    }
    // Add the files
    foreach($valid_files as $file) {
      $zip->addFile($file['path'], $file['name']);
    }
    
    // Close the zip -- done!
    $zip->close();
    
    // Check to make sure the file exists.
    return file_exists($destination);
  }
  else {
    return 'no valid files';
  }
}
