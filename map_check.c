/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:02:22 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 12:01:33 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_length(char *str, t_map_det **map, char *filename)
{
	size_t	len;
	size_t	comp_len;
	int		fd;
	int		a;

	a = 0;
	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	len = ft_strlen(str);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (str)
			comp_len = ft_strlen(str);
		else
			break ;
		if (comp_len != len || len >= 200 || comp_len >= 200)
			a = -1;
		(*map)->rows++;
	}
	(*map)->columns = len;
	close(fd);
	return (a);
}

void	map_copy(t_map_det **map, char *filename)
{
	int		fd;
	int		x;
	char	*str;

	x = 0;
	(*map)->data = (char **)malloc((sizeof(char *) * (*map)->rows + 1));
	if (!(*map)->data)
		return ;
	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		(*map)->data[x] = (char *)malloc((*map)->columns + 1);
		if (!(*map)->data[x])
			return ;
		ft_strlcpy((*map)->data[x], str, (*map)->columns + 1);
		free(str);
		x++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}

void	check_for_walls(t_map_det **map)
{
	int	len;
	int	y;
	int	x;
	int	col;

	len = (*map)->rows - 1;
	y = 0;
	x = 0;
	col = ((*map)->columns - 1);
	while ((*map)->data[0][y] != '\0'
		|| (*map)->data[len][y] != '\0')
	{
		if ((*map)->data[0][y] != '1'
			|| (*map)->data[len][y] != '1')
			wall_error(map);
		y++;
	}
	while (x < (*map)->rows)
	{
		if ((*map)->data[x][0] != '1'
			|| (*map)->data[x][col] != '1')
			wall_error(map);
		x++;
	}
}

void	map_parsing(t_map_det **map, char *filename)
{
	int		x;
	int		y;
	char	*str;

	(*map)->rows = 0;
	(*map)->columns = 0;
	str = NULL;
	x = 0;
	if (check_length(str, map, filename) < 0)
		(free(*map), map_not_rectangle());
	if (check_for_empty_lines(map, filename) < 0)
		(free(*map), read_error(str));
	(*map)->rows++;
	map_copy(map, filename);
	check_for_invalid(map);
	check_for_walls(map);
	check_for_collectable(map);
	check_for_exit(map);
	check_for_player(map);
	x = (*map)->pl_pos_x;
	y = (*map)->pl_pos_y;
	valid_path(map, x, y);
}
