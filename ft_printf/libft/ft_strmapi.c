/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:23:46 by evlad             #+#    #+#             */
/*   Updated: 2016/11/11 15:08:48 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*retour;

	i = 0;
	retour = NULL;
	if ((!(s)) || (!(f)))
		return (NULL);
	if (!(retour = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (i != ft_strlen(s))
	{
		retour[i] = f(i, s[i]);
		i++;
	}
	retour[i] = '\0';
	return (retour);
}
