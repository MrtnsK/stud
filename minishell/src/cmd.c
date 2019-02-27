/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/27 16:27:10 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd(t_ms *m)
{
	if (get_next_line(0, &m->cmd) == -1)
		exit(ft_putstr_int("=== GNL error ===\n", 1));
}

int		cmd_not_found(char *cmd, int ret)
{
	if (cmd[0])
	{
		write(1, "minishell: command not found: ", 31);
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
	}
	return (ret);
}

int		var_exe_cmd(t_ms *m, char **env)
{
	if (!ft_strcmp("env", m->cmd))
		show_env(m, env);
	else if (!ft_strcmp("env -i", m->cmd))
		env_i(m, env);
	else if (!ft_strncmp("setenv ", m->cmd, 7) && m->cmd[8])
		set_env(m->cmd, m);
	else if (!ft_strcmp("setenv", m->cmd))
		set_env(m->cmd, m);
	else if (!ft_strncmp("unsetenv ", m->cmd, 9) && m->cmd[10])
		unset_env(m);
	else if (!ft_strcmp("unsetenv", m->cmd))
		unset_env(m);
	else
		return (1);
	return (0);
}
int		test_cmd(t_ms *m, char **env)
{
	pid_t	pid;
	char	**arg;

	arg = ft_strsplit(m->cmd, ' ');
	pid = fork();
	if (pid == 0 && execve(env[12], arg, env) < 0)
		return (cmd_not_found(arg[12], -1));
	wait(&pid);
	free(*arg);
	return (0);
}

int		exe_cmd(t_ms *m, char **env)
{
	if (test_cmd(m, env) == -1)
		return (-1);
	else if (!ft_strncmp("/bin/", m->cmd, 5) && m->cmd[5])
		return (bin_cmd(m, env));
	else if (!ft_strcmp(m->cmd, "exit"))
		exit_function(m);
	else if (!ft_strncmp("cd ", m->cmd, 3) && m->cmd[4])
		cd_function(ft_strsub(m->cmd, 3, ft_strlen(m->cmd) - 3), m);
	else if (!ft_strcmp(m->cmd, "cd") || !ft_strcmp(m->cmd, "cd ~"))
		gohome(m);
	else if (!ft_strncmp("echo ", m->cmd, 5) && m->cmd[5])
		echo_function(ft_strsplit(m->cmd, ' '));
	else if (!ft_strcmp("echo", m->cmd))
		echo_function(ft_strsplit(m->cmd, ' '));
	else if (!ft_strcmp("pwd", m->cmd))
		pwd_fun(m);
	else if (var_exe_cmd(m, env) == 1)
		cmd_not_found(m->cmd, 0);
	return (0);
}
