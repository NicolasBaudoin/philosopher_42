# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/25 17:28:16 by nbaudoin          #+#    #+#              #
#    Updated: 2026/04/27 11:40:04 by nbaudoin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC := cc
CFLAGS := -Wall -Werror -Wextra -I.

cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"

UTILS_DIR = src/utils

UTILS_FILES = ${UTILS_DIR}/utils.c ${UTILS_DIR}/put_utils.c

SRC_FILES = src/main.c src/error.c src/parse.c ${UTILS_FILES}

OBJ_DIR = obj

SRC = ${SRC_FILES}

OBJ = $(SRC:%.c=${OBJ_DIR}/%.o)

all: $(NAME)
	@$(call cyan,"Compilation done !")

${NAME} : ${OBJ}
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@$(call cyan,"Creating Philo...")

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(call cyan,"Cleaning .o files...")
	@rm -rf $(OBJ_DIR)
	@$(call cyan,"All .o files are removed !")

fclean: clean
	@$(call cyan,"Cleaning executables and .a files...")
	@rm -f $(NAME)
	@$(call cyan,"All executables and .a files are removed !")

re: fclean all

.PHONY: all clean fclean re