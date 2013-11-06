#include <stdio.h>
#include <unistd.h>
#include "http.h"

const unsigned int sleep_time = 5 * 60 * 1000 * 1000; // 5 minute
const char *get_packet = "GET /light/?redirurl=http://mail.ru HTTP/1.1\r\n"
                   "Host: hello.yota.ru\r\n"
                   "Connection: keep-alive\r\n"
                   "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
                   "User-Agent: qURL\r\n"
                   "Accept: */*\r\n"
                   "\r\n";
 const unsigned short get_packet_length = 208;
 const char *post_packet = "POST /php/go.php HTTP/1.1\r\n"
             "Host: hello.yota.ru\r\n"
             "User-Agent: qURL\r\n"
             "Accept: */*\r\n"
             "Origin: http://hello.yota.ru\r\n"
             "Referer: http://hello.yota.ru/light/?redirurl=http://mail.ru\r\n"
             "Content-type: application/x-www-form-urlencoded\r\n"
             "Content-length: 102\r\n"
             "\r\n"
             "accept_lte=1&redirurl=http%3A%2F%2Fmail.ru&city=spb&connection_type=light&service_id=Sliders_Free_Temp";            
const unsigned short post_packet_length = 345;

int main( int argc, const char** argv )
{
    int pid = fork();
    if ( pid != -1 && !pid )
    {
        umask(0);
        setsid();
        chdir("/");
        
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        
	    FILE *file_stream = fopen("/var/run/yota-auto.pid", "w+");
	    if (file_stream)
	    {
	        fprintf( file_stream, "%u", getpid() );
	        fclose( file_stream );
	    }

        while(1)
	{
		if( http_packet_send_and_check_status_code( "hello.yota.ru", get_packet, get_packet_length, "200" ) == 1 )
		{
		    http_packet_send_and_check_status_code( "hello.yota.ru", post_packet, post_packet_length, "302" );
		}
		usleep( sleep_time );
	}
    }

	return 0;
}
