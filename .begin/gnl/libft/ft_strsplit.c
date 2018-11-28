/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:42:19 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 14:59:33 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(const char *s, char c)
{
	int			cmpt;
	int			i;

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

static	char	**ft_split(char **tab, char c, size_t l, const char *str)
{
	size_t		save;
	size_t		i;
	size_t		n;

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
		if (!(tab[n] = malloc(sizeof(char) * (l + 1))))
			return (NULL);
		tab[n] = ft_strsub(str, save, l);
		n++;
		l = 0;
	}
	return (tab);
}

char			**ft_strsplit(const char *str, char c)
{
	int			m;
	size_t		l;
	char		**tab;
	int			n;

	if (str == NULL)
		return (NULL);
	m = count_word(str, c);
	n = 0;
	l = 0;
	if (!(tab = malloc(sizeof(char *) * (m + 1))))
		return (NULL);
	tab = ft_split(tab, c, l, str);
	tab[count_word(str, c)] = 0;
	return (tab);
}
