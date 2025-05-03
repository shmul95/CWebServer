/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** send
*/

#include "web_server.h"

static int wrap_in_http(int fd, const char *html)
{
    const char *header = "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %zu\r\n"
        "\r\n";
    char response[BUFFER_SIZE];
    size_t length = strlen(html);
    int status = 0;

    snprintf(response, sizeof(response), header, length);
    if (send(fd, response, strlen(response), 0) == -1)
        status = 1;
    if (send(fd, html, length, 0) == -1)
        status = 1;
    return status;
}

void send_http(int fd, const char *html, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];

    if (fd < 0 || html == NULL)
        eprintf(84, "Invalid arguments to send_http");
    va_start(args, html);
    vsprintf(buffer, html, args);
    va_end(args);
    if (wrap_in_http(fd, buffer) == 1)
        eprintf(84, "Couldn't send_http");
}
