/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:20:06 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/12 19:14:04 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	t_list
{
	void		*content;
	int			content_size;
	t_list		*next;
}				s_list;

int				get_next_line(const int fd, char **line);

#endif
