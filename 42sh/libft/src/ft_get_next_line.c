/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:17:08 by pharatyk          #+#    #+#             */
/*   Updated: 2018/12/16 10:46:48 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmaster.h"

static int		ft_outer(char **memory, char **line, int fd)
{
	char	*out;
	int		len;

	len = -1;
	while (memory[fd][++len] != '\n' && memory[fd][len])
		;
	if (!memory[fd][len])
	{
		if (!(*line = ft_strdup(memory[fd])))
			return (-1);
		ft_strdel(&memory[fd]);
	}
	else if (memory[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(memory[fd], 0, len)))
			return (-1);
		if (!(out = ft_strdup(memory[fd] + len + 1)))
			return (-1);
		free(memory[fd]);
		memory[fd] = out;
		if (!memory[fd][0])
			ft_strdel(&memory[fd]);
	}
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static char	*memory[FOPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*out;
	int			bufsize;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	while ((bufsize = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bufsize] = 0;
		if (!memory[fd])
		{
			if (!(memory[fd] = ft_strnew(1)))
				return (-1);
		}
		if (!(out = ft_strjoin(memory[fd], buf)))
			return (-1);
		free(memory[fd]);
		memory[fd] = out;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bufsize <= 0 && (!memory[fd] || !memory[fd][0]))
		return (bufsize);
	return (ft_outer(memory, line, fd));
}
