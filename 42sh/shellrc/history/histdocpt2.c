/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histdocpt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:02:24 by apsaint-          #+#    #+#             */
/*   Updated: 2019/07/01 10:50:59 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		hist_quotes(void)
{
	int		i;
	int		quoters;

	i = 0;
	quoters = 0;
	while (g_ultib[i])
	{
		if (g_ultib[i] == '"' && (i == 0 || g_ultib[i - 1] != '\\')
			&& quoters != 2)
			ft_quoters(&quoters, 1);
		if (g_ultib[i] == '\'' && i > 0 && g_ultib[i - 1] != '\\'
		&& quoters != 1)
			ft_quoters(&quoters, 2);
		i++;
	}
	return (quoters);
}

char	*ft_fakedbs(char *str)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	while (str[i])
		if (str[i++] == '\n')
			c++;
	if (c == 0)
		return (ft_strdup(str));
	if (!(tmp = (char*)malloc(sizeof(char)
		* (ft_strlen(str) + (c * 2) + 1))))
		return (NULL);
	i = -1;
	c = 0;
	while (str[++i])
	{
		if (str[i] != '\n')
			tmp[c++] = str[i];
		else if (str[i] == '\n')
			c = put_bsbsn(c, &tmp);
	}
	tmp[c] = '\0';
	return (tmp);
}

int		ft_create_hist(t_keymaster *lock)
{
	char	*buf;
	int		i;
	int		fd_file;

	i = -1;
	fd_file = 0;
	if (ft_read_hist(&buf, lock, fd_file))
	{
		lock->hist.count = 0;
		return (1);
	}
	lock->hist.cmdhist = ft_strsplit(buf, 7);
	free(buf);
	lock->hist.count = 0;
	lock->hist.n = 1;
	lock->hist.usercmd = ft_strdup("");
	while (lock->hist.cmdhist[++i])
		lock->hist.count++;
	lock->hist.index = lock->hist.count;
	return (0);
}

int		ft_uphist(t_keymaster *lock, t_stockap *pac)
{
	int	i;

	if (lock->hist.count == 0)
		return (0);
	if (lock->hist.index)
		lock->hist.index--;
	i = lock->hist.index;
	ft_switchout(lock, pac, lock->hist.cmdhist[i]);
	return (0);
}

int		ft_downhist(t_keymaster *lock, t_stockap *pac)
{
	int i;

	if (lock->hist.count == 0)
		return (0);
	if (lock->hist.index <= lock->hist.count - 1)
		lock->hist.index++;
	if (lock->hist.index == lock->hist.count)
		return (ft_switchout(lock, pac, lock->hist.usercmd));
	i = lock->hist.index;
	ft_switchout(lock, pac, lock->hist.cmdhist[i]);
	return (0);
}
