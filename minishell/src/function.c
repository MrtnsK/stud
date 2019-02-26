/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:19 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/26 17:20:14 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_function(char *dir, t_ms *m)
{
	if (opendir(dir))
	{
		chdir(dir);
		if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
			return ;
		if (!(m->cur_dir = getcwd(dir, PATH_MAX)))
			return ;
	}
	else
	{
		write(1, "cd: no such file or directory: ", 32);
		ft_putstr(dir);
		write(1, "\n", 1);
	}
}

int		bin_cmd(t_ms *m, char **env)
{
	pid_t	pid;
	char	**arg;

	arg = ft_strsplit(m->cmd, ' ');
	pid = fork();
	if (pid == 0 && execve(arg[0], arg, env) < 0)
		return (ft_putstr_int("minishell: command not found: ", -1)
		+ ft_putstr_int(arg[0], 0) + ft_putstr_int("\n", 0));
	wait(&pid);
	free(*arg);
	(void)m;
	return (0);
}

void	exit_function(t_ms *m)
{
	ft_putstr("== sortie \"exit\" ==\n");
	(void)m;
	// free(m);
	exit(0);
}

void	echo_function(char **tab)
{
	int		i;
	int		j;
	int		swt;

	j = 1;
	swt = 0;
	if (tab[j])
		if (!ft_strncmp(tab[j], "-n", 2) && !tab[j][3])
			swt = 2 * j++;
	while (tab[j])
	{
		i = 0;
		while(tab[j][i])
		{
			if (tab[j][i] != '"')
				ft_putchar(tab[j][i]);
			i++;
		}
		if (j > 1 && !!tab[2])
			write(1, " ", 1);
		j++;
	}
	!swt ? write(1, "\n", 1) : write(1, "\033[47m\033[30m%\033[0m", 15);
}

void	ctrlc(int sign)
{
	char	*dir;

	if (sign == SIGINT)
	{
		ft_putchar('\n');
		if (!(dir = (char*)malloc(sizeof(char) * PATH_MAX)))
			return ;
		if (!(dir = getcwd(dir, PATH_MAX)))
			return ;
		write(1, "\033[33m\033[100m", 11);
		if (!ft_strncmp("/Users/kemartin/", dir, 16))
		{
			ft_putstr("~/");
			ft_putstr(ft_strsub(ft_strdup(dir), 16, ft_strlen(dir) - 16));
		}
		else
			ft_putstr(dir);
		write(1, "\033[0m ", ft_strlen("\033[0m "));
		write(1, "\033[95m$> ", ft_strlen("\033[95m$> "));
		write(1, "\033[0m", ft_strlen("\033[0m"));
		signal(SIGINT, ctrlc);
	}
}
