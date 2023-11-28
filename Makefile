# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 22:39:07 by bsousa-d          #+#    #+#              #
#    Updated: 2023/11/28 12:27:22 by bsousa-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
PRINTF_PATH = libft/libft.a
SRCSPATH = srcs/
CFLAGS = -Wall -Wextra -Werror

all: 	
		${MAKE} libft
		cc ${CFLAGS} ${SRCSPATH}client.c ${PRINTF_PATH} -o client
		cc ${CFLAGS} ${SRCSPATH}server.c ${PRINTF_PATH} -o server

bonus:
		${MAKE} libft
		cc ${CFLAGS} ${SRCSPATH}client_bonus.c ${PRINTF_PATH} -o client
		cc ${CFLAGS} ${SRCSPATH}server_bonus.c ${PRINTF_PATH} -o server

client:
		${MAKE} libft
		cc ${CFLAGS} ${SRCSPATH}client.c ${PRINTF_PATH} -o client
		
server:
		${MAKE} libft
		cc ${CFLAGS} ${SRCSPATH}server.c ${PRINTF_PATH} -o server

clean:
		${MAKE} libft clean

fclean: clean
		${MAKE} libft fclean
		rm -f server client

re: fclean all

.PHONY: all clean fclean re

.SILENT:
