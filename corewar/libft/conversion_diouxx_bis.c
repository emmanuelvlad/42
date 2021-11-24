/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_diouxx_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:29:31 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:23:58 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	size_int(va_list ap, t_display d)
{
	intmax_t	nbr;

	if (flag_j_conv & d.flag)
		nbr = va_arg(ap, intmax_t);
	else if (flag_z_conv & d.flag)
		nbr = va_arg(ap, size_t);
	else if (flag_ll_conv & d.flag)
		nbr = va_arg(ap, long long);
	else if (flag_l_conv & d.flag)
		nbr = va_arg(ap, long);
	else if (flag_hh_conv & d.flag)
		nbr = (char)va_arg(ap, int);
	else if (flag_h_conv & d.flag)
		nbr = (short)va_arg(ap, int);
	else
		nbr = va_arg(ap, int);
	return (nbr);
}

uintmax_t	size_uint(va_list ap, t_display d)
{
	intmax_t	nbr;

	if (flag_j_conv & d.flag)
		nbr = va_arg(ap, uintmax_t);
	else if (flag_z_conv & d.flag)
		nbr = va_arg(ap, size_t);
	else if (flag_ll_conv & d.flag)
		nbr = va_arg(ap, unsigned long long);
	else if (flag_l_conv & d.flag)
		nbr = va_arg(ap, unsigned long);
	else if (flag_hh_conv & d.flag)
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (flag_h_conv & d.flag)
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else
		nbr = va_arg(ap, unsigned int);
	return (nbr);
}

char		*display_arg(char **s, t_display d, char type)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*s);
	if (((flag_pos & d.flag) || (flag_space & d.flag)) && *s[0] != '-'
			&& (type == 'd' || type == 'i'))
		len++;
	if (d.size > len)
		len = d.size;
	tmp = ft_strnew(len);
	if (flag_0 & d.flag && d.prec == -1 && !(flag_left & d.flag))
		tmp = ft_memset(tmp, '0', sizeof(char) * len);
	else
		tmp = ft_memset(tmp, ' ', sizeof(char) * len);
	if (flag_left & d.flag)
		ft_strncpy(tmp, *s, ft_strlen(*s));
	else
		ft_strncpy(tmp + len - ft_strlen(*s), *s, ft_strlen(*s));
	if ((flag_pos & d.flag || flag_space & d.flag || flag_0 & d.flag)
			&& (type == 'd' || type == 'i'))
		parse_sgn(&tmp, s, d);
	if (flag_parse_alt & d.flag)
		tmp = parse_alt(&tmp, *s, type, d);
	ft_strdel(s);
	return (tmp);
}
