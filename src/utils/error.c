/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** error
*/

#include "web_server.h"

void eprintf(const int status, const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    fprintf(stderr, "Error : ");
    vfprintf(stderr, format, ap);
    va_end(ap);
    perror(" ");
    exit(status);
}
