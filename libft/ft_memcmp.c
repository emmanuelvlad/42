/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:26:04 by evlad             #+#    #+#             */
/*   Updated: 2017/04/21 12:26:59 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	cs1;
	unsigned char	cs2;

	while (n != 0)
	{
		cs1 = *(unsigned char*)s1;
		cs2 = *(unsigned char*)s2;
		if (cs1 != cs2)
			return (cs1 - cs2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
