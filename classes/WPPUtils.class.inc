<?php

class WPPUtils {
	
	// ==================
	// ! METHODS
	// ==================
	
	/**
	* New subscriber database request
	*
	* @return bool
	* @author - Adam Bulmer
	*/
	
	public static function new_subscriber( $email ) {
		
		global $wpdb;
		
		if( ! WPPUtils::get_subscriber( $email ) ) {
				
			return $wpdb->insert( $wpdb->prefix . WPP_CUSTOM_TABLE , array( 'subscriber_email' => $email ) , array( '%s' ) );	
			
		}
		
		return false;
		
	}
	
	/**
	* Only return array of emails
	*
	* @return object
	* @author - Adam Bulmer
	*/
	
	public static function get_subscriber_emails() {
		
		global $wpdb;
		
		return $wpdb->get_results( $wpdb->prepare( "SELECT `subscriber_email` FROM `" . $wpdb->prefix . WPP_CUSTOM_TABLE . "`" ) , ARRAY_A );
		
	}
	
	/**
	* Get all subscribers rows
	*
	* @return object
	* @author - Adam Bulmer
	*/
	
	public static function get_subscribers() {
		
		global $wpdb;
		
		return $wpdb->get_results( $wpdb->prepare( "SELECT * FROM `". $wpdb->prefix . WPP_CUSTOM_TABLE . "`" ) , ARRAY_A );
		
	}
	
	/**
	* Get a single subscriber
	*
	* @return array
	* @author - Adam Bulmer
	*/
	
	public static function get_subscriber( $email ) {
		
		global $wpdb;
		
		return $wpdb->get_row( $wpdb->prepare( "SELECT * FROM " . $wpdb->prefix . WPP_CUSTOM_TABLE . " WHERE subscriber_email = %s", $email ) , ARRAY_A );
		
	}
	
	/**
	* Remove a subscriber
	*
	* @return bool
	* @author - Adam Bulmer
	*/
	
	public static function remove_subscriber( $email ) {
		
		global $wpdb;
		
		if( WPPUtils::get_subscriber( $email ) ) {
				
			return $wpdb->query( $wpdb->prepare( "DELETE FROM " . $wpdb->prefix . WPP_CUSTOM_TABLE . " WHERE subscriber_email = %s", $email ) );
			
		}
		
		return false;
		
	}
	
	/**
	* Lets count the subscribers shall we
	*
	* @return bool
	* @author - Adam Bulmer
	*/
	
	public static function count_subscribers() {
		
		global $wpdb;
		
		return $wpdb->get_var( "SELECT COUNT(*) FROM " . $wpdb->prefix .WPP_CUSTOM_TABLE );
		
	}
	
}

?>