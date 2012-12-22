<?php

class WPPTemplateTags {
	
	// ==================
	// ! METHODS
	// ==================
	
	/**
	* Show custom subscribe widget to allow vistors to register
	*
	* @author - Adam Bulmer
	*/
	
	public static function show_subscribe_widget() {
		
		if( isset( $_POST[ 'btn-subscribe' ] ) ) {
			
			$status = WPPUtils::new_subscriber( $_POST[ 'txt-email-address' ] );
			
			if( $status == 'inserted' ) {
				
				$status = '<span class="help-inline">You are now subscribed.</span>';
				
			} else if( $status == 'already_exists' ) {
				
				$status = '<span class="help-inline">You have already subscribed to this website.</span>';
				
			} else if( $status == 'invalid_email' ) {
				
				$status = '<span class="help-inline">The email you have provided is invalid.</span>';
				
			}
		
		}
		
		
	?>
	
		<div class="wpp-subscribe-box" id="wpp-subscribe-box">
			<p>Enter your email address to follow this blog and receive notifications of new posts by email.</p>

			<p>Join <?php echo WPPUtils::count_subscribers(); ?> other followers</p>
			<form class="form-inline" action="/" method="post">
				<input type="email" name="txt-email-address" class="input-small" placeholder="Your email address:">
				<button type="submit" name="btn-subscribe" class="btn btn-primary">Subscribe</button>
				<?php echo ( $status ) ? $status : ''; ?>
			</form>
		</div>
	
	<?php	
		
	}
	
	public static function show_unsubscribe_widget() {
		
		
	}
	
}

?>