/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:13:31 by agissing          #+#    #+#             */
/*   Updated: 2019/02/13 18:49:51 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param	*ft_create_param(char *name)
{
	t_param		*param;

	if (!(param = (t_param *)ft_memalloc(sizeof(t_param))))
		return (NULL);
	param->next = NULL;
	param->ok = 1;
	param->name = name != NULL ? name : ".";
	if (!(param->child = (t_lst **)ft_memalloc(sizeof(t_lst *))))
		return (NULL);
	*param->child = NULL;
	return (param);
}

void	ft_param_push_back(t_param **param, char *name)
{
	if (*param)
	{
		if ((*param)->next)
			ft_param_push_back(&(*param)->next, name);
		else
			(*param)->next = ft_create_param(name);
	}
	else
		(*param) = ft_create_param(name);
}

void	ft_param_push_after(t_param *param, char *name)
{
	t_param		*tmp;

	if (param->next)
	{
		tmp = param->next;
		param->next = ft_create_param(name);
		param->next->next = tmp;
	}
	else
		param->next = ft_create_param(name);
}

void	paramcpy(t_param *new, t_param *old)
{
	new->ok = old->ok;
	new->name = old->name;
	new->child = old->child;
}
