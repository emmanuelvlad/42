/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:49:01 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:05:51 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		neg2(int nb)
{
	if (nb > 0x7FFF)
	{
		nb = 0xFFFF - nb;
		nb = nb * -1;
		nb = nb - 1;
	}
	return (nb);
}

int		get_adress(t_prog *pc, t_env *env)
{
	int	adress;

	adress = 0;
	if (pc->acb == 0b01100100)
		adress = MODA(pc->reg[pc->arg[0] - 1] + pc->arg[1]);
	else if (pc->acb == 0b01010100)
		adress = MODA(pc->reg[pc->arg[0] - 1] + pc->reg[pc->arg[1] - 1]);
	else if (pc->acb == 0b10100100)
		adress = MODA(pc->arg[0] + pc->arg[1]);
	else if (pc->acb == 0b10010100)
		adress = neg2(pc->arg[0]) + neg2(pc->reg[pc->arg[1] - 1]);
	else if (pc->acb == 0b11100100)
		adress = MODA(env->arena[pc->pc_position + pc->arg[0]] + pc->arg[1]);
	else if (pc->acb == 0b11010100)
		adress = MODA(env->arena[pc->pc_position + pc->arg[0]] +
			pc->reg[pc->arg[1] - 1]);
	return (adress);
}

void	ldi(t_prog *pc, t_env *env)
{
	int		adress;

	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	get_args_diff(pc, env);
	adress = pc->pc_position + MODR(get_adress(pc, env));
	if (adress == 0)
		pc->carry = 1;
	else
	{
		pc->reg[pc->arg[2] - 1] = hex_sum2(env->arena[MODA(adress)], env->arena[
			MODA(adress + 1)], env->arena[MODA(adress + 2)], env->arena[
			MODA(adress + 3)]);
		if (pc->arg[2] - 1 >= 0 && pc->arg[2] - 1 < 16)
			pc->reg[pc->arg[2] - 1] = hex_sum2(MODA(adress), MODA(adress + 1),
					MODA(adress + 2), MODA(adress + 3));
		pc->carry = 0;
	}
}
