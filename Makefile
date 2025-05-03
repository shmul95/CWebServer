##
## EPITECH PROJECT, 2025
## web_server
## File description:
## Makefile
##

.SILENT: all clean fclean re

CC = @gcc
CFLAGS = -I./includes -Wall -Wextra -g

SRC_DIR = src
OBJ_DIR = build

SRC 	= 	$(SRC_DIR)/main.c \
			$(SRC_DIR)/server.c \
			$(SRC_DIR)/server_run.c \
			$(SRC_DIR)/send.c \
			$(SRC_DIR)/parse_http.c \
			$(SRC_DIR)/utils/error.c \
			$(SRC_DIR)/utils/debug.c \
			$(SRC_DIR)/guards/guards_map.c \
			$(SRC_DIR)/guards/cond/otherwise.c \
			$(SRC_DIR)/guards/exec/send_html.c \
			$(SRC_DIR)/guards/exec/show_path.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = web_server

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Build complete: $@"
	@echo "Run with: ./$(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Cleaned up object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up executable."

re: fclean all
	@echo "Rebuild complete."

.PHONY: all clean fclean re
