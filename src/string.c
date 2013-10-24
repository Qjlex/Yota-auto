#include "string.h"

__inline__ unsigned int string_get_length( const char *str )
{
    unsigned int result;
    for( result = 0; * ( str + result ) != '\0' ; result++ );
    return result;
}

unsigned short int string_compare( const char *str1, const char *str2, unsigned int n )
{
    int i;
    for( i = 0; i < n; i++ )
    {
        if( *(str1 + i) != *(str2 + i) )
        {
            return 0;
        }
    }

    return 1;
}