/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colon_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:23:08 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/18 22:44:08 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*minus(char *var, int pos, char *value)
{
	int		i;
	int		start;
	char	*final_form;

	if (value)
		return (ft_strdup(value));
	i = 0;
	start = pos;
	while (var[pos + 1])
	{
		pos++;
		i++;
	}
	if (i == 0 || !(final_form = ft_strnew(i)))
		return (NULL);
	ft_strncpy(final_form, &var[start], i);
	return (final_form);
}

static char	*egal(t_masterenv *menv, char *var, int pos, char *value)
{
	int		len;
	char	*name;
	char	*final_form;

	if (value)
		return (ft_strdup(value));
	final_form = minus(var, pos, value);
	len = ft_strlen(var);
	if (len == 0 || !(name = ft_strnew(len - (len - pos) - 2)))
		return (NULL);
	ft_strncpy(name, &var[2], len - (len - pos) - 2);
	name[ft_strlen(name) - 1] = '\0';
	name[ft_strlen(name) - 1] = '\0';
	if (final_form)
		ft_addvar(menv->internal_var, setvar(name, final_form));
	else
		ft_addvar(menv->internal_var, setvar(name, ""));
	free(name);
	return (final_form);
}

static int	question_mark(char *var, int pos, char *value, char **final_form)
{
	int		i;
	char	*tmp;

	if (value)
	{
		*final_form = ft_strdup(value);
		return (1);
	}
	i = 0;
	while (var[i] && var[i] != ':')
		i++;
	if (!(tmp = ft_strndup(&var[2], i - 2)))
		return (-1);
	*final_form = minus(var, pos, value);
	if (*final_form)
		ft_printfd(2, "\e[93mMastershell\e[0m: %s: %s\n", tmp, *final_form);
	else
	{
		ft_printfd(2, "\e[93mMastershell\e[0m: %s: ", tmp);
		ft_printfd(2, "parameter null or not set\n");
	}
	if (*final_form)
		free(*final_form);
	free(tmp);
	return (-1);
}

static char	*plus(char *var, int pos, char *value)
{
	int		i;
	int		start;
	char	*final_form;

	if (!value)
		return (value);
	i = 0;
	start = pos;
	while (var[pos + 1])
	{
		pos++;
		i++;
	}
	if (i == 0 || !(final_form = ft_strnew(i)))
		return (NULL);
	ft_strncpy(final_form, &var[start], i);
	return (final_form);
}

int			colon_exp(t_masterenv *menv, char *var, int pos, char **final_form)
{
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	tmp = get_var(menv, var, pos);
	if (var[pos + 1] == '-')
		*final_form = minus(var, pos + 2, tmp);
	else if (var[pos + 1] == '=')
		*final_form = egal(menv, var, pos + 2, tmp);
	else if (var[pos + 1] == '?')
	{
		if ((ret = question_mark(var, pos + 2, tmp, final_form)) == -1)
		{
			free(tmp);
			return (-1);
		}
	}
	else if (var[pos + 1] == '+')
		*final_form = plus(var, pos + 2, tmp);
	free(tmp);
	return (1);
}
