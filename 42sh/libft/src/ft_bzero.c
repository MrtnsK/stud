/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:39:36 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/07 13:39:38 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	ft_bzero(void *s, size_t nbyte)
{
	char	*saviour;
	size_t	john;

	john = -1;
	saviour = s;
	while (++john < nbyte)
		saviour[john] = 0;
}
