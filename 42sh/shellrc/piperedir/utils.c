/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:59:32 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 13:10:44 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static	int		ft_perm(char *tmp, int *nf, t_masterenv *menv)
{
	if (is_file(tmp) && !is_dir(tmp))
	{
		*nf = 0;
		return (0);
	}
	else if (is_dir(tmp))
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: permission denied: %s\n", tmp);
		menv->nruter = 1;
	}
	else
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: ");
		ft_printfd(2, "no such file or directory: %s\n", tmp);
		menv->nruter = 127;
	}
	return (1);
}

static	int		ft_pathslash(char **cmd, char *tmp)
{
	char	*pwd;

	if (!(pwd = getcwd(NULL, 0)))
		return (1);
	if (!(cmd[0] = (char*)malloc(sizeof(char) *
	(ft_strlen(pwd) + ft_strlen(tmp) + 2))))
		return (1);
	ft_strcpy(cmd[0], pwd);
	ft_strcat(cmd[0], "/");
	ft_strcat(cmd[0], tmp);
	free(pwd);
	return (0);
}

static	int		ft_notfound(int nf, char *tmp, t_masterenv *menv)
{
	if (nf)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m:");
		ft_printfd(2, " %s: command not found\n", tmp);
		menv->nruter = 127;
		return (1);
	}
	return (0);
}

int				ft_findpathperm(t_masterenv *menv, char **cmd, char *tmp)
{
	int	nf;

	nf = 1;
	if (tmp[0] == '/')
	{
		if (ft_perm(tmp, &nf, menv) == 0)
			cmd[0] = ft_strdup(tmp);
		else
			return (1);
	}
	else if (ft_strchr(tmp, '/'))
	{
		if (ft_pathslash(&cmd[0], tmp))
			return (1);
		if (ft_perm(cmd[0], &nf, menv))
		{
			free(cmd[0]);
			return (1);
		}
	}
	else if (menv->internal_var[0][menv->rep[4]])
		if (ft_pathfinal(menv, cmd, tmp, &nf))
			return (1);
	return (ft_notfound(nf, tmp, menv));
}

int				ft_exec_builtin_redir(t_masterenv *menv)
{
	int		fd_agregin;
	int		fd_b;
	int		fd[3];
	int		i;

	fd_b = -1;
	fd_agregin = -1;
	ft_savefdb((int *)fd);
	if (ft_check(menv, &fd_agregin, &fd_b))
		return (menv->nruter = 1);
	ft_redir_exec(menv, -1);
	i = -1;
	while (++i < 3)
		close(i);
	i = -1;
	while (++i < 3)
		dup2(fd[i], i);
	i = -1;
	while (++i < 3)
		if (fd[i] != -1)
			close(fd[i]);
	if (ft_restablish(fd_b, fd_agregin))
		return (menv->nruter = 1);
	ft_supvar(menv, -1);
	return (menv->nruter);
}
