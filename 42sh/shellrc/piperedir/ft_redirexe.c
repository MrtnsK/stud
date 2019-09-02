/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirexe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:59:54 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/17 13:10:57 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static	int		ft_openout(t_masterenv *tenv, int j, int fd_agregin)
{
	int		fd_redirout;

	fd_redirout = 1;
	if (ft_strcmp(tenv->cgv[j], ">") == 0
	|| (ft_strcmp(tenv->cgv[j], ">&") == 0 && !ft_checkfd(tenv->cgv[j + 1]))
	|| ft_checkredirfd(tenv->cgv[j]))
	{
		if ((fd_redirout = open(tenv->cgv[j + 1], O_RDWR | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR)) == -1)
			return (-1);
	}
	else if (ft_strstr(tenv->cgv[j], ">>"))
	{
		if ((fd_redirout = open(tenv->cgv[j + 1], O_RDWR | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR)) == -1)
			return (-1);
	}
	if (fd_agregin == fd_redirout)
		return (ft_openout(tenv, j, fd_agregin));
	return (fd_redirout);
}

static	int		ft_openin(t_masterenv *tenv, int i)
{
	int		fd_redirin;
	char	*heredoc;

	if (ft_strstr(tenv->cgv[i], "<<"))
	{
		heredoc = ft_getheredoc();
		if ((fd_redirin = open(heredoc, O_RDONLY, S_IRUSR | S_IWUSR)) == -1)
			return (-1);
		free(heredoc);
	}
	else
	{
		if ((fd_redirin = open(tenv->cgv[i + 1], O_RDONLY,
		S_IRUSR | S_IWUSR)) == -1)
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: %s: Can't open file\n",
			tenv->cgv[i + 1]);
			return (-1);
		}
	}
	return (fd_redirin);
}

int				ft_redirout(t_masterenv *tenv, int j, int fd_agregin)
{
	int		fd_redirout;
	int		ind;
	char	*tmp;
	int		fd;

	if ((fd_redirout = ft_openout(tenv, j, fd_agregin)) == -1)
		return (1);
	if ((ft_checkredirfd(tenv->cgv[j]) && ft_strcmp(tenv->cgv[j], ">") != 0)
	|| (ft_strstr(tenv->cgv[j], ">>") && ft_strlen(tenv->cgv[j]) > 2))
	{
		ind = ft_strchri(tenv->cgv[j], '>');
		tmp = ft_strsub(tenv->cgv[j], 0, ind);
		fd = ft_atoi(tmp);
		free(tmp);
		if (fd > MAX_FD || fd < 0)
			return (fd);
	}
	else
		fd = 1;
	dup2(fd_redirout, fd);
	close(fd_redirout);
	return (0);
}

int				ft_redirin(t_masterenv *tenv, int i)
{
	int		fd_redirin;
	int		ind;
	char	*tmp;
	int		fd;

	if ((fd_redirin = ft_openin(tenv, i)) == -1)
		return (1);
	if (ft_strcmp(tenv->cgv[i], "<<") != 0 || ft_strcmp(tenv->cgv[i], "<") != 0)
	{
		ind = ft_strchri(tenv->cgv[i], '<');
		tmp = ft_strsub(tenv->cgv[i], 0, ind);
		fd = ft_atoi(tmp);
		free(tmp);
		if (fd > MAX_FD || fd < 0)
			return (fd);
	}
	else
		fd = 0;
	dup2(fd_redirin, fd);
	close(fd_redirin);
	return (0);
}

int				ft_checkredirerror(t_masterenv *tenv, int i, int fd_agregin)
{
	int	j;
	int	fd;

	fd = 0;
	if ((j = ft_checkredirout(tenv, i)))
	{
		if ((fd = ft_redirout(tenv, j, fd_agregin)))
			ft_checkfderror(fd);
	}
	else if ((j = ft_checkredirin(tenv, i)))
	{
		if ((fd = ft_redirin(tenv, j)))
			ft_checkfderror(fd);
	}
	return (fd);
}
