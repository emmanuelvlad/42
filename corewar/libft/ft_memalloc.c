/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:17:40 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/08 15:21:21 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *s;

	s = (void*)malloc(sizeof(*s) * size);
	if (s)
	{
		ft_memset(s, 0, size);
		return (s);
	}
	return (NULL);
}
