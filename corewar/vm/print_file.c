/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:40:16 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 18:10:45 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	put_hexa(unsigned char h)
{
	const char	hex[17] = "0123456789abcdef";
	char		hex_big;
	char		hex_small;

	hex_big = hex[(h / 16)];
	hex_small = hex[h % 16];
	ft_putchar(hex_big);
	ft_putchar(hex_small);
}

void		print_file(unsigned char *file, int tot_char)
{
	int j;

	j = 0;
	ft_putstr("0x0000 : ");
	while (j < tot_char)
	{
		put_hexa(*(file + j));
		j++;
		if (j % 64 == 0)
		{
			ft_putchar(' ');
			ft_putchar('\n');
			ft_putstr("0x");
			ft_printf("%04x : ", j);
		}
		else
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
