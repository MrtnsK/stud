/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histdoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:35:31 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 10:16:33 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_histpath(char *path, char *histdoc)
{
	char	*tmp;

	if (!(tmp = (char*)lt_add(malloc(sizeof(char) * (ft_strlen(path)
	+ ft_strlen(histdoc) + 2)))))
		exit(1);
	ft_strcpy(tmp, path);
	ft_strcat(tmp, "/");
	ft_strcat(tmp, histdoc);
	free(histdoc);
	return (tmp);
}

void	ft_gethistfile(t_keymaster *lock, t_masterenv *menv)
{
	int		i;
	char	*lvl;
	char	*tmp;
	char	*test;
	char	*here;

	i = 0;
	lvl = getshlvl(menv);
	if (!(tmp = getcwd(NULL, 0)))
		exit(1);
	test = ft_strjoin(".histdoc", lvl);
	here = ft_strjoin(".masterheredoc", lvl);
	lock->hist.histfile = ft_histpath(tmp, test);
	lock->pathfile = ft_histpath(tmp, here);
	free(lvl);
	free(tmp);
}

int		ft_printfhisto(t_keymaster *lock)
{
	int i;

	i = -1;
	ft_printfd(0, "==============================================\n");
	while (++i < lock->hist.count)
		ft_printfd(0, "%d [%s]\n", i, lock->hist.cmdhist[i]);
	return (0);
}

int		ft_addtohist(char *ultib, t_keymaster *lock)
{
	int		fd;
	char	file_name[255];
	char	*tmp;

	fd = -1;
	ft_strcpy(file_name, lock->hist.histfile);
	if (okforhist())
		return (0);
	if ((fd = open(file_name, O_RDWR | O_CREAT | O_APPEND | O_NOFOLLOW,
		S_IRUSR | S_IWUSR)) == -1)
		return (1);
	tmp = ft_fakedbs(ultib);
	if (ft_strcmp(tmp, "\n") != 0 && tmp != NULL)
		ft_printfd(fd, "%s%c", tmp, 7);
	free(tmp);
	close(fd);
	return (0);
}

int		ft_read_hist(char **str, t_keymaster *lock, int fd_file)
{
	char		*buf;
	int			tot;
	int			b;

	b = 0;
	if ((fd_file = ft_openhist(lock)) == -1)
		return (1);
	if ((buf = (char *)lt_add(malloc(sizeof(char) * (BUFF_SIZE + 1)))) == NULL)
		return (1);
	ft_memset(buf, '\0', BUFF_SIZE);
	tot = hist_reader(buf, fd_file, str, b);
	close(fd_file);
	return (!tot ? 1 : 0);
}
