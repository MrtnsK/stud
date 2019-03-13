/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:29:59 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/13 10:11:07 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_function(t_ms *m)
{
	(void)m;
	ft_lst_clear(&m->var);
	ft_strdel(&m->cur_dir);
	ft_strdel(&m->cmd);
	exit(0);
}

char	*is_this_home(char *may)
{
	int		i;
	int		len;

	len = ft_strlen(may);
	i = 0;
	while (may[i] && may[i] != '~')
		i++;
	if (may[i] == '~' && may[i + 1] == '\0')
		return ("/Users/kemartin");
	return (may);
}

void	pwd_fun(t_ms *m)
{
	write(1, m->cur_dir, ft_strlen(m->cur_dir));
	write(1, "\n", 1);
}

void	gohome(t_ms *m)
{
	char	*dir;

	if(!(dir = ft_strdup("/Users/kemartin")))
		return ;
	chdir(dir);
	if (m->cur_dir)
		free(m->cur_dir);
	if (!(m->cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
		return ;
	if (!(m->cur_dir = getcwd(dir, PATH_MAX)))
		return ;
	if (dir)
		free(dir);
}

void	quote_case(char *str)
{
	int		i;

	i = 1;
	while (str[i + 1])
		ft_putchar(str[i++]);
}
