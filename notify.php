<?php

/*

Plugin Name: WP Post Notify
Plugin URI: http://www.mintuz.com
Description: Notify subscribers of a new post
Version: 0.2
Author: Adam Bulmer
Author URI: http://www.mintuz.com

*/

// =============
// ! CONSTANTS
// =============

define( 'WPP_VERSION', '0.2' );
define( 'WPP_DIR', WP_PLUGIN_DIR . '/' . basename( dirname(__FILE__) ) );
define( 'WPP_URL', rtrim( plugin_dir_url( __FILE__ ), '/' ) );
define( 'WPP_CUSTOM_TABLE' , 'wpp_subscribers' );

// ==================
// ! INCLUDES
// ==================

// WP Post Notify Plugin Classes
include WPP_DIR . '/classes/WPPBackendUI.class.inc';
include WPP_DIR . '/classes/WPPConfig.class.inc';
include WPP_DIR . '/classes/WPPTemplateManager.class.inc';
include WPP_DIR . '/classes/WPPTemplateTags.class.inc';
include WPP_DIR . '/classes/WPPNotificationCentre.class.inc';
include WPP_DIR . '/classes/WPPUtils.class.inc';
include WPP_DIR . '/classes/WPPFrontendUI.class.inc';

// Third Party Classes
include WPP_DIR . '/libs/php_extended.inc';

// ==================
// ! WPPConfig
// ==================

// Shortcodes

// Filters

// Actions
register_activation_hook( __FILE__ , array( 'WPPConfig', 'install' ) );

add_action( 'save_post', array( 'WPPConfig', 'save_post' ) );

// ==================
// ! WPPBackendUI
// ==================

// Shortcodes

// Filters

// Actions
add_action( 'add_meta_boxes' , array( 'WPPBackendUI', 'add_meta_boxes' ) );

// ==================
// ! WPPBackendUI
// ==================

// Shortcodes

// Filters

// Actions
add_action( 'wp_enqueue_scripts' , array( 'WPPFrontendUI', 'wp_enqueue_scripts' ) );

?>