/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:11:17 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:05:00 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	get_3regs(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b01010100)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = env->arena[MODA(pc->pc_position + 3)];
		pc->arg[2] = env->arena[MODA(pc->pc_position + 4)];
	}
}

int		is_reg(int arg1, int arg2, int arg3)
{
	if (arg1 > 0 && arg1 < 17 && arg2 > 0 && arg2 < 17 && arg3 > 0 && arg3 < 17)
		return (1);
	return (0);
}

void	add(t_prog *pc, t_env *env)
{
	int		res;

	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	get_3regs(pc, env);
	if (pc->arg[0] - 1 >= 0 && pc->arg[0] - 1 < 16
	&& pc->arg[1] - 1 >= 0 && pc->arg[1] - 1 < 16
	&& is_reg(pc->arg[0], pc->arg[1], pc->arg[2]))
	{
		res = pc->reg[pc->arg[0] - 1] + pc->reg[pc->arg[1] - 1];
		if (res == 0)
			pc->carry = 1;
		else
		{
			pc->reg[pc->arg[2] - 1] = res;
			pc->carry = 0;
		}
	}
	pc->pc_next = 5;
}
