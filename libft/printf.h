/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 15:34:55 by evlad             #+#    #+#             */
/*   Updated: 2017/04/12 16:37:11 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/*
** --------------------------------------------------------------------------
**								   INCLUDES
** --------------------------------------------------------------------------
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft.h"

/*
** --------------------------------------------------------------------------
**								   STRUCTURES
** --------------------------------------------------------------------------
*/

typedef struct		s_flag
{
	int				diese;
	int				zero;
	int				minus;
	int				plus;
	int				width;
	int				precision;
	int				space;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
	char			type;
	int				length;

	int				first_malloc;
	int				second_malloc;
	int				null;
	wchar_t			*buff;
}					t_flag;

typedef struct		s_length
{
	int				len;
}					t_length;

typedef struct		s_conv
{
	char			*type;
	void			(*function)(char type, t_flag *active, va_list args,
						t_length *len);
}					t_conv;

/*
** --------------------------------------------------------------------------
**								    BASICS
** --------------------------------------------------------------------------
*/

int					ft_printf(const char *format, ...);
int					formating(const char *format, va_list args, t_length *len);

int					check_size(t_flag *active);
int					check_address(char *buffer);
intmax_t			signed_cast(va_list args, t_flag *active);
uintmax_t			unsigned_cast(va_list args, t_flag *active);

void				freemalloc(char *buffer, t_flag *active, int realloc);

char				*strsubwchar(char *buffer, int start, t_flag *active);

/*
** --------------------------------------------------------------------------
**								    FLAGS
** --------------------------------------------------------------------------
*/

t_flag				*init_flag(void);
t_length			*init_length(void);
int					check_flags(const char *flag, t_flag *active);
void				apply_flags(char *buffer, int length, t_flag *active,
						t_length *len);

char				*apply_diese(char *buffer, t_flag *active);
char				*apply_zero(char *buffer, t_flag *active);
char				*apply_plus(char *buffer, t_flag *active);
char				*apply_width(char *buffer, t_flag *active);
char				*apply_space(char *buffer, t_flag *active);
char				*apply_last_flags(char *buffer, int length,
						t_flag *active);
char				*apply_precision(char *buffer, int length, t_flag *active);
char				*apply_minus(char *buffer, t_flag *active);

/*
** --------------------------------------------------------------------------
**								   CONVERSIONS
** --------------------------------------------------------------------------
*/

void				conv(char type, t_flag *active, va_list args,
						t_length *len);
void				conv_int(char type, t_flag *active, va_list args,
						t_length *len);
void				conv_dou(char type, t_flag *active, va_list args,
						t_length *len);
void				conv_c(char type, t_flag *active, va_list args,
						t_length *len);
void				conv_s(char type, t_flag *active, va_list args,
						t_length *len);
void				conv_ws(char type, t_flag *active, va_list args,
						t_length *len);
void				conv_p(char type, t_flag *active, va_list args,
						t_length *len);
void				conv_pct(char type, t_flag *active, va_list args,
						t_length *len);

#endif
