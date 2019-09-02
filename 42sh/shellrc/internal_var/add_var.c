/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 09:09:58 by fdikilu           #+#    #+#             */
/*   Updated: 2019/07/24 20:07:45 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*setvar(char *name, char *value)
{
	int		len;
	char	*var;

	len = ft_strlen(name) + ft_strlen(value) + 1;
	if (!(var = ft_strnew(len)))
		return (NULL);
	len = ft_strlen(name);
	ft_strcpy(var, name);
	var[len] = '=';
	ft_strcpy(&var[len + 1], value);
	return (var);
}

static char	**insert_var(char **tab_var, char *name, char *value)
{
	int		i;
	char	**new_tab;

	i = 0;
	if (!(new_tab = ft_reset_tab(tab_var, 1)))
		return (tab_var);
	while (new_tab[i])
	{
		if (ft_strcmp(new_tab[i], "insert here") == 0)
		{
			if (!(new_tab[i] = setvar(name, value)))
			{
				new_tab[i] = 0;
				ft_tabfree(new_tab);
				return (tab_var);
			}
		}
		i++;
	}
	ft_tabfree(tab_var);
	return (new_tab);
}

static char	**addvar(char **tab_var, char *name, char *value)
{
	int		i;
	char	*tmp;

	if (!name || !value)
		return (tab_var);
	i = 0;
	if (!tab_var)
	{
		if (!(tab_var = (char **)(malloc(sizeof(char *)))))
			return (NULL);
		tab_var[0] = 0;
	}
	while (tab_var[i])
	{
		if (ft_findvar(tab_var[i], name))
		{
			if (!(tmp = setvar(name, value)))
				return (tab_var);
			free(tab_var[i]);
			tab_var[i] = tmp;
			return (tab_var);
		}
		i++;
	}
	return (insert_var(tab_var, name, value));
}

void		ft_addvar(char ***tab_var, char *cmd)
{
	int		i;
	int		j;
	char	*name;
	char	*value;

	i = 0;
	while (cmd[i] && cmd[i] != '=')
		i++;
	if (!(name = ft_strnew(i)))
		return ;
	i = -1;
	while (cmd[++i] && cmd[i] != '=')
		name[i] = cmd[i];
	i++;
	j = 0;
	if (!(value = ft_strnew(ft_strlen(cmd) - i)))
		return ;
	while (cmd[i])
		value[j++] = cmd[i++];
	*tab_var = addvar(*tab_var, name, value);
	free(cmd);
	free(name);
	free(value);
}
