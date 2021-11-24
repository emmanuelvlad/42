/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 15:31:24 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/20 11:11:30 by mkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char		*g_error_msg[14] =
{
	"\x1b[31mError: Wrong name syntax or is empty.\x1b[0m\n",
	"\x1b[31mwrong file extension.\x1b[0m\n",
	"\x1b[31mError in label's name.\x1b[0m\n",
	"\x1b[31mError in champion's name.\x1b[0m\n",
	"\x1b[31mError in file's comment.\x1b[0m\n",
	"\x1b[31mError in comment.\x1b[0m\n",
	"\x1b[31mError: number of parameter invalid\x1b[0m\n",
	"\x1b[31mError: invalid type of parameter\x1b[0m\n",
	"\x1b[31mError: wrong file\x1b[0m\n",
	"\x1b[31mError: wrong instruction name\x1b[0m\n",
	"\x1b[31mUsage: ./asm [filename.s]\x1b[0m\n",
	"\x1b[31mError: Wrong comment syntax or is empty.\x1b[0m\n",
	"\x1b[31mError: Wrong register\x1b[0m\n",
	"\x1b[31mMalloc failed\x1b[0m\n"
};

int				error_msg(int id)
{
	ft_putstr_fd(g_error_msg[id], 2);
	return (0);
}
