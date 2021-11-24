/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <evlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 14:32:37 by evlad             #+#    #+#             */
/*   Updated: 2017/07/19 17:04:39 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		write_label_4(t_main **main, t_instr *instr, char *str, int fd)
{
	int		index;

	index = get_label_index(main, str);
	index -= instr->index;
	if (fixed_write(fd, &index, 4) == -1)
		return (0);
	return (1);
}
