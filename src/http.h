#pragma once

#include "http.h"
#include "socket.h"

unsigned short int http_packet_send_and_check_status_code( const char *, const char *, unsigned int, const char * );