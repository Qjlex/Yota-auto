#include <malloc.h>
#include <memory.h>
#include <string.h>
#include "http.h"

int get_connected_socket( const char *host )
{
    int result = -1;

    struct sockaddr_in *addr = socket_create_sockaddr_in( host, 80 );
    if( addr != NULL )
    {
	    result = socket_create( *addr );
	    if( socket_connect( result, *addr ) == 0 )
	    {
	        result = -1;
	    }
	    free( addr );
	}

    return result;
}

char *http_get_status_code( int socket, int timeout )
{
    char *result = NULL;

    if( socket_select( socket, timeout ) == 0 )
    {
    	return result;
    }

    int buffer_length = 24;
    char *buffer = ( char * )malloc( buffer_length );
    if( socket_receive( socket, buffer, buffer_length ) != buffer_length )
    {
    	free( buffer );
    	return result;
    }

	result = ( char * )malloc( 4 );
	memcpy( result, buffer + 9, 3 );
	*( result + 3 ) = '\0';

    while( socket_receive( socket, buffer, buffer_length ) == buffer_length );
    free( buffer );
   
    return result;
}

unsigned short int http_packet_send_and_check_status_code( const char *host, const char *packet, unsigned int packet_length, const char *need_status_code )
{
    int socket = get_connected_socket( host );
    if( socket == -1 )
    {
        return -1;
    }

	unsigned short int result = 0;
    if( socket_send( socket, packet, packet_length ) == 1 )
    {
    	char *receive_status_code = http_get_status_code( socket, 2000 );
    	if( receive_status_code != NULL )
    	{
	    	if( strcmp( receive_status_code, need_status_code ) == 0 )
	    	{
	        	result = 1;	
	    	}
	    	free( receive_status_code );
    	}
    }

    socket_close( socket );
    return result;
}