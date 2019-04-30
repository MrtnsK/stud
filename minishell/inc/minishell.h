/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:27:01 by kemartin          #+#    #+#             */
/*   Updated: 2019/04/30 15:58:30 by kemartin         ###   ########.fr       */
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
	char			**arg;
	t_var			*var;
}				t_ms;

void			cd_function(char *dir, t_ms *m, char **env);
int				path_cmd(t_ms *m, char **env, char **arg);
int				bin_cmd(t_ms *m, char **env);
void			echo_function(char **env, t_ms *m);
char			*lst_env(char *var, t_ms *m);
char			*env_find(char *str, char **env, t_ms *m);
void			show_env(t_ms *m, char **env);
void			ctrlc(int sign);
void			exit_function(t_ms *m);
char			*is_this_home(char *may);
void			gohome(t_ms *m, char **env);
void			quote_case(char *str);
int				spc_cnt(char *str);
void			get_cmd(t_ms *m);
int				cmd_not_found(char *cmd, int ret);
int				var_exe_cmd(t_ms *m, char **env);
int				is_wp(char *str);
int				exe_cmd(t_ms *m, char **env);
void			set_env(char *env, t_ms *m, char **origin_env);
void			freenc(char *name, char *content);
void			unset_env_while(t_var *af, t_var *prev, t_ms *m, char *del);
void			unset_env(t_ms *m);
void			init_env(char **env, t_ms *m);
int				ft_varsize(t_var *list);
void			cd_notfound(char *dir, t_ms *m, char **env);
void			show_prompt(void);
void			ft_replace(char **old, char *new);
void			set_oldpwd(t_ms **m, char cwd[1025]);
t_var			*ft_create_lst(char *name, char *data);
void			ft_lst_push_back(t_var **var, char *name, char *data);
void			ft_lst_clear(t_var **var);
void			starting(void);
void			silence_warning(int ac, char **av, char **env);
void			ft_clear_path(char **arg);
int				ft_clear_dir(char **dir);
char			*reallocstr(char *str);
char			*arg_adjustment(char *path, char *str);
void			ft_freetab(char **tab);

#endif
