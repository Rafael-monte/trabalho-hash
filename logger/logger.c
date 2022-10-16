#include <stdio.h>
#include "logger.h"


void log_info(const char* info, const char* complement)
{
    if (complement == NULL) 
    {
        printf("\033[0;36m%s\n", info);
    } else 
    {
        printf("\033[0;36m%s%s\n", info, complement);
    }
    __normalize_terminal();
}

void log_error(const char* error, const char* complement)
{
    if (complement == NULL)
    {
        printf("\033[0;31m%s\n",error);
    } else 
    {
        printf("\033[0;31m%s%s\n",error, complement);
    }
    __normalize_terminal();
}

void __normalize_terminal()
{
    printf("\033[0;37m\n");
}