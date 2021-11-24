/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:49:59 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:05:48 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		arg_ld(t_prog *pc, t_env *env)
{
	int		adr;

	pc->arg[0] = 0;
	if (pc->acb == 0b11010000)
	{
		adr = MODA(pc->pc_position + hex_sum(env->arena[MODA(pc->pc_position +
			2)], env->arena[MODA(pc->pc_position + 3)]));
		if (adr == 0)
			pc->arg[0] = 0;
		pc->arg[0] = MODR(hex_sum2(env->arena[MODA(adr)], env->arena[MODA(adr +
					1)], env->arena[MODA(adr + 2)], env->arena[MODA(adr + 3)]));
		pc->arg[1] = env->arena[MODA(pc->pc_position + 4)];
		pc->pc_next = 5;
	}
	if (pc->acb == 0b10010000)
	{
		adr = hex_sum2(env->arena[MODA(pc->pc_position + 2)], env->arena[
			MODA(pc->pc_position + 3)], env->arena[MODA(pc->pc_position + 4)],
			env->arena[MODA(pc->pc_position + 5)]);
		if (adr == 0)
			pc->arg[0] = 0;
		pc->arg[0] = adr;
		pc->arg[1] = env->arena[MODA(pc->pc_position + 6)];
		pc->pc_next = 7;
	}
}

void			ld(t_prog *pc, t_env *env)
{
	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	arg_ld(pc, env);
	if (pc->arg[0] != 0)
	{
		if (pc->arg[1] > 0 && pc->arg[1] <= 16)
			pc->reg[pc->arg[1] - 1] = pc->arg[0];
		else
			pc->carry = 0;
	}
	else
		pc->carry = 1;
}
