/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:24:57 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/18 09:47:38 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_controlcerstuff(void)
{
	ft_putatend(&g_lock, &g_pac);
	free(g_ultib);
	free(g_lock.out);
	if (g_lock.aukprinted)
		ft_pathter(&g_lock, &g_pac, g_lock.aukprinted);
	ft_memset(g_lock.buf, 0, 256);
	g_lock.buf[0] = 0;
	g_lock.out[0] = 0;
	g_lock.lenout = 0;
	if (ft_errorprompt(&g_lock) || !(g_ultib = (char*)malloc(sizeof(char)))
		|| !(g_lock.out = (char*)malloc(sizeof(char))))
		if (ft_failed())
			exit(1);
	ft_controlcerstuff_2();
}

void		ft_redim(t_keymaster *lock, t_stockap *pac)
{
	int				savepos;
	int				i;
	struct winsize	sz;

	if ((ioctl(0, TIOCGWINSZ, &sz)) == -1)
		sz.ws_col = 200;
	pac->nbcol = sz.ws_col;
	savepos = lock->curspos;
	ft_putatend(lock, pac);
	i = -1;
	while (++i < lock->lvl)
		ft_printfd(0, "%s", pac->up_cap);
	i = -1;
	while (++i < pac->nbcol)
		ft_printfd(0, "%s", pac->left_cap);
	ft_printfd(0, "%s", pac->cd_cap);
	lock->lvl = (int)((lock->lenout + lock->promptsize) / pac->nbcol);
	ft_printfd(0, "%s%s", lock->prompt, lock->out);
	lock->curspos = lock->promptsize + lock->lenout;
	if ((lock->curspos % pac->nbcol) == 0)
		ft_right(lock, pac);
	i = lock->curspos + 1;
	while (--i > savepos)
		ft_goleft(lock, pac);
}

void		ft_controlcer(int signo)
{
	if (signo == SIGINT && !g_pid)
		ft_controlcerstuff();
	if (signo == SIGWINCH && !g_pid)
	{
		ft_redim(&g_lock, &g_pac);
		if (g_lock.aukprinted)
		{
			g_lock.stock.select -= 1;
			if (g_lock.stock.select == -1)
				g_lock.stock.select = (g_lock.stock.argc - 1);
			if (ft_pathter(&g_lock, &g_pac, 0))
				if (ft_failed())
					exit(1);
		}
	}
}

void		ft_termoder(int mode)
{
	static struct termios	orig_tios;

	if (mode == 1)
	{
		if (tcgetattr(STDIN_FILENO, &orig_tios) == -1)
			exit(1);
	}
	else if (mode == 2)
	{
		if (tcsetattr(STDIN_FILENO, TCSANOW, &orig_tios) == -1)
			exit(1);
	}
}

int			ft_cannoner(void)
{
	struct termios	terter;

	if (tcgetattr(STDIN_FILENO, &(terter)) == -1)
		exit(1);
	ft_termoder(1);
	terter.c_lflag &= ~(ICANON);
	terter.c_lflag &= ~(ECHO);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &(terter)) == -1)
	{
		ft_termoder(2);
		ft_putstr_fd("Call to tcsetattr() failed\n", STDERR_FILENO);
		return (1);
	}
	g_shell_attr = terter;
	return (0);
}
