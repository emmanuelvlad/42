/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:35:00 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:03:59 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		bin2dec(char *str)
{
	int		size;
	int		count;
	int		n;

	size = ft_strlen(str) - 1;
	count = 0;
	n = 0;
	while (*str != '\0')
	{
		if (*str == '1')
			n = n + ft_pow(2, size - count);
		count++;
		str++;
	}
	return (n);
}

int		find_octal(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (i < 16)
	{
		if (ft_strcmp(g_op_tab[i].nom, str) == 0)
			break ;
		i++;
	}
	return (i + 1);
}

int		is_direct2(char *instr)
{
	if (ft_strcmp(instr, "zjmp") == 0 || ft_strcmp(instr, "ldi") == 0 ||
			ft_strcmp(instr, "sti") == 0 || ft_strcmp(instr, "fork") == 0 ||
			ft_strcmp(instr, "lldi") == 0 || ft_strcmp(instr, "lfork") == 0)
		return (1);
	else
		return (0);
}

void	do_ocp(t_instr *instr, int index, int type)
{
	if (type == 1)
	{
		instr->ocp[index] = '0';
		instr->ocp[index + 1] = '1';
	}
	if (type == 2)
	{
		instr->ocp[index] = '1';
		instr->ocp[index + 1] = '0';
	}
	if (type == 3)
	{
		instr->ocp[index] = '1';
		instr->ocp[index + 1] = '1';
	}
}

int		is_ocp(char *str)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(g_op_tab[i].nom, str) == 0 && g_op_tab[i].octal)
			return (1);
		i++;
	}
	return (0);
}
