/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:34:07 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/06 19:43:16 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] == c)
			tmp = i;
		i++;
	}
	if (tmp != 0)
		return ((char *)(s + tmp));
	return (NULL);
}
