/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:38:51 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/14 19:45:46 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fcntl.h"
#include <stdio.h>


int     main(int c, char **v)
{
    char    *line;
    int     fd;
    int     i;
    int     out;

    if (c >= 2)
    {
        i = 0;
        if (!(fd = open(v[1], O_RDONLY)))
           return (0);
        line = NULL;
        out = get_next_line(fd, &line);
		ft_putendl(line);
//		printf ("\ni = %d; line = %s", i, line);
		printf("\nOUT ::::::::::: %d\n", out);
        while (out > 0)
        {
            i++;
  //          printf ("\ni = %d; line = %s", i, line);
            out = get_next_line(fd, &line);
			ft_putendl(line);
            printf("\nOUT ::::::::::: %d\n", out);
        }
        free(line);
    }
    return (0);
}

/*
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
*/
