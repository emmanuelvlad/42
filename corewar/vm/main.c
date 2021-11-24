/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:23:37 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:54:53 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		champ_parsing(t_champ **champ, t_env env)
{
	unsigned char	file[4000];
	int				fd;
	int				nb;

	nb = 0;
	while (nb < env.nb_players)
	{
		ft_bzero(file, 4000);
		fd = open(env.player[nb], O_RDONLY);
		if (fd <= 0)
		{
			handle_error(7);
			return (1);
		}
		if (read_cor_file(fd, file, champ, nb) == -1)
			return (1);
		nb++;
	}
	return (0);
}

void	check_champ(t_champ *champ)
{
	t_champ *tmp;

	tmp = champ;
	while (tmp)
	{
		ft_putendl(tmp->h->prog_name);
		ft_putendl(tmp->h->comment);
		ft_putnbr(tmp->size);
		ft_putchar('\n');
		print_file(tmp->champ, tmp->size);
		ft_putchar('\n');
		ft_printf("champ_nb = %hhd\n", tmp->champ_nb);
		tmp = tmp->next;
	}
}

void	init_env(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->speed = 1;
	env->loop_to_dump = -1;
	env->pc = NULL;
	if (!(env->pc = (t_prog**)malloc(sizeof(t_prog*) * PROC_SIZE)))
		exit(EXIT_FAILURE);
	env->malloc_size = PROC_SIZE;
	ft_bzero(env->pc, sizeof(env->pc));
}

void	clean_champ(t_champ **champ)
{
	t_champ *lst1;
	t_champ *lst2;

	lst1 = *champ;
	while (lst1)
	{
		lst2 = lst1->next;
		free(lst1->h);
		free(lst1);
		lst1 = lst2;
	}
	*champ = NULL;
}

int		main(int argc, char **argv)
{
	t_env		env;
	t_champ		*champ;

	champ = NULL;
	init_env(&env);
	if (argc < 2)
		return (handle_error(6));
	if (parse_flag(argc, argv, &env) == -1)
		return (1);
	if (champ_parsing(&champ, env) == 1)
		return (1);
	if (env.nb_players < 1)
		return (handle_error(6));
	else if (env.nb_players > 4)
		return (handle_error(9));
	create_arena(champ, &env);
	introduce_champ(champ);
	let_the_game_begin(&env);
	if (env.loop_to_dump == env.cycle)
		print_file(env.arena, 4096);
	else
		select_winner(env, champ);
	clean_champ(&champ);
	return (0);
}
