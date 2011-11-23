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
