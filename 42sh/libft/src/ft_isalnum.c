/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:02:48 by pharatyk          #+#    #+#             */
/*   Updated: 2018/11/09 12:02:49 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

int	ft_isalnum(int c)
{
	return ((ft_isdigit(c) || ft_isalpha(c)) ? 1 : 0);
}

int	ft_isalnumflt(int c)
{
	return ((ft_isdigit(c) || ft_isalpha(c) || c == '.') ? 1 : 0);
}
