/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:31:30 by agissing          #+#    #+#             */
/*   Updated: 2019/02/13 18:21:32 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free(t_param **tab)
{
	t_param	*tmp;
	t_lst	*tmp1;
	t_param	*tmp2;

	tmp = *tab;
	while (tmp)
	{
		while (*tmp->child)
		{
			tmp1 = (*tmp->child)->next;
			free((*tmp->child)->name);
			free(*tmp->child);
			*tmp->child = tmp1;
		}
		free(tmp->child);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}
