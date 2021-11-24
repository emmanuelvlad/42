/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:53:02 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:05:46 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	hex_sum2(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
	int				a1;
	int				b1;
	int				c1;
	int				d1;
	unsigned int	res;

	a1 = (int)a << 8 * 3;
	b1 = (int)b << 8 * 2;
	c1 = (int)c << 8;
	d1 = (int)d;
	res = a1 + b1 + c1 + d1;
	return ((int)res);
}

int	hex_sum(unsigned char a, unsigned char b)
{
	int		a1;
	int		b1;
	int		res;

	a1 = (int)a << 8;
	b1 = (int)b;
	res = a1 + b1;
	return (res);
}
