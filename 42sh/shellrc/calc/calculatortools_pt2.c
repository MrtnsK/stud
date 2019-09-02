/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculatortools_pt2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:05:51 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:05:56 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_checkcalc(char **calc)
{
	int	i;
	int	paren;

	paren = 0;
	i = -1;
	while (calc[0][++i])
	{
		if (calc[0][i] == '(')
			paren++;
		if (calc[0][i] == ')')
			paren--;
	}
	if (!paren)
		return (0);
	ft_printfd(2, "parenthesis error : only calculs accept parenthesis\n");
	return (1);
}
