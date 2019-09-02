/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agreg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:04:32 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 07:46:39 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_strstri(char *haystack, char *needle)
{
	int i;

	i = 0;
	if (!(ft_strlen(needle)))
		return (1);
	while (*haystack)
	{
		if (*haystack == needle[0])
		{
			while (haystack[i] == needle[i])
			{
				if (needle[i + 1] == 0)
					return (1);
				i++;
			}
		}
		haystack++;
	}
	return (0);
}

int		ft_checkagreg(t_masterenv *menv, int a)
{
	if (ft_strstri(menv->cgv[a], ">&") || ft_strstri(menv->cgv[a], "<&"))
		return (a);
	return (0);
}

int		ft_checkfd(char *str)
{
	int		i;

	i = -1;
	if (ft_strcmp(str, "-") == 0)
		return (1);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int		ft_recupfd(t_masterenv *menv, int j)
{
	int		fd;
	int		ind;
	char	*tmp;

	if (ft_strstr(menv->cgv[j], "<&"))
		fd = 0;
	else if (ft_strstr(menv->cgv[j], ">&") && ft_checkfd(menv->cgv[j + 1]))
		fd = 1;
	if (ft_strlen(menv->cgv[j]) > 2)
	{
		if (fd)
			ind = ft_strchri(menv->cgv[j], '>');
		else
			ind = ft_strchri(menv->cgv[j], '<');
		tmp = ft_strsub(menv->cgv[j], 0, ind);
		fd = ft_atoi(tmp);
		free(tmp);
	}
	return (fd);
}

int		ft_checkfderror(int fd)
{
	int dp;

	if (fd < 0)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: ");
		ft_printfd(2, "file descriptor out of range: Bad file descriptor\n");
		return (1);
	}
	else if (fd > MAX_FD)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: %d: Bad file descriptor\n", fd);
		return (1);
	}
	if ((dp = dup(fd)) == -1)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: %d: Bad file descriptor\n", fd);
		return (1);
	}
	close(dp);
	return (0);
}
