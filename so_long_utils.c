/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:02:49 by suhelal           #+#    #+#             */
/*   Updated: 2024/05/28 12:05:19 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while ((s1[n] != '\0' || s2[n] != '\0') && s1[n] == s2[n])
		n++;
	return (s1[n] - s2[n]);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar (n + '0');
	else
	{
		ft_putnbr (n / 10);
		ft_putchar (n % 10 + '0');
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (size != 0 && count > UINT_MAX / size)
		return (NULL);
	a = malloc (size * count);
	if (!a)
		return (0);
	ft_bzero (a, size * count);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > (slen - start))
		len = (slen - start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
