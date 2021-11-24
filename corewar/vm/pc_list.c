/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:39:28 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:06:57 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_prog	*pc_new(int pc_pos, t_env *env, int champ_nb)
{
	t_prog		*pc;
	int			j;
	static int	i = 0;

	if (!(pc = (t_prog*)malloc(sizeof(t_prog))))
		exit(EXIT_FAILURE);
	j = 0;
	while (j < REG_NUMBER)
		pc->reg[j++] = 0;
	pc->champ_nb = champ_nb;
	pc->nb_life = 0;
	pc->reg[0] = 0xffffffff - champ_nb;
	pc->pc_position = pc_pos;
	pc->nb_life = 0;
	pc->carry = 0;
	pc->kill = 0;
	pc->pc_next = 1;
	pc->acb = 0;
	pc->remaining_cycle = 0;
	new_cycle(pc, env);
	pc->nb = i++;
	return (pc);
}

void	pc_add(t_env *env, t_prog *new)
{
	int		i;

	i = 0;
	while (i < env->malloc_size && env->pc[i])
		i++;
	if (i >= env->malloc_size)
	{
		env->malloc_size *= 2;
		if (!(env->pc = (t_prog**)realloc(env->pc, sizeof(t_prog*) *
				env->malloc_size)))
			exit(EXIT_FAILURE);
	}
	env->pc[i] = new;
}
