/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:41:13 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/26 19:29:15 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map, int x, int y, char visited)
{
	if (map[x][y] == '1' || map[x][y] == visited || map[x][y] == '\0')
		return (-1);
	map[x][y] = visited;
	check_map(map, x + 1, y, visited);
	check_map(map, x - 1, y, visited);
	check_map(map, x, y + 1, visited);
	check_map(map, x, y - 1, visited);
	return (0);
}

void	copy_map(t_map_det **map, char **map_replica)
{
	int	a;

	a = 0;
	while (a < (*map)->rows)
	{
		map_replica[a] = (char *)malloc(sizeof(char) * (*map)->columns + 1);
		if (!map_replica[a])
			return ;
		ft_strlcpy(map_replica[a], (*map)->data[a], (*map)->columns + 1);
		a++;
	}
}

void	valid_path(t_map_det **map, int x, int y)
{
	char	**map_replica;
	int		a;
	int		b;

	a = 0;
	b = 0;
	map_replica = (char **)ft_calloc(((*map)->rows + 1), sizeof(char *));
	copy_map(map, map_replica);
	check_map(map_replica, x, y, 'V');
	while (a < (*map)->rows)
	{
		b = 0;
		while (b < (*map)->columns)
		{
			if (map_replica[a][b] == 'E' || map_replica[a][b] == 'C')
			{
				double_free(map_replica);
				no_valid_path(map);
			}
			b++;
		}
		a++;
	}
	double_free(map_replica);
}

int	check_for_empty_lines(t_map_det **map, char *filename)
{
	int		fd;
	char	*str;
	int		a;
	size_t	map_length;

	a = 0;
	map_length = (*map)->columns;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	if (str == NULL)
		a = -1;
	while (str)
	{
		if (ft_strlen(str) == 0 || ft_strlen(str) > map_length)
			a = -1;
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	return (a);
}
