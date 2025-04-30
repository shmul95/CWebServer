/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** debug
*/

#include "web_server.h"

void pdebug(const char *format, ...)
{
    va_list ap;

    if (!DO_DEBUG)
        return;
    va_start(ap, format);
    printf("Debug: ");
    vfprintf(stderr, format, ap);
    va_end(ap);
}
