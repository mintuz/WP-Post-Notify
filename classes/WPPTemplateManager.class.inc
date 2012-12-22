<?php

/*
 * == WPPTemplateManager ==
 * 
 * - WPPTemplateManager - Used to load a html template and replace the placeholders with dynamic text
 *
 * - class functions are static eg. public static function <function_name>
 * - Place filters at the top of the class followed by actions
 *
 * - No Functionality should be included within the action functions,
 *   Instead the action functions should call private functions.
 *
 * - Private functions are prefixed with _ eg private static function _function_name(){}
 * 
 /

//Please comment all functions using the following comment standard:
	
/**
* Description of the function
*
* @param - what parameters are accepted by this function
* @return - what is returned by the function
* @author - who wrote this function
* @editor - who edited this funciton
* 
*/

class WPPTemplateManager {
		
		// ==================
		// ! CONSTAINTS
		// ==================
		
		const TEMPLATE_DIR = "templates/";	
		private $html;
		
		// ==================
		// ! METHODS
		// ==================
		
		/**
		* Public Wrapper Function
		*
		* @return - void
		* @author - Tim Perry
		*/
		
		public function __construct( $template_name = '', $replacements = array( ) ) {
		
			if ( ! empty( $template_name ) ) {

				// simply call the load template function
				$this->load_template( $template_name, $replacements );
				
			}
		
		}
		
		/**
		* Public function to load the htm template and replace placeholders
		*
		* @return - bool
		* @author - Tim Perry
		*/
		
		public function load_template( $template_name, $replacements = array( ) ) {
		
			unset( $this->html );
				
			$template_path = WPP_DIR . "/templates/". $template_name . '.htm';
			
			if ( file_exists( $template_path ) ) {
		
				// get the template file					
				$this->html = file_get_contents( $template_path );
				
				if ( ! empty( $replacements ) ) {
				
					// replace all the template parts
					foreach( $replacements as $search => $replace ) {
						
						$this->html = str_replace( "[" . $search . "]", $replace, $this->html );
						
					}
					
					return true;

				}
			
			}
			
			return false;
		
		}
		
		/**
		* Public function to return html string
		*
		* @return - string
		* @author - Tim Perry
		*/
		
		public function get_html( ) {
			
			return $this->html;
		
		}

	
}

?>