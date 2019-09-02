/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_dollar_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:12:23 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/18 22:39:23 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_value_simple_dollar(t_masterenv *menv, char *name)
{
	int		i;
	int		len;

	i = -1;
	while (menv->internal_var[0][++i])
	{
		len = ft_strlen(menv->internal_var[0][i]) - ft_strlen(name);
		if (ft_strstr(menv->internal_var[0][i], name))
			return (ft_strsub(menv->internal_var[0][i], ft_strlen(name), len));
	}
	i = 0;
	while (menv->stock[0][++i])
	{
		len = ft_strlen(menv->stock[0][i]) - ft_strlen(name);
		if (ft_strstr(menv->stock[0][i], name))
			return (ft_strsub(menv->stock[0][i], ft_strlen(name), len));
	}
	return (ft_strnew(0));
}

int		do_digit_dollar(char **cmd, int start)
{
	char	*new_cmd;

	if ((*cmd)[start + 1] == '0')
	{
		if (!(new_cmd = ft_strnew(ft_strlen(*cmd) + 2)))
			return (0);
	}
	else
	{
		if (!(new_cmd = ft_strnew(ft_strlen(*cmd) - 2)))
			return (0);
	}
	ft_strncpy(new_cmd, *cmd, start);
	if ((*cmd)[start + 1] == '0')
		ft_strcat(new_cmd, "42sh");
	ft_strcat(new_cmd, &(*cmd)[start + 2]);
	free(*cmd);
	*cmd = new_cmd;
	return (1);
}
