/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:15:21 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/26 17:35:31 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_img_setup(t_mlx *mlx)
{
	int		bpp;
	int		size_l;
	int		endian;

	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &bpp, &size_l, &endian);
}
