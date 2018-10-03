/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:20:58 by kemartin          #+#    #+#             */
/*   Updated: 2018/09/17 16:04:29 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# define BUF_SIZE 4096

# include <unistd.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_putchar_e(char c);
void	ft_putstr(char *str);
void	ft_putstr_e(char *str);

#endif
