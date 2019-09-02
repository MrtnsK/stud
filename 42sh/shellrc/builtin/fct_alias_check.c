/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_alias_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:58:53 by kemartin          #+#    #+#             */
/*   Updated: 2019/08/18 18:23:21 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_strpos(char *haystack, char *needle, int start)
{
	int i;
	int j;

	i = start;
	if (needle[0] == '\0')
		return (0);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && needle[j])
			j++;
		if (!needle[j])
			return (i);
		i++;
	}
	return (0);
}

int		last_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] == '\0' && str[i - 1] == ' ')
		return (0);
	return (1);
}

char	*cycle_alias(char *first, char *str, t_alias *als)
{
	t_alias		*tmp;
	char		*actual;
	int			i;

	i = 0;
	tmp = als;
	actual = ft_strdup(str);
	while (i <= 100)
	{
		if (!tmp)
			tmp = als;
		if (tmp->alias && !ft_strcmp(actual, tmp->alias))
		{
			if (!ft_strcmp(first, tmp->name))
				break ;
			ft_replace_cmd(&actual, tmp->name);
		}
		i++;
		tmp = tmp->next;
	}
	return (actual);
}

int		is_apb(char c)
{
	if (!c || c == '&' || c == '|' || c == ';' || c == '<' || c == '>'
	|| ft_isspace(c) || c == '\0')
		return (0);
	return (1);
}

int		can_we_alias(char *str, int deb, int fin)
{
	if (fin <= (int)ft_strlen(str))
	{
		if (is_apb(str[deb > 0 ? deb - 1 : ft_strlen(str)]))
			return (0);
		if (is_apb(str[fin + 1]))
			return (0);
		return (1);
	}
	return (0);
}
