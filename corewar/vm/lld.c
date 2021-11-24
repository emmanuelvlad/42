/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:42:49 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:06:06 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	arg_ld(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b11010000)
	{
		pc->arg[0] = hex_sum(env->arena[MODA(pc->pc_position + 2)], env->arena[
			MODA(pc->pc_position + 3)]);
		pc->arg[1] = env->arena[MODA(pc->pc_position + 4)];
		pc->pc_next = 5;
	}
	if (pc->acb == 0b10010000)
	{
		pc->arg[0] = hex_sum2(env->arena[MODA(pc->pc_position + 2)], env->arena[
			MODA(pc->pc_position + 3)], env->arena[MODA(pc->pc_position + 4)],
			env->arena[MODA(pc->pc_position + 5)]);
		pc->arg[1] = env->arena[MODA(pc->pc_position + 6)];
		pc->pc_next = 7;
	}
}

void		lld(t_prog *pc, t_env *env)
{
	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	arg_ld(pc, env);
	if (pc->arg[0] != 0)
	{
		pc->reg[pc->arg[1] - 1] = pc->arg[0];
		pc->carry = 0;
	}
	else
		pc->carry = 1;
}
