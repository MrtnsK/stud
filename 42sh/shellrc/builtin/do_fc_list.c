/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:43:02 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/19 15:18:18 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_replace_cmd(char **old, char *new)
{
	free(*old);
	(*old) = ft_strdup(new);
}

void	digit_aff(t_keymaster *lock, int i, int j, int opt)
{
	if (i < j && lock->hist.count > 0)
	{
		i -= 2;
		j--;
		while (++i <= j && lock->hist.cmdhist[i] && i >= 0 && lock->hist.fc++)
			opt & OPT_N ? ft_printfd(0, "\t%s\n", lock->hist.cmdhist[i])\
				: ft_printfd(0, "%d\t%s\n", i + 1, lock->hist.cmdhist[i]);
	}
	else if (i >= j && lock->hist.count > 0)
	{
		j -= 1;
		while (--i >= j && lock->hist.cmdhist[i] && i >= 0 && lock->hist.fc++)
			opt & OPT_N ? ft_printfd(0, "\t%s\n", lock->hist.cmdhist[i])\
				: ft_printfd(0, "%d\t%s\n", i + 1, lock->hist.cmdhist[i]);
	}
}

void	pre_digit(t_keymaster *lock, int opt, char **cmd, int i[2])
{
	if (ft_strdigit(cmd[2]))
		i[0] = cmd[2][0] == '-' ? lock->hist.count + ft_atoi(cmd[2])\
		: ft_atoi(cmd[2]);
	else if (ft_stralpha(cmd[2]))
	{
		while (lock->hist.cmdhist[i[0]] && ft_strncmp(cmd[2],\
		lock->hist.cmdhist[i[0]], ft_strlen(cmd[2])))
			i[0]++;
		i[0]++;
	}
	if (ft_strdigit(cmd[3]))
		i[1] = cmd[3][0] == '-' ? lock->hist.count + ft_atoi(cmd[3])\
		: ft_atoi(cmd[3]);
	else if (ft_stralpha(cmd[3]))
	{
		while (lock->hist.cmdhist[i[1]] && ft_strncmp(cmd[3],\
		lock->hist.cmdhist[i[1]], ft_strlen(cmd[3])))
			i[1]++;
		i[0] > i[1] ? 0 : i[1]++;
	}
	digit_aff(lock, i[0], i[1], opt);
}

void	simple_case(t_keymaster *lock, int opt, char **cmd)
{
	int	i;

	i = 0;
	if (ft_strdigit(cmd[2]))
		i = cmd[2][0] == '-' ? lock->hist.count + ft_atoi(cmd[2]) - 1\
		: ft_atoi(cmd[2]) - 2;
	else if (ft_stralpha(cmd[2]))
	{
		while (lock->hist.cmdhist[i] && ft_strncmp(cmd[2],\
		lock->hist.cmdhist[i], ft_strlen(cmd[2])))
			i++;
		i--;
	}
	while (++i < lock->hist.count && i >= 0 && lock->hist.cmdhist[i]
	&& lock->hist.fc++)
		opt & OPT_N ? ft_printfd(0, "\t%s\n", lock->hist.cmdhist[i])\
			: ft_printfd(0, "%d\t%s\n", i + 1, lock->hist.cmdhist[i]);
}

void	fc_list(t_keymaster *lock, int opt, char **cmd)
{
	int i;
	int	j[2];

	j[0] = 0;
	j[1] = 0;
	if ((i = lock->hist.count - 16) < 0)
		i = -1;
	if (cmd[1] && !cmd[2])
		while (++i <= lock->hist.count && lock->hist.cmdhist[i]
		&& lock->hist.fc++)
			opt & OPT_N ? ft_printfd(0, "\t%s\n", lock->hist.cmdhist[i])\
				: ft_printfd(0, "%d\t%s\n", i + 1, lock->hist.cmdhist[i]);
	else if (cmd[2])
	{
		if (!cmd[3])
			simple_case(lock, opt, cmd);
		else if (cmd[3])
			pre_digit(lock, opt, cmd, j);
	}
	if (lock->hist.fc == 1)
		error_list();
}
