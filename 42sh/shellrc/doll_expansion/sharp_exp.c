/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:51:37 by fdikilu           #+#    #+#             */
/*   Updated: 2019/07/29 15:27:08 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*nb_char_exp(char **env, char *var)
{
	int		i;
	char	*name;
	char	*tmp;
	char	*final_form;

	if (var[3] == '}')
		return (ft_strdup("0"));
	i = 3;
	while (var[i + 1])
		i++;
	if (!(name = ft_strnew(i - 3 + 1)))
		return (NULL);
	ft_strncpy(name, &var[3], i - 3);
	name[i - 3] = '=';
	i = 0;
	while (env[i])
		if ((tmp = cmp_getvalue(env[i++], name)))
		{
			final_form = ft_itoa(ft_strlen(tmp));
			free(tmp);
			free(name);
			return (final_form);
		}
	free(name);
	return (ft_strdup("0"));
}

static char	*get_strtocut(char *var, int pos)
{
	char	*tocut;

	if (var[pos + 1] == '#')
		pos++;
	pos++;
	if (var[pos] == '}')
		return (NULL);
	if (!(tocut = ft_strnew(ft_strlen(var) - pos - 1)))
		return (NULL);
	ft_strncpy(tocut, &var[pos], ft_strlen(var) - pos - 1);
	return (tocut);
}

static int	cut_sharp(char *value, char *tocut, char **final_form)
{
	int		i;
	int		len;

	i = 0;
	while (value[i] && tocut[i] && (value[i] == tocut[i]))
		i++;
	if (tocut[i] != '\0')
	{
		*final_form = ft_strdup(value);
		ft_strdel(&value);
		return (0);
	}
	len = ft_strlen(value) - ft_strlen(tocut);
	if (!(*final_form = ft_strnew(len)))
	{
		ft_strdel(&value);
		return (-1);
	}
	ft_strncpy(*final_form, &value[ft_strlen(tocut)], len);
	ft_strdel(&value);
	return (1);
}

static int	cut_2sharp(char *value, char *tocut, char **final_form)
{
	int		ret;

	ret = cut_sharp(value, tocut, final_form);
	if (ret == 0)
		return (0);
	else if (ret == -1)
		return (-1);
	else
		return (cut_2sharp(*final_form, tocut, final_form));
}

char		*sharp_exp(t_masterenv *menv, char *var, int pos)
{
	char	*nb;
	char	*value;
	char	*tocut;
	char	*final_form;

	if (pos == 2)
	{
		if (ft_strcmp((nb = nb_char_exp(menv->stock[0], var)), "0") != 0)
			return (nb);
		else
		{
			free(nb);
			return (nb_char_exp(*menv->internal_var, var));
		}
	}
	if (!(value = get_var(menv, var, pos)))
		return (NULL);
	if (!(tocut = get_strtocut(var, pos)))
		return (value);
	if (var[pos + 1] == '#')
		cut_2sharp(value, tocut, &final_form);
	else
		cut_sharp(value, tocut, &final_form);
	free(tocut);
	return (final_form);
}
