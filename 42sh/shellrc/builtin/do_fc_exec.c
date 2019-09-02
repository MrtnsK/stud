/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:34:51 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/20 09:41:51 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		options(char *str)
{
	int			i;
	int			opt;

	i = 0;
	opt = 0;
	if (str[0] == '-')
	{
		while (str[++i])
			if (str[i] == 'l')
				opt |= OPT_L;
			else if (str[i] == 'n')
				opt |= OPT_N;
			else if (str[i] == 'r')
				opt |= OPT_R;
			else if (str[i] == 'e')
				opt |= OPT_E;
			else if (str[i] == 's')
				opt |= OPT_S;
			else
				return (illegal_opt(str[i]));
	}
	return (opt);
}

int		ft_exec_fc(char *exec, t_masterenv *menv, t_masterenv *tenv,
t_keymaster *lock)
{
	int		k;

	k = -1;
	tenv->nruter = 0;
	while (++k < 5)
		tenv->rep[k] = menv->rep[k];
	tenv->stock = menv->stock;
	tenv->fcts = menv->fcts;
	tenv->als = menv->als;
	tenv->internal_var = menv->internal_var;
	tenv->inenv = menv->inenv;
	if (theresexp(exec, lock))
		if (exp_main(&exec, lock))
			return (1);
	replace_alias(&exec, menv);
	if (findparserror(&exec) || ft_fcinfc(exec))
		return (1);
	if (ft_preultimain_mk2(&exec, tenv, lock))
		return (1);
	menv->nruter = tenv->nruter;
	menv->als = tenv->als;
	if (menv->nruter != 0)
		return (1);
	return (0);
}

char	*reader_helper(char *str, int fd, char *exec)
{
	int		ret;
	int		tot;
	char	*tmp;

	tot = 0;
	while ((ret = read(fd, exec, BUFF_SIZE)) > 0)
	{
		exec[ret] = '\0';
		if (tot == 0)
			str = ft_strdup(exec);
		else
		{
			tmp = ft_strjoin(str, exec);
			ft_replace_cmd(&str, tmp);
			free(tmp);
		}
		tot += ret;
	}
	free(exec);
	close(fd);
	return (str);
}

char	*fc_editor_reader(char *exec, int fd)
{
	char	*str;

	str = NULL;
	if (!is_fcfile_ok())
		return (NULL);
	if ((fd = open(".fc_edit", O_RDWR, S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	if ((exec = (char *)(malloc(sizeof(char) * (BUFF_SIZE + 1)))) == NULL)
		return (NULL);
	return (reader_helper(str, fd, exec));
}

char	*fc_editor_spe(t_masterenv *menv, t_keymaster *lock)
{
	t_masterenv tenv;
	char		*exec;
	int			fd;
	char		*cmd;

	cmd = NULL;
	if (lock->hist.count > 0 && lock->hist.cmdhist)
		cmd = lock->hist.cmdhist[lock->hist.count - 1];
	if (!cmd || !is_fcfile_ok())
		return (NULL);
	if ((fd = open(".fc_edit", O_RDWR | O_CREAT | O_TRUNC,\
	S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	ft_printfd(fd, "%s", cmd);
	close(fd);
	exec = ft_strjoin("ed ", ".fc_edit");
	if (ft_exec_fc(exec, menv, &tenv, lock))
		return (NULL);
	return (fc_editor_reader(exec, fd));
}
