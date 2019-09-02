/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufgetortools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:17:31 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:48:04 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_dquote(int i, int cpt, t_keymaster *lock)
{
	while (g_ultib[++i])
	{
		if (g_ultib[i] == '"' && g_ultib[i - 1] != '\\')
			break ;
		if (g_ultib[i] == '$'
			&& g_ultib[i + 1] == '(' && g_ultib[i + 2] == '(')
		{
			if (ft_unfinishedollar(&cpt, &i))
				return (-10);
			else if (g_ultib[i] != ')' || g_ultib[i + 1] != ')' || cpt != 0)
			{
				if (ft_mathdquoteprompt(lock))
					return (-10);
				return (-20);
			}
		}
	}
	if (g_ultib[i] != '"' || g_ultib[i - 1] == '\\')
	{
		ft_addnewline(&g_ultib);
		if (ft_dquoteprompt(lock))
			return (-10);
		return (-20);
	}
	return (i);
}

static int	ft_quotept2(int i, int cpt, t_keymaster *lock)
{
	if (cpt < 0)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: parse error near ')'\n");
		return (-10);
	}
	if (g_ultib[i] != '\'' || g_ultib[i - 1] == '\\')
	{
		ft_addnewline(&g_ultib);
		if (ft_quoteprompt(lock))
			return (-10);
		return (-20);
	}
	return (i);
}

static int	ft_quote(int i, int cpt, t_keymaster *lock)
{
	while (g_ultib[++i])
	{
		if (g_ultib[i] == '\'' && g_ultib[i - 1] != '\\')
			break ;
		if (g_ultib[i] == '$' && g_ultib[i + 1] == '('
			&& g_ultib[i + 2] == '(')
		{
			if (ft_unfinishedollar(&cpt, &i))
				return (-10);
			else if (g_ultib[i] != ')' || g_ultib[i + 1] != ')'
				|| cpt != 0)
			{
				if (ft_mathquoteprompt(lock))
					return (-10);
				return (-20);
			}
		}
	}
	return (ft_quotept2(i, cpt, lock));
}

static int	ft_dollar(int i, int cpt, t_keymaster *lock)
{
	if (ft_unfinishedollar(&cpt, &i))
		return (-10);
	if (g_ultib[i - 1] == '\\' && !g_ultib[i])
	{
		g_ultib[i - 1] = 0;
		if (ft_simpleprompt(lock))
			return (1);
		return (-20);
	}
	if (g_ultib[i] != ')' || g_ultib[i + 1] != ')' || cpt != 0)
	{
		if (ft_mathprompt(lock))
			return (-10);
		return (-20);
	}
	return (i);
}

int			ft_unfinishedcore(int i, int cpt, t_keymaster *lock)
{
	if (g_ultib[i] == '"' && (i == 0 || g_ultib[i - 1] != '\\'))
	{
		if ((i = ft_dquote(i, cpt, lock)) == -10 || i == -20)
			return (i);
	}
	if (g_ultib[i] == '\'' && (i == 0 || g_ultib[i - 1] != '\\'))
	{
		if ((i = ft_quote(i, cpt, lock)) == -10 || i == -20)
			return (i);
	}
	if (g_ultib[i] == '$' && g_ultib[i + 1] == '(' && g_ultib[i + 2] == '(')
	{
		if ((i = ft_dollar(i, cpt, lock)) == -10 || i == -20)
			return (i);
	}
	return (ft_unfinishedcore_pt2(i, cpt, lock));
}
