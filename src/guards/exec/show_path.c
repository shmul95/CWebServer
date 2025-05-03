/*
** EPITECH PROJECT, 2025
** CWebServer
** File description:
** show_path
*/

#include "web_server.h"

void show_path(
    int fd, http_request_t *request, server_t *server
)
{
    (void)fd;
    (void)server;
    printf("Request path: %s\n", request->request_line.path);
}
