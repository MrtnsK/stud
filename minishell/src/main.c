/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:25:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/07 14:39:27 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_prompt(t_ms *m)
{
	write(1, "\033[33m\033[100m", 11);
	if (!ft_strncmp("/Users/kemartin/", m->cur_dir, 16))
	{
		ft_putstr("~/");
		ft_putstr(ft_strsub(ft_strdup(m->cur_dir),\
		16, ft_strlen(m->cur_dir) - 16));
	}
	else
		ft_putstr(m->cur_dir);
	write(1, "\033[0m ", 5);
	write(1, "\033[95m$> ", 8);
	write(1, "\033[0m", 4);
}

void	silence_warning(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
}

int		main(int ac, char **av, char **env)
{
	t_ms	*m;

	silence_warning(ac, av, env);
	if (!(m = (t_ms*)ft_memalloc(sizeof(t_ms))))
		return (0);
	if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
		return (0);
	m->cur_dir = NULL;
	if (!(m->cur_dir = getcwd(m->cur_dir, PATH_MAX)))
		return (ft_putstr_int("== getcwd error ==", 1));
	m->var = NULL;
	init_env(env, m);
	while (1)
	{
		show_prompt(m);
		signal(SIGINT, ctrlc);
		get_cmd(m);
		if (exe_cmd(m, env) == -1)
			break ;
	}
	return (0);
}
