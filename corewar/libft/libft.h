/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:42:32 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/24 19:04:05 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 10

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			*str;
	int				i;
}					t_gnl;

typedef	enum		e_flag
{
	flag_parse_alt = 1 << 0,
	flag_0 = 1 << 1,
	flag_left = 1 << 2,
	flag_pos = 1 << 3,
	flag_space = 1 << 4,
	flag_j_conv = 1 << 5,
	flag_z_conv = 1 << 6,
	flag_h_conv = 1 << 8,
	flag_hh_conv = 1 << 7,
	flag_l_conv = 1 << 9,
	flag_ll_conv = 1 << 10,
}					t_flag;

typedef struct		s_flag_content
{
	char		*s;
	t_flag		v;
}					t_content;

typedef	struct		s_display
{
	int				size;
	int				prec;
	uint16_t		flag;
}					t_display;

typedef struct		s_fun
{
	char			*s;
	int				(*f)(va_list ap, char type, t_display d);
}					t_fun;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy_rev(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_wcharlen(const wchar_t c);
size_t				ft_strwlen(const wchar_t *s);
size_t				ft_strwttlen(const wchar_t *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *srcs);
char				*ft_strncpy(char *dest, const char *src, size_t len);
wchar_t				*ft_strwncpy(wchar_t *dest, const wchar_t *src,
		size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *ltl, size_t l);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int a);
int					ft_isdigit(int a);
int					ft_isalnum(int a);
int					ft_isascii(int a);
int					ft_isprint(int a);
int					ft_toupper(int a);
int					ft_tolower(int a);
char				*ft_lowerstr(char *str);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
wchar_t				*ft_strwnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
wchar_t				*ft_strwsub(wchar_t const *s, unsigned int start,
		size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2, int free_str);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_max(intmax_t n);
char				*ft_itoa_base_max(uintmax_t value, int base);
void				ft_putchar(char c);
void				ft_putwchar(wchar_t c);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putstr(char const *str);
void				ft_putwstr(wchar_t *s);
void				ft_putwstr_fd(wchar_t *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

unsigned int		ft_pow(int x, int y);
unsigned int		ft_abs(int x);
int					ft_wordcount(char const *s, char c);
size_t				ft_wordlen(const char *s, char c);
int					ft_is_sort(int *a, int size);

int					get_next_line(const int fd, char **line);

/*
 **		PRINTF
*/

int					ft_printf(const char *str, ...);
int					printf_next(const char *str, va_list ap, int *tot);
int					conversion_type(va_list ap, char type, t_display d);
char				*display_arg(char **s, t_display d, char type);
int					display_arg_wstr(t_display d, wchar_t *s);
int					display_arg_str(t_display d, char *s);
int					display_arg_pct(t_display d, char *c);
char				*display_arg_ptr(char **s, t_display d);
char				*parse_alt_ptr(char **tmp, int len, t_display d);
void				parse_sgn(char **tmp, char **s, t_display d);
char				*parse_alt(char **tmp, char *s, char type, t_display d);
t_flag				fill_flag(const char *flag);
t_flag				display_control(const char *flag,
		const t_content disp[11]);
int					int_arg(va_list ap, char type, t_display d);
int					lint_arg(va_list ap, char type, t_display d);
int					int_char(va_list ap, char type, t_display d);
int					p_arg(va_list ap, char type, t_display d);
int					str_arg(va_list ap, char type, t_display d);
int					wstr_arg(va_list ap, t_display d);
int					pct_arg(va_list ap, char type, t_display d);
int					no_conversion(t_display d);

char				*prec_int(char **s, t_display d);
wchar_t				*parse_prec(wchar_t *s, t_display d);
char				*parse_str_prec(char *s, t_display d);
wchar_t				*parse_wprec(wchar_t *s, t_display d);
intmax_t			size_int(va_list ap, t_display d);
uintmax_t			size_uint(va_list ap, t_display d);
uintmax_t			*size_uint_ptr(va_list ap, t_display d);

#endif
