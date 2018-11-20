/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 20:37:03 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 15:47:06 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revlst(t_list **list)
{
	t_list *tmp1;
	t_list *tmp2;
	t_list *tmp3;

	if (!(*list) || !(*list)->next)
		return ;
	tmp1 = (*list);
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	tmp1->next = NULL;
	tmp2->next = tmp1;
	while (tmp3)
	{
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->next;
		tmp2->next = tmp1;
	}
	(*list) = tmp2;
}
