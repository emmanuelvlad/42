/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:04:22 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:05:22 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		exec(t_prog *tmp, unsigned char f_nb, t_env *env)
{
	if (f_nb == 1)
		live(tmp, env);
	else if (f_nb == 2)
		ld(tmp, env);
	else if (f_nb == 3)
		st(tmp, env);
	else if (f_nb == 4)
		add(tmp, env);
	else if (f_nb == 5)
		sub(tmp, env);
	else if (f_nb == 6)
		and(tmp, env);
	else if (f_nb == 7)
		or(tmp, env);
	else if (f_nb == 8)
		xor(tmp, env);
	return (0);
}

int		exec_bis(t_prog *tmp, unsigned char f_nb, t_env *env)
{
	if (f_nb == 9)
		zjmp(tmp, env);
	else if (f_nb == 10)
		ldi(tmp, env);
	else if (f_nb == 11)
		sti(tmp, env);
	else if (f_nb == 12)
		nfork(tmp, env);
	else if (f_nb == 13)
		lld(tmp, env);
	else if (f_nb == 14)
		lldi(tmp, env);
	else if (f_nb == 15)
		lfork(tmp, env);
	else if (f_nb == 16)
		aff(tmp, env);
	return (0);
}
