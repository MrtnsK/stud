/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:11:57 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 13:12:01 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*cpdest;
	const char	*cpsrc;

	cpdest = dest;
	cpsrc = src;
	while (n--)
	{
		*cpdest = *cpsrc;
		if (*cpdest == (char)c)
			return ((void *)(++cpdest));
		cpdest++;
		cpsrc++;
	}
	return (0);
}
