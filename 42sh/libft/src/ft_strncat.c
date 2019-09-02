/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:15:58 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 13:15:59 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int	i;

	i = -1;
	while (dest[++i])
		;
	while (*src && n--)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}
