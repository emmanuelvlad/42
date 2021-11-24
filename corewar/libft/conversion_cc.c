/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_cc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:11:37 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:22:28 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	display_arg_wchar(t_display d, wchar_t c)
{
	char	*tmp;
	int		len_r;

	len_r = (ft_wcharlen(c) > 0 ? ft_wcharlen(c) : 1);
	if (d.size > (int)ft_wcharlen(c))
	{
		len_r = (c != 0 ? d.size - (int)ft_wcharlen(c) : d.size - 1);
		tmp = ft_memset(ft_strnew(d.size), ' ', len_r);
		len_r = d.size;
	}
	else
		tmp = ft_strdup("");
	if (flag_left & d.flag)
	{
		ft_putwchar(c);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		return (len_r);
	}
	ft_putstr(tmp);
	ft_putwchar(c);
	ft_strdel(&tmp);
	return (len_r);
}

static int	display_arg_char(t_display d, char c)
{
	char	*tmp;
	int		len_r;
	char	flag_z;

	len_r = 1;
	if (d.size > len_r)
	{
		len_r = d.size;
		flag_z = (flag_0 & d.flag ? '0' : ' ');
		tmp = ft_memset(ft_strnew(d.size), flag_z, d.size - 1);
	}
	else
		tmp = ft_strdup("");
	if (flag_left & d.flag)
	{
		ft_putchar(c);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		return (len_r);
	}
	ft_putstr(tmp);
	ft_putchar(c);
	ft_strdel(&tmp);
	return (len_r);
}

static int	int_wchar(va_list ap, t_display d)
{
	wchar_t c;
	int		parse_len;

	c = (wchar_t)va_arg(ap, wint_t);
	parse_len = display_arg_wchar(d, c);
	return (parse_len);
}

int			int_char(va_list ap, char type, t_display d)
{
	char	c;
	int		parse_len;

	parse_len = 0;
	if (type == 'C')
		d.flag |= flag_l_conv;
	if (d.flag & flag_l_conv)
		return (int_wchar(ap, d));
	c = (unsigned char)va_arg(ap, int);
	parse_len = display_arg_char(d, c);
	return (parse_len);
}
