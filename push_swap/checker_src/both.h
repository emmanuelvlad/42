/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:25:07 by evlad             #+#    #+#             */
/*   Updated: 2017/05/16 10:30:56 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H
# include "../includes/libft.h"

/*
** --------------------------------------------------------------------------
**									STRUCTURES
** --------------------------------------------------------------------------
*/

typedef struct			s_malloc
{
	char				**av;
	int					ac;
}						t_malloc;

typedef struct			s_element
{
	int					value;
	struct s_element	*next;
}						t_element;

typedef struct			s_stack
{
	struct s_element	*first;
}						t_stack;

/*
** --------------------------------------------------------------------------
**									STOCK
** --------------------------------------------------------------------------
*/

void					stock(t_stack *stack, int ac, char **av,
							t_malloc *malloc);

/*
** --------------------------------------------------------------------------
**									INITILIZATION
** --------------------------------------------------------------------------
*/

t_element				*init_element(int value);
t_stack					*init_a(char *str, t_malloc *malloc);
t_stack					*init_b(void);
t_malloc				*init_malloc(void);

/*
** --------------------------------------------------------------------------
**									OPERATIONS
** --------------------------------------------------------------------------
*/

void					sa(t_stack *a);
void					sb(t_stack *b);
void					ss(t_stack *a, t_stack *b);
void					pa(t_stack *a, t_stack *b);
void					pb(t_stack *a, t_stack *b);
void					ra(t_stack *a);
void					rb(t_stack *b);
void					rr(t_stack *a, t_stack *b);
void					rra(t_stack *a);
void					rrb(t_stack *b);
void					rrr(t_stack *a, t_stack *b);

/*
** --------------------------------------------------------------------------
**										MISC
** --------------------------------------------------------------------------
*/

void					printexit(char *str);
void					freexit(t_stack *stack, char *str, int first,
							t_malloc *malloc);
void					freestack(t_stack *stack);
void					free_malloc(t_malloc *malloc);
int						check_stack(t_stack *stack);
int						check_if_exists(t_element *element, int value);

#endif
