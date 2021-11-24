/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:16:06 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/23 11:17:03 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

wchar_t	*ft_strwnew(size_t size)
{
	wchar_t *s;

	s = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1));
	if (s)
	{
		ft_memset(s, '\0', sizeof(wchar_t) * (size + 1));
		return (s);
	}
	return (NULL);
}
