/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:51:32 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/13 14:55:40 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*lst_env(char *var, t_ms *m)
{
	t_var	*af;

	if (!(af = m->var))
		return (NULL);
	while (af && af->name && af->content && ft_strcmp(var, af->name))
		af = af->next;
	if (af && af->name && af->content && !ft_strcmp(var, af->name))
	{
		free(var);
		return (af->content);
	}
	free(var);
	return ("");
}

char	*env_find(char *str, char **env, t_ms *m)
{
	int		i;
	int		j;
	char	*var;

	if (str[0] == '$' && str[1])
	{
		if (!(var = ft_strnew(ft_strlen(str) - 1)))
			return (NULL);
		i = 1;
		j = 0;
		while (str[i])
			var[j++] = str[i++];
		var[j] = '\0';
		j = 0;
		i = ft_strlen(var);
		while (env[j] && ft_strncmp(var, env[j], i))
			j++;
		if (env[j] && !ft_strncmp(var, env[j], i))
		{
			free(var);
			return (env[j] + i + 1);
		}
		else if (!env[j])
			return (lst_env(var, m));
	}
	return (str);
}

void	show_env(t_ms *m, char **env)
{
	t_var	*af;

	if (!ft_strcmp("env -i", m->cmd))
	{
		ft_lst_clear(&m->var);
		init_env(env, m);
		return ;
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

void	ctrlc(int sign)
{
	char	cwd[1025];

	if (sign == SIGINT)
	{
		ft_putchar('\n');
		getcwd(cwd, 1024);
		write(1, "\033[95m", 6);
		ft_putstr(cwd);
		write(1, "\033[0m", 4);
		write(1, "\033[33m 💾  > ", 15);
		write(1, "\033[0m", 4);
		signal(SIGINT, ctrlc);
	}
}
