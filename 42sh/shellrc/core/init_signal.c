/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:32:51 by fdikilu           #+#    #+#             */
/*   Updated: 2019/08/18 19:56:16 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_init_signals(void)
{
	signal(SIGHUP, &ft_quit_on_signal);
	signal(SIGINT, &ft_signal_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGILL, &ft_quit_on_signal);
	signal(SIGTRAP, &ft_quit_on_signal);
	signal(SIGABRT, &ft_quit_on_signal);
	signal(SIGEMT, &ft_quit_on_signal);
	signal(SIGFPE, &ft_quit_on_signal);
	signal(SIGBUS, &ft_quit_on_signal);
	signal(SIGSEGV, &ft_quit_on_signal);
	signal(SIGSYS, &ft_quit_on_signal);
	signal(SIGALRM, &ft_quit_on_signal);
	signal(SIGTERM, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCHLD, &ft_signal_handler);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGXCPU, &ft_quit_on_signal);
	signal(SIGXFSZ, &ft_quit_on_signal);
	signal(SIGVTALRM, &ft_quit_on_signal);
	signal(SIGPROF, &ft_quit_on_signal);
	signal(SIGWINCH, &ft_signal_handler);
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
}

void	ft_quit_on_signal(int sig)
{
	ft_printfd(2, "\n\e\033[31mMastershell\e[0m: ");
	ft_printfd(2, "was killed by signal: %d\n", sig);
	signal(sig, SIG_DFL);
	kill(0, sig);
	serial_killer();
	lt_delet();
	ft_termoder(2);
	exit(128 + sig);
}

void	ft_reset_signals(void)
{
	int		i;

	i = 0;
	while (++i < 32)
		signal(i, SIG_DFL);
}

void	ft_signal_handler(int sig)
{
	if (sig == SIGWINCH || sig == SIGINT)
		ft_controlcer(sig);
	else if (sig == SIGCHLD)
		update_jobs();
}
