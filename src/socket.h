#pragma once

#include <netdb.h>

int socket_select( int, int );
__inline__ unsigned short int socket_send( int, const char *, int );
__inline__ int socket_receive( int, char *, unsigned int );
struct sockaddr_in socket_create_sockaddr_in( const char *, int );
__inline__ int socket_create( struct sockaddr_in );
__inline__ unsigned short int socket_connect( int, struct sockaddr_in );
__inline__ int socket_close( int );