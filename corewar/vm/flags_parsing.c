/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <sait-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:35:18 by sait-ben          #+#    #+#             */
/*   Updated: 2017/07/19 17:05:27 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	rec_player2(char **argv, int i, t_env *env, int j)
{
	char		*str;

	if (env->player[ft_atoi(argv[i + 1]) - 1] != NULL)
	{
		str = ft_strdup(env->player[ft_atoi(argv[i + 1]) - 1]);
		while (ft_strlen(env->player[j]) != 0)
			j++;
		ft_strcpy(env->player[j], str);
		free(str);
	}
}

int		rec_player(char **argv, int i, t_env *env, int flag)
{
	static int	k = 0;
	int			j;

	j = 0;
	if (flag == 1)
	{
		if (check_nb(ft_atoi(argv[i + 1]), env) == 0)
			return (handle_error(11));
		if (check_nb(ft_atoi(argv[i + 1]), env) == 1)
			env->chk_nb[k++] = ft_atoi(argv[i + 1]);
		if (env->player[ft_atoi(argv[i + 1]) - 1] != NULL)
			rec_player2(argv, i, env, j);
		if (!argv[i + 2])
			return (handle_error(10));
		ft_strcpy(env->player[ft_atoi(argv[i + 1]) - 1], argv[i + 2]);
		return (1);
	}
	else
	{
		while (ft_strlen(env->player[j]) != 0)
			j++;
		ft_strcpy(env->player[j], argv[i]);
		return (1);
	}
}

int		check_flag(char **argv, int i, t_env *env)
{
	if (ft_strcmp(argv[i], "-dump") == 0 && argv[i + 1] &&
			is_number(argv[i + 1]) == 1)
		env->loop_to_dump = ft_atoi(argv[++i]);
	else if (ft_strcmp(argv[i], "-n") == 0 && argv[i + 1] &&
			ft_isdigit(ft_atoi(argv[i + 1])) == 0)
	{
		if (ft_atoi(argv[i + 1]) > 4 || ft_atoi(argv[i + 1]) < 1)
			return (handle_error(0));
		env->nb_players++;
		if (rec_player(argv, i, env, 1) == -1)
			return (-1);
		i += 2;
	}
	else if (ft_strstr(argv[i], ".cor"))
	{
		env->nb_players++;
		rec_player(argv, i, env, -1);
	}
	else if (ft_strcmp(argv[i], "-nc") == 0)
		env->nc = 1;
	else
		i = 0;
	return (i);
}

int		parse_flag(int argc, char **argv, t_env *env)
{
	int	i;

	i = 0;
	env->nb_players = 0;
	while (i < 4)
	{
		ft_bzero(env->player[i], PROG_NAME_LENGTH);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		i = check_flag(argv, i, env);
		if (i == 0)
			return (handle_error(6));
		if (i == -1)
			return (-1);
		i++;
	}
	return (0);
}
