/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histdocpt3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:02:30 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/19 17:07:13 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		theresexp(char *str, t_keymaster *lock)
{
	int		i;

	i = 0;
	lock->exp = 0;
	while (str[i] && str[i] != '!')
		i++;
	if (str[i] == '!')
		return (1);
	return (0);
}

int		put_bsbsn(int c, char **tmp)
{
	(*tmp)[c++] = '\\';
	(*tmp)[c++] = '\\';
	(*tmp)[c++] = 'n';
	return (c);
}

void	ft_replace(char **old, char *new)
{
	lt_remove(*old);
	(*old) = ft_strdup(new);
}

int		hist_reader(char *buf, int fd_file, char **str, int b)
{
	int		tot;
	char	*tmp;

	tot = 0;
	while ((b = read(fd_file, buf, BUFF_SIZE)) > 0)
	{
		buf[b] = '\0';
		if (tot == 0)
			*str = ft_strduphist(buf);
		else
		{
			tmp = ft_strduphist(buf);
			*str = ft_strjoin_free(*str, tmp);
			free(tmp);
		}
		tot += b;
	}
	lt_remove(buf);
	return (tot);
}

char	*getshlvl(t_masterenv *menv)
{
	int		i;
	int		j;
	char	*lvl;

	j = -1;
	i = -1;
	lvl = NULL;
	while (menv->stock[0][++i])
		if (ft_strcmp("SHLVL", menv->stock[0][i]) == -61)
		{
			while (menv->stock[0][i][++j] != '=')
				;
			lvl = ft_strsub(menv->stock[0][i], j + 1,\
			ft_strlen(menv->stock[0][i]));
			break ;
		}
	if (!lvl)
	{
		if (!(lvl = (char*)malloc(sizeof(char) * 5)))
			exit(1);
		ft_strcpy(lvl, "ator");
	}
	return (lvl);
}
