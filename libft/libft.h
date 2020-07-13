/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 13:17:18 by jboer          #+#    #+#                */
/*   Updated: 2019/12/10 15:35:09 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1000

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_get
{
	char			*content;
	int				file;
	int				ret;
	struct s_get	*next;
}					t_get;

int					ft_atoi(const char *str);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
int					ft_strequ(char const *s1, char const *s2);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_isprint(int c);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(char const *str);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strdup(char const *src);
void				ft_putnbr(int nb);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_tolower(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(char const *haystack, char const *needle);
char				*ft_strnstr(char const *haystack, char const *needle,
size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_memdel(void **ap);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_putendl(char const *s);
int					ft_delimc(char const *s, char c);
int					ft_charc(char const *s, char c);
int					ft_strc(char const *s, char c);
int					ft_intlen(int n);
char				*ft_intos(char *strn, int intlen, int i, int n);
void				ft_printarray(char **ar);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strndup(const char *src, size_t size);
int					ft_strdcount(char const *s, char c);
size_t				ft_astrlen(char **ptr);
int					ft_mapdel(void **map);
int					get_next_line(const int fd, char **line);
int					ft_charindex(const char *str, char c);
int					ft_ispint(char *str);
long long			ft_llatoi(const char *str);
int					ft_natoi(const char *str, int n);
int					ft_datoi(const char *str, char d);
void				ft_printarray_fd(char **ar, int fd);
void				*ft_memallocexit(size_t size);
int					ft_powerof(int n, int p);

#endif
