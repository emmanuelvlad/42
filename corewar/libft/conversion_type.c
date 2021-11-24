/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:15:54 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:23:17 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		conversion_type(va_list ap, char type, t_display d)
{
	int					i;
	static const t_fun	conv[] = {
		{ "diouxX", &int_arg },
		{ "DOU", &lint_arg },
		{ "cC", &int_char },
		{ "p", &p_arg },
		{ "sS", &str_arg },
		{ "%Z", &pct_arg },
	};

	i = 0;
	while (i < 6)
	{
		if (ft_strchr(conv[i].s, type))
		{
			return (conv[i].f(ap, type, d));
		}
		i++;
	}
	return (-1);
}

t_flag	display_control(const char *flag, const t_content disp[11])
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (ft_strchr(disp[i].s, flag[0]))
		{
			if (flag[0] == 'h' && flag[1] == 'h')
				return (flag_hh_conv);
			else if (flag[0] == 'l' && flag[1] == 'l')
				return (flag_ll_conv);
			else
				return (disp[i].v);
		}
		i++;
	}
	return (0);
}

t_flag	fill_flag(const char *flag)
{
	static const t_content disp[] = {
		{ "#", flag_parse_alt},
		{ "0", flag_0},
		{ "-", flag_left},
		{ "+", flag_pos},
		{ " ", flag_space},
		{ "j", flag_j_conv},
		{ "z", flag_z_conv},
		{ "h", flag_h_conv},
		{ "hh", flag_hh_conv},
		{ "l", flag_l_conv},
		{ "ll", flag_ll_conv},
	};

	return (display_control(flag, disp));
}
