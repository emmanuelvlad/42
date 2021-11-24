/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:12:39 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 22:46:19 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t	signed_cast(va_list args, t_flag *active)
{
	intmax_t nb;

	nb = 0;
	if (active->z)
		nb = va_arg(args, size_t);
	else if (active->j)
		nb = va_arg(args, intmax_t);
	else if (active->ll)
		nb = va_arg(args, long long int);
	else if (active->l)
		nb = va_arg(args, long int);
	else if (active->hh)
		nb = (char)va_arg(args, int);
	else if (active->h)
		nb = (short)va_arg(args, int);
	return (nb);
}

uintmax_t	unsigned_cast(va_list args, t_flag *active)
{
	uintmax_t nb;

	nb = 0;
	if (active->z)
		nb = va_arg(args, ssize_t);
	else if (active->j)
		nb = va_arg(args, uintmax_t);
	else if (active->ll)
		nb = va_arg(args, unsigned long long int);
	else if (active->l)
		nb = va_arg(args, unsigned long int);
	else if (active->hh)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if (active->h)
		nb = (unsigned short)va_arg(args, unsigned int);
	return (nb);
}
