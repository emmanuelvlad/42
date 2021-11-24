/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:48:58 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:25:06 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		str_arg(va_list ap, char type, t_display d)
{
	char	*s;
	int		parse_len;

	if (type == 'S' || d.flag & flag_l_conv)
		return (wstr_arg(ap, d));
	s = va_arg(ap, char*);
	if (s == NULL)
		s = "(null)";
	parse_len = 0;
	if (d.prec != -1 && d.prec < (int)ft_strlen(s))
		s = ft_strsub(s, 0, d.prec);
	parse_len = display_arg_str(d, s);
	return (parse_len);
}

int		wstr_arg(va_list ap, t_display d)
{
	int		parse_len;
	wchar_t	*s;

	parse_len = 0;
	s = va_arg(ap, wchar_t*);
	if (s == NULL)
		s = L"(null)";
	s = parse_wprec(s, d);
	parse_len = display_arg_wstr(d, s);
	return (parse_len);
}

int		display_arg_str(t_display d, char *s)
{
	char	*tmp;
	int		len_r;

	len_r = ft_strlen(s);
	tmp = ft_strdup("");
	if (d.size > (int)ft_strlen(s))
	{
		len_r = d.size;
		ft_strdel(&tmp);
		tmp = ft_memset(ft_strnew(d.size), (flag_0 & d.flag &&
				!(flag_left & d.flag)) ? '0' : ' ', d.size - ft_strlen(s));
	}
	if (flag_left & d.flag)
	{
		ft_putstr(s);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		return (len_r);
	}
	ft_putstr(tmp);
	ft_putstr(s);
	ft_strdel(&tmp);
	return (len_r);
}

wchar_t	*parse_wprec(wchar_t *s, t_display d)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (d.prec != -1 && d.prec < (int)ft_strwttlen(s))
	{
		while (k < d.prec)
		{
			i += ft_wcharlen(*(s + k));
			if (i > d.prec)
				break ;
			k++;
		}
		s = ft_strwsub(s, 0, k);
	}
	return (s);
}

int		display_arg_wstr(t_display d, wchar_t *s)
{
	char	*tmp;
	int		len_r;

	len_r = (int)ft_strwttlen(s);
	tmp = ft_strdup("");
	if (d.size > (int)ft_strwttlen(s))
	{
		len_r = (*s != 0 ? d.size - len_r : d.size);
		ft_strdel(&tmp);
		tmp = ft_memset(ft_strnew(d.size), (flag_0 & d.flag &&
				!(flag_left & d.flag)) ? '0' : ' ', len_r);
		len_r = d.size;
	}
	if (flag_left & d.flag)
	{
		ft_putwstr(s);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		return (len_r);
	}
	ft_putstr(tmp);
	ft_putwstr(s);
	ft_strdel(&tmp);
	return (len_r);
}
