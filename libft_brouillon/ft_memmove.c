/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:23:41 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/05 18:20:02 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	cpy;

	if (!((void *)malloc(sizeof(void *) * n)))
		return (NULL);
	ft_memcpy(cpy, src, n);
	ft_memcpy(dest, cpy, n);
	free(cpy);
	return (dest);
}
