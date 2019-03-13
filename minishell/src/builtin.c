/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:19 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/13 11:19:02 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_function(char *dir, t_ms *m, char **env)
{
	if (opendir(env_find(dir, env, m)))
	{
		chdir(env_find(dir, env, m));
		ft_strdel(&m->cur_dir);
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

int		path_cmd(t_ms *m, char **env, char **arg)
{
	int		j;
	char	**path;
	char	*cpy;
	t_var	*af;

	j = 0;
	if (!(af = m->var))
		return (0);
	while (af && ft_strncmp(af->name, "PATH", 4))
		af = af->next;
	if (!af || !(path = ft_strsplit(af->content, ':')))
		return (0);
	j = 0;
	cpy = ft_strdup(arg[0]);
	while (path[j])
	{
		path[j] = reallocstr(path[j]);
		ft_strdel(&arg[0]);
		arg[0] = arg_adjustment(path[j], cpy);
		execve(arg[0], arg, env);
		j++;
	}
	ft_freetab(path);
	ft_strdel(&cpy);
	return (0);
}

int		bin_cmd(t_ms *m, char **env)
{
	pid_t	pid;
	char	**arg;
	int		status;

	arg = ft_strsplit(m->cmd, ' ');
	pid = fork();
	signal(SIGINT, ctrlc);
	
	if (pid == 0)
	{
		if (execve(arg[0], arg, env) < 0 && path_cmd(m, env, arg) == 0)
		{
			ft_freetab(arg);
			return (cmd_not_found(m->cmd, -1));
		}
	}
	else if (pid < 0)
		return (ft_putstr_int("unable to fork process\n", -1));
	wait(&status);
	ft_freetab(arg);
	return (0);
}

void	echo_function(char **env, t_ms *m)
{
	int		j;
	int		swt;
	int		len;
	char	**tab;

	j = 1;
	swt = 0;
	tab = ft_strsplit(m->cmd, ' ');
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
	ft_freetab(tab);
}
