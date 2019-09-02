/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moder_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:27:11 by apsaint-          #+#    #+#             */
/*   Updated: 2019/06/18 10:42:19 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_failed(void)
{
	ft_printfd(2, "\n\e[93mMastershell failed to please you[0m\n");
	return (1);
}

void	ft_right(t_keymaster *lock, t_stockap *pac)
{
	lock->curspos -= 1;
	ft_simplegoright(lock, pac);
}

void	ft_controlcerstuff_2(void)
{
	g_lock.curspos = g_lock.promptsize;
	g_lock.aukprinted = 0;
	g_lock.out[0] = 0;
	g_ultib[0] = 0;
	g_lock.selectmode = 0;
	g_lock.heremode = 0;
	g_lock.search = 0;
	g_lock.herelvl = 0;
	free(g_lock.sep);
	g_lock.sep = NULL;
	free(g_lock.rechist);
	g_lock.rechist = NULL;
	ft_printfd(0, "\n\e[93mMastershell\e[0m$> ");
}
