/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:25:27 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:07:50 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	zjmp(t_prog *pc, t_env *env)
{
	int	res;

	if (pc->carry == 1)
	{
		pc->arg[0] = hex_sum(env->arena[MODA(pc->pc_position + 1)],
			env->arena[MODA(pc->pc_position + 2)]);
		res = pc->pc_position + MODR(neg(pc->arg[0]));
		pc->pc_position = MODA(res);
		pc->pc_next = 0;
	}
	else
		pc->pc_next = 3;
}
