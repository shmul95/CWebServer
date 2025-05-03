/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** server_run
*/

#include "web_server.h"

static sig_atomic_t run_server = 1;

static void sigint_handler(int signum)
{
    (void)signum;
    run_server = 0;
}

static void server_handle_connection(server_t *server)
{
    int client_fd = accept(server->sfd, NULL, NULL);

    if (client_fd == -1)
        eprintf(84, "accept");
    server->pfds[server->nfds].fd = client_fd;
    server->pfds[server->nfds].events = POLLIN;
    server->nfds++;
}

static void server_handle_read(server_t *server, const nfds_t i)
{
    char buffer[BUFFER_SIZE] = {0};
    ssize_t bytes_read = recv(server->pfds[i].fd, buffer, sizeof(buffer), 0);
    http_request_t request = {0};

    if (bytes_read <= 0) {
        close(server->pfds[i].fd);
        server->pfds[i].fd = -1;
        server->nfds--;
    } else {
        parse_http_request(&request, buffer);
        handle_guards_map(server->pfds[i].fd, &request, server);
    }
}

static void server_disconnection(server_t *server, const nfds_t i)
{
    close(server->pfds[i].fd);
    server->pfds[i].fd = -1;
    server->nfds--;
}

static void server_handle_client(server_t *server, const nfds_t i)
{
    short revents = server->pfds[i].revents;

    if (revents & POLLIN) {
        if (server->pfds[i].fd == server->sfd)
            server_handle_connection(server);
        else
            server_handle_read(server, i);
    }
    if (revents & POLLHUP || revents & POLLERR)
    server_disconnection(server, i);
}

void server_run(server_t server)
{
    int ready = false;

    signal(SIGINT, sigint_handler);
    while (run_server) {
        ready = poll(server.pfds, server.nfds, -1);
        if (ready == -1)
            eprintf(84, "poll");
        for (nfds_t i = 0; i < server.nfds; i++)
            server_handle_client(&server, i);
    }
}
