/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:32:45 by kemartin          #+#    #+#             */
/*   Updated: 2019/04/05 19:57:34 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_replace(char **old, char *new)
{
	ft_strdel(old);
	(*old) = ft_strdup(new);
}

void	set_oldpwd(t_ms *m, char cwd[1025])
{
	t_var	*af;
	char	*tmp;

	af = m->var;
	tmp = "";
	while (af && af->name)
	{
		if (!ft_strcmp(af->name, "PWD"))
		{
			tmp = ft_strdup(af->content);
			ft_replace(&af->content, cwd);
		}
		if (!ft_strcmp(af->name, "OLDPWD"))
			ft_replace(&af->content, tmp);
		af = af->next;
	}
	ft_strdel(&tmp);
}
