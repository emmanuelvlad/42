/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:14:00 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 18:45:10 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = tmp * -1;
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putchar_fd((tmp % 10) + '0', fd);
	}
	else
		ft_putchar_fd(tmp + '0', fd);
}
