/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_var_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:07:53 by fdikilu           #+#    #+#             */
/*   Updated: 2019/07/24 20:20:52 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	**realloc_tab(int resize, int len)
{
	char	**new_tab;

	if (resize == 0)
	{
		if (!(new_tab = (char **)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
		new_tab[len] = 0;
	}
	else if (resize == 1)
	{
		if (!(new_tab = (char **)(malloc(sizeof(char *) * (len + 2)))))
			return (NULL);
		new_tab[len + 1] = 0;
	}
	else
	{
		if (!(new_tab = (char **)(malloc(sizeof(char *) * (len)))))
			return (NULL);
		new_tab[len - 1] = 0;
	}
	return (new_tab);
}

static int	fill_tab(char **old_tab, char **new_tab, int settab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (old_tab[i])
	{
		if (old_tab[i][0] != '\0')
		{
			if (!(new_tab[j] = ft_strdup(old_tab[i])))
			{
				ft_tabfree(new_tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i < settab)
		new_tab[i] = "insert here";
	return (1);
}

char		**ft_reset_tab(char **old_tab, int resize)
{
	int		len;
	char	**new_tab;

	len = 0;
	while (old_tab[len])
		len++;
	if (!(new_tab = realloc_tab(resize, len)))
		return (NULL);
	if (!fill_tab(old_tab, new_tab, len + resize))
		return (NULL);
	return (new_tab);
}

char		*ft_findvar(char *intern_var, char *name)
{
	int		len;
	char	*var;
	char	*tmp;

	if (!intern_var || !name)
		return (NULL);
	if (intern_var[0] != name[0])
		return (NULL);
	len = ft_strlen(name);
	if (!(var = ft_strnew(len + 1)))
		return (NULL);
	ft_strcpy(var, name);
	var[len] = '=';
	tmp = ft_strstr(intern_var, var);
	free(var);
	return (tmp);
}

void		ft_tabfree(char **free_tab)
{
	int		i;

	i = 0;
	if (!free_tab)
		return ;
	while (free_tab[i])
	{
		free(free_tab[i]);
		free_tab[i] = NULL;
		i++;
	}
	free(free_tab);
	free_tab = NULL;
}
