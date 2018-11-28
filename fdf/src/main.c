/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:23:42 by flklein           #+#    #+#             */
/*   Updated: 2018/11/28 16:02:00 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	t_coord	*coord;
	int		fd;
	int		**map;

	if (!(mlx = ft_mlx_setup(1200, 800)))
		return (0);
	ft_img_setup(mlx);
	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		return (0);
	coord->x1 = 50;
	coord->y1 = 50;
	coord->x2 = 500;
	coord->y2 = 250;
	fd = open(av[1], O_RDONLY);
	map = ft_parse_file(fd);
	ft_line(mlx, coord, 0xFFFF00);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_key_hook(mlx->win, &ft_key, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}