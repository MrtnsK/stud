/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:12:44 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 13:12:48 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cps;
	size_t			cpt;

	cpt = -1;
	cps = (unsigned char *)s;
	while (++cpt < n)
	{
		if (cps[cpt] == (unsigned char)c)
			return (cps + cpt);
	}
	return (0);
}
