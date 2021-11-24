/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:33:39 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:04:02 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			set_label_index(t_main **main, char *str, int index)
{
	t_lab	*label;

	label = (*main)->label;
	while (label)
	{
		if (ft_strcmp(label->nom, str) == 0)
		{
			label->pos = index;
			break ;
		}
		label = label->next;
	}
}

int				get_label_index(t_main **main, char *str)
{
	t_lab	*label;

	label = (*main)->label;
	while (label)
	{
		if (ft_strcmp(label->nom, str) == 0)
			return (label->pos);
		label = label->next;
	}
	return (-1);
}

int				check_params(t_instr *instr, char *str, int index)
{
	if (str[0] == 'r')
	{
		do_ocp(instr, index * 2, 1);
		return (1);
	}
	else if (str[0] == DIRECT_CHAR)
	{
		do_ocp(instr, index * 2, 2);
		if (is_direct2(instr->nom))
			return (2);
		else
			return (4);
	}
	else
	{
		do_ocp(instr, index * 2, 3);
		return (2);
	}
}

static int		get_prog_size(t_main **main)
{
	int		index;
	t_instr	*instr;
	int		i;

	instr = (*main)->instr;
	index = 0;
	while (instr->nom && instr)
	{
		i = -1;
		instr->index = index;
		if (instr->lab)
			set_label_index(main, instr->lab, index);
		index += 1;
		if (is_ocp(instr->nom))
			index += 1;
		while (instr->param[++i])
			index += check_params(instr, instr->param[i], i);
		instr = instr->next;
	}
	return (index);
}

int				compile(t_main **main, int fd, char *name)
{
	t_instr *instr;
	int		tmp;
	int		i;

	instr = (*main)->instr;
	(*main)->prog_size = get_prog_size(main);
	if (!(write_header(main, fd)))
		return (0);
	while (instr->nom)
	{
		i = 0;
		tmp = find_octal(instr->nom);
		write(fd, &tmp, 1);
		if (is_ocp(instr->nom))
		{
			tmp = bin2dec(instr->ocp);
			write(fd, &tmp, 1);
		}
		while (instr->param[i])
			write_params(main, instr, instr->param[i++], fd);
		instr = instr->next;
	}
	ft_printf("Writing output program to %s\n", name);
	return (1);
}
