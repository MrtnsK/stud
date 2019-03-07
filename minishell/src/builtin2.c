/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:51:32 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/07 14:03:31 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*lst_env(char *var, t_ms *m)
{
	t_var	*af;

	if (!(af = m->var))
		return (NULL);
	while (af && af->name && af->content && ft_strcmp(var, af->name))
		af = af->next;
	if (af && af->name && af->content && !ft_strcmp(var, af->name))
	{
		free(var);
		return (af->content);
	}
	free(var);
	return ("");
}

char	*env_find(char *str, char **env, t_ms *m)
{
	int		i;
	int		j;
	char	*var;

	if (str[0] == '$' && str[1])
	{
		if (!(var = (char*)malloc(sizeof(char) * ft_strlen(str))))
			return (NULL);
		i = 1;
		j = 0;
		while (str[i])
			var[j++] = str[i++];
		var[j] = '\0';
		j = 0;
		i = ft_strlen(var);
		while (env[j] && ft_strncmp(var, env[j], i))
			j++;
		if (env[j] && !ft_strncmp(var, env[j], i))
		{
			free(var);
			return (env[j] + i + 1);
		}
		else if (!env[j])
			return (lst_env(var, m));
	}
	return (str);
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
