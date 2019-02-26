/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/26 17:26:19 by kemartin         ###   ########.fr       */
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

void	gohome(t_ms *m)
{
		char	*dir;

		dir = ft_strdup("/Users/kemartin");
		chdir(dir);
		if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
			return ;
		if (!(m->cur_dir = getcwd(dir, PATH_MAX)))
			return ;	
}

int		exe_cmd(t_ms *m, char **env)
{
	if (m->cmd[5] && !ft_strncmp("/bin/", m->cmd, 5))
		return (bin_cmd(m, env));
	if (!ft_strcmp(m->cmd, "exit"))
		exit_function(m);
	if (m->cmd[4] && !ft_strncmp("cd ", m->cmd, 3))
		cd_function(ft_strsub(m->cmd, 3, ft_strlen(m->cmd) - 3), m);
	if (!ft_strcmp(m->cmd, "cd") || !ft_strcmp(m->cmd, "cd ~"))
		gohome(m);
	if (m->cmd[4] && !ft_strncmp("echo", m->cmd, 4))
		echo_function(ft_strsplit(m->cmd, ' '));
	return (0);
}
