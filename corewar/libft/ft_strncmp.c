/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:10:38 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/12 09:48:37 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	while (i < n && c1[i])
	{
		if (c1[i] != c2[i] || !c1[i])
			return (c1[i] - c2[i]);
		i++;
	}
	if (i == n)
		return (c1[i - 1] - c2[i - 1]);
	return (c1[i] - c2[i]);
}
