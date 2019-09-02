/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:34:21 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/02 15:01:40 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*create_value(char *env, char *name)
{
	int		i;
	int		len;
	char	*value;

	i = 0;
	if (!name[i])
		return (NULL);
	while (env[i] && name[i])
	{
		if (name[i] != env[i])
			return (NULL);
		i++;
	}
	if (name[i])
		return (NULL);
	i++;
	len = ft_strlen(&env[i]);
	if (len == 0 || !(value = ft_strnew(len)))
		return (NULL);
	ft_strncpy(value, &env[i], len);
	return (value);
}

static char	*browse_tab_value(char **tab_var, char *name)
{
	int		i;
	char	*value_var;

	i = 0;
	if (!tab_var || !(*tab_var))
		return (NULL);
	while (tab_var[i])
		if ((value_var = create_value(tab_var[i++], name)))
			return (value_var);
	return (NULL);
}

char		*ft_getvalue(t_masterenv *menv, char *name)
{
	char	*value;

	if (!name)
		return (NULL);
	if ((value = browse_tab_value(menv->stock[0], name)))
		return (value);
	else if ((value = browse_tab_value(menv->internal_var[0], name)))
		return (value);
	else
		return (NULL);
}
