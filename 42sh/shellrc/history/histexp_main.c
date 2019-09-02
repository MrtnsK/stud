/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histexp_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 02:01:39 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/18 18:18:11 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		is_event(char **cmd, int pos)
{
	if (cmd[0][pos] == '!')
	{
		if (cmd[0][pos + 1] >= '0' && cmd[0][pos] <= '9')
			return (1);
		if (cmd[0][pos + 1] >= 'a' && cmd[0][pos] <= 'z')
			return (1);
		if (cmd[0][pos + 1] >= 'A' && cmd[0][pos] <= 'Z')
			return (1);
	}
	return (0);
}

int		okforhist(void)
{
	int		pos;

	pos = ft_strpos(g_ultib, "!", 0);
	if (g_ultib[pos] == '!')
	{
		if (g_ultib[pos + 1] == '!')
			return (1);
		if (g_ultib[pos + 1] == '-')
			return (1);
		if (g_ultib[pos + 1] >= '0' && g_ultib[pos] <= '9')
			return (1);
		if (g_ultib[pos + 1] >= 'a' && g_ultib[pos] <= 'z')
			return (1);
		if (g_ultib[pos + 1] >= 'A' && g_ultib[pos] <= 'Z')
			return (1);
	}
	if (hist_quotes() || ft_strstr(g_ultib, "fc -s")
	|| !ft_strcmp(g_ultib, "fc"))
		return (1);
	return (0);
}

int		no_event(char **cmd, int i)
{
	char	*tmp;
	int		j;

	j = i;
	if (cmd[0])
	{
		while (cmd[0][j] && cmd[0][j] != ' ')
			j++;
		tmp = ft_strsub(cmd[0], i, j - i);
		ft_printf("\e[93mMastershell\e[0m: %s: event not found \n", tmp);
		free(tmp);
	}
	return (1);
}

int		in_quote(char **cmd, int pos)
{
	char	q;
	int		i;
	int		j;

	i = 0;
	q = '\0';
	while (cmd[0][i] && cmd[0][i] != '\'' && cmd[0][i] != '\"')
		i++;
	if (cmd[0][i] == '\'' || cmd[0][i] == '\"')
		q = cmd[0][i];
	j = i + 1;
	if (q)
	{
		while (cmd[0][j] && cmd[0][j] != q)
			j++;
		if (cmd[0][j] == q)
			if (pos > i && pos < j)
				return (1);
	}
	return (0);
}

int		exp_main(char **cmd, t_keymaster *lock)
{
	int		i;
	int		ret;
	int		pos;

	i = 0;
	ret = 0;
	if (lock->hist.count <= 0)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: it seems like there's \
something wrong with historic\n");
		return (-1);
	}
	while (ft_strchr(cmd[0], '!') && i <= 10)
	{
		pos = ft_strpos(cmd[0], "!", 0);
		if (cmd[0] && !in_quote(cmd, pos) && cmd[0][pos + 1] != '='
		&& cmd[0][pos + 1] != ' ' && cmd[0][pos + 1] != '\t'
		&& cmd[0][pos + 1] != '\0' && ret == 0)
			ret += ft_expensions(cmd, lock);
		i++;
	}
	return (ret);
}
