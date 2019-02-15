/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:28:07 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/12 19:28:40 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *node, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	while (i < nbr)
	{
		node = node->next;
		i++;
	}
	if (i == nbr)
		return (&(*node));
	else
		return (NULL);
}
