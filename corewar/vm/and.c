/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:09:39 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:05:06 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	and(t_prog *pc, t_env *env)
{
	int	res;

	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	get_args_diff(pc, env);
	res = pc->arg[0] & pc->arg[1];
	if (res == 0)
		pc->carry = 1;
	else
	{
		if (pc->arg[2] - 1 < 16 && pc->arg[2] - 1 >= 0)
			pc->reg[pc->arg[2] - 1] = res;
		pc->carry = 0;
	}
}
