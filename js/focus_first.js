(function ($) {
  Drupal.behaviors.focus_first = {
    attach: function(context, settings) {
      if ($('input[type=text]')) {
        $('input[type=text]').first().focus();
      }
		}
  }
})(jQuery);