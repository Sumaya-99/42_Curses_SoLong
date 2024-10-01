# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 10:49:09 by suhelal           #+#    #+#              #
#    Updated: 2024/05/28 12:20:29 by suhelal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES 	   = so_long.c down_movement.c so_long_get.c left_movement.c map_error.c mlx_func.c path_error.c right_movement.c up_movement.c read_error.c map_check.c map_error_check.c so_long_utils.c check_path.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

PROGRAM_NAME = so_long

CC	= cc

CFLAGS	= -Wall -Wextra -Werror 

MLXFLAGS = -L ./mlx -lmlx -Ilmlx -framework OpenGL -framework AppKit

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

NAME	= so_long

all: $(NAME)

$(NAME): $(CFILES)
	$(MAKE) -C $(MINILIBX_PATH)
	$(CC) $(CFLAGS) $(CFILES) $(MLXFLAGS) -o $(NAME)

clean: clean
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: clean $(NAME)
