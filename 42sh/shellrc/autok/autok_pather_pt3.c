/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autok_pather_pt3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:13:04 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:13:05 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_pather_1opt_dir(t_keymaster *lock, int i)
{
	if (!ft_strcmp(lock->contdir[i], lock->final))
	{
		if (!(lock->complete = (char*)malloc(sizeof(char) * 2)))
			return (1);
		lock->complete[0] = '/';
		lock->complete[1] = 0;
	}
	else
	{
		if (!(lock->complete = (char*)malloc(sizeof(char)
			* (2 + ft_strlen(lock->contdir[i]) - ft_strlen(lock->final)))))
			return (1);
		ft_strcpy(lock->complete, lock->contdir[i] + ft_strlen(lock->final));
		ft_strcat(lock->complete, "/");
	}
	return (0);
}

int			ft_pather_1opt_file(t_keymaster *lock, int i)
{
	if (!ft_strcmp(lock->contdir[i], lock->final))
	{
		if (!(lock->complete = (char*)malloc(sizeof(char) * 2)))
			return (1);
		lock->complete[0] = ' ';
		lock->complete[1] = 0;
	}
	else
	{
		if (!(lock->complete = (char*)malloc(sizeof(char)
			* (2 + ft_strlen(lock->contdir[i]) - ft_strlen(lock->final)))))
			return (1);
		ft_strcpy(lock->complete, lock->contdir[i] + ft_strlen(lock->final));
		ft_strcat(lock->complete, " ");
	}
	return (0);
}

int			jpp(t_keymaster *lock)
{
	free(lock->tmp);
	free(lock->final);
	return (0);
}
