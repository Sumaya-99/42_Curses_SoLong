/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:22:50 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 12:02:38 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_copy_1(t_map_det **map)
{
	(*map)->img_tile = malloc(sizeof(t_img));
	(*map)->img_wall = malloc(sizeof(t_img));
	(*map)->img_tile->img = mlx_xpm_file_to_image((*map)->mlx,
			"./map_image/tile.xpm", &(*map)->img_tile->w, &(*map)->img_tile->h);
	if (!(*map)->img_tile->img)
		(write(2, "Error: Image file/data not accurate!\n", 37),
			exit(1), free((*map)->img_tile));
	(*map)->img_wall->img = mlx_xpm_file_to_image((*map)->mlx,
			"./map_image/wall.xpm", &(*map)->img_wall->w, &(*map)->img_wall->h);
	if (!(*map)->img_wall->img)
		(write(2, "Error: Image file/data not accurate!\n", 37),
			exit(1), free((*map)->img_wall));
}

void	image_copy_2(t_map_det **map)
{
	(*map)->img_player = malloc(sizeof(t_img));
	(*map)->img_exit = malloc(sizeof(t_img));
	(*map)->img_collectable = malloc(sizeof(t_img));
	(*map)->img_player->img = mlx_xpm_file_to_image((*map)->mlx,
			"./map_image/player.xpm", &(*map)->img_player->w,
			&(*map)->img_player->h);
	if (!(*map)->img_player->img)
		(write(2, "Error: Image file/data not accurate!\n", 37),
			exit(1), free((*map)->img_player));
	(*map)->img_exit->img = mlx_xpm_file_to_image((*map)->mlx,
			"./map_image/exit.xpm", &(*map)->img_exit->w, &(*map)->img_exit->h);
	if (!(*map)->img_exit->img)
		(write(2, "Error: Image file/data not accurate!\n", 37),
			exit(1), free((*map)->img_exit));
	(*map)->img_collectable->img = mlx_xpm_file_to_image((*map)->mlx,
			"./map_image/collectable.xpm", &(*map)->img_collectable->w,
			&(*map)->img_collectable->w);
	if (!(*map)->img_collectable->img)
		(write(2, "Error: Image file/data not accurate!\n", 37),
			exit(1), free((*map)->img_collectable));
}

void	image_conditions(t_map_det **map, int height, int width)
{
	if ((*map)->data[height][width] == '1')
		mlx_put_image_to_window((*map)->mlx, (*map)->win,
			(*map)->img_wall->img, width * 40, height * 40);
	else
		mlx_put_image_to_window((*map)->mlx, (*map)->win,
			(*map)->img_tile->img, width * 40, height * 40);
	if ((*map)->data[height][width] == 'P')
		mlx_put_image_to_window((*map)->mlx, (*map)->win,
			(*map)->img_player->img, width * 40, height * 40);
	else if ((*map)->data[height][width] == 'C')
		mlx_put_image_to_window((*map)->mlx, (*map)->win,
			(*map)->img_collectable->img, width * 40, height * 40);
	else if ((*map)->data[height][width] == 'E')
		mlx_put_image_to_window((*map)->mlx, (*map)->win,
			(*map)->img_exit->img, width * 40, height * 40);
}

void	put_image(t_map_det **map)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (height < (*map)->rows)
	{
		width = 0;
		while (width < (*map)->columns)
		{
			image_conditions(map, height, width);
			width++;
		}
		height++;
	}
}
