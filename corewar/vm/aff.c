/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:09:47 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:05:04 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	aff(t_prog *pc, t_env *env)
{
	char	ret;

	ret = 0;
	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	if (pc->acb != 64)
	{
		pc->pc_next = 3;
		return ;
	}
	pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
	pc->pc_next = 3;
	if (pc->arg[0] < 0 || pc->arg[0] > 16)
	{
		pc->carry = 1;
		return ;
	}
	ret = pc->reg[pc->arg[0] - 1] % 256;
	if (ret == 0)
		pc->carry = 1;
	else
	{
		ret = pc->reg[pc->arg[0] - 1] % 256;
		ft_putchar(ret);
		pc->carry = 0;
	}
}
