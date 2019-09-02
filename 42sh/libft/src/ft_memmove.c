/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:13:50 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 13:13:51 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cpdest;
	char	*cpsrc;
	size_t	i;

	i = -1;
	cpdest = (char *)dest;
	cpsrc = (char *)src;
	if ((cpsrc - cpdest) < 0)
	{
		while (n--)
			*(cpdest + n) = *(cpsrc + n);
	}
	else
	{
		while (++i < n)
			*(cpdest + i) = *(cpsrc + i);
	}
	return (dest);
}
