/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:37:29 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/27 15:08:28 by kemartin         ###   ########.fr       */
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
	int		j;

	j = spc_cnt(env);
	if (j != 2 || ft_strlen(env) == 0)
	{
		write(1, "usage: setenv [name ...] [data ...]\n", 36);
		return ;
	}
	tab = ft_strsplit(env, ' ');
	ft_lst_push_back(&m->var, tab[1], tab[2]);
	(void)m;
}

void	unset_env(t_ms *m)
{
	int		j;
	t_var	*af;
	char	*del;

	j = spc_cnt(m->cmd);
	if (j != 1 || ft_strlen(m->cmd) == 0)
	{
		write(1, "usage: unsetenv [name ...]\n", 27);
		return ;
	}
	del = ft_strdup(ft_strsub(m->cmd, 9, ft_strlen(m->cmd) - 9));
	if (!(af = m->var))
		return ;
	while (af)
	{
		if (af->name)
			if (!ft_strcmp(af->name, del))
			{
				ft_memdel((void**)&af->name);
				ft_memdel((void**)&af->content);
			}
		af = af->next;
	}
	free(del);
}

void	show_env(t_ms *m, char **env)
{
	t_var	*af;
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putstr(&(*env[i++]));
		ft_putchar('\n');
	}
	if (!(af = m->var))
		return ;
	while (af)
	{
		if (af->name && af->content)
		{
			write(1, af->name, ft_strlen(af->name));
			write(1, "=", 3);
			write(1, af->content, ft_strlen(af->content));
			write(1, "\n", 1);
		}
		af = af->next;
	}
}

void	env_i(t_ms *m, char **env)
{
	(void)env;
	ft_lst_clear(&m->var);
}
