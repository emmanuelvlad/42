/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:43:01 by evlad             #+#    #+#             */
/*   Updated: 2021/12/03 17:51:26 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_length	*init_length(void)
{
	t_length	*length;

	length = (t_length *)malloc(sizeof(t_length));
	if (!length)
		return (NULL);
	length->len = 0;
	return (length);
}

t_flag	*init_flag(void)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->diese = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->space = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->j = 0;
	flag->z = 0;
	flag->length = 0;
	flag->type = 0;
	flag->first_malloc = 0;
	flag->second_malloc = 0;
	flag->null = 0;
	flag->buff = NULL;
	return (flag);
}
