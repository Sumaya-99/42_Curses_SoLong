/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:56:41 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 08:56:41 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	memory_alloc_double_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	write(2, "Error: Memory allocation failed!!\n", 35);
	exit(1);
}

void	double_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	wall_error(t_map_det **map)
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
	write(2, "Error: There are no walls surrounding map!!\n", 45);
	exit(1);
}

void	no_valid_path(t_map_det **map)
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
	write(2, "Error: There is no valid path!!\n", 33);
	exit(1);
}
