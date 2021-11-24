/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:56:34 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/12 10:09:29 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	if (n == 0)
		return (dst);
	s1 = (char*)dst;
	s2 = (char*)src;
	while (n--)
		s1[n] = s2[n];
	return (dst);
}
