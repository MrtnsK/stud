/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufgetor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:17:13 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/15 13:57:26 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_bufator(char **buf, char *sbuff)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (1 + ft_strlen(buf[0])))))
		return (1);
	ft_strcpy(tmp, buf[0]);
	free(buf[0]);
	if (!(buf[0] = (char*)malloc(sizeof(char)
		* (ft_strlen(sbuff) + ft_strlen(tmp) + 1))))
		return (1);
	ft_strcpy(buf[0], tmp);
	ft_strcat(buf[0], sbuff);
	free(tmp);
	return (0);
}

int	ft_addnewline(char **buf)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(buf[0]) + 1))))
		return (1);
	ft_strcpy(tmp, buf[0]);
	free(buf[0]);
	if (!(buf[0] = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + 2))))
		return (1);
	ft_strcpy(buf[0], tmp);
	free(tmp);
	ft_strcat(buf[0], "\n");
	return (0);
}

int	ft_unfinishedollar(int *cpt, int *i)
{
	*cpt = 0;
	*i += 1;
	while (g_ultib[*i])
	{
		if (g_ultib[*i] == '(')
			*cpt += 1;
		if (g_ultib[*i] == ')')
			*cpt -= 1;
		if (g_ultib[*i] == ')' && g_ultib[*i + 1] == ')'
			&& g_ultib[*i + 2] != ')' && (*cpt - 1) == 0)
		{
			*cpt -= 1;
			break ;
		}
		*i += 1;
	}
	if (*cpt < 0)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: parse error near ')'\n");
		return (1);
	}
	return (0);
}

int	ft_unfinishedlauncher(t_stockap *pac, t_keymaster *lock
	, t_masterenv *menv)
{
	if (lock->heremode == 0)
		return (ft_newgetbuf(&g_ultib, lock, pac, menv));
	else
		return (ft_hereshlag(pac, lock, menv));
}

int	ft_unfinished(t_stockap *pac, t_keymaster *lock, t_masterenv *menv)
{
	int i;
	int cpt;

	i = -1;
	cpt = 0;
	while (g_ultib[++i])
	{
		i = ft_unfinishedcore(i, cpt, lock);
		if (i == -10)
			return (1);
		if (i == -20)
			return (ft_unfinishedlauncher(pac, lock, menv));
	}
	lock->heremode = 1;
	lock->herelvl = 0;
	lock->rechist = NULL;
	return (ft_unfinishedlauncher(pac, lock, menv));
}
