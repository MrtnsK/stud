/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:34:07 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/07 14:35:19 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			tmp = (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (tmp);
}
