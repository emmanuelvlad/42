/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 21:39:41 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 17:05:39 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static char		*g_error_msg[12] =
{
	"Invalid player number [1 - 4]\n",
	"Champion's name too long\n",
	"Comment's length too long\n",
	"Champion's size too long\n",
	"Wrong magic number\n",
	"Wrong file format\n",
	"usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]\n\
	\t-dump N\t: Dumps memory after N cycles then exits\n\
	\t-nc\t: Display ncurses corewar\n",
	"Can't read source file\n",
	"Missing champion\n",
	"Too many champions\n",
	"Missing champion after -n\n",
	"Check players numbers\n"
};

int	handle_error(int err)
{
	ft_putstr_fd(g_error_msg[err], 2);
	return (-1);
}
