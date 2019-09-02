/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_alias_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:20:02 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/15 22:18:24 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		nothing_next(char *str, int i)
{
	while (str[i] && str[i] != '&' && str[i] != '|' && str[i] != ';'
	&& str[i] != '<' && str[i] != '>')
		i++;
	if (str[i] == '&' || str[i] == '|' || str[i] == ';'
	|| str[i] == '<' || str[i] == '>')
		return (0);
	return (1);
}

t_alias	*ft_create_lst(char *alias, char *name)
{
	t_alias	*als;

	if ((!(als = (t_alias *)malloc(sizeof(t_alias)))))
		return (NULL);
	als->alias = ft_strdup(alias);
	als->name = ft_strdup(name);
	als->next = NULL;
	return (als);
}

void	ft_lst_push_back(t_alias **als, char *alias, char *name)
{
	if (*als)
	{
		if ((*als)->next)
			ft_lst_push_back(&((*als)->next), alias, name);
		else
			(*als)->next = ft_create_lst(alias, name);
	}
	else
		(*als) = ft_create_lst(alias, name);
}

void	ft_lst_show(t_alias *als)
{
	t_alias	*show;

	show = als;
	while (show)
	{
		if (show->alias && show->name)
		{
			ft_putstr(show->alias);
			ft_putstr("=\'");
			ft_putstr(show->name);
			ft_putendl("\'");
		}
		show = show->next;
	}
}

int		ft_lst_clear(t_alias **als)
{
	if (*als)
	{
		free((*als)->name);
		free((*als)->alias);
		ft_lst_clear(&(*als)->next);
		free((*als));
		*als = NULL;
	}
	return (0);
}
