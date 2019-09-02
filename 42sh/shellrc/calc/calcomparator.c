/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcomparator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:05:07 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:05:12 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_calcomparatorend(char **calc, char **avant, int ope)
{
	double	f1;
	double	f2;

	f1 = ft_atof(avant[0]);
	f2 = ft_atof(calc[0]);
	free(avant[0]);
	free(calc[0]);
	if (!(calc[0] = (char*)malloc(sizeof(char) * 2)))
		return (1);
	calc[0][1] = 0;
	if (ope == 0)
		calc[0][0] = (f1 == f2) ? '1' : '0';
	if (ope == 1)
		calc[0][0] = (f1 != f2) ? '1' : '0';
	if (ope == 2)
		calc[0][0] = (f1 < f2) ? '1' : '0';
	if (ope == 3)
		calc[0][0] = (f1 <= f2) ? '1' : '0';
	if (ope == 4)
		calc[0][0] = (f1 > f2) ? '1' : '0';
	if (ope == 5)
		calc[0][0] = (f1 >= f2) ? '1' : '0';
	return (0);
}

int		ft_corecalcomparator_pt2(char **calc, int i, int ope)
{
	char	*avant;

	if (!(avant = (char*)malloc(sizeof(char) * (ft_strlen(calc[0]) + 1))))
		return (1);
	ft_strcpy(avant, calc[0]);
	if (!ft_is(avant))
		return (ft_corecalcomparator_badend(&avant));
	if (ft_resultor(&avant))
		return (ft_corecalcomparator_badend(&avant));
	calc[0][0] = 0;
	if (calc[0][i + 1] && calc[0][i + 1] == '=' && calc[0][i + 2])
		ft_strcator(calc[0], calc[0] + i + 2);
	else if (calc[0][i + 1])
		ft_strcator(calc[0], calc[0] + i + 1);
	if (!ft_is(calc[0]))
		return (ft_corecalcomparator_badend(&avant));
	if (ft_resultor(calc))
		return (ft_corecalcomparator_badend(&avant));
	return (ft_calcomparatorend(calc, &avant, ope));
}

int		ft_corecalcomparator(char **calc, int i)
{
	int		ope;

	ope = -1;
	if (calc[0][i] == '=' && calc[0][i + 1] == '=')
		ope = 0;
	if (calc[0][i] == '!' && calc[0][i + 1] == '=')
		ope = 1;
	if (calc[0][i] == '<' && calc[0][i + 1] != '=')
		ope = 2;
	if (calc[0][i] == '<' && calc[0][i + 1] == '=')
		ope = 3;
	if (calc[0][i] == '>' && calc[0][i + 1] != '=')
		ope = 4;
	if (calc[0][i] == '>' && calc[0][i + 1] == '=')
		ope = 5;
	if (ope == -1)
	{
		ft_printfd(2, "operator not found\n");
		free(calc[0]);
		return (1);
	}
	calc[0][i] = 0;
	return (ft_corecalcomparator_pt2(calc, i, ope));
}

int		ft_calcomparator_core(char **calc, int i)
{
	char	*tmp;
	int		j;

	j = i;
	if (calc[0][j + 1] == '=')
		j++;
	while (calc[0][++j] && calc[0][j] != '!' && calc[0][j] != '<'
		&& calc[0][j] != '>' && calc[0][j] != '=')
		;
	if (!(tmp = (char*)malloc(sizeof(char) * (j + 1))))
		;
	ft_strncpy(tmp, calc[0], j);
	tmp[j] = 0;
	if (ft_corecalcomparator(&tmp, i))
	{
		free(tmp);
		return (1);
	}
	calc[0][0] = tmp[0];
	calc[0][1] = 0;
	ft_strcator(calc[0], calc[0] + j);
	free(tmp);
	return (0);
}

int		ft_calcomparator(char **calc, int i)
{
	i = -1;
	while (calc[0][++i])
	{
		if (calc[0][i] == '<' || calc[0][i] == '>'
			|| calc[0][i] == '=' || calc[0][i] == '!')
		{
			if (ft_calcomparator_core(calc, i))
				return (1);
			i = 0;
		}
	}
	return (0);
}
