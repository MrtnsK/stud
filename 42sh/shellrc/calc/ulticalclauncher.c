/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulticalclauncher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:06:55 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:06:56 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_preulticalculator(char **calc, t_masterenv *menv, t_preult *eul)
{
	int i;

	i = -1;
	while (eul->indexor[++i] != -42)
		if (eul->indexor[i] == 10)
		{
			if (!ft_lifechecker(eul->tablor[i]))
			{
				ft_printfd(2, "manque un calcul la\n");
				freepreulticalc(&eul->tablor, &eul->ftabor, &eul->indexor);
				free(calc[0]);
				return (1);
			}
			if (ft_ulticalc(&eul->tablor[i], menv))
			{
				freepreulticalc(&eul->tablor, &eul->ftabor, &eul->indexor);
				free(calc[0]);
				return (1);
			}
			ft_putanswer(&eul->tablor[i], &eul->ftabor[i]);
		}
	return (0);
}

int		ft_preulticalc(char **calc, t_masterenv *menv)
{
	t_preult	eul;

	if (ft_checkcalc(calc))
	{
		free(calc[0]);
		return (1);
	}
	if (ft_preulticalcmallocer(calc, &eul)
		|| ft_preulticalcremplissor(calc, &eul)
		|| ft_preulticalculator(calc, menv, &eul))
		return (1);
	if (ft_gettoit(&eul.ftabor, &eul.indexor, &eul.tablor))
	{
		freepreulticalc(&eul.tablor, &eul.ftabor, &eul.indexor);
		free(calc[0]);
		return (1);
	}
	free(calc[0]);
	if (!(calc[0] = (char*)malloc(sizeof(char)
		* (ft_strlen(eul.tablor[0]) + 1))))
		return (1);
	ft_strcpy(calc[0], eul.tablor[0]);
	freepreulticalc(&eul.tablor, &eul.ftabor, &eul.indexor);
	return (0);
}

int		ft_ulticalclaunchercore(char **calc, t_masterenv *menv, int i)
{
	char	*newcalc;

	calc[0][i] = 0;
	if (!(newcalc = (char*)malloc(sizeof(char)
		* (ft_strlen(calc[0]) + 1))))
		return (1);
	ft_strcpy(newcalc, calc[0]);
	if (ft_preulticalc(&newcalc, menv))
	{
		free(calc[0]);
		return (1);
	}
	free(newcalc);
	calc[0][0] = 0;
	if (calc[0][i + 1])
		ft_strcator(calc[0], calc[0] + i + 1);
	return (0);
}

int		ft_ulticalclauncher(char **calc, t_masterenv *menv)
{
	int		i;

	if (ft_checkcalc(calc))
		return (1);
	i = -1;
	while (calc[0][++i])
		if (calc[0][i] == ',')
		{
			if (ft_ulticalclaunchercore(calc, menv, i))
				return (1);
			i = -1;
		}
	if (ft_preulticalc(calc, menv))
		return (1);
	return (0);
}
