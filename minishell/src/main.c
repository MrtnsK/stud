/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:25:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/20 13:36:21 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_prompt(t_ms *m)
{
	if (!ft_strncmp("/Users/kemartin/", m->cur_dir, 16))
	{
		ft_putstr("~/");
		ft_putstr(ft_strsub(ft_strdup(m->cur_dir), 16, ft_strlen(m->cur_dir) - 16));
	}
	else	
		ft_putstr(m->cur_dir);
	write (1, " ", 1);
	write(1, "\033[95m$> ", ft_strlen("\033[95m$> "));
	write(1, "\033[0m", ft_strlen("\033[0m"));
}

int		main(/*int ac, char **av, char **env*/void)
{
	t_ms	*m;

	if (!(m = (t_ms*)malloc(sizeof(t_ms))))
		return (0);
	if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
		return (0);
	if (!(m->cur_dir = getcwd(m->cur_dir, PATH_MAX)))
		return (ft_putstr_int("== getcwd error ==", 1));
	while (1)
	{
		show_prompt(m);
		get_cmd(m);
		exe_cmd(m);
		//free(m);
	}
	return (0);
}
