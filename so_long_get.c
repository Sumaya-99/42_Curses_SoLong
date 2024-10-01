/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:04:23 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 12:04:34 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	b;

	if (!dstsize)
		return (ft_strlen(src));
	b = 0;
	while (b < (dstsize - 1) && src[b] != '\0')
	{
		dst[b] = src[b];
		b++;
	}
	dst[b] = '\0';
	return (ft_strlen(src));
}
