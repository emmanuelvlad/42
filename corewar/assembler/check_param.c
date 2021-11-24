/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 18:30:56 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/19 17:03:47 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_type(char *str)
{
	if (str[0] == 'r')
		return (T_REG);
	if (str[0] == DIRECT_CHAR)
		return (T_DIR);
	if (str[0] == LABEL_CHAR)
		return (T_LAB);
	if (str[0] == '\0')
		return (-1);
	else
		return (T_IND);
}

int		compare_types(int type, int tp)
{
	if (type == 1)
	{
		if (tp == 3 || tp == 1 || tp == 5 || tp == 9 \
				|| tp == 7 || tp == 15 || tp == 13)
			return (1);
	}
	if (type == 2)
	{
		if (tp == 2 || tp == 3 || tp == 6 || tp == 10 || \
				tp == 7 || tp == 14 || tp == 15 || tp == 11)
			return (1);
	}
	if (type == 4)
	{
		if (tp == 4 || tp == 7 || tp == 6 || tp == 5 || \
				tp == 12 || tp == 14 || tp == 13)
			return (1);
	}
	if (type == 8)
	{
		if (tp >= 4 && tp <= 15)
			return (1);
	}
	return (0);
}

int		verify_value(char *param, int k)
{
	if (param[k] == '-')
		k++;
	while (param[k])
	{
		if (param[k] < 48 || param[k] > 57)
			return (0);
		k++;
	}
	return (1);
}

int		check_param_bis(t_instr *instr, t_lab *label, int i, t_check **check)
{
	initialize_check(&(*check), instr);
	if (compare_types((*check)->type, g_op_tab[i].T[(*check)->j]) == 0)
		return (error_msg(7));
	if (I->P[(*check)->j][(*check)->k] == 'r')
	{
		if (ft_atoi(&(I->P[(*check)->j][(*check)->k + 1])) > REG_NUMBER \
				|| ft_atoi(&(I->P[(*check)->j][(*check)->k + 1])) < 1)
			return (error_msg(12));
	}
	if (I->P[(*check)->j][(*check)->k] == 'r')
		(*check)->reg = 1;
	if (I->P[(*check)->j][(*check)->k] == DIRECT_CHAR \
			|| I->P[(*check)->j][(*check)->k] == 'r')
		(*check)->k++;
	if (I->P[(*check)->j][(*check)->k] == LABEL_CHAR)
	{
		if (check_param_label(&(I->P[(*check)->j][(*check)->k + 1]), \
					label) == 0)
			return (error_msg(2));
	}
	if ((*check)->reg == 0 && I->P[(*check)->j][(*check)->k] \
			!= LABEL_CHAR && verify_value(I->P[(*check)->j], (*check)->k) == 0)
		return (0);
	(*check)->j++;
	return (1);
}

int		check_param(t_instr *instr, t_lab *label, int i)
{
	int		ret;
	t_check	*check;

	if ((check = malloc(sizeof(t_check))) == NULL)
		return (error_msg(13));
	check->j = 0;
	ret = 1;
	while (I->P[check->j] && ret != 0)
		ret = check_param_bis(&(*instr), label, i, &check);
	if (ret == 0)
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}
