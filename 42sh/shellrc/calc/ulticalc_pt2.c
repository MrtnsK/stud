/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulticalc_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:06:35 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:06:36 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_incbef(char *word, char **number, int incbef, t_masterenv *menv)
{
	int		i;
	double	yes;

	yes = ft_atof(number[0]);
	i = -1;
	if (incbef == -1)
		yes--;
	else
		yes++;
	free(number[0]);
	number[0] = ft_ftoa(yes, 18);
	if (yes == (long long)yes)
		while (number[0][++i])
			if (number[0][i] == '.')
				number[0][i] = 0;
	ft_addvar(menv->internal_var, setvar(word, number[0]));
}

void		ft_incaft(char *word, char **number, int incaft, t_masterenv *menv)
{
	int		i;
	double	yes;

	yes = ft_atof(number[0]);
	i = -1;
	if (incaft == -1)
		yes--;
	else
		yes++;
	free(number[0]);
	number[0] = ft_ftoa(yes, 18);
	if (yes == (long long)yes)
		while (number[0][++i])
			if (number[0][i] == '.')
				number[0][i] = 0;
	ft_addvar(menv->internal_var, setvar(word, number[0]));
}

static int	ft_wordproblem(char *word)
{
	int i;

	i = -1;
	while (word[++i])
		if (!ft_isalnum(word[i]))
			return (1);
	return (0);
}

static int	ft_worder_pt2(char **word, int save)
{
	if (save != 0 && !ft_isspace(word[0][save]))
	{
		word[0][0] = 0;
		ft_strcator(word[0], word[0] + save);
	}
	else if (ft_isspace(word[0][save]))
	{
		word[0][0] = 0;
		ft_strcator(word[0], word[0] + save + 1);
	}
	if (ft_wordproblem(word[0]))
	{
		ft_printfd(2, "lvalue required\n");
		return (1);
	}
	return (0);
}

int			ft_worder(char **word)
{
	int	i;
	int	save;

	i = -1;
	while (word[0][++i])
		;
	while (--i > 0 && ft_isspace(word[0][i]))
		word[0][i] = 0;
	if (i == 0)
	{
		ft_printfd(2, "no stuff before the =\n");
		return (1);
	}
	while (--i > 0 && !ft_isspace(word[0][i]))
		;
	save = i;
	while (--i > 0)
		if (!ft_isspace(word[0][i]))
		{
			ft_printfd(2, "too much stuff before the =\n");
			return (1);
		}
	return (ft_worder_pt2(word, save));
}
