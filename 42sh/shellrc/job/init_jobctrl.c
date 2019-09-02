/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_jobctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:02:10 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/16 09:05:38 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_init_jobctrl(void)
{
	pid_t	shell_pgid;
	pid_t	fg_pgid;

	shell_pgid = getpid();
	if (setpgid(shell_pgid, shell_pgid) == -1)
		return (-1);
	if ((fg_pgid = tcgetpgrp(STDIN_FILENO)) == -1)
		return (-1);
	if (shell_pgid != fg_pgid)
		if (kill(shell_pgid, SIGTTIN) == -1)
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: crashed\n");
			exit(1);
		}
	ft_init_signals();
	if (tcsetpgrp(STDIN_FILENO, shell_pgid) == -1)
		return (-1);
	g_lock.shell_pgid = shell_pgid;
	return (0);
}

char	**ft_arraydup(char **array)
{
	int		i;
	char	**new;

	i = 0;
	while (array[i])
		i++;
	if (!(new = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (i >= 0)
		new[i--] = 0;
	i = 0;
	while (array[i])
	{
		if (!(new[i] = ft_strdup(array[i])))
		{
			ft_tabfree(new);
			return (NULL);
		}
		i++;
	}
	i = 0;
	return (new);
}
