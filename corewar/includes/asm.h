/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:02:00 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/20 11:30:01 by mkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include "op.h"

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef char		t_param_type;

typedef struct		s_op
{
	char			*nom;
	int				nb_param;
	t_param_type	type_param[MAX_ARGS_NUMBER];
	int				nb;
	int				cycle;
	char			*comment;
	int				octal;
	int				index;
}					t_op;

typedef struct		s_check
{
	int				j;
	int				type;
	int				k;
	int				reg;
}					t_check;

typedef struct		s_lab
{
	char			*nom;
	char			*line;
	int				pos;
	struct s_lab	*next;
}					t_lab;

typedef struct		s_instr
{
	char			*nom;
	char			*lab;
	char			*param[MAX_ARGS_NUMBER];
	char			ocp[9];
	int				index;
	struct s_instr	*next;
}					t_instr;

typedef struct		s_main
{
	t_instr			*instr;
	t_lab			*label;
	char			nom[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				prog_size;
}					t_main;

typedef struct		s_ci
{
	int				i;
	int				j;
	int				i_init;
	char			*str;
	t_instr			*tmp;
	t_lab			*start;
}					t_ci;

typedef struct		s_gi
{
	int				start_init;
	int				start;
	int				len;
	int				j;
}					t_gi;

extern t_op			g_op_tab[];

# define ME (*main)
# define I instr
# define L label
# define LE (*label)
# define N nom
# define C comment
# define P param
# define T type_param

char				*get_lines(char *argv);
char				*fill_cor(char *name, char **tab);
int					check_name(char *argv);
int					check_s(char **tab, t_main **main);
int					check_first_lines(char **tab);
int					check_instructions(char **tab, int i, t_main **main);
void				get_label(char **tab, int *k, t_lab **label, int *i);
int					get_param(t_instr **instr, char *tab, int i);
int					initialize_instr(t_instr **instr);
int					check_instr(t_instr *instr, t_lab *label);
int					only_comment(char *tab, int *i);
int					only_space_comment_tab(char *tab);
int					check_param(t_instr *intr, t_lab *label, int i);
char				*get_only_label(char *str);
int					check_param_label(char *str, t_lab *label);
int					start_with(char *tab, char *str);
int					get_info(char **tab, t_main **main, int *k);
void				get_instruction_bis(char *res, char *tab, t_gi *gi);
void				get_label_bis(char **tab, int *k, int *i);
int					check_instructions_bis(char **tab, int *k, t_main **main,
											t_ci **ci);
int					check_instructions_ter(char **tab, int *k, t_main **main,
											t_ci **ci);
int					check_label(char *tab, int *i);
char				*get_instruction(char *tab, int *i, int i_init);
void				initialize_check(t_check **check, t_instr *instr);
int					get_type(char *str);
int					idx_start(char *tab, char *str);
int					get_name(char *tab, t_main **main);
int					get_comment(char *tab, t_main **main);
void				free_everything(t_main **main, char **tab);
int					return_free_ci(t_ci **ci, int nb);
int					check_quote(char *tab, int start);
int					strlenet(char **tab);
int					return_main(t_main **main);
int					empty_file(t_main **main, char **tab);

/*
** --------------------------------------------------------------------------
**									COMPILATION
** --------------------------------------------------------------------------
*/

int					compile(t_main **main, int fd, char *name);
int					write_params(t_main **main, t_instr *instr, char *str,
									int fd);
ssize_t				fixed_write(int fd, const void *buf, size_t nbyte);
int					write_header(t_main **main, int fd);
int					get_label_index(t_main **main, char *str);
void				set_label_index(t_main **main, char *str, int index);
int					is_direct2(char *str);
int					is_ocp(char *str);
void				do_ocp(t_instr *instr, int index, int type);
int					find_octal(char *str);
int					bin2dec(char *str);
unsigned int		ft_pow(int x, int y);
int					write_label_4(t_main **main, t_instr *instr,
									char *str, int fd);
int					error_msg(int id);
int					error_line(int id, int line);

#endif
