/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulticalc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:06:23 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:06:25 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_createwn(char **word, char **number, char **calc, int i)
{
	int j;

	j = 0;
	if (!(word[0] = (char*)malloc(sizeof(char) * (i - j + 1))))
		return (1);
	ft_strncpy(word[0], calc[0] + j, i - j);
	word[0][i - j] = 0;
	if (ft_worder(word))
	{
		free(word[0]);
		return (1);
	}
	i++;
	return (ft_createwn_pt2(word, number, calc, i));
}

int		ft_findultioperatorcore(t_masterenv *menv, char **calc, int i, int cpt)
{
	if (calc[0][i] == '=' && calc[0][i + 1] != '='
		&& calc[0][i - 1] != '<' && calc[0][i - 1] != '>'
		&& calc[0][i - 1] != '!' && calc[0][i - 1] != '=')
	{
		cpt++;
		if (ft_changend(menv, calc, i))
			return (-1);
	}
	if ((calc[0][i] == '=' && calc[0][i + 1] && calc[0][i + 1] == '=')
		|| (calc[0][i] == '<' && calc[0][i + 1] && calc[0][i + 1] == '=')
		|| (calc[0][i] == '>' && calc[0][i + 1] && calc[0][i + 1] == '=')
		|| (calc[0][i] == '!' && calc[0][i + 1] && calc[0][i + 1] == '=')
		|| (calc[0][i] == '<' && calc[0][i + 1] != '<')
		|| (calc[0][i] == '>' && calc[0][i + 1] != '>'))
	{
		cpt++;
		if (ft_changend(menv, calc, -1))
			return (-1);
	}
	return (cpt);
}

int		ft_findultioperator(t_masterenv *menv, char **calc)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (calc[0][++i])
	{
		if ((cpt = ft_findultioperatorcore(menv, calc, i, cpt)) == -1)
			return (-1);
	}
	if (cpt)
		return (1);
	if (ft_changend(menv, calc, -1))
		return (-1);
	return (0);
}

int		ft_ulticalcore(char **calc, t_masterenv *menv)
{
	char	*word;
	char	*number;
	int		i;

	i = 0;
	while (calc[0][++i])
	{
		if (calc[0][i] == '=' && calc[0][i - 1] != '='
			&& calc[0][i - 1] != '!' && calc[0][i + 1] != '=')
		{
			if (ft_createwn(&word, &number, calc, i))
				return (1);
			ft_addvar(menv->internal_var, setvar(word, number));
			free(word);
			free(number);
		}
		if (calc[0][i] == '<' || calc[0][i] == '>'
			|| (calc[0][i] == '=' && calc[0][i + 1] == '=')
			|| calc[0][i] == '!')
			return (ft_calcomparator(calc, i));
	}
	return (0);
}

int		ft_ulticalc(char **calc, t_masterenv *menv)
{
	int				hmm;

	if (ft_checkcalc(calc))
		return (1);
	if (calc[0][0] == '=' || calc[0][0] == '<'
		|| calc[0][0] == '>' || calc[0][0] == '!')
	{
		ft_printfd(2, "pas d'operateur au debut wsh\n");
		return (1);
	}
	hmm = ft_findultioperator(menv, calc);
	if (hmm == -1)
		return (1);
	if (hmm)
		return (ft_ulticalcore(calc, menv));
	else
	{
		if (ft_resultor(calc))
			return (1);
	}
	return (0);
}
