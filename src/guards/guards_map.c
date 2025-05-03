/*
** EPITECH PROJECT, 2025
** CWebServer
** File description:
** guards_map
*/

#include "web_server.h"

const guards_map_t guards_map[] = {
    "GET", (guards_t[]){
        {otherwise, send_html, "GET", 200},
    }
};

static int handle_guards(
    const guards_t *guards,
    int fd, http_request_t *request, server_t *server
)
{
    for (int i = 0; guards[i].cond != NULL; i++) {
        if (guards[i].cond(fd, request, server)) {
            guards[i].exec(fd, request, server);
            return guards[i].status;
        }
    }
    return 84;
}

int handle_guards_map(int fd, http_request_t *request, server_t *server)
{
    for (int i = 0; guards_map[i].key[0] != '\0'; i++) {
        if (strcmp(
            request->request_line.method,
            guards_map[i].key
        ) == 0) {
            return handle_guards(
                guards_map[i].guards,
                fd, request, server
            );
        }
    }
    return 84;
}
