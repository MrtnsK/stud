/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_childs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:56:16 by agissing          #+#    #+#             */
/*   Updated: 2019/02/13 19:09:22 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_ok(char opt, char *name)
{
	return (opt & OPT_A || (opt & OPT_UA && (name[0] != '.'
		|| (name[1] && (name[1] != '.' || name[2])))) || name[0] != '.');
}

void	get_childs(t_param *p, char opt)
{
	DIR				*d;
	struct dirent	*dir;
	struct stat		buf;

	while (p)
	{
		lstat(p->name, &buf);
		if (!S_ISLNK(buf.st_mode) && (d = opendir(p->name)))
		{
			while ((dir = readdir(d)))
				if (is_ok(opt, dir->d_name))
					ft_lst_push_back(p->child, dir->d_name, p->name);
			closedir(d);
			p->ok = 2;
		}
		else if ((lstat(p->name, &buf) < 0 || errno == EACCES) && !(p->ok = 0))
			errno == EACCES ? acces_error(p->name) : files_err(p->name);
		else
			ft_lst_push_back(p->child, p->name, "");
		p = p->next;
	}
}
