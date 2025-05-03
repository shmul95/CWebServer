/*
** EPITECH PROJECT, 2025
** CWebServer
** File description:
** parse_http
*/

#include "web_server.h"

static bool parse_http_request_line(
    http_request_line_t *request_line, const char *line
)
{
    if (sscanf(line, "%s %s %s",
        request_line->method,
        request_line->path,
        request_line->http_version
    ) != 3)
        return false;
    return true;
}

static bool parse_http_header(http_header_t *header, char *line)
{
    char *key = strtok(line, ": ");
    char *value = strtok(NULL, "");

    if (key == NULL || value == NULL)
        return false;
    while (*value == ' ')
        value++;
    strncpy(header->key, key, sizeof(header->key) - 1);
    header->key[sizeof(header->key) - 1] = '\0';
    strncpy(header->value, value, sizeof(header->value) - 1);
    header->value[sizeof(header->value) - 1] = '\0';
    return true;
}

static int parse_http_headers(http_header_t *headers, char *buffer)
{
    int count = 0;
    char *line;
    char *saveptr_line;

    line = strtok_r(buffer, "\r\n", &saveptr_line);
    while (line != NULL) {
        if (strcmp(line, "") == 0)
            break;
        if (count >= MAX_HEADERS_SIZE)
            return -1;
        if (!parse_http_header(&headers[count], line))
            return -1;
        count++;
        line = strtok_r(NULL, "\r\n", &saveptr_line);
    }
    return count;
}

bool parse_http_request(http_request_t *request, char *buffer)
{
    char *request_line = strtok(buffer, "\r\n");

    if (request_line == NULL)
        return false;
    if (!parse_http_request_line(&request->request_line, request_line))
        return false;
    request->header_count = parse_http_headers(request->headers, strtok(NULL, ""));
    if (request->header_count < 0)
        return false;
    return true;
}

void print_http_request(const http_request_t request, bool show_headers)
{
    printf("Method: %s\n", request.request_line.method);
    printf("Path: %s\n", request.request_line.path);
    printf("HTTP Version: %s\n", request.request_line.http_version);
    printf("Number of Headers: %d\n", request.header_count);
    for (int i = 0; show_headers && i < request.header_count; i++) {
        printf("Header %d: %s: %s\n", i + 1,
            request.headers[i].key,
            request.headers[i].value
        );
    }
}
