/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc_simple_retouch.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:06:09 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/19 10:37:00 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*r_edit_exec(t_masterenv *menv, t_keymaster *lock, int i[2], char *edit)
{
	int			fd;
	char		*exec;
	t_masterenv tenv;

	if (!is_fcfile_ok())
		return (NULL);
	if ((fd = open(".fc_edit", O_RDWR | O_CREAT | O_TRUNC,\
	S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	if (i[1] > i[0] && lock->hist.count > 0 && i[1] >= 0)
	{
		i[0] -= 1;
		while (--i[1] > i[0] && lock->hist.cmdhist[i[1]])
			ft_printfd(fd, "%s\n", lock->hist.cmdhist[i[1]]);
	}
	else if (i[0] >= i[1] && lock->hist.count > 0)
		while (--i[0] >= i[1] && lock->hist.cmdhist[i[0]] && i[0] >= 0)
			ft_printfd(fd, "%s\n", lock->hist.cmdhist[i[0]]);
	close(fd);
	exec = ft_strjoin(edit, " .fc_edit");
	if (ft_exec_fc(exec, menv, &tenv, lock))
		return (NULL);
	return (fc_editor_reader(exec, fd));
}

char	*replacebsn(char *str)
{
	int		i[2];
	char	*cmd;

	if (!(cmd = (char*)malloc(sizeof(char) * (ft_strlen(str) * 2))))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	if (str)
		while (str[i[0]])
		{
			if (str[i[0]] == '\n')
				cmd[i[1]] = ';';
			else
				cmd[i[1]] = str[i[0]];
			i[1]++;
			i[0]++;
		}
	if (str)
		free(str);
	cmd[i[1]] = '\0';
	return (cmd);
}

int		is_fcfile_ok(void)
{
	struct stat	perm;

	if (stat(".fc_edit", &perm) < 0)
		return (-1);
	if (perm.st_mode && (perm.st_mode & S_IRUSR) && (perm.st_mode & S_IWUSR)
	&& !(perm.st_mode & S_IXUSR) && !(perm.st_mode & S_IRGRP)
	&& !(perm.st_mode & S_IWGRP) && !(perm.st_mode & S_IXGRP)
	&& !(perm.st_mode & S_IROTH) && !(perm.st_mode & S_IWOTH)
	&& !(perm.st_mode & S_IXOTH))
		return (1);
	ft_printfd(2, "\e[93mMastershell\e[0m: you should stop messing up \
with the permission\n");
	return (0);
}

int		fc_noarg(t_masterenv *menv, t_keymaster *lock, t_masterenv *tenv,
char *exec)
{
	if (!(exec = fc_editor_spe(menv, lock)))
		return (1);
	exec[ft_strlen(exec) - 1] == '\n' ? ft_printfd(1, "%s", exec)\
	: ft_printfd(1, "%s\n", exec);
	if (ft_exec_fc(exec, menv, tenv, lock))
		return (1);
	return (0);
}

char	**pre_simple(char **cmd)
{
	int		i;

	i = 3;
	if (cmd[1] && cmd[1][0] == '-')
	{
		if (!cmd[2])
			ft_strdel(&cmd[1]);
		else if (cmd[2])
		{
			ft_replace_cmd(&cmd[1], cmd[2]);
			if (!cmd[3])
				ft_strdel(&cmd[2]);
		}
		if (cmd[1] && cmd[3])
		{
			ft_replace_cmd(&cmd[2], cmd[3]);
			while (cmd[i])
				ft_strdel(&cmd[i++]);
		}
	}
	return (cmd);
}
