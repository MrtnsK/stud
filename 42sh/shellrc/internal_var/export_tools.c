/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:34:12 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/17 14:09:01 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_error_flag(char *opt)
{
	int		i;

	i = 1;
	if (opt[0] == '-')
	{
		if (!opt[1])
			return (2);
		else
		{
			if (opt[1] == '-' && !opt[2])
				return (-1);
			else if (opt[1] == '-' && opt[2])
				return (1);
			while (opt[i] && opt[i] == 'p')
				i++;
		}
		if (opt[i])
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		check_error_arg(char *opt)
{
	int i;

	i = -1;
	if (ft_isdigit(opt[0]) || opt[0] == '=')
		return (1);
	while (opt[++i])
	{
		if (opt[i] == '=')
			return (0);
		if (!ft_isalnum(opt[i]) && opt[i] != '_')
			return (1);
	}
	return (0);
}

void	print_error(int ret, char *opt)
{
	if (ret == 2)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: export: ");
		ft_printfd(2, "%s: no a valid identifier\n", opt);
	}
	else if (ret == 1)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: export: invalid option\n");
		ft_printfd(2, "usage: export [name[=value] ...] or export -p\n");
	}
}
