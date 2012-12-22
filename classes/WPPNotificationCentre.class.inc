<?php

/*
 * == WPPNotificationCentre ==
 * 
 * - WPPNotificationCentre - Used to send emails, works with the template manager and phpmailer
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

class WPPNotificationCentre {
	
	// ==================
	// ! CONSTAINTS
	// ==================
	
	// ==================
	// ! METHODS
	// ==================
	
	/**
	* Public function to load the htm template and replace placeholders
	*
	* @return - bool
	* @author - Adam Bulmer
	*/
		
	public static function send_email( $args = array() ) {
		
		include WPP_DIR . '/libs/PHPMailer/class.phpmailer.php';	
			
		$defaults = array(
			
			'to' => array( 'email' => 'webteam@forepoint.co.uk', 'name' => get_bloginfo( 'name' ) ),
			'from' => array( 'email' => 'website@' . $_SERVER[ 'HTTP_HOST' ], 'name' => get_bloginfo( 'name' ) ),
		
		);
		
		$args = array_merge( $defaults, $args );
		
		extract( $args );
		
		$mail = new PHPMailer();
		
		$mail->SetFrom( $from[ 'email' ] , $from[ 'name' ] );
		$mail->AddAddress( $to[ 'email' ] , $to[ 'name' ] );
		
		$mail->Subject = $subject;
		
		$tm = new WPPTemplateManager( $template , $replacements );
		
		$html_body = $tm->get_html();
		
		$mail->Body = $html_body;
		$mail->IsHTML( true ); 
		
		$plain_text_message = str_replace( "</br>", "\r\n", $html_body );
		$plain_text_message = str_replace( "</p>", "\r\n", $plain_text_message );
		$plain_text_message = strip_tags( $plain_text_message );
		
		$mail->AltBody = $plain_text_message;
			
		return $mail->Send();

	}
		
}

?>