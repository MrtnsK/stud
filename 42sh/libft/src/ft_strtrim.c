/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:48:39 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/16 11:44:15 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strtrim(char const *s)
{
	char	*out;
	int		len;
	int		i;

	i = -1;
	if (!s)
		return (0);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n'
		|| s[len - 1] == '\v' || s[len - 1] == '\r')
		len--;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\r')
		len--;
	if (len < 0)
		len = 0;
	if (!(out = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	s = s + i;
	i = -1;
	while (++i < len)
		out[i] = *s++;
	out[i] = 0;
	return (out);
}

int		ft_len(char *s)
{
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(s);
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\r')
			if (s[i + 1] && !ft_isdigit(s[i + 1]))
				len--;
	}
	return (len);
}

void	ft_strtrim_calc(char **s)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	i = -1;
	len = ft_len(s[0]);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return ;
	j = 0;
	while (s[0][++i])
	{
		if (s[0][i] == ' ' || s[0][i] == '\t' || s[0][i] == '\n'
		|| s[0][i] == '\v' || s[0][i] == '\r')
		{
			if (s[0][i + 1] && !ft_isdigit(s[0][i + 1]))
				continue ;
			tmp[j++] = s[0][i];
		}
		else
			tmp[j++] = s[0][i];
	}
	tmp[j] = 0;
	free(s[0]);
	s[0] = tmp;
}
