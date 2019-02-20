/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:27:01 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/20 18:26:04 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <libc.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <signal.h>

# define B_SIZE 1

char				**g_envv;

typedef struct	s_var
{
	char			*name;
	char			*content;
	struct s_var	*next;
}				t_var;

typedef struct	s_ms
{
	char			*cmd;
	char			*cur_dir;
	t_var			*var;
}				t_ms;


void		get_cmd(t_ms *m);
int			exe_cmd(t_ms *m, char **env);
void		cd_function(char *dir, t_ms *m);
void		exit_function(t_ms *m);
void		show_prompt(t_ms *m);
void		ctrlc(int sign);

#endif
