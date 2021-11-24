/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:49:28 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:24:48 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			p_arg(va_list ap, char type, t_display d)
{
	char		*str;
	uintmax_t	*nbr;
	int			len;

	d.flag |= flag_parse_alt;
	str = NULL;
	nbr = size_uint_ptr(ap, d);
	str = ft_itoa_base_max((uintmax_t)nbr, 16);
	type = 'x';
	if ((int)ft_strlen(str) < d.prec || str[0] == '0')
		str = prec_int(&str, d);
	str = display_arg_ptr(&str, d);
	str = ft_lowerstr(str);
	ft_putstr(str);
	len = (int)ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

uintmax_t	*size_uint_ptr(va_list ap, t_display d)
{
	uintmax_t *nbr;

	nbr = NULL;
	if (flag_j_conv & d.flag)
		nbr = (uintmax_t*)va_arg(ap, uintmax_t *);
	else if (flag_z_conv & d.flag)
		nbr = (uintmax_t*)va_arg(ap, size_t *);
	else if (flag_l_conv & d.flag)
		nbr = (uintmax_t*)va_arg(ap, unsigned long *);
	else if (flag_ll_conv & d.flag)
		nbr = (uintmax_t*)va_arg(ap, unsigned long long *);
	else
		nbr = (uintmax_t*)va_arg(ap, unsigned int *);
	return (nbr);
}

char		*display_arg_ptr(char **s, t_display d)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*s);
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
	tmp = parse_alt_ptr(&tmp, (int)ft_strlen(*s), d);
	ft_strdel(s);
	return (tmp);
}

char		*parse_alt_ptr(char **tmp, int len, t_display d)
{
	char	*s_a;

	s_a = ft_strdup("0x");
	if (len + 2 > d.size || flag_left & d.flag)
	{
		*tmp = ft_strjoin_free(s_a, *tmp, 1);
		if ((len > d.size || len + 2 <= d.size)
				&& flag_left & d.flag)
			ft_bzero(*tmp + (int)ft_strlen(*tmp) - 2, 2);
		else if (len + 2 > d.size && flag_left & d.flag)
			ft_bzero(*tmp + len + 2, 2);
	}
	else
		(*tmp[0] == '0' ? ft_strncpy(*tmp, s_a, 2) :
		ft_strncpy(*tmp + ft_strlen(*tmp) - len - 2, s_a, 2));
	ft_strdel(&s_a);
	return (*tmp);
}
