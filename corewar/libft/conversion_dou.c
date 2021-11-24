/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_dou.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:45:48 by fpipart           #+#    #+#             */
/*   Updated: 2017/01/03 14:24:17 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lint_arg(va_list ap, char type, t_display d)
{
	d.flag |= flag_l_conv;
	if (type == 'D')
		type = 'd';
	else if (type == 'O')
		type = 'o';
	else if (type == 'U')
		type = 'u';
	return (int_arg(ap, type, d));
}
