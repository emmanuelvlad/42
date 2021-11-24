/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:39:59 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/11 16:17:12 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	tmp = (char*)malloc(sizeof(const char) * (len + 1));
	if (tmp)
	{
		while (i < len)
		{
			tmp[i] = s1[i];
			i++;
		}
		tmp[len] = '\0';
		return (tmp);
	}
	return (NULL);
}
