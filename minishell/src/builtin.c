/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:19 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/07 13:50:46 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_function(char *dir, t_ms *m, char **env)
{
	if (opendir(env_find(dir, env, m)))
	{
		chdir(env_find(dir, env, m));
		free(m->cur_dir);
		if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
			return ;
		if (!(m->cur_dir = getcwd(dir, PATH_MAX)))
			return ;
	}
	else
	{
		write(1, "cd: no such file or directory: ", 32);
		ft_putstr(env_find(dir, env, m));
		write(1, "\n", 1);
	}
}

int		path_cmd(char **env, char **arg)
{
	int		j;
	char	**path;

	j = 0;
	while (env[j] && ft_strncmp(env[j], "PATH", 4))
		j++;
	path = ft_strsplit(env[j] + 5, ':');
	j = 0;
	while (path[j])
	{
		ft_putendl(path[j]);
		execve(path[j], arg, env);
		j++;
	}
	return (0);
}

int		bin_cmd(t_ms *m, char **env)
{
	pid_t	pid;
	char	**arg;

	arg = ft_strsplit(m->cmd, ' ');
	pid = fork();
	if (pid == 0 && (path_cmd(env, arg) < 0 /*|| execve(arg[0], arg, env) < 0 */\
	|| execve(".", arg, env) < 0))
		return (cmd_not_found(m->cmd, -1));
	wait(&pid);
	free(*arg);
	return (0);
}

void	quote_case(char *str)
{
	int		i;

	i = 1;
	while (str[i + 1])
		ft_putchar(str[i++]);
}

void	echo_function(char **tab, char **env, t_ms *m)
{
	int		j;
	int		swt;
	int		len;

	j = 1;
	swt = 0;
	if (tab[j])
		if (!ft_strncmp(tab[j], "-n", 2) && !tab[j][3])
			swt = 2 * j++;
	while (tab[j])
	{
		len = ft_strlen(tab[j]);
		if ((tab[j][0] == '\'' || tab[j][0] == '"')
		&& (tab[j][len - 1] == '\'' || tab[j][len - 1] == '"'))
			quote_case(tab[j]);
		else
			ft_putstr(is_this_home(env_find(tab[j], env, m)));
		if (j > 0 && !!tab[2] && tab[j + 1])
			write(1, " ", 1);
		j++;
	}
	!swt ? write(1, "\n", 1) : write(1, "\033[47m\033[30m%\033[0m", 15);
}
