/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:19 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/20 12:59:39 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_function(char *dir, t_ms *m)
{
	if (opendir(dir))
		chdir(dir);
	if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
		return ;
	if (!(m->cur_dir = getcwd(dir, PATH_MAX)))
		return ;
}

void	exit_function(t_ms *m)
{
	ft_putstr("== sortie \"exit\" ==\n");
	(void)m;
	//free(m);
	exit(0);
}
