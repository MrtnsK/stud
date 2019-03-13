/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:37:29 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/13 16:04:57 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		spc_cnt(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		if (str[i++] == ' ')
			j++;
	return (j);
}

void	set_env(char *env, t_ms *m)
{
	char	**tab;
	t_var	*af;
	int		j;

	j = spc_cnt(env);
	if (j != 2 || ft_strlen(env) == 0)
	{
		write(1, "usage: setenv [name ...] [data ...]\n", 36);
		return ;
	}
	af = m->var;
	tab = ft_strsplit(env, ' ');
	while (af)
	{
		if (!ft_strcmp(af->name, tab[1]))
		{
			ft_strdel(&af->content);
			af->content = ft_strdup(tab[2]);
			ft_freetab(tab);
			return ;
		}
		af = af->next;
	}
	ft_lst_push_back(&m->var, tab[1], tab[2]);
	ft_freetab(tab);
}

void	unset_env_while(t_var *af, t_var *prev, t_ms *m, char *del)
{
	while (af)
	{
		if (af->name)
			if (!ft_strcmp(af->name, del))
			{
				if (!ft_strcmp(prev->name, af->name))
				{
					ft_strdel(&m->var->name);
					ft_strdel(&m->var->content);
					m->var = m->var->next;
				}
				else
				{
					prev->next = af->next;
					ft_strdel(&af->name);
					ft_strdel(&af->content);
				}
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
	del = ft_strsub(m->cmd, 9, ft_strlen(m->cmd) - 9);
	if (!(af = m->var))
		return ;
	prev = af;
	unset_env_while(af, prev, m, del);
	free(del);
}

void	init_env(char **env, t_ms *m)
{
	char	**tmp;
	int		j;

	j = 0;
	while (env[j])
	{
		tmp = ft_strsplit(env[j], '=');
		ft_lst_push_back(&m->var, tmp[0], tmp[1]);
		ft_freetab(tmp);
		j++;
	}
}
