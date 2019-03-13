/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:35:27 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/13 11:16:06 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int		cmpt;
	int		i;

	cmpt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			cmpt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cmpt);
}

static char	**ft_split(char **tab, char c, size_t l, const char *str)
{
	size_t	save;
	size_t	i;
	size_t	n;

	save = 0;
	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		save = i;
		while (str[i] != c && str[i])
		{
			i++;
			l++;
		}
		tab[n] = ft_strsub(str, save, l);
		n++;
		l = 0;
	}
	tab[n] = 0;
	return (tab);
}

char		**ft_strsplit(const char *str, char c)
{
	int		m;
	size_t	l;
	char	**tab;

	if (str == NULL)
		return (NULL);
	l = 0;
	m = count_word(str, c);
	if (!(tab = malloc(sizeof(char *) * (m + 1))))
		return (NULL);
	return (ft_split(tab, c, l, str));
}
