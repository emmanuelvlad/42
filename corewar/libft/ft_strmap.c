/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:59:28 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/09 17:41:17 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				tmp[i] = f(s[i]);
				i++;
			}
		}
		return (tmp);
	}
	return (NULL);
}
