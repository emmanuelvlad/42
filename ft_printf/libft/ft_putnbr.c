/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:04:20 by evlad             #+#    #+#             */
/*   Updated: 2016/11/09 10:34:20 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int mdrptdr;

	mdrptdr = n;
	if (mdrptdr < 0)
	{
		ft_putchar('-');
		mdrptdr = mdrptdr * -1;
	}
	if (mdrptdr >= 10)
	{
		ft_putnbr(mdrptdr / 10);
		ft_putchar((mdrptdr % 10) + '0');
	}
	else
		ft_putchar(mdrptdr + '0');
}
