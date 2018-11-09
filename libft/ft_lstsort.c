/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:08:22 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/09 15:36:31 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **list)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;
	void	*trie;

	tmp1 = (*list);
	while (tmp1)
	{
		tmp3 = tmp1;
		trie = tmp1->content;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(trie, tmp2->content) > 0)
			{
				tmp3 = tmp2;
				trie = tmp3->content;
			}
			tmp2 = tmp2->next;
		}
		tmp3->content = tmp1->content;
		tmp1->content = trie;
		tmp1 = tmp1->next;
	}
}
