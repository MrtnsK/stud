/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:13:32 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 13:13:34 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpdest;
	char	*cpsrc;
	size_t	cpt;

	cpt = -1;
	if (n == 0 || src == dest)
		return (dest);
	cpdest = (char*)dest;
	cpsrc = (char*)src;
	while (++cpt < n)
		cpdest[cpt] = cpsrc[cpt];
	return (dest);
}
