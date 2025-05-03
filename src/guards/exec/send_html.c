/*
** EPITECH PROJECT, 2025
** CWebServer
** File description:
** send_requested_html
*/

#include "web_server.h"

void send_html(int fd, http_request_t *request, server_t *server)
{
    int file_fd = open("public/index.html", O_RDONLY);
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    debug_print("send_html");
    (void)server;
    (void)request;
    if (fd == -1)
        eprintf(84, "Couldn't open index.html");
    bytes_read = read(file_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1)
        eprintf(84, "Couldn't read index.html");
    buffer[bytes_read] = '\0';
    debug_str(buffer);
    debug_void(send_http, fd, buffer);
    // while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
    //     buffer[bytes_read] = '\0';
    //     send_http(fd, "%s", buffer);
    // }
}
