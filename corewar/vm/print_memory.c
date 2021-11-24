/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:22:40 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:07:40 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_number(const unsigned int *addr, size_t size)
{
	size_t		i;
	const char	nb[17] = "0123456789abcdef";

	i = 0;
	while (i < size)
	{
		ft_putchar(nb[((*(addr + i)) / 16) % 16]);
		ft_putchar(nb[(*(addr + i)) % 16]);
		i++;
		if (i % 16 == 0 && i > 1)
			ft_putchar('\n');
		else if (i % 2 == 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	print_memory(const void *addr, size_t size)
{
	print_number((const unsigned int *)addr, size);
}
