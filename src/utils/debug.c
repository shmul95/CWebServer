/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** debug
*/

#include "web_server.h"

void pdebug(
    const char *file, const int line,
    const char *format, ...
)
{
    va_list ap;

    if (!DO_DEBUG)
        return;
    va_start(ap, format);
    fprintf(stderr, "Debug: %s:%d: ", file, line);
    vfprintf(stderr, format, ap);
    fprintf(stderr, "\n");
    va_end(ap);
}
