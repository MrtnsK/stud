/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:51:34 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/17 14:52:29 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_set(char **internal_var)
{
	int		i;

	if (!internal_var)
		return (0);
	i = 0;
	while (internal_var[i])
	{
		if (internal_var[i][0])
			ft_printf("%s\n", internal_var[i]);
		i++;
	}
	return (0);
}

static int	varclr(char **internal_var, char *name)
{
	int		i;

	i = 0;
	while (internal_var[i])
	{
		if (ft_findvar(internal_var[i], name))
		{
			ft_strclr(internal_var[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_err_arg_unset(char *arg)
{
	int		i;

	i = -1;
	if (ft_isdigit(arg[0]) || arg[0] == '=')
		return (1);
	while (arg[++i])
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (1);
	return (0);
}

int			ft_unset(char ***internal_var, char **cgv, int ret)
{
	char	*name;
	char	**new_internvar;

	name = *cgv;
	if (!name)
		return (ret);
	if (check_err_arg_unset(name))
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: unset: `%s'", name);
		ft_printfd(2, ": not a valid identifier\n", name);
		ret = 1;
	}
	else
	{
		if (!varclr(*internal_var, name))
			return (1);
		if (!(new_internvar = ft_reset_tab(*internal_var, -1)))
			return (1);
		ft_tabfree(*internal_var);
		*internal_var = new_internvar;
	}
	return (ft_unset(internal_var, &cgv[1], ret));
}
