/*
** EPITECH PROJECT, 2025
** CWebServer
** File description:
** guards
*/

#ifndef GUARDS_H_
    #define GUARDS_H_
    #include "libs.h"
    #include "const.h"
    #include "struct.h"

typedef struct guards_s {
    bool (*cond)(int fd, http_request_t *request, server_t *server);
    void (*exec)(int fd, http_request_t *request, server_t *server);
    char msg[256];
    int status;
} guards_t;

typedef struct guards_map_s {
    char key[10];
    const guards_t *guards;
} guards_map_t;

extern const guards_map_t guards_map[];

int handle_guards_map(int fd, http_request_t *request, server_t *server);


bool otherwise(int fd, http_request_t *request, server_t *server);

void show_path(int fd, http_request_t *request, server_t *server);
void send_html(int fd, http_request_t *request, server_t *server);

#endif /* !GUARDS_H_ */
