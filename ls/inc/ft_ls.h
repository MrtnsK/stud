/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:56:16 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/13 19:35:03 by kemartin         ###   ########.fr       */
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

# define OPT_L 1
# define OPT_UR 2
# define OPT_A 4
# define OPT_LR 8
# define OPT_T 16
# define OPT_G 32
# define OPT_UA 64
# define OPT_F 128

# define BUFSIZE_LS 1024

typedef struct stat		t_stat;
typedef struct dir		t_dir;
typedef struct passwd	t_pswd;
typedef struct group	t_grp;

typedef struct			s_buf
{
	unsigned		id;
	char			buf[BUFSIZE_LS];
}						t_buf;

typedef struct			s_lst
{
	char			*name;
	t_stat			stat;
	t_pswd			*pswd;
	t_grp			*grp;
	t_dir			*dir;
	char			acl;
	char			t;
	struct s_lst	*next;
}						t_lst;

typedef struct			s_param
{
	char			ok;
	char			*name;
	t_lst			**child;
	struct s_param	*next;
}						t_param;

typedef struct			s_struct
{
	char		opt;
	int			nb;
	t_buf		bf;
	t_param		**names;
}						t_struct;

void					ft_putbuff(t_buf *i);
void					ft_addstr(t_buf *i, char *str);
void					ft_addtwostr(t_buf *i, char *str, char *str2);
void					ft_addchar(t_buf *i, char c);
void					ft_addnbr(t_buf *i, int nbr);

void					total(t_buf *i, t_lst *lst);
void					files_err(char *name);
void					acces_error(char *name);

void					leading(int size, char *str, t_buf *i);
void					leading_nbr(int size, int nbr, t_buf *i);
void					leading_nbr2(int size, int nbr, t_buf *i);

void					ls_rec(t_struct *tab, int rec);
void					ls(t_struct *tab, int rec);
int						link_pointer(t_buf *i, char *name);

void					ft_lst_push_back(t_lst **lst, char *name, char *src);

char					*join_path(char *path1, char *path2);

t_param					*ft_create_param(char *name);
void					ft_param_push_back(t_param **lst, char *name);
void					ft_param_push_after(t_param *lst, char *name);
void					paramcpy(t_param *new, t_param *old);

void					get_childs(t_param *p, char opt);
void					simple_print(t_lst *lst, t_buf *i, char opt);
void					list_print(t_lst *lst, char opt, t_buf *i);
void					lstcpy(t_lst *new, t_lst *old);

void					options(char *str, t_struct *tab);
void					ft_sort(t_lst **lst, char o, t_lst *tmp2, t_lst *tmp3);
void					ft_reverse(t_lst **lst, char o, t_lst *t2, t_lst *t3);
void					cut_time_opt(char *str, t_buf *i);
void					cut_time_year(char *str, t_buf *i);
void					write_perms(int perm, char acl, t_buf *i);
char					*ft_title(char *title, int t);

void					ft_free(t_param **tab);

#endif
