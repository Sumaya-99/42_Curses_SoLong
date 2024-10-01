/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:45:56 by suhelal           #+#    #+#             */
/*   Updated: 2024/01/25 08:53:44 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	if (!str)
		return (-1);
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	if (!s1)
		return (NULL);
	a = 0;
	b = 0;
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		str[a] = s2[b];
		a++;
		b++;
	}
	str[a] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == (char)c)
		{
			return ((char *)(s + a));
			break ;
		}
		a++;
	}
	if ((char)c == '\0' && s[a] == '\0')
		return ((char *)(s + a));
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		((char *)s)[a] = 0;
		a++;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*b;
	int		a;
	int		c;

	if (!s1)
		return (NULL);
	c = ft_strlen(s1);
	a = 0;
	b = ((char *)malloc((c + 1) * (sizeof(char))));
	if (!b)
		return (NULL);
	while (s1[a] != '\0')
	{
		b[a] = s1[a];
		a++;
	}
	b[a] = '\0';
	return (b);
}
