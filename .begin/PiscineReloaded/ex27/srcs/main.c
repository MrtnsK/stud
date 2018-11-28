/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:24:36 by kemartin          #+#    #+#             */
/*   Updated: 2018/09/17 17:14:42 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	read_files(char *str)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		ret;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fd);
}

int		main(int ac, char **av)
{
	if (ac > 2)
	{
		ft_putstr_e("Too many arguments.\n");
		return (0);
	}
	else if (ac < 2)
	{
		ft_putstr_e("File name missing.\n");
		return (0);
	}
	else
		read_files(av[1]);
	return (0);
}
