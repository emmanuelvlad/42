/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:10:03 by evlad             #+#    #+#             */
/*   Updated: 2016/12/03 10:06:24 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_colorit(char *result)
{
	int		c;

	c = 0;
	while (*result)
	{
		c = (int)*result - 65;
		if (c < 0)
			c = 0;
		else if (c > 6)
			c = 31 + (c % 6);
		else
			c = c + 31;
		ft_putstr("\x1B[");
		ft_putnbr(c);
		ft_putchar('m');
		ft_putchar(*result);
		result++;
	}
	ft_putstr("\x1B[0m");
}
