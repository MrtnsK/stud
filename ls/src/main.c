/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/15 15:06:28 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_file(char *name)
{
	DIR			*fd;

	if ((fd = opendir(name)) && closedir(fd))
		return (0);
	if (errno == ENOTDIR)
		return (1);
	return (-1);
}

void	ft_param_push_front(t_param **param, char *name)
{
	t_param		*start;

	start = ft_create_param(name);
	if (*param)
		start->next = (*param);
	(*param) = start;
}

int		main(int ac, char **av)
{
	int			i;
	t_param		*tmp;
	t_struct	tab;

	i = 1;
	tab.opt = 0;
	ft_bzero(&tab.bf, sizeof(t_buf));
	if (!(tab.names = (t_param **)ft_memalloc(sizeof(t_param *))))
		return (0);
	while (i < ac)
		if ((av[i][0] == '-' && av[i][1]) || (i++ && 0))
			options(av[i++], &tab);
	i = 1;
	while (i < ac)
		if ((av[i][0] == '-' && !av[i][1]) || av[i][0] != '-' || (i++ && 0))
			tab.opt & OPT_LR ? ft_param_push_front(tab.names, av[i++])
				: ft_param_push_back(tab.names, av[i++]);
	if (!(*tab.names))
		ft_param_push_back(tab.names, ".");
	tab.nb = 0;
	tmp = *tab.names;
	(tab.opt & OPT_UR) ? ls_rec(&tab, 0) : ls(&tab, 1);
	ft_free(tab.names);
	free(tab.names);
	return (0);
}
