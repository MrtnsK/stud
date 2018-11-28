/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/11/28 20:19:07 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		usage_e(int ac)
{
	if (ac == 2)
		return (0);
	else
	ft_putendl("usage : ./fdf <your_map>");
	return (1);
}

void	printmap(int **map)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	t_coord	*coord;
	int		fd;
	int		**map;

	if (usage_e(ac) == 1)
		return (0);
	if (!(mlx = ft_mlx_setup(1200, 800)))
		return (0);
	ft_img_setup(mlx);
	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		return (0);
	coord->x1 = 200;
	coord->y1 = 50;
	coord->x2 = 500;
	coord->y2 = 400;
	fd = open(av[1], O_RDONLY);
	map = NULL;
	if (ft_parse_file(fd, map) == 1)
		return (0);
	printmap(map);
	ft_line(mlx, coord, 0xFFFF00);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_key_hook(mlx->win, &ft_key, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
