/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:07:09 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/20 18:10:00 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file			*ft_newfile(int fd)
{
	t_file		*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->next = NULL;
	file->fd = fd;
	file->buf = NULL;
	return (file);
}

t_file			*ft_findfd(t_file *file, int fd)
{
	if (file)
	{
		if (file->fd == fd)
			return (file);
		else if (file->next)
			return (ft_findfd(file->next, fd));
		file->next = ft_newfile(fd);
		return (file->next);
	}
	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file = ft_newfile(fd);
	return (file);
}

int				ft_clearfile(t_file **file, int fd, int ret)
{
	t_file		*last;
	t_file		*tofree;

	last = *file;
	while (last->fd != fd && last->next && last->next->fd != fd)
		last = last->next;
	tofree = last->fd == fd ? last : last->next;
	if (last->fd == fd)
		*file = tofree->next;
	else
		last->next = tofree->next;
	ft_strdel(&(tofree->buf));
	free(tofree);
	return (ret);
}

int				ft_treat(char **buf, char **line)
{
	char	*tmp;
	int		l_line;

	l_line = 0;
	while ((*buf)[l_line] && (*buf)[l_line] != '\n')
		l_line++;
	if (((*buf)[l_line]) == '\n')
	{
		*line = ft_strsub(*buf, 0, l_line);
		tmp = *buf;
		*buf = ft_strdup(&(*buf)[l_line + 1]);
		free(tmp);
		!(*buf)[0] ? ft_strdel(buf) : 0;
	}
	else if (!((*buf)[l_line]))
	{
		*line = ft_strdup(*buf);
		ft_strdel(buf);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*current;
	char			*tmp;
	char			*buffer;
	int				r;

	if (fd < 0 || !line || (!file && !(file = ft_newfile(fd))))
		return (-1);
	current = ft_findfd(file, fd);
	if ((!(current->buf) && !(current->buf = ft_strnew(0))) ||
		!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!(r = 0) && !ft_strchr(current->buf, 10) && !ft_strchr(buffer, 10)
		&& (r = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[r] = 0;
		tmp = current->buf;
		current->buf = ft_strjoin(current->buf, buffer);
		free(tmp);
	}
	free(buffer);
	if (r < 0 || (r == 0 && (!(current->buf) || !(current->buf)[0])))
		return (ft_clearfile(&file, fd, r < 0 ? -1 : 0));
	return (ft_treat(&(current->buf), line));
}
