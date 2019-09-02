/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_alias.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:20:33 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/15 22:47:53 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_lst_chr(t_alias *als, char **toshw)
{
	t_alias	*show;
	int		on;

	show = als;
	on = 0;
	while (show)
	{
		if (show->alias && show->name && !ft_strcmp(show->alias, toshw[0]))
		{
			ft_printf("%s=\'%s\'\n", show->alias, show->name);
			on = 1;
		}
		show = show->next;
	}
	if (on == 0)
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: alias: %s: not found\n"
		, toshw[0]);
		return (1);
	}
	return (0);
}

char	**parse_alias_following(char *str, char **tb, int i, int j)
{
	i++;
	tb[0] = ft_strndup(str, i - 1);
	if (str[i - 1] == '=')
	{
		j = i;
		while (str[j])
			j++;
		tb[1] = ft_strsub(str, i, str[j] == ' '\
		&& str[j + 1] == '\0' ? j - i + 1 : j - i);
		tb[2] = NULL;
	}
	else
		tb[1] = NULL;
	return (tb);
}

char	**parse_alias(char *str)
{
	char	**tb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tb = (char**)malloc(sizeof(char*) * 3)))
		return (NULL);
	if (str[0] == '=')
	{
		while (str[i] && str[i] != ' ')
			i++;
		tb[0] = ft_strndup(str, i);
		tb[1] = NULL;
		return (tb);
	}
	while (str[i] && str[i] != '=' && str[i] != ' ')
		i++;
	if (i > (int)ft_strlen(str) || str[i] == ' ')
		return (tb);
	return (parse_alias_following(str, tb, i, j));
}

int		push_alias(t_masterenv *menv, t_alias *tmp, char **tabal)
{
	while (tmp && tmp->alias && ft_strcmp(tmp->alias, tabal[0]))
		tmp = tmp->next;
	if (tmp && tmp->alias && !ft_strcmp(tmp->alias, tabal[0]))
	{
		ft_replace_cmd(&tmp->name, tabal[1]);
		return (0);
	}
	else
	{
		ft_lst_push_back(&menv->als, tabal[0], tabal[1]);
		return (0);
	}
	return (1);
}

int		add_alias(t_masterenv *menv, char **opt)
{
	char		**tabal;
	t_alias		*tmp;
	int			ret;
	int			cgc;
	int			j;

	tmp = menv->als;
	cgc = ft_tablen(opt);
	j = 1;
	ret = 0;
	while (j <= cgc && opt[j])
	{
		tabal = parse_alias(opt[j]);
		if (tabal[0] && tabal[1])
			ret += push_alias(menv, tmp, tabal);
		else if (tabal[0] && !tabal[1])
			ret += ft_lst_chr(menv->als, &tabal[0]);
		ft_freetabc(tabal);
		j++;
	}
	if (!opt[1])
		ft_lst_show(menv->als);
	return (ret ? 1 : 0);
}
