<?php

	class WPPWidget extends WP_Widget {
	
		public function __construct() {
			
			//construct for WP_Widget base class
			parent::__construct(
		 		'wpp_widget', // Base ID
				'WP Post Notify Widget', // Name
				array( 'description' => __( 'Display the subscribe button', 'text_domain' ), ) // Args
			);
			
		}
		
		public function widget() {
		
			WPPTemplateTags::show_subscribe_widget();
		
		}
		
	}
	

?>