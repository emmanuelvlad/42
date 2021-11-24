/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:22:29 by evlad             #+#    #+#             */
/*   Updated: 2017/04/12 14:27:09 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= 0x70F)
			length++;
		else if (str[i] <= 0x7FF)
			length += 2;
		else if (str[i] <= 0xFFFF)
			length += 3;
		else if (str[i] <= 0x10FFFF)
			length += 4;
		i++;
	}
	return (length);
}
