/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:39:49 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/16 16:46:53 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	check_done(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$' && cmd[i + 1] == '{')
		{
			i += 2;
			while (cmd[i])
			{
				if (cmd[i] == '}')
					return (0);
				i++;
			}
			return (1);
		}
		i++;
	}
	return (1);
}

static char	*var_to_change(char **cmd)
{
	int		i;
	int		j;
	int		start;
	char	*var;

	i = 0;
	j = -1;
	while ((*cmd)[i] && ((*cmd)[i] != '$' || (*cmd)[i + 1] != '{'))
		i++;
	start = i;
	while ((*cmd)[i] && ((*cmd)[i] != '}'))
		if ((*cmd)[i++] == '$' && (*cmd)[i] == '{')
			j++;
	while (j--)
		i++;
	if (!(*cmd)[i] || !(var = ft_strnew(i - start + 1)))
		return (NULL);
	ft_strncpy(var, &(*cmd)[start], i - start + 1);
	return (var);
}

int			change_cmd(char **cmd, char *final_form)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*tmp;

	if (!(tmp = ft_strnew(len_cmd(cmd, final_form))))
		return (0);
	i = -1;
	while (!((*cmd)[++i] == '$' && (*cmd)[i + 1] == '{'))
		tmp[i] = (*cmd)[i];
	k = i;
	j = 0;
	if ((l = -1) && final_form)
		while (final_form[j])
			tmp[i++] = final_form[j++];
	while ((*cmd)[k] != '}')
		if ((*cmd)[k++] == '$' && (*cmd)[k] == '{')
			l++;
	k = increment_k(l, k);
	while ((*cmd)[k])
		tmp[i++] = (*cmd)[k++];
	free(*cmd);
	*cmd = tmp;
	return (1);
}

int			one_dollar_exp(t_masterenv *menv, char **cmd)
{
	char	*var;
	char	*final_form;

	final_form = NULL;
	if (!(var = var_to_change(cmd)))
		return (0);
	if (!check_done(&var[2]))
		return (do_recursiv(menv, cmd, var));
	if (ft_check_error(var))
		return (free_norme(&var, NULL, 0));
	if (ft_substitution(menv, var, &final_form) == -1)
		return (free_norme(&var, cmd, -1));
	if (!change_cmd(cmd, final_form))
		return (free_norme(&var, &final_form, 0));
	return (free_norme(&var, &final_form, 1));
}

int			ft_dollar_expansion(t_masterenv *menv, char **cmd)
{
	int		ret;

	while (check_done(*cmd) == 0)
	{
		if ((ret = one_dollar_exp(menv, cmd)) == 0)
		{
			ft_printfd(2, "\e[93mMastershell\e[0m: bad substitution\n");
			ft_strdel(cmd);
			return (0);
		}
		else if (ret == -1)
			return (0);
	}
	return (1);
}
