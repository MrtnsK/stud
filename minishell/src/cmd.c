/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/13 11:18:24 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd(t_ms *m)
{
	if (m->cmd)
		ft_strdel(&m->cmd);
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
	if (!ft_strcmp("env", m->cmd) || !ft_strcmp("env -i", m->cmd))
		show_env(m, env);
	else if (!ft_strncmp("setenv ", m->cmd, 7) && m->cmd[7])
		set_env(m->cmd, m);
	else if (!ft_strcmp("setenv", m->cmd))
		set_env(m->cmd, m);
	else if (!ft_strncmp("unsetenv ", m->cmd, 9) && m->cmd[9])
		unset_env(m);
	else if (!ft_strcmp("unsetenv", m->cmd))
		unset_env(m);
	else
		return (1);
	return (0);
}

int		is_wp(char *str)
{
	int		i;

	i = 0;
	if (str && str[i])
		while (str[i])
		{
			if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
				return (1);
			i++;
		}
	return (0);
}

int		exe_cmd(t_ms *m, char **env)
{
	char	*tmp;

	if (is_wp(m->cmd) == 0)
		return (0);
	else if (!ft_strcmp(m->cmd, "exit"))
		exit_function(m);
	else if (!ft_strncmp("cd ", m->cmd, 3) && m->cmd[4])
	{
		tmp = ft_strsub(m->cmd, 3, ft_strlen(m->cmd) - 3);
		cd_function(tmp, m, env);
		ft_strdel(&tmp);
	}
	else if (!ft_strcmp(m->cmd, "cd") || !ft_strcmp(m->cmd, "cd ~"))
		gohome(m);
	else if ((!ft_strncmp("echo ", m->cmd, 5) && m->cmd[5])
	|| !ft_strcmp("echo", m->cmd))
		echo_function(env, m);
	else if (!ft_strcmp("pwd", m->cmd))
		pwd_fun(m);
	else if (var_exe_cmd(m, env) == 1)
		return (bin_cmd(m, env));
	return (0);
}
