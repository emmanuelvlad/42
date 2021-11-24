/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:26:49 by evlad             #+#    #+#             */
/*   Updated: 2016/11/11 15:10:19 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retour;
	int		i;

	if ((!(s1)) || (!(s2)))
		return (NULL);
	i = 0;
	retour = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (retour == NULL)
		return (NULL);
	while (*s1)
		retour[i++] = *s1++;
	while (*s2)
		retour[i++] = *s2++;
	retour[i] = '\0';
	return (retour);
}
