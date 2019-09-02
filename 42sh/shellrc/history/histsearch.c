/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:32:57 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 13:14:34 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_search(t_keymaster *lock)
{
	int		i;
	char	*mp;

	i = lock->hist.index;
	if (lock->out[0] == 0 || !lock->hist.cmdhist || i == 0
	|| !lock->hist.cmdhist[i - 1])
		return (0);
	while (--i)
	{
		if ((mp = ft_strstr(lock->hist.cmdhist[i], lock->out)) != 0)
		{
			free(lock->rechist);
			lock->rechist = ft_strdup(lock->hist.cmdhist[i]);
			return (1);
		}
	}
	return (0);
}

char	*ft_strduphist(char *buf)
{
	char	*s2;
	int		i;
	int		s;

	i = -1;
	s = 0;
	while (buf[++i] != '\0')
	{
		if (ft_isprint(buf[i]) || buf[i] == 7)
			s++;
	}
	if (!(s2 = (char*)malloc(sizeof(char) * (s + 1))))
		return (0);
	i = -1;
	s = -1;
	while (buf[++i])
	{
		if (ft_isprint(buf[i]) || buf[i] == 7)
			s2[++s] = buf[i];
	}
	s2[++s] = '\0';
	return (s2);
}

int		ft_pathfinal(t_masterenv *menv, char **cmd, char *tmp, int *nf)
{
	if (ft_findfct(menv, &cmd[0], tmp))
		return (1);
	if (cmd[0])
		*nf = 0;
	return (0);
}

int		ft_openhist(t_keymaster *lock)
{
	struct stat	st;
	int			fd_file;

	if (stat(lock->hist.histfile, &st) != -1)
	{
		if (st.st_size > HIST_SIZE)
		{
			if ((fd_file = open(lock->hist.histfile, O_TRUNC | O_RDWR
			, S_IRUSR | S_IWUSR)) == -1)
				return (-1);
		}
		else
		{
			if ((fd_file = open(lock->hist.histfile, O_RDWR | O_NOFOLLOW
			, S_IRUSR | S_IWUSR)) == -1)
				return (-1);
		}
	}
	else
	{
		if ((fd_file = open(lock->hist.histfile, O_TRUNC | O_RDWR
		, S_IRUSR | S_IWUSR)) == -1)
			return (-1);
	}
	return (fd_file);
}
