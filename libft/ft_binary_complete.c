/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_complete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:04:38 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 22:49:59 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_binary_complete(char *str)
{
	char	*newstr;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (len < 4)
	{
		newstr = ft_strnew(4);
		ft_strcpy(newstr + (4 - len), str);
		free(str);
		while ((4 - len) > i)
		{
			newstr[i] = '0';
			i++;
		}
	}
	else
		newstr = str;
	return (newstr);
}
