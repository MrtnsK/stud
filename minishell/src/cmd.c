/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/20 18:41:42 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd(t_ms *m)
{
	if (get_next_line(0, &m->cmd) == -1)
		exit(ft_putstr_int("=== GNL error ===\n", 1));
}

int		ft_strchrint(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (0);
	return (0);
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

int		exe_cmd(t_ms *m, char **env)
{
	if (m->cmd[5] && !ft_strncmp("/bin/", m->cmd, 5))
		return (bin_cmd(m, env));
	if (!ft_strcmp(m->cmd, "exit"))
		exit_function(m);
	if (m->cmd[4] && !ft_strncmp("cd ", m->cmd, 3))
		cd_function(ft_strsub(m->cmd, 3, ft_strlen(m->cmd) - 3), m);
	return (0);
}
