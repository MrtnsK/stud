/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:43:08 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/27 11:15:43 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	*ft_memalloc(size_t size)
{
	void	*out;

	if (!(out = malloc(size)))
		return (0);
	ft_bzero(out, size);
	return (out);
}
