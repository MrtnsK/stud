/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:07:09 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/14 20:06:03 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_file	*ft_newfile(int fd)
{
	t_file	*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->next = NULL;
	file->fd = fd;
	file->r = -1;
	file->buf = NULL;
	return (file);
}

t_file	*ft_getfile(t_file **file, int fd)
{
	if (*file)
	{
		if ((*file)->fd == fd)
			return (*file);
		else if ((*file)->next)
			return (ft_getfile(&((*file)->next), fd));
		else
		{
			(*file)->next = ft_newfile(fd);
			return ((*file)->next);
		}
	}
	else
	{
		*file = ft_newfile(fd);
		return (*file);
	}
}

char	ft_treatbuffer(char **line, t_file *f)
{
	int		i;

	i = 0;
	while ((f->buf)[i] && (f->buf)[i] != '\n')
		i++;
	if ((f->buf)[i] == '\n')
	{
		*line = ft_strjoin(*line, ft_strsub(f->buf, 0, i));
		f->buf += i + 1;
		f->r = ft_strlen(f->buf);
		return ('\n');
	}
	if ((f->buf)[i] == '\0' && f->r < BUFF_SIZE && f->r > 0)
	{
		*line = ft_strjoin(*line, f->buf);
		f->buf = NULL;
		return ('F');
	}
	// SAVOIR SI R == BUFFSIZE && FIN DU FICHIER
	//  if ((f->buf)[i] == '\0' && f->r == BUFF_SIZE && f->r > 0)
	// {
	// 	*line = ft_strjoin(*line, f->buf);
	// 	f->buf = NULL;
	// 	return (0);
	// }
	*line = ft_strjoin(*line, f->buf);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				r;
	static t_file	*file = NULL;
	t_file			*f;
	int				output;

	if (fd < 0 || !line || !(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!file)
		if (!(file = ft_newfile(fd)))
			return (-1);
	output = 0;
	f = ft_getfile(&file, fd);
	if (f->buf)
		if ((output = ft_treatbuffer(line, f)) > 0)
			return (1);
	if (!(f->buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((r = read(fd, f->buf, BUFF_SIZE)))
	{
		if (r < 0)
			return (-1);
		(f->buf)[r] = '\0';
		f->r = r;
		if ((output = ft_treatbuffer(line, f)) > 1)
			return (1);
	}
	return (0);
}
