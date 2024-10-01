/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:37:00 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 09:58:47 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_collectable(t_map_det **map)
{
	int	x;
	int	y;

	x = 0;
	(*map)->collectable = 0;
	while (x < (*map)->rows)
	{
		y = 0;
		while (y < (*map)->columns)
		{
			if ((*map)->data[x][y] == 'C')
				(*map)->collectable++;
			y++;
		}
		x++;
	}
	if ((*map)->collectable < 1)
		collectable_error(map);
}

void	check_for_invalid(t_map_det **map)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*map)->rows)
	{
		y = 0;
		while (y < (*map)->columns)
		{
			if ((*map)->data[x][y] != 'C' && (*map)->data[x][y] != '1'
				&& (*map)->data[x][y] != '0' && (*map)->data[x][y] != 'E'
				&& (*map)->data[x][y] != 'P')
				invalid_error(map);
			y++;
		}
		x++;
	}
}

void	check_for_exit(t_map_det **map)
{
	int	x;
	int	y;

	x = 0;
	(*map)->exit = 0;
	while (x < (*map)->rows)
	{
		y = 0;
		while (y < (*map)->columns)
		{
			if ((*map)->data[x][y] == 'E')
				(*map)->exit++;
			y++;
		}
		x++;
	}
	if ((*map)->exit < 1 || (*map)->exit > 1)
		exit_error(map);
}

void	check_for_player(t_map_det **map)
{
	int	x;
	int	y;

	x = 0;
	(*map)->player = 0;
	(*map)->pl_pos_y = 0;
	(*map)->pl_pos_x = 0;
	while (x < (*map)->rows)
	{
		y = 0;
		while (y < (*map)->columns)
		{
			if ((*map)->data[x][y] == 'P')
			{
				(*map)->pl_pos_x = x;
				(*map)->pl_pos_y = y;
				(*map)->player++;
			}
			y++;
		}
		x++;
	}
	if ((*map)->player < 1 || (*map)->player > 1)
		player_error(map);
}
