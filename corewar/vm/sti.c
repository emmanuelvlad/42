/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:26:48 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:07:48 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		calc_adress4(t_env *env, t_prog *pc, int adress)
{
	if (pc->acb == 0b01101100)
	{
		adress = pc->pc_position + neg(hex_sum(env->arena[MODA(pc->pc_position
			+ 3)], env->arena[MODA(pc->pc_position + 4)])) + neg(env->arena[
			MODA(hex_sum(env->arena[MODA(pc->pc_position + 5)], env->arena[
			MODA(pc->pc_position + 6)]))]);
		if (adress < 0)
			adress = 4096 + adress - 2;
	}
	else if (pc->acb == 0b01101000)
	{
		adress = pc->pc_position + neg(hex_sum(env->arena[
			MODA(pc->pc_position + 3)], env->arena[MODA(pc->pc_position + 4)]))
			+ neg(hex_sum(env->arena[MODA(pc->pc_position + 5)], env->arena[
			MODA(pc->pc_position + 6)]));
		if (adress < 0)
			adress = 4096 + adress - 2;
	}
	return (adress);
}

int		calc_adress3(t_env *env, t_prog *pc, int adress)
{
	if (pc->acb == 0b01100100)
	{
		adress = pc->pc_position + neg(hex_sum(env->arena[MODA(pc->pc_position
			+ 3)], env->arena[MODA(pc->pc_position + 4)])) + neg(pc->reg[
			pc->arg[2] - 1]);
		if (adress < 0)
			adress = 4096 + adress - 2;
	}
	return (adress);
}

int		calc_adress2(t_env *env, t_prog *pc, int adress)
{
	if (pc->acb == 0b01111100)
	{
		adress = pc->pc_position + neg(env->arena[MODA(hex_sum(env->arena[
			MODA(pc->pc_position + 3)], env->arena[MODA(pc->pc_position + 4)]))
			]) + neg(env->arena[MODA(hex_sum(env->arena[MODA(pc->pc_position +
			5)], env->arena[MODA(pc->pc_position + 6)]))]);
		if (adress < 0)
			adress = 4096 + adress - 2;
	}
	else if (pc->acb == 0b01111000)
	{
		adress = pc->pc_position + neg(env->arena[MODA(hex_sum(env->arena[
			MODA(pc->pc_position + 3)], env->arena[MODA(pc->pc_position +
			4)]))]) + neg(hex_sum(env->arena[MODA(pc->pc_position + 5)],
			env->arena[MODA(pc->pc_position + 6)]));
		if (adress < 0)
			adress = 4096 + adress - 2;
	}
	else if (pc->acb == 0b01101100)
		adress = calc_adress4(env, pc, adress);
	else
		adress = calc_adress3(env, pc, adress);
	return (adress);
}

int		calc_adress(t_env *env, t_prog *pc)
{
	int		adress;

	adress = 0;
	if (pc->acb == 0b01011000)
	{
		adress = pc->pc_position + neg(pc->reg[pc->arg[1] - 1]) + neg(hex_sum(
			env->arena[MODA(pc->pc_position + 4)], env->arena[MODA(
			pc->pc_position + 5)]));
		if (adress < 0)
			adress = 4096 + adress - 2;
	}
	else if (pc->acb == 0b01011100)
	{
		adress = pc->pc_position + neg(pc->reg[pc->arg[1] - 1]) +
			neg(env->arena[MODA(hex_sum(env->arena[MODA(pc->pc_position + 4)],
			env->arena[MODA(pc->pc_position + 5)]))]);
		if (adress < 0)
			adress = 4096 + adress - 2;
	}
	else if (pc->acb == 0b01101000)
		adress = calc_adress4(env, pc, adress);
	else
		adress = calc_adress2(env, pc, adress);
	return (adress);
}

void	sti(t_prog *pc, t_env *env)
{
	int	adress;

	pc->acb = env->arena[MODA(pc->pc_position + 1)];
	args_sti(pc, env);
	adress = MODA(calc_adress(env, pc));
	if (env->arena[MODA(pc->pc_position + 2)] > 0 &&
	env->arena[MODA(pc->pc_position + 2)] < 17)
	{
		int_to_chars(env, adress, pc->reg[pc->arg[0] - 1], pc);
	}
}
