/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:53:40 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/18 18:23:22 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*fc_editor_simple(t_masterenv *menv, t_keymaster *lock,\
char *cmd, int tofree)
{
	t_masterenv tenv;
	char		*exec;
	int			fd;

	if (!cmd || !is_fcfile_ok())
		return (NULL);
	if ((fd = open(".fc_edit", O_RDWR | O_CREAT | O_TRUNC,\
	S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	ft_printfd(fd, "%s", cmd);
	if (tofree)
		free(cmd);
	close(fd);
	exec = ft_strjoin("ed ", ".fc_edit");
	if (ft_exec_fc(exec, menv, &tenv, lock))
		return (NULL);
	return (fc_editor_reader(exec, fd));
}

char	*simple_digit(t_masterenv *menv, t_keymaster *lock, int fd, char **cmd)
{
	int			i;
	int			j;
	char		*exec;
	t_masterenv tenv;

	if (!is_fcfile_ok())
		return (NULL);
	if ((fd = open(".fc_edit", O_RDWR | O_CREAT | O_TRUNC,\
	S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	i = ft_atoi(cmd[1]) - 1;
	j = ft_atoi(cmd[2]);
	if (i < j && lock->hist.count > 0)
		while (++i <= j && lock->hist.cmdhist[i])
			ft_printfd(fd, "%s\n", lock->hist.cmdhist[i]);
	else if (i >= j && lock->hist.count > 0 && i++ && i++)
		while (--i > j && lock->hist.cmdhist[i] && i > 0)
			ft_printfd(fd, "%s\n", lock->hist.cmdhist[i]);
	close(fd);
	exec = ft_strjoin("ed ", ".fc_edit");
	if (ft_exec_fc(exec, menv, &tenv, lock))
		return (NULL);
	return (fc_editor_reader(exec, fd));
}

char	*multi_digit(t_masterenv *menv, t_keymaster *lock, int i, int j)
{
	int			fd;
	char		*exec;
	t_masterenv tenv;

	if (!is_fcfile_ok())
		return (NULL);
	if ((fd = open(".fc_edit", O_RDWR | O_CREAT | O_TRUNC,\
	S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	if (i < j && lock->hist.count > 0)
	{
		i--;
		j--;
		while (++i <= j && lock->hist.cmdhist[i])
			ft_printfd(fd, "%s\n", lock->hist.cmdhist[i]);
	}
	else if (i >= j && lock->hist.count > 0 && j--)
		while (--i > j && lock->hist.cmdhist[i] && i > 0)
			ft_printfd(fd, "%s\n", lock->hist.cmdhist[i]);
	close(fd);
	exec = ft_strjoin("ed ", ".fc_edit");
	if (ft_exec_fc(exec, menv, &tenv, lock))
		return (NULL);
	return (fc_editor_reader(exec, fd));
}

char	*pre_simple_digit(t_masterenv *menv, t_keymaster *lock, char **cmd,
int i[2])
{
	if (ft_strdigit(cmd[1]))
		i[0] = cmd[1][0] == '-' ? lock->hist.count + ft_atoi(cmd[1])\
		: ft_atoi(cmd[1]);
	else if (ft_stralpha(cmd[1]))
	{
		while (lock->hist.cmdhist[i[0]] && ft_strncmp(cmd[1],\
		lock->hist.cmdhist[i[0]], ft_strlen(cmd[1])))
			i[0]++;
		i[0]++;
	}
	if (ft_strdigit(cmd[2]))
		i[1] = cmd[2][0] == '-' ? lock->hist.count + ft_atoi(cmd[2])\
		: ft_atoi(cmd[2]);
	else if (ft_stralpha(cmd[2]))
	{
		while (lock->hist.cmdhist[i[1]] && ft_strncmp(cmd[2],\
		lock->hist.cmdhist[i[1]], ft_strlen(cmd[2])))
			i[1]++;
		i[0] > i[1] ? 0 : i[1]++;
	}
	return (multi_digit(menv, lock, i[0], i[1]));
}

char	*simple_fc(t_masterenv *menv, t_keymaster *lock, char **cmd, char *exec)
{
	int			i;
	int			j[2];
	t_masterenv tenv;

	j[0] = 0;
	j[1] = 0;
	if (!cmd[1])
		fc_noarg(menv, lock, &tenv, exec);
	else if (cmd[1] && !cmd[2])
	{
		if (ft_strdigit(cmd[1]))
		{
			i = cmd[1][0] == '-' ? lock->hist.count + ft_atoi(cmd[1])\
			: ft_atoi(cmd[1]) - 1;
			if (i < lock->hist.count && i > 0 && lock->hist.cmdhist[i])
				return (fc_editor_simple(menv, lock, lock->hist.cmdhist[i], 0));
		}
		else if (ft_stralpha(cmd[1]))
			return (fc_editor_simple(menv, lock, fc_chr(lock, 1, cmd), 1));
	}
	else if (cmd[2])
		return (replacebsn(pre_simple_digit(menv, lock, cmd, j)));
	return (NULL);
}
