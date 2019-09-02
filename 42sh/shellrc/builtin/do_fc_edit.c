/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc_edit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:59:48 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/18 18:23:40 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*fc_editor_op(t_masterenv *menv, t_keymaster *lock, char *cmd,
char *edit)
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
	close(fd);
	exec = ft_strjoin(edit, " .fc_edit");
	if (ft_exec_fc(exec, menv, &tenv, lock))
		return (NULL);
	return (fc_editor_reader(exec, fd));
}

char	*edit_exec(t_masterenv *menv, t_keymaster *lock, int i[2], char *edit)
{
	int			fd;
	char		*exec;
	t_masterenv tenv;

	if (!is_fcfile_ok())
		return (NULL);
	if ((fd = open(".fc_edit", O_RDWR | O_CREAT | O_TRUNC,\
	S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	if (i[0] < i[1] && lock->hist.count > 0)
	{
		i[0] -= 2;
		i[1]--;
		while (++i[0] <= i[1] && lock->hist.cmdhist[i[0]])
			ft_printfd(fd, "%s\n", lock->hist.cmdhist[i[0]]);
	}
	else if (i[0] >= i[1] && lock->hist.count > 0 && i[1]-- && i[1]--)
		while (--i[0] > i[1] && lock->hist.cmdhist[i[0]] && i[0] > 0)
			ft_printfd(fd, "%s\n", lock->hist.cmdhist[i[0]]);
	close(fd);
	exec = ft_strjoin(edit, " .fc_edit");
	if (ft_exec_fc(exec, menv, &tenv, lock))
		return (NULL);
	return (fc_editor_reader(exec, fd));
}

char	*edit_digit(t_masterenv *menv, t_keymaster *lock, char **cmd, int i[2])
{
	if (ft_strdigit(cmd[3]))
		i[0] = cmd[3][0] == '-' ? lock->hist.count + ft_atoi(cmd[3])\
		: ft_atoi(cmd[3]);
	else if (ft_stralpha(cmd[3]))
	{
		while (lock->hist.cmdhist[i[0]] && ft_strncmp(cmd[3],\
		lock->hist.cmdhist[i[0]], ft_strlen(cmd[3])))
			i[0]++;
		i[0]++;
	}
	if (ft_strdigit(cmd[4]))
		i[1] = cmd[4][0] == '-' ? lock->hist.count + ft_atoi(cmd[4])\
		: ft_atoi(cmd[4]);
	else if (ft_stralpha(cmd[4]))
	{
		while (lock->hist.cmdhist[i[1]] && ft_strncmp(cmd[4],\
		lock->hist.cmdhist[i[1]], ft_strlen(cmd[4])))
			i[1]++;
		i[0] > i[1] ? 0 : i[1]++;
	}
	return (lock->opt & OPT_R ? r_edit_exec(menv, lock, i, cmd[2])\
	: edit_exec(menv, lock, i, cmd[2]));
}

char	*one_param(t_masterenv *menv, t_keymaster *lock, char **cmd)
{
	int		i;
	char	*exec;
	char	*tmp;

	if (ft_strdigit(cmd[3]))
	{
		i = cmd[3][0] == '-' ? lock->hist.count + ft_atoi(cmd[3])\
		: ft_atoi(cmd[3]) - 1;
		if (i < lock->hist.count && i > 0 && lock->hist.cmdhist[i])
			return (fc_editor_op(menv, lock, lock->hist.cmdhist[i], cmd[2]));
	}
	else if (ft_stralpha(cmd[3]))
	{
		tmp = fc_chr(lock, 3, cmd);
		exec = fc_editor_op(menv, lock, tmp, cmd[2]);
		free(tmp);
		return (exec);
	}
	return (NULL);
}

char	*fc_editor(t_masterenv *menv, t_keymaster *lock, char **cmd)
{
	char	*exe;
	int		i[2];

	exe = NULL;
	i[0] = 0;
	i[1] = 0;
	if (lock->hist.count > 0 && lock->hist.cmdhist)
		exe = lock->hist.cmdhist[lock->hist.count - 1];
	if (!is_fcfile_ok() || !cmd[2] || (cmd[2] && ft_strcmp(cmd[2], "vim")
	&& ft_strcmp(cmd[2], "emacs") && ft_strcmp(cmd[2], "nano")
	&& ft_strcmp(cmd[2], "vi") && ft_strcmp(cmd[2], "ed")))
		return (NULL);
	if (cmd[2] && !cmd[3] && exe)
		return (fc_editor_op(menv, lock, exe, cmd[2]));
	else if (!cmd[4] && cmd[3])
		return (one_param(menv, lock, cmd));
	else if (cmd[4])
		return (replacebsn(edit_digit(menv, lock, cmd, i)));
	return (NULL);
}
