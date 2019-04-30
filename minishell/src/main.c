/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:25:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/04/30 15:57:41 by kemartin         ###   ########.fr       */
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
