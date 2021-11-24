MAKEFLAGS += --silent

ASM_NAME = asm

ASM_SRC = assembler

ASM_LIST = main.c pars.c op.c check_s.c check_instructions.c initialize.c \
		get_param.c check_instr.c check_param.c check_label.c start_with.c \
		check_instructions_bis.c check_param_bis.c start_with_bis.c \
		free_everything.c misc.c compile.c compile_2.c write.c write_2.c \
		write_3.c strlenet.c errors.c

ASM_PATH = $(OBJ_PATH)$(ASM_NAME)/

ASM_FILES = $(ASM_LIST:%=./$(ASM_SRC)/%)

ASM_OBJ = $(ASM_LIST:%.c=%.o)

ASM = $(ASM_OBJ:%=$(ASM_PATH)%)



VM_NAME = corewar

VM_SRC = vm

VM_LIST = main.c read_cor_file.c reverse_bits.c create_arena.c print_file.c \
		champ_list.c flags_parsing.c check_numbers.c handle_error.c \
		let_the_game_begin.c pc_list.c exec_pc_1cycle.c \
		ncurses_print_window.c print_file_ncurse.c \
		add.c aff.c and.c fork.c get_args_diff.c get_args_sti.c \
		hex_sum.c int_to_chars.c select_winner.c ld.c ldi.c live.c lld.c \
		lldi.c or.c st.c sti.c sub.c xor.c zjmp.c lfork.c main_2.c exec_2.c \
		misc.c

VM_PATH = $(OBJ_PATH)$(VM_NAME)/

VM_FILES = $(VM_LIST:%=./$(VM_SRC)/%)

VM_OBJ = $(VM_LIST:%.c=%.o)

VM = $(VM_OBJ:%=$(VM_PATH)%)


LIBFT = ./libft/libft.a

OBJ_PATH = ./obj/

LIBFT_INC = -L ./libft/ -lft

FLAGS = -Wextra -Werror -Wall

c_green = $$(tput setaf 2)
c_reset = $$(tput sgr0)
c_red = $$(tput setaf 1)
OK = "$(c_green)[OK]$(c_reset)"

$(VM_PATH)%.o: $(VM_FILES) ./includes/op.h ./includes/vm.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(VM_PATH)
	@gcc $(FLAGS) -c ./$(VM_SRC)/$(@F:%.o=%.c) -o $(@F:%=$(OBJ_PATH)$(VM_NAME)/%)

$(ASM_PATH)%.o: $(ASM_FILES) ./includes/op.h ./includes/asm.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(ASM_PATH)
	@gcc $(FLAGS) -c ./$(ASM_SRC)/$(@F:%.o=%.c) -o $(@F:%=$(OBJ_PATH)$(ASM_NAME)/%)

all: $(LIBFT) $(ASM_NAME) $(VM_NAME)

$(LIBFT):
	@echo -n '-> Compiling LIBFT .'
	@make -C ./libft/
	@echo -n '..			'
	@echo $(OK)

$(ASM_NAME): $(LIBFT) $(ASM)
	@echo -n '-> Compiling ASM ..'
	@gcc -o $(ASM_NAME) $(ASM_OBJ:%=$(OBJ_PATH)$(ASM_NAME)/%) $(LIBFT_INC)
	@echo -n '.			'
	@echo $(OK)

$(VM_NAME): $(LIBFT) $(VM)
	@echo -n '-> Compiling Corewar .'
	@gcc -lncurses -o $(VM_NAME) $(VM_OBJ:%=$(OBJ_PATH)$(VM_NAME)/%) $(LIBFT_INC)
	@echo -n '.'
	@echo -n '.		'
	@echo $(OK)

clean:
	@echo -n '-> Deleting object files ..'
	@/bin/rm -rf $(OBJ_PATH)
	@echo -n '.		'
	@make -C ./libft/ clean
	@echo $(OK)

fclean: clean
	@echo -n '-> Deleting executable files ..'
	@/bin/rm -f $(ASM_NAME) $(VM_NAME)
	@echo -n '.	'
	@make -C ./libft/ fclean
	@echo $(OK)

re: fclean all

.PHONY: clean fclean re
