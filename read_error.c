/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:20:29 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 12:51:56 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_not_rectangle(void)
{
	write(2, "Error: The map is not accurate!!\n", 34);
	exit(1);
}

void	wrong_file(void)
{
	write(2, "Error: Wrong file name\n", 24);
	exit(1);
}

void	read_error(char *str)
{
	if (str != NULL)
	{
		free (str);
		str = NULL;
	}
	write(2, "Error: There was a problem reading file\n", 40);
	exit(1);
}

void	no_of_arguments(void)
{
	write(2, "Error: Make sure number of arguments are correct!!\n", 52);
	exit(1);
}

void	memory_alloc_free(char *str)
{
	if (str != NULL)
	{
		free (str);
		str = NULL;
	}
	write(2, "Error: Memory allocation failed!!\n", 35);
	exit(1);
}
