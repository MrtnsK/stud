/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:27:01 by kemartin          #+#    #+#             */
/*   Updated: 2019/03/06 15:29:30 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
int				cmd_not_found(char *cmd, int ret);
int				var_exe_cmd(t_ms *m, char **env);
int				exe_cmd(t_ms *m, char **env);
int				spc_cnt(char *str);
void			set_env(char *env, t_ms *m);
void			unset_env(t_ms *m);
void			show_env(t_ms *m, char **env);
void			env_i(t_ms *m, char **env);
void			cd_function(char *dir, t_ms *m, char **env);
int				bin_cmd(t_ms *m, char **env);
void			exit_function(t_ms *m);
void			echo_function(char **tab, char **env, t_ms *m);
void			pwd_fun(t_ms *m);
void			gohome(t_ms *m);
void			ctrlc(int sign);
t_var			*ft_create_lst(char *name, char *data);
void			ft_lst_push_back(t_var **var, char *name, char *data);
void			ft_lst_clear(t_var **var);
void			show_prompt(t_ms *m);
void			silence_warning(int ac, char **av, char **env);
char			*is_this_home(char *may);
char			*env_find(char *str, char **env, t_ms *m);

#endif
