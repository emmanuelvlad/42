/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwttlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 12:50:14 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/31 12:48:46 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strwttlen(const wchar_t *c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (c[j])
	{
		if (c[j] <= 0x7F)
			i++;
		else if (c[j] <= 0x7FF)
			i += 2;
		else if (c[j] <= 0xFFFF)
			i += 3;
		else if (c[j] <= 0x10FFFF)
			i += 4;
		j++;
	}
	return (i);
}
