/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:26:07 by evlad             #+#    #+#             */
/*   Updated: 2017/04/03 19:04:46 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		count(intmax_t value, int base)
{
	int		len;

	len = 0;
	if (value <= 0)
	{
		len = 1;
		value *= -1;
	}
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(intmax_t value, int base)
{
	static char	rep[] = "0123456789abcdef";
	char		*str;
	int			len;
	intmax_t	dup;

	dup = value;
	len = count(value, base);
	str = ft_strnew(len);
	str[len] = '\0';
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		str[--len] = '0';
	while (value != 0)
	{
		str[--len] = rep[value % base];
		value /= 10;
	}
	if (dup < 0 && base == 10)
		str[--len] = '-';
	return (str);
}
