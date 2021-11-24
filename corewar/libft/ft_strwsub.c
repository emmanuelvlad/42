/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:35:41 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/23 17:42:57 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

wchar_t	*ft_strwsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	tmp = (wchar_t*)malloc(sizeof(wchar_t) * len + 1);
	if (!tmp)
		return (NULL);
	while (len-- && (s + start + i) && (tmp + i))
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
