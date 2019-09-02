/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_unalias.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:34:42 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/16 09:18:45 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	first_unalias(t_alias **als)
{
	void		*t;

	t = (*als);
	ft_strdel(&(*als)->alias);
	ft_strdel(&(*als)->name);
	(*als) = (*als)->next;
	free(t);
}

void	unalias_helper(t_alias *tmp, t_alias *prev)
{
	ft_strdel(&tmp->alias);
	ft_strdel(&tmp->name);
	if (tmp->next)
		prev->next = tmp->next;
	else
		prev->next = NULL;
	free(tmp);
}

int		unalias_usage(void)
{
	ft_printfd(2, "unalias: usage: unalias [-a] name [name ...]\n");
	return (1);
}

int		unalias_while(t_alias **als, char *del)
{
	t_alias		*tmp;
	t_alias		*prev;

	if (!del)
		return (1);
	tmp = (*als);
	while (tmp)
	{
		if (tmp->alias && !ft_strcmp(del, tmp->alias))
		{
			if (!ft_strcmp((*als)->alias, tmp->alias))
				first_unalias(als);
			else
				unalias_helper(tmp, prev);
			return (0);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	ft_printfd(2, "\e[93mMastershell\e[0m: unalias: %s: not found\n", del);
	return (1);
}

int		unalias(t_masterenv **tenv, char **del)
{
	int			ret;
	int			i;
	int			cgc;

	ret = 0;
	i = 1;
	cgc = ft_tablen(del);
	if (cgc == 1)
		return (unalias_usage());
	if (cgc >= 2 && !ft_strcmp(del[1], "-a"))
		return (ft_lst_clear(&(*tenv)->als));
	while (i <= cgc && del[i])
	{
		ret += unalias_while(&(*tenv)->als, del[i]);
		i++;
	}
	return (ret ? 1 : 0);
}
