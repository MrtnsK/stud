/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouverror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:37:15 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 15:10:02 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		ft_trunkator(t_calctools *stock, int i)
{
	int j;

	if (ft_isdigit(stock->stuff[i][0]))
	{
		j = -1;
		while (stock->stuff[i][++j])
			;
		if (j > 15)
		{
			stock->stuff[i][15] = 0;
			ft_printfd(2, "\e[93mMastershell\e[0m: number ");
			ft_printfd(2, "truncated after 15 digits : %s\n", stock->stuff[i]);
		}
	}
}

int			noegal(char **calc)
{
	int i;

	i = -1;
	while (calc[0][++i])
	{
		if (i > 0 && calc[0][i] == '=' && calc[0][i - 1] != '='
			&& calc[0][i - 1] != '<' && calc[0][i - 1] != '>'
			&& calc[0][i - 1] != '!' && calc[0][i + 1] != '=')
		{
			ft_printfd(2, "flemme de crash pour un truc inutile\n");
			free(calc[0]);
			return (1);
		}
		if (i > 0 && calc[0][i] == '*' && (calc[0][i - 1] == '*'
			|| calc[0][i + 1] == '*'))
		{
			ft_printfd(2, "flemme de crash pour un truc inutile\n");
			free(calc[0]);
			return (1);
		}
	}
	return (0);
}

int			ft_goodcara(char **calc)
{
	int i;

	i = -1;
	while (calc[0][++i])
	{
		if (!ft_isalnum(calc[0][i]) && calc[0][i] != '*' && calc[0][i] != '-'
			&& calc[0][i] != '+' && calc[0][i] != '/' && calc[0][i] != '%'
			&& !ft_isspace(calc[0][i])
			&& calc[0][i] != '&' && calc[0][i] != '|' && calc[0][i] != '='
			&& calc[0][i] != '!' && calc[0][i] != '<' && calc[0][i] != '>')
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: bad cara %c\n", calc[0][i]);
			free(calc[0]);
			return (1);
		}
	}
	return (noegal(calc));
}
