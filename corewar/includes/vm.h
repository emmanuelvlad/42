/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:02:17 by fpipart           #+#    #+#             */
/*   Updated: 2017/07/19 18:17:45 by fpipart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <unistd.h>
# include <fcntl.h>
# include <ncurses.h>
# include "../libft/libft.h"
# include "op.h"

# define PROC_SIZE	420

# define LIVE 		1
# define LD			2
# define ST			3
# define ADD		4
# define SUB		5
# define AND		6
# define OR			7
# define XOR		8
# define ZJMP		9
# define LDI		10
# define STI		11
# define FORK		12
# define LLD		13
# define LLDI		14
# define LFORK		15
# define AFF		16

# define MODA(x)		((x) % MEM_SIZE)
# define MODR(x)		((x) % IDX_MOD)

typedef struct		s_prog
{
	int				reg[REG_NUMBER];
	int				arg[MAX_ARGS_NUMBER];
	int				acb;
	int				nb_life;
	int				pc_position;
	int				pc_next;
	int				remaining_cycle;
	char			carry;
	int				nb;
	int				kill;
	int				champ_nb;
}					t_prog;

typedef struct		s_env
{
	int				loop_to_dump;
	int				nb_players;
	int				chk_nb[4];
	char			player[5][PROG_NAME_LENGTH];
	int				load_adress;
	int				players_lives[MAX_PLAYERS];
	int				last_alive;
	int				ctd;
	unsigned char	arena[MEM_SIZE];
	unsigned char	color[MEM_SIZE];
	int				checks;
	int				cycle;
	int				tot_cycle_delta;
	int				last_ctd_cycle;
	int				nb_ctd;
	int				pc_nbr_live;
	int				usleep;
	int				last_f_nb;
	int				c_b_ctd;
	int				nc;
	int				speed;
	int				malloc_size;
	WINDOW			*main;
	WINDOW			*info;
	t_prog			**pc;
}					t_env;

typedef struct		s_champ
{
	t_header		*h;
	char			champ_nb;
	unsigned char	champ[CHAMP_MAX_SIZE];
	int				size;
	int				nb_life;
	int				killed;
	struct s_champ	*next;
}					t_champ;

/*
** --------------------------------------------------------------------------
**										PARSE
** --------------------------------------------------------------------------
*/

int					parse_flag(int argc, char **argv, t_env *env);
int					is_number(char *str);
int					check_nb(int nb, t_env *env);

void				champ_add(t_champ **champ, t_champ **new);
t_champ				*champ_new(unsigned char *file, int tot_char,
								int player_nb);
int					store_champ_info(unsigned char *file, t_champ **new,
								int tot_char);
void				print_memory(const void *addr, size_t size);
int					read_cor_file(int fd, unsigned char *dest, t_champ **champ,
								int i);
void				print_file(unsigned char *dest, int tot_char);
unsigned int		little_to_big(unsigned int b);
void				create_arena(t_champ *champ, t_env *env);
int					handle_error(int err);

/*
** --------------------------------------------------------------------------
**									PC LIST
** --------------------------------------------------------------------------
*/

t_prog				*pc_new(int pc_pos, t_env *env, int champ_nb);
void				pc_add(t_env *env, t_prog *new);

/*
** --------------------------------------------------------------------------
**								LET THE GAME BEGIN
** --------------------------------------------------------------------------
*/

void				let_the_game_begin(t_env *env);
int					exec_pc_1cycle(t_env *env);
void				new_cycle(t_prog *tmp, t_env *env);

int					exec(t_prog *tmp, unsigned char f_nb, t_env *env);
int					exec_bis(t_prog *tmp, unsigned char f_nb, t_env *env);

/*
** --------------------------------------------------------------------------
**									NCURSES
** --------------------------------------------------------------------------
*/
void				init_ncurses(t_env *env);
void				ncurses_print_file(t_env *env);

/*
** --------------------------------------------------------------------------
**									MAIN
** --------------------------------------------------------------------------
*/

void				add(t_prog *pc, t_env *env);
void				aff(t_prog *pc, t_env *env);
void				and(t_prog *pc, t_env *env);
void				nfork(t_prog *pc, t_env *env);
void				lfork(t_prog *pc, t_env *env);
void				ld(t_prog *pc, t_env *env);
void				lld(t_prog *pc, t_env *env);
void				ldi(t_prog *pc, t_env *env);
void				lldi(t_prog *pc, t_env *env);
void				live(t_prog *pc, t_env *env);
void				or(t_prog *pc, t_env *env);
void				st(t_prog *pc, t_env *env);
void				sti(t_prog *pc, t_env *env);
void				sub(t_prog *pc, t_env *env);
void				xor(t_prog *pc, t_env *env);
void				zjmp(t_prog *pc, t_env *env);

void				args_sti(t_prog *pc, t_env *env);
void				get_args_diff(t_prog *pc, t_env *env);
int					hex_sum(unsigned char a, unsigned char b);
int					hex_sum2(unsigned char a, unsigned char b, unsigned char c,
							unsigned char d);
void				int_to_chars(t_env *env, int i, int num, t_prog *pc);
void				get_3regs(t_prog *pc, t_env *env);
int					is_reg(int arg1, int arg2, int arg3);
int					neg(int nb);
int					select_winner(t_env env, t_champ *champ);
void				introduce_champ(t_champ *champ);

/*
** mint		little_to_big(unsigned int b);
**
** int					ncurses_print_window(t_env *env, t_prog *pc,
**										t_champ *champ);
** void				ncurses_reload(t_env *env, t_prog *pc, t_champ *champ);
** int				ncurse_init(unsigned char *arena);
** void				ncurse_print_arena(unsigned char *file, WINDOW *gch);
**
** void				add(t_prog *pc, unsigned char *arena);
** void				get_3regs(t_prog *pc, unsigned char *arena);
** int					is_reg(int arg1, int arg2, int arg3);
** int					hex_sum(char a, char b);
** int					hex_sum2(char a, char b, char c, char d);
** void				get_args_diff(t_prog *pc, unsigned char *arena);
** void				arg_ld(t_prog *pc, unsigned char *arena);
** void				int_to_chars(char *arena, int i, int num);
*/

#endif
