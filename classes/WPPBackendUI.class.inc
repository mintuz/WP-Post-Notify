<?php

	class WPPBackendUI {
		
		// ==================
		// ! ACTIONS
		// ==================
		
		/**
		* add_meta_box action
		*
		* @return void
		* @author - Adam Bulmer
		*/
		
		public static function add_meta_boxes( ) {
		
			global $post;
			
			add_meta_box( 'wpp-send-email' , 'WP Post Notify' , array( 'WPPBackendUI','send_email_box' ) , 'post', 'side', 'low' );
			
		}
		
		// ==================
		// ! METHODS
		// ==================
		
		/**
		* Display send email meta box
		*
		* @return void
		* @author - Adam Bulmer
		*/
		
		public static function send_email_box( $post ) {
	
		?>
		
		<div class="wpp-send-email">
			<p>Send a notification email to your subscribers:</p>
			<input type="submit" id="btn-notify" name="btn-notify" value="Send Notification Email" class="button-primary metabox-button" />
		</div>
		
		<?php
	
		}
	
	}

?>