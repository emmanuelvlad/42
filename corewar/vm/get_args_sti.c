/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_sti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:54:03 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:05:37 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	args_sti4(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b01101000)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 3)],
			env->arena[MODA(pc->pc_position + 4)]));
		pc->arg[2] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 5)],
			env->arena[MODA(pc->pc_position + 6)]));
		pc->pc_next = 7;
	}
	else if (pc->acb == 0b01111100)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 3)],
			env->arena[MODA(pc->pc_position + 4)]));
		pc->arg[2] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 5)],
			env->arena[MODA(pc->pc_position + 6)]));
		pc->pc_next = 7;
	}
}

void	args_sti3(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b01100100)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 3)],
			env->arena[MODA(pc->pc_position + 4)]));
		pc->arg[0] = MODR(env->arena[MODA(pc->pc_position + 5)]);
		pc->pc_next = 6;
	}
}

void	args_sti2(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b01111000)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 3)],
			env->arena[MODA(pc->pc_position + 4)]));
		pc->arg[2] = MODR(hex_sum2(env->arena[MODA(pc->pc_position + 5)],
			env->arena[MODA(pc->pc_position + 6)], env->arena[
			MODA(pc->pc_position + 7)], env->arena[MODA(pc->pc_position + 8)]));
		pc->pc_next = 9;
	}
	else if (pc->acb == 0b01101100)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(hex_sum2(env->arena[MODA(pc->pc_position + 3)],
			env->arena[MODA(pc->pc_position + 4)], env->arena[
			MODA(pc->pc_position + 5)], env->arena[MODA(pc->pc_position + 6)]));
		pc->arg[2] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 7)],
			env->arena[MODA(pc->pc_position + 8)]));
		pc->pc_next = 9;
	}
	else if (pc->acb == 0b01101000)
		args_sti4(pc, env);
	else
		args_sti3(pc, env);
}

void	args_sti(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b01011100)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(env->arena[MODA(pc->pc_position + 3)]);
		pc->arg[2] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 4)],
			env->arena[MODA(pc->pc_position + 5)]));
		pc->pc_next = 6;
	}
	else if (pc->acb == 0b01011000)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(env->arena[MODA(pc->pc_position + 3)]);
		pc->arg[2] = MODR(hex_sum2(env->arena[MODA(pc->pc_position + 4)],
			env->arena[MODA(pc->pc_position + 5)],
			env->arena[MODA(pc->pc_position + 6)],
			env->arena[MODA(pc->pc_position + 7)]));
		pc->pc_next = 8;
	}
	else if (pc->acb == 0b01111100)
		args_sti4(pc, env);
	else
		args_sti2(pc, env);
}
