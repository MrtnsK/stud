/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:50:15 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 10:50:20 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char *)s);
	while (s[i] != (char)c && i)
		i--;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int		ft_strcpt(const char *s, int c)
{
	int	i;
	int	out;

	i = -1;
	out = 0;
	while (s[++i])
		if (s[i] == c)
			out++;
	return (out);
}

int		ft_strrdigit(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]))
			return (1);
	return (0);
}
