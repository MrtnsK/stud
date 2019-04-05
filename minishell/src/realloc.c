/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:50:41 by kemartin          #+#    #+#             */
/*   Updated: 2019/04/05 16:21:23 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_path(char **arg)
{
	char	*tmp;
	char	*tmp2;

	if ((*arg) && (*arg)[0] == '~' && ((*arg)[1] == '/' || !(*arg)[1]))
	{
		if (!(*arg)[1])
		{
			ft_strdel(&(*arg));
			(*arg) = ft_strdup("/Users/kemartin/");
			return ;
		}
		if ((*arg)[1] && (*arg)[1] == '/')
		{
			tmp = "/Users/kemartin";
			tmp2 = (*arg);
			(*arg) = ft_strjoin(tmp, (*arg + 1));
			ft_strdel(&tmp2);
			return ;
		}
	}
}

void	ft_clear_dir(char **dir)
{
	char	*tmp;

	if ((*dir) && (*dir)[0] == '~' && ((*dir)[1] == '/' || !(*dir)[1]))
	{
		if (!(*dir)[1])
		{
			ft_strdel(&(*dir));
			(*dir) = ft_strdup("/Users/kemartin/");
			return ;
		}
		if ((*dir)[1] && (*dir)[1] == '/')
		{
			tmp = "/Users/kemartin";
			(*dir) = ft_strjoin(tmp, (*dir + 1));
			return ;
		}
	}
}

char	*reallocstr(char *str)
{
	char	*new;
	int		i;

	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '/';
	new[i + 1] = '\0';
	ft_memdel((void**)&str);
	return (new);
}

char	*arg_adjustment(char *path, char *str)
{
	int		i;
	int		j;
	char	*new;

	i = ft_strlen(path);
	j = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (path[i])
		new[j++] = path[i++];
	i = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

void	ft_freetab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
}
