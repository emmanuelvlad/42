/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:34 by evlad             #+#    #+#             */
/*   Updated: 2017/04/12 15:02:45 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	conv_dou(char type, t_flag *active, va_list args, t_length *len)
{
	if (type == 'D')
		type = 'd';
	else if (type == 'O')
		type = 'o';
	else if (type == 'U')
		type = 'u';
	active->l = 1;
	conv_int(type, active, args, len);
}

void	conv_c(char type, t_flag *active, va_list args, t_length *len)
{
	char	*str;
	int		length;

	str = NULL;
	active->type = type;
	active->first_malloc = 1;
	length = 1;
	if (!check_size(active) && active->type == 'c')
	{
		str = ft_strnew(2);
		str[0] = va_arg(args, int);
		str[1] = '\0';
	}
	else if (check_size(active) || active->type == 'C')
	{
		str = ft_putwchar(va_arg(args, wchar_t));
		length = ft_strlen(str);
		if (length)
			len->len += length - 1;
		else
			len->len += length;
		if (active->type == 'C' && *str == '\0')
			active->null = 1;
	}
	apply_flags(str, length, active, len);
}

void	conv_ws(char type, t_flag *active, va_list args, t_length *len)
{
	wchar_t	*wstr;
	char	*str;
	char	*tmp;
	int		i;

	wstr = va_arg(args, wchar_t*);
	active->buff = wstr;
	str = NULL;
	active->type = type;
	i = 0;
	if (wstr == NULL)
		apply_flags("(null)", 6, active, len);
	else
	{
		str = ft_strnew(ft_wstrlen(wstr) * 2);
		active->first_malloc = 1;
		while (wstr[i])
		{
			tmp = ft_putwchar(wstr[i++]);
			str = ft_strcat(str, tmp);
			free(tmp);
		}
		apply_flags(str, ft_wstrlen(wstr), active, len);
	}
}

void	conv_p(char type, t_flag *active, va_list args, t_length *len)
{
	void		*ptr;
	uintptr_t	ptrint;
	char		*address;
	char		*str;

	ptr = va_arg(args, void*);
	ptrint = (uintptr_t)ptr;
	address = ft_itoa_base_uint(ptrint, 16);
	str = ft_strnew(ft_strlen(address) + 2);
	ft_strcpy(str, "0x");
	if (!(ptrint == 0 && active->precision == 0))
		ft_strcat(str, address);
	free(address);
	active->type = type;
	active->first_malloc = 1;
	apply_flags(str, ft_strlen(str), active, len);
}

void	conv_pct(char type, t_flag *active, va_list args, t_length *len)
{
	char	str[2];

	(void)args;
	str[0] = (unsigned char)type;
	str[1] = '\0';
	active->type = type;
	apply_flags(str, 1, active, len);
}
