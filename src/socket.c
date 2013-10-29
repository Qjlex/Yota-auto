#include <memory.h>
#include <malloc.h>

#include "socket.h"

int socket_select( int socket, int timeout )
{
    if( timeout > 0 )
    {
        struct timeval tv;
	    tv.tv_sec  = timeout / 1000;
    	tv.tv_usec = ( timeout % 1000 ) * 1000;
    	
	    fd_set fdsr;
	    FD_ZERO(&fdsr);
    	FD_SET(socket, &fdsr);

        int responce = select( FD_SETSIZE, &fdsr, NULL, NULL, &tv );
        if( responce != 1 )
        {
            return 0;
        }
    }

    return 1;
}

__inline__ int socket_receive( int socket, char *buffer, unsigned int buffer_length )
{
   return recv( socket, buffer, buffer_length, 0 );
}

__inline__ unsigned short int socket_send( int socket, const char *buffer, int buffer_size )
{
    return send( socket, buffer, buffer_size, 0 ) == buffer_size ? 1 : 0;
}

struct sockaddr_in socket_create_sockaddr_in( const char *hostName, int port )
{
    struct sockaddr_in result;
    memset( &result, '\0', sizeof( result ) );
    result.sin_family = AF_INET;
    result.sin_port = htons( port );

    struct hostent *lphost = gethostbyname( hostName );
    memcpy( &( result.sin_addr ), lphost->h_addr, lphost->h_length );
    free(lphost);
    return result;
}

__inline__ int socket_create( struct sockaddr_in addr )
{
    return socket( addr.sin_family, SOCK_STREAM, IPPROTO_TCP );
}

__inline__ unsigned short int socket_connect( int socket, struct sockaddr_in addr )
{
    return connect( socket, ( struct sockaddr * )&addr, sizeof( addr ) ) == 0 ? 1 : 0;
}

__inline__ int socket_close( int socket )
{
    return close( socket );
}