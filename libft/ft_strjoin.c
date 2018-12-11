/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:07:39 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 15:11:29 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if (!(res = ft_strnew(len1 + len2 + 1)))
		return (NULL);
	i = -1;
	while (i++ < len1)
		res[i] = s1[i];
	i = -1;
	while (i++ < len2)
		res[len1 + i] = s2[i];
	res[len1 + i] = '\0';
	return (res);
}
