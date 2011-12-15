(function ($) {

/**
 * Attaches the autocomplete behavior to all required fields.
 */
Drupal.behaviors.aidyl = {
	attach: function (context, settings) {
    console.log('test');
    $('#wrapper').height($(window).height());
  }
}
})(jQuery);
