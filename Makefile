# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 22:39:07 by bsousa-d          #+#    #+#              #
#    Updated: 2023/11/26 22:51:37 by bsousa-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
PRINTF_PATH = libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all: 	
		${MAKE} libft
		cc ${CFLAGS} client.c ${PRINTF_PATH} -o client
		cc ${CFLAGS} server.c ${PRINTF_PATH} -o server

clean:
		${MAKE} libft clean

fclean: clean
		${MAKE} libft fclean
		rm -f server client

re: fclean all

.PHONY: all clean fclean re

.SILENT:
