/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_ncurse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:40:16 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/25 11:37:15 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include <ncurses.h>

int		is_underline(int j, t_env *env)
{
	int		i;

	i = 0;
	while (env->pc[i])
	{
		if (j == env->pc[i]->pc_position)
			return (1);
		i++;
	}
	return (0);
}

void	interact_ncurses(t_env *env)
{
	if (env->speed == 0)
		env->speed = getch();
	while (env->speed != '1' && env->speed != '2' && env->speed != '3'
	&& env->speed != '4' && env->speed != ' ' && env->speed != -1)
		env->speed = getch();
	if (env->speed == '1')
		env->speed = 1;
	else if (env->speed == '2')
		env->speed = 5;
	else if (env->speed == '3')
		env->speed = 10;
	else if (env->speed == '4')
		env->speed = 100;
	else if (env->speed == ' ')
		env->speed = -1;
}

void	ncurses_display_reg(t_prog *tmp)
{
	int j;

	j = 1;
	printw("REG:\t");
	while (j <= REG_NUMBER)
	{
		printw("num %d - reg = %d  ", j, tmp->reg[j - 1]);
		j++;
	}
	printw("\n");
}

void	display_info(t_env *env)
{
	int		i;

	i = 0;
	printw("Nb of cycle: %5d\t\t\tLast operation: %02x\t\t \
	Nb of cycle before CTD: %d, ctd = %d\n",
	env->cycle, env->last_f_nb, env->c_b_ctd, env->ctd);
	printw("checksCTD = %d\t\t nb_cycle_to_die = %d\n",
	env->checks, env->nb_ctd);
	if (env->c_b_ctd == 0)
		env->last_ctd_cycle = env->cycle;
	while (i <= env->nb_players)
	{
		attron(COLOR_PAIR(i));
		printw("Player %d : %s\n** %d lives\n", i, env->player[i - 1],
			env->players_lives[i - 1]);
		attroff(COLOR_PAIR(i));
		i++;
	}
}

void	ncurses_print_file(t_env *env)
{
	int	i;

	i = 0;
	interact_ncurses(env);
	erase();
	while (i < MEM_SIZE)
	{
		if (is_underline(i, env))
			attron(A_STANDOUT);
		attron(COLOR_PAIR(env->color[i]));
		printw("%02x", 0xFF & env->arena[i]);
		attroff(COLOR_PAIR(env->color[i]));
		if (is_underline(i, env))
			attroff(A_STANDOUT);
		printw(" ");
		if ((i + 1) % (128 / 2) == 0)
			printw("\n");
		i++;
	}
	display_info(env);
	refresh();
}
