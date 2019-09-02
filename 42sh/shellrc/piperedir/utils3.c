/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:22:47 by apsaint-          #+#    #+#             */
/*   Updated: 2019/08/20 14:32:44 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_freetabc(char **opt)
{
	int i;

	i = -1;
	while (opt[++i])
		free(opt[i]);
	free(opt);
}

int		ft_restablish(int fd_b, int fd_agregin)
{
	if (fd_agregin != -1)
		dup2(fd_b, fd_agregin);
	close(fd_b);
	return (0);
}

int		ft_check_agregin(t_masterenv *tenv, int j)
{
	if (ft_strstr(tenv->cgv[j], "<&"))
	{
		if (!tenv->cgv[j + 1] || !ft_checkfd(tenv->cgv[j + 1]))
		{
			if (tenv->cgv[j + 1])
				ft_printfd(2,
				"\e[93mMastershell\e[0m: %s: ambiguous redirect\n",
				tenv->cgv[j + 1]);
			else
			{
				ft_printfd(2, "\e[93mMastershell\e[0m: syntax error ");
				ft_printfd(2, "near unexpected token `newline'\n");
			}
			return (1);
		}
	}
	return (0);
}

void	ft_close_pipe(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

char	*ft_opt_pipe(int k, int i, t_masterenv *menv, int end)
{
	char	*cmd;
	char	*tmp;
	char	c;
	char	sp[2];

	c = 7;
	sp[0] = c;
	sp[1] = '\0';
	tmp = NULL;
	while (menv->cgv[++k] && (menv->cgprio[k] == 10 || menv->cgprio[k] == 0
	|| menv->cgprio[k] == 9 || menv->cgprio[k] == 1) && k < end)
	{
		if (k == i + 1)
			tmp = ft_strdup(menv->cgv[k]);
		else
		{
			cmd = ft_strjoin(tmp, sp);
			free(tmp);
			tmp = ft_strjoin(cmd, menv->cgv[k]);
			free(cmd);
		}
	}
	return (tmp);
}
