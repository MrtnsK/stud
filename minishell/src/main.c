/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:25:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/04/06 18:22:45 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	starting(void)
{
	write(1, "\033[33m", 6);
	ft_putendl(" _  _  ____              _       _     _          _ _ \n\
| || ||___ \\   _ __ ___ (_)_ __ (_)___| |__   ___| | |\n\
| || |_ __) | | '_ ` _ \\| | '_ \\| / __| '_ \\ / _ \\ | |\n\
|__   _/ __/  | | | | | | | | | | \\__ \\ | | |  __/ | |\n   \
|_||_____| |_| |_| |_|_|_| |_|_|___/_| |_|\\___|_|_|\n ");
}

void	silence_warning(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
}

void	execenv(char **env, char *var)
{
	char	**tab;
	char	**arg;

	if(!(arg = (char**)malloc(sizeof(char*) * 5)))
		return ;
	tab = ft_strsplit(var, ' ');
	arg[0] = ft_strdup("env");
	arg[1] = ft_strdup("/usr/bin/env");
	arg[2] = ft_strdup(tab[1]);
	arg[3] = ft_strdup(tab[2]);
	arg[4] = NULL;
	execve("/usr/bin/env", arg, env);
	ft_freetab(env);
	ft_freetab(tab);
	ft_freetab(arg);
}

void	env_push(t_ms *m, char *var)
{
	t_var	*af;
	int		i;
	char	*tmp;
	char	**env;

	af = m->var;
	i = ft_varsize(af);
	if (!(env = (char**)ft_memalloc(sizeof(char*) * i + 1)))
		return ;
	i = 0;
	while (af && af->name && af->content)
	{
		if (af->name && af->content)
		{
			tmp = ft_strjoin(af->name, "=");
			env[i++] = ft_strjoin(tmp, af->content);
			ft_strdel(&tmp);
		}
		af = af->next;
	}
	execenv(env, var);
}

int		main(int ac, char **av, char **env)
{
	t_ms	*m;

	silence_warning(ac, av, env);
	starting();
	if (!(m = (t_ms*)ft_memalloc(sizeof(t_ms))))
		return (0);
	init_env(env, m);
	while (1)
	{
		show_prompt();
		signal(SIGINT, ctrlc);
		get_cmd(m);
		if (exe_cmd(m, env) == -1)
			break ;
	}
	exit_function(m);
	return (0);
}
