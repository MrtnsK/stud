/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 15:02:19 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/14 21:01:53 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	while_in_doexport(t_masterenv *menv, char *opt)
{
	int		j;
	char	*tmp;

	j = 0;
	while (menv->internal_var[0][j])
	{
		if (ft_findvar(menv->internal_var[0][j], opt))
		{
			if (!(tmp = ft_strdup(menv->internal_var[0][j])))
				return (0);
			ft_addvar(menv->stock, tmp);
		}
		j++;
	}
	return (1);
}

static void	do_export(t_masterenv *menv, char **opt)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (opt[++i])
	{
		j = 0;
		while (opt[i][j] && opt[i][j] != '=')
			j++;
		if (!opt[i][j])
		{
			if (!while_in_doexport(menv, opt[i]))
				return ;
		}
		else
		{
			if (!(tmp = ft_strdup(opt[i])))
				return ;
			ft_addvar(menv->stock, tmp);
			if (!(tmp = ft_strdup(opt[i])))
				return ;
			ft_addvar(menv->internal_var, tmp);
		}
	}
}

int			print_opt_p(t_masterenv *menv)
{
	int		i;
	int		j;

	i = 0;
	while (menv->stock[0][i])
	{
		j = 0;
		while (menv->internal_var[0][j])
		{
			if (!ft_strcmp(menv->stock[0][i], menv->internal_var[0][j]))
				ft_printfd(1, "export %s\n", menv->stock[0][i]);
			j++;
		}
		i++;
	}
	return (0);
}

static int	in_while_export(char *opt)
{
	int		ret;

	ret = check_error_flag(opt);
	if (ret == 1 || ret == 2)
	{
		print_error(ret, opt);
		return (-1);
	}
	else if (ret == -1)
		return (-2);
	return (0);
}

int			ft_export(t_masterenv *menv, char **opt)
{
	int		i;
	int		ret;

	i = -1;
	while (opt[++i] && opt[i][0] == '-')
		if ((ret = in_while_export(opt[i])) == -1)
			return (1);
		else if (ret == -2)
		{
			i++;
			break ;
		}
	if (((ret = i) || !ret) && !opt[i])
		return (print_opt_p(menv));
	while (opt[i])
	{
		if (check_error_arg(opt[i]))
		{
			print_error(2, opt[i]);
			return (1);
		}
		i++;
	}
	do_export(menv, &opt[ret]);
	return (0);
}
