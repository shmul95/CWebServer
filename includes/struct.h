/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "libs.h"
    #include "const.h"

typedef struct {
    char method[MAX_METHOD_SIZE];
    char path[MAX_PATH_SIZE];
    char http_version[MAX_HTTP_VERSION_SIZE];
} http_request_line_t;

typedef struct {
    char key[MAX_HEADER_KEY_SIZE];
    char value[MAX_HEADER_VALUE_SIZE];
} http_header_t;

typedef struct {
    http_request_line_t request_line;
    http_header_t headers[MAX_HEADERS_SIZE];
    int header_count;
} http_request_t;

typedef struct {
    int sfd;
    struct sockaddr_in addr;
    nfds_t nfds;
    struct pollfd pfds[MAX_CLIENTS];
    // usr_t users[MAX_CLIENTS];
    // char path[PATH_MAX];
} server_t;

#endif /* !STRUCT_H_ */
