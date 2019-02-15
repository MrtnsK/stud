/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:18:16 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/15 19:18:19 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count(char const *str, char const *set)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (in_set(set, str[i]))
			i++;
		if (str[i])
			nb++;
		while (str[i] && !in_set(set, str[i]))
			i++;
	}
	return (nb);
}

int			*ft_intsplitstr(char const *str, char const *set)
{
	int		*tab;
	int		pos;
	int		i;

	if (!(tab = (int *)malloc(count(str, set) * sizeof(int))))
		return (NULL);
	pos = 0;
	i = 0;
	while (str[i])
	{
		while (in_set(set, str[i]))
			i++;
		if (str[i])
		{
			tab[pos++] = ft_atoi(str + i);
			while (str[i] && !in_set(set, str[i]))
				i++;
		}
	}
	return (tab);
}
