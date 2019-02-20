/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/20 13:10:42 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd(t_ms *m)
{
	if (get_next_line(0, &m->cmd) == -1)
		exit (ft_putstr_int("=== GNL error ===\n", 1));
}

void	exe_cmd(t_ms *m)
{
	// if (!ft_strcmp("/bin/", ft_strsub(cmd, 0, 5)))
	// 	bin_cmd(cmd);
	if (!ft_strcmp(m->cmd, "exit"))
		exit_function(m);
	if (!ft_strcmp("cd ", ft_strsub(m->cmd, 0, 3)) && ft_strlen(m->cmd) > 3)
		cd_function(ft_strsub(m->cmd, 3, ft_strlen(m->cmd) - 1), m);
}
