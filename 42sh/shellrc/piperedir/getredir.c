/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getredir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:15:23 by apsaint-          #+#    #+#             */
/*   Updated: 2019/06/20 09:47:29 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_checkredirin(t_masterenv *menv, int a)
{
	int		i;
	int		size;

	i = ft_strchri(menv->cgv[a], '<');
	size = ft_strlen(menv->cgv[a]);
	if (ft_strstr(menv->cgv[a], "<<"))
		return (a);
	if (ft_strcmp(menv->cgv[a], "<") == 0)
		return (a);
	if (size > 1 && i == (size - 1))
		return (a);
	return (0);
}

int		ft_checkperm(t_masterenv *menv, int i, int type)
{
	struct stat	st;
	int			file_fd;

	if (stat(menv->cgv[i + 1], &st) != -1 && !(st.st_mode & S_IRUSR))
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: %s: Permission Denied\n",
		menv->cgv[i + 1]);
		return (i + 1);
	}
	if (type)
	{
		if ((file_fd = open(menv->cgv[i + 1], O_RDWR | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR)) == -1)
			return (1);
	}
	else
	{
		if ((file_fd = open(menv->cgv[i + 1], O_RDWR | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR)) == -1)
			return (1);
	}
	close(file_fd);
	return (0);
}

char	*ft_protectheredoc(t_masterenv *menv, char *str)
{
	char	*name;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (menv->stock[0][++i])
	{
		if (ft_strcmp(str, menv->stock[0][i]) == -61)
		{
			while (menv->stock[0][i][++j] != '=')
				;
			name = ft_strsub(menv->stock[0][i], j + 1,
			ft_strlen(menv->stock[0][i]));
			j = 0;
			break ;
		}
	}
	if (j)
		return (NULL);
	return (name);
}

void	ft_findslash(char *name, int j)
{
	while (--j > 0)
	{
		if (name[j] == '/')
		{
			name[j + 1] = 0;
			break ;
		}
	}
}

char	*ft_getheredoc(void)
{
	char *name;

	if (!(name = (char*)malloc(sizeof(char)
		* (ft_strlen(g_lock.pathfile) + 1))))
		return (NULL);
	ft_strcpy(name, g_lock.pathfile);
	return (name);
}
