/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:19:31 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 15:35:05 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **list1, t_list *list2)
{
	if ((*list1) == NULL)
		(*list1) = list2;
	else if (!((*list1)->next))
		(*list1)->next = list2;
	else
		ft_lstmerge(&((*list1)->next), list2);
}
