/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenvstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:36:57 by pharatyk          #+#    #+#             */
/*   Updated: 2019/06/22 10:35:18 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_setenvcgc2xist(t_masterenv *menv, int i)
{
	int		j;
	char	*tmp;

	j = -1;
	while (menv->stock[0][i][++j] != '=')
		;
	menv->stock[0][i][++j] = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (j + 1))))
		return (1);
	ft_strcpy(tmp, menv->stock[0][i]);
	free(menv->stock[0][i]);
	if (!(menv->stock[0][i] = (char*)malloc(sizeof(char) * (j + 1))))
		return (1);
	ft_strcpy(menv->stock[0][i], tmp);
	free(tmp);
	return (0);
}

int	ft_setenvcgc2xistpo(t_masterenv *menv, int i, char **opt)
{
	char	**tenv;

	i = -1;
	while (menv->stock[0][++i])
		;
	if (!(tenv = (char**)malloc(sizeof(char*) * (i + 2))))
		return (1);
	tenv[i + 1] = 0;
	i = -1;
	while (menv->stock[0][++i])
		tenv[i] = menv->stock[0][i];
	if (!(tenv[i] = (char*)malloc(sizeof(char) *
		(ft_strlen(opt[1]) + 2))))
		return (1);
	ft_strcpy(tenv[i], opt[1]);
	ft_strcat(tenv[i], "=");
	free(menv->stock[0]);
	if (!(menv->stock[0] = (char**)malloc(sizeof(char*) * (i + 2))))
		return (1);
	menv->stock[0][i + 1] = 0;
	i = -1;
	while (tenv[++i])
		menv->stock[0][i] = tenv[i];
	free(tenv);
	return (0);
}

int	ft_setenvcgc3xist(t_masterenv *menv, int i, char **opt)
{
	int		j;
	char	*tmp;

	j = -1;
	while (menv->stock[0][i][++j] != '=')
		;
	menv->stock[0][i][++j] = 0;
	if (!(tmp = (char*)malloc(sizeof(char) *
		(j + 1 + ft_strlen(opt[2])))))
		return (1);
	ft_strcpy(tmp, menv->stock[0][i]);
	ft_strcat(tmp, opt[2]);
	free(menv->stock[0][i]);
	if (!(menv->stock[0][i] = (char*)malloc(sizeof(char)\
	* (ft_strlen(tmp) + 1))))
		return (1);
	ft_strcpy(menv->stock[0][i], tmp);
	free(tmp);
	return (0);
}

int	ft_setenvcgc3xistpo(t_masterenv *menv, int i, char **tenv, char **opt)
{
	i = -1;
	while (menv->stock[0][++i])
		;
	if (!(tenv = (char**)malloc(sizeof(char*) * (i + 2))))
		return (1);
	tenv[i + 1] = 0;
	i = -1;
	while (menv->stock[0][++i])
		tenv[i] = menv->stock[0][i];
	if (!(tenv[i] = (char*)malloc(sizeof(char) *
		(ft_strlen(opt[1]) + 2 + ft_strlen(opt[2])))))
		return (1);
	ft_strcpy(tenv[i], opt[1]);
	ft_strcat(tenv[i], "=");
	ft_strcat(tenv[i], opt[2]);
	free(menv->stock[0]);
	if (!(menv->stock[0] = (char**)malloc(sizeof(char*) * (i + 2))))
		return (1);
	menv->stock[0][i + 1] = 0;
	i = -1;
	while (tenv[++i])
		menv->stock[0][i] = tenv[i];
	free(tenv);
	return (0);
}
