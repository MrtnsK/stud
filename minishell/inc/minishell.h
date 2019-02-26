/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:27:01 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/26 19:49:16 by kemartin         ###   ########.fr       */
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

void			get_cmd(t_ms *m);
int				ft_strchrint(const char *str, int c);
int				exe_cmd(t_ms *m, char **env);
void			gohome(t_ms *m);
void			cd_function(char *dir, t_ms *m);
int				bin_cmd(t_ms *m, char **env);
void			exit_function(t_ms *m);
void			echo_function(char **tab);
void			ctrlc(int sign);
void			show_prompt(t_ms *m);
void			silence_warning(int ac, char **av, char **env);
void			set_env(char *env, t_ms *m);
t_var			*ft_create_lst(char *name, char *data);
void			ft_lst_push_back(t_var **var, char *name, char *data);
void			show_env(t_ms *m, char **env);

#endif
