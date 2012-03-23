# mod_fakephp #

This is a very simple module that installs null handlers for the various PHP configuration directives, to allow you to use the htscanner extension with PHP as CGI.

The source code is released under a BSD-like licence.

Installing and activating this module allows you to use the php_value and php_flag directives in Apache configuration files without warnings, without requiring mod_php to be installed. This means you can use PHP in CGI mode (e.g. via mod_suphp and the htscanner extension) as if it was a module.

Note that this module does not interpret the directives – it merely suppresses Apache warnings so that they can be parsed by other means.

For more information, see <http://www.dmi.me.uk/code/apache/mod_fakephp/>
