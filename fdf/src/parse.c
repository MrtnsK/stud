/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:36:06 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/28 20:40:58 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_map(char **map)
{
	int		i;
	int		j;

	i = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_isdigit(map[i][j])
			&& map[i][j] != '-' && map[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		fill_map(char *line, int **map)
{
	int		i;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	i = ft_strlen(line);
	ft_strdel(&line);
	if (!(*map = (int *)malloc(sizeof(int) * (i + 1))))
		return (0);
// probleme de malloc actuellement du coup j'ai peut etre fais de la merde partout
	if (check_map(tmp) == 1)
		return (ft_putstr_int("map is not valide\n", 1));
	i = 0;
	while(tmp[i])
	{
		*(map[i]) = ft_atoi((const char *)tmp[i]);
		i++;
	}
	return (0);
}

int		ft_parse_file(int fd, int **map)
{
	char	*line;
	int		i;

	if (fd < 0)
		return (0);
	i = 0;
	map = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (fill_map(line, &(map[i])) == 1)
			return (1);
		i++;
	}
	return (0);
}
