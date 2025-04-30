/*
** EPITECH PROJECT, 2025
** web_server
** File description:
** main
*/

#include "web_server.h"

int main(int ac, char **av)
{
    char *port = ac == 2 ? av[1] : NULL;
    server_t server = server_create(port);

    server_print(server);
    server_run(server);
    server_destroy(server);
    return 0;
}
