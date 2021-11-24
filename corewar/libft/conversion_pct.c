/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:34:54 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:24:33 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pct_arg(va_list ap, char type, t_display d)
{
	char	*pct;
	int		parse_len;

	(void)type;
	(void)ap;
	pct = ft_strnew(1);
	parse_len = 0;
	pct[0] = type;
	parse_len = display_arg_pct(d, pct);
	ft_strdel(&pct);
	return (parse_len);
}

int		display_arg_pct(t_display d, char *c)
{
	char	*tmp;
	int		len_r;

	len_r = 1;
	tmp = ft_strdup("");
	if (d.size > (int)ft_strlen(c))
	{
		len_r = d.size;
		tmp = ft_memset(ft_strnew(d.size), (flag_0 & d.flag
			&& !(flag_left & d.flag)) ? '0' : ' ', d.size - 1);
	}
	if (flag_left & d.flag)
	{
		ft_putstr(c);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		return (len_r);
	}
	ft_putstr(tmp);
	ft_putstr(c);
	ft_strdel(&tmp);
	return (len_r);
}
