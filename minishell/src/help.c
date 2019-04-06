/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:32:45 by kemartin          #+#    #+#             */
/*   Updated: 2019/04/06 14:28:08 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_varsize(t_var *list)
{
	if (!list)
		return (0);
	else
		return (ft_varsize(list->next) + 1);
}

void	cd_notfound(char *dir, t_ms *m, char **env)
{
	write(1, "cd: no such file or directory: ", 32);
	ft_putstr(env_find(dir, env, m));
	write(1, "\n", 1);
}

void	show_prompt(void)
{
	char	cwd[1025];

	getcwd(cwd, 1024);
	write(1, "\033[95m", 6);
	ft_putstr(cwd);
	write(1, "\033[0m", 4);
	write(1, "\033[33m 💾  > ", 15);
	write(1, "\033[0m", 4);
}

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
