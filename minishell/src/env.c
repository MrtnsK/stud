/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:37:29 by kemartin          #+#    #+#             */
/*   Updated: 2019/04/30 15:57:41 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(char *env, t_ms *m, char **origin_env)
{
	char	**tab;
	t_var	*af;
	int		j;

	j = spc_cnt(env);
	if (j != 2 || ft_strlen(env) == 0)
		return (ft_putstr("usage: setenv [name ...] [data ...]\n"));
	af = m->var;
	tab = ft_strsplit(env, ' ');
	while (af)
	{
		if (!ft_strcmp(af->name, tab[1]))
		{
			ft_strdel(&af->content);
			af->content = ft_strdup(env_find(tab[2], origin_env, m));
			ft_freetab(tab);
			return ;
		}
		af = af->next;
	}
	ft_lst_push_back(&m->var, tab[1], tab[2]);
	ft_freetab(tab);
}

void	freenc(char *name, char *content)
{
	ft_strdel(&name);
	ft_strdel(&content);
}

void	unset_env_while(t_var *af, t_var *prev, t_ms *m, char *del)
{
	void	*tmp;

	while (af)
	{
		if (af->name)
			if (!ft_strcmp(af->name, del))
			{
				if (!ft_strcmp(prev->name, af->name))
				{
					tmp = m->var;
					m->var = m->var->next;
					freenc(m->var->name, m->var->content);
				}
				else
				{
					tmp = prev->next;
					prev->next = af->next;
					freenc(af->name, af->content);
				}
				tmp ? free(tmp) : 0;
				break ;
			}
		prev = af;
		af = af->next;
	}
}

void	unset_env(t_ms *m)
{
	int		j;
	t_var	*af;
	t_var	*prev;
	char	*del;

	j = spc_cnt(m->cmd);
	if (j != 1 || ft_strlen(m->cmd) == 0)
	{
		write(1, "usage: unsetenv [name ...]\n", 27);
		return ;
	}
	del = ft_strdup(m->cmd + 9);
	if (!(af = m->var))
		return ;
	prev = af;
	unset_env_while(af, prev, m, del);
	ft_strdel(&del);
}

void	init_env(char **env, t_ms *m)
{
	char	**tmp;
	int		j;

	j = 0;
	while (env[j])
	{
		tmp = ft_strsplit(env[j], '=');
		if (tmp && tmp[0] && tmp[1])
			ft_lst_push_back(&m->var, tmp[0], tmp[1]);
		ft_freetab(tmp);
		j++;
	}
}
