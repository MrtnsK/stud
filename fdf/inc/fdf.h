/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:44:57 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/26 17:23:20 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "stdlib.h"

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			width;
	int			height;
	void		*img;
	int			*data;
}				t_mlx;

t_mlx			*ft_mlx_setup(int width, int height);
void			ft_img_setup(t_mlx *mlx);
void			ft_fill_pxl(t_mlx *mlx,int x, int y, int color);

#endif
