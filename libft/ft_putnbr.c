/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:04:20 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 18:43:12 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		ft_putchar('-');
		tmp = tmp * -1;
	}
	if (tmp >= 10)
	{
		ft_putnbr(tmp / 10);
		ft_putchar((tmp % 10) + '0');
	}
	else
		ft_putchar(tmp + '0');
}
