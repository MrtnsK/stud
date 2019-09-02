/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:43:59 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/13 10:44:00 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
