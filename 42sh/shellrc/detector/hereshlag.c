/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hereshlag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:50:14 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/29 15:00:19 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_hereshlagcore_pt2(int i, t_keymaster *lock, int j, int k)
{
	if (!lock->sep && lock->herelvl == lock->new_lvl)
	{
		lock->first = 1;
		if (k == j)
			return (ft_herror(lock));
		if (!(lock->sep = (char*)malloc(sizeof(char) * (k - j + 1))))
			return (-10);
		ft_strncpy(lock->sep, g_ultib + j, k - j);
		lock->sep[k - j] = 0;
		if (ft_strrchr(lock->sep, '<') || ft_strrchr(lock->sep, '>')
			|| ft_strrchr(lock->sep, ';') || ft_strrchr(lock->sep, '|'))
			return (ft_herror(lock));
	}
	else
		lock->first = 0;
	i = j - 1;
	return (i);
}

static int	ft_hereshlagcore(int i, t_keymaster *lock)
{
	int j;
	int	k;

	if (!g_ultib[i] || !g_ultib[i + 1])
		return (i);
	if (g_ultib[i] == '<' && g_ultib[i + 1] == '<' && g_ultib[i + 2] != '<')
	{
		if (g_ultib[i + 2] == '&' || !g_ultib[i + 2])
			return (ft_herror(lock));
		j = i + 1;
		while (g_ultib[++j] && ft_isspace(g_ultib[j]))
			;
		k = j - 1;
		while (g_ultib[++k] && !ft_isspace(g_ultib[k]))
			;
		return (ft_hereshlagcore_pt2(i, lock, j, k));
	}
	return (i);
}

static int	ft_hereshlagloopcore(t_keymaster *lock)
{
	int		fd_file;

	ft_hereprompt(lock);
	if (lock->first)
	{
		if ((fd_file = open(lock->pathfile, O_CREAT | O_RDWR | O_TRUNC,
			S_IRUSR | S_IWUSR)) == -1)
		{
			free(lock->sep);
			lock->sep = NULL;
			ft_printfd(2, "heredoc: no access to heredoc file\n");
			return (-10);
		}
		close(fd_file);
	}
	else
	{
		if (access(lock->pathfile, F_OK))
		{
			ft_printfd(2, "\e[93mMastershell\e[0m:");
			ft_printfd(2, " heredoc: no access to heredoc file\n");
			return (-10);
		}
	}
	return (-20);
}

static int	ft_hereshlagloop(t_keymaster *lock, int i)
{
	int		j;

	j = i;
	i = ft_hereshlagcore(i, lock);
	if (i == -10)
		return (-10);
	if (j != i && lock->new_lvl == lock->herelvl)
		return (ft_hereshlagloopcore(lock));
	if (j != i)
		lock->new_lvl += 1;
	return (i);
}

int			ft_hereshlag(t_stockap *pac, t_keymaster *lock, t_masterenv *menv)
{
	int		i;

	i = -1;
	lock->new_lvl = 0;
	while (g_ultib[++i])
	{
		i = ft_hereshlagloop(lock, i);
		if (i == -20)
			return (ft_newgetbuf(&g_ultib, lock, pac, menv));
		if (i == -10)
		{
			menv->nruter = 1;
			return (1);
		}
	}
	return (0);
}
