/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_job.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:38:01 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 11:35:41 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_execute_bg_builtin(t_masterenv *tenv, t_job *new_j)
{
	int		ret;

	if (!(new_j->fst_process = new_process()))
		return (0);
	if ((g_pid = fork()) == -1)
		return (-1);
	if (g_pid == 0)
	{
		launch_process(new_j, tenv, tenv->fg);
		ret = ft_builtin(tenv, tenv->cgv);
		tenv->nruter = ret;
		exit(ret);
	}
	else
	{
		if (!new_j->pgid)
			new_j->pgid = g_pid;
		set_process(new_j, g_pid, -1, tenv);
		setpgid(g_pid, new_j->pgid);
	}
	back_fore(tenv, new_j, tenv->fg);
	return (0);
}

int			ft_execute_bg(t_keymaster *lock, t_masterenv *menv)
{
	int		i;
	t_job	*new_j;

	i = -1;
	(void)lock;
	menv->fg = 0;
	if (!ft_notbltin(menv->cgv[0]) && !ft_checkpipe(menv, menv->cgc)
	&& !ft_checkredir(menv, i, menv->cgc))
	{
		if (!(new_j = new_job()))
			return (0);
		ft_execute_bg_builtin(menv, new_j);
	}
	else
		return (1);
	return (0);
}

int			ft_supvarinit(t_masterenv *tenv, int start)
{
	int	i;
	int	k;
	int	c;

	i = start;
	k = -1;
	c = 0;
	while (tenv->cgv[++i] && tenv->cgprio[i] == 8)
	{
		while (tenv->stock[0][++k])
		{
			if (!ft_strcmp(tenv->stock[0][k], tenv->cgv[i]))
			{
				k = -1;
				c++;
				break ;
			}
		}
	}
	return (c);
}

char		**ft_supvarcre(t_masterenv *tenv, int size, int i, int j)
{
	int		k;
	char	**var_sup;

	k = -1;
	if (!(var_sup = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	var_sup[size] = 0;
	size = 0;
	while (tenv->cgv[++i] && tenv->cgprio[i] == 8)
	{
		while (tenv->stock[0][++k])
		{
			if (!ft_strcmp(tenv->stock[0][k], tenv->cgv[i]))
			{
				size = ft_strchri(tenv->cgv[i], '=');
				if (!(var_sup[++j] = ft_strsub(tenv->cgv[i], 0, size)))
					return (NULL);
				k = -1;
				break ;
			}
		}
	}
	return (var_sup);
}

int			ft_check_final(t_masterenv *menv, char **buf)
{
	char	*tmp;

	tmp = ft_strtrim(buf[0]);
	if (!ft_strcmp(tmp, "|"))
	{
		ft_inirep(menv, 0);
		ft_freear(menv, buf[0]);
		ft_printfd(2, "\e[93mMastershell\e[0m: Parse error\n");
		menv->nruter = 1;
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
