/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:15:48 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/19 09:23:59 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_pre_exec_fc(char *exec, t_masterenv *menv, t_masterenv *tenv,
t_keymaster *lock)
{
	int			ret;

	ret = 0;
	if (ft_exec_fc(exec, menv, tenv, lock))
		ret = 1;
	return (ret);
}

int		precheck(char *str, t_keymaster *lock)
{
	int			i;

	i = str[0] == '-' ? lock->hist.count + ft_atoi(str) - 1 : ft_atoi(str);
	if (i < 0 || i > lock->hist.count)
		return (1);
	return (0);
}

int		test_hist(t_masterenv *menv, t_keymaster *lock)
{
	int			i;

	i = 1;
	if (lock->hist.count <= 0)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: it seems like there's \
something wrong with historic\n");
		return (1);
	}
	while (i <= menv->cgc && menv->cgv[i])
	{
		if (precheck(menv->cgv[i], lock))
		{
			error_list();
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_dofc_following(int opt, char **cmd, t_masterenv *menv,
t_keymaster *lock)
{
	char		*exec;
	int			cgc;

	exec = NULL;
	cgc = ft_tablen(cmd);
	if ((opt = options(cmd[1])) == -1)
		return (0);
	lock->opt = opt;
	if (cmd[1] && (opt == 0 || opt & OPT_R || opt & OPT_N)
	&& !(opt & OPT_E) && !(opt & OPT_L))
		exec = simple_fc(menv, lock, pre_simple(cmd), exec);
	else if (cmd[1] && opt & OPT_S && !cmd[2])
		exec = ft_strdup(lock->hist.cmdhist[lock->hist.count - 1]);
	else if (cmd[1] && opt & OPT_S && cmd[2])
		exec = fc_s(lock, 2, cmd);
	else if (cmd[1] && opt & OPT_E && !cmd[2])
		fc_usage();
	else if (cmd[1] && opt & OPT_E && cmd[2])
		exec = fc_editor(menv, lock, cmd);
	else if (cmd[1] && opt & OPT_L && opt & OPT_R)
		fc_rlist(lock, opt, cmd);
	else if (cmd[1] && opt & OPT_L)
		fc_list(lock, opt, cmd);
	return (exec);
}

int		ft_dofc(t_masterenv *menv, t_keymaster *lock, char **cmd)
{
	char		*exec;
	int			cgc;
	t_masterenv tenv;

	exec = NULL;
	lock->hist.fc = 1;
	cgc = ft_tablen(cmd);
	if (test_hist(menv, lock))
		return (0);
	if (cgc == 1)
		return (fc_noarg(menv, lock, &tenv, exec));
	exec = ft_dofc_following(0, cmd, menv, lock);
	if (exec)
		if (ft_pre_exec_fc(exec, menv, &tenv, lock))
			return (1);
	return (exec || lock->hist.fc != 1 ? 0 : 1);
}
