/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulticalc_pt3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:06:44 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:06:47 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_replassor(char **toretouch, char *calc, int i, int j)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char)
		* (ft_strlen(toretouch[0]) - (j - i - 1) + ft_strlen(calc)))))
		return (1);
	toretouch[0][i] = 0;
	ft_strcpy(tmp, toretouch[0]);
	ft_strcat(tmp, calc);
	ft_strcat(tmp, toretouch[0] + j + 1);
	free(toretouch[0]);
	if (!(toretouch[0] = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		return (1);
	ft_strcpy(toretouch[0], tmp);
	free(tmp);
	return (0);
}

static int	ft_foundvalue(t_masterenv *menv, char **calc, int i, t_palten *pal)
{
	if (pal->incbef)
		ft_incbef(pal->test, &pal->hope, pal->incbef, menv);
	if (ft_replassor(calc, pal->hope, i, pal->j - 1))
		return (1);
	pal->j += ft_strlen(pal->hope) - pal->j - i;
	if (pal->incaft)
		ft_incaft(pal->test, &pal->hope, pal->incaft, menv);
	free(pal->hope);
	return (0);
}

static int	ft_changendcore(t_masterenv *menv, char **calc, int i
	, t_palten *pal)
{
	pal->incaft = 0;
	pal->incbef = 0;
	pal->j = i + 1;
	while (calc[0][pal->j] && ft_isalnum(calc[0][pal->j]))
		pal->j += 1;
	if (!(pal->test = (char*)malloc(sizeof(char) * (pal->j - i + 1))))
		return (-10);
	ft_strncpy(pal->test, calc[0] + i, pal->j - i);
	pal->test[pal->j - i] = 0;
	pal->hope = ft_getvalue(menv, pal->test);
	if (i >= 2 && ((calc[0][i - 1] == '+' && calc[0][i - 2] == '+')
		|| (calc[0][i - 1] == '-' && calc[0][i - 2] == '-')))
	{
		pal->incbef = (calc[0][i - 1] == '+') ? 1 : -1;
		i -= 2;
	}
	if (calc[0][pal->j] && calc[0][pal->j + 1] && ((calc[0][pal->j] == '+'
		&& calc[0][pal->j + 1] == '+')
		|| (calc[0][pal->j] == '-' && calc[0][pal->j + 1] == '-')))
	{
		pal->incaft = (calc[0][pal->j] == '+') ? 1 : -1;
		pal->j += 2;
	}
	return (i);
}

int			ft_changend(t_masterenv *menv, char **calc, int i)
{
	t_palten	pal;

	while (calc[0][++i])
	{
		if (ft_isalpha(calc[0][i]))
		{
			if ((i = ft_changendcore(menv, calc, i, &pal)) == -10)
				return (1);
			if (pal.hope)
			{
				if (ft_foundvalue(menv, calc, i, &pal))
					return (1);
			}
			else
			{
				if (ft_replassor(calc, "0", i, pal.j - 1))
					return (1);
			}
			free(pal.test);
			i = pal.j - 1;
		}
	}
	return (0);
}

int			ft_createwn_pt2(char **word, char **number, char **calc, int i)
{
	int j;

	j = i;
	while (calc[0][++j])
		;
	j--;
	if (!(number[0] = (char*)malloc(sizeof(char) * (j - i + 2))))
		return (1);
	ft_strncpy(number[0], calc[0] + i, j - i + 1);
	number[0][j - i + 1] = 0;
	if (ft_resultor(number))
	{
		free(word[0]);
		return (1);
	}
	free(calc[0]);
	if (!(calc[0] = (char*)malloc(sizeof(char)
		* (ft_strlen(number[0]) + 1))))
		return (1);
	ft_strcpy(calc[0], number[0]);
	return (0);
}
