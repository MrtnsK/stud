/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:56:38 by agissing          #+#    #+#             */
/*   Updated: 2019/02/07 17:50:12 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	acces_error(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(ft_title(name, 0), 2);
	ft_putendl_fd(": Permission denied", 2);
}

void	files_err(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": No such file or directory", 2);
}
