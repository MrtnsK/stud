/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:50:48 by apsaint-          #+#    #+#             */
/*   Updated: 2019/06/28 14:25:09 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static	int		sizetab(const char *s, char c)
{
	int taille;
	int	i;
	int	b;

	taille = 0;
	i = 0;
	b = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c && b == 1)
			b = 0;
		if (s[i] != '\0' && b == 0)
		{
			b = 1;
			taille++;
		}
		i++;
	}
	return (taille);
}

static	int		sizemot(int index, const char *s, char c)
{
	int taille_mot;

	taille_mot = 0;
	while (s[index] != c && s[index])
	{
		taille_mot++;
		index++;
	}
	return (taille_mot);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tabsplit;
	int			size;
	int			i;
	int			j;

	i = 0;
	j = 0;
	size = sizetab(s, c);
	if (!(tabsplit = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (size--)
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			if ((tabsplit[j] = ft_strsub(s, i, sizemot(i, s, c))) == NULL)
				return (NULL);
			i += sizemot(i, s, c);
			j++;
		}
	}
	tabsplit[j] = NULL;
	return (tabsplit);
}
