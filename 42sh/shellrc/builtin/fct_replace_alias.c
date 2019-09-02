/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_replace_alias.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:02:49 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/18 18:18:12 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	end_replace(char **cmd, char *bef, char *alsed, char *aft)
{
	char		*tmp;

	tmp = ft_strjoin(bef, alsed);
	free(bef);
	bef = ft_strjoin(tmp, aft);
	ft_replace_cmd(&cmd[0], bef);
	free(bef);
	free(alsed);
	free(aft);
	free(tmp);
}

void	modify_cmd(t_masterenv *menv, t_alias *tmp, char **cmd, int i)
{
	char		*bef;
	char		*aft;
	char		*alsed;

	bef = ft_strsub(cmd[0], 0, i);
	alsed = cycle_alias(tmp->alias, tmp->name, menv->als);
	aft = ft_strsub(cmd[0], i + ft_strlen(tmp->alias), ft_strlen(cmd[0])\
	- (i + ft_strlen(tmp->alias)));
	end_replace(cmd, bef, alsed, aft);
}

int		replace_helper(t_masterenv *menv, char **cmd, t_alias *tmp, int j[2])
{
	int			i;

	while (tmp)
	{
		if (tmp->alias && (i = ft_strpos(cmd[0], tmp->alias, j[0])) >= 0
		&& i <= j[0])
			if (!ft_strncmp(cmd[0] + i, tmp->alias, ft_strlen(tmp->alias))
			&& can_we_alias(cmd[0], i, i + ft_strlen(tmp->alias) - 1))
			{
				modify_cmd(menv, tmp, cmd, i);
				if (nothing_next(cmd[0], i))
					if (last_space(tmp->name))
						return (-1);
				menv->pals = j[0] + ft_strlen(tmp->name);
				menv->changeals = 1;
				j[1]++;
			}
		tmp = tmp->next;
	}
	return (j[1]);
}

void	replace_alias(char **cmd, t_masterenv *menv)
{
	int			j[2];
	t_alias		*tmp;

	if (!cmd[0] || !ft_strncmp(cmd[0], "unalias", 7)
	|| !ft_strncmp(cmd[0], "alias", 5) || !ft_strncmp(cmd[0], "type", 4))
		return ;
	j[0] = 0;
	j[1] = 0;
	menv->changeals = 0;
	if (menv->als)
		while (j[0] <= (int)ft_strlen(cmd[0]))
		{
			while (cmd[0][j[0]] && !is_apb(cmd[0][j[0]]) && cmd[0][j[0]] != ' ')
				j[0]++;
			tmp = menv->als;
			if ((j[1] = replace_helper(menv, cmd, tmp, j)) == -1)
				return ;
			if (menv->changeals)
			{
				menv->changeals = 0;
				j[0] = menv->pals;
			}
			j[0]++;
		}
}
