/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:10:57 by evlad             #+#    #+#             */
/*   Updated: 2016/12/03 10:50:17 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define COLOR 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"

typedef struct	s_coord
{
	int			*pos;
	int			total_tetri;
	int			sqr_size;
	char		*open;
}				t_coord;

int				ft_errors(int ac, t_coord *crd);
char			*ft_open(char *av);
int				ft_checkfile(char *str);
char			***ft_stock(char *str, int total_tetri);
char			**ft_backtrack(char ***tetris, char **result,
				t_coord *crd, int i);
char			**ft_backtrack2(char ***tetris, char **result,
				t_coord *crd, int i);
void			ft_swap(char *pt1, char *pt2);
int				ft_sqrt(int total_tetri);
int				ft_overlap(t_coord crd, char **result, char **treti, int i);
void			ft_fill(t_coord crd, char **result, char **tetri, int i);
void			ft_unfill(t_coord crd, char **result, char **tetri, int i);
t_coord			*ft_init(char *str);
char			**ft_init_tab(t_coord crd);
int				ft_sqrt_mod(int total_tetri);
void			ft_colorit(char *result);
void			ft_clean(char ***tetris, char **result, t_coord *crd);

#endif
