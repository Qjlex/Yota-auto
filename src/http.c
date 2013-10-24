#include "http.h"

int get_connected_socket( const char *host )
{
    int result;

    struct sockaddr_in addr = socket_create_sockaddr_in( host, 80 );
    result = socket_create( addr );
    if( socket_connect( result, addr ) == 0 )
    {
        result = -1;
    }

    return result;
}

unsigned short int http_packet_send_and_check_status_code( const char *host, const char *packet, const char *need_status_code )
{
    int socket = get_connected_socket( host );
    if( socket == -1 )
    {
        return -1;
    }

	unsigned short int result = 0;
    unsigned int paket_length = string_get_length( packet );
    if( socket_send( socket, packet, paket_length ) == 1 )
    {
    	char *receive_status_code = socket_http_get_status_code( socket, 2000 );
    	if( receive_status_code != NULL )
    	{
	    	if( string_compare( receive_status_code, need_status_code, 3 ) == 1 )
	    	{
	        	result = 1;	
	    	}
	    	free( receive_status_code );
    	}
    }

    socket_close( socket );
    return result;
}