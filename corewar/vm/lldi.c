/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:42:02 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:06:09 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		get_adress2(t_prog *pc)
{
	int	adress;

	adress = 0;
	if (pc->acb == 0b01100100)
		adress = pc->reg[pc->arg[0] - 1] + pc->arg[1];
	else if (pc->acb == 0b01010100)
		adress = pc->reg[pc->arg[0] - 1] + pc->reg[pc->arg[1] - 1];
	else if (pc->acb == 0b10100100)
		adress = pc->arg[0] + pc->arg[1];
	else if (pc->acb == 0b10010100)
		adress = pc->arg[0] + pc->reg[pc->arg[1] - 1];
	else if (pc->acb == 0b11100100)
		adress = MODA(pc->pc_position + pc->arg[0]) + pc->arg[1];
	else if (pc->acb == 0b11010100)
		adress = MODA(pc->pc_position + pc->arg[0]) + pc->reg[pc->arg[1] - 1];
	return (adress);
}

void	lldi(t_prog *pc, t_env *env)
{
	int		adress;

	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	get_args_diff(pc, env);
	adress = pc->pc_position + get_adress2(pc);
	if (adress == 0)
		pc->carry = 1;
	else
	{
		pc->reg[pc->arg[2] - 1] = hex_sum2(MODA(adress), MODA(adress + 1),
			MODA(adress + 2), MODA(adress + 3));
		pc->carry = 0;
	}
}
