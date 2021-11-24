/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:25:11 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 22:35:01 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (little[0] == '\0')
		return ((char*)&big[0]);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		k = i;
		while (little[j] == big[i] && little[j] != '\0' && i < len)
		{
			if (little[j + 1] == '\0')
				return ((char*)&big[k]);
			i++;
			j++;
		}
		if (j == 0)
			i++;
	}
	return (NULL);
}
