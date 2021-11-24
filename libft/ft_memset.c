/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:08:07 by evlad             #+#    #+#             */
/*   Updated: 2016/11/09 13:41:16 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy;
	size_t			i;

	copy = b;
	i = 0;
	while (len > i)
	{
		copy[i] = (unsigned char)c;
		i++;
	}
	return (copy);
}
