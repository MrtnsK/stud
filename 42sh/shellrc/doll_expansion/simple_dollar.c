/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:08:36 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/18 22:41:53 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	is_done(char *cmd, int nope)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$' && nope)
			nope--;
		else if (cmd[i] == '$' && !nope)
			return (0);
		i++;
	}
	return (1);
}

static int	is_badchar(char c)
{
	if (c == '%' || c == '@' || c == ':' || c == 34 || c == 39 || c == '\\'
		|| c == '~' || c == ',' || c == '.' || c == ' ' || c == '^'
		|| c == '`' || c == '}' || c == ']' || c == ')' || c == '='
		|| c == '+' || c == '#' || c == '(' || c == '{' || c == '['
		|| c == '<' || c == '>' || c == '|' || c == '/' || c == '\n'
		|| c == '\t' || c == '\0')
		return (1);
	return (0);
}

static int	do_the_change(t_masterenv *menv, char **cmd, int start, int len)
{
	char	*name;
	char	*value;
	char	*new_cmd;

	if (!(name = ft_strnew(len)))
		return (0);
	name[len - 1] = '=';
	ft_strncpy(name, &(*cmd)[start + 1], len - 1);
	value = get_value_simple_dollar(menv, name);
	free(name);
	if (!value)
		return (0);
	if (!(new_cmd = ft_strnew(ft_strlen(*cmd) - len + ft_strlen(value))))
	{
		free(value);
		return (0);
	}
	ft_strncpy(new_cmd, *cmd, start);
	ft_strcat(new_cmd, value);
	free(value);
	ft_strcat(new_cmd, &(*cmd)[start + len]);
	free(*cmd);
	*cmd = new_cmd;
	return (1);
}

static int	do_simple_dollar(t_masterenv *menv, char **cmd, int *nope)
{
	int		i;
	int		j;

	i = -1;
	j = 1;
	while ((*cmd)[++i])
	{
		if ((*cmd)[i] == '$')
		{
			if (i > 0)
				if ((*cmd)[i - 1] == '\\' && ++(*nope))
					continue ;
			if (ft_isdigit((*cmd)[i + 1]))
				return (do_digit_dollar(cmd, i));
			if (is_badchar((*cmd)[i + 1]))
			{
				(*nope)++;
				continue ;
			}
			while ((*cmd)[i + j] != '$' && !is_badchar((*cmd)[i + j]))
				j++;
			return (do_the_change(menv, cmd, i, j));
		}
	}
	return (1);
}

int			ft_simple_dollar(t_masterenv *menv, char **cmd)
{
	int		ret;
	int		nope;

	nope = 0;
	while (is_done(*cmd, nope) == 0)
	{
		if (!(ret = do_simple_dollar(menv, cmd, &nope)))
			return (0);
	}
	return (1);
}
