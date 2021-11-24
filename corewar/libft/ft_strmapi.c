/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:43:04 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/09 17:42:00 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*tmp;
	int		i;

	if (s)
	{
		len = ft_strlen(s);
		tmp = ft_strnew(len);
		if (tmp)
		{
			i = 0;
			while (s[i] != '\0')
			{
				tmp[i] = f(i, s[i]);
				i++;
			}
		}
		return (tmp);
	}
	return (NULL);
}
