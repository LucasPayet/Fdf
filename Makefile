# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:54:12 by lupayet           #+#    #+#              #
#    Updated: 2025/07/15 13:42:35 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC	= cc
AR = ar rs
CFLAGS	= -Wall -Wextra -Werror -g
RM = rm -f
LIBFT_P = ./libft/
MLX_P = ./minilibx-linux/


SRC	= main.c input.c input2.c clean.c close.c map.c color.c draw.c render.c \
		project.c ./Gnl/get_next_line.c ./Gnl/get_next_line_utils.c

OBJ	= $(SRC:.c=.o)

%.o: %.c fdf.h s_fdf.h
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(MLX):
	make -C $(MLX_P)

$(LIBFT):
	make -C $(LIBFT_P)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L./minilibx-linux/ -lmlx -lXext -lX11 -lm $(LIBFT_P)libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
