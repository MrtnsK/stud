/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:10:08 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/11 19:42:28 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		d_len;
	size_t		s_len;

	i = 0;
	d_len = ft_strlen((char *)dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (s_len + size);
	while (dest[i] && i < size - 1)
		i++;
	while (*src && i < size - 1)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (d_len + s_len);
}
