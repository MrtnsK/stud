/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:38:51 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/12 19:01:54 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fcntl.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*str;
	int		n;

	(void)ac;
	n = 0;
	fd = open(av[1], O_RDONLY);
	while (n < ft_atoi(av[2]))
	{
		get_next_line(fd, &str);
		ft_putendl(str);
		ft_strdel(&str);
		n++;
	}
	close(fd);
	return (0);
}
