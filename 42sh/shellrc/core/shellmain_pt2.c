/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellmain_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:56:27 by apsaint-          #+#    #+#             */
/*   Updated: 2019/06/23 16:44:52 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			init_term(void)
{
	int		ret;
	char	*term_type;

	term_type = getenv("TERM");
	if (term_type == NULL)
	{
		ft_printfd(2, "TERM must be set (see 'env').\n");
		return (-1);
	}
	ret = tgetent(NULL, term_type);
	if (ret == -1)
	{
		ft_printfd(2, "Could not access to the termcap database..\n");
		return (-1);
	}
	else if (ret == 0)
	{
		ft_printfd(2, "'%s' is not defined in termcap database.\n", term_type);
		return (-1);
	}
	return (0);
}

void		ft_inicap(t_stockap *pac)
{
	if ((!(pac->nbcol = tgetnum("co")))
		|| (!(pac->nbline = tgetnum("li")))
		|| (!(pac->cl_cap = tgetstr("cl", NULL)))
		|| (!(pac->us_cap = tgetstr("us", NULL)))
		|| (!(pac->me_cap = tgetstr("me", NULL)))
		|| (!(pac->mb_cap = tgetstr("mb", NULL)))
		|| (!(pac->md_cap = tgetstr("md", NULL)))
		|| (!(pac->cm_cap = tgetstr("cm", NULL)))
		|| (!(pac->left_cap = tgetstr("le", NULL)))
		|| (!(pac->right_cap = tgetstr("nd", NULL)))
		|| (!(pac->ec_cap = tgetstr("ec", NULL)))
		|| (!(pac->ti_cap = tgetstr("ti", NULL)))
		|| (!(pac->up_cap = tgetstr("up", NULL)))
		|| (!(pac->down_cap = tgetstr("do", NULL)))
		|| (!(pac->dl_cap = tgetstr("dl", NULL)))
		|| (!(pac->savecurs_cap = tgetstr("sc", NULL)))
		|| (!(pac->backurs_cap = tgetstr("rc", NULL)))
		|| (!(pac->rv_cap = tgetstr("mr", NULL)))
		|| (!(pac->cd_cap = tgetstr("cd", NULL))))
	{
		ft_printfd(2, "\e[93mobsolete termcap database\n\e[90mRIP\e[0m\n");
		exit(1);
	}
}
