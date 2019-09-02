/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_exp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:16:49 by fdikilu           #+#    #+#             */
/*   Updated: 2019/07/29 08:39:45 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*get_strtocut(char *var, int pos)
{
	char	*tocut;

	if (var[pos + 1] == '%')
		pos++;
	pos++;
	if (var[pos] == '}')
		return (NULL);
	if (!(tocut = ft_strnew(ft_strlen(var) - pos - 1)))
		return (NULL);
	ft_strncpy(tocut, &var[pos], ft_strlen(var) - pos - 1);
	return (tocut);
}

static int	cut_percent(char *value, char *tocut, char **final_form)
{
	int		l_tocut;
	int		l_val;

	l_tocut = ft_strlen(tocut) - 1;
	l_val = ft_strlen(value) - 1;
	while (l_val >= 0 && l_tocut >= 0 && (value[l_val] == tocut[l_tocut]))
	{
		l_tocut--;
		l_val--;
	}
	if (l_tocut >= 0)
	{
		*final_form = ft_strdup(value);
		ft_strdel(&value);
		return (0);
	}
	if (!(*final_form = ft_strnew(l_val + 1)))
	{
		ft_strdel(&value);
		return (-1);
	}
	ft_strncpy(*final_form, value, l_val + 1);
	ft_strdel(&value);
	return (1);
}

static int	cut_2percent(char *value, char *tocut, char **final_form)
{
	int		ret;

	ret = cut_percent(value, tocut, final_form);
	if (ret == 0)
		return (0);
	else if (ret == -1)
		return (-1);
	else
		return (cut_2percent(*final_form, tocut, final_form));
}

char		*percent_exp(t_masterenv *menv, char *var, int pos)
{
	char	*value;
	char	*tocut;
	char	*final_form;

	if (!(value = get_var(menv, var, pos)))
		return (NULL);
	if (var[pos + 1] == '}' || (var[pos + 1] == '%' && var[pos + 2] == '}'))
		return (value);
	if (!(tocut = get_strtocut(var, pos)))
		return (value);
	if (var[pos + 1] == '%')
		cut_2percent(value, tocut, &final_form);
	else
		cut_percent(value, tocut, &final_form);
	ft_strdel(&tocut);
	return (final_form);
}
