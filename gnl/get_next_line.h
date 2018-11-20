/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:20:06 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/20 15:17:13 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct		s_file
{
	int				fd;
	char			*buf;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
