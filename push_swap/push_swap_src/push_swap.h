/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:10:23 by evlad             #+#    #+#             */
/*   Updated: 2017/05/30 12:40:58 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../includes/libft.h"
# include "./both.h"

/*
** --------------------------------------------------------------------------
**									   SORT
** --------------------------------------------------------------------------
*/

void				sort(t_stack *a, t_stack *b, int amount);
void				sort_3(t_stack *stack);
void				sort_30(t_stack *a, t_stack *b);
void				sort_plus(t_stack *a, t_stack *b);
void				put_first_a(t_stack *stack, int value);
void				put_first_b(t_stack *stack, int value);

/*
** --------------------------------------------------------------------------
**									  PARSE
** --------------------------------------------------------------------------
*/

int					parse_min(t_stack *stack);
int					parse_max(t_stack *stack);
int					parse_max_min(t_stack *stack, int percent);
int					parse_pos(t_stack *stack, int num);
int					stack_size(t_stack *stack);

/*
** --------------------------------------------------------------------------
**									   MISC
** --------------------------------------------------------------------------
*/

int					check_if_exists(t_element *element, int value);
int					closest(t_stack *stack, int value);

#endif
