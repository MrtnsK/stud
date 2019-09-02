/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mk2_pt3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:05:43 by apsaint-          #+#    #+#             */
/*   Updated: 2019/07/18 11:52:13 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_multicator(t_masterenv *menv, int rekool)
{
	int	i;

	i = rekool + 1;
	while (menv->cgv[++i])
	{
		menv->cgv[i - 2] = menv->cgv[i];
		menv->cgv[i] = 0;
		menv->cgprio[i - 2] = menv->cgprio[i];
		menv->cgtype[i - 2] = menv->cgtype[i];
	}
}

int		ft_cgtrier(t_masterenv *menv, int j, int k)
{
	int		rekol;
	int		looker;
	t_tmper	tmp1;
	t_tmper	tmp2;

	looker = k + 1;
	while (--looker >= j)
		if (menv->cgprio[looker] == 2)
		{
			rekol = k + 1;
			while (--rekol > looker && (menv->cgprio[rekol] >= 20
				|| menv->cgprio[rekol] == 2))
				;
			if (rekol != looker)
			{
				ft_memtmp(&tmp1, &tmp2, menv, looker);
				ft_tab3decaler(menv, looker, rekol);
				ft_resmemtmp(&tmp1, &tmp2, menv, rekol);
			}
		}
	return (k);
}

int		ft_cgepurator(t_masterenv *menv)
{
	int i;
	int j;
	int k;

	i = -1;
	while (menv->cgv[++i])
		if (menv->cgprio[i] > 20)
		{
			j = i;
			k = i;
			while (--j > 0 && menv->cgtype[j] != 12)
				;
			if (j < 0 || menv->cgtype[j] == 12)
				j++;
			while (menv->cgv[++k] && menv->cgtype[k] != 12)
				;
			if (!menv->cgv[k] || menv->cgtype[k] == 12)
				k--;
			k = ft_cgtrier(menv, j, k);
			i = k;
		}
	return (0);
}

int		ft_prio(t_masterenv *menv, char **buf)
{
	int		i;
	int		nope;

	i = -1;
	nope = 1;
	menv->neight = 1;
	while (menv->cgv[++i])
	{
		if (ft_if_prio(menv, i, nope, buf) == 1)
			return (1);
		if (menv->cgtype[i] == 12)
		{
			menv->cgprio[i] = 12;
			menv->neight = 1;
			nope = 0;
		}
	}
	return (ft_cgepurator(menv));
}

int		ft_errorpars_mk2(t_masterenv *menv, char **buf)
{
	int i;

	ft_printfd(2, "\e[93mMastershell\e[0m: parse error\n");
	i = -1;
	free(buf[0]);
	menv->nruter = 1;
	return (1);
}
