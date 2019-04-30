/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:29:59 by kemartin          #+#    #+#             */
/*   Updated: 2019/04/30 14:43:42 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_function(t_ms *m)
{
	ft_lst_clear(&m->var);
	ft_strdel(&m->cmd);
	exit(0);
}

char	*is_this_home(char *may)
{
	int		i;
	int		len;

	len = ft_strlen(may);
	i = 0;
	while (may[i] && may[i] != '~')
		i++;
	if (may[i] == '~' && may[i + 1] == '\0')
		return ("/Users/kemartin");
	return (may);
}

void	gohome(t_ms *m, char **env)
{
	t_var *af;

	af = m->var;
	if (!ft_strcmp(m->cmd, "cd ~") || !ft_strcmp(m->cmd, "cd"))
		chdir("/Users/kemartin");
	else if (!ft_strcmp(m->cmd, "cd -"))
		cd_function(env_find("$OLDPWD", env, m), m, env);
}

void	quote_case(char *str)
{
	int		i;

	i = 1;
	while (str[i + 1])
		ft_putchar(str[i++]);
}

int		spc_cnt(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		if (str[i++] == ' ')
			j++;
	return (j);
}
