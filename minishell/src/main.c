/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:25:52 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/19 20:09:11 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_prompt(void)
{
	write(1, "\033[95m$> ", ft_strlen("\033[95m$> "));
	write(1, "\033[0m", ft_strlen("\033[0m"));
}

void	get_cmd(char **cmd)
{
	int		r;
	char	buf;
	int		i;
	int		count;

	*cmd = ft_strnew(1);
	i = 0;
	count = 1;
	while ((r = read(0, &buf, B_SIZE)) && buf != '\n')
	{
		*(*cmd + i++) = buf;
		*cmd = ft_realloc(*cmd, count, count + 1);
		count++;
	}
	*(*cmd + i++) = '\0';
	if (!r)
		exit (ft_putstr_int("== sortie r = -1 ==\n", 1));
}

void	cd_function(char *dir, char *cur_dir)
{
	chdir(dir);
	if (!(cur_dir = getcwd(cur_dir, PATH_MAX)))
		return ;
	ft_putendl(cur_dir);
}

void	exe_cmd(char *cmd, char *cur_dir)
{
	// if (!ft_strcmp("/bin/", ft_strsub(cmd, 0, 5)))
	// 	bin_cmd(cmd);
	if (!ft_strcmp(cmd, "exit"))
		exit (ft_putstr_int("== sortie \"exit\" ==\n", 1));
	if (!ft_strcmp("cd", ft_strsub(cmd, 0, 2)))
		cd_function(ft_strsub(cmd, 2, ft_strlen(cmd)), cur_dir);
}

int		main(/*int ac, char **av, char **env*/void)
{
	char	*cmd;
	char	*cur_dir;

	if (!(cur_dir = (char*)malloc(sizeof(char) * PATH_MAX)))
		return (0);
	if (!(cur_dir = getcwd(cur_dir, PATH_MAX)))
		return (ft_putstr_int("== getcwd error ==", 1));
	ft_putendl(cur_dir);
	while (1)
	{
		show_prompt();
		get_cmd(&cmd);
		exe_cmd(cmd, cur_dir);
	}
	return (0);
}
