/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:37:29 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/27 10:53:13 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(char *env, t_ms *m)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
		if (env[i++] == ' ')
			j++;
	if (j != 2 || i == 0)
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
	int		i;
	int		j;
	t_var	*af;
	char	*del;

	i = 0;
	j = 0;
	while (m->cmd[i])
		if (m->cmd[i++] == ' ')
			j++;
	if (j != 1 || i == 0)
	{
		write(1, "usage: unsetenv [name ...]\n", 27);
		return ;
	}
	del = ft_strdup(ft_strsub(m->cmd, 9, i - 9));
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

void	show_env(t_ms *m,char **env)
{
	t_var	*af;
	int		i;

	i = 0;
	while(env[i])
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
