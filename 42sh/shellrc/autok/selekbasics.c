/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selekbasics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:17:28 by pharatyk          #+#    #+#             */
/*   Updated: 2019/07/01 14:47:08 by pharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_maxer(t_stock *stock, int max)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (stock->output[++i])
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (max + 2))))
			return (1);
		j = -1;
		while (stock->output[i][++j])
			tmp[j] = stock->output[i][j];
		tmp[j] = 0;
		j--;
		while (++j < max)
			tmp[j] = ' ';
		tmp[j] = 0;
		free(stock->output[i]);
		if (!(stock->output[i] = (char*)malloc(sizeof(char)
			* (max + 2))))
			return (1);
		stock->output[i] = ft_strcpy(stock->output[i], tmp);
		free(tmp);
	}
	return (0);
}

static int	ft_maxfinder(t_stock *stock, t_basiks *tools)
{
	struct winsize w;

	if ((ioctl(0, TIOCGWINSZ, &w)) == -1)
		return (1);
	tools->nbobj = 0;
	tools->max = 0;
	while (stock->output[tools->nbobj])
	{
		if ((int)ft_strlen(stock->output[tools->nbobj]) > tools->max)
			tools->max = ft_strlen(stock->output[tools->nbobj]);
		tools->nbobj += 1;
	}
	if ((tools->max % 8) == 0)
		tools->max += 1;
	while ((tools->max % 8) != 0)
		tools->max += 1;
	if (tools->max > w.ws_col)
		return (2);
	if (ft_maxer(stock, tools->max))
		return (1);
	return (ft_maxfinder_ender(tools, w));
}

static int	ft_outcreator(t_basiks *tools, t_keymaster *lock)
{
	int				isimpair;
	float			truenbline;
	struct winsize	w;

	if ((ioctl(0, TIOCGWINSZ, &w)) == -1)
		return (1);
	if (tools->lignemax == 0)
	{
		tools->nbligne = -1;
		return (0);
	}
	isimpair = (tools->nbobj % 2);
	truenbline = (float)tools->nbobj / (float)(tools->lignemax);
	if (truenbline > (int)truenbline)
		tools->nbligne = (int)truenbline + 1;
	else
		tools->nbligne = (int)truenbline;
	if (tools->nbligne > w.ws_row - 3 - lock->lvl)
		return (2);
	return (0);
}

void		ft_reboot(t_stock *stock)
{
	int i;
	int j;

	i = -1;
	while (stock->output[++i])
	{
		j = ft_strlen(stock->output[i]);
		while (stock->output[i][--j] == ' ')
			stock->output[i][j] = 0;
	}
}

int			ft_basic(t_stock *stock, t_stockap *pac, t_basiks *tools
	, t_keymaster *lock)
{
	int		hmm;

	hmm = ft_maxfinder(stock, tools);
	if (hmm == 1)
		return (1);
	if (hmm == 2)
		return (ft_basicimpossible(stock, tools));
	hmm = ft_outcreator(tools, lock);
	if (hmm == 1)
		return (1);
	if (hmm == 2)
		return (ft_basicimpossible(stock, tools));
	tools->lignemax = 0;
	if (tools->nbligne >= 0)
		while ((tools->lignemax * tools->nbligne) < tools->nbobj)
			tools->lignemax += 1;
	return (ft_basic_end(stock, pac, tools));
}
