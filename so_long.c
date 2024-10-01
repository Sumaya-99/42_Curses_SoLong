/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:11:43 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 11:52:11 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argument(int ac, char **av, char *filename)
{
	size_t	length;

	if (av[1])
		length = ft_strlen(av[1]);
	else
		no_of_arguments();
	if (ac == 2)
	{
		if ((ft_strcmp(filename + (length - 4), ".ber")) != 0)
			wrong_file();
	}
	else
		no_of_arguments();
}

int	keys(int keycode, t_map_det **map)
{
	if (keycode == W)
		up_movement(map);
	else if (keycode == S)
		down_movement(map);
	else if (keycode == A)
		left_movement(map);
	else if (keycode == D)
		right_movement(map);
	if (keycode == ARROW_KEY_UP)
		up_movement(map);
	else if (keycode == ARROW_KEY_DOWN)
		down_movement(map);
	else if (keycode == ARROW_KEY_LEFT)
		left_movement(map);
	else if (keycode == ARROW_KEY_RIGHT)
		right_movement(map);
	else if (keycode == ESC)
	{
		mlx_destroy_window((*map)->mlx, (*map)->win);
		free_map(map);
		exit(0);
	}
	return (0);
}

int	exit_game(t_map_det **map)
{
	mlx_destroy_window((*map)->mlx, (*map)->win);
	free_map(map);
	exit(0);
}

int	main(int ac, char **av)
{
	char		*filename;
	t_map_det	*map;

	filename = av[1];
	map = NULL;
	map = ft_calloc(1, sizeof(t_map_det));
	ft_bzero(map, sizeof(t_map_det));
	check_argument(ac, av, filename);
	map_parsing(&map, filename);
	map->mlx = mlx_init();
	image_copy_1(&map);
	image_copy_2(&map);
	map->win = mlx_new_window(map->mlx, map->columns * 40, map->rows * 40,
			"Sumaya's So_Long!");
	put_image(&map);
	mlx_hook(map->win, KEY_PRESS, 0, &keys, &map);
	mlx_hook(map->win, X_EXIT_KEY, 0, &exit_game, &map);
	mlx_loop(map->mlx);
}
