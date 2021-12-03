/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:25:51 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 18:21:15 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*retour;
	size_t	i;

	if (!(s))
		return (NULL);
	i = 0;
	retour = (char *)malloc(sizeof(char) * (len + 1));
	if (!retour)
		return (NULL);
	while (i < len)
	{
		retour[i] = s[start];
		i++;
		start++;
	}
	retour[i] = '\0';
	return (retour);
}
