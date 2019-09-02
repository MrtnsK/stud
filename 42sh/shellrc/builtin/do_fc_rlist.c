/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc_rlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:35:32 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/18 18:32:35 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	r_digit_aff(t_keymaster *lock, int i[2], int opt, char **cmd)
{
	if (i[1] > i[0])
	{
		i[0] -= 2;
		while (--i[1] > i[0] && lock->hist.cmdhist[i[1]] && i[1] >= 0
		&& lock->hist.fc++)
			opt & OPT_N ? ft_printfd(0, "\t%s\n", lock->hist.cmdhist[i[1]])\
				: ft_printfd(0, "%d\t%s\n", i[1] + 1, lock->hist.cmdhist[i[1]]);
	}
	else if (i[0] >= i[1])
	{
		i[1] = cmd[3][0] == '-' ? i[1] - 1 : i[1] - 2;
		while (--i[0] > i[1] && lock->hist.cmdhist[i[0]] && i[0] >= 0
		&& lock->hist.fc++)
			opt & OPT_N ? ft_printfd(0, "\t%s\n", lock->hist.cmdhist[i[0]])\
				: ft_printfd(0, "%d\t%s\n", i[0] + 1, lock->hist.cmdhist[i[0]]);
	}
}

void	r_pre_digit(t_keymaster *lock, int opt, char **cmd, int i[2])
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
	r_digit_aff(lock, i, opt, cmd);
}

void	r_simple_case(t_keymaster *lock, int opt, char **cmd)
{
	int	i;

	i = 0;
	if (ft_strdigit(cmd[2]))
		i = cmd[2][0] == '-' ? lock->hist.count + ft_atoi(cmd[2])\
		: ft_atoi(cmd[2]);
	else if (ft_stralpha(cmd[2]))
	{
		while (lock->hist.cmdhist[i] && ft_strncmp(cmd[2],\
		lock->hist.cmdhist[i], ft_strlen(cmd[2])))
			i++;
		i++;
	}
	while (--i >= 0 && lock->hist.cmdhist[i] && lock->hist.fc++)
		opt & OPT_N ? ft_printfd(0, "\t%s\n", lock->hist.cmdhist[i])\
			: ft_printfd(0, "%d\t%s\n", i + 1, lock->hist.cmdhist[i]);
}

void	fc_rlist(t_keymaster *lock, int opt, char **cmd)
{
	int i;
	int	count;
	int	j[2];

	j[0] = 0;
	j[1] = 0;
	i = lock->hist.count;
	count = lock->hist.count - 15 > 0 ? lock->hist.count - 15 : 0;
	if (cmd[1] && !cmd[2])
		while (--i >= count && lock->hist.cmdhist[i] && lock->hist.fc++)
			opt & OPT_N ? ft_printfd(0, "\t%s\n", lock->hist.cmdhist[i])\
				: ft_printfd(0, "%d\t%s\n", i + 1, lock->hist.cmdhist[i]);
	else if (cmd[2])
	{
		if (!cmd[3])
			r_simple_case(lock, opt, cmd);
		else if (cmd[3])
			r_pre_digit(lock, opt, cmd, j);
	}
	if (lock->hist.fc == 1)
		error_list();
}
