/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:25:08 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/15 14:22:52 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMASTER_H
# define LIBMASTER_H

# define BUFF_SIZE 1000
# define INF 1.0/0.0
# define LINF -1.0/0.0

# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_normfriendly
{
	int				i;
	int				j;
	int				printed_char;
}				t_norm;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_parameters
{
	char	specifier;
	char	*flags;
	int		widist;
	size_t	width;
	int		prexist;
	size_t	precision;
	char	*lenght;
	char	*arg;
	int		sign;
	int		maj;
	int		masterflag[3];
	int		isp;
	int		ismaj;
}				t_parameters;

typedef struct	s_lt
{
	void		*ptr;
	struct s_lt	*next;
}				t_lt;

char			*ft_crea0(int size, char g);
void			ft_printsign(t_parameters *stock);
void			ft_widthower(t_parameters *stock);
void			ft_switchmaster(char **switcher, t_parameters *stock);
char			*ft_convhex(unsigned long long in, char x);
char			*ft_convbin(unsigned long long in);
void			ft_masterprec(t_parameters *stock);
void			ft_printprec(t_parameters *stock);

int				ft_printf(const char *format, ...);
char			*ft_plus_ou_moins(char *acheker);
char			*ft_convhoc(unsigned long long in);

void			detect_sign_n_maj(t_parameters *param);
int				detect_specifier(const char *format, int i,
	t_parameters *param);
void			detect_flags(const char *format, int *ptr_i,
	t_parameters *param);
void			detect_width(const char *str, int *ptr_i,
	t_parameters *param, va_list arg);
void			detect_prec(const char *str, int *p_i,
	t_parameters *par, va_list arg);
void			detect_len_d(const char *format, int i,
	t_parameters *param, va_list arg);
void			detect_len_f(const char *format, int i,
	t_parameters *param, va_list arg);
void			detect_arg_csp(t_parameters *param, va_list arg);

void			detect_arg_none(t_parameters *param, va_list arg);
void			detect_arg_hh(t_parameters *param, va_list arg);
void			detect_arg_h(t_parameters *param, va_list arg);
void			detect_arg_ll(t_parameters *param, va_list arg);
void			detect_arg_l(t_parameters *param, va_list arg);
void			detect_arg_none_xo(t_parameters *param, va_list arg);
void			detect_arg_hh_xo(t_parameters *param, va_list arg);
void			detect_arg_h_xo(t_parameters *param, va_list arg);
void			detect_arg_ll_xo(t_parameters *param, va_list arg);
void			detect_arg_l_xo(t_parameters *param, va_list arg);
void			check_specifier(const char *format, int i, t_parameters *param);
void			detect_flags_2(const char *format, int *ptr_i,
	t_parameters *param);
void			detect_flags_3(const char *format, int *ptr_i,
	t_parameters *param);
void			detect_prec2(t_parameters *pm);
void			init_t_parameters(t_parameters *param);
void			free_struct(t_parameters *param);
void			check_maj_specifier(t_parameters *param);

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t nbyte);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
int				ft_strchri(const char *s, int c);
int				ft_strrchri(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
size_t			ft_strlcat(char *dst, const char *src, size_t siz);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_itoa(long long n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
int				ft_get_next_line(const int fd, char **line);
char			*ft_strndup(const char *s, int n);
char			*ft_strjoin_free(char *str, char *buff);
char			*ft_strjoin_eerf(char *str, char *buff);
char			*ft_unitoa(unsigned long long n);
char			*ft_ftoa(long double f, size_t prec);
char			*ft_convhsuite(void);
void			ft_arrondisorsuite(t_parameters *stock, int *i);
void			n(t_parameters *param, t_norm *nrm);
int				ft_isspace(int c);
char			*ft_strcator(char *dest, char *src);
double			ft_atof(char *str);
int				ft_isalnumflt(int c);
long long		ft_ultimatoi(const char *str);
char			*ft_strchrstr(const char *s, char *find);
char			*ft_strjoin_ufree(char *str, char *buff);
int				ft_mastoi(const char *str);
int				go_end(const char *format, int i);
t_parameters	parameters_parser(const char *format, va_list arg, int i);
void			procedure2(const char *format, t_norm *sympa);

int				ft_printfd(int fd, const char *format, ...);
void			nfd(t_parameters *param, t_norm *nrm, int fd);
int				ft_strchrstrfirst(const char *s, char *find);
size_t			ft_tablen(char **s);
char			**ft_tabcpy(char **dest, char **src);
char			**ft_tabcat(char **dest, char **src);
int				ft_strchralpha(const char *s);
int				ft_strnchralpha(const char *s, int n);
char			**ft_tabncpy(char **dest, char **src, size_t n);
int				*ft_tabintncpy(int *dest, int *src, size_t n);
int				ft_strcpt(const char *s, int c);
char			**ft_tabcator(char **dest, char **src);
int				*ft_tabintcat(int *dest, int *src);
int				*ft_tabintcpy(int *dest, int *src);
void			ft_putnstr_fd(char const *s, int fd, int n);
int				ft_strrdigit(const char *s);
int				ft_abs(int a);

t_lt			*get_lifetime(t_lt	*new_ptr);
void			*lt_add(void *ptr);
void			lt_remove(void *ptr);
void			lt_delet(void);
void			ft_strtrim_calc(char **s);
#endif
