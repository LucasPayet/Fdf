# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupayet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:54:12 by lupayet           #+#    #+#              #
#    Updated: 2025/07/20 17:09:49 by lupayet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = fdf
BONUS = fdf_bonus

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM = rm -f
LIBFT_P = ./libft/
MLX_P = ./minilibx-linux/
LIBFT = $(LIBFT_P)libft.a
MLX = $(MLX_P)libmlx_Linux.a


SRC	= main.c input.c input2.c clean.c close.c map.c draw.c render.c \
	  project.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

BONUS_SRC	= main_bonus.c input_bonus.c input2_bonus.c clean_bonus.c \
			  close_bonus.c map_bonus.c color_bonus.c draw_bonus.c render_bonus.c \
			  render2_bonus.c project_bonus.c ./gnl/get_next_line.c \
			  ./gnl/get_next_line_utils.c color_utils_bonus.c gradiant_bonus.c

OBJ	= $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

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
	@rm -f $(BONUS_OBJ)

fclean: clean
	@make fclean -C $(LIBFT_P) 1>/dev/null
	@rm -f $(NAME)

$(BONUS): $(MLX) $(LIBFT) $(BONUS_OBJ)
	@echo "\nCOMPILING FDF BONUS..."
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -Lmlx_linux -lmlx_Linux -L./minilibx-linux/ -lmlx -lXext -lX11 -lm $(LIBFT_P)libft.a -o $(BONUS)
	@echo "> BONUS READY"

bonus: $(BONUS)

re:fclean all

rebonus: fclean bonus

dev: re
	@make clean 1>/dev/null

devbonus: rebonus
	@make clean 1>/dev/null

.PHONY: all clean fclean re dev
