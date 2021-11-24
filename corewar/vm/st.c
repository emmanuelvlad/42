/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:32:53 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 18:11:16 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	st(t_prog *pc, t_env *env)
{
	int		adress;

	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	if (pc->acb == 0b01010000)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(env->arena[MODA(pc->pc_position + 3)]);
		pc->pc_next = 4;
		pc->reg[pc->arg[1] - 1] = pc->reg[pc->arg[0] - 1];
	}
	if (pc->acb == 0b01110000)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = hex_sum(env->arena[MODA(pc->pc_position + 3)],
			env->arena[MODA(pc->pc_position + 4)]);
		adress = pc->pc_position + MODR(neg(pc->arg[1]));
		if (adress < 0)
			adress = 4096 + adress;
		adress = MODA(adress);
		if (pc->arg[0] > 0 && pc->arg[0] <= 16)
			int_to_chars(env, adress, pc->reg[pc->arg[0] - 1], pc);
		pc->pc_next = 5;
	}
}
