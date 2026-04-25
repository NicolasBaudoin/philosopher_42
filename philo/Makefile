# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/25 17:28:16 by nbaudoin          #+#    #+#              #
#    Updated: 2026/04/25 17:42:36 by nbaudoin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC := cc
CFLAGS := -Wall -Werror -Wextra

cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"

SRC_DIR = src

SRC_FILES = ${SRC_DIR}/main.c ${SRC_DIR}/atoi.c \
${SRC_DIR}/error.c ${SRC_DIR}/input_verification.c \
 ${SRC_DIR}/len.c

OBJ_DIR = obj

SRC = ${SRC_FILES}

OBJ = $(SRC:%.c=${OBJ_DIR}/%.o)

all: $(NAME)
	@$(call cyan,"Compilation done !")

${NAME} : ${OBJ}
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@$(call cyan,"Creating so_long...")

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

.PHONY: all clean fclean re philo