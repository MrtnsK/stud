/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 00:07:49 by flklein           #+#    #+#             */
/*   Updated: 2018/11/29 20:45:05 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	mlx->data[x + mlx->width * y] = color;
}

void	ft_line(t_mlx *mlx, t_coord *coord, int color)
{
	int		dx;
	int		dy;
	int		e;

	e = coord->x2 - coord->x1;
	dx = e * 2;
	dy = (coord->y2 - coord->y1) * 2;
	while (coord->x1 <= coord->x2)
	{
		ft_fill_pixel(mlx, coord->x1, coord->y1, color);
		coord->x1++;
		if ((e -= dy) <= 0)
		{
			coord->y1++;
			e += dx;
		}
	}
}

void	draw_map(t_map	*map, t_coord *coord, t_mlx *mlx)
{
	int	x;
	int	y;
	int ratio1;
	int ratio2;

	x = 0;
	y = 0;
	ratio1 = 1200 / map->columns;
	ratio2 = 800 / map->lines;
	while (x < map->lines)
	{
		while(y < map->columns)
		{
			coord->x1 = x * ratio1;
			coord->y1 = y * ratio1;
			coord->x2 = (x + 1) *ratio2;
			coord->y2 = y * ratio2;
			ft_line(mlx, coord, 0xFFFFFF);
			coord->x1 = x * ratio1;
			coord->y1 = y * ratio1;
			coord->x2 = x * ratio2;
			coord->y2 = (y + 1) * ratio2;
			ft_line(mlx, coord, 0xFFFFFF);
			y++;
		}
		x++;
	}
}
