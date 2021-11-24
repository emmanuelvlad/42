/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:26:07 by evlad             #+#    #+#             */
/*   Updated: 2017/03/30 21:41:25 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		count(uintmax_t value, int base)
{
	int		len;

	len = 0;
	if (value == 0)
		len = 1;
	while (value != 0)
	{
		len++;
		value /= base;
	}
	return (len);
}

char			*ft_itoa_base_uint(uintmax_t value, int base)
{
	static char	rep[] = "0123456789abcdef";
	char		*str;
	int			len;

	len = count(value, base);
	str = ft_strnew(len + 1);
	if (value == 0)
		str[--len] = '0';
	while (value != 0)
	{
		str[--len] = rep[value % base];
		value /= base;
	}
	return (str);
}
