# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:54:12 by lupayet           #+#    #+#              #
#    Updated: 2025/07/19 19:04:14 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = fdf

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM = rm -f
LIBFT_P = ./libft/
MLX_P = ./minilibx-linux/
LIBFT = $(LIBFT_P)libft.a
MLX = $(MLX_P)libmlx_Linux.a


SRC	= main.c input.c input2.c clean.c close.c map.c color.c draw.c render.c \
		render2.c project.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
		color_utils.c gradiant.c

OBJ	= $(SRC:.c=.o)

%.o: %.c fdf.h s_fdf.h
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(MLX):
	@echo "\nCOMPILING MLX..."
	@make -C $(MLX_P) 1>/dev/null 2>/dev/null
	@echo "> MLX CREATED"

$(LIBFT):
	@echo "\nCOMPILING LIBFT..."
	@make -C $(LIBFT_P) 1>/dev/null
	@echo "> LIBFT CREATED"

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@echo "\nCOMPILING FDF..."
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L./minilibx-linux/ -lmlx -lXext -lX11 -lm $(LIBFT_P)libft.a -o $(NAME)
	@echo "> FDF READY"

clean:
	@make clean -C $(MLX_P) 1>/dev/null 2>/dev/null
	@make clean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(NAME)

re:fclean all

dev: re
	@make clean 1>/dev/null

.PHONY: all clean fclean re dev
