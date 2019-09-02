/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellmain_pt5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 09:41:39 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/19 09:41:41 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	foundparserror(void)
{
	ft_printfd(2, "\e[93mMastershell\e[0m: parse error\n");
	return (-10);
}

int	findparserror_core(char **ultib, int i)
{
	int	test;

	test = 1;
	if ((ultib[0][i] == '&' && ultib[0][i + 1] != '&')
		|| ultib[0][i] == ';')
		test = 0;
	if (ultib[0][i + 1] == '|' || ultib[0][i + 1] == '&')
	{
		if ((ultib[0][i] == '|' && ultib[0][i + 1] != '|')
			|| (ultib[0][i] == '&' && ultib[0][i + 1] != '&'))
			return (foundparserror());
		i++;
		if (ultib[0][i + 1] == '|' || ultib[0][i + 1] == '&')
			return (foundparserror());
	}
	while (ultib[0][i + 1] && ft_isspace(ultib[0][i + 1]))
		i++;
	if (!ultib[0][i + 1] && !test)
		return (-20);
	if (!ultib[0][i + 1] && test)
		return (foundparserror());
	if (ultib[0][i + 1] == '&' || ultib[0][i + 1] == '|'
		|| ultib[0][i + 1] == ';')
		return (foundparserror());
	return (i);
}
