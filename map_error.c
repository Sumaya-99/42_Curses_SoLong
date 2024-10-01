/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:56:54 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 08:56:54 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map_det **map)
{
	int	i;

	i = 0;
	if ((*map)->data)
	{
		while (i < (*map)->rows)
		{
			free((*map)->data[i]);
			i++;
		}
		free((*map)->data);
	}
	free((*map)->img_collectable);
	free((*map)->img_tile);
	free((*map)->img_player);
	free((*map)->img_exit);
	free((*map)->img_wall);
	free(*map);
}

void	invalid_error(t_map_det **map)
{
	int	i;

	i = 0;
	if ((*map)->data)
	{
		while (i < (*map)->rows)
		{
			free((*map)->data[i]);
			i++;
		}
		free((*map)->data);
	}
	free(*map);
	write(2, "Error: There is an invalid character!!\n", 40);
	exit(1);
}

void	collectable_error(t_map_det **map)
{
	int	i;

	i = 0;
	if ((*map)->data)
	{
		while (i < (*map)->rows)
		{
			free((*map)->data[i]);
			i++;
		}
		free((*map)->data);
	}
	free(*map);
	write(2, "Error: No. of collectables not enough!!\n", 41);
	exit(1);
}

void	exit_error(t_map_det **map)
{
	int	i;

	i = 0;
	if ((*map)->data)
	{
		while (i < (*map)->rows)
		{
			free((*map)->data[i]);
			i++;
		}
		free((*map)->data);
	}
	free(*map);
	write(2, "Error: There should be 1 exit!!\n", 33);
	exit(1);
}

void	player_error(t_map_det **map)
{
	int	i;

	i = 0;
	if ((*map)->data)
	{
		while (i < (*map)->rows)
		{
			free((*map)->data[i]);
			i++;
		}
		free((*map)->data);
	}
	free(*map);
	write(2, "Error: There should be 1 player!!\n", 35);
	exit(1);
}
