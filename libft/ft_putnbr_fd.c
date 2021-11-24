/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:14:00 by evlad             #+#    #+#             */
/*   Updated: 2016/11/09 10:25:58 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int tpeupastest;

	tpeupastest = n;
	if (tpeupastest < 0)
	{
		ft_putchar_fd('-', fd);
		tpeupastest = tpeupastest * -1;
	}
	if (tpeupastest >= 10)
	{
		ft_putnbr_fd(tpeupastest / 10, fd);
		ft_putchar_fd((tpeupastest % 10) + '0', fd);
	}
	else
		ft_putchar_fd(tpeupastest + '0', fd);
}
