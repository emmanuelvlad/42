/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:46:54 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 18:38:12 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*retour;

	retour = (char *)malloc(sizeof(char) * (size + 1));
	if (!retour)
		return (NULL);
	ft_bzero(retour, size + 1);
	return (retour);
}
