# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:54:12 by lupayet           #+#    #+#              #
#    Updated: 2025/06/06 13:17:45 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC	= cc
AR = ar rs
CFLAGS	= -Wall -Wextra -Werror
RM = rm -f

SRC	= main.c

OBJ	= $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

