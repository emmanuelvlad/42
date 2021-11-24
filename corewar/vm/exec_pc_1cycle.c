/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pc_1cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:15:31 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:50:38 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	new_cycle(t_prog *tmp, t_env *env)
{
	unsigned char	f_nb;

	f_nb = env->arena[tmp->pc_position % MEM_SIZE];
	if (f_nb == 16)
		tmp->remaining_cycle = 2;
	else if (f_nb == 2 || f_nb == 3)
		tmp->remaining_cycle = 5;
	else if (f_nb == 6 || f_nb == 7 || f_nb == 8)
		tmp->remaining_cycle = 6;
	else if (f_nb == 1 || f_nb == 4 || f_nb == 5 || f_nb == 13)
		tmp->remaining_cycle = 10;
	else if (f_nb == 9)
		tmp->remaining_cycle = 20;
	else if (f_nb == 10 || f_nb == 11)
		tmp->remaining_cycle = 25;
	else if (f_nb == 14)
		tmp->remaining_cycle = 50;
	else if (f_nb == 12)
		tmp->remaining_cycle = 800;
	else if (f_nb == 15)
		tmp->remaining_cycle = 1000;
	else
		tmp->remaining_cycle = 0;
}

int		exec_function(t_prog *tmp, t_env *env)
{
	unsigned char	f_nb;

	f_nb = 0;
	if (tmp)
	{
		if (tmp->remaining_cycle > 1)
			tmp->remaining_cycle--;
		else
		{
			f_nb = env->arena[tmp->pc_position % MEM_SIZE];
			if (f_nb < 9)
				exec(tmp, f_nb, env);
			else
				exec_bis(tmp, f_nb, env);
			tmp->pc_position = (tmp->pc_position + tmp->pc_next) % 4096;
			env->last_f_nb = f_nb;
			new_cycle(tmp, env);
			tmp->pc_next = 1;
		}
		return (0);
	}
	else
		return (-1);
}

int		pc_size(t_env *env)
{
	int		i;

	i = 0;
	while (env->pc[i])
		i++;
	return (i - 1);
}

int		exec_pc_1cycle(t_env *env)
{
	int		at_least_1pc;
	int		i;

	at_least_1pc = 0;
	i = pc_size(env);
	while (i >= 0 && env->pc[i])
	{
		if (env->pc[i]->kill == 0)
		{
			if (exec_function(env->pc[i], env) == -1)
				return (-1);
			at_least_1pc = 1;
		}
		i--;
	}
	if (at_least_1pc == 0)
		return (1);
	return (0);
}
