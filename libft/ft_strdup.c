/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:45:51 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 18:44:42 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(src) + 1;
	if (src == NULL)
		return (NULL);
	copy = (char *)malloc(sizeof(*src) * len);
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, (char *)src);
	return ((char *)copy);
}
