/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:12:20 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 12:29:40 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	right_exit_condition(t_map_det **map, int x, int y)
{
	if ((*map)->data[x][y] == 'P')
	{
		if ((*map)->data[x][y + 1] == 'C')
			(*map)->collectable--;
		if ((*map)->data[x][y + 1] == 'E' && (*map)->collectable == 0)
		{
			mlx_destroy_window((*map)->mlx, (*map)->win);
			free_map(map);
			exit(0);
		}
		if ((*map)->data[x][y + 1] != '1' && (*map)->data[x][y + 1] != 'E')
		{
			(*map)->data[x][y] = '0';
			(*map)->data[x][y + 1] = 'P';
			put_image(map);
			(*map)->mov++;
			write(1, "No. of Movements: ", 18);
			ft_putnbr((*map)->mov);
			write(1, "\n", 1);
			return (1);
		}
	}
	return (0);
}

void	right_movement(t_map_det **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < (*map)->rows)
	{
		y = 0;
		while (y < (*map)->columns)
		{
			if (right_exit_condition(map, x, y))
				return ;
			y++;
		}
		x++;
	}
}
