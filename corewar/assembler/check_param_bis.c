/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrebs <mkrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 12:28:14 by mkrebs            #+#    #+#             */
/*   Updated: 2017/07/19 17:03:45 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		initialize_check(t_check **check, t_instr *instr)
{
	(*check)->k = 0;
	(*check)->reg = 0;
	(*check)->type = get_type(I->P[(*check)->j]);
}
