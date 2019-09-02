/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_internvar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 08:01:21 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/14 18:17:43 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "shell.h"

static void	init_pt2(t_masterenv *menv)
{
	char			*tmp_uid;
	char			*tmp_gid;
	char			*user;
	struct passwd	*st_pw;

	if ((user = getenv("USER")))
		st_pw = getpwnam(user);
	else
		return ;
	if (!(tmp_uid = ft_itoa(st_pw->pw_uid)))
		return ;
	if (!(tmp_gid = ft_itoa(st_pw->pw_gid)))
	{
		free(tmp_uid);
		return ;
	}
	ft_addvar(menv->internal_var, setvar("EUID", tmp_uid));
	ft_addvar(menv->internal_var, setvar("GROUPS", tmp_gid));
	free(tmp_uid);
	free(tmp_gid);
}

static void	init_pt3(t_masterenv *menv)
{
	int		i;
	char	*tmp;

	i = 0;
	while (menv->stock[0][i])
	{
		if (!(tmp = ft_strdup(menv->stock[0][i])))
			return ;
		ft_addvar(menv->internal_var, tmp);
		i++;
	}
}

int			ft_init_internalvar(t_masterenv *menv)
{
	char			*pid;
	char			*hostname;

	if (!(menv->internal_var = (char***)malloc(sizeof(char**))))
		return (0);
	menv->internal_var[0] = 0;
	if (!(menv->internal_var[0] = (char**)malloc(sizeof(char*))))
		return (0);
	menv->internal_var[0][0] = 0;
	ft_addvar(menv->internal_var, setvar("HISTFILE", g_lock.hist.histfile));
	if ((hostname = ft_strnew(129)))
		if (!gethostname(hostname, 128))
			ft_addvar(menv->internal_var, setvar("HOSTNAME", hostname));
	if ((pid = ft_itoa(getpid())))
		ft_addvar(menv->internal_var, setvar("$", pid));
	ft_addvar(menv->internal_var, ft_strdup("?=0"));
	ft_addvar(menv->internal_var, ft_strdup("!=0"));
	init_pt2(menv);
	init_pt3(menv);
	free(hostname);
	free(pid);
	return (1);
}
