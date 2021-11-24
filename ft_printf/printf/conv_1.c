/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:28 by evlad             #+#    #+#             */
/*   Updated: 2017/04/12 14:58:35 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	conv(char type, t_flag *active, va_list args, t_length *len)
{
	int					i;
	static const t_conv	g_conv[] = {
		{ "bdiouxX", &conv_int },
		{ "DOU", &conv_dou },
		{ "Cc", &conv_c },
		{ "s", &conv_s },
		{ "S", &conv_ws },
		{ "p", &conv_p },
		{ "%ZR", &conv_pct }
	};

	i = 0;
	while (i < 7)
	{
		if (ft_strchr(g_conv[i].type, type))
			g_conv[i].function(type, active, args, len);
		i++;
	}
}

char	*sized_oux_int(va_list args, t_flag *active)
{
	uintmax_t	u_int;

	active->first_malloc = 1;
	u_int = unsigned_cast(args, active);
	if (active->type == 'o')
		return (ft_itoa_base_uint(u_int, 8));
	else if (active->type == 'u')
		return (ft_itoa_base_uint(u_int, 10));
	else if (active->type == 'X')
		return (ft_strtoupper(ft_itoa_base_uint(u_int, 16)));
	return (ft_itoa_base_uint(u_int, 16));
}

char	*other_int(va_list args, t_flag *active)
{
	active->first_malloc = 1;
	if (active->type == 'b')
		return (ft_binary_complete(ft_itoa_base_uint(va_arg(args, int), 2)));
	else if (active->type == 'o')
		return (ft_itoa_base_uint((va_arg(args, unsigned int)), 8));
	else if (active->type == 'u')
		return (ft_itoa_base_uint(va_arg(args, unsigned int), 10));
	else if (active->type == 'x')
		return (ft_itoa_base_uint(va_arg(args, unsigned int), 16));
	else if (active->type == 'X')
	{
		return (ft_strtoupper(
					ft_itoa_base_uint(va_arg(args, unsigned int), 16)));
	}
	return (ft_itoa_base(va_arg(args, int), 10));
}

void	conv_int(char type, t_flag *active, va_list args, t_length *len)
{
	intmax_t	s_int;
	int			length;
	char		*str;

	active->type = type;
	s_int = 0;
	if (check_size(active) && ft_strchr("di", active->type))
	{
		s_int = signed_cast(args, active);
		if (s_int == -9223372036854775807 - 1)
			str = "-9223372036854775808";
		else
		{
			active->first_malloc = 1;
			str = ft_itoa_base(s_int, 10);
		}
	}
	else if (check_size(active) && ft_strchr("ouxX", active->type))
		str = sized_oux_int(args, active);
	else
		str = other_int(args, active);
	length = ft_strlen(str);
	apply_flags(str, length, active, len);
}

void	conv_s(char type, t_flag *active, va_list args, t_length *len)
{
	char	*str;
	int		length;

	if (!active->l)
		str = va_arg(args, char*);
	else
		return (conv_ws(type, active, args, len));
	if (str == NULL)
		str = "(null)";
	length = ft_strlen(str);
	active->type = type;
	apply_flags(str, length, active, len);
}
