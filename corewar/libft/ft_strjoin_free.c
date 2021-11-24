/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:42:59 by fpipart           #+#    #+#             */
/*   Updated: 2016/12/31 12:58:06 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int free_str)
{
	char *tmp1;
	char *tmp2;
	char *s;

	tmp1 = s1;
	tmp2 = s2;
	s = ft_strjoin(s1, s2);
	if (free_str == 0)
		ft_strdel(&tmp1);
	else if (free_str == 1)
		ft_strdel(&tmp2);
	else if (free_str == 2)
	{
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	return (s);
}
