/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulticalclauncher_pt2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:07:02 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:07:03 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_gettoitcore(double **ftabor, int **indexor, int i)
{
	int	bef;
	int	aft;

	bef = i;
	aft = i;
	while (--bef >= 0 && indexor[0][bef] != 10)
		;
	if (bef == -1)
		return (1);
	while (indexor[0][++aft] != -42 && indexor[0][aft] != 10)
		;
	if (indexor[0][aft] == -42)
		return (1);
	if (indexor[0][i] == 2)
		ftabor[0][bef] = (ftabor[0][bef] || ftabor[0][aft]) ? 1 : 0;
	else
		ftabor[0][bef] = (ftabor[0][bef] && ftabor[0][aft]) ? 1 : 0;
	indexor[0][aft] = -1;
	return (0);
}

int			ft_gettoit(double **ftabor, int **indexor, char ***tablor)
{
	int	i;
	int yep;

	i = -1;
	yep = 0;
	while (indexor[0][++i] != -42)
		if (indexor[0][i] == 1 || indexor[0][i] == 2)
		{
			yep = 1;
			if (ft_gettoitcore(ftabor, indexor, i))
				return (1);
		}
	if (yep)
	{
		free(tablor[0][0]);
		tablor[0][0] = ft_ftoa(ftabor[0][0], 0);
		tablor[0][0][1] = 0;
	}
	return (0);
}

int			ft_preulticalcmallocer(char **calc, t_preult *eul)
{
	int		i;
	int		cpt;

	i = -1;
	cpt = 0;
	while (calc[0][++i])
		if ((calc[0][i] == '&' && calc[0][i + 1] == '&')
			|| (calc[0][i] == '|' && calc[0][i + 1] == '|'))
			cpt++;
	if (!(eul->tablor = (char**)malloc(sizeof(char*) * ((cpt * 2) + 2))))
		return (1);
	if (!(eul->ftabor = (double*)malloc(sizeof(double) * ((cpt * 2) + 2))))
		return (1);
	if (!(eul->indexor = (int*)malloc(sizeof(int) * ((cpt * 2) + 2))))
		return (1);
	i = -1;
	while (++i < ((cpt * 2) + 2))
	{
		eul->ftabor[i] = 0;
		eul->indexor[i] = 0;
	}
	eul->tablor[(cpt * 2) + 1] = 0;
	eul->indexor[(cpt * 2) + 1] = -42;
	return (0);
}

static int	ft_preulticalcremplissorcore(char **calc, int i, int cpt
	, t_preult *eul)
{
	if (calc[0][i] == '&')
	{
		eul->tablor[cpt + 1] = NULL;
		eul->indexor[cpt + 1] = 1;
	}
	else
	{
		eul->tablor[cpt + 1] = NULL;
		eul->indexor[cpt + 1] = 2;
	}
	eul->indexor[cpt] = 10;
	calc[0][i] = 0;
	if (!(eul->tablor[cpt] = (char*)malloc(sizeof(char)
		* (ft_strlen(calc[0]) + 1))))
		return (-1);
	ft_strcpy(eul->tablor[cpt], calc[0]);
	i++;
	calc[0][0] = 0;
	if (calc[0][i + 1])
		ft_strcator(calc[0], calc[0] + i + 1);
	return (cpt);
}

int			ft_preulticalcremplissor(char **calc, t_preult *eul)
{
	int			i;
	int			cpt;

	i = -1;
	cpt = 0;
	while (calc[0][++i])
		if ((calc[0][i] == '&' && calc[0][i + 1] && calc[0][i + 1] == '&')
			|| (calc[0][i] == '|' && calc[0][i + 1] && calc[0][i + 1] == '|'))
		{
			if ((cpt = ft_preulticalcremplissorcore(calc, i, cpt, eul)) == -1)
				return (1);
			i = -1;
			cpt += 2;
		}
	if (!(eul->tablor[cpt] = (char*)malloc(sizeof(char)
		* (ft_strlen(calc[0]) + 1))))
		return (1);
	ft_strcpy(eul->tablor[cpt], calc[0]);
	eul->indexor[cpt] = 10;
	return (0);
}
