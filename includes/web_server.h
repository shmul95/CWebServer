/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** web_server
*/

#ifndef WEB_SERVER_H_
    #define WEB_SERVER_H_
    #include "libs.h"
    #include "struct.h"
    #include "guards.h"
    #include "const.h"
    #include "debug.h"

void eprintf(const int status, const char *format, ...);

server_t server_create(char *port);
void server_destroy(server_t server);
void server_run(server_t server);
void server_print(const server_t server);

void send_http(int fd, const char *html, ...);

bool parse_http_request(http_request_t *request, char *buffer);
void print_http_request(const http_request_t request, bool show_headers);

#endif /* WEB_SERVER_H_ */
