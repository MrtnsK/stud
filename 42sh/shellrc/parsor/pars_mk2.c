/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mk2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:05:31 by apsaint-          #+#    #+#             */
/*   Updated: 2019/07/01 10:50:24 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_triploswitch(t_masterenv *menv, int a, int b)
{
	int		part1;
	int		part2;
	char	*part3;

	part1 = menv->cgtype[a];
	part2 = menv->cgprio[a];
	part3 = menv->cgv[a];
	menv->cgtype[a] = menv->cgtype[b];
	menv->cgprio[a] = menv->cgprio[b];
	menv->cgv[a] = menv->cgv[b];
	menv->cgtype[b] = part1;
	menv->cgprio[b] = part2;
	menv->cgv[b] = part3;
}

void	ft_memtmp(t_tmper *tmp1, t_tmper *tmp2, t_masterenv *menv, int i)
{
	tmp2->part1 = menv->cgtype[i];
	tmp2->part2 = menv->cgprio[i];
	tmp2->part3 = menv->cgv[i];
	tmp1->part1 = menv->cgtype[i - 1];
	tmp1->part2 = menv->cgprio[i - 1];
	tmp1->part3 = menv->cgv[i - 1];
}

void	ft_resmemtmp(t_tmper *tmp1, t_tmper *tmp2, t_masterenv *menv, int i)
{
	menv->cgtype[i] = tmp2->part1;
	menv->cgprio[i] = tmp2->part2;
	menv->cgv[i] = tmp2->part3;
	menv->cgtype[i - 1] = tmp1->part1;
	menv->cgprio[i - 1] = tmp1->part2;
	menv->cgv[i - 1] = tmp1->part3;
}

void	ft_tab3decaler(t_masterenv *menv, int looker, int rekool)
{
	ft_tabintncpy(menv->cgtype + looker - 1,\
	menv->cgtype + looker + 1, rekool - looker);
	ft_tabintncpy(menv->cgprio + looker - 1,\
	menv->cgprio + looker + 1, rekool - looker);
	ft_tabncpy(menv->cgv + looker - 1,\
	menv->cgv + looker + 1, rekool - looker);
}
