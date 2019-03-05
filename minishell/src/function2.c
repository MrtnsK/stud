/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:51:32 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/05 17:38:12 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_fun(t_ms *m)
{
	write(1, m->cur_dir, ft_strlen(m->cur_dir));
	write(1, "\n", 1);
}

void	gohome(t_ms *m)
{
	char	*dir;

	dir = ft_strdup("/Users/kemartin");
	chdir(dir);
	free(m->cur_dir);
	if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
		return ;
	if (!(m->cur_dir = getcwd(dir, PATH_MAX)))
		return ;
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
		write(1, "\033[33m\033[100m", 11);
		if (!ft_strncmp("/Users/kemartin/", dir, 16))
		{
			ft_putstr("~/");
			ft_putstr(ft_strsub(ft_strdup(dir), 16, ft_strlen(dir) - 16));
		}
		else
			ft_putstr(dir);
		write(1, "\033[0m ", ft_strlen("\033[0m "));
		write(1, "\033[95m$> ", ft_strlen("\033[95m$> "));
		write(1, "\033[0m", ft_strlen("\033[0m"));
		signal(SIGINT, ctrlc);
	}
}

char	*is_this_home(char *may)
{
	int		i;
	int		len;

	len = ft_strlen(may);
	i = 0;
	while (may[i] && may[i] != '~')
		i++;
	if ((may[i - 1] == ' ' && may[i - 1] == '\t') && may[i] == '~' && i + 1 == len)
		return ("/Users/kemartin");
	return (may);
}
