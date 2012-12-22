<?php
/*
 * Checks if the string start with another string
 *
 * @return true if string is found
 * @author Tim Perry
 */
if ( ! function_exists( 'starts_with' ) ) {

	function starts_with( $haystack, $needle ) {
	
	    $length = strlen($needle);
	    return (substr($haystack, 0, $length) === $needle);
	}

}

/*
 * Checks if the string ends with another string
 *
 * @return true if string is found
 * @author Tim Perry
 */
 if ( ! function_exists( 'ends_with' ) ) {
	
	function ends_with( $haystack, $needle ) {
	
	    $length = strlen($needle);
	    if ($length == 0) {
	        return true;
	    }
	
	    return (substr($haystack, -$length) === $needle);
	}

}

/*
 * Checks if the string contains another string
 *
 * @return true if string is found
 * @author Tim Perry
 */
 if ( ! function_exists( 'contains' ) ) {
	
	function contains( $haystack, $needle ) {
		return (strlen(strstr($haystack,$needle))>0);
	}

}
/*
 * Gets the current url
 *
 * @return Current url
 * @author Tim Perry
 */
 
if ( ! function_exists( 'current_url' ) ) {
	
	function current_url( ) {
		
		$pageURL = 'http';
		if ( array_key_exists( 'HTTPS', $_SERVER ) && $_SERVER["HTTPS"] == "on") {$pageURL .= "s";}
			$pageURL .= "://";
		if ($_SERVER["SERVER_PORT"] != "80") {
			$pageURL .= $_SERVER["SERVER_NAME"].":".$_SERVER["SERVER_PORT"].$_SERVER["REQUEST_URI"];
		} else {
			$pageURL .= $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"];
		}
		return $pageURL;
		
	}

}

/*
 * Used for ips, multi dimensional version of in_array
 *
 * @return true if in array, false if not
 * @author Tim Perry
 */
if ( ! function_exists( 'in_array_r' ) ) {

	function in_array_r( $needle, $haystack, $strict = true ) {
	
	    foreach ( $haystack as $item) {
	    
	        if (($strict ? $item === $needle : $item == $needle) || (is_array($item) && in_array_r($needle, $item, $strict))) {
	            return true;
	        }
	    }
	    
	    return false;
	}

}

/*
 * Used for debugging, simplfies print_r / die
 *
 * @return void
 * @author Tim Perry
 */
if ( ! function_exists( 'dlog' ) ) {

	function dlog( $output ) {
		
		if ( fpt_ip( ) ) {
			
			die( nlog( $output ) );
		
		}
	
	}

}


/*
 * Non destructive version of dlog
 *
 * @return void
 * @author Tim Perry
 */
if ( ! function_exists( 'nlog' ) ) {

	function nlog( $output ) {
		
		if ( empty( $output ) && $output != 0 ) {
			$output = "EMPTY";
		}
		
		if ( is_array( $output ) || is_object( $output ) ) {
			$output = print_r( $output, true );
		}
		
		// only output for forepoint
		if ( fpt_ip( ) ) {
			
			echo "<pre>" . $output . "</pre>" ;
		
		}
	
	}

}
/*
 * Simply, log to file
 *
 * @return void
 * @author Tim Perry
 */
if ( ! function_exists( 'ltf' ) ) {

	function ltf( $output, $file=null ) {
		
		if ( ! $file ) {
			$file = dirname( __FILE__ ) . '/output.log';
		}
		
		if ( empty( $output ) && $output != 0 ) {
			$output = "EMPTY";
		}
		
		if ( is_array( $output ) || is_object( $output ) ) {
			$output = print_r( $output, true );
		}
		
		// only log for forepoint
		if ( fpt_ip( ) ) {
					
			$fh = fopen( $file, 'a' ) or die( "Failed opening file $file" );
			fwrite( $fh, $output );
			fclose( $fh );
		
		}
	
	}

}

/*
 * Used for debugging, simplfies print_r / die
 *
 * @return void
 * @author Tim Perry
 */
if ( ! function_exists( 'extend_query' ) ) {

	function extend_query( $query, $extension ) {
		
		if ( contains( $query, "?" ) ) {
			return $query . "&" . $extension;
		}
		
		return $query . "?" . $extension;
	
	}

}

/*
 * Return if key exists
 *
 * @return void
 * @author Tim Perry
 */
if ( ! function_exists( 'eike' ) ) {
	
	function eike( $key, $search ) {
	
		echo rike( $key, $search );
	
	}

}

/*
 * Return if key exists, works on objects and classes
 *
 * @return the element if it exists
 * @author Tim Perry
 */
if ( ! function_exists( 'rike' ) ) {

	function rike( $key, $search ) {
	
		if( is_array( $search ) ) {
	
			if ( array_key_exists( $key, $search ) ) {
			
				return $search[ $key ];
			
			}
		
		} else if( is_object( $search ) ) {
			
			if ( property_exists( $search, $key ) ) {
			
				$vars = get_object_vars( $search );
				return $vars[ $key ];
			
			}
		
		}
		
	}

}

/*
 * check if forepoint ip
 *
 * @return return is ip is forepoint
 * @author Tim Perry
 */

if ( ! function_exists( 'fpt_ip' ) ) {

	function fpt_ip( ) {
		
		return true;
		return ( $_SERVER[ 'REMOTE_ADDR' ] == '217.36.5.158' );	
		
	}

}

?>