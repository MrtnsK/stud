/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:07:09 by kemartin          #+#    #+#             */
/*   Updated: 2018/11/12 19:46:37 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		check_e(int fd, char **line)
{
	if (fd < 0 || line == NULL)
		return (-1);
	return (0);
}

char	*ft_read(int fd, t_list *node)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	node->content = "";
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		node->content = ft_strjoin(node->content, buff);
	}
	return (node->content);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*node;
	int				i;
	char			*tmp;

	tmp = NULL;
	if (check_e(fd, line) == -1)
		return (-1);
	printf("ici\n");
	if (ft_lstfind(node, (void*)fd) == NULL)
		ft_lstnew(ft_read(fd, node), fd);
	printf("ici\n");
	tmp = ft_strcpy(tmp, node->content);
	printf("ici\n");
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (i > 0)
	{
		*line = ft_strsub(tmp, 0, i);
		node->content = &node->content[i + 1];
	}
	return (0);
}
