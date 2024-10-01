/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:23:26 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 11:43:29 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_PRESS			2
# define KEY_RELEASE		3

# define ESC				53
# define W					13
# define A					0
# define S					1
# define D					2
# define ARROW_KEY_LEFT		123
# define ARROW_KEY_RIGHT	124
# define ARROW_KEY_UP		126
# define ARROW_KEY_DOWN		125
# define X_EXIT_KEY		17

# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
	int		x;
	int		y;
}			t_img;

typedef struct map_det
{
	char	**data;
	void	*mlx;
	void	*win;
	t_img	*img_tile;
	t_img	*img_player;
	t_img	*img_wall;
	t_img	*img_collectable;
	t_img	*img_exit;
	int		mov;
	int		wall;
	int		rows;
	int		columns;
	int		player;
	int		exit;
	int		pl_pos_x;
	int		pl_pos_y;
	int		collectable;
}			t_map_det;

/*ERROR MESSAGES*/
void	map_not_rectangle(void);
void	wrong_file(void);
void	no_of_arguments(void);
void	memory_alloc_free(char *str);
void	memory_alloc_double_free(char **str);
void	collectable_error(t_map_det **map);
void	wall_error(t_map_det **map);
void	exit_error(t_map_det **map);
void	player_error(t_map_det **map);
void	no_valid_path(t_map_det **map);
void	invalid_error(t_map_det **map);
void	read_error(char *str);
void	double_free(char **str);
void	free_map(t_map_det **map);
void	free_str(char *str);

/*UTILS*/
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
void	*ft_calloc(size_t count, size_t size);

/*MAP PARSING AND ERROR CHECK*/
int		check_length(char *str, t_map_det **map, char *filename);
void	map_parsing(t_map_det **map, char *filename);
void	check_for_collectable(t_map_det **map);
void	check_for_exit(t_map_det **map);
void	check_for_player(t_map_det **map);
void	valid_path(t_map_det **map, int x, int y);
void	check_for_invalid(t_map_det **map);
int		check_for_empty_lines(t_map_det **map, char *filename);
void	check_map_accuarte(t_map_det *map, char *filename);

/*MLX*/
void	put_image(t_map_det **map);
void	image_copy_1(t_map_det **map);
void	up_movement(t_map_det **map);
void	down_movement(t_map_det **map);
void	right_movement(t_map_det **map);
void	left_movement(t_map_det **map);
void	image_copy_2(t_map_det **map);

#endif