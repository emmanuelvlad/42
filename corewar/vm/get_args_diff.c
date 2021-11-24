/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:56:26 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 18:13:38 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	wrong_acb(t_prog *pc)
{
	pc->arg[0] = 0;
	pc->arg[1] = 0;
	pc->arg[2] = 0;
	pc->pc_next = 1;
}

void	get_args_diff4(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b10010100)
	{
		pc->arg[0] = (hex_sum(env->arena[MODA(pc->pc_position + 2)],
			env->arena[MODA(pc->pc_position + 3)]));
		pc->arg[1] = env->arena[MODA(pc->pc_position + 4)];
		pc->arg[2] = env->arena[MODA(pc->pc_position + 5)];
		pc->pc_next = 6;
	}
	else if (pc->acb == 0b11010100)
	{
		pc->arg[0] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 2)],
			env->arena[MODA(pc->pc_position + 3)]));
		pc->arg[1] = env->arena[MODA(pc->pc_position + 4)];
		pc->arg[2] = env->arena[MODA(pc->pc_position + 5)];
		pc->pc_next = 6;
	}
	else if (pc->acb == 0b01010100)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = env->arena[MODA(pc->pc_position + 3)];
		pc->arg[2] = env->arena[MODA(pc->pc_position + 4)];
		pc->pc_next = 5;
	}
	else
		wrong_acb(pc);
}

void	get_args_diff3(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b10110100)
	{
		pc->arg[0] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 2)],
			env->arena[MODA(pc->pc_position + 3)]));
		pc->arg[1] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 4)],
			env->arena[MODA(pc->pc_position + 5)]));
		pc->arg[2] = env->arena[MODA(pc->pc_position + 6)];
		pc->pc_next = 7;
	}
	else if (pc->acb == 0b10100100)
	{
		pc->arg[0] = MODR(hex_sum2(env->arena[MODA(pc->pc_position + 2)],
			env->arena[MODA(pc->pc_position + 3)], env->arena[
			MODA(pc->pc_position + 4)], env->arena[MODA(pc->pc_position + 5)]));
		pc->arg[1] = MODR(hex_sum2(env->arena[MODA(pc->pc_position + 6)],
			env->arena[MODA(pc->pc_position + 7)], env->arena[
			MODA(pc->pc_position + 8)], env->arena[MODA(pc->pc_position + 9)]));
		pc->arg[2] = env->arena[MODA(pc->pc_position + 10)];
		pc->pc_next = 11;
	}
	else
		get_args_diff4(pc, env);
}

void	get_args_diff2(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b11110100)
	{
		pc->arg[0] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 2)],
			env->arena[MODA(pc->pc_position + 3)]));
		pc->arg[1] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 4)],
			env->arena[MODA(pc->pc_position + 5)]));
		pc->arg[2] = env->arena[MODA(pc->pc_position + 6)];
		pc->pc_next = 7;
	}
	else if (pc->acb == 0b11100100)
	{
		pc->arg[0] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 2)],
			env->arena[MODA(pc->pc_position + 3)]));
		pc->arg[1] = MODR(hex_sum2(env->arena[MODA(pc->pc_position + 4)],
			env->arena[MODA(pc->pc_position + 5)], env->arena[
			MODA(pc->pc_position + 6)], env->arena[MODA(pc->pc_position + 7)]));
		pc->arg[2] = env->arena[MODA(pc->pc_position + 8)];
		pc->pc_next = 9;
	}
	else
		get_args_diff3(pc, env);
}

void	get_args_diff(t_prog *pc, t_env *env)
{
	if (pc->acb == 0b01010100)
		get_args_diff4(pc, env);
	else if (pc->acb == 0b01110100)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(hex_sum(env->arena[MODA(pc->pc_position + 3)],
			env->arena[MODA(pc->pc_position + 4)]));
		pc->arg[2] = env->arena[MODA(pc->pc_position + 5)];
		pc->pc_next = 6;
	}
	else if (pc->acb == 0b01100100)
	{
		pc->arg[0] = env->arena[MODA(pc->pc_position + 2)];
		pc->arg[1] = MODR(hex_sum2(env->arena[MODA(pc->pc_position + 3)],
			env->arena[MODA(pc->pc_position + 4)], env->arena[
			MODA(pc->pc_position + 5)], env->arena[MODA(pc->pc_position + 6)]));
		pc->arg[2] = env->arena[MODA(pc->pc_position + 7)];
		pc->pc_next = 8;
	}
	else
		get_args_diff2(pc, env);
}
