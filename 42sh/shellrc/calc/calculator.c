/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:18:06 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:05:25 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_calculatorpt1(int i, int *j, char **toretouch, char **calc)
{
	int cpt;

	cpt = 0;
	while (toretouch[0][*j])
	{
		if (toretouch[0][*j] == '(')
			cpt++;
		if (toretouch[0][*j] == ')')
			cpt--;
		if (toretouch[0][*j] == ')' && toretouch[0][*j + 1] == ')'
			&& (cpt - 1) == 0)
			break ;
		*j += 1;
	}
	toretouch[0][*j] = 0;
	if (!(calc[0] = (char*)malloc(sizeof(char)
		* ft_strlen(toretouch[0] + i + 2))))
		return (1);
	ft_strcpy(calc[0], toretouch[0] + i + 3);
	toretouch[0][*j] = ')';
	return (0);
}

int			ft_calculatorendit(char **toretouch, char **calc, int i, int j)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char)
		* (ft_strlen(toretouch[0]) - (j - i - 1) + ft_strlen(calc[0])))))
		return (1);
	toretouch[0][i] = 0;
	ft_strcpy(tmp, toretouch[0]);
	ft_strcat(tmp, calc[0]);
	ft_strcat(tmp, toretouch[0] + j + 2);
	free(toretouch[0]);
	if (!(toretouch[0] = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		return (1);
	ft_strcpy(toretouch[0], tmp);
	free(tmp);
	free(calc[0]);
	return (0);
}

int			ft_calculator(char **toretouch, t_masterenv *menv)
{
	int		j;
	int		i;
	char	*calc;

	i = -1;
	while (toretouch[0][++i])
		if (toretouch[0][i] == '$' && toretouch[0][i + 1] == '('
			&& toretouch[0][i + 2] == '(')
		{
			j = i + 1;
			if (ft_calculatorpt1(i, &j, toretouch, &calc))
				return (1);
			ft_strtrim_calc(&calc);
			if (ft_goodcara(&calc))
				return (1);
			if (ft_ulticalclauncher(&calc, menv))
				return (1);
			if (ft_calculatorendit(toretouch, &calc, i, j))
				return (1);
		}
	return (0);
}
