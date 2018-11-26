/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:48:54 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/26 17:34:56 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*ft_mlx_setup(int width, int height)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (0);
	mlx->ptr = mlx_init();
	mlx->width = width;
	mlx->height = height;
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "fdf");
	return (mlx);
}
