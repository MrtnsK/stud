/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fc_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:10:46 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/17 11:44:29 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	tab_to_str(char **cmd, char **splt, int word, int i)
{
	int		j;
	int		len;
	char	*tmp;

	len = 0;
	while (splt[i] && word++)
		len += ft_strlen(splt[i++]);
	if (!(tmp = (char*)malloc(sizeof(char) * (word + len + 1))))
		return ;
	i = 0;
	len = 0;
	while (splt[i])
	{
		j = 0;
		while (splt[i][j])
			tmp[len++] = splt[i][j++];
		tmp[len++] = ' ';
		i++;
	}
	tmp[len - 1] = '\0';
	ft_replace_cmd(cmd, tmp);
	ft_strdel(&tmp);
	ft_freetabc(splt);
}

char	*fc_chr(t_keymaster *lock, int i, char **cmd)
{
	int		e;
	int		nb;

	e = 0;
	while (cmd[i][e] && cmd[i][e] != ' ')
		e++;
	if (lock->hist.count > 0)
	{
		nb = lock->hist.count - 1;
		while (nb > 0 && ft_strncmp(lock->hist.cmdhist[nb], cmd[i], e))
			nb--;
		if (!ft_strncmp(lock->hist.cmdhist[nb], cmd[i], e))
			return (ft_strdup(lock->hist.cmdhist[nb]));
	}
	if (i == 3)
	{
		error_list();
		lock->hist.fc++;
	}
	else
		ft_printfd(2, "\e[93mMastershell\e[0m: fc: no command found\n");
	return (NULL);
}

char	*fcs_snr(char *find, char *replace, char *cmd)
{
	char	**splt;
	int		i;

	if (!cmd)
	{
		free(find);
		free(replace);
		return (NULL);
	}
	i = 0;
	splt = ft_strsplit(cmd, ' ');
	while (splt[i])
	{
		if (!ft_strcmp(find, splt[i]))
			ft_replace_cmd(&splt[i], replace);
		i++;
	}
	free(find);
	free(replace);
	tab_to_str(&cmd, splt, 0, 0);
	return (cmd);
}

char	*fc_s(t_keymaster *lock, int i, char **cmd)
{
	char	*exec;
	int		e;
	char	*tb[2];

	e = 0;
	exec = NULL;
	if (!ft_strchr(cmd[2], '='))
		return (fc_chr(lock, i, cmd));
	else if (ft_strchr(cmd[2], '='))
	{
		while (cmd[2][e] && cmd[2][e] != '=')
			e++;
		if (e == 0 || e == (int)ft_strlen(cmd[2]) - 1)
			return (NULL);
		tb[0] = ft_strsub(cmd[2], 0, e);
		tb[1] = ft_strsub(cmd[2], e + 1, ft_strlen(cmd[2]) - e);
		exec = fcs_snr(tb[0], tb[1], cmd[3] ? fc_chr(lock, 3, cmd)\
		: ft_strdup(lock->hist.cmdhist[lock->hist.count - 1]));
	}
	return (exec);
}

int		ft_fcinfc(char *exec)
{
	char	**opt;
	int		ret;

	ret = -1;
	if (!(opt = ft_strsplit(exec, ' ')))
		return (1);
	if (!ft_strcmp(opt[0], "fc"))
	{
		if (opt[1] && (!ft_strcmp(opt[1], "-l") || !ft_strcmp(opt[1], "-ln")
		|| !ft_strcmp(opt[1], "-lr") || !ft_strcmp(opt[1], "-e")))
			ret = 0;
		else
			ret = 1;
	}
	else
		ret = 0;
	if (ret)
		ft_printfd(2
		, "\e[93mMastershell\e[0m: Protect fc against infinite loop\n");
	ft_freetabc(opt);
	return (ret);
}
