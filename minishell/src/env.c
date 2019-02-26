/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:37:29 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/26 19:54:44 by kemartin         ###   ########.fr       */
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
	{
		if (env[i++] == ' ')
			j++;
	}
	if (j != 2 || i == 0)
	{
		write(1, "usage: setenv [name ...] [data ...]\n", 36);
		return ;
	}
	tab = ft_strsplit(env, ' ');
	ft_lst_push_back(&m->var, tab[1], tab[2]);
	(void)m;
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
		write(1, af->name, ft_strlen(af->name));
		write(1, "=", 3);
		write(1, af->content, ft_strlen(af->content));
		write(1, "\n", 1);
		af = af->next;
	}
}
