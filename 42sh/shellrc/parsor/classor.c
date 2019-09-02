/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:20:26 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/20 14:53:49 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_calcnbtool_pt2(t_nbtool *koul, int *i, char *buf)
{
	if (buf[*i] == '$' && (*i == 0 || buf[*i - 1] != '\\')
		&& (buf[*i + 1] == '(' || buf[*i + 1] == '{')
		&& koul->parf == 1 && koul->sparf == 1)
	{
		*i += 2;
		koul->cpt = 1;
		koul->dparf = -1;
		koul->par = 1;
		if (buf[*i - 1] == '{')
			koul->par = 2;
	}
	if (koul->dparf == -1 && buf[*i] == '(' && koul->par == 1)
		koul->cpt += 1;
	if (koul->dparf == -1 && buf[*i] == ')' && koul->par == 1)
		koul->cpt -= 1;
	if (koul->dparf == -1 && buf[*i] == '{' && koul->par == 2)
		koul->cpt += 1;
	if (koul->dparf == -1 && buf[*i] == '}' && koul->par == 2)
		koul->cpt -= 1;
	if (koul->dparf == -1 && koul->cpt == 0)
		koul->dparf = 1;
}

static void	ft_calcnbtool(t_nbtool *koul, int *i, char *buf)
{
	if (!ft_isspace(buf[*i]) && koul->flag && koul->parf == 1
		&& koul->sparf == 1 && koul->dparf == 1)
	{
		koul->flag = 0;
		koul->nb += 1;
	}
	if (ft_isspace(buf[*i]) && buf[*i - 1] != '\\'
		&& koul->parf == 1 && koul->sparf == 1 && koul->dparf == 1)
		koul->flag = 1;
	if (buf[*i] == '"' && (*i == 0 || buf[*i - 1] != '\\') && koul->sparf == 1
		&& koul->dparf == 1)
		koul->parf *= -1;
	if (buf[*i] == '\'' && (*i == 0 || buf[*i - 1] != '\\') && koul->parf == 1
		&& koul->dparf == 1)
		koul->sparf *= -1;
	ft_calcnbtool_pt2(koul, i, buf);
}

int			ft_calcnb_initer(t_masterenv *menv, int nb)
{
	int i;

	i = -1;
	while (++i < nb)
	{
		menv->cgprio[i] = 0;
		menv->cgtype[i] = 0;
	}
	return (nb);
}

static int	ft_calcnb(t_masterenv *menv, char *buf)
{
	int			i;
	t_nbtool	koul;

	i = -1;
	koul.nb = 0;
	koul.flag = 1;
	koul.parf = 1;
	koul.sparf = 1;
	koul.dparf = 1;
	koul.par = 0;
	koul.cpt = 0;
	while (buf[++i])
		ft_calcnbtool(&koul, &i, buf);
	menv->cgc = koul.nb;
	if (!(menv->cgv = (char**)malloc(sizeof(char*) * (koul.nb + 1))))
		return (-10);
	menv->cgv[koul.nb] = 0;
	if (!(menv->cgtype = (int*)malloc(sizeof(int) * (koul.nb + 1))))
		return (-10);
	if (!(menv->cgprio = (int*)malloc(sizeof(int) * (koul.nb + 1))))
		return (-10);
	return (ft_calcnb_initer(menv, koul.nb));
}

int			ft_classor(t_masterenv *menv, char **buf)
{
	int nb;

	if ((nb = ft_calcnb(menv, buf[0])) == -10)
		return (1);
	if (ft_remplissor(menv, nb, buf[0]))
		return (1);
	if (ft_pars_mk2(menv, buf))
	{
		ft_freetabc(menv->cgv);
		free(menv->cgprio);
		free(menv->cgtype);
		return (1);
	}
	if (ft_piperror(menv, buf))
		return (1);
	return (0);
}
