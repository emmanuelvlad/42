/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:52:29 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 18:13:55 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	int_to_chars_2(t_env *env, int i, char o[4])
{
	if (i == 4095)
	{
		env->arena[MODA(i)] = o[0];
		env->arena[0] = o[1];
		env->arena[1] = o[2];
		env->arena[2] = o[3];
	}
	else
	{
		env->arena[MODA(i)] = o[0];
		env->arena[MODA(i + 1)] = o[1];
		env->arena[MODA(i + 2)] = o[2];
		env->arena[MODA(i + 3)] = o[3];
	}
}

void	insert_color(t_env *env, int i, t_prog *tmp)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (i + j > 4095)
			i = -j;
		env->color[i + j] = tmp->champ_nb + 1;
		j++;
	}
}

void	int_to_chars(t_env *env, int i, int num, t_prog *pc)
{
	char	o[4];

	o[0] = num >> 24;
	o[1] = (num >> 16) & 0xFF;
	o[2] = (num >> 8) & 0xFF;
	o[3] = num & 0xFF;
	if (env->nc)
		insert_color(env, i, pc);
	if (i == 4093)
	{
		env->arena[MODA(i)] = o[0];
		env->arena[MODA(i + 1)] = o[1];
		env->arena[MODA(i + 2)] = o[2];
		env->arena[0] = o[3];
	}
	else if (i == 4094)
	{
		env->arena[MODA(i)] = o[0];
		env->arena[MODA(i + 1)] = o[1];
		env->arena[0] = o[2];
		env->arena[1] = o[3];
	}
	else
		int_to_chars_2(env, i, o);
}
