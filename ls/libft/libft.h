/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:40:18 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/19 16:15:19 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct	s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;

typedef struct	s_file
{
	int					fd;
	char				*data;
	struct s_file		*next;
}				t_file;

char			**ft_strsplit(const char *str, char c);
char			**ft_strsplitstr(char const *str, char const *set);
char			*ft_convert_base(char const *nbr, char const *base_from, \
				char const *base_to);
char			*ft_itoa(int n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *str, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, const char *src, size_t nb);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *str, const char *to_find, size_t l);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *str);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				*ft_intsplitstr(char const *str, char const *set);
int				ft_abs(int a);
int				ft_atoi(const char *str);
int				ft_delelem(t_file **file, int fd, int ret);
int				ft_isalnum(int c);
int				ft_isalpha(int s);
int				ft_isascii(int c);
int				ft_isdigit(int nb);
int				ft_isprint(int c);
int				ft_lstsize(t_list *list);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_nblen(long nb);
int				ft_putstr_int(char const *str, int ret);
int				ft_sqrt_app(int nb);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_treat(char **data, char **line);
int				get_next_line(const int fd, char **line);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
t_file			*ft_newfile(int fd);
t_file			*ft_srchfile(t_file *file, int fd);
t_list			*ft_lstat(t_list *node, unsigned int nbr);
t_list			*ft_lstfind(t_list *node, void *data_ref);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstmerge(t_list **list1, t_list *list2);
void			ft_lstsort(t_list **list);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_base(int nbr, char const *base);
void			ft_putnbr_base_fd(int nbr, char const *base, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(const char *str);
void			ft_putstr_fd(const char *str, int fd);
void			ft_revlst(t_list **list);
void			ft_sortedlstmerge(t_list **list1, t_list *list2);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_swap(int *a, int *b);
void			ft_swapchar(char *a, char *b);

#endif
