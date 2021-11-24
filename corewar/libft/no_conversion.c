/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:04:21 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:25:34 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		no_conversion(t_display d)
{
	char	*s;
	int		len;

	s = ft_strnew((d.size - 1 > 0 ? d.size : 0));
	if (flag_0 & d.flag && d.prec == -1 && !(flag_left & d.flag))
		s = ft_memset(s, '0',
				sizeof(char) * ((d.size - 1) > 0 ? d.size - 1 : 0));
	else
		s = ft_memset(s, ' ',
				sizeof(char) * ((d.size - 1) > 0 ? d.size - 1 : 0));
	ft_putstr(s);
	len = ft_strlen(s);
	ft_strdel(&s);
	return (len);
}
