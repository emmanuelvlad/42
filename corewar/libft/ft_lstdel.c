/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:35:32 by fpipart           #+#    #+#             */
/*   Updated: 2016/11/11 11:11:32 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst1;
	t_list *lst2;

	lst1 = *alst;
	while (lst1)
	{
		lst2 = lst1->next;
		del(lst1->content, lst1->content_size);
		free(lst1);
		lst1 = lst2;
	}
	*alst = NULL;
}
