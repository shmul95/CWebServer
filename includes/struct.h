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

typedef struct server_s {
    int sfd;
    struct sockaddr_in addr;
    nfds_t nfds;
    struct pollfd pfds[MAX_CLIENTS];
    // usr_t users[MAX_CLIENTS];
    // char path[PATH_MAX];
} server_t;

#endif /* !STRUCT_H_ */
