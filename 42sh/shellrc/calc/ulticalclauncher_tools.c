/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulticalclauncher_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:07:11 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/17 15:07:13 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_putanswer(char **string, double *number)
{
	number[0] = ft_atof(string[0]);
}

void	freepreulticalc(char ***tablor, double **ftabor, int **indexor)
{
	int i;

	i = -1;
	while (indexor[0][++i] != -42)
		free(tablor[0][i]);
	free(tablor[0]);
	free(indexor[0]);
	free(ftabor[0]);
}

int		ft_lifechecker(char *totest)
{
	int	i;
	int	yup;

	if (!totest)
		return (0);
	i = -1;
	yup = 0;
	while (totest[++i])
		if (!ft_isspace(totest[i]))
			yup = 1;
	return (yup);
}
