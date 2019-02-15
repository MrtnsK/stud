/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:09:32 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/08 20:04:52 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	illegal_opt(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-lRGartf] [file ...]", 2);
	exit(1);
}

void	options(char *str, t_struct *tab)
{
	int			i;

	i = 0;
	while (str[++i])
		if (str[i] == 'l')
			tab->opt |= OPT_L;
		else if (str[i] == 'R')
			tab->opt |= OPT_UR;
		else if (str[i] == 'a')
			tab->opt |= OPT_A;
		else if (str[i] == 'r')
			tab->opt |= OPT_LR;
		else if (str[i] == 't')
			tab->opt |= OPT_T;
		else if (str[i] == 'G')
			tab->opt |= OPT_G;
		else if (str[i] == 'f')
			tab->opt |= OPT_F + OPT_A;
		else if (str[i] == 'A')
			tab->opt |= OPT_UA;
		else
			illegal_opt(str[i]);
	(tab->opt & OPT_LR && tab->opt & OPT_F) ? tab->opt &= ~OPT_LR : 0;
}
