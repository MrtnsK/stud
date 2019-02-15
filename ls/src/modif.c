/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:47:31 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/15 15:00:45 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	cut_time_opt(char *str, t_buf *x)
{
	int		i;
	int		j;
	char	*date;

	if (!(date = (char *)ft_memalloc(sizeof(char) * 17)))
		return ;
	i = 4;
	j = 0;
	while (i < 16 && str[i])
		date[j++] = str[i++];
	date[j] = '\0';
	leading(13, date, x);
	free(date);
}

void	cut_time_year(char *str, t_buf *x)
{
	int		i;
	int		j;
	char	*date;

	if (!(date = (char *)ft_memalloc(sizeof(char) * 17)))
		return ;
	i = 4;
	j = 0;
	while (i < 11 && str[i])
		date[j++] = str[i++];
	i += 8;
	while (i < 24 && str[i])
		date[j++] = str[i++];
	date[j] = '\0';
	leading(13, date, x);
	free(date);
}

char	*ft_title(char *title, int t)
{
	int		i;

	if (t)
		return (title);
	while (ft_strchr(title, '/'))
		title = ft_strchr(title, '/') + 1;
	i = ft_strlen(title);
	return (title);
}

void	ft_reverse(t_lst **lst, char opt, t_lst *tmp2, t_lst *tmp3)
{
	t_lst	*tmp1;
	t_lst	*trie;

	tmp1 = (*lst);
	if (opt & OPT_F || !(trie = ft_memalloc(sizeof(t_lst))))
		return ;
	while (tmp1 && (tmp3 = tmp1))
	{
		lstcpy(trie, tmp1);
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (opt & OPT_T && trie->stat.st_mtime == tmp2->stat.st_mtime
				&& ft_strcmp(tmp2->name, trie->name) > 0)
				lstcpy(trie, (tmp3 = tmp2));
			else if (opt & OPT_T ? trie->stat.st_mtime > tmp2->stat.st_mtime
					: ft_strcmp(tmp2->name, trie->name) > 0)
				lstcpy(trie, (tmp3 = tmp2));
			tmp2 = tmp2->next;
		}
		lstcpy(tmp3, tmp1);
		lstcpy(tmp1, trie);
		tmp1 = tmp1->next;
	}
	free(trie);
}
