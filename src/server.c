/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** server
*/

#include "web_server.h"

static void server_socket_addr(server_t *server, char *port)
{
    server->sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sfd == -1)
        eprintf(84, "socket");
    memset(&server->addr, 0, sizeof(server->addr));
    server->addr.sin_family = AF_INET;
    if (port)
        server->addr.sin_port = htons(atoi(port));
    else
        server->addr.sin_port = htons(SERVER_PORT);
    server->addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

static void server_bind_listen(server_t *server)
{
    if (bind(server->sfd, (struct sockaddr *)&server->addr,
        sizeof(server->addr)) == -1)
        eprintf(84, "bind");
    if (listen(server->sfd, LISTEN_BACKLOG) == -1)
        eprintf(84, "listen");
}

static void server_poll(server_t *server)
{
    memset(server->pfds, 0, sizeof(*server->pfds));
    server->pfds[0].fd = server->sfd;
    server->pfds[0].events = POLLIN;
    server->nfds = 1;
}

server_t server_create(char *port)
{
    server_t server = {0};

    server_socket_addr(&server, port);
    server_bind_listen(&server);
    server_poll(&server);
    return server;
}

void server_destroy(server_t server)
{
    close(server.sfd);
    server.sfd = -1;
    server.nfds = 0;
    memset(&server.addr, 0, sizeof(server.addr));
    memset(server.pfds, 0, sizeof(server.pfds));
}

void server_print(const server_t server)
{
    printf("--------------------------\n");
    printf("Server socket: %d\n", server.sfd);
    printf("Server address: %s\n", inet_ntoa(server.addr.sin_addr));
    printf("Server port: %d\n", ntohs(server.addr.sin_port));
    printf("Number of clients: %ld\n", server.nfds);
    for (nfds_t i = 0; i < server.nfds; i++)
        printf("Client %ld: fd=%d, events=%d\n", i, server.pfds[i].fd,
            server.pfds[i].events);
}
