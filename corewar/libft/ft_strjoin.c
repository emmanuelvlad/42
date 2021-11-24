/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:40:01 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/09 17:56:02 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*new;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		new = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (new)
		{
			i = -1;
			while (++i < len_s1)
				new[i] = s1[i];
			j = 0;
			while (j < len_s2)
				new[i++] = s2[j++];
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}
