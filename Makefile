# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:54:12 by lupayet           #+#    #+#              #
#    Updated: 2025/06/18 16:05:37 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC	= cc
AR = ar rs
CFLAGS	= -Wall -Wextra -Werror -g
RM = rm -f

SRC	= main.c input.c clean.c close.c map.c color.c ./Gnl/get_next_line.c ./Gnl/get_next_line_utils.c

OBJ	= $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) s_fdf.h fdf.h
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L./minilibx-linux/ -lmlx -lXext -lX11 libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
