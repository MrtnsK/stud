/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion_norme.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:44:12 by fdikilu           #+#    #+#             */
/*   Updated: 2019/07/29 16:30:54 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		increment_k(int l, int k)
{
	while (l--)
		k++;
	k++;
	return (k);
}

int		free_norme(char **str, char **sstr, int ret)
{
	ft_strdel(str);
	ft_strdel(sstr);
	return (ret);
}

int		do_recursiv(t_masterenv *menv, char **cmd, char *var)
{
	int		ret;
	char	*tmp;

	if (!(tmp = ft_strdup(&var[2])))
		return (0);
	free(var);
	ret = one_dollar_exp(menv, &tmp);
	if (!(var = ft_strnew(ft_strlen(tmp) + 2)))
		return (0);
	ft_strcpy(var, "${");
	ft_strcat(var, tmp);
	if (ret)
		if (!change_cmd(cmd, var))
		{
			free(var);
			return (0);
		}
	free(var);
	free(tmp);
	return (ret);
}

int		check_digit(char *var)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (var[0] == '#')
	{
		i++;
		j++;
	}
	while (var[i + 1] && (var[i] != ':' && var[i] != '%' && var[i] != '#')
		&& ft_isdigit(var[i]))
		i++;
	if (var[i] == '}' || var[i] == ':' || var[i] == '%' || var[i] == '#')
	{
		if (var[i] == ':' && var[i + 1] == '=')
			return (1);
		else if (var[i] != '}' && j == 1)
			return (1);
		else
			return (0);
	}
	if (ft_isalpha(var[i]) && ft_isdigit(var[j]))
		return (1);
	return (0);
}
