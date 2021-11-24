# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 16:48:29 by evlad             #+#    #+#              #
#    Updated: 2017/05/30 12:40:36 by evlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --silent

CHECKER_NAME = checker

CHECKER_SRC = checker_src

CHECKER_LIST = main.c \
			   misc.c \
			   stock.c \
			   freexit.c \
			   init.c \
			   operations.c \
			   operations_2.c \
			   operations_3.c \

CHECKER_PATH = $(OBJ_PATH)$(CHECKER_NAME)/

CHECKER_FILES = $(CHECKER_LIST:%=./$(CHECKER_SRC)/%)

CHECKER_OBJ = $(CHECKER_LIST:%.c=%.o)

CHECKER = $(CHECKER_OBJ:%=$(CHECKER_PATH)%)



PS_NAME = push_swap

PS_SRC = push_swap_src

PS_LIST = main.c \
		  sort.c \
		  parse.c \
		  put_first.c \
		  misc.c \
		  stock.c \
		  freexit.c \
		  init.c \
		  operations.c \
		  operations_2.c \
		  operations_3.c \

PS_PATH = $(OBJ_PATH)$(PS_NAME)/

PS_FILES = $(PS_LIST:%=./$(PS_SRC)/%)

PS_OBJ = $(PS_LIST:%.c=%.o)

PS = $(PS_OBJ:%=$(PS_PATH)%)


LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = -L $(LIBFT_PATH) -lft

OBJ_PATH = ./obj/


FLAGS = -Wextra -Werror -Wall

c_green = $$(tput setaf 2)
c_reset = $$(tput sgr0)
c_red = $$(tput setaf 1)
OK = "$(c_green)[OK]$(c_reset)"

$(PS_PATH)%.o: $(PS_FILES) ./$(PS_SRC)/$(PS_NAME).h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(PS_PATH)
	@gcc $(FLAGS) -c ./$(PS_SRC)/$(@F:%.o=%.c) -o $(@F:%=$(OBJ_PATH)$(PS_NAME)/%)

$(CHECKER_PATH)%.o: $(CHECKER_FILES) ./$(CHECKER_SRC)/$(CHECKER_NAME).h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(CHECKER_PATH)
	@gcc $(FLAGS) -c ./$(CHECKER_SRC)/$(@F:%.o=%.c) -o $(@F:%=$(OBJ_PATH)$(CHECKER_NAME)/%)

all: $(LIBFT) $(CHECKER_NAME) $(PS_NAME)

$(LIBFT):
	@echo -n '-> Compiling LIBFT .'
	@make -C $(LIBFT_PATH) -s
	@cp $(LIBFT_PATH)/*.h ./includes
	@echo -n '..			'
	@echo $(OK)

$(CHECKER_NAME): $(CHECKER)
	@echo -n '-> Compiling CHECKER ..'
	@gcc -o $(CHECKER_NAME) $(CHECKER_OBJ:%=$(OBJ_PATH)$(CHECKER_NAME)/%) $(LIBFT_INC)
	@echo -n '.		'
	@echo $(OK)

$(PS_NAME): $(PS)
	@echo -n '-> Compiling PUSH_SWAP .'
	@gcc -o $(PS_NAME) $(PS_OBJ:%=$(OBJ_PATH)$(PS_NAME)/%) $(LIBFT_INC)
	@echo -n '.'
	@echo -n '.		'
	@echo $(OK)
	
clean:
	@echo -n '-> Deleting object files ..'
	@/bin/rm -rf $(OBJ_PATH)
	@/bin/rm -rf ./includes/*.h
	@echo -n '.		'
	@make -C $(LIBFT_PATH) clean
	@echo $(OK)

fclean: clean
	@echo -n '-> Deleting executable files ..'
	@/bin/rm -f $(CHECKER_NAME) $(PS_NAME)
	@echo -n '.	'
	@make -C $(LIBFT_PATH) fclean
	@echo $(OK)

re: fclean all

.PHONY: clean fclean re
