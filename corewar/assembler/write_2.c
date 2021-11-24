/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:32:37 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:04:37 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		write_registre(int registre, int fd)
{
	if (write(fd, &registre, 1) == -1)
		return (0);
	return (1);
}

static int		write_label(t_main **main, t_instr *instr, char *str, int fd)
{
	int		index;

	index = get_label_index(main, str);
	index -= instr->index;
	if (fixed_write(fd, &index, 2) == -1)
		return (0);
	return (1);
}

static int		write_direct(int index, int size, int fd)
{
	if (fixed_write(fd, &index, size) == -1)
		return (0);
	return (1);
}

static int		write_index(int index, int fd)
{
	if (fixed_write(fd, &index, 2) == -1)
		return (0);
	return (1);
}

int				write_params(t_main **main, t_instr *instr, char *str, int fd)
{
	if (str[0] == 'r')
		return (write_registre(ft_atoi(str + 1), fd));
	else if (str[0] == DIRECT_CHAR)
	{
		if (is_direct2(instr->nom))
		{
			if (str[1] == LABEL_CHAR)
				return (write_label(main, instr, str + 2, fd));
			return (write_direct(ft_atoi(str + 1), 2, fd));
		}
		else
		{
			if (str[1] == LABEL_CHAR)
				return (write_label_4(main, instr, str + 2, fd));
			return (write_direct(ft_atoi(str + 1), 4, fd));
		}
	}
	else if (str[0] == LABEL_CHAR)
		return (write_label(main, instr, str + 1, fd));
	else
		return (write_index(ft_atoi(str), fd));
}
