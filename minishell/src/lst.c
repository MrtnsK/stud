/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:11:37 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/27 11:36:14 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*ft_create_lst(char *name, char *data)
{
	t_var	*var;

	if ((!(var = (t_var *)ft_memalloc(sizeof(t_var)))))
		return (NULL);
	var->name = ft_strdup(name);
	var->content = ft_strdup(data);
	var->next = NULL;
	return (var);
}

void	ft_lst_push_back(t_var **var, char *name, char *data)
{
	if (*var)
	{
		if ((*var)->next)
			ft_lst_push_back(&((*var)->next), name, data);
		else
			(*var)->next = ft_create_lst(name, data);
	}
	else
		(*var) = ft_create_lst(name, data);
}

void	ft_lst_clear(t_var **var)
{
	if (*var)
	{
		free((*var)->name);
		free((*var)->content);
		ft_lst_clear(&(*var)->next);
		free((*var));
		*var = NULL;
	}
}
