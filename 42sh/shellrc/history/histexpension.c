/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histexpension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:54:46 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/17 10:38:53 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		exp_addtohist(t_keymaster *lock, char *toadd)
{
	int		fd;
	char	file_name[255];
	char	*tmp;

	fd = -1;
	ft_strcpy(file_name, lock->hist.histfile);
	if (!ft_strncmp(g_ultib, "fc", 2) || hist_quotes())
		return (0);
	if ((fd = open(file_name, O_RDWR | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR)) == -1)
		return (1);
	tmp = ft_fakedbs(toadd);
	if (ft_strcmp(tmp, "\n") != 0 && tmp != NULL)
		ft_printfd(fd, "%s%c", tmp, 7);
	free(tmp);
	close(fd);
	return (0);
}

void	changexp(char **cmd, char *tmp, int d[2], t_keymaster *lock)
{
	char	*debut;
	char	*fin;
	char	*join;

	if (tmp == NULL || cmd == NULL)
		return ;
	debut = ft_strsub((*cmd), 0, d[0]);
	fin = ft_strsub((*cmd), d[1], ft_strlen(*cmd) - d[1]);
	join = ft_strjoin(debut, tmp);
	ft_replace_cmd(&debut, join);
	free(join);
	join = ft_strjoin(debut, fin);
	ft_replace_cmd(&debut, join);
	free(join);
	free(fin);
	ft_replace_cmd(cmd, debut);
	free(debut);
	free(tmp);
	lock->exp = 1;
	if (!ft_strchr(cmd[0], '!'))
	{
		ft_putendl(cmd[0]);
		exp_addtohist(lock, cmd[0]);
	}
}

void	digit_case(char **cmd, t_keymaster *lock, int i[2], int index)
{
	char	*tmp;
	char	*post;
	int		nb;

	i[1] = (*cmd)[i[0] + 1] == '-' ? i[0] + 2 : i[0] + 1;
	while ((*cmd)[i[1]] && ft_isdigit((*cmd)[i[1]]))
		i[1]++;
	while (lock->hist.cmdhist[index])
		index++;
	post = ft_strsub((*cmd), i[0], i[1] - i[0]);
	nb = ft_abs(ft_atoi(post + 1));
	cmd[0][i[0] + 1] == '-' ? nb = lock->hist.count - nb : nb--;
	if (nb <= index && nb >= 0)
		if (lock->hist.cmdhist[nb])
		{
			tmp = ft_strdup(lock->hist.cmdhist[nb]);
			changexp(cmd, tmp, i, lock);
		}
	free(post);
}

void	alpha_case(char **cmd, t_keymaster *lock, int i[2])
{
	int		e;
	int		nb;
	char	*tmp;

	e = 0;
	while ((*cmd)[e] && (*cmd)[e] != ' ')
		e++;
	nb = lock->hist.count - 1;
	while (nb > 0
	&& ft_strncmp(lock->hist.cmdhist[nb], (*cmd) + i[0] + 1, e - 1))
		nb--;
	if (!ft_strncmp(lock->hist.cmdhist[nb], (*cmd) + i[0] + 1, e - 1))
	{
		tmp = ft_strdup(lock->hist.cmdhist[nb]);
		i[1] = i[0] + e;
		changexp(cmd, tmp, i, lock);
	}
}

int		ft_expensions(char **cmd, t_keymaster *lock)
{
	char	*tmp;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while ((*cmd)[i[0]] && (*cmd)[i[0]] != '!')
		i[0]++;
	if ((*cmd)[i[0]] && (*cmd)[i[0] + 1] && (*cmd)[i[0]] == '!'
	&& (*cmd)[i[0] + 1] == '!' && lock->hist.count > 0)
	{
		i[1] = i[0] + 2;
		tmp = ft_strdup(lock->hist.cmdhist[lock->hist.count - 1]);
		changexp(cmd, tmp, i, lock);
	}
	if ((*cmd)[i[0]] && (*cmd)[i[0] + 1] && (*cmd)[i[0]] == '!'
	&& (ft_isdigit((*cmd)[i[0] + 1]) || (*cmd)[i[0] + 1] == '-'))
		digit_case(cmd, lock, i, 0);
	if ((*cmd)[i[0]] && (*cmd)[i[0] + 1] && lock->hist.count > 0
	&& (*cmd)[i[0]] == '!' && ft_stralpha((*cmd) + i[0] + 1)
	&& (*cmd)[i[0] + 1] != ' ')
		alpha_case(cmd, lock, i);
	if (lock->exp == 0 && is_event(cmd, i[0]))
		return (no_event(cmd, i[0]));
	return (0);
}
