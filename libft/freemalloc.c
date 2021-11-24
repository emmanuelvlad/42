/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:57:14 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 22:46:33 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	freemalloc(char *buffer, t_flag *active, int realloc)
{
	if (active->first_malloc || active->second_malloc)
	{
		active->first_malloc = 0;
		active->second_malloc = 0;
		free(buffer);
	}
	if (realloc)
		active->second_malloc = 1;
}
