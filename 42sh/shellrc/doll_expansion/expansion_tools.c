/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:46:16 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/18 22:40:22 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*cmp_getvalue(char *env, char *name)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	while (env[i] && name[i])
	{
		if (name[i] != env[i])
			return (NULL);
		i++;
	}
	if (name[i])
		return (NULL);
	len = ft_strlen(&env[i]);
	if (len == 0 || !(value = ft_strnew(len)))
		return (NULL);
	ft_strncpy(value, &env[i], len);
	return (value);
}

char	*browse_tab(char **tab_var, char *name)
{
	int		i;
	char	*value_var;

	i = 0;
	if (!tab_var || !(*tab_var))
		return (NULL);
	while (tab_var[i])
		if ((value_var = cmp_getvalue(tab_var[i++], name)))
		{
			free(name);
			return (value_var);
		}
	return (NULL);
}

char	*get_var(t_masterenv *menv, char *var, int i)
{
	int		len;
	char	*name;
	char	*value_var;

	len = ft_strlen(var);
	if (len == 0 || !(name = ft_strnew(len - (len - i) - 2 + 1)))
		return (NULL);
	ft_strncpy(name, &var[2], len - (len - i) - 2);
	name[len - (len - i) - 2] = '=';
	if ((value_var = browse_tab(menv->stock[0], name)))
		return (value_var);
	if ((value_var = browse_tab(*menv->internal_var, name)))
		return (value_var);
	free(name);
	return (NULL);
}

int		len_cmd(char **cmd, char *final_form)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while ((*cmd)[i] && ((*cmd)[i] != '$' || (*cmd)[i + 1] != '{'))
		i++;
	len = i;
	while ((*cmd)[i] && ((*cmd)[i] != '}'))
		if ((*cmd)[i++] == '$' && (*cmd)[i] == '{')
			j++;
	while (j--)
		i++;
	while ((*cmd)[i++])
		len++;
	if (final_form)
		len += ft_strlen(final_form);
	return (len);
}
