<?php

	class WPPFrontendUI {
		
		// ==================
		// ! ACTIONS
		// ==================
		
		/**
		* wp_enqueue_scripts hook
		*
		* @author - Adam Bulmer
		*/
		
		public static function wp_enqueue_scripts() {
			
			WPPFrontendUI::_register_styles();
			
		}
		
			/**
			* register custom styles
			*
			* @author - Adam Bulmer
			*/
		
			private static function _register_styles() {
				
				wp_register_style( 'bootstrap-forms' , WPP_URL . '/assets/css/bootstrap.min.css' );
				wp_enqueue_style( 'bootstrap-forms' );
				
			}
		
	}

?>