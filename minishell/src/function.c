/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:11:19 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/20 18:46:01 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_function(char *dir, t_ms *m)
{
	if (opendir(dir))
	{
		chdir(dir);
		if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
			return ;
		if (!(m->cur_dir = getcwd(dir, PATH_MAX)))
			return ;
	}
}

void	exit_function(t_ms *m)
{
	ft_putstr("== sortie \"exit\" ==\n");
	(void)m;
	// free(m);
	exit(0);
}

void	ctrlc(int sign)
{
	char	*dir;

	if (sign == SIGINT)
	{
		ft_putchar('\n');
		if (!(dir = (char*)malloc(sizeof(char) * PATH_MAX)))
			return ;
		if (!(dir = getcwd(dir, PATH_MAX)))
			return ;
		if (!ft_strncmp("/Users/kemartin/", dir, 16))
		{
			write(1, "\033[33m\033[100m", 11);
			ft_putstr("~/");
			ft_putstr(ft_strsub(ft_strdup(dir), 16, ft_strlen(dir) - 16));
		}
		else
			ft_putstr(dir);
		write(1, " ", 1);
		write(1, "\033[95m$> ", ft_strlen("\033[95m$> "));
		write(1, "\033[0m", ft_strlen("\033[0m"));
		signal(SIGINT, ctrlc);
	}
}
