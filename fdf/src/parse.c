/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:36:06 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/28 18:20:16 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		map_valid(char *line)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '-' || str[i] != '+')
		&& str[i + 1] <= '0' && strp[i + 1] <= '9')
			return (0);
		i++;
	}
}

void	fill_map(char *line, int **map)
{
	int		i;
	int		j;
	i = ft_strlen(line);
	if (!((*map) = (int *)malloc(sizeof(int) * i)))
		return (0);
	i = 0;
	j = 0;
	while(line[i])
	{
		*map[j] = ft_atoi(line[i]);
		j++;
		i++;
	}
}

int		**ft_parse_file(int fd)
{
	char	*line;
	int		r;
	int		**map;
	int		i;

	if (fd < 0)
	while (get_next_line(fd, &line) > 0)
	{
		if (map_valide(line) == 1)
			return (ft_putstr_fd("map is not valide\n", 2));
		fill_map(line, &(map[i]));
		i++;
	}
	return (map);
}
