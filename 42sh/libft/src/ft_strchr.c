/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:14:19 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/27 09:43:52 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	return (0);
}

char	*ft_strchrstr(const char *s, char *find)
{
	int i;
	int j;

	if (!find)
		return ((char *)s + ft_strlen(s));
	i = -1;
	while (s[++i])
	{
		if (s[i] == find[0])
		{
			j = 0;
			while (s[j + i] == find[j] && find[j] && s[j + i])
				j++;
			if (find[j] == 0)
				return ((char*)(s + i));
		}
	}
	return (0);
}

int		ft_strchralpha(const char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (!ft_isspace(s[i]))
			return (1);
	return (0);
}

int		ft_strnchralpha(const char *s, int n)
{
	int i;

	i = -1;
	while (s[++i] && i < n)
		if (!ft_isspace(s[i]))
			return (1);
	return (0);
}

int		ft_strchrstrfirst(const char *s, char *find)
{
	int i;

	if (!find)
		return (1);
	i = 0;
	while (find[i] && s[i] && s[i] == find[i])
		i++;
	if (!find[i])
		return (1);
	return (0);
}
