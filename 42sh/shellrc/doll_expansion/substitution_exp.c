/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_exp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 07:50:06 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/16 15:42:25 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	check_special_var(char *var)
{
	if (var[2] == '?')
		return (1);
	else if (var[2] == '$')
		return (1);
	else if (var[2] == '-')
		return (1);
	else if (var[2] == '_')
		return (1);
	else if (var[2] == '!')
		return (1);
	return (0);
}

static int	check_char(char p, char c)
{
	int		i;
	char	cmp[22];

	i = 0;
	ft_bzero(cmp, 22);
	ft_strcpy(cmp, "$ /><|;'\".,()\n\t{}&^~\\");
	while (cmp[i])
		if (cmp[i++] == c)
			return (1);
	if (c == '+' || c == '-' || c == '=' || c == '?')
	{
		if (p != ':')
			return (1);
	}
	if (c == '%' && p == '{')
		return (1);
	return (0);
}

int			ft_check_error(char *var)
{
	int		i;
	int		len;

	i = 2;
	len = ft_strlen(var);
	if (len == 3)
		return (1);
	if (len == 4 && check_special_var(var))
		return (0);
	while (var[i + 1] && var[i] != ':' && var[i] != '#' && var[i] != '%')
	{
		if (check_char(var[i - 1], var[i]))
			return (1);
		i++;
	}
	if (var[i] == ':' && var[i + 1] != '-' && var[i + 1] != '+' \
		&& var[i + 1] != '?' && var[i + 1] != '=')
		return (1);
	else if (var[i] == ':' && var[i - 1] == '{')
		return (1);
	if (check_digit(&var[2]))
		return (1);
	return (0);
}

int			ft_substitution(t_masterenv *menv, char *var, char **final_form)
{
	int		i;
	int		ret;

	i = 0;
	while (var[i] != ':' && var[i] != '#' && var[i] != '%' && var[i] != '}')
		i++;
	if (var[i] == ':')
	{
		if ((ret = colon_exp(menv, var, i, final_form)) == -1)
			return (-1);
	}
	else if (var[i] == '#')
		*final_form = sharp_exp(menv, var, i);
	else if (var[i] == '%')
		*final_form = percent_exp(menv, var, i);
	else if (var[i] == '}')
		*final_form = get_var(menv, var, i);
	if (!(*final_form))
		return (0);
	return (1);
}
