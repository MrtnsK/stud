/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:53 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/11 19:12:20 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_tutorial(t_stc *stc)
{
	mlx_string_put(stc->mlx->ptr, stc->mlx->win,
	stc->mlx->width - 300, 25, 0xFFFFFF, "        How to?");
	mlx_string_put(stc->mlx->ptr, stc->mlx->win,
	stc->mlx->width - 300, 50, 0xFFFFFF, "ESC              quit");
	mlx_string_put(stc->mlx->ptr, stc->mlx->win,
	stc->mlx->width - 300, 75, 0xFFFFFF, "R                reset");
	mlx_string_put(stc->mlx->ptr, stc->mlx->win,
	stc->mlx->width - 300, 100, 0xFFFFFF, "TAB              perspective");
	mlx_string_put(stc->mlx->ptr, stc->mlx->win,
	stc->mlx->width - 300, 125, 0xFFFFFF, "PAGE UP / DOWN   height");
	mlx_string_put(stc->mlx->ptr, stc->mlx->win,
	stc->mlx->width - 300, 150, 0xFFFFFF, "ARROWS           move");
	mlx_string_put(stc->mlx->ptr, stc->mlx->win,
	stc->mlx->width - 300, 175, 0xFFFFFF, "HOME / END       zoom");
	mlx_string_put(stc->mlx->ptr, stc->mlx->win,
	stc->mlx->width - 300, 200, 0xFFFFFF, "NUMBERS          colors");
}

void ft_reset(t_stc *stc)
{
	stc->mlx->zoom = 0;
	stc->mlx->panel_choice = 0;
}

int ft_key(int key, t_stc *stc)
{
	if (key == 53)
		exit(0);
	ft_bzero(stc->mlx->str, stc->mlx->width * stc->mlx->height * sizeof(int));
	ft_fractal(stc);
	mlx_put_image_to_window(stc->mlx->ptr, stc->mlx->win, stc->mlx->img, 0, 0);
	ft_tutorial(stc);
	return (0);
}
