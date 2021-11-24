/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:26:22 by evlad             #+#    #+#             */
/*   Updated: 2017/07/20 10:50:41 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	xor(t_prog *pc, t_env *env)
{
	int	res;

	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	get_args_diff(pc, env);
	res = pc->arg[0] ^ pc->arg[1];
	if (res == 0)
		pc->carry = 1;
	else
	{
		if (pc->arg[2] > 0 && pc->arg[2] <= 16)
			pc->reg[pc->arg[2]] = res;
		pc->carry = 0;
	}
}
