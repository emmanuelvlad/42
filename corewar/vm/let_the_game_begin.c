/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_the_game_begin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:21:34 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:51:37 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			check_cycle_die(t_env *env)
{
	int		i;

	i = 0;
	env->pc_nbr_live = 0;
	while (i < env->malloc_size && env->pc[i])
	{
		if (env->pc[i]->nb_life > 0)
			env->pc_nbr_live += env->pc[i]->nb_life;
		else if (!env->pc[i]->nb_life)
			env->pc[i]->kill = 1;
		else if (env->players_lives[-1 * env->pc[i]->reg[0] - 1] == 0)
			env->pc[i]->kill = 1;
		env->pc[i]->nb_life = 0;
		i++;
	}
	ft_bzero(env->players_lives, sizeof(env->players_lives));
	if (env->pc_nbr_live >= NBR_LIVE)
		return (0);
	return (1);
}

void		fight_2(t_env *env, int end)
{
	if (!env->c_b_ctd)
	{
		env->checks++;
		end = check_cycle_die(env);
		if (!end || env->checks == MAX_CHECKS)
		{
			env->tot_cycle_delta += CYCLE_DELTA;
			env->checks = 0;
		}
		if (env->tot_cycle_delta > CYCLE_TO_DIE)
			env->tot_cycle_delta = CYCLE_TO_DIE;
		env->last_ctd_cycle = env->cycle;
		env->nb_ctd++;
	}
}

int			fight(t_env *env)
{
	int end;

	end = 0;
	while (env->c_b_ctd >= 0)
	{
		env->c_b_ctd = CYCLE_TO_DIE + env->last_ctd_cycle
		- env->tot_cycle_delta - env->cycle;
		env->ctd = CYCLE_TO_DIE - env->tot_cycle_delta;
		if (env->nc ? env->cycle % env->speed == 0 : 0)
			env->nc ? ncurses_print_file(env) : 0;
		if (env->loop_to_dump == env->cycle)
			return (0);
		if (!env->c_b_ctd)
			fight_2(env, end);
		if (exec_pc_1cycle(env))
			return (1);
		env->cycle++;
	}
	return (0);
}

void		clean_pc(t_env *env)
{
	int		i;

	i = 0;
	while (env->pc[i])
	{
		free(env->pc[i]);
		i++;
	}
	free(env->pc);
}

void		let_the_game_begin(t_env *env)
{
	int		i;
	int		pc_pos;

	pc_pos = 0;
	i = 0;
	while (i < env->nb_players)
	{
		env->pc[i] = pc_new(pc_pos, env, i);
		pc_pos += MEM_SIZE / env->nb_players;
		i++;
	}
	env->nb_ctd = 0;
	env->checks = 0;
	env->c_b_ctd = 0;
	env->nc ? init_ncurses(env) : 0;
	fight(env);
	env->nc ? endwin() : 0;
	clean_pc(env);
}
