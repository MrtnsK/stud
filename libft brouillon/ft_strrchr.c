/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:34:07 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/05 18:48:21 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	int i;
	int tmp;

	i = 0
	tmp = 0;
	while (str[i])
	{
		if (str[i] == c)
			tmp = i;
		i++;
	}
	if (tmp != 0)
		return (str + tmp);
	return (NULL);
}
