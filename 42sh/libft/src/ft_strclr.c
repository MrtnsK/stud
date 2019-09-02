/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:45:43 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/04 09:33:26 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
			*(s++) = 0;
	}
}

int		ft_strchri(const char *s, int c)
{
	int i;

	i = 0;
	if (c == 0)
		return (ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_strrchri(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	if (c == 0)
		return (ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i--;
	}
	return (-1);
}
