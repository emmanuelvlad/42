/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:26:32 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:07:48 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	sub(t_prog *pc, t_env *env)
{
	int	res;

	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	get_3regs(pc, env);
	res = pc->reg[pc->arg[0] - 1] - pc->reg[pc->arg[1] - 1];
	if (is_reg(pc->arg[0], pc->arg[1], pc->arg[2]))
	{
		if (res != 0)
		{
			pc->carry = 1;
			pc->reg[pc->arg[2] - 1] = res;
		}
		else
			pc->carry = 0;
	}
	pc->pc_next = 5;
}
