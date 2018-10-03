/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:03:44 by kemartin          #+#    #+#             */
/*   Updated: 2018/09/05 12:18:12 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;
	int n;

	i = 0;
	n = min;
	if (min >= max)
		return (NULL);
	if (!(tab = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (n < max)
	{
		tab[i] = n;
		i++;
		n++;
	}
	return (tab);
}
