<?php

class WPPConfig {
	
	// ==================
	// ! ACTIONS
	// ==================
	
	/**
	* Install Hook
	*
	* @author - Adam Bulmer
	*/
	
	public static function install() {
		
		WPPConfig::_create_tables();
		
	}
		
		/**
		* Create table
		*
		* @author - Adam Bulmer
		*/
		
		private static function _create_tables() {
			
			require_once( ABSPATH . 'wp-admin/includes/upgrade.php' );
			
			global $wpdb;
			
			//Custom subscribers table
			$table_name = $wpdb->prefix . "wpp_subscribers";
			$sql = "CREATE TABLE `$table_name` (
			  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
			  `subscriber_email` VARCHAR(255) NOT NULL,
			  `date_subscribed` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
			  PRIMARY KEY (`id`)
			) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;";
			
			dbDelta( $sql );
			
		}
	
	/**
	* Save Post Hook
	*
	* @author - Adam Bulmer
	*/
	
	public static function save_post( $post_id ) {
		
		//if post is published and not a revision
		if( ( isset( $_POST[ 'btn-notify' ] ) ) && ( get_post_status( $post_id ) == 'publish' ) ) {
		
			//array of subscribers
			$subscribers = WPPUtils::get_subscriber_emails();
			
			//some post information to be sent in email
			$post_title = get_the_title( $post_id );
			$post_url = get_permalink( $post_id );
			
			$subject = 'A new blog post has been published on ' . get_bloginfo( 'name' );
			
			if( $subscribers ) {
				
				foreach( $subscribers as $subscriber ) {
					
					$args = array (
		
						'to' => array( 
			
							'email' => $subscriber[ 'subscriber_email' ],
							'name' => $subscriber[ 'subscriber_email' ]
			
						),
						'subject' => $subject,
						'replacements' => array(
			
							'TITLE' => $subject,
							'WEBSITE_URL' => $_SERVER[ 'HTTP_HOST' ],
							'POST_TITLE' => $post_title,
							'POST_URL' => $post_url,
							'WEBSITE_NAME' => get_bloginfo( 'name' )
			
						),
						'template' => 'notify_email_template'
		
					);
				
					WPPNotificationCentre::send_email( $args );
					
				} //foreach
		
			} //if subscribers
		
		} //if submitted
		
	} //save_post function
	
	public static function widgets_init() {
		
		register_widget( 'WPPWidget' );
		
	}
	
}

?>