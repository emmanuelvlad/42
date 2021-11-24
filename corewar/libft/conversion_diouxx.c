/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_diouxx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:44:06 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:23:42 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			int_arg(va_list ap, char type, t_display d)
{
	uintmax_t	nbr;
	char		*str;

	str = NULL;
	if (type == 'd' || type == 'i')
		str = ft_itoa_max(size_int(ap, d));
	else
	{
		nbr = size_uint(ap, d);
		if (type == 'o')
			str = ft_itoa_base_max(nbr, 8);
		else if (type == 'u')
			str = ft_itoa_base_max(nbr, 10);
		else if (type == 'x' || type == 'X')
			str = ft_itoa_base_max(nbr, 16);
	}
	if ((int)ft_strlen(str) < d.prec || str[0] == '0')
		str = prec_int(&str, d);
	str = display_arg(&str, d, type);
	str = (type == 'x' ? ft_lowerstr(str) : str);
	ft_putstr(str);
	nbr = (int)ft_strlen(str);
	ft_strdel(&str);
	return ((int)nbr);
}

char		*prec_int(char **s, t_display d)
{
	char	*tmp;
	int		sgn;
	int		len;

	len = (int)ft_strlen(*s);
	sgn = 0;
	if (*s[0] == '-')
		sgn = 1;
	if (d.prec != -1)
	{
		tmp = ft_strnew(d.prec + sgn);
		ft_memset(tmp, '0', d.prec + sgn);
		if (sgn == 1)
			tmp = ft_strjoin_free("-", tmp, 1);
		if (d.prec > (int)ft_strlen(*s))
			ft_strncpy(tmp + (int)ft_strlen(tmp) - len, *s + sgn, len);
		if (ft_atoi(*s) != 0)
			ft_strdel(s);
		return (tmp);
	}
	return (*s);
}

void		parse_sgn(char **tmp, char **s, t_display d)
{
	char	*sgn;

	sgn = (*s[0] == '-' ? "-" : "+");
	if (flag_space & d.flag && !(flag_pos & d.flag))
		sgn = " ";
	if (flag_0 & d.flag && ((!(flag_space & d.flag) && !(flag_left & d.flag))
				|| ft_atoi(*s) == 0))
	{
		if (*sgn == '-')
			*(ft_strchr(*tmp, '-')) = '0';
		if (flag_pos & d.flag || *sgn == '-')
			*tmp[0] = *sgn;
		else if (flag_space & d.flag)
			*tmp[0] = ' ';
	}
	else if ((flag_pos & d.flag || flag_space & d.flag) && *sgn != '-')
	{
		sgn = ft_strjoin(sgn, *s);
		if (!(flag_left & d.flag))
			ft_strncpy(*tmp + ft_strlen(*tmp) - (ft_strlen(*s) + 1),
					sgn, ft_strlen(*s) + 1);
		else if (flag_left & d.flag)
			ft_strncpy(*tmp, sgn, ft_strlen(*s) + 1);
		ft_strdel(&sgn);
	}
}

void		parse_alt_bis(t_display d, char *s, char **tmp, char *s_a)
{
	int	l_a;

	l_a = (int)ft_strlen(s_a);
	*tmp = ft_strjoin_free(s_a, *tmp, 1);
	if (((int)ft_strlen(s) > d.size || (int)ft_strlen(s) + l_a <= d.size)
			&& flag_left & d.flag)
		ft_bzero(*tmp + (int)ft_strlen(*tmp) - l_a, l_a);
	else if ((int)ft_strlen(s) + l_a > d.size && flag_left & d.flag)
		ft_bzero(*tmp + (int)ft_strlen(s) + l_a, l_a);
}

char		*parse_alt(char **tmp, char *s, char type, t_display d)
{
	char	*s_a;
	int		l_a;

	if ((type == 'x' || type == 'X') && *s != '\0')
		s_a = ft_strdup("0X");
	else
		s_a = (type == 'o' ? ft_strdup("0") : ft_strdup(""));
	l_a = (int)ft_strlen(s_a);
	if (((type == 'x' || type == 'X') || type == 'o') && ft_atoi(s) != 0)
	{
		if ((ft_strlen(s) + l_a > (size_t)d.size || flag_left & d.flag) &&
				!(type == 'o' && s[0] == '0'))
			parse_alt_bis(d, s, tmp, s_a);
		else
			(*tmp[0] == '0' ? ft_strncpy(*tmp, s_a, l_a) : ft_strncpy(*tmp +
			ft_strlen(*tmp) - ft_strlen(s) - l_a, s_a, l_a));
	}
	if (type == 'o' && ft_atoi(s) == 0)
		*tmp = ft_strdup("0");
	ft_strdel(&s_a);
	return (*tmp);
}
